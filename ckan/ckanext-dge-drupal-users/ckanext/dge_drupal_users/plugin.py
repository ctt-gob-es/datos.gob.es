# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge_drupal_users (datos.gob.es)".
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

import logging
import uuid
import hashlib
import re

import sqlalchemy as sa

import ckan.plugins as p
import ckan.lib.base as base
import ckan.logic as logic
import ckan.lib.helpers as h

log = logging.getLogger('ckanext.dge_drupal_users')


def sanitize_drupal_username(name):
    """Convert a drupal username (which can have spaces and other special characters) into a form that is valid in CKAN
    """
    # convert spaces and separators
    name = re.sub('[ .:/]', '-', name)
    # take out not-allowed characters
    name = re.sub('[^a-zA-Z0-9-_]', '', name).lower()
    # remove doubles
    name = re.sub('--', '-', name)
    # remove leading or trailing hyphens
    name = name.strip('-')[:99]
    return name

def _no_permissions(context, msg):
    user = context['user']
    return {'success': False, 'msg': msg.format(user=user)}

class DgeDrupalUsersPlugin(p.SingletonPlugin):

    p.implements(p.IAuthenticator, inherit=True)
    p.implements(p.IRoutes, inherit=True)
    p.implements(p.IConfigurer)
    p.implements(p.IConfigurable)
    p.implements(p.ITemplateHelpers)

    drupal_session_name = None

    def get_helpers(self):
        return {'ckanext_dge_drupal_users_domain': self.get_domain}

    def get_domain(self):
        return self.domain

    @staticmethod
    def update_config(config):
        p.toolkit.add_template_directory(config, 'templates')

    def configure(self, config):
        self.domain = config.get('ckanext.dge_drupal_users.domain')
        self.connection = config.get('ckanext.dge_drupal_users.connection')

        if not (self.domain and self.connection):
            raise Exception('DgeDrupalUsers extension has not been configured')

    @staticmethod
    def before_map(map):
        map.connect(
            'user_unauthorized',
            '/user_unauthorized',
            controller='ckanext.dge_drupal_users.plugin:DgeDrupalUsersController',
            action='unauthorized'
        )
        return map

    @staticmethod
    def make_password():
        # create a hard to guess password
        out = ''
        for n in xrange(8):
            out += str(uuid.uuid4())
        return out

    def create_drupal_session_name(self, https=True):
        server_name = self.domain or p.toolkit.request.environ['SERVER_NAME']
        prefix = 'SSESS%s' if https else 'SESS%s'
        session_name = prefix % hashlib.sha256(server_name).hexdigest()[:32]
        self.drupal_session_name = session_name

    def destroy_drupal_session(self):
        self.drupal_session_name = None

    def identify(self):
        """ This does drupal authorization.
        The drupal session contains the drupal id of the logged in user.
        We need to convert this to represent the ckan user. """

        # If no drupal session name create one
        if self.drupal_session_name is None:
            self.create_drupal_session_name()

        # Can we find the user?
        cookies = p.toolkit.request.cookies

        drupal_sid = cookies.get(self.drupal_session_name)
        if not drupal_sid:
            self.create_drupal_session_name(https=False)
            drupal_sid = cookies.get(self.drupal_session_name)

        if drupal_sid:
            engine = sa.create_engine(self.connection)
            rows = engine.execute(
                'SELECT u.field_ckan_user_name_value name, p.uid uid FROM profile p '
                'JOIN sessions s on s.uid=p.uid JOIN field_data_field_ckan_user_name u '
                'on p.pid=u.entity_id  WHERE s.sid=%s',
                [str(drupal_sid)])

            for row in rows:
                # check if session has username, otherwise is unauthenticated user session
                if row.name and row.name != '':
                    self.user(row)
                    break
        else:
            self.destroy_drupal_session()

    def user(self, user_data):
        try:
            user = p.toolkit.get_action('user_show')(
                {'keep_sensitive_data': True,
                 'keep_email': True},
                {'id': user_data.name}
            )
        except p.toolkit.ObjectNotFound:
            pass
            user = None
        if user and user['state'] == 'active':
            p.toolkit.c.user = user['name']

    @staticmethod
    def abort(status_code, detail, headers, comment):
        # HTTP Status 401 causes a login redirect.  We need to prevent this
        # unless we are actually trying to login.
        if status_code == 401 and p.toolkit.request.environ['PATH_INFO'] != '/user/login':
            h.redirect_to('user_unauthorized')
        return status_code, detail, headers, comment

class DgeDrupalUsersController(base.BaseController):

    def unauthorized(self):
        # Avoid loops
        c = p.toolkit.c
        c.title = p.toolkit._('Access denied')
        c.code = 401
        c.content = p.toolkit._('You are not authorized to access this page.')
        return p.toolkit.render('error_document_template.html')

