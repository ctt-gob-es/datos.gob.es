# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge_harvest (datos.gob.es)".
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

import logging
import uuid

from pylons import config

from ckan import model
import ckan.plugins.toolkit as toolkit
from ckanext.dcat.utils import catalog_uri

_ = toolkit._

log = logging.getLogger(__name__)





def dataset_uri(dataset_dict):
    '''
    Returns an URI for the dataset

    This will be used to uniquely reference the dataset on the RDF
    serializations.

    The value will be the first found of:

        1. The value of the `uri` field
        2. The value of an extra with key `uri`
        3. `catalog_uri()` + '/dataset/' + `id` field

    Check the documentation for `catalog_uri()` for the recommended ways of
    setting it.

    Returns a string with the dataset URI.
    '''

    uri = dataset_dict.get('uri')
    if not uri:
        for extra in dataset_dict.get('extras', []):
            if extra['key'] == 'uri' and extra['value'] != 'None':
                uri = extra['value']
                break
    if not uri and dataset_dict.get('id'):
        uri = '{0}/catalogo/{1}'.format(catalog_uri().rstrip('/'),
                                       dataset_dict['id'])
    if not uri:
        uri = '{0}/catalogo/{1}'.format(catalog_uri().rstrip('/'),
                                       str(uuid.uuid4()))
        log.warning('Using a random id for dataset URI')

    return uri


def resource_uri(resource_dict):
    '''
    Returns an URI for the resource

    This will be used to uniquely reference the resource on the RDF
    serializations.

    The value will be the first found of:

        1. The value of the `uri` field
        2. `catalog_uri()` + '/dataset/' + `package_id` + '/resource/'
            + `id` field

    Check the documentation for `catalog_uri()` for the recommended ways of
    setting it.

    Returns a string with the resource URI.
    '''

    uri = resource_dict.get('uri')
    if not uri or uri == 'None':
        dataset_id = dataset_id_from_resource(resource_dict)

        uri = '{0}/catalog/{1}/resource/{2}'.format(catalog_uri().rstrip('/'),
                                                    dataset_id,
                                                    resource_dict['id'])

    return uri