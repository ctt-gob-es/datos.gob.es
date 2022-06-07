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

#!/usr/bin/env python
# -*- coding: utf-8 -*-
import calendar
import datetime
import json
import logging
import traceback
import urllib
from time import strptime

import ckan.lib.helpers as h
import ckan.plugins.toolkit as toolkit
import ckanext.dge.helpers as dh
import ckanext.dge_scheming.helpers as dsh
import ckanext.scheming.helpers as sh
import paste.deploy.converters as converters
from ckan import logic
from ckan.common import (
    _, c, json
)
from dateutil.relativedelta import relativedelta
from pylons import config

ORDER_UNITS = ['E', 'A', 'L', 'U', 'I', 'J', 'P']

TRANSLATED_UNITS = {'E': {'es': 'Administraci\u00F3n del Estado',
                          'ca': 'Administraci\u00F3 de l\u0027Estat',
                          'gl': 'Administraci\u00F3n do Estado',
                          'eu': 'Estatuko Administrazioa',
                          'en': 'State Administration'},
                    'A': {'es': 'Administraci\u00F3n Auton\u00F3ica',
                          'ca': 'Administraci\u00F3 Auton\u00F3mica',
                          'gl': 'Administraci\u00F3n Auton\u00F3mica',
                          'eu': 'Administrazio Autonomikoa',
                          'en': 'Regional Administration'},
                    'L': {'es': 'Administraci\u00F3n Local',
                          'ca': 'Administraci\u00F3 Local',
                          'gl': 'Administraci\u00F3n Local',
                          'eu': 'Toki Administrazioa',
                          'en': 'Local Administration'},
                    'U': {'es': 'Universidades',
                          'ca': 'Universitats',
                          'gl': 'Universidades',
                          'eu': 'Universities',
                          'en': 'Unibertsitateak'},
                    'I': {'es': 'Otras Instituciones',
                          'ca': 'Altres institucions',
                          'gl': 'Outras instituci\u00F3ns',
                          'eu': 'Beste instituzio batzuk',
                          'en': 'Other Institutions'},
                    'J': {'es': 'Administraci\u00F3n de Justicia',
                          'ca': 'Administraci\u00F3 de Just\u00EDcia',
                          'gl': 'Administraci\u00F3n de Xustiza',
                          'eu': 'Justizia Administrazioa',
                          'en': 'Legal Administration'},
                    'P': {'es': 'Entidad Privada',
                          'ca': 'Entitat privada',
                          'gl': 'Entidade Privada',
                          'eu': 'Erakunde pribatua',
                          'en': 'Private Entity'}
                    }

DEFAULT_UNIT = 'I'

PUBLISHER_TYPES = ['manual_loading_publishers', 'harvester_publishers', 'both']

DRUPAL_CONTENT_TYPES = {'app': {'color': "#76BEDF", 'bullet': "triangleDown",
                                'bulletSize': 10, "position": "left",
                                "offset": 0, "title": 'apps'},
                        'initiative': {'color': "#FF6600", 'bullet': "triangleRight",
                                       'bulletSize': 10, "position": "right",
                                       "offset": 0, "title": 'initiatives'},
                        'request': {'color': "#FCD202", 'bullet': "diamond",
                                    'bulletSize': 11, "position": "left",
                                    "offset": 50, "title": 'requests'},
                        'success': {'color': "#A1C51B", 'bullet': "triangleUp",
                                    'bulletSize': 10, "position": "right",
                                    "offset": 50, "title": 'empresas-reutilizadoras'}}

EXCLUDED_DRUPAL_CONTENT_TYPES = ['request']

SECTIONS = {'aplicaciones': {'color': "#76BEDF", 'bullet': "triangleDown",
                             'bulletSize': 10, },
            'iniciativas': {'color': "#FF6600", 'bullet': "triangleRight",
                            'bulletSize': 10},
            'peticiones-datos': {'color': "#FCD202", 'bullet': "diamond",
                                 'bulletSize': 11},
            'empresas-reutilizadoras': {'color': "#A1C51B", 'bullet': "triangleLeft",
                                        'bulletSize': 10},
            'dashboard': {'color': "#0000CC", 'bullet': "triangleUp",
                          'bulletSize': 10},
            'catalogo': {'color': "#D1655D", 'bullet': "round",
                         'bulletSize': 10},
            'documentacion': {'color': "#CD0D74", 'bullet': "diamond",
                              'bulletSize': 11},
            'noticias': {'color': '#AE60EA', 'bullet': "square",
                         'bulletSize': 8},
            'blog_blog': {'color': '#faf60f', 'bullet': "square",
                          'bulletSize': 9},
            'eventos': {'color': '#19AA7A', 'bullet': "square",
                        'bulletSize': 8},
            'entrevistas': {'color': '#FC6CBE', 'bullet': "square",
                            'bulletSize': 8},
            'boletines': {'color': '#65556B', 'bullet': "square",
                          'bulletSize': 8},
            'agricultura': {'color': '#30bf64', 'bullet': "rectangle",
                            'bulletSize': 8},
            'cultura': {'color': '#cc3e16', 'bullet': "rectangle",
                        'bulletSize': 8},
            'educacion': {'color': '#5E63D8', 'bullet': "rectangle",
                            'bulletSize': 8},
            'transporte': {'color': '#D3D85E', 'bullet': "rectangle",
                        'bulletSize': 8},
            'salud-bienestar': {'color': '#30f834', 'bullet': "rectangle",
                            'bulletSize': 8},
            'turismo': {'color': '#5E63D8', 'bullet': "rectangle",
                            'bulletSize': 8}}

PUBLISHER_TYPES = {'harvester_publishers': {'color': "#C64A1A", 'bullet': "bubble",
                                            'bulletSize': 12, },
                   'manual_loading_publishers': {'color': "#D3D85E", 'bullet': "bubble",
                                                 'bulletSize': 12},
                   'both': {'color': "#5E63D8", 'bullet': "bubble",
                                                 'bulletSize': 12},                             
                                                 }

log = logging.getLogger(__name__)

global_special_org_id = "a8693443-d272-48eb-b02e-a465ef2356f5"


def _dge_dashboard_get_backend(filepath=None):
    url = None
    try:
        backend = config.get('ckanext.dge_dashboard.backend', None)
        if backend and filepath:
            url = '%s%s' % (backend, filepath)
    except:
        url = None
    return url


def _dge_dashboard_convert_date(sdate=None):
    fdate = None
    if sdate:
        try:
            data_date = datetime.datetime.strptime(sdate, '%Y-%m-%d')
            language = dsh.lang()
            if language == 'en':
                fdate = data_date.strftime('%m-%d-%Y')
            else:
                fdate = data_date.strftime('%d/%m/%Y')
        except:
            data_date = None
    return fdate


def _dge_dashboard_user_organization():
    ''' Returns the first organization in which the user active is editor '''
    if c.userobj and c.userobj.sysadmin == False:
        orgs = toolkit.get_action('organization_list_for_user')(data_dict={'permission': 'read'})
        if orgs and len(orgs) > 0:
            return orgs[0]
    return None


def _dge_dashboard_organization_title(org_id=None):
    ''' Returns the organization name whose id is org_id '''
    if org_id:
        try:
            org = toolkit.get_action('organization_show')(data_dict={'id': org_id,
                                                                     'include_datasets': False,
                                                                     'include_extras': False,
                                                                     'include_users': False,
                                                                     'include_groups': False,
                                                                     'include_tags': False,
                                                                     'include_followers': False})
            if org:
                return org.get('title', org.get('name', None))
        except logic.NotFound:
            log.warn('Org with id %s not found' % org_id)
            return None

    return None


def _dge_dashboard_user_is_sysadmin():
    ''' Returns True if the user active is sysadmin '''
    org_id = None
    orgs = toolkit.get_action('organization_list_for_user')(data_dict={'permission': 'read'})
    if orgs and len(orgs) > 0:
        org_id = orgs[0].get('id', None) if orgs[0] else None
    aux = org_id.encode('ascii', 'ignore')
    if ((c.userobj and c.userobj.sysadmin == True) or (aux == global_special_org_id)):
        return True
    return False


def _dge_dashboard_theme_label(theme=None):
    '''
    Given an theme, get its label

    :param theme: format
    :type string

    :rtype string
    '''
    if theme:
        dataset = sh.scheming_get_schema('dataset', 'dataset')
        themes = sh.scheming_field_by_name(dataset.get('dataset_fields'),
                                           'theme')
        theme_label = sh.scheming_choices_label(themes['choices'], theme)
        if theme_label:
            return theme_label
    return theme


def _dge_dashboard_get_translated_administration_level(prefix=None):
    '''
    Given a prefix of administration level,
    returns translated administration level
    '''
    units = {'E': _('State Administration'),
             'A': _('Regional Administration'),
             'L': _('Local Administration'),
             'U': _('Universities'),
             'I': _('Other Institutions'),
             'J': _('Legal Administration'),
             'P': _('Private Entity')
             }
    if prefix and prefix in units:
        return units.get(prefix, None)
    else:
        return units.get(DEFAULT_UNIT, None)
    return None


def _dge_dashboard_sort_dict_by_administration_level_key(aux_dict=None):
    '''
        Sort a dictionary whose keys are ADMINISTRATION LEVEL letters
        in ORDER_UNITS order
    '''
    result = None
    if aux_dict:
        print aux_dict
        for unit in ORDER_UNITS:
            item = aux_dict.get(unit, None)
            if item:
                if result is None:
                    result = []
                result.append(item)
    return result


def _dge_dashboard_data_initial_date():
    for_date = None
    try:
        for_date = datetime.strptime(config.get('ckanext.dge_dashboard.portal_implementation_date'), '%Y-%m')
    except ValueError as e:
        log.error("Exception in _dge_dashboard_portal_implementation_date: %s", e)
    return for_date


def dge_dashboard_get_month(month=None, day=0):
    result = month
    if month:
        if month == 'All':
            result = _('All months')
        else:
            d = strptime(month, '%Y-%m')
            month_name = '%s %s' % (_(calendar.month_name[d.tm_mon]), d.tm_year)
            end = calendar.monthrange(d.tm_year, d.tm_mon)[1]
            if day > 0 and day < end:
                result = '%s (%s %s)' % (month_name, _('up to'), day)
            else:
                result = '%s' % _(month_name)
    return result


def _dge_dashboard_data_num_comments_by_month_year(url=None, id_organization=None):
    result_graphs = None
    result_data = []
    month_data = {}
    if url:
        tmp_data = None
        response = urllib.urlopen(url)
        if response:
            tmp_data = json.loads(response.read())
            if tmp_data:
                for item in tmp_data:
                    year = item.get('year', None)
                    if year:
                        if id_organization:
                            if item.get('org') and item.get('org') == id_organization:
                                month_data[item.get('year')] = {'year': item.get('year'), 'content_comments': item.get(
                                    'content_comments') if item.get('content_comments') else 0,
                                                                'dataset_comments': item.get(
                                                                    'dataset_comments') if item.get(
                                                                    'dataset_comments') else 0}
                        else:
                            month_data[item.get('year')] = {'year': item.get('year'), 'content_comments': item.get(
                                'content_comments') if item.get('content_comments') else 0,
                                                            'dataset_comments': item.get(
                                                                'dataset_comments') if item.get(
                                                                'dataset_comments') else 0}

    # generate result content
    str_initial_date = config.get('ckanext.dge_dashboard.initial_date', '2016-11')
    str_end_dat = datetime.datetime.now().strftime("%Y-%m")
    # if a previous date exists then it must be the initial date
    for month in month_data.keys():
        # the string dates can be comparated because its format
        if month < str_initial_date:
            str_initial_date = month
        if month > str_end_dat:
            str_end_dat = month

    initial_date = datetime.datetime.strptime(str_initial_date, '%Y-%m')
    end_date = datetime.datetime.strptime(str_end_dat, '%Y-%m')

    # generate output
    data = False
    if initial_date < end_date:
        delta = relativedelta(months=1)
        while initial_date < end_date:
            str_initial_date = initial_date.strftime("%Y-%m")
            if str_initial_date in month_data:
                result_data.append(month_data[str_initial_date])
                data = True
            else:
                result_data.append({'year': str_initial_date, 'content_comments': 0, 'dataset_comments': 0})
            initial_date += delta

    # last month only is displayed if exists information
    if str_end_dat in month_data:
        result_data.append(month_data[str_end_dat])

    # no data add some void info
    if not result_data:
        now = datetime.datetime.now()
        result_data.append({'year': now.strftime("%Y-%m")})

    if result_data:
        # set the information labels
        result_graphs = []
        result_graphs.append({
            "balloonText": "<b>[[title]]</b><br><span style='font-size:14px'>[[category]]: <b>[[value]]</b></span>",
            "bullet": "yError",
            "bulletColor": "#9400D3",
            "bulletBorderThickness": 2,
            #                     "customBullet": "/amcharts/data/images/purpleast.png",
            #                     "customBulletField": "customBullet",
            "bulletSize": 5,
            "bulletOffset": 1,
            "title": _('dataset_comments'),
            "valueField": 'dataset_comments',
            "fillAlphas": 0,
            "lineThickness": 3,
            "lineColor": "#9400D3",
            "lineAlpha": 1
        })
        result_graphs.append({
            "balloonText": "<b>[[title]]</b><br><span style='font-size:14px'>[[category]]: <b>[[value]]</b></span>",
            "bullet": "yError",
            "bulletColor": "#00CC00",
            "bulletBorderThickness": 2,
            "bulletOffset": 1,
            #                     "customBullet": "/amcharts/data/images/greenast.png",
            #                     "customBulletField": "customBullet",
            "bulletSize": 5,
            "title": _('content_comments'),
            "valueField": 'content_comments',
            "fillAlphas": 0,
            "lineThickness": 3,
            "lineColor": "#00CC00",
            "lineAlpha": 1
        })
    if not data:
        result_data = []
    return json.dumps(result_data), json.dumps(result_graphs)


################################################
## METODOS PARA CUADRO DE MANDO VISTA PUBLICA ##
################################################
def dge_dashboard_data_num_datasets_by_month_year():
    '''
    Returns data for datasets per month chart.
    Get data of endpoint set in ckanext.dge_dashboard.chart.datasets_month_year.url_data config property
    '''
    data = None
    result_data = []
    try:
        url = _dge_dashboard_get_backend(config.get('ckanext.dge_dashboard.chart.datasets_month_year.url_data', None))
        if url:
            response = urllib.urlopen(url)
            if response:
                data = json.loads(response.read())
                if data:
                    for item in data:
                        year = item.get("year", None)
                        value = item.get("value", 0)
                        if year and value:
                            result_data.append({"year": year, "value": value})
                    return json.dumps(result_data)
    except Exception as e:
        log.error('Exception in dge_dashboard_data_num_datasets_by_month_year: %s', e)
    return []


def dge_dashboard_data_num_datasets_by_administration_level():
    '''
    Returns data for published datataset per administration level.
    Get data of endpoint set in ckanext.dge_dashboard.chart.datasets_administration_level.url_data config property
    '''
    data = None
    result_data = []
    total = 0
    data_date = None
    try:
        url = _dge_dashboard_get_backend(
            config.get('ckanext.dge_dashboard.chart.datasets_administration_level.url_data', None))
        if url:
            response = urllib.urlopen(url)
            if response:
                data = json.loads(response.read())
        if data:
            adm_levels = {}
            for item in data:
                adm_level = item.get('administration_level', None)
                if adm_level:
                    total = total + item.get('num_datasets', 0)
                    translated = _dge_dashboard_get_translated_administration_level(adm_level)
                    if translated:
                        item['administration_level'] = translated
                    if not data_date:
                        data_date = _dge_dashboard_convert_date(item.get('date', None))
                    if  adm_levels.get(translated):
                        adm_levels[translated]['num_datasets'] = adm_levels[translated]['num_datasets'] + item.get('num_datasets', 0)
                    else:
                        adm_levels[translated] = item
            result_data.extend(adm_levels.values())
            return json.dumps(result_data), total, data_date
    except Exception as e:
        log.error(
            'Exception in dge_dashboard_data_num_datasets_by_administration_level: %s', e)
    return [], total, data_date


def dge_dashboard_data_distribution_format():
    '''
    Returns data for distribution format.
    Get data of endpoint set in ckanext.dge_dashboard.chart.distribution_format.url_data config property
    '''
    data = None
    result_data = []
    total = 0
    data_date = None
    try:
        url = _dge_dashboard_get_backend(config.get('ckanext.dge_dashboard.chart.distribution_format.url_data', None))
        if url:
            response = urllib.urlopen(url)
            if response:
                data = json.loads(response.read())
        if data:
            available_formats = {}
            top = 0;
            other = 0
            for item in data:
                total = total + item.get('value', 0)
                if not data_date:
                    data_date = _dge_dashboard_convert_date(item.get('date', None))
                format = item.get('format', None)
                if format:
                    if format.lower() not in available_formats:
                        available_formats[format] = dh.dge_resource_format_label(format.lower())
                    result_data.append(
                        {"date": item.get('date', ''), "format": available_formats.get(format.lower(), format),
                         "value": item.get('value', 0)})
            return json.dumps(result_data), total, data_date
    except Exception as e:
        log.error('Exception in dge_dashboard_data_distribution_format: %s', e)
    return [], total, data_date


def dge_dashboard_data_distribution_format_by_administration_level():
    '''
    Returns data for distribution format.
    Get data of endpoint set in ckanext.dge_dashboard.chart.distribution_format_administration_level_prueba1.url_data config property
    '''
    chartData = []
    data = None
    results = []
    result_data = {}
    result_levels = {}
    result_totals = {}
    data_date = None
    total = 0
    try:
        url = _dge_dashboard_get_backend(
            config.get('ckanext.dge_dashboard.chart.distribution_format_administration_level.url_data', None))
        if url:
            response = urllib.urlopen(url)
            if response:
                data = json.loads(response.read())
        if data:
            available_formats = {}
            top = 0;
            other = 0
            list_adm_level = []
            for item in data:
                nitem = {}
                level = None
                for key, value in item.iteritems():
                    if key == 'date':
                        if value:
                            nitem[key] = value
                            if not data_date:
                                data_date = _dge_dashboard_convert_date(value)
                    elif key == 'level':
                        if value:
                            level = value.upper();
                            if not (result_levels.get(level, None)):
                                translated = _dge_dashboard_get_translated_administration_level(value)
                                if translated:
                                    result_levels[level] = translated
                    elif key == 'format':
                        if value:
                            if value.lower() not in available_formats:
                                available_formats[value] = dh.dge_resource_format_label(value.lower())
                            nitem[key] = available_formats.get(value.lower(), value)
                    elif key == 'value':
                        if value:
                            nitem[key] = value
                            result_totals[level] = result_totals.get(level, 0) + value
                if nitem and nitem.get('date', None) and nitem.get('format', None) and nitem.get('value', None):
                    if (result_data.get(level, None)) is None:
                        result_data[level] = []
                    result_data[level].append(nitem)
            for key, value in result_data.iteritems():
                value = sorted(value, key=lambda k: k['value'], reverse=True)
                result_data[key] = json.dumps(value)

            for unit in ORDER_UNITS:
                data_unit = result_data.get(unit, None)
                if data_unit:
                    results.append((unit, data_unit, result_levels[unit], result_totals[unit]))
            return results, data_date
    except Exception as e:
        log.error('Exception in dge_dashboard_data_distribution_format_by_administration_level: %s', e)
    return [], data_date


def dge_dashboard_data_num_drupal_contents():
    '''
    Returns data for drupal contents.
    Get data of endpoint set in ckanext.dge_dashboard.chart.drupal_contents_month_year.url_data config property
    '''
    data = None
    result_data = []
    result_value_axis = None
    result_graphs = None
    try:
        url = _dge_dashboard_get_backend(
            config.get('ckanext.dge_dashboard.chart.drupal_contents_month_year.url_data', None))
        initial_zoom = config.get('ckanext.dge_dashboard.chart.drupal_contents_month_year.inital_zoom', 0.8)
        if url:
            response = urllib.urlopen(url)
            if response:
                data = json.loads(response.read())
        if data:
            types = []
            for item in data:
                result_data.append(item)
                for key, value in item.iteritems():
                    if key != 'date' \
                            and key in DRUPAL_CONTENT_TYPES \
                            and key not in EXCLUDED_DRUPAL_CONTENT_TYPES \
                            and key not in types:
                        types.append(key)
            if types and len(types) > 0:
                types.sort()
                result_value_axis = []
                result_graphs = []
                for type in types:
                    result_value_axis.append({"id": "v_" + type,
                                              "axisThickness": 2,
                                              "axisAlpha": 1,
                                              "position": DRUPAL_CONTENT_TYPES[type]['position'],
                                              "offset": DRUPAL_CONTENT_TYPES[type]['offset'],
                                              "axisColor": DRUPAL_CONTENT_TYPES[type]['color'],
                                              "integersOnly": "true"
                                              })
                    result_graphs.append({"valueAxis": "v_" + type,
                                          "balloonText": "[[title]] :[[value]]",
                                          "lineColor": DRUPAL_CONTENT_TYPES[type]['color'],
                                          "bullet": DRUPAL_CONTENT_TYPES[type]['bullet'],
                                          "bulletSize": DRUPAL_CONTENT_TYPES[type]['bulletSize'],
                                          "bulletBorderThickness": 1,
                                          "hideBulletsCount": 50,
                                          "lineThickness": 3,
                                          "title": _(DRUPAL_CONTENT_TYPES[type]['title']),
                                          "valueField": type,
                                          "fillAlphas": 0
                                          })
            return json.dumps(result_data), json.dumps(result_value_axis), json.dumps(result_graphs), initial_zoom
    except Exception as e:
        log.error('Exception in dge_dashboard_data_num_drupal_contents: %s', e)
    return [], [], [], initial_zoom


def dge_dashboard_data_num_datasets_by_category():
    '''
    Returns data for datasets per category chart.
    Get data of endpoint set in ckanext.dge_dashboard.chart.datasets_category.url_data config property
    '''
    result_data = []
    data = None
    data_date = None
    try:
        url = _dge_dashboard_get_backend(config.get('ckanext.dge_dashboard.chart.datasets_category.url_data', None))
        if url:
            response = urllib.urlopen(url)
            if response:
                data = json.loads(response.read())
        if data:
            data_date = None
            for item in data:
                if not data_date:
                    data_date = _dge_dashboard_convert_date(item.get('date', None))
                theme = item.get('theme', None)
                if theme:
                    label_theme = theme
                    label_theme = _dge_dashboard_theme_label(theme)
                    result_data.append(
                        {"date": item.get('date', ''), "theme": label_theme, "value": item.get('value', 0)})
            return json.dumps(result_data), data_date
    except Exception as e:
        log.error('Exception in dge_dashboard_data_num_datasets_by_category: %s', e)
    return [], data_date


def dge_dashboard_data_num_visits():
    '''
    Returns data for datos.gob.es visits per month.
    Get data of endpoint set in ckanext.dge_dashboard.chart.visits_month_year.url_data config property
    '''
    data = None
    result_data = []
    try:
        url = _dge_dashboard_get_backend(config.get('ckanext.dge_dashboard.chart.visits_month_year.url_data', None))
        if url:
            response = urllib.urlopen(url)
            if response:
                data = json.loads(response.read())
                if data:
                    for item in data:
                        date = item.get("date", None)
                        value = item.get("value", 0)
                        if date and value:
                            result_data.append({"date": date, "value": value})
                    return json.dumps(result_data)
    except Exception as e:
        log.error('Exception in dge_dashboard_data_num_visits: %s', e)
    return []


def dge_dashboard_data_most_visited_datasets(visible_visits=None):
    '''
    Returns data for the most visited datasets.
    Get data of endpoint set in ckanext.dge_dashboard.chart.most_visited_datasets.url_data config property
    '''
    data = None
    result_data = []
    if not visible_visits:
        visible_visits = converters.asbool(
            config.get('ckanext.dge_dashboard.chart.most_visited_datasets.num_visits.visible', False))
    month_list = []
    month_name_list = []
    month_name_dict = {}
    column_titles = [_('Month'), _('Order'), _('Dataset'), _('Publisher'), _('Visits')]
    try:
        url = _dge_dashboard_get_backend(config.get('ckanext.dge_dashboard.chart.most_visited_datasets.url_data', None))
        if url:
            response = urllib.urlopen(url)
            if response:
                data = json.loads(response.read())
                if data:
                    prefix_url = config.get('ckan.site_url') + h.url_for(controller='package', action='search') + "/"
                    index = prefix_url.find('://')
                    if c.userobj and index >= 0:
                        prefix_url = 'https' + prefix_url[index:]
                    for item in data:
                        if item:
                            new_item = {}
                            month = item.get('month', None)
                            day = item.get('day', 0)
                            if month:
                                month_name = ''
                                if month and month in month_list:
                                    month_name = month_name_dict.get(month, '')
                                else:
                                    month_list.append(month)
                                    month_name = dge_dashboard_get_month(month, day)
                                    month_name_list.append({"id": month.replace('-', ''), "name": month_name})
                                    month_name_dict[month] = month_name
                                new_item["month"] = month_name
                                new_item["month_id"] = month.replace('-', '')
                                new_item["order"] = item.get('order', '')
                                new_item["url"] = item.get('name', '')
                                new_item["title"] = item.get('title', '')
                                new_item["package"] = "<a href='%s%s'>%s</a>" % (
                                    prefix_url, item.get('name', ''), item.get('title', ''))
                                new_item["publisher"] = item.get('publisher', '')
                                if visible_visits:
                                    new_item["visits"] = item.get('visits', 0)
                                result_data.append(new_item)
    except Exception as e:
        log.error('Exception in dge_dashboard_data_most_visited_datasets: %s', e)
        result_data = []
    if result_data and len(result_data) > 0:
        return json.dumps(result_data), json.dumps(month_name_list), month_name_list, json.dumps(
            column_titles), visible_visits
    else:
        return [], json.dumps(month_name_list), month_name_list, json.dumps(column_titles), visible_visits


def dge_get_visibility_of_public_graphs(graph_names=None):
    visibility = {}
    if graph_names:
        for name in graph_names:
            if name:
                if name == 'chartVisitsDatosGobEsByMonth':
                    visibility[name] = converters.asbool(
                        config.get('ckanext.dge_dashboard.chart.visits_month_year.visible', False))
                elif name == 'chartNumDrupalContentsByMonthYear':
                    visibility[name] = converters.asbool(
                        config.get('ckanext.dge_dashboard.chart.drupal_contents_month_year.visible', False))
                elif name == 'chartNumDatasetsByMonthYear':
                    visibility[name] = converters.asbool(
                        config.get('ckanext.dge_dashboard.chart.datasets_month_year.visible', False))
                elif name == 'chartNumDatasetsByAdministrationLevel':
                    visibility[name] = converters.asbool(
                        config.get('ckanext.dge_dashboard.chart.datasets_administration_level.visible', False))
                elif name == 'chartNumDatasetsByCategory':
                    visibility[name] = converters.asbool(
                        config.get('ckanext.dge_dashboard.chart.datasets_category.visible', False))
                elif name == 'chartMostVisitedDatasets':
                    visibility[name] = converters.asbool(
                        config.get('ckanext.dge_dashboard.chart.most_visited_datasets.visible', False))
                elif name == 'chartDistributionFormat':
                    visibility[name] = converters.asbool(
                        config.get('ckanext.dge_dashboard.chart.distribution_format.visible', False))
                elif name == 'chartDistributionFormatByAdministrationLevel':
                    visibility[name] = converters.asbool(
                        config.get('ckanext.dge_dashboard.chart.distribution_format_administration_level.visible',
                                   False))
    return visibility


##################################################
## METODOS PARA CUADRO DE MANDO VISTA ORGANISMO ##
##################################################
def dge_dashboard_organization_data_num_datasets_by_month_year():
    '''
    Returns data for datasets per month chart.
    Get data of endpoint set in ckanext.dge_dashboard.chart.org.datasets_month_year.url_data config property
    '''
    data = None
    result_data = None
    error_loading_data = True
    try:
        organization = _dge_dashboard_user_organization();
        organization_id = organization.get('id', None) if organization else None
        if organization_id:
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.org.datasets_month_year.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
                    if data:
                        for item in data:
                            org = item.get('org', None)
                            if org and org == organization_id:
                                if result_data is None:
                                    result_data = []
                                result_data.append({'year': item.get('year'), 'value': item.get('value')})
            if result_data:
                return json.dumps(result_data), error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_organization_data_num_datasets_by_month_year: %s', e)
        error_loading_data = True
    return [], error_loading_data


def dge_dashboard_organization_data_distribution_format():
    '''
    Returns data for distribution format.
    Get data of endpoint set in ckanext.dge_dashboard.chart.org.distribution_format.url_data config property
    '''
    data = None
    result_data = []
    total = 0
    data_date = None
    error_loading_data = True
    try:
        organization = _dge_dashboard_user_organization();
        organization_id = organization.get('id', None) if organization else None
        if organization_id:
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.org.distribution_format.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
            if data:
                available_formats = {}
                top = 0;
                other = 0
                for item in data:
                    org = item.get('org_id', None)
                    if org and org == organization_id:
                        total = total + item.get('value', 0)
                        if not data_date:
                            data_date = _dge_dashboard_convert_date(item.get('date', None))
                        format = item.get('format', None)
                        if format:
                            if format.lower() not in available_formats:
                                available_formats[format] = dh.dge_resource_format_label(format.lower())
                        result_data.append(
                            {"date": item.get('date', ''), "format": available_formats.get(format.lower(), format),
                             "value": item.get('value', 0)})
                return json.dumps(result_data), total, data_date, error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_organization_data_distribution_format: %s', e)
        error_loading_data = True
    return [], total, data_date, error_loading_data


def dge_dashboard_organization_data_users():
    '''
    Returns data for active users.
    Get data of endpoint set in ckanext.dge_dashboard.chart.org.users.url_data config property
    '''
    data = None
    result_data = None
    total = 0
    data_date = None
    error_loading_data = True
    column_titles = [_('Users number')]
    try:
        organization = _dge_dashboard_user_organization();
        organization_id = organization.get('id', None) if organization else None
        if organization_id:
            url = _dge_dashboard_get_backend(config.get('ckanext.dge_dashboard.chart.org.users.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
            if data:
                available_formats = {}
                top = 0;
                other = 0
                for item in data:
                    org = item.get('org_id', None)
                    if org and org == organization_id:
                        users = item.get('users', None)
                        if users:
                            if not data_date:
                                data_date = _dge_dashboard_convert_date(item.get('date', None))
                            # result_data = users.split(',')
                            list_users = users.split(',')
                            for user in list_users:
                                if result_data is None:
                                    result_data = []
                                result_data.append({'username': user, 'date': data_date})
                            total = len(result_data) if result_data else 0
                            column_titles = ['%s: %s' % (_('Users number'), total)]
                        return json.dumps(result_data), json.dumps(column_titles), total, data_date, error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_organization_data_users: %s', e)
        error_loading_data = True
    return [], json.dumps(column_titles), total, data_date, error_loading_data


def dge_dashboard_organization_data_assigned_requests():
    '''
    Returns data for assigned and published requests.
    Get data of endpoint set in ckanext.dge_dashboard.chart.org.assigned_requests.url_data config property
    '''
    data = None
    result_data = None
    total = 0
    data_date = None
    error_loading_data = True
    try:
        organization = _dge_dashboard_user_organization();
        organization_id = organization.get('id', None) if organization else None
        if organization_id:
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.org.assigned_requests.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
            if data:
                available_formats = {}
                top = 0;
                other = 0
                for item in data:
                    org = item.get('org_id', None)
                    if org and org == organization_id:
                        if not data_date:
                            data_date = _dge_dashboard_convert_date(item.get('date', None))
                        if result_data is None:
                            result_data = []
                        result_data.append({'date': item.get('date', ''), 'state': item.get('state', ''),
                                            'value': item.get('value', 0)})
                        total = total + item.get('value', 0)
            if result_data:
                return json.dumps(result_data), total, data_date, error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_organization_data_assigned_requests: %s', e)
        error_loading_data = True
    return [], total, data_date, error_loading_data


def dge_dashboard_organization_data_num_comments_by_month_year():
    '''
    Returns comments for datasets and contents per month chart.
    Get data of endpoint set in ckanext.dge_dashboard.chart.org.comments_month_year.url_data config property
    '''
    data = None
    result_data = None
    result_graphs = None
    error_loading_data = True
    try:
        organization = _dge_dashboard_user_organization();
        organization_id = organization.get('id', None) if organization else None
        if organization_id:
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.org.comments_month_year.url_data', None))
            if url:
                error_loading_data = False
                result_data, result_graphs = _dge_dashboard_data_num_comments_by_month_year(url, organization_id)
                return result_data, result_graphs, error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_organization_data_num_comments_by_month_year: %s', e)
        error_loading_data = True
    return [], [], error_loading_data


def dge_dashboard_organization_data_most_visited_datasets():
    '''
    Returns data for the most visited datasets.
    Get data of endpoint set in ckanext.dge_dashboard.chart.org.most_visited_datasets.url_data config property
    '''
    data = None
    result_data = []
    month_list = []
    month_name_list = []
    month_name_dict = {}
    error_loading_data = True
    column_titles = [_('Month'), _('Dataset'), _('Publisher'), _('Visits'), _('Downloads')]
    try:
        organization = _dge_dashboard_user_organization();
        organization_id = organization.get('id', None) if organization else None
        if organization_id:
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.org.most_visited_datasets.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
                    if data:
                        prefix_url = config.get('ckan.site_url') + h.url_for(controller='package',
                                                                             action='search') + "/"
                        index = prefix_url.find('://')
                        if c.userobj and index >= 0:
                            prefix_url = 'https' + prefix_url[index:]

                        for item in data:
                            if item:
                                org = item.get('org_id', None)
                                if org and org == organization_id:
                                    new_item = {}
                                    month = item.get('month', '')
                                    day = item.get('day', 0)
                                    month_name = ''
                                    if month and month in month_list:
                                        month_name = month_name_dict.get(month, '')
                                    else:
                                        month_list.append(month)
                                        month_name = dge_dashboard_get_month(month, day)
                                        month_name_list.append({"id": month.replace('-', ''), "name": month_name})
                                        month_name_dict[month] = month_name
                                    new_item["month"] = month_name
                                    new_item["month_id"] = month.replace('-', '')
                                    new_item["url"] = item.get('name', '')
                                    new_item["title"] = item.get('title', '')
                                    new_item["package"] = "<a href='%s%s'>%s</a>" % (
                                        prefix_url, item.get('name', ''), item.get('title', ''))
                                    new_item["publisher"] = item.get('publisher', '')
                                    new_item['visits'] = item.get('visits', 0)
                                    new_item['downloads'] = item.get('downloads', 0)
                                    result_data.append(new_item)
                        result_data = sorted(result_data, key=lambda k: k['visits'], reverse=True)
    except Exception as e:
        log.error('Exception in dge_dashboard_organization_data_most_visited_datasets: %s', e)
        error_loading_data = True
    return json.dumps(result_data), json.dumps(month_name_list), month_name_list, json.dumps(
        column_titles), error_loading_data


######################################################
## METODOS PARA CUADRO DE MANDO VISTA ADMINISTRADOR ##
######################################################
def dge_dashboard_administrator_data_num_datasets_by_administration_level():
    '''
    Returns data for published datataset per administration level.
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.datasets_administration_level.url_data config property
    '''
    data = None
    result_data = []
    result_graphs = None
    graphs = None
    error_loading_data = True
    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.datasets_administration_level.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
                if data:
                    list_adm_level = []
                    for item in data:
                        if item.get('year', None):
                            for key, value in item.iteritems():
                                if (key != 'year') and key not in list_adm_level:
                                    list_adm_level.append(key)
                                    translated = _dge_dashboard_get_translated_administration_level(key)
                                    if graphs is None:
                                        graphs = {}
                                    graphs[key] = {
                                        "balloonText": "<b>[[title]]</b><br><span style='font-size:14px'>[[category]]: <b>[[value]]</b></span>",
                                        "bullet": "round",
                                        "title": translated,
                                        "valueField": key,
                                        "fillAlphas": 0.5,
                                        "lineAlpha": 0.5,
                                        "lineThickness": 2
                                    }
                            result_data.append(item)
        result_graphs = _dge_dashboard_sort_dict_by_administration_level_key(graphs)
        return json.dumps(result_data), json.dumps(result_graphs), error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_data_num_datasets_by_administration_level: %s', e)
        error_loading_data = True
    return [], [], error_loading_data


def dge_dashboard_administrator_data_num_datasets_by_organization():
    '''
    Returns data for datasets per organization.
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.datasets_month_year_org.url_data config property
    '''
    data = None
    result_data = []
    error_loading_data = True
    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.datasets_month_year_org.url_data', None))
            url_2 = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.organizations_name.url_data', None))
            data = None
            data2 = None
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
            if url_2:
                error_loading_data = False
                response2 = urllib.urlopen(url_2)
                if response2:
                    data2 = json.loads(response2.read())
            if data and data2:
                orgs = []
                not_found_orgs = []
                for item in data:
                    org = item.get('org', None)
                    value = item.get('value', None)
                    year = item.get('year', None)
                    index_org = None
                    nitem = None
                    if org and value and year:
                        if org in orgs:
                            index_org = orgs.index(org)
                            nitem = result_data[index_org]
                            dataProvider = nitem.get('dataProvider', [])
                            dataProvider.append({"year": year, "value": value})
                            nitem['dataProvider'] = dataProvider
                        elif org in not_found_orgs:
                            pass
                        else:
                            # Comprobar que el usuario no sea la organizacion "aportaview". Si lo es, hacemos el not_found si es admin, que haga el org_title
                            org_id_aux = None
                            orgs_aux = toolkit.get_action('organization_list_for_user')(
                                data_dict={'permission': 'read'})
                            if orgs_aux and len(orgs_aux) > 0:
                                org_id_aux = orgs_aux[0].get('id', None) if orgs_aux[0] else None
                            aux = org_id_aux.encode('ascii', 'ignore')
                            if (aux == global_special_org_id):
                                org_title = None
                                for item2 in data2:
                                    if org in orgs:
                                        pass
                                    else:
                                        id_aux = item2.get('id', None)
                                        title = item2.get('title', None)
                                        if (org == id_aux):
                                            org_title = title
                                        if org_title:
                                            orgs.append(org)
                                            result_data.append({
                                                "title": org_title,
                                                "fieldMappings": [{"fromField": "value", "toField": "value"}],
                                                "dataProvider": [{"year": year, "value": value}],
                                                "categoryField": "year"})
                                        else:
                                            not_found_orgs.append(org)
                            else:
                                org_title = _dge_dashboard_organization_title(org)
                                if org_title:
                                    orgs.append(org)
                                    result_data.append({
                                        "title": org_title,
                                        "fieldMappings": [{"fromField": "value", "toField": "value"}],
                                        "dataProvider": [{"year": year, "value": value}],
                                        "categoryField": "year"})
                                else:
                                    not_found_orgs.append(org)
                result_data = sorted(result_data, key=lambda k: k['title'])
                return json.dumps(result_data), error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_data_num_datasets_by_organization: %s', e)
        error_loading_data = True
    return [], error_loading_data


def dge_dashboard_administrator_data_num_datasets_by_num_resources():
    '''
    Returns data for datasets per organization.
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.datasets_month_year_num_res.url_data config property
    '''
    result_data = []
    month_list = []
    month_name_list = []
    month_name_dict = {}
    column_titles = [_('Month'), _('Resources Number'), _('Datasets Number')]
    error_loading_data = True
    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.datasets_month_year_num_res.url_data', None))
            data = None
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
            if data:
                num_res = []
                for item in data:
                    nr = item.get('num_res', None)
                    if nr:
                        new_item = {}
                        value = item.get('value', 0)
                        month = item.get('year', None)
                        month_name = ''
                        if month and month in month_list:
                            month_name = month_name_dict.get(month, '')
                        else:
                            month_list.append(month)
                            month_name = dge_dashboard_get_month(month, 0)
                            month_name_list.append({"id": month.replace('-', ''), "name": month_name})
                            month_name_dict[month] = month_name
                        new_item["month"] = month_name
                        new_item["month_id"] = month.replace('-', '')
                        new_item["num_resources"] = int(item.get('num_res', '0'))
                        new_item["num_datasets"] = item.get('value', 0)
                        result_data.append(new_item)
                if result_data:
                    result_data = sorted(result_data, key=lambda k: k['num_resources'])
                if month_name_list:
                    month_name_list = sorted(month_name_list, key=lambda k: k['id'], reverse=True)
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_data_num_datasets_by_num_resources: %s', e)
        result_data = []
        error_loading_data = True
    return json.dumps(result_data), json.dumps(month_name_list), month_name_list, json.dumps(
        column_titles), error_loading_data


def dge_dashboard_administrator_data_num_publishers_by_month_year():
    '''
    Returns data for publishers per month-year.
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.publishers_month_year.url_data config property
    '''
    data = None
    result_data = []
    result_graphs = []
    error_loading_data = True
    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.publishers_month_year.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
                if data:
                    list_adm_level = []
                    for item in data:
                        if item.get('year', None):
                            result_data.append(item)
                            for key, value in item.iteritems():
                                if (key != 'year') and key not in list_adm_level:
                                    list_adm_level.append(key)
                                    if result_graphs is None:
                                        result_graphs = []
                                    result_graphs.append({
                                        "balloonText": "<b>[[title]]</b><br><span style='font-size:14px'>[[category]]: <b>[[value]]</b></span>",
                                        "bullet": PUBLISHER_TYPES[key]['bullet'],
                                        "bulletSize": PUBLISHER_TYPES[key]['bulletSize'],
                                        "title": _(key),
                                        "valueField": key,
                                        "fillAlphas": 0.5,
                                        "lineAlpha": 0.5,
                                        "lineColor": PUBLISHER_TYPES[key]['color'],
                                        "bulletBorderThickness": 1,
                                        "hideBulletsCount": 50,
                                        "lineThickness": 3
                                    })
                return json.dumps(result_data), json.dumps(result_graphs), error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_data_num_publishers_by_month_year: %s', e)
        error_loading_data = True
    return [], [], error_loading_data


def dge_dashboard_administrator_data_num_publishers_by_administration_level():
    '''
    Returns data for publishers per administration_level.
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.publishers_adm_level.url_data config property
    '''
    data = None
    result_data = []
    result_graphs = []
    data_date = None
    nitems = {}
    error_loading_data = False
    try:
        url = _dge_dashboard_get_backend(
            config.get('ckanext.dge_dashboard.chart.adm.publishers_adm_level.url_data', None))
        if url:
            response = urllib.urlopen(url)
            if response:
                data = json.loads(response.read())
            if data:
                for item in data:
                    if not data_date:
                        data_date = _dge_dashboard_convert_date(item.get('date', None))
                    adm_level = item.get('adm_level', None)
                    if adm_level:
                        nitems[adm_level] = {'date': item.get('date', ''),
                                             'category': _dge_dashboard_get_translated_administration_level(adm_level)}
                        for key in PUBLISHER_TYPES:
                            nitems[adm_level][key] = item.get(key, 0)
            sort_result = _dge_dashboard_sort_dict_by_administration_level_key(nitems)
            if sort_result:
                result_data = sort_result
            for key in PUBLISHER_TYPES:
                result_graphs.append({
                    "balloonText": "<b>[[title]]</b><br><span style='font-size:14px'>[[category]]: <b>[[value]]</b></span>",
                    "type": "column",
                    "title": _(key),
                    "valueField": key,
                    "fillAlphas": 1,
                    "balloonText": "<b>[[title]]</b><br><span style='font-size:14px'>[[category]]: <b>[[value]]</b></span>",
                    "lineColor": PUBLISHER_TYPES[key]['color']})
            return json.dumps(result_data), json.dumps(result_graphs), data_date, error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_data_num_publishers_by_administration_level: %s', e)
        error_loading_data = True
    return [], [], data_date, error_loading_data


def dge_dashboard_administrator_data_assigned_requests():
    '''
    Returns data for assigned requests.
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.assigned_requests.url_data config property
    '''
    data = None
    result_data = []
    total = 0
    data_date = None
    error_loading_data = True
    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.assigned_requests.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
            if data:
                available_formats = {}
                top = 0;
                other = 0
                for item in data:
                    if item.get('state', None):
                        if not data_date:
                            data_date = _dge_dashboard_convert_date(item.get('date', None))
                        result_data.append({'date': item.get('date', ''), 'state': _(item.get('state', '')),
                                            'value': item.get('value', 0)})
                        total = total + item.get('value', 0)
                return json.dumps(result_data), total, data_date, error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_data_assigned_requests: %s', e)
        error_loading_data = True
    return [], total, data_date, error_loading_data


def dge_dashboard_administrator_data_users():
    '''
    Returns data for num of active users by organization.
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.users.url_data config property
    '''
    data = None
    result_data = []
    total = 0
    data_date = None
    error_loading_data = True
    column_titles = [_('Organization name'), _('Users number')]
    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(config.get('ckanext.dge_dashboard.chart.adm.users.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
            if data:
                for item in data:
                    org = item.get('org_name', None)
                    if org:
                        users = item.get('num_users', 0)
                        total = total + users
                        if not data_date:
                            data_date = _dge_dashboard_convert_date(item.get('date', None))
                        result_data.append({'organization': org, 'num_users': users, 'date': item.get('date', '')})
                column_titles = [_('Organization name'), ' %s<br/>(%s: %s)' % (_('Users number'), _('Total'), total)]
                result_data = sorted(result_data, key=lambda k: k['organization'], reverse=False)
                return json.dumps(result_data), json.dumps(column_titles), total, data_date, error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_data_users: %s', e)
        error_loading_data = True
    return [], json.dumps(column_titles), total, data_date, error_loading_data


def dge_dashboard_administrator_data_users_by_adm_level():
    '''
    Returns data for num of active users by administration_level.
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.users_adm_level.url_data config property
    '''
    data = None
    result_data = []
    total = 0
    data_date = None
    error_loading_data = True
    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.users_adm_level.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
            if data:
                adm_levels = {}
                for item in data:
                    adm_level = item.get('adm_level', None)
                    if adm_level:
                        total = total + item.get('num_users', 0)
                        translated = _dge_dashboard_get_translated_administration_level(adm_level)
                        if translated:
                            item['adm_level'] = translated
                        if not data_date:
                            data_date = _dge_dashboard_convert_date(item.get('date', None))
                        if  adm_levels.get(translated):
                            adm_levels[translated]['num_users'] = adm_levels[translated]['num_users'] + item.get('num_users', 0)
                        else:
                            adm_levels[translated] = item
                result_data.extend(adm_levels.values())
                return json.dumps(result_data), total, data_date, error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_data_users_by_adm_level: %s', e)
        error_loading_data = True
    return [], total, data_date, error_loading_data


def dge_dashboard_administrator_published_drupal_contents():
    '''
    Returns data for num of published drupal contents by content type.
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.pusblished_drupal_contents.url_data config property
    '''
    data = None
    result_data = []
    total = 0
    data_date = None
    error_loading_data = True
    column_titles = [_('Content type'), _('Content number')]
    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.pusblished_drupal_contents.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
            if data:
                for item in data:
                    content_type = item.get('content_type', None)
                    if content_type:
                        num_contents = item.get('num_contents', 0)
                        total = total + num_contents
                        if not data_date:
                            data_date = _dge_dashboard_convert_date(item.get('date', None))
                        result_data.append(
                            {'content_type': _(content_type), 'num_contents': num_contents, 'date': data_date})
                column_titles = [_('Content type'), ('%s<br/>(%s: %s)' % (_('Content number'), _('Total'), total))]
                result_data = sorted(result_data, key=lambda k: k['content_type'], reverse=False)
                return json.dumps(result_data), json.dumps(column_titles), total, data_date, error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_published_drupal_contents: %s', e)
        error_loading_data = True
    return [], json.dumps(column_titles), total, data_date, error_loading_data


def dge_dashboard_administrator_drupal_contents_by_likes(limit=None):
    data = None
    error_loading_data = True
    likes_template = u'{} ({}: {{}})'.format(_('Likes'), _('Total'))
    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.drupal_contents_by_likes.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.load(response, encoding='latin1')
            if data:
                translated = data['data']
                total = 0
                for c, obj in enumerate(translated, 1):
                    obj['name'] = _(obj['name'])
                    obj['content_type'] = _(obj['content_type'])
                    obj['link'] = u'<a href="{url}">{name}</a>'.format(**obj)
                    total += obj['likes']
                    if limit is not None and limit == c:
                        break

                return ({
                            'data': json.dumps(translated if limit is None else translated[:limit]),
                            'update_date': data['update_date']
                        },
                        json.dumps([_('Name'), _('URL'), likes_template.format(int(total)), _('Content type')]),
                        error_loading_data)
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_drupal_contents_by_likes: %s', e)
        error_loading_data = True

    return ({
                'data': '[]',
                'update_date': data['update_date']
            },
            json.dumps([_('Name'), _('URL'), likes_template.format(0), _('Content type')]),
            error_loading_data)


def dge_dashboard_administrator_drupal_top10_voted_datasets(limit=None):
    data = None
    error_loading_data = True
    likes_template = u'{} ({}: {{}})'.format(_('Likes'), _('Total'))
    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.drupal_top10_voted_datasets.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.load(response, encoding='latin1')
            if data:
                translated = data['data']
                total = 0
                for c, obj in enumerate(translated, 1):
                    obj['name'] = _(obj['name'])
                    obj['link'] = u'<a href="{url}">{name}</a>'.format(**obj)
                    total += obj['likes']
                    if limit is not None and c == limit:
                        break

                return ({
                            'data': json.dumps(translated if limit is None else translated[:limit]),
                            'update_date': data['update_date']
                        },
                        json.dumps([_('Name'), _('URL'), likes_template.format(int(total))]),
                        error_loading_data)
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_drupal_top10_voted_datasets: %s\n%s\n' %
                  (e, traceback.format_exc()))
        error_loading_data = True

    return {'data': '[]', 'update_date': None}, \
           json.dumps([_('Name'), _('URL'), likes_template.format(0)]), \
           error_loading_data


def dge_dashboard_administrator_data_num_comments_by_month_year():
    '''
    Returns comments for datasets and drupal contents per month-year.
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.comments_month_year.url_data config property
    '''
    result_data = None
    result_graphs = None
    error_loading_data = True
    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.comments_month_year.url_data', None))
            if url:
                error_loading_data = False
                result_data, result_graphs = _dge_dashboard_data_num_comments_by_month_year(url)
                return result_data, result_graphs, error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_published_drupal_contents: %s', e)
        error_loading_data = True
    return [], [], error_loading_data


def dge_dashboard_administrator_data_num_visits_by_section():
    '''
    Returns data for datos.gob.es visits per month by section
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.visits_month_year.url_data config property
    '''
    data = None
    result_data = []
    result_graphs = None
    error_loading_data = True
    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.visits_month_year.url_data', None))
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
                if data:
                    section_list = []
                    for item in data:
                        nitem = {}
                        if item.get('date', None):
                            for key, value in item.iteritems():
                                if (key != 'date') and key not in section_list:
                                    section_list.append(key)
                                    if result_graphs is None:
                                        result_graphs = []
                                    result_graphs.append({
                                        "balloonText": "<b>[[title]]</b><br><span style='font-size:14px'>[[category]]: <b>[[value]]</b></span>",
                                        "bullet": "round",
                                        "title": _(key),
                                        "valueField": key,
                                        "fillAlphas": 0,
                                        "lineAlpha": 1,
                                        "lineColor": SECTIONS[key]['color'],
                                        "bullet": SECTIONS[key]['bullet'],
                                        "bulletSize": SECTIONS[key]['bulletSize'],
                                        "bulletBorderThickness": 1,
                                        "hideBulletsCount": 50,
                                        "lineThickness": 2
                                    })
                            result_data.append(item)
                return json.dumps(result_data), json.dumps(result_graphs), error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_data_num_visits_by_section: %s', e)
        error_loading_data = True
    return [], [], error_loading_data


def dge_dashboard_administrator_datasets_by_org():
    '''
    Returns the number of datasets per organization. 
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.datasets_month_year_org.url_data config property
    '''
    data = None
    result_data = []
    error_loading_data = True

    try:
        if _dge_dashboard_user_is_sysadmin():
            url = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.datasets_month_year_org.url_data', None))
            url_2 = _dge_dashboard_get_backend(
                config.get('ckanext.dge_dashboard.chart.adm.organizations_name.url_data', None))
            data = None
            data2 = None
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
            if url_2:
                error_loading_data = False
                response2 = urllib.urlopen(url_2)
                if response2:
                    data2 = json.loads(response2.read())

            if data and data2:
                orgs = []
                not_found_orgs = []
                header = []
                for item in data:
                    org = item.get('org', None)
                    value = item.get('value', None)
                    year = item.get('year', None)
                    index_org = None
                    nitem = None
                    if org and value and year:
                        # add header
                        if year not in header:
                            header.append(year)
                        if org in orgs:
                            index_org = orgs.index(org)
                            nitem = result_data[index_org]
                            nitem.get('data')[year] = value
                        elif org in not_found_orgs:
                            pass
                        else:
                            # Comprobar que el usuario no sea la organizacion "aportaview". Si lo es, hacemos el not_found si es admin, que haga el org_title
                            org_id_aux = None
                            orgs_aux = toolkit.get_action('organization_list_for_user')(
                                data_dict={'permission': 'read'})
                            if orgs_aux and len(orgs_aux) > 0:
                                org_id_aux = orgs_aux[0].get('id', None) if orgs_aux[0] else None
                            aux = org_id_aux.encode('ascii', 'ignore')
                            if (aux == global_special_org_id):
                                org_title = None
                                for item2 in data2:
                                    if org in orgs:
                                        pass
                                    else:
                                        id_aux = item2.get('id', None)
                                        title = item2.get('title', None)
                                        if (org == id_aux):
                                            org_title = title
                                        if org_title:
                                            orgs.append(org)
                                            result_data.append({
                                                "title": org_title,
                                                "data": {year: value}})
                                        else:
                                            not_found_orgs.append(org)
                            else:
                                org_title = _dge_dashboard_organization_title(org)
                                if org_title:
                                    orgs.append(org)
                                    result_data.append({
                                        "title": org_title,
                                        "data": {year: value}})
                                else:
                                    not_found_orgs.append(org)
                result_data = sorted(result_data, key=lambda k: k['title'])
                header = sorted(header)
                return result_data, header, error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_datasets_by_org: %s', e)
        error_loading_data = True
    return [], [], error_loading_data


def dge_dashboard_special_org():
    org_id = None
    orgs = toolkit.get_action('organization_list_for_user')(data_dict={'permission': 'read'})
    if orgs and len(orgs) > 0:
        org_id = orgs[0].get('id', None) if orgs[0] else None
    aux = org_id.encode('ascii', 'ignore')
    if (aux == global_special_org_id):
        return True
    return False


def dge_dashboard_administrator_organizations_by_level():
    '''
    Returns data for publishers per administration_level.
    Get data of endpoint set in ckanext.dge_dashboard.chart.adm.publishers_adm_level.url_data config property
    '''
    data = None
    i = 0
    sort_result = None
    result_data = []
    result_graphs = []
    data_date = None
    organizations = {}
    actualizations = {}
    nitems = {}
    error_loading_data = False
    try:
        url = _dge_dashboard_get_backend(
            config.get('ckanext.dge_dashboard.chart.adm.organizations_adm_level.url_data', None))
        if url:
            response = urllib.urlopen(url)
            if response:
                data = json.loads(response.read())
            if data:
                for item in data:
                    if not data_date:
                        data_date = _dge_dashboard_convert_date(item.get('date', None))
                    organization = item.get('organization', None).encode('utf-8')
                    actualization = item.get('type_actualization', None).encode('utf-8')
                    if organization:
                        organizations[i] = organization
                        actualizations[i] = actualization
                        if i != 0:
                            if organizations[i - 1] == organization:
                                i = i - 1
                                actualizations[i] = 'ambas'
                    adm_level = item.get('adm_level', None)
                    if adm_level:
                        nitems[i] = {'date': item.get('date', ''), 'organization': organizations[i],
                                     'category': _dge_dashboard_get_translated_administration_level(adm_level),
                                     'type_actualization': actualizations[i]}
                        i = i + 1

            for j in range(0, i):
                item = nitems.get(j)
                if item:
                    if sort_result is None:
                        sort_result = []
                    sort_result.append(item)
            if sort_result:
                result_data = sort_result
            return json.dumps(result_data), json.dumps(result_graphs), data_date, error_loading_data
    except Exception as e:
        log.error('Exception in dge_dashboard_administrator_organizations_by_level: %s', e)
        error_loading_data = True
    return [], [], data_date, error_loading_data
