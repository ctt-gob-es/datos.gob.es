# Copyright (C) 2017 Entidad P�blica Empresarial Red.es
# 
# This file is part of "ckanext-dge-scheming (datos.gob.es)".
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

import logging
import ckan.lib.helpers as h
import ckan.lib.munge as munge
import re
import json
import ckanext.dge_scheming.helpers as dh
import ckan.model as model
import ckan.plugins.toolkit as toolkit

from pylons import config
from ckan.plugins.toolkit import missing, _
from ckantoolkit import get_validator


log = logging.getLogger(__name__)

ISO_639_LANGUAGE = u'^[a-z][a-z][a-z]?[a-z]?$'
FREQUENCY_VALUES = [ "days", "weeks", "months", "years", "hours", "minutes", "seconds" ]
DEFAULT_TITLE_FIELD = 'title_translated'

not_empty = get_validator('not_empty')

def scheming_validator(fn):
    """
    Decorate a validator for using with scheming.
    """
    fn.is_a_scheming_validator = True
    return fn

"""
FIELD TYPE URL
"""
@scheming_validator
def uri_text(field, schema):
    def validator(key, data, errors, context):
        value = data[key]

        is_url = False
        if ('is_url' in field):
            is_url = field['is_url']

        if value is not missing:
            if value:
                if is_url and not h.is_url(value):
                    errors[key].append(_('the URL format is not valid'))
                else:
                    if not is_url and not dh.dge_is_uri(value):
                        errors[key].append(_('the URI format is not valid'))
                return

        # 3. separate fields
        extras = data.get(('__extras',), {})
        if key in extras:
            value = extras[key]

            if is_url and not h.is_url(value):
                errors[key].append(_('the URL format is not valid'))
            else:
                if not is_url and not dh.dge_is_uri(value):
                    errors[key].append(_('the URI format is not valid'))
            return

        if field.get('required'):
            not_empty(key, data, errors, context)

    return validator

def uri_text_output(value):
    return value

"""
FIELD TYPE MULTIPLE URL
"""
@scheming_validator
def multiple_uri_text(field, schema):
    def validator(key, data, errors, context):
        """
        Accept repeating text input in the following forms
        and convert to a json list for storage:
        1. a list of strings, eg.
           ["http://url1", "http://url2"]
        2. a single string value to allow single text fields to be
           migrated to repeating text
           "http://url1"
        3. separate fields per language (for form submissions):
           fieldname-0 = "http://url1"
           fieldname-1 = "http://url2"
        """
        # just in case there was an error before that validator
        if errors[key]:
            return

        value = data[key]

        is_url = False
        if ('is_url' in field):
            is_url = field['is_url']

        # 1. list of strings or 2. single string
        if value is not missing:
            if isinstance(value, basestring):
                value = [value]
            if not isinstance(value, list):
                errors[key].append(_('Expecting list of strings'))
                return

            out = []
            for element in value:
                if not isinstance(element, basestring):
                    errors[key].append(_('Invalid type for repeating url text: %r')
                        % element)
                    continue
                    type(i)
                try:
                    if not isinstance(element, unicode):
                        element = element.decode('utf-8')
                    if element:
                        if is_url and not h.is_url(element):
                            errors[key].append(_('The URL format is not valid'))
                        else:
                            if not is_url and not dh.dge_is_uri(element):
                                errors[key].append(_('The URI format is not valid'))

                except UnicodeDecodeError:
                    errors[key]. append(_('Invalid encoding for "%s" value')
                        % lang)
                    continue
                out.append(element)

            if not errors[key]:
                data[key] = json.dumps(out)
            return

        # 3. separate fields
        found = {}
        prefix = key[-1] + '-'
        extras = data.get(key[:-1] + ('__extras',), {})

        #Validation
        url_errors = False
        for name, text in extras.iteritems():
            if not name.startswith(prefix):
                continue
            if not text:
                continue
            index = name.split('-', 1)[1]
            if text is not missing:
                if is_url and not h.is_url(text):
                    url_errors = True
                    name_error = key[:-1] + (name,)
                    errors[name_error] = [_('The URL format for "%s" is not valid') % text]
                else:
                    if not is_url and not dh.dge_is_uri(text):
                        url_errors = True
                        name_error = key[:-1] + (name,)
                        errors[name_error] = [_('The URI format for "%s" is not valid') % text]

        if url_errors:
            return

        for name, text in extras.iteritems():
            if not name.startswith(prefix):
                continue
            if not text:
                continue
            index = name.split('-', 1)[1]
            try:
                index = int(index)
            except ValueError:
                continue
            found[index] = text

        out = [found[i] for i in sorted(found)]
        data[key] = json.dumps(out)

    return validator

def multiple_uri_text_output(value):
    """
    Return stored json representation as a list, if
    value is already a list just pass it through.
    """
    if isinstance(value, list):
        return value
    if value is None:
        return []
    try:
        return json.loads(value)
    except ValueError:
        return [value]


"""
FIELD TYPE DATE FREQUENCY
"""
@scheming_validator
def date_frequency(field, schema):
    def validator(key, data, errors, context):
        """
        JSON with frequency and value information
        """
        # just in case there was an error before that validator
        if errors[key]:
            return

        value = data[key]

        # 1. list of strings or 2. single string
        if value is not missing:
            if isinstance(value, basestring):
                try:
                    value = json.loads(value)
                except ValueError:
                    errors[key].append(_('Failed to decode JSON string'))
                    return
                except UnicodeDecodeError:
                    errors[key].append(_('Invalid encoding for JSON string'))
                    return
            if not isinstance(value, dict):
                errors[key].append(_('Expecting JSON object'))
                return

            if not 'type' in value or not 'value' in value:
                errors[key].append(_('The JSON object must contain type and value keys'))
                return

            frequency_type = value['type']
            frequency_value = value['value']

            if frequency_type and frequency_value:
                if not frequency_type in FREQUENCY_VALUES:
                    errors[key] = [_('The frequency type is no allowed')]
                try:
                   int(frequency_value)
                except ValueError:
                    errors[key] = [_('The frequency value is not an integer')]
            else:
                if frequency_type and not frequency_value:
                    errors[key] = [_('The frequency value is mandatory')]
                if frequency_value and not frequency_type:
                    errors[key] = [_('The frequency type is mandatory')]
                if field.get('required') and not frequency_value and not frequency_type:
                    not_empty(key, data, errors, context)

            if not errors[key]:
                if frequency_value and frequency_type:
                    out = { 'type': frequency_type, 'value': frequency_value}
                    data[key] = json.dumps(out)
                else:
                    data[key] = None
            return

        # 3. separate fields
        found = {}
        prefix = key[-1] + '-'
        extras = data.get(key[:-1] + ('__extras',), {})

        #Form validations
        frequency_type = extras.get(prefix+ 'type')
        frequency_value = extras.get(prefix + 'value')

        if frequency_type and frequency_value:
            if not frequency_type in FREQUENCY_VALUES:
                errors[key] = [_('The frequency type is no allowed')]
            try:
               int(frequency_value)
            except ValueError:
                errors[key] = [_('The frequency value is not an integer')]
        else:
            if frequency_type and not frequency_value:
                errors[key] = [_('The frequency value is mandatory')]
            if frequency_value and not frequency_type:
                errors[key] = [_('The frequency type is mandatory')]
            if field.get('required') and not frequency_value and not frequency_type:
                not_empty(key, data, errors, context)

        #With errors we finish
        if errors[key]:
            return

        #transform to JSON
        if frequency_value and frequency_type:
            out = { 'type': frequency_type, 'value': frequency_value}
            data[key] = json.dumps(out)
        else:
            data[key] = None

    return validator


def date_frequency_output(value):
    """
    Return stored json representation as a dict, if
    value is already a dict just pass it through.
    """
    if isinstance(value, dict):
        return value
    if value is None:
        return {}
    try:
        return json.loads(value)
    except ValueError:
        return {}


"""
FIELD URL FROM MULTILANGUAGE TITLE
"""
@scheming_validator
def multilanguage_url(field, schema):

    def validator(key, data, errors, context):
        if errors[key]:
            return

        value = data[key]
        if value is not missing:
            if value:
                return

        output = {}

        prefix = field['autogeneration_field']
        if not prefix:
            prefix = DEFAULT_TITLE_FIELD

        log.debug('[multilanguage_url] Creating field using the field %s', prefix)

        prefix = prefix + '-'

        extras = data.get(key[:-1] + ('__extras',), {})

        locale_default = config.get('ckan.locale_default', 'es')
        if locale_default:
            title_lang = prefix + locale_default

            if title_lang in extras and extras[title_lang]:
                dataset_title = extras[title_lang]

                # Generate title prefix
                field_prefix = field['organization_field']
                organization_prefix = field['organization_prefix']

                publisher_id = data.get((field_prefix,))
                if not publisher_id and field_prefix in extras:
                    publisher_id = extras[field_prefix]

                if publisher_id and organization_prefix:

                    organization = h.get_organization(publisher_id)
                    if not organization:
                        organization = toolkit.get_action('dge_organization_publisher')({'model': model}, {'id': publisher_id})
                    if organization and organization['extras']:
                        for extra in organization['extras']:
                            if extra['key'] == organization_prefix and extra['state'] == 'active':
                                dataset_title = extra['value'] + '-' + dataset_title
                                break
                data[key] = munge.munge_title_to_name(dataset_title)

                log.debug('[multilanguage_url] Created name "%s" for package from language %s',
                            data[key], locale_default)
                return

        locale_order = config.get('ckan.locale_order', '').split()
        for l in locale_order:
            title_lang = prefix + l
            if title_lang in extras and extras[title_lang]:
                dataset_title = extras[title_lang]

                # Generate title prefix
                field_prefix = field['organization_field']
                organization_prefix = field['organization_prefix']

                publisher_id = data.get((field_prefix,))
                if not publisher_id and field_prefix in extras:
                    publisher_id = extras[field_prefix]

                if publisher_id and organization_prefix:
                    organization = h.get_organization(publisher_id)
                    if not organization:
                        organization = toolkit.get_action('dge_organization_publisher')({'model': model}, {'id': publisher_id})
                    if organization and organization['extras']:
                        for extra in organization['extras']:
                            if extra['key'] == organization_prefix and extra['state'] == 'active':
                                dataset_title = extra['value'] + '-' + dataset_title
                                break

                data[key] = munge.munge_title_to_name(dataset_title)

                log.debug('[multilanguage_url] Created name "%s" for package from language %s',
                            data[key], l)
                break

    return validator



"""
FIELD TYPE DATE PERIOD
"""
@scheming_validator
def date_period(field, schema):
    def validator(key, data, errors, context):
        """
        1. a JSON with dates, eg.
           {"1": {"to": "2016-05-28T00:00:00", "from": "2016-05-11T00:00:00"}}
        2. separate fields per date and time (for form submissions):
           fieldname-from-date-1 = "2012-09-11"
           fieldname-from-time-1 = "11:00"
           fieldname-from-date-2 = "2014-03-03"
           fieldname-from-time-2 = "09:45"
        """
        # just in case there was an error before that validator
        if errors[key]:
            return

        value = data[key]

        # 1. json
        if value is not missing:
            if isinstance(value, basestring):
                try:
                    value = json.loads(value)
                except ValueError, e:
                    errors[key].append(_('Invalid field structure, it is not a valid JSON'))
                    return
            if not isinstance(value, dict):
                 errors[key].append(_('Expecting valid JSON value'))
                 return

            out = {}
            for element in sorted(value):
                dates = value.get(element)
                with_date = False
                #if dates['from']:
                if 'from' in dates:
                    try:
                        date = h.date_str_to_datetime(dates['from'])
                        with_date = True
                    except (TypeError, ValueError), e:
                        errors[key].append(_('From value: Date format incorrect'))
                        continue
                #if dates['to']:
                if 'to' in dates:
                    try:
                        date = h.date_str_to_datetime(dates['to'])
                        with_date = True
                    except (TypeError, ValueError), e:
                        errors[key].append(_('To value: Date format incorrect'))
                        continue

                if not with_date:
                    errors[key]. append(_('Date period without from and to'))
                    continue
                out[str(element)] = dates

            if not errors[key]:
                data[key] = json.dumps(out)

            return

        # 3. separate fields
        found = {}
        short_prefix = key[-1] + '-'
        prefix = key[-1] + '-date-'
        extras = data.get(key[:-1] + ('__extras',), {})

        #Fase de validacion
        datetime_errors = False
        valid_indexes = []
        for name, text in extras.iteritems():
            if not name.startswith(prefix):
                continue
            if not text:
                continue

            datetime = text
            #Get time if exists
            index = name.split('-')[-1]
            type_field = name.split('-')[-2]
            time_value = extras.get(short_prefix+'time-'+type_field+'-'+index)
            #Add the time
            if time_value:
                datetime = text + ' ' + time_value

            #Create datetime and validation
            try:
                date = h.date_str_to_datetime(datetime)
                valid_indexes.append(index)
            except (TypeError, ValueError), e:
                errors[key].append(_('Date time format incorrect'))
                datetime_errors = True

        if datetime_errors:
            return

        valid_indexes = sorted(list(set(valid_indexes)))
        new_index = 1;
        for index in valid_indexes:
            period = {}

            #Get from
            date_from_value = extras.get(short_prefix+'date-from-'+index)
            if date_from_value:
                datetime = date_from_value
                time_from_value = extras.get(short_prefix+'time-from-'+index)
                if time_from_value:
                    datetime = date_from_value + " " + time_from_value
                try:
                    date = h.date_str_to_datetime(datetime)
                    period['from'] = date.strftime("%Y-%m-%dT%H:%M:%S")
                except (TypeError, ValueError), e:
                    continue

            date_to_value = extras.get(short_prefix+'date-to-'+index)
            if date_to_value:
                datetime = date_to_value
                time_to_value = extras.get(short_prefix+'time-to-'+index)
                if time_to_value:
                    datetime = date_to_value + " " + time_to_value
                try:
                    date = h.date_str_to_datetime(datetime)
                    period['to'] = date.strftime("%Y-%m-%dT%H:%M:%S")
                except (TypeError, ValueError), e:
                    continue

            if period:
                found[new_index] = period
                # only adds 1 to the new index with good periods
                new_index = new_index+1

        out = {}
        for i in sorted(found):
            out[i] = found[i]
        data[key] = json.dumps(out)

    return validator


def date_period_output(value):
    """
    Return stored json representation as a dict, if
    value is already a dict just pass it through.
    """
    if isinstance(value, dict):
        return value
    if value is None or isinstance(value, list):
        return {}
    try:
        return json.loads(value)
    except ValueError:
        return {}


"""
VALIDATOR FOR FLUENT TEXT
"""
def multiple_one_value(key, data, errors, context):
    if errors[key]:
        return

    values = []
    languages = []

    #Get value from dict or JSON encoded string
    value = data[key]
    if value is not missing:
        if isinstance(value, basestring):
            try:
                value = json.loads(value)
            except ValueError:
                errors[key].append(_('Failed to decode JSON string'))
                return
            except UnicodeDecodeError:
                errors[key].append(_('Invalid encoding for JSON string'))
                return
        if not isinstance(value, dict):
            errors[key].append(_('Expecting JSON object'))
            return

        for lang, text in value.iteritems():
            try:
                m = re.match(ISO_639_LANGUAGE, lang)
            except TypeError:
                errors[key].append(_('Invalid type for language code: %r')
                    % lang)
                continue

            #Register the language
            languages += [lang]
            if not isinstance(text, basestring):
                errors[key].append(_('Invalid type for "%s" value') % lang)
                continue
            if isinstance(text, str) or isinstance(text, unicode):
                try:
                    #Si el valor no es vacio lo registro
                    if text.strip():
                        values += [lang]
                except UnicodeDecodeError:
                    errors[key]. append(_('Invalid encoding for "%s" value')
                        % lang)

        if not values:
            for lang in languages:
                errors[key[:-1] + (key[-1] + '-' + lang,)] = [_('Missing value')]

        return


    #Get values from formulary
    prefix = key[-1] + '-'
    extras = data.get(key[:-1] + ('__extras',), {})

    for name, text in extras.iteritems():
        if not name.startswith(prefix):
            continue

        lang = name.split('-', 1)[1]
        m = re.match(ISO_639_LANGUAGE, lang)
        if not m:
            errors[name] = [_('Invalid language code: "%s"') % lang]
            values = None
            continue

        languages += [lang]
        if text:
            values += [lang]

    if not values:
        for lang in languages:
            errors[key[:-1] + (key[-1] + '-' + lang,)] = [_('Missing value')]

"""
CHECK REQUIRED LANGUAGE
"""
@scheming_validator
def multiple_required_language(field, schema):

    def validator(key, data, errors, context):
        if errors[key]:
            return

        values = []
        languages = []

        required_language = field['required_language']
        if not required_language:
            required_language = config.get('ckan.locale_default', 'es')

        required_field = field.get('required')
        if not required_field:
            required_field = False

        #Get value from dict or JSON encoded string
        value = data[key]
        if value is not missing:
            if isinstance(value, basestring):
                try:
                    value = json.loads(value)
                except ValueError:
                    errors[key].append(_('Failed to decode JSON string'))
                    return
                except UnicodeDecodeError:
                    errors[key].append(_('Invalid encoding for JSON string'))
                    return
            if not isinstance(value, dict):
                errors[key].append(_('Expecting JSON object'))
                return

            for lang, text in value.iteritems():
                try:
                    m = re.match(ISO_639_LANGUAGE, lang)
                except TypeError:
                    errors[key].append(_('Invalid type for language code: %r')
                        % lang)
                    continue

                #Register the language
                languages += [lang]
                if not isinstance(text, basestring):
                    errors[key].append(_('Invalid type for "%s" value') % lang)
                    continue
                if isinstance(text, str) or isinstance(text, unicode):
                    try:
                        #Not register empty values
                        if text.strip():
                            values += [lang]
                    except UnicodeDecodeError:
                        errors[key]. append(_('Invalid encoding for "%s" value')
                            % lang)

            #Error if texts exist but not in required language
            if values and not required_language in values:
                errors[key[:-1] + (key[-1] + '-' + required_language,)] = [_('Missing required language value')]
            else:
                if not values and required_field:
                    errors[key[:-1] + (key[-1] + '-' + required_language,)] = [_('Missing required language value')]

            return


        #Get values from formulary
        prefix = key[-1] + '-'
        extras = data.get(key[:-1] + ('__extras',), {})

        for name, text in extras.iteritems():
            if not name.startswith(prefix):
                continue

            lang = name.split('-', 1)[1]
            m = re.match(ISO_639_LANGUAGE, lang)
            if not m:
                errors[name] = [_('Invalid language code: "%s"') % lang]
                values = None
                continue

            languages += [lang]
            if text:
                values += [lang]

        #Error if texts exist but not in required language
        if values and not required_language in values:
            errors[key[:-1] + (key[-1] + '-' + required_language,)] = [_('Missing required language value')]
        else:
            if not values and required_field:
                errors[key[:-1] + (key[-1] + '-' + required_language,)] = [_('Missing required language value')]

    return validator

"""
VALIDATOR FOR PUBLISHER FIELD
"""
@scheming_validator
def select_organization(field, schema):
    def validator(key, data, errors, context):
        value = data.get(key)
    
        if value is missing or value is None:
            if not authz.check_config_permission('create_unowned_dataset'):
                raise Invalid(_('A organization must be supplied'))
            data.pop(key, None)
            raise df.StopOnError
    
        model = context['model']
        user = context['user']
        user = model.User.get(user)
        if value == '':
            if not authz.check_config_permission('create_unowned_dataset'):
                raise Invalid(_('A organization must be supplied'))
            return
    
        group = model.Group.get(value)
        if not group:
            raise Invalid(_('Organization does not exist'))
        group_id = group.id
    #     if not(user.sysadmin or
    #            authz.has_user_permission_for_group_or_org(
    #                group_id, user.name, 'create_dataset')):
    #         raise Invalid(_('You cannot add a dataset to this organization'))
        data[key] = group_id
    return validator