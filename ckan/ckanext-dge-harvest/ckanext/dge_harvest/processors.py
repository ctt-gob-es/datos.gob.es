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

import sys
import argparse
import xml
import json
import ckanext.dge_harvest.constants as dhc
import ckanext.dge_harvest.helpers as dhh

from pkg_resources import iter_entry_points

from pylons import config

import rdflib
import rdflib.parser
from rdflib import URIRef, BNode, Literal
from rdflib.namespace import Namespace, RDF
from collections import OrderedDict
import ckan.plugins as p

from ckanext.dcat.utils import catalog_uri, url_to_rdflib_format
from ckanext.dge_harvest.utils import dataset_uri

from ckanext.dcat.processors import RDFParserException, \
                                    RDFProfileException, \
                                    RDFProcessor,\
                                    RDFParser,\
                                    RDFSerializer, \
                                    DCAT
from ckanext.dcat.profiles import DCT, XSD
import logging
log = logging.getLogger(__name__)

class DGERDFParser(RDFParser):
    '''
    An RDF to CKAN parser based on rdflib

    Supports different profiles which are the ones that will generate
    CKAN dicts from the RDF graph.
    '''
    def datasets(self, dict=None):
        '''
        Generator that returns CKAN datasets parsed from the RDF graph

        Each dataset is passed to all the loaded profiles before being
        yielded, so it can be further modified by each one of them.

        Returns a dataset dict that can be passed to eg `package_create`
        or `package_update`
        '''
        for dataset_ref in self._datasets():
            dataset_dict = {}
            if (dict is not None):
                for key in dict:
                    value = dict[key] if dict[key] is not None else None
                    if value is not None:
                        dataset_dict[key] = value
            for profile_class in self._profiles:
                profile = profile_class(self.g, self.compatibility_mode)
                profile.parse_dataset(dataset_dict, dataset_ref)

            yield dataset_dict

    def _catalogs(self):
        '''
        Generator that returns all DCAT catalog on the graph

        Yields rdflib.term.URIRef objects that can be used on graph lookups
        and queries
        '''
        for catalog in self.g.subjects(RDF.type, DCAT.Catalog):
            yield catalog

    def catalogs(self):
        '''
        Generator that returns CKAN catalogs parsed from the RDF graph

        Each catalog is passed to all the loaded profiles before being
        yielded, so it can be further modified by each one of them.

        Returns a catalog dict 
        '''
        for catalog_ref in self._catalogs():
            catalog_dict = {}
            for profile_class in self._profiles:
                profile = profile_class(self.g, self.compatibility_mode)
                profile.parse_catalog(catalog_dict, catalog_ref)
            yield catalog_dict



class DGERDFSerializer(RDFSerializer):
    '''
    A CKAN to RDF serializer based on rdflib

    Supports different profiles which are the ones that will generate
    the RDF graph.
    '''

    def serialize_catalog(self, catalog_dict=None, dataset_dicts=None,
                          _format='xml', pagination_info=None):
        '''
        Returns an RDF serialization of the whole catalog

        `catalog_dict` can contain literal values for the dcat:Catalog class
        like `title`, `homepage`, etc. If not provided these would get default
        values from the CKAN config (eg from `ckan.site_title`).

        If passed a list of CKAN dataset dicts, these will be also serializsed
        as part of the catalog.
        **Note:** There is no hard limit on the number of datasets at this
        level, this should be handled upstream.

        The serialization format can be defined using the `_format` parameter.
        It must be one of the ones supported by RDFLib, defaults to `xml`.

        `pagination_info` may be a dict containing keys describing the results
        pagination. See the `_add_pagination_triples()` method for details.

        Returns a string with the serialized catalog
        '''

        catalog_ref = self.graph_from_catalog(catalog_dict)
        if dataset_dicts:
            i = 0
            publishers = {}
            formats = {}
            themes = dhh.dge_harvest_dict_theme_option_label()
            for dataset_dict in dataset_dicts:
                #Add available resource formats in catalog and publishers
                dataset_dict[dhc.EXPORT_AVAILABLE_RESOURCE_FORMATS] = formats
                dataset_dict[dhc.EXPORT_AVAILABLE_PUBLISHERS] = publishers
                dataset_dict[dhc.EXPORT_AVAILABLE_THEMES] = themes
                dataset_ref = self.graph_from_dataset(dataset_dict)
                publishers = dataset_dict.get(dhc.EXPORT_AVAILABLE_PUBLISHERS, {})
                formats = dataset_dict.get(dhc.EXPORT_AVAILABLE_RESOURCE_FORMATS, {})
                i = i+1
                self.g.add((catalog_ref, DCAT.dataset, dataset_ref))

            log.debug("[processors] serialize_catalog Total datasets i=%s", i)
            self.g.add((catalog_ref, DCT.extent, Literal(i, datatype=XSD.nonNegativeInteger)))
        
        if pagination_info:
            self._add_pagination_triples(pagination_info)
        
        _format = url_to_rdflib_format(_format)
        output = self.g.serialize(format=_format)

        return output
    
    def serialize_catalog_EDP(self, catalog_dict=None, dataset_dicts=None, _format='xml', pagination_info=None):
        '''
        Returns an RDF serialization of the whole catalog

        `catalog_dict` can contain literal values for the dcat:Catalog class
        like `title`, `homepage`, etc. If not provided these would get default
        values from the CKAN config (eg from `ckan.site_title`).

        If passed a list of CKAN dataset dicts, these will be also serializsed
        as part of the catalog.
        **Note:** There is no hard limit on the number of datasets at this
        level, this should be handled upstream.

        The serialization format can be defined using the `_format` parameter.
        It must be one of the ones supported by RDFLib, defaults to `xml`.

        `pagination_info` may be a dict containing keys describing the results
        pagination. See the `_add_pagination_triples()` method for details.

        Returns a string with the serialized catalog
        '''
        catalog_ref = self.graph_from_catalog_EDP(catalog_dict)
        if dataset_dicts:
            i = 0
            publishers = {}
            formats = {}
            themes = dhh.dge_harvest_dict_theme_option_label()
            for dataset_dict in dataset_dicts:
                #Add available resource formats in catalog and publishers
                dataset_dict[dhc.EXPORT_AVAILABLE_RESOURCE_FORMATS] = formats
                dataset_dict[dhc.EXPORT_AVAILABLE_PUBLISHERS] = publishers
                dataset_dict[dhc.EXPORT_AVAILABLE_THEMES] = themes
                dataset_ref = self.graph_from_dataset_EDP(dataset_dict)
                publishers = dataset_dict.get(dhc.EXPORT_AVAILABLE_PUBLISHERS, {})
                formats = dataset_dict.get(dhc.EXPORT_AVAILABLE_RESOURCE_FORMATS, {})
                i = i+1
                self.g.add((catalog_ref, DCAT.dataset, dataset_ref))

            log.debug("[processors] serialize_catalog Total datasets i=%s", i)
            self.g.add((catalog_ref, DCT.extent, Literal(i, datatype=XSD.nonNegativeInteger)))
        
        if pagination_info:
            self._add_pagination_triples(pagination_info)
        _format = url_to_rdflib_format(_format)
        output = self.g.serialize(format=_format)

        return output
    
    def graph_from_dataset(self, dataset_dict):
        '''
        Given a CKAN dataset dict, creates a graph using the loaded profiles

        The class RDFLib graph (accessible via `serializer.g`) will be updated
        by the loaded profiles.

        Returns the reference to the dataset, which will be an rdflib URIRef.
        '''
        
        dataset_ref = URIRef(self._dge_harvest_dataset_uri(dataset_dict))

        for profile_class in self._profiles:
            profile = profile_class(self.g, self.compatibility_mode)
            profile.graph_from_dataset(dataset_dict, dataset_ref)

        return dataset_ref


    def graph_from_dataset_EDP(self, dataset_dict):
        '''
        Given a CKAN dataset dict, creates a graph using the loaded profiles

        The class RDFLib graph (accessible via `serializer.g`) will be updated
        by the loaded profiles.

        Returns the reference to the dataset, which will be an rdflib URIRef.
        '''
        dataset_ref = URIRef(self._dge_harvest_dataset_uri(dataset_dict))
        for profile_class in self._profiles:
            profile = profile_class(self.g, self.compatibility_mode)
            profile.graph_from_dataset_EDP(dataset_dict, dataset_ref)

        return dataset_ref
    
    def _dge_harvest_dataset_uri(self, dataset_dict):
        '''
        Returns an URI for the dataset
    
        This will be used to uniquely reference the dataset on the RDF
        serializations.
    
        The value will be the first found of:
    
            1. `catalog_uri()` + '/catalogo/' + `name` field
            2. The value of the `uri` field
            3. The value of an extra with key `uri`
            4. `catalog_uri()` + '/catalogo/' + `id` field
    
        Check the documentation for `catalog_uri()` for the recommended ways of
        setting it.
    
        Returns a string with the dataset URI.
        '''
    
        if dataset_dict.get('name'):
            uri = '{0}/catalogo/{1}'.format(catalog_uri().rstrip('/'), dataset_dict['name'])
        if not uri:
            uri = dataset_uri(dataset_dict)
        return uri