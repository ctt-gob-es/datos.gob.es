# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge_dashboard (datos.gob.es)".
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

from ckan.plugins import toolkit as pt
from ckanext.harvest.logic.auth import user_is_sysadmin


def dge_dashboard_json_published_datasets(context, data_dict):
    '''
        Authorization check for get dge_dashboard_published_dataset table data

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can get dge_dashboard table data')}
    else:
        return {'success': True}


def dge_dashboard_json_current_published_datasets_by_administration_level(context, data_dict):
    '''
        Authorization check for get published datasets by administration level

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False,
                'msg': pt._('Only sysadmins can get number of published datasets by administration level')}
    else:
        return {'success': True}


def dge_dashboard_json_current_distribution_format(context, data_dict):
    '''
        Authorization check for get distribution by format

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can get number of distribution by format')}
    else:
        return {'success': True}


def dge_dashboard_json_current_distribution_format_by_administration_level(context, data_dict):
    '''
        Authorization check for get distribution by format and administration level

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False,
                'msg': pt._('Only sysadmins can get number of distribution by format and administration level')}
    else:
        return {'success': True}


def dge_dashboard_json_current_published_datasets_by_category(context, data_dict):
    '''
        Authorization check for get published datasets by category

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can get number of published datasets by category')}
    else:
        return {'success': True}


def dge_dashboard_json_publishers(context, data_dict):
    '''
        Authorization check for get dge_dashboard_publishers table data

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can get dge_dashboard table data')}
    else:
        return {'success': True}


def dge_dashboard_json_current_publishers_by_administration_level(context, data_dict):
    '''
        Authorization check for get dge_dashboard_publishers table data

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False,
                'msg': pt._('Only sysadmins can get number of current publisher by administration level')}
    else:
        return {'success': True}


def dge_dashboard_json_drupal_published_contents(context, data_dict):
    '''
        Authorization check for get dge_dashboard_drupal_contents table data

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can get dge_dashboard_drupal_contents table data')}
    else:
        return {'success': True}


def dge_dashboard_drupal_content_by_likes(context, data_dict):
    '''
        Authorization check for update dge_dashboard_update_drupal_content_by_likes table

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can update dge_dashboard tables')}
    else:
        return {'success': True}


def dge_dashboard_json_drupal_top10_voted_datasets(context, data_dict):
    '''
        Authorization check for update dge_dashboard_update_drupal_content_by_likes table

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can update dge_dashboard tables')}
    else:
        return {'success': True}


def dge_dashboard_json_current_drupal_published_contents(context, data_dict):
    '''
        Authorization check for get drupal published data by content_type

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can get drupal published data')}
    else:
        return {'success': True}


def dge_dashboard_json_current_users(context, data_dict):
    '''
        Authorization check for get drupal active users

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can get drupal active users')}
    else:
        return {'success': True}


def dge_dashboard_json_current_assigned_request_by_state(context, data_dict):
    '''
        Authorization check for get drupal assigned requests

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can get drupal assigned requests')}
    else:
        return {'success': True}


def dge_dashboard_json_visits(context, data_dict):
    '''
        Authorization check for get visits to datos.gob.es

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can get visits to datos.gob.es')}
    else:
        return {'success': True}


def dge_dashboard_json_visited_datasets(context, data_dict):
    '''
        Authorization check for get the most visited datasets

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can get the most visited datasets')}
    else:
        return {'success': True}


def dge_dashboard_csv_visited_datasets(context, data_dict):
    '''
        Authorization check for get the most visited datasets in csv

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can get the most visited datasets csv')}
    else:
        return {'success': True}


def dge_dashboard_csv_published_datasets_by_root_org(context, data_dict):
    '''
        Authorization check for get the most visited datasets

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can get the datasets by root organization')}
    else:
        return {'success': True}
