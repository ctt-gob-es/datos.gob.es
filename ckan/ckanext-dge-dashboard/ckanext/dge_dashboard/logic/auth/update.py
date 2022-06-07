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



def dge_dashboard_update_published_datasets(context, data_dict):
    '''
        Authorization check for update dge_dashboard_published_dataset table

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can update dge_dashboard tables')}
    else:
        return {'success': True}


def dge_dashboard_update_publishers(context, data_dict):
    '''
        Authorization check for update dge_dashboard_publisher table

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can update dge_dashboard tables')}
    else:
        return {'success': True}

def dge_dashboard_update_drupal_published_contents(context, data_dict):
    '''
        Authorization check for update dge_dashboard_update_drupal_published_contents table

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can update dge_dashboard tables')}
    else:
        return {'success': True}


def dge_dashboard_update_drupal_comments(context, data_dict):
    '''
        Authorization check for update dge_dashboard_update_drupal_comments table

        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': pt._('Only sysadmins can update dge_dashboard tables')}
    else:
        return {'success': True}