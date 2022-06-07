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

#!/usr/bin/env python
# -*- coding: 850 -*-
# -*- coding: utf-8 -*-
from __future__ import division
import math
import json
import datetime
import losser.losser
import iso8601
import smtplib
import re

import ckan.lib.helpers as h
import ckanext.dge_harvest.constants as dhc
import ckanext.dge_harvest.helpers as dhh
import ckanext.scheming.helpers as sh
import ckanext.dcat.converters as converters
import ckan.lib.base as base
import paste.deploy.converters
import ckan.model as model

from pytz import timezone

from pylons import config
from dateutil.parser import parse as dateutil_parse
from ckanext.dge_harvest.utils import dataset_uri
from ckanext.harvest.model import HarvestSource
from email.mime.text import MIMEText
from email.MIMEMultipart import MIMEMultipart


from ckan.plugins import toolkit

from ckanext.dcat.processors import RDFSerializer
from ckanext.dge_harvest.processors import DGERDFSerializer
from ckan.common import _

import logging
log = logging.getLogger(__name__)

DATASETS_PER_PAGE = 500
RDF_FORMAT = 'rdf'
CSV_FORMAT = 'csv'
MAIN_SEPARATOR = '//'
SECONDARY_SEPARATOR = ';'

wrong_page_exception = toolkit.ValidationError(
    'Page param must be a positive integer starting in 1')


@toolkit.side_effect_free
def dge_harvest_catalog_show(context, data_dict):
    method_log_prefix = '[%s][dge_harvest_catalog_show]' % __name__
    output = None
    try:
        log.debug('%s Init method. Inputs context=%s, data_dict=%s' % (method_log_prefix, context, data_dict))
        ini = datetime.datetime.now()
        toolkit.check_access('dge_harvest_catalog_show', context, data_dict)

        page = 1
        data_dict['page'] = page
        limit = data_dict.get('limit', -1)
        _format=data_dict.get('format')
        if _format==RDF_FORMAT:
            filepath = config.get('ckanext.dge_harvest.rdf.filepath', '/tmp/catalog.rdf')
        elif _format==CSV_FORMAT:
            filepath = config.get('ckanext.dge_harvest.csv.filepath', '/tmp/catalog.csv')
            columnsfilepath = config.get('ckanext.dge_harvest.csv.columns.filepath', '/usr/lib/ckan/default/src/ckanext-dge-harvest/ckanext/dge_harvest/commands/columns.json')
        else:
            filepath = '/tmp/catalog.' + _format
        query = _dge_harvest_search_ckan_datasets(context, data_dict)
        dataset_dicts = query['results']
        total_datasets = query['count']
        log.debug('%s Total_datasets obtenidos en la query: %s' % (method_log_prefix, total_datasets))
        if limit > -1 and limit < total_datasets:
            total_datasets = limit
        num = len(dataset_dicts)
        log.debug('%s Total_datasets a exportar: %s' % (method_log_prefix, total_datasets))

        while (total_datasets > num):
            page = page + 1
            data_dict['page'] = page
            query = _dge_harvest_search_ckan_datasets(context, data_dict)
            dataset_dicts.extend(query['results'])
            total_datasets = query['count']
            num = len(dataset_dicts)
            log.debug('%s Total_datasets obtenidos en la query: %s' % (method_log_prefix, total_datasets))
            log.debug('%s Total_datasets a exportar: %s' % (method_log_prefix, num))

        if _format==RDF_FORMAT:
            serializer = DGERDFSerializer()
            #log.debug("%s DATASET_DICTS = %s" % (method_log_prefix,dataset_dicts))
            output = serializer.serialize_catalog({}, dataset_dicts, _format=data_dict.get('format'), pagination_info=None)
        elif _format == CSV_FORMAT and columnsfilepath:
            output = _dge_csv_serialize_datasets(dataset_dicts, columnsfilepath)

        if filepath:
            file = None
            try:
                file = open(filepath, "w")
                file.write(output)
                file.close()
            except:
                if file and not file.closed:
                    file.close()

        end = datetime.datetime.now()
        log.debug("%s Time in serialize %s catalog [%s] with %s datasets ... %s milliseconds" % (method_log_prefix, _format, filepath, total_datasets, int((end - ini).total_seconds() * 1000)))
    except Exception, e:
        log.error("%s Exception %s: %s" % (method_log_prefix, type(e).__name__, e))
        output = None
    #log.debug('%s End method. Results = %s' % (method_log_prefix, output))
    log.debug('%s End method.' % (method_log_prefix))
    return output

#RDF EDP SDA-667
def dge_harvest_catalog_show_EDP(context, data_dict):
    method_log_prefix = '[%s][dge_harvest_catalog_show]' % __name__
    output = None
    try:
        log.debug('%s Init method. Inputs context=%s, data_dict=%s' % (method_log_prefix, context, data_dict))
        ini = datetime.datetime.now()
        toolkit.check_access('dge_harvest_catalog_show', context, data_dict)

        page = 1
        data_dict['page'] = page
        limit = data_dict.get('limit', -1)
        _format = data_dict.get('format')
        if _format == RDF_FORMAT:
            filepath = config.get('ckanext.dge_harvest.rdf_edp.filepath', '/tmp/catalog.rdf')
        else:
            filepath = '/tmp/catalog.' + _format
        query = _dge_harvest_search_ckan_datasets(context, data_dict)
        dataset_dicts = query['results']
        total_datasets = query['count']
        log.debug('%s Total_datasets obtenidos en la query: %s' % (method_log_prefix, total_datasets))
        if limit > -1 and limit < total_datasets:
            total_datasets = limit
        num = len(dataset_dicts)
        log.debug('%s Total_datasets a exportar: %s' % (method_log_prefix, total_datasets))

        while (total_datasets > num):
            page = page + 1
            data_dict['page'] = page
            query = _dge_harvest_search_ckan_datasets(context, data_dict)
            dataset_dicts.extend(query['results'])
            total_datasets = query['count']
            num = len(dataset_dicts)
            log.debug('%s Total_datasets obtenidos en la query: %s' % (method_log_prefix, total_datasets))
            log.debug('%s Total_datasets a exportar: %s' % (method_log_prefix, num))

        if _format == RDF_FORMAT:
            serializer = DGERDFSerializer()
            # log.debug("%s DATASET_DICTS = %s" % (method_log_prefix,dataset_dicts))
            output = serializer.serialize_catalog_EDP({}, dataset_dicts, _format=data_dict.get('format'), pagination_info=None)
        if filepath:
            file = None
            try:
                file = open(filepath, "w")
                file.write(output)
                file.close()
            except:
                if file and not file.closed:
                    file.close()

        end = datetime.datetime.now()
        log.debug("%s Time in serialize %s catalog [%s] with %s datasets ... %s milliseconds" % (
            method_log_prefix, _format, filepath, total_datasets, int((end - ini).total_seconds() * 1000)))
    except Exception, e:
        log.error("%s Exception %s: %s" % (method_log_prefix, type(e).__name__, e))
        output = None
    # log.debug('%s End method. Results = %s' % (method_log_prefix, output))
    log.debug('%s End method.' % (method_log_prefix))
    return output


def dge_harvest_dataset_show(context, data_dict):
    method_log_prefix = '[%s][dge_harvest_dataset_show]' % __name__
    output = None
    log.debug('%s Init method. Inputs context=%s, data_dict=%s' %
              (method_log_prefix, context, data_dict))
    toolkit.check_access('dge_harvest_dataset_show', context, data_dict)

    dataset_dict = toolkit.get_action('package_show')(context, data_dict)
    _format = data_dict.get('format')

    if _format and _format == 'csv':
        columnsfilepath = config.get('ckanext.dge_harvest.csv.columns.filepath',
                                     '/usr/lib/ckan/default/src/ckanext-dge-harvest/ckanext/dge_harvest/commands/columns.json')
        dataset_dicts = []
        dataset_dicts.append(dataset_dict)
        output = _dge_csv_serialize_datasets(dataset_dicts, columnsfilepath)
    else:
        serializer = DGERDFSerializer()
        output = serializer.serialize_dataset(dataset_dict,
                                              _format=data_dict.get('format'))
    log.debug('%s End method.' % (method_log_prefix))
    return output


def _dge_csv_serialize_datasets(dataset_dicts, columnsfilepath):
    method_log_prefix = '[%s][_dge_csv_serialize_datasets]' % __name__
    output = None
    log.debug('%s Init method.' % method_log_prefix)
    # log.debug('%s Init method. Inputs dataset_dicts=%s, columnsfilepath=%s' % (
    #    method_log_prefix, dataset_dicts, columnsfilepath))
    #log.info('%s Dataset_dicts de partida =%s' % (method_log_prefix, dataset_dicts))

    if not (dataset_dicts and columnsfilepath):
        return None

    organizations = {}
    themes = dhh.dge_harvest_dict_theme_option_label()
    spatial_coverages = dhh.dge_harvest_dict_spatial_coverage_option_label()
    _dataset = sh.scheming_get_schema('dataset', 'dataset')
    res_format = sh.scheming_field_by_name(
        _dataset.get('resource_fields'), 'format')
    format_values = res_format['choices']
    formats = {}
    datasets = []
    num = 0
    for dataset in dataset_dicts:
        ds = {}
        # Id
        #ds['id'] = _encode_value(dataset.get('id', None))

        # ulr
        ds['url'] = dataset_uri(dataset)

        # Description
        descriptions = _from_dict_to_string(
            dataset.get(dhc.DS_DESCRIPTION, None))
        ds['description'] = _encode_value(descriptions, True)

        # Title
        titles = _from_dict_to_string(
            dataset.get(dhc.DS_TITLE_TRANSLATED, None))
        ds['title'] = _encode_value(titles, True)

        # Theme
        theme_values = dataset.get(dhc.DS_THEME, None)
        theme_labels = []
        if theme_values:
            for value in theme_values:
                theme = themes.get(value)
                if theme and theme.get('label'):
                    theme_labels.append(theme.get('label').get('es'))
            theme_value = _from_list_to_string(theme_labels)
            ds['theme'] = _encode_value(theme_value, True)

        # Keywords
        #Keywords
        #tags = dataset.get(dhc.DS_TAGS)
        #value = None
        #if tags and len(tags) > 0:
        #    for tag in tags:
        #        stag = tag.get('name', None)
        #        if stag:
        #            if value:
        #                value = '%s%s%s' % (value, MAIN_SEPARATOR, stag)
        #            else:
        #                value = stag
        #    ds['tags'] = _encode_value(value, True)

        tags = dataset.get(dhc.DS_MULTILINGUAL_TAGS)
        value = None
        if tags and len(tags) > 0:
            tags_field = None
            for key, value in tags.items():
                if value and len(value) > 0:
                    if tags_field:
                        tags_field = '%s[%s]%s' % (tags_field, key, _from_list_to_string(value))
                    else:
                        tags_field = '[%s]%s' % (key, _from_list_to_string(value))
            if tags_field:
                ds['tags'] = _encode_value(tags_field, True)

        # Identifier
        ds['identifier'] = _encode_value(dataset.get('identifier', None), True)

        # Created
        ds['issued_date'] = _encode_value(
            _from_iso8601_date_to_string(dataset.get(dhc.DS_ISSUED_DATE, None)))

        # Modified
        ds['modified_date'] = _encode_value(
            _from_iso8601_date_to_string(dataset.get(dhc.DS_MODIFIED_DATE, None)))

        # Accrual Periodicity
        frequency = dataset.get(dhc.DS_FREQUENCY)
        if (frequency):
            stype = frequency.get('type', '')
            if stype and len(stype) > 0:
                stype = 'http://www.w3.org/2006/time#' + stype
            svalue = frequency.get('value', '')
            sfrequency = '[TYPE]%s[VALUE]%s' % (stype, svalue)
            ds['frequency'] = _encode_value(sfrequency, True)

        # Language
        languages = _from_list_to_string(dataset.get(dhc.DS_LANGUAGE))
        ds['language'] = _encode_value(languages, True)

        # Publisher
        publisher = dataset.get(dhc.DS_PUBLISHER, None)
        if publisher:
            if publisher in organizations:
                ds['publisher'] = _encode_value(
                    organizations.get(publisher, None), True)
            else:
                organization = h.get_organization(publisher, False)
                if organization:
                    organizations[publisher] = organization.get(
                        'title', organization.get('display_name', None))
                    ds['publisher'] = _encode_value(
                        organizations.get(publisher), True)
                else:
                    organization = model.Group.get(publisher)
                    if organization:
                        organizations[publisher] = organization.title if organization.title else organization.name
                        ds['publisher'] = _encode_value(organizations.get(publisher), True)


        # License
        ds['license_id'] = _encode_value(dataset.get(dhc.DS_LICENSE), True)

        # Spatial
        spatial_values = dataset.get(dhc.DS_SPATIAL, None)
        spatial_labels = []
        if spatial_values:
            for value in spatial_values:
                spatial = spatial_coverages.get(value)
                if spatial and spatial.get('label') and spatial.get('label').get('es'):
                    spatial_labels.append(spatial.get('label').get('es'))
            spatials = _from_list_to_string(spatial_labels)
            ds['spatial'] = _encode_value(spatials, True)

        # Temporal
        temporal_coverage = dataset.get(dhc.DS_TEMPORAL_COVERAGE)
        if temporal_coverage:
            value = None
            for tc in temporal_coverage.itervalues():
                if tc:
                    tc_from = _from_iso8601_date_to_string(
                        tc.get('from', None))
                    tc_to = _from_iso8601_date_to_string(tc.get('to', None))
                    if tc_from or tc_to:
                        if value:
                            value = '%s%s%s-%s' % (value, MAIN_SEPARATOR,
                                                   (tc_from or ''), (tc_to or ''))
                        else:
                            value = '%s-%s' % ((tc_from or ''), (tc_to or ''))
            ds['coverage_new'] = _encode_value(value, True)

        # Valid
        ds['valid'] = _encode_value(_from_iso8601_date_to_string(
            dataset.get(dhc.DS_VALID, None)), True)

        # References
        references = _from_list_to_string(dataset.get(dhc.DS_REFERENCE, None))
        ds['references'] = _encode_value(references, True)

        # Normative
        conforms_to = _from_list_to_string(dataset.get(dhc.DS_NORMATIVE, None))
        ds['conforms_to'] = _encode_value(conforms_to, True)

        # Resources
        resources = dataset.get(dhc.DS_RESOURCES)
        sresources = []
        if resources:
            for resource in resources:
                sresource = None
                if resource:
                    name = _from_dict_to_string(resource.get(
                        dhc.DS_RESOURCE_NAME_TRANSLATED, None), 'TITLE_')
                    if not name:
                        name = ''
                    url = resource.get(dhc.DS_RESOURCE_ACCESS_URL, '')
                    if url:
                        url = '[ACCESS_URL]%s' % (url)

                    format_value = resource.get(dhc.DS_RESOURCE_FORMAT, None)
                    format = None
                    if format_value:
                        if format_value in formats:
                            format = formats.get(format_value, None)
                        else:
                            formats[format_value] = sh.scheming_choices_label(
                                format_values, format_value)
                            format = formats.get(format_value, None)
                    if format:
                        format = '[MEDIA_TYPE]%s' % (format)
                    size = resource.get(dhc.DS_RESOURCE_BYTE_SIZE, '')
                    if size:
                        size = '[BYTE_SIZE]%s' % (size)
                    relation = _from_list_to_string(resource.get(
                        dhc.DS_RESOURCE_RELATION, None), SECONDARY_SEPARATOR)
                    relations = ''
                    if relation:
                        relations = '[RELATION]%s' % (relation)
                    sresource = '%s%s%s%s%s' % (
                        name, url, format, size, relations)
                    if sresource and len(sresource) > 0:
                        sresources.append(sresource)
        if len(sresources) > 0:
            value = None
            for item in sresources:
                if value:
                    value = '%s%s%s' % (value, MAIN_SEPARATOR, item)
                else:
                    value = item
            ds['resources'] = _encode_value(value, True)

        num = num + 1
        datasets.append(ds)
    #log.debug('%s Datasets con datos a exportar=%s' % (method_log_prefix, datasets))
    log.debug('%s Numero de datasets con datos a exportar...%s' %
              (method_log_prefix, num))
    output = losser.losser.table(
        datasets, columnsfilepath, csv=True, pretty=False)
    log.debug('%s End method.' % (method_log_prefix))
    return output


def _encode_value(value=None, clean=False):
    if value:
        if clean and clean == True:
            value = re.sub('[\n\r]', ' ', value)
        return value.encode('utf-8')

def _from_list_to_string(data_list=None, separator = MAIN_SEPARATOR):
    method_log_prefix = '[%s][_from_list_to_string]' % __name__
    result = None
    try:
        if data_list:
            for value in data_list:
                if result:
                    result = "%s%s%s" % (result, separator, value)
                else:
                    result = "%s"%(value)
    except Exception, e:
        result = None
        log.error("%s Exception %s: %s" % (method_log_prefix, type(e).__name__, e))
    return result

def _from_dict_to_string(data_dict=None, key_prefix=None):
    method_log_prefix = '[%s][_from_dict_to_string]' % __name__
    result = None
    try:
        if data_dict:
            for key, value in data_dict.items():
                if value and len(value) > 0:
                    if key_prefix:
                        key = key_prefix + key
                    if result:
                        result = '%s[%s]%s' % (result, key, value)
                    else:
                        result = '[%s]%s' % (key, value)
    except Exception, e:
        result = None
        log.error("%s Exception %s: %s" % (method_log_prefix, type(e).__name__, e))
    return result

def _from_iso8601_date_to_string(datevalue):
    method_log_prefix = '[%s][_from_dict_to_string]' % __name__
    result = None
    try:
        if (datevalue):

            default_timezone = timezone(dhc.DEFAULT_TIMEZONE)
            naive = iso8601.parse_date(datevalue, None)
            local_dt = default_timezone.localize(naive, is_dst=None)
            result = local_dt.strftime("%Y-%m-%dT%H:%M:%S%z")
    except Exception, e:
        result = datevalue
        log.error("%s Exception %s: %s" % (method_log_prefix, type(e).__name__, e))
    return result

def _dge_harvest_search_ckan_datasets(context, data_dict):

    method_log_prefix = '[%s][_dge_harvest_search_ckan_datasets]' % __name__
    log.debug('%s Init method. Inputs context=%s, data_dict=%s' % (method_log_prefix, context, data_dict))
    n = int(config.get('ckanext.dcat.datasets_per_page', DATASETS_PER_PAGE))
    limit = data_dict.get('limit', -1)
    if limit > -1 and limit < n:
        n = limit

    page = data_dict.get('page', 1) or 1
    try:
        page = int(page)
        if page < 1:
            raise wrong_page_exception
    except ValueError:
        raise wrong_page_exception

    modified_since = data_dict.get('modified_since')
    if modified_since:
        try:
            modified_since = dateutil_parse(modified_since).isoformat() + 'Z'
        except (ValueError, AttributeError):
            raise toolkit.ValidationError(
                'Wrong modified date format. Use ISO-8601 format')

    search_data_dict = {
        'rows': n,
        'start': n * (page - 1),
        'sort': 'organization asc, metadata_modified desc',
    }

    search_data_dict['q'] = data_dict.get('q', '*:*')
    search_data_dict['fq'] = data_dict.get('fq')
    search_data_dict['fq_list'] = []

    # Exclude certain dataset types
    search_data_dict['fq_list'].append('-dataset_type:harvest')
    search_data_dict['fq_list'].append('-dataset_type:showcase')

    if modified_since:
        search_data_dict['fq_list'].append(
            'metadata_modified:[{0} TO NOW]'.format(modified_since))

    query = toolkit.get_action('package_search')(context, search_data_dict)

    log.debug('%s End method. Returns query=%s' % (method_log_prefix, query))
    return query


def dge_harvest_clear_old_harvest_jobs(context, data_dict):
    '''
    Clears all finished jobs that have been created over one month ago of a harvest source
    except the last job by source if it has been created makes more than one month will be cleared.
    The datasets imported from the harvest source will NOT be deleted!!!
    :param id: the id of the harvest source to clear
    :type id: string
    '''
    method_log_prefix = '[%s][dge_harvest_clear_old_harvest_jobs]' % __name__
    log.debug('%s Init method. Inputs context=%s, data_dict=%s' % (method_log_prefix, context, data_dict))
    toolkit.check_access('dge_harvest_clear_old_harvest_jobs', context, data_dict)

    harvest_source_id = data_dict.get('id', None)
    interval_value = config.get('ckanext.dge_harvest.clear_jobs.interval', '1 month')
    model = context['model']
    source_list = []
    sql = None
    if harvest_source_id:
        sql = '''select distinct hj.source_id, p.name from harvest_job hj,
                 package p where hj.source_id = p.id and p.type like 'harvest'
                 and source_id like '{source_id}';'''.format(source_id = harvest_source_id)
    else:
        sql = '''select distinct hj.source_id, p.name from harvest_job hj,
                 package p where hj.source_id = p.id and p.type like 'harvest';'''
    if sql:
        result = model.Session.execute(sql)
        if result:
            for row in result:
                source_id = row[0] if row else None
                if source_id:
                    source_list.append({'id': row[0], 'name': row[1] if row[1] else ''})

    if source_list:
        sql = '''begin;'''
        for item in source_list:
            hs_id = item.get('id', None)
            if hs_id:
                sql += '''
                    delete from harvest_object_error where harvest_object_id in (select id from harvest_object where current=false and harvest_job_id in (select id from harvest_job where status like 'Finished' and created <= (now() - interval '{interval_value}') and  source_id like '{harvest_source_id}' and id not in (select h.id from (select ROW_NUMBER() OVER (PARTITION BY hj.source_id order by hj.created desc) as rn, * from Harvest_job hj where source_id like '{harvest_source_id}') h where h.rn = 1 and h.created <= (now() - interval '{interval_value}') order by created desc) order by source_id desc, created desc));
                    delete from harvest_object_extra where harvest_object_id in (select id from harvest_object where current=false and harvest_job_id in (select id from harvest_job where status like 'Finished' and created <= (now() - interval '{interval_value}') and  source_id like '{harvest_source_id}' and id not in (select h.id from (select ROW_NUMBER() OVER (PARTITION BY hj.source_id order by hj.created desc) as rn, * from Harvest_job hj where source_id like '{harvest_source_id}') h where h.rn = 1 and h.created <= (now() - interval '{interval_value}') order by created desc) order by source_id desc, created desc));
                    delete from harvest_gather_error where harvest_job_id in (select id from harvest_job where status like 'Finished' and created <= (now() - interval '{interval_value}') and  source_id like '{harvest_source_id}' and id not in (select h.id from (select ROW_NUMBER() OVER (PARTITION BY hj.source_id order by hj.created desc) as rn, * from Harvest_job hj where source_id like '{harvest_source_id}') h where h.rn = 1 and h.created <= (now() - interval '{interval_value}') order by created desc) order by source_id desc, created desc);
                    delete from harvest_object where current=false and harvest_job_id in (select id from harvest_job where status like 'Finished' and created <= (now() - interval '{interval_value}') and  source_id like '{harvest_source_id}' and id not in (select h.id from (select ROW_NUMBER() OVER (PARTITION BY hj.source_id order by hj.created desc) as rn, * from Harvest_job hj where source_id like '{harvest_source_id}') h where h.rn = 1 and h.created <= (now() - interval '{interval_value}') order by created desc) order by source_id desc, created desc);
                    delete from harvest_job where status like 'Finished' and created <= (now() - interval '{interval_value}') and  source_id like '{harvest_source_id}' and id not in (select h.id from (select ROW_NUMBER() OVER (PARTITION BY hj.source_id order by hj.created desc) as rn, * from Harvest_job hj where source_id like '{harvest_source_id}') h where h.rn = 1 and h.created <= (now() - interval '{interval_value}') order by created desc);
                    '''.format(harvest_source_id=hs_id, interval_value=interval_value)
        sql += '''commit;'''
        model.Session.execute(sql)
        # Refresh the index for this source to update the status object
        for item in source_list:
            hs_id = item.get('id', None)
            if hs_id:
                toolkit.get_action('harvest_source_reindex')(context, {'id': hs_id})
        log.debug('%s End method. Returns %s' % (method_log_prefix, source_list))
        return source_list

def _dge_harvest_send_email(from_addr, to_addrs, msg):
    log.info("Sending email from {0} to {1}".format(from_addr, to_addrs))
    # Send the email using Python's smtplib.
    smtp_connection = smtplib.SMTP()
    #smtp_connection.set_debuglevel(1) descomentar para pruebas
    if 'smtp.test_server' in config:
        # If 'smtp.test_server' is configured we assume we're running tests,
        # and don't use the smtp.server, starttls, user, password etc. options.
        smtp_server = config['smtp.test_server']
        smtp_starttls = False
        smtp_user = None
        smtp_password = None
    else:
        smtp_server = config.get('smtp.server', 'localhost')
        smtp_starttls = paste.deploy.converters.asbool(
                        config.get('smtp.starttls'))
        smtp_user = config.get('smtp.user')
        smtp_password = config.get('smtp.password')
    smtp_connection.connect(smtp_server)
    try:
        #smtp_connection.set_debuglevel(True)

        # Identify ourselves and prompt the server for supported features.
        smtp_connection.ehlo()

        # If 'smtp.starttls' is on in CKAN config, try to put the SMTP
        # connection into TLS mode.
        if smtp_starttls:
            if smtp_connection.has_extn('STARTTLS'):
                smtp_connection.starttls()
                # Re-identify ourselves over TLS connection.
                smtp_connection.ehlo()
            else:
                raise MailerException("SMTP server does not support STARTTLS")

        # If 'smtp.user' is in CKAN config, try to login to SMTP server.
        if smtp_user:
            assert smtp_password, ("If smtp.user is configured then "
                    "smtp.password must be configured as well.")
            smtp_connection.login(smtp_user, smtp_password)

        smtp_connection.sendmail(from_addr, to_addrs, msg.as_string())
        log.info("Sent email from {0} to {1}".format(from_addr, to_addrs))

    except smtplib.SMTPException, e:
        msg = '%r' % e
        log.exception(msg)
        raise MailerException(msg)
    finally:
        smtp_connection.quit()


def dge_harvest_source_email_job_finished(context, data_dict):
    method_log_prefix = '[%s][dge_harvest_source_email_job_finished]' % __name__
    log.debug('%s Init method. Inputs context=%s, data_dict=%s' % (method_log_prefix, context, data_dict))
    toolkit.check_access('dge_harvest_source_email_job_finished', context, data_dict)
    model = context['model']
    source_id = data_dict.get('source_id')
    job_id = data_dict.get('job_id')
    pkg = model.Package.get(source_id)
    if pkg is None:
        raise NotFound
    source_status_dict = toolkit.get_action('harvest_source_show_status')(context, {'id': source_id})
    last_job = source_status_dict.get('last_job', None);
    members = toolkit.get_action('member_list')(
                        context, {'id': pkg.owner_org, 'object_type': 'user', 'capacity': 'editor'})
    if members is None:
        raise NotFound

    #To
    mail_to = []
    for member in members:
        user = model.User.get(member[0])
        if user.state == 'active' and user.email and len(user.email) > 0:
            mail_to.append(user.email)

    #From
    mail_from = config.get('smtp.mail_from', None)

    #CC
    mail_ccs = config.get('smtp.mail_cc', '').split(' ')

    #Reply-To
    mail_reply_to = config.get('smtp.mail_reply_to', None)

    #Subject
    subject = u'Finalizada federaci\u00F3n con %s' % (config.get('ckan.site_title', 'datos.gob.es'))

    #Body
    url_job = config.get('ckan.site_url') + "/harvest/" + pkg.name + "/job/" + job_id;
    url_job = url_job.replace("http://", "https://")
    mail_body = """* %s: %s\n* %s: %s\n* %s: %s\n* %s: %s\n* %s: %s\n* %s: %s\n* %s: %s\n* %s: %s\n* %s: %s\n* %s: %s\n---\nMessage sent by %s (%s)
                """ % ('Id', job_id,
                       'Created', h.render_datetime(last_job['created'], with_hours=True),
                       'Started', h.render_datetime(last_job['gather_started'], with_hours=True),
                       'Finished', h.render_datetime(last_job['finished'], with_hours=True),
                       'Status', last_job['status'],
                       'Deleted', str(last_job['stats']['deleted']),
                       'Updated', str(last_job['stats']['updated']),
                       'Added', str(last_job['stats']['added']),
                       'Errors/warnings', str(last_job['stats']['errored']),
                       'View full job report', url_job,
                       config.get('ckan.site_title', 'datos.gob.es'),
                       config.get('ckan.site_url'))
    msg = MIMEMultipart()
    if mail_from:
        msg['From'] = mail_from
    if mail_reply_to:
        msg['Reply-To'] = mail_reply_to
    if mail_to and len(mail_to) > 0:
        msg['To'] = ", ".join(mail_to)
    if mail_ccs and len(mail_ccs) > 0:
        msg['Cc'] = ", ".join(mail_ccs)
    msg['Subject'] = subject
    msg.attach(MIMEText(mail_body.encode('utf-8'), 'plain', 'utf-8'))
    try:
        _dge_harvest_send_email(msg['From'], (mail_to + mail_ccs), msg)
    except MailerException, e:
        msg = '%r' % e
        log.exception('%s Exception sending email.' % (method_log_prefix))
    finally:
        log.debug('%s End method.' % (method_log_prefix))


def dge_harvest_get_running_harvest_jobs(context, data_dict):
    '''
    Gets running jobs that more than {minutes} minutes ago and send and email
    :param minutes: the number of minutes. 1440 minutes (24 hours) by default.
    :type minutes: int
    '''
    try:
        method_log_prefix = '[%s][dge_harvest_get_running_harvest_jobs]' % __name__
        log.debug('%s Init method. Inputs context=%s, data_dict=%s' % (method_log_prefix, context, data_dict))
        toolkit.check_access('dge_harvest_get_running_harvest_jobs', context, data_dict)

        try:
            minutes = int(data_dict.get('minutes', 1440))
        except Exception:
            minutes = 1440

        if minutes == 1:
            interval_value = '1 minute'
        else:
            interval_value = '%s minutes' % minutes

        model = context['model']
        harvest_job_list = []
        sql = '''select p.name, p.title, hj.id, hj.created, hj.gather_started,
                 hj.gather_finished, hj.finished
                 from harvest_job hj, package p
                 where hj.status like 'Running'
                 and hj.created <= (now() at time zone 'utc' - interval '{interval_value}')
                 and hj.source_id = p.id order by created desc;
                 '''.format(interval_value=interval_value)
        result = model.Session.execute(sql)
        if result:
            for row in result:
                job_id = row[2] if row else None
                if job_id:
                    harvest_job_list.append({'source_name': row[0] if row[0] else '',
                                             'source_title': row[1] if row[1] else '',
                                             'job_id': row[2] if row[2] else '',
                                             'created': row[3] if row[3] else '',
                                             'gather_started': row[4] if row[4] else '',
                                             'gather_finished': row[5] if row[5] else '',
                                             'finished': row[6] if row[6] else ''
                                            })

        if harvest_job_list and len(harvest_job_list) > 0:

            #From
            mail_from = config.get('smtp.mail_from', None)

            #To
            mail_to = config.get('smtp.mail_cc', '').split(' ')

            #Reply-To
            mail_reply_to = config.get('smtp.mail_reply_to', None)

            #Subject
            subject = u'Listado de federaciones en estado Running iniciadas hace m\u00E1s de %s minutos' % minutes

            #Body
            mail_body = ''
            num_job = 0
            for harvest_job in harvest_job_list:
                num_job = num_job + 1
                url_source = config.get('ckan.site_url') + "/harvest/" + harvest_job['source_name']
                url_source = url_source.replace("http://", "https://")
                url_job = config.get('ckan.site_url') + "/harvest/" + harvest_job['source_name'] + "/job/" + harvest_job['job_id'];
                url_job = url_job.replace("http://", "https://")
                mail_body += """\n**%s.- %s: %s (%s)\n\t * %s: %s (%s)\n\t * %s: %s\n\t * %s: %s\n\t * %s: %s\n\t * %s: %s\n\n
                             """ % (num_job, 'SOURCE', harvest_job['source_title'], url_source,
                                    'JOB', harvest_job['job_id'], url_job,
                                    'CREATED', h.render_datetime(harvest_job['created'], with_hours=True),
                                    'GATHER STARTED', h.render_datetime(harvest_job['gather_started'], with_hours=True),
                                    'GATHER FINISHED', h.render_datetime(harvest_job['gather_finished'], with_hours=True),
                                    'FINISHED', h.render_datetime(harvest_job['finished'], with_hours=True))

            mail_body += """\n---\nMessage sent by %s (%s)
                         """ % (config.get('ckan.site_title', 'datos.gob.es'),
                                config.get('ckan.site_url', ''))
            msg = MIMEMultipart()
            if mail_from:
                msg['From'] = mail_from
            if mail_reply_to:
                msg['Reply-To'] = mail_reply_to
            if mail_to and len(mail_to) > 0:
                msg['To'] = ", ".join(mail_to)
            msg['Subject'] = subject
            msg.attach(MIMEText(mail_body.encode('utf-8'), 'plain', 'utf-8'))
            try:
                _dge_harvest_send_email(msg['From'], mail_to, msg)
            except MailerException, e:
                log.exception('%s Exception sending email. %r' % (method_log_prefix, e))
            finally:
                log.debug('%s End method.' % (method_log_prefix))
    except Exception, e:
        log.exception('%s Exception: %r.' % (method_log_prefix, e))
        print ('%s Exception: %r.' % (method_log_prefix, e))
    finally:
        log.debug('%s End method.' % (method_log_prefix))
    return harvest_job_list

############### AUTHORIZATION ###################

@toolkit.auth_allow_anonymous_access
def dge_harvest_auth(context, data_dict):
    '''
    All users can access DCAT endpoints by default
    '''
    return {'success': True}

def dge_harvest_is_sysadmin(context, data_dict):
    '''
        Only sysadmins can do it
    '''
    if not user_is_sysadmin(context):
        return {'success': False, 'msg': 'Only sysadmins can do this operation'}
    else:
        return {'success': True}
