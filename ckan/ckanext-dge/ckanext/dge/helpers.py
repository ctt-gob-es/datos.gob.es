# Copyright (C) 2017 Entidad Pública Empresarial Red.es
# 
# This file is part of "ckanext-dge (datos.gob.es)".
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
import ckan.lib.helpers as h
import ckan.plugins.toolkit as toolkit
import urllib, json
from ckan import logic
from ckan.common import (
    _, ungettext, g, c, request, session, json, OrderedDict
)
from operator import itemgetter
import ckan.model as model
import ckanext.dge_harvest.helpers as dhh

import logging

TRANSLATED_UNITS = {'E': { 'es': 'Administraci\u00F3n del Estado',
                           'ca': 'Administraci\u00F3 de l\u0027Estat',
                           'gl': 'Administraci\u00F3n do Estado',
                           'eu': 'Estatuko Administrazioa',
                           'en': 'State Administration'}, \
                    'A': { 'es': 'Administraci\u00F3n Auton\u00F3ica',
                           'ca': 'Administraci\u00F3 Auton\u00F3mica',
                           'gl': 'Administraci\u00F3n Auton\u00F3mica',
                           'eu': 'Administrazio Autonomikoa',
                           'en': 'Regional Administration'},
                    'L': { 'es': 'Administraci\u00F3n Local',
                           'ca': 'Administraci\u00F3 Local',
                           'gl': 'Administraci\u00F3n Local',
                           'eu': 'Toki Administrazioa',
                           'en': 'Local Administration'},
                    'U': { 'es': 'Universidades',
                           'ca': 'Universitats',
                           'gl': 'Universidades',
                           'eu': 'Universities',
                           'en': 'Unibertsitateak'},
                    'I': { 'es': 'Otras Instituciones',
                           'ca': 'Altres institucions',
                           'gl': 'Outras instituci\u00F3ns',
                           'eu': 'Beste instituzio batzuk',
                           'en': 'Other Institutions'},
                    'J': { 'es': 'Administraci\u00F3n de Justicia',
                           'ca': 'Administraci\u00F3 de Just\u00EDcia',
                           'gl': 'Administraci\u00F3n de Xustiza',
                           'eu': 'Justizia Administrazioa',
                           'en': 'Legal Administration'},
                    '-': { 'es': 'Otros',
                           'ca': 'Altres',
                           'gl': 'Outros',
                           'eu': 'OTHER',
                           'en': 'Beste batzuk'}
                 }

DEFAULT_UNIT =  '-'


log = logging.getLogger(__name__)

def dge_default_locale():
    return config.get('ckan.locale_default', 'es').lower()

def dge_is_downloadable_resource(resource_url, resource_format=None):
    '''
    :param resource_url: resource access url
    :type string
    
    Returns True if resource_url does not end with a format included in
    ckanext.dge.no.downloadable.formats config properties or
    resource_format is not included in kanext.dge.no.downloadable.formats config properties. 
    Otherwise False. 
    '''
    result = True
    no_downloadable_formats = config.get('ckanext.dge.no.downloadable.formats', '').lower().split()
    resource_format_url = None
    if no_downloadable_formats and len(no_downloadable_formats) > 0:
        if resource_url is not None:
            split_resource_url = resource_url.lower().split('.')
            if len(split_resource_url) > 0:
                resource_format_url = split_resource_url[-1]

        if (resource_format_url is not None and \
            resource_format_url in no_downloadable_formats) or \
           (resource_format is not None \
            and resource_format.lower() in no_downloadable_formats):
            result = False
        
    return result

def dge_dataset_field_value(text):
    """
    :param text: {lang: text} dict or text string

    Convert "language-text" to users' language by looking up
    language in dict or using gettext if not a dict but. If the text
    doesn't exist look for an available text
    """
    value = None
    language = None
    if not text:
        result = u''

    dict_text = dsh.dge_dataset_form_lang_and_value(text)
    if (dict_text):
        language = sh.lang()
        if (dict_text.has_key(language) and dict_text[language] and \
            dict_text[language].strip() != ''):
            value = dict_text[language]
            language = None
        else:
            for key in dict_text:
                if (dict_text[key] and dict_text[key].strip() != ''):
                    value = (dict_text[key])
                    language = key
                    break
    return language, value

def dge_dataset_display_fields(field_name_list, dataset_fields):
    """
    :param field_name_list: list of scheme field names
    :param dataset_fields:  fields of dataset

    Return a dictionary with field names in field_name_list and
    value field in scheme. None if field not exists in scheme
    """
    dataset_dict = {}
    if field_name_list:
        for field_name in field_name_list:
            dataset_dict[field_name] = None

        if dataset_fields:
            for field in dataset_fields:
                if field and field['field_name'] and field['field_name'] in field_name_list:
                    dataset_dict[field['field_name']] = field
    return dataset_dict

def dge_render_datetime(datetime_, date_format=None, with_hours=False):
    '''Render a datetime object or timestamp string as a localised date or
    in the requested format.
    If timestamp is badly formatted, then a blank string is returned.

    :param datetime_: the date
    :type datetime_: datetime or ISO string format
    :param date_format: a date format
    :type date_format: string
    :param with_hours: should the `hours:mins` be shown
    :type with_hours: bool

    :rtype: string
    '''
    if not datetime_:
        return ''
    if isinstance(datetime_, basestring):
        try:
            datetime_ = h.date_str_to_datetime(datetime_)
        except TypeError:
            return None
        except ValueError:
            return None
    # check we are now a datetime
    if not isinstance(datetime_, datetime.datetime):
        return None

    #Timezone in dge is always Europe/Madrid
    from_timezone = pytz.timezone('Europe/Madrid')
    to_timezone = pytz.timezone('UTC')
    datetime_ = from_timezone.localize(datetime_)
    # if date_format was supplied we use it
    if date_format:
        return datetime_.strftime(date_format)

    # the localised date
    datetime_ = datetime_.astimezone(tz=to_timezone)

    details = {
        'min': datetime_.minute,
        'hour': datetime_.hour,
        'day': datetime_.day,
        'year': datetime_.year,
        'month': datetime_.month,
        'timezone': datetime_.tzinfo.zone,
    }
    if with_hours:
        result = ('{day}/{month:02}/{year} {hour:02}:{min:02} ({timezone})').format(**details)
    else:
        result = ('{day}/{month:02}/{year}').format(**details)
    return result

def dge_dataset_display_name(package_or_package_dict):
    """
    Get title and language of a package
    
    :param package_or_package_dict: the package
    :type dict or package: 
    
    :rtype string, string: translated title, and locale
    """
    if isinstance(package_or_package_dict, dict):
        language, value = dge_dataset_field_value(package_or_package_dict.get('title_translated'))
    else:
        language, value = dge_dataset_field_value(package_or_package_dict.title_translated)
    return value

def dge_resource_display_name(resource_or_resource_dict):
    """
    Get title and language of a resource
    
    :param resource_or_resource_dict: the resource
    :type dict or resource: 
    
    :rtype string, string: translated title, and locale
    """
    if isinstance(resource_or_resource_dict, dict):
        language, value = dge_dataset_field_value(resource_or_resource_dict.get('name_translated'))
    else:
        language, value = dge_dataset_field_value(resource_or_resource_dict.name_translated)
    if value:
        return value
    else:
        return _("Unnamed resource")

def dge_get_dataset_publisher(org=None):
    '''
    Given an organization id, returns a dict:
     key='name' -> the organization title
     key='title' -> the organization title
     key='subname' -> the principal organization title  
     key= 'administration_level' -> administration level of the organization 
    
    :param org: organization id
    :type string
    '''
    if org is None:
        return {}
    try:
        result = {}
        organization = toolkit.get_action('dge_organization_publisher')({'model': model}, {'id': org})
        if organization:
            result['NAME'] = organization['title'] or organization['name']
            if organization['extras']:
                for extra in organization['extras']:
                    if extra and extra['key'] == 'C_DNM_DEP_UD_PRINCIPAL' \
                            and extra['value']:
                        result['PPAL_NAME'] = extra['value']
                    elif extra and extra['key'] == 'C_ID_UD_ORGANICA' \
                            and extra['value']:
                        result['AL'] = dge_get_dataset_administration_level(None, extra['value'])
    except:
        return None
    return result


def dge_get_dataset_administration_level(org=None, id_ud_organic=None):
    '''
    Given an id_ud_organic, returns the administration level according 
    to the first letter of id_ud_organic
    Given an organization , returns the administration level according 
    to the first letter of its extra C_ID_UD_ORGANICA
    
    :param org: organization id
    :type string
    
    :param id_ud_organic: id_ud_organic
    :type string
    '''
    if org is None and id_ud_organic is None:
        return {}
    try:
        result = {}
        if id_ud_organic and len(id_ud_organic) > 0:
            value = id_ud_organic[0].upper()
            if value:
                value_translated = dge_get_translated_administration_level(value)
                if value_translated:
                    return value_translated
        elif org:
            organization = toolkit.get_action('dge_organization_publisher')({'model': model}, {'id': org})
            value = dge_get_organization_administration_level_code(organization)
            if value:
                value_translated = dge_get_translated_administration_level(value)
                if value_translated:
                    return value_translated
    except :
       return {}
    
    return result

def dge_get_organization_administration_level_code(organization=None):
    if organization is None:
        return {}
    try:
        result = None
        if (organization and organization['extras']):
            for extra in organization['extras']:
                if extra and extra['key'] == 'C_ID_UD_ORGANICA' \
                   and extra['value']:
                    result = extra['value'][0].upper()
    except :
        return None
    return result

def dge_get_translated_dataset_administration_level(organization=None, lang='es'):
    '''
    Given an organization id, returns values of extra C_ID_UD_ORGANICA 
    
    :param organization: organization id
    :type string
    
    :param lang: locale
    :type string
    '''
    if organization is None:
        return {}
    try:
        result = None
        value = dge_get_organization_administration_level_code(organization)
        if value and value in TRANSLATED_UNITS:
            return TRANSLATED_UNITS[value][lang]
        else:
            return TRANSLATED_UNITS[DEFAULT_UNIT][lang]
    except :
        return None
    return result

def dge_list_reduce_resource_format_label(resources=None, field_name='format'):
    '''
    Given an resource list, get label of resource_format
    
    :param resources: resource dict
    :type dict list
    
    :param field_name: field_name of resource
    :type string
    
    :rtype string list
    '''
    
    format_list = h.dict_list_reduce(resources, field_name)
    dataset = sh.scheming_get_schema('dataset', 'dataset')
    formats = sh.scheming_field_by_name(dataset.get('resource_fields'),
                'format')
    label_list = []
    for res_format in format_list:
        res_format_label = sh.scheming_choices_label(formats['choices'], res_format)
        if res_format_label:
            label_list.append(res_format_label)
    return label_list

def dge_resource_format_label(res_format=None):
    '''
    Given an format, get its label
    
    :param res_format: format
    :type string
    
    :rtype string
    '''
    if format:
        dataset = sh.scheming_get_schema('dataset', 'dataset')
        formats = sh.scheming_field_by_name(dataset.get('resource_fields'),
                'format')
        res_format_label = sh.scheming_choices_label(formats['choices'], res_format)
        if res_format_label:
            return res_format_label
    return res_format

def dge_theme_id(theme=None):
    '''
    Given a value of theme, returs its identifier
    :param theme: value theme 
    :type string 
    
    :rtype string
    '''
    id = None
    if theme:
        index = theme.rfind('/')
        if (index > -1 and (index+1 < len(theme))):
            id = theme[index+1:]
    return id

def dge_list_themes(themes=None):
    '''
    Given an theme list values, get theirs translated labels
    
    :param themes: value theme list
    :type string list
    
    :rtype (string, string) list
    '''
    dataset = sh.scheming_get_schema('dataset', 'dataset')
    formats = sh.scheming_field_by_name(dataset.get('dataset_fields'),
                'theme')
    label_list = []
    for theme in themes:
        label = sh.scheming_choices_label(formats['choices'], theme)
        if label:
            label_list.append((dge_theme_id(theme), label))
    return label_list
    
def dge_dataset_display_frequency(value, stype):
    '''
    Given a value and type frequency, get the translated label
    
    :param value: value of frequency
    :type int
    
    :param stype: type of frequency
    :type string
    
    :rtype string (frequency label)
    '''
    result = None
    years = {'1':_('Annual'), '2':_('Biennial'), '3':_('Triennial')}
    months = {'1':_('Monthly'), '2':_('Bimonthly'), '3':_('Quarterly'), '4':_('Three times a year'), '6':_('Semiannual')}
    weeks = {'1':_('Weekly'), '2':_('Biweekly')}
    days = {'1':_('Daily'), '2':_('Three times a week'), '3':_('Semiweekly'), '7':_('Weekly'), '10':_('Three times a month'), '15':_('Semimonthly')}
    hours = {'12': _('Twice a day')}
    seconds = {'1': _('Continuous')}
    types = ['seconds', 'minutes', 'hours', 'days', 'weeks', 'months', 'years']
    if value and stype and stype in types:
        default_value =  _('Every') + ((' %s %s') % (value, _(stype)))
        svalue = str(value)
        if stype == 'years':
            default_value = _('Every {time_value} years').format(time_value=value)
            if svalue in years:
                result = years[svalue]  
        elif stype == 'months':
            default_value = _('Every {time_value} months').format(time_value=value)
            if svalue in months:
                result = months[svalue] 
        elif stype == 'weeks':
            default_value = _('Every {time_value} weeks').format(time_value=value)
            if svalue in weeks:
                result = weeks[svalue] 
        elif stype == 'days':
            default_value = _('Every {time_value} days').format(time_value=value)
            if svalue in days:
                result = days[svalue] 
        elif stype == 'hours':
            if svalue in hours:
                result = hours[svalue]
        elif stype == 'seconds':
            if svalue in seconds:
                result = seconds[svalue] 
        if result is None:
            result = default_value 
        return result

def dge_url_for_user_organization():
    ''' Returns the link to the Organization in which the user active is editor '''
    if c.userobj:
        if c.userobj.sysadmin:
            return h.url_for(controller='organization', action='index')
        else:
            orgs = toolkit.get_action('organization_list_for_user')(data_dict={'permission': 'read'})
            if orgs and len(orgs) > 0:
                return h.url_for(controller='organization', action='read', id=orgs[0].get('name'))
    return None

def dge_resource_display_name_or_desc(name=None, description=None):
    '''
    Given a resource name, returns resourcename, 
          else returns given resource description
    
    :param name: resource name
    :type string
    
    :param stype: resource description
    :type string
    
    :rtype string (resource display name)
    '''
    if name:
        return name
    elif description:
        description = description.split('.')[0]
        max_len = 60
        if len(description) > max_len:
            description = description[:max_len] + '...'
        return description
    else:
        return _("Unnamed resource")

def dge_package_list_for_source(source_id):
    '''
    Creates a dataset list with the ones belonging to a particular harvest
    source.

    It calls the package_list snippet and the pager.
    '''
    DATASET_TYPE_NAME = 'harvest'
    limit = 20
    page = int(request.params.get('page', 1))
    fq = 'harvest_source_id:"{0}"'.format(source_id)
    search_dict = {
        'fq' : fq,
        'rows': limit,
        'sort': 'metadata_modified desc',
        'start': (page - 1) * limit,
    }

    context = {'model': model, 'session': model.Session}

    owner_org =  toolkit.c.harvest_source.get('owner_org', '')
    if owner_org:
        user_member_of_orgs = [org['id'] for org
                   in h.organizations_available('read')]
        if (toolkit.c.harvest_source and owner_org in user_member_of_orgs):
            context['ignore_capacity_check'] = True

    query = logic.get_action('package_search')(context, search_dict)

    base_url = h.url_for('{0}_read'.format(DATASET_TYPE_NAME), id=source_id)
    def pager_url(q=None, page=None):
        url = base_url
        if page:
            url += '?page={0}'.format(page)
        return url

    pager = h.Page(
        collection=query['results'],
        page=page,
        url=pager_url,
        item_count=query['count'],
        items_per_page=limit
    )
    pager.items = query['results']

    if query['results']:
        out = h.snippet('snippets/dge_package_list.html', packages=query['results'])
        out += pager.pager()
    else:
        out = h.snippet('snippets/package_list_empty.html')

    return out

def dge_api_swagger_url():
    '''
    Returns endpoint of swagger, set in ckanext.dge.api.swagger.url config property.
    Returns emtpy string if property does not exist.
    '''
    return h.url_for_static_or_external(config.get('ckanext.dge.api.swagger.url', '').lower())

def dge_sparql_yasgui_endpoint():
    '''
    Returns endpoint of sparql, set in ckanext.dge.api.yasgui.url config property.
    Returns emtpy string if property does not exist.
    '''
    return h.url_for_static_or_external(config.get('ckanext.dge.sparql.yasgui.endpoint', '').lower())

def dge_swagger_doc_url(lang = None):
    '''
    Returns url of swagger documentation page, 
    set in ckanext.dge.api.swagger.doc.url config property.
    Returns emtpy string if property does not exist.
    '''
    prefix = None
    url = config.get('ckanext.dge.api.swagger.doc.url', None)
    if not lang:
        lang = config.get('ckan.locale_default', 'es')
    if url and lang:
        if (url.startswith('/')):
            prefix = ('/' + lang + url).lower()
        else:
            prefix = ('/' + lang + '/' + url).lower()
    return prefix

def dge_sparql_yasgui_doc_url(lang = None):
    '''
    Returns url of sparql documentation page, 
    set in ckanext.dge.sparql.yasgui.doc.url config property.
    Returns emtpy string if property does not exist.
    '''
    
    prefix = None
    url = config.get('ckanext.dge.sparql.yasgui.doc.url', None)
    if not lang:
        lang = config.get('ckan.locale_default', 'es')
    if url and lang:
        if (url.startswith('/')):
            prefix = ('/' + lang + url).lower()
        else:
            prefix = ('/' + lang + '/' + url).lower()
    return prefix

def dge_get_translated_administration_level(prefix=None):
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
             '-': _('Other')
            }
    if prefix and prefix in units:
        return units.get(prefix, None)
    else:
        return units.get(DEFAULT_UNIT, None)
    return None

def dge_exported_catalog_files():
    '''
    Returns endpoint of download catalog files in rdf, csv and atom format
    '''
    url_rdf = config.get('ckanext.dge.catalog.export.rdf.url', None)
    url_csv = config.get('ckanext.dge.catalog.export.csv.url', None)
    url_atom = config.get('ckanext.dge.catalog.export.atom.url', None)
    return url_rdf, url_csv, url_atom

def dge_get_endpoints_menu(keys=[], lang=None, header=True, footer=False):
    ''' get endpoint for drupal submenu elements 
    :param keys: properties keys
    :type keys: list
    
    :param lang: locale for endpoints. It must be a locale_order
    :type lang: string
    
    :param header: if true, get endpoints for header drupal submenu elements
    :type header: boolean
    
    :param footer: if true, get endpoints for footer drupal submenu elements
    :type footer: boolean

    :rtype: dict with key, property key and value the endpoint
    '''
    menu = {}
    if not lang:
        lang = config.get('ckan.locale_default', None)
        if not lang:
            log.debug('empty or None local')
            return {}
    prefix = '/' + lang

    #action of login form --> https
    user_logged_page = config.get('ckan.site_url', '') + prefix + '/home?destination=home'
    index = user_logged_page.find('://')  
    if (index >= 0):
        user_logged_page = 'https' + user_logged_page[index:]
    
    #default values
    menu['ckanext.dge.user_logged_page'] = user_logged_page
    menu['ckanext.dge.drupal_menu.home'] = prefix + '/home'
    menu['ckanext.dge.drupal_menu.aporta.about'] = prefix + '/acerca-de-la-iniciativa-aporta'
    menu['ckanext.dge.drupal_menu.aporta.meetings'] = prefix + '/encuentros-aporta'
    menu['ckanext.dge.drupal_menu.aporta.challenge'] = prefix + '/desafio-aporta-2017-el-valor-del-dato-para-la-administracion'
    menu['ckanext.dge.drupal_menu.aporta.awards'] = prefix + '/premios-aporta'
    menu['ckanext.dge.drupal_menu.impact.initiatives'] = prefix + '/iniciativas'
    menu['ckanext.dge.drupal_menu.impact.applications'] = prefix + '/aplicaciones'
    menu['ckanext.dge.drupal_menu.impact.success_cases'] = prefix + '/casos-exito'
    menu['ckanext.dge.drupal_menu.interact.documentation'] = prefix + '/documentacion'
    menu['ckanext.dge.drupal_menu.interact.advise_support'] = prefix + '/asesoramiento-y-soporte'
    menu['ckanext.dge.drupal_menu.interact.requests'] = prefix + '/peticiones-datos'
    menu['ckanext.dge.drupal_menu.interact.about'] = prefix + '/informa-sobre'
    menu['ckanext.dge.drupal_menu.news.news'] = prefix + '/noticias'
    menu['ckanext.dge.drupal_menu.news.newsletters'] = prefix + '/boletines'
    menu['ckanext.dge.drupal_menu.news.events'] = prefix + '/eventos'
    menu['ckanext.dge.drupal_menu.news.risp'] = prefix + '/comunidad-risp'
    menu['ckanext.dge.drupal_menu.account.profile'] = prefix + '/user'
    menu['ckanext.dge.drupal_menu.account.requests'] = prefix + '/admin/dashboard/requests'
    menu['ckanext.dge.drupal_menu.account.applications'] = prefix + '/admin/dashboard/apps'
    menu['ckanext.dge.drupal_menu.account.success_cases'] = prefix + '/admin/dashboard/success'
    menu['ckanext.dge.drupal_menu.account.unassigned_requests'] = prefix + '/admin/dashboard/unassigned-requests'
    menu['ckanext.dge.drupal_menu.account.initiatives'] = prefix + '/admin/dashboard/initiatives'
    menu['ckanext.dge.drupal_menu.account.comments'] = prefix + '/admin/dashboard/comment'
    menu['ckanext.dge.drupal_menu.account.widget'] = prefix + '/admin/dashboard/widget'
    menu['ckanext.dge.drupal_menu.account.users'] = prefix + '/admin/people/dge-user-panel'
    menu['ckanext.dge.drupal_menu.account.logout'] = prefix + '/user/logout'
    menu['ckanext.dge.drupal_menu.sitemap'] = prefix + '/sitemap'
    menu['ckanext.dge.drupal_menu.contact'] = prefix + '/contacto'
    menu['ckanext.dge.drupal_menu.legal_notice'] = prefix + '/aviso-legal'
    menu['ckanext.dge.drupal_menu.faq'] = prefix + '/faq-page'
    menu['ckanext.dge.drupal_menu.accesibility'] = prefix + '/accesibilidad'
    menu['ckanext.dge.drupal_menu.cookies_policy'] = prefix + '/politica-de-cookies'

    if (keys and len(keys) > 0) or header or footer:
        locales_order = config.get('ckan.locale_order', None)

        lorder = []
        if locales_order:
            lorder = locales_order.split();
            index = lorder.index(lang)
            if (index == -1):
                log.debug('locale not found %s', lang)
                return {}
           
        if header or footer:
            #aporta
            if 'ckanext.dge.drupal_menu.aporta.about' not in keys: 
                keys.append('ckanext.dge.drupal_menu.aporta.about')
            if 'ckanext.dge.drupal_menu.aporta.meetings' not in keys: 
                keys.append('ckanext.dge.drupal_menu.aporta.meetings')
            if 'ckanext.dge.drupal_menu.aporta.challenge' not in keys: 
                keys.append('ckanext.dge.drupal_menu.aporta.challenge')
            if 'ckanext.dge.drupal_menu.aporta.awards' not in keys: 
                keys.append('ckanext.dge.drupal_menu.aporta.awards')
            #impact
            if 'ckanext.dge.drupal_menu.impact.initiatives' not in keys: 
                keys.append('ckanext.dge.drupal_menu.impact.initiatives')
            if 'ckanext.dge.drupal_menu.impact.applications' not in keys: 
                keys.append('ckanext.dge.drupal_menu.impact.applications')
            if 'ckanext.dge.drupal_menu.impact.success_cases' not in keys: 
                keys.append('ckanext.dge.drupal_menu.impact.success_cases')
            #interact
            if 'ckanext.dge.drupal_menu.interact.documentation' not in keys: 
                keys.append('ckanext.dge.drupal_menu.interact.documentation')
            if 'ckanext.dge.drupal_menu.interact.advise_support' not in keys: 
                keys.append('ckanext.dge.drupal_menu.interact.advise_support')
            if 'ckanext.dge.drupal_menu.interact.requests' not in keys: 
                keys.append('ckanext.dge.drupal_menu.interact.requests')
            if 'ckanext.dge.drupal_menu.interact.about' not in keys: 
                keys.append('ckanext.dge.drupal_menu.interact.about')
            #news
            if 'ckanext.dge.drupal_menu.news.news' not in keys: 
                keys.append('ckanext.dge.drupal_menu.news.news')
            if 'ckanext.dge.drupal_menu.news.newsletters' not in keys: 
                keys.append('ckanext.dge.drupal_menu.news.newsletters')
            if 'ckanext.dge.drupal_menu.news.events' not in keys: 
                keys.append('ckanext.dge.drupal_menu.news.events')
            if 'ckanext.dge.drupal_menu.news.risp' not in keys: 
                keys.append('ckanext.dge.drupal_menu.news.risp')

        if header:
            #my account
            if 'ckanext.dge.drupal_menu.account.profile' not in keys: 
                keys.append('ckanext.dge.drupal_menu.account.profile')
            if 'ckanext.dge.drupal_menu.account.requests' not in keys: 
                keys.append('ckanext.dge.drupal_menu.account.requests')
            if 'ckanext.dge.drupal_menu.account.applications' not in keys: 
                keys.append('ckanext.dge.drupal_menu.account.applications')
            if 'ckanext.dge.drupal_menu.account.success_cases' not in keys: 
                keys.append('ckanext.dge.drupal_menu.account.success_cases')
            if 'ckanext.dge.drupal_menu.account.unassigned_requests' not in keys: 
                keys.append('ckanext.dge.drupal_menu.account.unassigned_requests')
            if 'ckanext.dge.drupal_menu.account.comments' not in keys: 
                keys.append('ckanext.dge.drupal_menu.account.comments')
            if 'ckanext.dge.drupal_menu.account.initiatives' not in keys: 
                keys.append('ckanext.dge.drupal_menu.account.initiatives')
            if 'ckanext.dge.drupal_menu.account.widget' not in keys: 
                keys.append('ckanext.dge.drupal_menu.account.widget')
            if 'ckanext.dge.drupal_menu.account.users' not in keys: 
                keys.append('ckanext.dge.drupal_menu.account.users')
            if 'ckanext.dge.drupal_menu.account.logout' not in keys: 
                keys.append('ckanext.dge.drupal_menu.account.logout')

        if footer:
            if 'ckanext.dge.drupal_menu.sitemap' not in keys: 
                keys.append('ckanext.dge.drupal_menu.sitemap')
            if 'ckanext.dge.drupal_menu.contact' not in keys: 
                keys.append('ckanext.dge.drupal_menu.contact')
            if 'ckanext.dge.drupal_menu.legal_notice' not in keys: 
                keys.append('ckanext.dge.drupal_menu.legal_notice')
            if 'ckanext.dge.drupal_menu.faq' not in keys: 
                keys.append('ckanext.dge.drupal_menu.faq')
            if 'ckanext.dge.drupal_menu.accesibility' not in keys: 
                keys.append('ckanext.dge.drupal_menu.accesibility')
            if 'ckanext.dge.drupal_menu.cookies_policy' not in keys: 
                keys.append('ckanext.dge.drupal_menu.cookies_policy')

        for key in keys:
            value = config.get(key, None)
            svalue = None
            if value:
                svalue = value.split(';')
            if svalue:
                if len(svalue) == 1:
                    menu[key] = prefix + svalue[0]
                elif len(svalue) > index:
                    menu[key] = prefix + svalue[index]
    return menu

def dge_sort_alphabetically_resources(resources = None):
    if not resources:
        return
    new_resources = []
    for res in resources:
        language, value= dge_dataset_field_value(res.get('name_translated'))
        if not value:
            value = _("Unnamed resource")
        new_res = {'lang': language, 'value': value, 'resource': res}
        new_resources.append(new_res)
    sorted_resources = sorted(new_resources, key=itemgetter('value'), reverse=False)
    return sorted_resources

def dge_dataset_tag_list_display_names(tags=None):
    ''' get a list of tags display_name separated by commas
    :param keys: tags 
    :type keys: list

    :rtype: string with display_name of tags separated by commas
    '''
    result = ""
    if tags:
        for tag in tags:
            if tag and tag.get('display_name'):
                result = result + "," + tag.get('display_name')
    if result and len(result)>0:
        return result[1:]
                