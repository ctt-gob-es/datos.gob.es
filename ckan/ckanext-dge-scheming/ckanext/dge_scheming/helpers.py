# Copyright (C) 2017 Entidad Pública Empresarial Red.es
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

import re
from ckanext.scheming.helpers import lang
from ckan.lib.helpers import get_available_locales
from pylons.i18n import gettext
from pylons import config

import ckan.model as model
import ckan.lib.dictization.model_dictize as model_dictize

import logging
log = logging.getLogger(__name__)


def dge_dataset_form_organization_list():
    """
    Get a list of all active organizations
    """
    context = {'model': model}
    orgs_q = model.Session.query(model.Group) \
        .filter(model.Group.is_organization == True) \
        .filter(model.Group.state == 'active')

    orgs_list = model_dictize.group_list_dictize(orgs_q.all(), context)
    return orgs_list

def dge_dataset_form_value(text):
    """
    :param text: {lang: text} dict or text string

    Convert "language-text" to users' language by looking up
    languag in dict or using gettext if not a dict but. If the text
    doesn't exist look for an available text
    """
    if not text:
        return u''

    if hasattr(text, 'get'):
        final_text = u''
        try:
            prefer_lang = lang()
        except:
            prefer_lang = config.get('ckan.locale_default', 'es')
        else:
            try:
                final_text = text[prefer_lang]
            except KeyError:
                pass

        if not final_text:
            locale_order = config.get('ckan.locale_order', '').split()
            for l in locale_order:
                if l in text and text[l]:
                    final_text = text[l]
                    break
        return final_text

    t = gettext(text)
    if isinstance(t, str):
        return t.decode('utf-8')
    return t

def dge_dataset_form_lang_and_value(text):
    """
    :param text: {lang: text} dict or text string

    Convert "language-text" to users' language by looking up
    languag in dict, if the text
    doesn't exit look for an available text
    """
    if not text:
        return {'': u''}

    if hasattr(text, 'get'):
        final_text = u''
        try:
            prefer_lang = lang()
        except:
            prefer_lang = config.get('ckan.locale_default', 'es')
        else:
            try:
                prefer_lang = str(prefer_lang)
                final_text = text[prefer_lang]
            except KeyError:
                pass

        if not final_text:
            locale_order = config.get('ckan.locale_order', '').split()
            for l in locale_order:
                if l in text and text[l]:
                    final_text = text[l]
                    prefer_lang = l
                    break

        return {prefer_lang: final_text}

    return {'': u''}


def dge_is_uri(value):
    '''
    Given a value, raises an RDFParsesException if value is not a complete
    URI.
    A complete URI starts with scheme_name: ([A-Za-z][A-Za-z0-9+.-]*):
    '''
    is_uri = False
    pattern = '^([A-Za-z][A-Za-z0-9+.-]*):'
    if (value and value.strip() != '' and re.match(pattern, value)):
        is_uri = True

    return is_uri


def dge_multiple_field_required(field, lang):
    """
    Return field['required'] or guess based on validators if not present.
    """
    if 'required' in field:
        return field['required']
    if 'required_language' in field and field['required_language'] == lang:
        return True
    return 'not_empty' in field.get('validators', '').split()
