# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge_archiver (datos.gob.es)".
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

import ckan.plugins as plugins
import ckan.plugins.toolkit as toolkit
import ckan.lib.helpers as h
import ckanext.scheming.helpers as sh
import ckanext.dge_scheming.helpers as dsh
import ckan.model as model
import pylons
from pylons import config
from ckanext.dge import helpers
from ckanext.dge_archiver import helpers as dah
from ckanext.dge.helpers import TRANSLATED_UNITS as TRANSLATED_UNITS
from ckanext.dge.helpers import DEFAULT_UNIT as DEFAULT_UNIT
from collections import OrderedDict
from routes.mapper import SubMapper
from ckan.lib.plugins import DefaultTranslation
import ckan.logic as logic
import ckan.logic.auth as logic_auth
import ckan.logic.action as logic_action
import ckan.authz as authz
from ckan.common import _
import ckan.lib.base as base
import ckan.lib.plugins as lib_plugins
import ckan.lib.dictization.model_dictize as model_dictize
import json
import logging

from ckanext.dge_archiver.controllers import DGEArchiverController

from ckanext.dge_archiver.logic import (dge_archiver_report_email_finished,
                                        dge_archiver_auth)

log = logging.getLogger(__name__)
is_frontend = False

def is_frontend():
    is_frontend = False
    config_is_frontend = config.get('ckanext.dge.is_frontend', None)
    if config_is_frontend and config_is_frontend.lower() == 'true':
        is_frontend = True
    return is_frontend

class DgeArchiverPlugin(plugins.SingletonPlugin, DefaultTranslation):
    plugins.implements(plugins.IActions, inherit=True)
    plugins.implements(plugins.IAuthFunctions, inherit=True)

    if is_frontend():
        plugins.implements(plugins.IConfigurer, inherit=True)
        plugins.implements(plugins.ITranslation, inherit=True)
        plugins.implements(plugins.IRoutes, inherit=True)

    # IConfigurer
    def update_config(self, config_):
        if is_frontend():
            toolkit.add_template_directory(config_, 'templates')
            toolkit.add_public_directory(config_, 'public')
            toolkit.add_resource('fanstatic', 'dge_archiver')

    # ############### IRoutes ################################################ #

    def before_map(self, _map):
        if not is_frontend():
            return _map

        try:
            log.debug("before_map")

            with SubMapper(_map, controller='ckanext.dge_archiver.controllers:DGEArchiverController') as m:
                m.connect('broken_links', '/enlaces-rotos', action='broken_links')
                m.connect('checkeable_groups', '/report/checkeable-groups', action="checkeable_groups")
                # m.connect('load_checkeable_groups', '/load-checkeable-groups', action="load_checkeable_groups")

        except Exception as e:
            log.warn("MAP Before_map exception %r: %r:", type(e), e.message)
        return _map

    def after_map(self, _map):
        return _map

        
    def get_helpers(self):
        return {
            'organization_name': dah.organization_name,
        }   
    ## IActions
    def get_actions(self):
        if not is_frontend():
            return {}
        return {
            'dge_archiver_report_email_finished': dge_archiver_report_email_finished,
        }
        
    def get_auth_functions(self):
        return { 'dge_archiver_report_email_finished': dge_archiver_auth }
'''
    def get_actions(self):
        if not is_frontend():
            return {}
        return { 'broken_links' : broken_links }'''

    # ########################### IAuthFunctions ##############################

'''    def get_auth_functions(self):
        return { 'broken_links': dge_archiver_auth }

    #@toolkit.auth_allow_anonymous_access
    def dge_archiver_auth(context, data_dict):
       ''' '''
        All users can access by default
       ''' '''
        return {'success': True}
'''