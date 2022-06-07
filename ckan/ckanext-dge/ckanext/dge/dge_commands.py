# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge (datos.gob.es)".
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

# coding=utf-8
import os
import re
import logging
from datetime import datetime
import time
import sys

from pylons import config
from ckan.lib.cli import CkanCommand


class DgeCommand(CkanCommand):
    ''' Transform the dataset tags into multilingual_tags

        dge from_tags_to_multilingual_tags {package-name/id}|{group-name/id}
            - Transform all tags beloging to a specific package or group

        paster --plugin=ckanext-dge dge from_tags_to_multilingual_tags {package-name/id}|{group-name/id} -c ../ckan/development.ini
    '''

    summary = __doc__.split('\n')[0]
    usage = __doc__
    max_args = 2
    min_args = 2
    datetime_format = '%d/%m/%Y %H:%M:%S.%f'

    def __init__(self, name):
        super(DgeCommand, self).__init__(name)

    def command(self):
        '''
          Parse command line arguments and call appropriate method.
        '''
        try:
            self._load_config()
            self.log = logging.getLogger(__name__)
            init = datetime.now()
            s_args = (self.args if self.args else '(no args)')
            self.log.info('[%s] - Init DgeCommand command with args: %s.' % (
                init.strftime(DgeCommand.datetime_format), s_args))

            if not self.args or len(self.args) < self.min_args or len(self.args) > self.max_args or self.args[0] in ['--help', '-h', 'help']:
                self.log.info(self.usage)
                sys.exit(1)

            cmd = self.args[0]
            if cmd == 'from_tags_to_multilingual_tags':
                self._from_tags_to_multilingual_tags()
        except Exception as e:
            self.log.error('Exception %s: %s' % (type(e).__name__, e))
            sys.exit(1)
        finally:
            end = datetime.now()
            self.log.info('[%s] - End DgeCommand command with args %s. Executed command in %s milliseconds.' % (
                end.strftime(DgeCommand.datetime_format), s_args, (end-init).total_seconds()*1000))
        sys.exit(0)

    def _from_tags_to_multilingual_tags(self):
        from ckan import model
        from ckan.logic import get_action
        method_log_prefix = '[%s][from_tags_to_multilingual_tags]' % type(
            self).__name__
        #print '%s Init method.' % (method_log_prefix)
        self.log.debug('%s Init method.' % (method_log_prefix))
        default_local = config.get(u'ckan.locale_default', 'es')
        context = {'model': model,
                   'session': model.Session, 'ignore_auth': True}
        self.admin_user = get_action('get_site_user')(context, {})
        context = {
            'model': model,
            'user': self.admin_user['name'],
            'session': model.Session
        }
        for pkg, num_tags_for_pkg, pkg_tags in \
                self._get_packages_in_args(self.args[1:]):
            try:
                package = pkg
                self.log.info(
                    'Transforming tags to dataset %s (%s tags)', package.name, num_tags_for_pkg)
                if num_tags_for_pkg > 0:
                    # se ordenan las tags
                    pkg_tags.sort
                    multilingual_tags = {}
                    multilingual_tags[default_local] = []
                    for tag in pkg_tags:
                        aux =  self._encode_value(tag.name, True)
                        if aux is not None:
                            multilingual_tags[default_local].append(aux)
                    if (len(pkg_tags) > 0):
                        self.log.info('Dataset: %s. From tags = %s to multilingual tags = %s ',
                                      package.name, self._from_list_to_string(pkg_tags).decode('utf-8'), multilingual_tags)
                    else:
                        self.log.info('Dataset: %s. From tags = %s to multilingual tags = %s ',
                                      package.name, pkg_tags, multilingual_tags)
                    data_dict = {}
                    data_dict['id'] = package.id
                    data_dict['multilingual_tags'] = multilingual_tags
                    data_dict['tags'] = []
                    get_action('package_patch')(context, data_dict)
            except Exception, e:
                self.log.error('%s Dataset %s. Exception %s: %s' % (
                    method_log_prefix, pkg.name, type(e).__name__, e))
                #print '%s Dataset %s. Exception %s: %s' % (
                #    method_log_prefix, pkg.name, type(e).__name__, e)

        #print '%s End method' % (method_log_prefix)
        self.log.debug('%s End method.' % (method_log_prefix))

    def _get_packages_in_args(self, args):
        from ckan import model
        packages = []
        org_or_pkg = False
        if args:
            for arg in args:
                # try arg as a group id/name
                group = model.Group.get(arg)
                if (group):
                    if group.is_organization:
                        packages.extend(model.Session.query(
                            model.Package).filter_by(owner_org=group.id))
                        org_or_pkg = True
                    else:
                        self.log.debug(
                            'There is not any organization with this name or id %s' % (arg))
                else:
                    # try arg as a package id/name
                    pkg = model.Package.get(arg)
                    if pkg:
                        packages.append(pkg)
                        org_or_pkg = True
                    else:
                        self.log.debug(
                            'There is not any package with this name or id %s' % (arg))
                if not org_or_pkg:
                    self.log.debug(
                        'There is not any package nor organization with this name or id %s' % (arg))
                    sys.exit(1)
        else:
            #self.log.debug('All packages')
            #pkgs = model.Session.query(model.Package).order_by('name').all()
            # packages.extend(pkgs)
            self.log.debug('There is not any argument')
            sys.exit(1)

        if packages:
            self.log.info(
                'Datasets number to transform tags into multilingual tags: %d', len(packages))
            if not (packages):
                self.log.error('No datasets to process')
                sys.exit(1)

            for package in packages:
                pkg_tags = package.get_tags() or []
                if len(pkg_tags) > 0:
                    self.log.debug('package_id = %s; package_name = %s; package_tags = %s' % (
                        package.id, package.name, self._from_list_to_string(pkg_tags).decode('utf-8')))
                    yield(package, len(pkg_tags), pkg_tags)
                else:
                    self.log.debug('No tags in package_id = %s; package_name = %s' % (
                        package.id, package.name))

    def _encode_value(self, value=None, clean=False):
        retult = None
        try:
            if value:
                if clean and clean == True:
                    value = re.sub('[\n\r]', ' ', value)
            result = value.encode('utf-8')
        except Exception, e:
            result = None
            self.log.error('_encode_value Exception %s: %s' %
                        (type(e).__name__, e))
        return result

    def _from_list_to_string(self, data_list=None, separator='//'):
        method_log_prefix = '[%s][_from_list_to_string]' % __name__
        result = None
        try:
            if data_list:
                for value in data_list:
                    if result:
                        result = "%s%s%s" % (result, separator, value)
                    else:
                        result = "%s" % (value)
        except Exception, e:
            result = None
            self.log.error('_from_list_to_string Exception %s: %s' %
                           (type(e).__name__, e))
        return result
