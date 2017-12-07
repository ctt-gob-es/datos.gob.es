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

import ckanext.dge_scheming.helpers as dsh
import ckanext.scheming.helpers as sh
from ckan.lib.helpers import get_available_locales
from pylons.i18n import gettext
from pylons import config
import pytz
import datetime
import ckan.logic as logic
import ckan.lib.helpers as h
import ckanext.dge_harvest.constants as dhc
from ckan import model
from ckan.common import (
    _, ungettext, g, c, request, session, json, OrderedDict
)


import logging
from rdflib.plugins.parsers.pyRdfa import options

log = logging.getLogger(__name__)

def _dge_harvest_list_dataset_field_values(name_field=None):
    '''
    Returns the available values that the given dataset name_field may have
    '''
    result = []
    if name_field is not None:
        dataset = sh.scheming_get_schema('dataset', 'dataset')
        values = sh.scheming_field_by_name(dataset.get('dataset_fields'),
                name_field) or []
        if values and values['choices']:
            for option in values['choices']:
                if option and option['value']:
                    result.append(option['value'])
    return result

def _dge_harvest_list_dataset_field_labels(name_field=None, value_field=None):
    '''
    Returns the available values that the given dataset name_field may have to the given value_field
    '''
    result = {}
    if name_field is not None:
        dataset = sh.scheming_get_schema('dataset', 'dataset')
        values = sh.scheming_field_by_name(dataset.get('dataset_fields'),
                name_field) or []
        if values and values['choices']:
            for option in values['choices']:
                if option and option['value']:
                    if value_field:
                        if option['value'] == value_field:
                            return {option.get('value'): {'label' : option.get('label'), 'description': option.get('description'), 'dcat_ap': option.get('dcat_ap'), 'notation': option.get('notation')}}
                    else:
                        result[option.get('value')] = {'label' : option.get('label'), 'description': option.get('description'), 'dcat_ap': option.get('dcat_ap'), 'notation': option.get('notation')}
    return result


def _dge_harvest_list_resource_field_values(name_field=None):
    '''
    Returns the available values that the given resource name_field may have
    '''
    result = []
    if name_field is not None:
        dataset = sh.scheming_get_schema('dataset', 'dataset')
        values = sh.scheming_field_by_name(dataset.get('resource_fields'),
                name_field) or []
        if values and values['choices']:
            for option in values['choices']:
                if option and option['value']:
                    result.append(option['value'])
    return result

def dge_harvest_list_spatial_coverage_option_value():
    '''
    Returns available values for spatial coverage 
    '''
    list = _dge_harvest_list_dataset_field_values('spatial')
    result = {}
    for item in list:
        if item:
            result[item.lower()] = item
    return result

def dge_harvest_dict_spatial_coverage_option_label(value=None):
    '''
    Returns available label for spatial coverage 
    '''
    result = _dge_harvest_list_dataset_field_labels('spatial', value)
    return result

def dge_harvest_list_theme_option_value():
    '''
    Returns available values for theme 
    '''
    list = _dge_harvest_list_dataset_field_values('theme')
    result = {}
    for item in list:
        if item:
            result[item.lower()] = item
    return result

def dge_harvest_dict_theme_option_label(value=None):
    '''
    Returns available label, descriptions and mappings for theme 
    '''
    result = _dge_harvest_list_dataset_field_labels('theme', value)
    return result

def _dge_harvest_list_format_option_value():
    '''
    Returns available values for format 
    '''
    list = _dge_harvest_list_resource_field_values('format')
    result = {}
    for item in list:
        if item:
            result[item.lower()] = item
    return result

def dge_harvest_is_url(url):
    ''' 
    Returns True if given url is a valid url
    '''
    return h.is_url(url)

def dge_harvest_is_uri(uri):
    ''' 
    Returns True if given uri is a valid uri
    '''
    return dsh.dge_is_uri(uri)

def dge_harvest_organizations_available():
    '''Return a dict of active organizations 
        where key id id_minhap (extra C_ID_UD_ORGANICA value) 
        and value is org_id
    '''
    idminhap_organizations = {}
    context = {'ignore_auth': False}
    data_dict = {'all_fields': True,
                 'include_extras': True}
    organizations = logic.get_action('organization_list')(context, data_dict)
    if organizations:
        idminhap_organizations = {}
        idminhap_dis_name = {}
        for organization in organizations:
            if organization and organization.get('id', None):
                organization_id = organization.get('id', None)
                organization_name = organization.get('title', None)
                if not organization_name or len(organization_name) == 0:
                    organization_name=organization.get('display_name', '')
                extras = organization.get('extras')
                if organization_id and extras:
                    found = False
                    for extra in extras:
                        if extra and not found:
                            if extra.get('key') == dhc.ORG_PROP_ID_UD_ORGANICA:
                                found = True
                                if extra.get('value'):
                                    value = extra.get('value').upper()
                                    if (value not in idminhap_organizations):
                                        idminhap_organizations[value] = [organization_id, organization_name]
                                    else:
                                        log.info("Organization %s[id=%s], the publisher %s is used by other organiztion whose id is %s" %(organization.get('name'), organization.get('id'), publisher, dict_idminhaps.get('value')))
                                break;
                    if  not found:
                        log.info("Organization %s[id=%s] has not an extra extra %s or its value is empty" % (organization.get('name'), organization.get('id'), dhc.ORG_PROP_ID_UD_ORGANICA))
                else:
                    log.info("Organization %s[id=%s] has not extras" % (organization.get('name'), organization.get('id')))
    log.debug("idminhap_organizations=%s", idminhap_organizations)
    return idminhap_organizations