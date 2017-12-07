# Copyright (C) 2017 Entidad Pública Empresarial Red.es
# 
# This file is part of "ckanext-dge-harvest (datos.gob.es)".
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
# 
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import ckan.plugins as plugins
import ckan.plugins.toolkit as toolkit
import logging

from ckanext.dge_harvest import helpers
from ckanext.dge_harvest.logic import (dge_harvest_catalog_show,
                                       dge_harvest_clear_old_harvest_jobs,
                                       dge_harvest_source_email_job_finished,
                                       dge_harvest_get_running_harvest_jobs,
                                       dge_harvest_auth,
                                       dge_harvest_is_sysadmin)
from pylons import config

log = logging.getLogger(__name__)


class DgeHarvestPlugin(plugins.SingletonPlugin):
    plugins.implements(plugins.IConfigurer)
    plugins.implements(plugins.ITemplateHelpers, inherit=True)
    plugins.implements(plugins.IActions, inherit=True)
    plugins.implements(plugins.IAuthFunctions, inherit=True)
#     log.info('[ DgeHarvestPlugin] Running Profile %s with local default %s' % 
#               (config.get('ckanext.dcat.rdf.profiles', None), 
#                config.get('ckan.locale_default', None)))

    # ########################### IActions ####################################
    def get_actions(self):
        return {
            'dge_harvest_catalog_show': dge_harvest_catalog_show,
            'dge_harvest_clear_old_harvest_jobs': dge_harvest_clear_old_harvest_jobs,
            'dge_harvest_source_email_job_finished' : dge_harvest_source_email_job_finished,
            'dge_harvest_get_running_harvest_jobs': dge_harvest_get_running_harvest_jobs,
        }

    # ########################### IAuthFunctions ##############################
    def get_auth_functions(self):
        return {
            'dge_harvest_catalog_show': dge_harvest_auth,
            'dge_harvest_clear_old_harvest_jobs': dge_harvest_is_sysadmin,
            'dge_harvest_source_email_job_finished': dge_harvest_is_sysadmin,
            'dge_harvest_get_running_harvest_jobs': dge_harvest_is_sysadmin,
        }

    # ########################### IConfigurer #################################
    def update_config(self, config_):
        toolkit.add_template_directory(config_, 'templates')
        toolkit.add_public_directory(config_, 'public')
        toolkit.add_resource('fanstatic', 'dge_harvest')

    # ########################### ITemplateHelpers ############################

    def get_helpers(self):
        return {
            'dge_harvest_list_spatial_coverage_option_value': helpers.dge_harvest_list_spatial_coverage_option_value,
            'dge_harvest_list_theme_option_value': helpers.dge_harvest_list_theme_option_value,
            '_dge_harvest_list_format_option_value': helpers._dge_harvest_list_format_option_value,
            'dge_harvest_organizations_available': helpers.dge_harvest_organizations_available,
            'dge_harvest_dict_theme_option_label': helpers.dge_harvest_dict_theme_option_label,
            'dge_harvest_dict_spatial_coverage_option_label': helpers.dge_harvest_dict_spatial_coverage_option_label,
            }