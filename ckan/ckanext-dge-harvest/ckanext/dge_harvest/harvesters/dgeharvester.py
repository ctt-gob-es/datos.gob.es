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

import os
import json
import uuid
import logging
import requests

import ckan.plugins as p
import ckan.model as model
import ckan.logic as logic
import ckanext.dge_harvest.constants as dhc

from ckan.lib.base import c
from ckan.logic import ValidationError, NotFound, get_action
from ckan.model import  PACKAGE_NAME_MAX_LENGTH
from ckanext.harvest.model import HarvestObject, HarvestObjectExtra
from ckanext.dcat.harvesters.rdf import DCATRDFHarvester
from ckanext.dcat.processors import RDFParserException
from ckanext.dge_harvest.processors import DGERDFParser
from ckanext.dcat.interfaces import IDCATRDFHarvester
from pylons import config as pc
from ckanext.harvest.logic.auth.update import harvest_sources_reindex
from _sqlite3 import IntegrityError


log = logging.getLogger(__name__)

MAX_NUM = 20

class DGERDFHarvester(DCATRDFHarvester):

    MAX_FILE_SIZE = 1024 * 1024 * 50  # 50 Mb
    CHUNK_SIZE = 1024


    def _get_content_and_type(self, url, harvest_job, page=1, content_type=None):
        '''
        Gets the content and type of the given url.

        :param url: a web url (starting with http) or a local path
        :param harvest_job: the job, used for error reporting
        :param page: adds paging to the url
        :param content_type: will be returned as type
        :return: a tuple containing the content and content-type
        '''
        method_log_prefix = '[%s][_get_content_and_type]' % type(self).__name__

        if not url.lower().startswith('http'):
            # Check local file
            if os.path.exists(url):
                with open(url, 'r') as f:
                    content = f.read()
                content_type = content_type or rdflib.util.guess_format(url)
                return content, content_type
            else:
                msg = u'No se pudo obtener contenido de esta url' #'Could not get content for this url'
                errormsg = dhc.CATALOG_ACCESS_ERROR % (msg)
                if url:
                    errormsg = dhc.CATALOG_ACCESS_ERROR_URL % (url, msg)
                self._save_gather_error(errormsg, harvest_job)
                return None, None

        try:
            if page > 1:
                url = url + '&' if '?' in url else url + '?'
                url = url + 'page={0}'.format(page)


            log.debug('%s Getting file %s' % (method_log_prefix, url))
            
            http_proxy = pc.get(dhc.CKAN_PROP_HTTP_PROXY, None)
            https_proxy = pc.get(dhc.CKAN_PROP_HTTPS_PROXY, None)
            proxies = None
            if http_proxy or https_proxy:
                proxies = {}
                if http_proxy:
                    proxies['http'] = http_proxy
                if https_proxy:
                    proxies['https'] = https_proxy
                log.debug("%s Using proxies %s" % (method_log_prefix, proxies))
            else:
                log.debug("%s No proxies" % (method_log_prefix))

            # first we try a HEAD request which may not be supported
            did_get = False
            r = requests.head(url, proxies=proxies, verify = False)
            if r.status_code == 405 or r.status_code == 400 or r.status_code == 404:
                r = requests.get(url, proxies=proxies, stream=True, verify = False)
                did_get = True
            r.raise_for_status()

            cl = r.headers.get('content-length')
            if cl and int(cl) > self.MAX_FILE_SIZE:
#                 msg = '''Remote file is too big. Allowed
#                     file size: {allowed}, Content-Length: {actual}.'''.format(
#                     allowed=self.MAX_FILE_SIZE, actual=cl)
                msg = u'''El fichero remoto es demasiado grande. Tama\u00F1o 
                de fichero permitido: {allowed], Longitud del contenido: {actual}'''.format(
                    allowed=self.MAX_FILE_SIZE, actual=cl)
                errormsg = dhc.CATALOG_ACCESS_ERROR % (msg)
                if url:
                    errormsg = dhc.CATALOG_ACCESS_ERROR_URL % (url, msg)
                self._save_gather_error(errormsg, harvest_job)
                return None, None

            if not did_get:
                r = requests.get(url, proxies=proxies, stream=True, verify = False)

            length = 0
            content = ''
            for chunk in r.iter_content(chunk_size=self.CHUNK_SIZE):
                content = content + chunk
                length += len(chunk)

                if length >= self.MAX_FILE_SIZE:
                    msg = u'El fichero remoto es demasiado grande'#'Remote file is too big.'
                    errormsg = dhc.CATALOG_ACCESS_ERROR % (msg)
                    if url:
                        errormsg = dhc.CATALOG_ACCESS_ERROR_URL % (url, msg)
                    self._save_gather_error(errormsg, harvest_job)
                    return None, None

            if content_type is None and r.headers.get('content-type'):
                content_type = r.headers.get('content-type').split(";", 1)[0]

            return content, content_type

        except requests.exceptions.HTTPError, error:
            if page > 1 and error.response.status_code == 404:
                # We want to catch these ones later on
                raise

#             msg = 'Could not get content. Server responded with %s %s' % (
#                 error.response.status_code, error.response.reason)
            msg = u'No se pudo obtener contenido. El servidor respondi\u00F3 con %s %s' % (
                 error.response.status_code, error.response.reason)
            errormsg = dhc.CATALOG_ACCESS_ERROR % (msg)
            if url:
                errormsg = dhc.CATALOG_ACCESS_ERROR_URL % (url, msg)
            self._save_gather_error(errormsg, harvest_job)
            return None, None
        except requests.exceptions.ConnectionError, error:
#             msg = '''Could not get content because a
#                                 connection error occurred. %s''' % error
            msg = u'''No se pudo obtener el contenido porque hubo un error de conexi\u00F3n. %s''' % error
            errormsg = dhc.CATALOG_ACCESS_ERROR % (msg)
            if url:
                errormsg = dhc.CATALOG_ACCESS_ERROR_URL % (url, msg)
            self._save_gather_error(errormsg, harvest_job)
            return None, None
        except requests.exceptions.Timeout, error:
            #msg = 'Could not get content because the connection timed out.'
            msg = u'No se ha podido obtener contenido porque el tiempo de conexi\u00F3n se ha agotado'
            errormsg = dhc.CATALOG_ACCESS_ERROR % (msg)
            if url:
                errormsg = dhc.CATALOG_ACCESS_ERROR_URL % (url, msg)
            self._save_gather_error(errormsg, harvest_job)
            return None, None

    def _set_config(self, config_str):
        method_log_prefix = '[%s][_set_config]' % type(self).__name__
        if config_str:
            self.config = json.loads(config_str)
            log.debug('%s Using config: %r' % (method_log_prefix, self.config))
        else:
            self.config = {}

    def info(self):
        return {
            'name': 'dge_rdf',
            'title': 'Generic DGE RDF Harvester',
            'description': 'Harvester for DGE datasets from an RDF graph'
        }

    def validate_config(self, source_config):
        if not source_config:
            return source_config

        try:
            config_obj = json.loads(source_config)
            if  dhc.HS_PROP_DEFULT_CATALOG_LANGUAGE in config_obj:
                default_catalog_language = config_obj.get(dhc.HS_PROP_DEFULT_CATALOG_LANGUAGE)
                locals_offered = pc.get(dhc.CKAN_PROP_LOCALES_OFFERED,'').split()
                if default_catalog_language not in locals_offered:
                    raise ValueError('main_catalog_language must be a value of %s', locals_offered)

            DCATRDFHarvester.validate_config(self, source_config)
        except ValueError, e:
            raise e
        return source_config

    def _get_guid(self, dataset_dict, source_url=None):
        '''
        Try to get a unique identifier for a harvested dataset

        It will be the first found of:
         * Source URL + Dataset name
         * Dataset name
         * URI (rdf:about)
         * dct:identifier

         The last two are obviously not optimal, as depend on title, which
         might change.

         Returns None if no guid could be decided.
        '''
        method_log_prefix = '[%s][_get_guid]' % type(self).__name__
        log.debug('%s Init method' % (method_log_prefix))
        guid = None

        if dataset_dict.get(dhc.DS_URI):
             if dataset_dict.get(dhc.DS_PUBLISHER_ID_MINHAP):
                return dataset_dict.get(dhc.DS_PUBLISHER_ID_MINHAP) + "-" + dataset_dict.get(dhc.DS_URI)
             else:
                return dataset_dict.get(dhc.DS_URI)
            
        if dataset_dict.get(dhc.DS_IDENTIFIER):
            if dataset_dict.get(dhc.DS_PUBLISHER_ID_MINHAP):
                 return dataset_dict.get(dhc.DS_PUBLISHER_ID_MINHAP) + "-" + dataset_dict.get(dhc.DS_IDENTIFIER)
            else:
                return dataset_dict.get(dhc.DS_IDENTIFIER)

        if dataset_dict.get(dhc.DS_NAME):
            guid = dataset_dict[dhc.DS_NAME]
            if source_url:
                guid = source_url.rstrip('/') + '/' + guid

        log.debug('%s End method. Returns guid=%s' % (method_log_prefix, guid))
        return guid

    def gather_stage(self, harvest_job):

        method_log_prefix = '[%s][gather_stage]' % type(self).__name__
        log.debug('%s Init method. Inputs: %s' % (method_log_prefix, harvest_job))
        self._set_config(harvest_job.source.config)

        
        # Get file contents
        url = harvest_job.source.url
        url_text = ''
        if url:
            url_text = url
        log.info('%s Init harvest for harvest_source with url %s' % (method_log_prefix, url_text))

        for harvester in p.PluginImplementations(IDCATRDFHarvester):
            url, before_download_errors = harvester.before_download(url, harvest_job)

            for error_msg in before_download_errors:
                errormsg = dhc.CATALOG_ACCESS_ERROR.format(error_msg)
                if url:
                    errormsg = dhc.CATALOG_ACCESS_ERROR_URL.format(url, error_msg)
                self._save_gather_error(errormsg, harvest_job)

            if not url:
                log.debug('%s End method. Returns: False' % (method_log_prefix))
                return False

        rdf_format = None
        default_catalog_language = None
        if harvest_job.source.config:
            rdf_format = self.config.get(dhc.HS_PROP_RDF_FORMAT, None)
            default_catalog_language = self.config.get(dhc.HS_PROP_DEFULT_CATALOG_LANGUAGE, None)
        content, rdf_format = self._get_content_and_type(url, harvest_job, 1, content_type=rdf_format)

        # TODO: store content?
        for harvester in p.PluginImplementations(IDCATRDFHarvester):
            content, after_download_errors = harvester.after_download(content, harvest_job)

            for error_msg in after_download_errors:
                errormsg = dhc.CATALOG_DOWNLOAD_ERROR % (error_msg)
                if url:
                    errormsg = dhc.CATALOG_DOWNLOAD_ERROR_URL % (url, error_msg)
                self._save_gather_error(errormsg, harvest_job)

        if not content:
            log.debug('%s End method. Returns: False' % (method_log_prefix))
            return False

        try:
            parser = DGERDFParser()
        except RDFParserException, e:
            errormsg = dhc.CATALOG_PARSER_ERROR % (e)
            if url:
                errormsg = dhc.CATALOG_PARSER_ERROR_URL % (url, e)
            self._save_gather_error(errormsg, harvest_job)
            log.debug('%s End method. Returns: False' % (method_log_prefix))
            return False

        try:
            parser.parse(content, _format=rdf_format)
        except RDFParserException, e:
            errormsg = dhc.CATALOG_PARSER_ERROR % (e)
            if url:
                errormsg = dhc.CATALOG_PARSER_ERROR_URL % (url, e)
            self._save_gather_error(errormsg, harvest_job)
            log.debug('%s End method. Returns: False' % (method_log_prefix))
            return False
        except Exception as e:
            errormsg = dhc.CATALOG_PARSER_ERROR % (e)
            if url:
                errormsg = dhc.CATALOG_PARSER_ERROR_URL % (url, e)
            self._save_gather_error(errormsg, harvest_job)
            log.debug('%s End method. Returns: False' % (method_log_prefix))
            return False

        guids_in_source = []
        object_ids = []

        catalog_errors = 0
        catalog_warnings = 0

        try:
            for catalog in parser.catalogs():
                catalog_errors = catalog[dhc.CAT_ERRORS]
                catalog_warnings = catalog[dhc.CAT_WARNINGS]
                
                #get owner_org of harvest_job
                owner_org_catalog = None
                source_catalog = model.Package.get(harvest_job.source.id)
                if source_catalog.owner_org:
                    owner_org_catalog = source_catalog.owner_org 

                #check if catalog_publisher is harvest_source_org
                if catalog.get(dhc.CAT_PUBLISHER) and\
                    catalog.get(dhc.CAT_PUBLISHER) != owner_org_catalog:
                        if not catalog_errors:
                            catalog_errors = []
                        errormsg = dhc.UNEXPECTED_PUBLISHER_CATALOG_OWNER_SOURCE
                        log.info("%s Adding catalog error %s" % (method_log_prefix, errormsg))
                        catalog_errors.append(errormsg)

                total_catalog_errors = len(catalog_errors) if catalog_errors else 0
                total_catalog_warnings = len(catalog_warnings) if catalog_warnings else 0


                if catalog_warnings and len(catalog_warnings) > 0:
                    num = 0
                    for catalog_warning in catalog_warnings:
                        num = num + 1
                        if (num <= MAX_NUM):
                            warnmsg = dhc.CATALOG_VALIDATION_WARNING % (catalog_warning)
                            if url:
                                warnmsg = dhc.CATALOG_VALIDATION_WARNING_URL % (url, catalog_warning)
                            log.info("%s Saving gather_error - %s %s" % (method_log_prefix, warnmsg, harvest_job))
                            self._save_gather_error(warnmsg, harvest_job)

                if catalog_errors and len(catalog_errors) > 0:
                    num = 0
                    for catalog_error in catalog_errors:
                        num = num + 1
                        if (num <= MAX_NUM):
                            errormsg = dhc.CATALOG_VALIDATION_ERRORS % (catalog_error)
                            if url: 
                                errormsg = dhc.CATALOG_VALIDATION_ERRORS_URL % (url, catalog_error)
                            log.info("%s Saving gather_error - %s %s" % (method_log_prefix, errormsg, harvest_job))
                            self._save_gather_error(errormsg, harvest_job)
                    #Summary
                    summarymsg = dhc.LOG_CATALOG_ERROR_SUMMARY % (total_catalog_warnings, total_catalog_errors)
                    log.info("%s %s" % (method_log_prefix, summarymsg))
                    log.debug('%s End method. Returns: False' % (method_log_prefix))
                    return False
                else:
                    error_dataset_identifier = ""
                    total_datasets = 0
                    total_error_datasets = 0
                    total_errors = 0
                    total_warnings = 0
                    try:
                        dict = {}
                        dict[dhc.CAT_LANGUAGE] = catalog[dhc.CAT_LANGUAGE]
                        dict[dhc.DS_DEFAULT_CATALOG_LANGUAGE] = default_catalog_language
                        dict[dhc.CAT_THEME_TAXONOMY] = catalog[dhc.CAT_THEME_TAXONOMY]
                        dict[dhc.CAT_URI] = catalog[dhc.CAT_URI]
                        dict[dhc.CAT_AVAILABLE_DATA] = catalog[dhc.CAT_AVAILABLE_DATA]

                        for dataset in parser.datasets(dict):
                            total_datasets = total_datasets + 1

                            # Unless already set by the parser, get the owner organization (if any)
                            # from the harvest source dataset
                            if not dataset.get(dhc.DS_OWNER_ORG):
                                if owner_org_catalog:
                                    dataset[dhc.DS_OWNER_ORG] = owner_org_catalog

                            if not dataset.get(dhc.DS_NAME) \
                                and dataset.get(dhc.DS_TITLE) \
                                and dataset.get(dhc.DS_PUBLISHER_ID_MINHAP):
                                dataset[dhc.DS_NAME] = self._gen_new_name(dataset.get(dhc.DS_PUBLISHER_ID_MINHAP, '') + '-' + dataset.get(dhc.DS_TITLE, ''))

                            # Try to get a unique identifier for the harvested dataset
                            guid = self._get_guid(dataset)

                            if not guid:
                                log.error('%s Could not get a unique identifier for dataset: %s' % (method_log_prefix, dataset))
                                continue

                            dataset[dhc.DS_EXTRAS].append({'key': 'guid', 'value': guid})
                            guids_in_source.append(guid)

                            errors = dataset[dhc.DS_ERRORS]
                            warnings = dataset[dhc.DS_WARNINGS]
                            #delete unnecesary info
                            del dataset[dhc.DS_ERRORS]
                            del dataset[dhc.DS_WARNINGS]

                            if guid or dataset.get(dhc.DS_NAME): 
                                error_dataset_identifier = guid if guid else dataset.get(dhc.DS_NAME)

                            if errors and len(errors) > 0:
                                total_errors = total_errors + len(errors)
                                log.debug("%s errors number=%s" % (method_log_prefix, len(errors)))
                            if warnings and len(warnings) > 0:
                                total_warnings = total_warnings + len(warnings)
                                log.debug("%s warnings number=%s" % (method_log_prefix, len(warnings)))

                            if errors and len(errors) > 0:
                                obj = HarvestObject(guid=guid, job=harvest_job, state='ERROR',
                                                content=json.dumps(dataset))
                                obj.save()
                                #object_ids.append(obj.id)
                                total_error_datasets = total_error_datasets + 1
                                num = 0
                                for error in errors:
                                    num = num + 1
                                    if (num <= MAX_NUM):
                                        log.info("%s Saving objectError %s for guid %s" % (method_log_prefix, error, guid))
                                        errormessage = dhc.DATASET_VALIDATION_ERROR % (error)
                                        self._save_object_error(errormessage, obj, 'Gather')
                            else:
                                obj = HarvestObject(guid=guid, job=harvest_job, 
                                                content=json.dumps(dataset), )

                                obj.save()
                                object_ids.append(obj.id)

                            if warnings and len(warnings) > 0:
                                num = 0
                                for warn in warnings:
                                    num = num + 1
                                    if (num <= MAX_NUM):
                                        log.info("%s Saving warning in objectError %r for guid %r" % (method_log_prefix, warn, guid))
                                        warnmessage = dhc.DATASET_VALIDATION_WARNING % (warn)
                                        self._save_object_error(warnmessage, obj, 'Gather')

                        #Summary
                        summarymsg = dhc.LOG_SUMMARY % (total_catalog_warnings, total_datasets, total_error_datasets, total_errors, total_warnings)
                        log.info("%s %s" % (method_log_prefix, summarymsg))
                    except RDFParserException, e:
                        errormsg = dhc.DATASET_VALIDATION_ERROR % (type(e).__name__, e)
                        log.info("%s Saving gather_error - %s" % (method_log_prefix, errormsg))
                        self._save_gather_error(errormsg, harvest_job)
                        #Summary
                        summarymsg = dhc.LOG_SUMMARY % (total_catalog_warnings, total_datasets, (total_error_datasets+1), total_errors, total_warnings)
                        log.info("%s %s" % (method_log_prefix, summarymsg))
                        log.debug('%s End method. Returns: False' % (method_log_prefix))
                        return False
        except RDFParserException, e:
            errormsg = dhc.CATALOG_VALIDATION_ERROR % (type(e).__name__, e)
            if url:
                errormsg = dhc.CATALOG_VALIDATION_ERROR_URL % (url, type(e).__name__, e)
            log.info("%s Saving gather_error - %s" % (method_log_prefix, errormsg))
            self._save_gather_error(errormsg, harvest_job)
            #Summary
            summarymsg = dhc.LOG_CATALOG_ERROR_SUMMARY % (total_catalog_warnings, (total_catalog_errors + 1))
            log.info("%s %s" % (method_log_prefix, summarymsg))
            log.debug('%s End method. Returns: False' % (method_log_prefix))
            return False
        # Check if some datasets need to be deleted
        object_ids_to_delete = self._mark_datasets_for_deletion(guids_in_source, harvest_job)

        object_ids.extend(object_ids_to_delete)
        log.debug('%s End method. Returns: %s' % (method_log_prefix, object_ids))
        return object_ids

    def fetch_stage(self, harvest_object):
        # Nothing to do here
        return True

    def import_stage(self, harvest_object):
        method_log_prefix = '[%s][import_stage]' % type(self).__name__
        
        log.debug('%s Init method. Inputs: %s' % (method_log_prefix, harvest_object))
        harvest_object_id = ''
        harvest_object_guid = ''
        try:
            harvest_object_id = harvest_object.id
            harvest_object_guid = harvest_object.guid
            status = self._get_object_extra(harvest_object, 'status')
            if status == 'delete':
                # Delete package
                context = {'model': model, 'session': model.Session,
                           'user': self._get_user_name(), 'ignore_auth': True}

                p.toolkit.get_action('package_delete')(context, {'id': harvest_object.package_id})
                log.info('%s Deleted package %s with guid %s' % (method_log_prefix, harvest_object.package_id,
                                                                    harvest_object.guid))
                return True

            if harvest_object.content is None:
                error = 'Empty content for object {0}'.format(harvest_object.id)
                log.info("%s Saving objectError %s for harvest_object_guid %s" % (method_log_prefix, error, harvest_object_guid))
                self._save_object_error(dhc.DATASET_IMPORT_ERROR % error, harvest_object, 'Import')
                return False

            try:
                dataset = json.loads(harvest_object.content)
            except ValueError:
                error = 'Could not parse content for object {0}'.format(harvest_object.id)
                log.info("%s Saving objectError %s for harvest_object_guid %s" % (method_log_prefix, error, harvest_object_guid))
                self._save_object_error(dhc.DATASET_IMPORT_ERROR % error, harvest_object, 'Import')
                return False

            # Get the last harvested object (if any)
            previous_object = model.Session.query(HarvestObject) \
                                           .filter(HarvestObject.guid==harvest_object.guid) \
                                           .filter(HarvestObject.current==True) \
                                           .first()

            # Flag previous object as not current anymore
            if previous_object:
                previous_object.current = False
                previous_object.add()

            # Flag this object as the current one
            harvest_object.current = True
            harvest_object.add()

            context = {
                'user': self._get_user_name(),
                'return_id_only': True,
                'ignore_auth': True,
            }

            # Check if a dataset with the same guid exists
            existing_dataset = self._get_existing_dataset(harvest_object.guid)

            if existing_dataset:
                # Don't change the dataset name even if the title has
                dataset[dhc.DS_NAME] = existing_dataset[dhc.DS_NAME]
                dataset[dhc.DS_ID] = existing_dataset[dhc.DS_ID]

                # Save reference to the package on the object
                harvest_object.package_id = dataset[dhc.DS_ID]
                harvest_object.add()

                try:
                    p.toolkit.get_action('package_update')(context, dataset)
                except p.toolkit.ValidationError, e:
                    error = dhc.DATASET_IMPORT_ERROR % (str(e.error_summary))
                    log.debug("%s Saving objectError %s for harvest_object_guid %s" % (method_log_prefix, error, harvest_object_guid))
                    self._save_object_error(error, harvest_object, 'Import')
                    return False

                log.info('%s Updated dataset %s' % (method_log_prefix, dataset.get(dhc.DS_NAME)))

            else:

                package_schema = logic.schema.default_create_package_schema()
                context['schema'] = package_schema

                # We need to explicitly provide a package ID
                dataset[dhc.DS_ID] = unicode(uuid.uuid4())
                package_schema['id'] = [unicode]

                # Save reference to the package on the object
                harvest_object.package_id = dataset[dhc.DS_ID]
                harvest_object.add()

                # Defer constraints and flush so the dataset can be indexed with
                # the harvest object id (on the after_show hook from the harvester
                # plugin)
                model.Session.execute('SET CONSTRAINTS harvest_object_package_id_fkey DEFERRED')
                model.Session.flush()

                try:
                    p.toolkit.get_action('package_create')(context, dataset)
                except p.toolkit.ValidationError, e:
                    error = dhc.DATASET_IMPORT_ERROR % str(e.error_summary)
                    log.info("%s Saving objectError %s for harvest_object_guid %s" % (method_log_prefix, error, harvest_object_guid))
                    self._save_object_error(error, harvest_object, 'Import')
                    return False

                log.info('%s Created dataset %s' % (method_log_prefix, dataset.get(dhc.DS_NAME)))
            model.Session.commit()
        except Exception as e:
            errormsg = '%s' % e
            try:
                errormsg ="Exception in harvest_object %s (%s) %s: %s" % (harvest_object_guid, harvest_object_id , type(e).__name__, e)
                log.error("%s %s" % (method_log_prefix, errormsg))
                if 'IntegrityError' == type(e).__name__:
                    errormsg = dhc.DATASET_INTEGRITY_ERROR
                self._save_object_error(dhc.DATASET_IMPORT_ERROR % errormsg, harvest_object, 'Import')
            except Exception as ex:
                log.error("%s Exception %r. %r" % (method_log_prefix, type(ex), ex))
                harvest_object.package_id = None
                self._save_object_error(dhc.DATASET_IMPORT_ERROR % errormsg, harvest_object, 'Import')
            return False
        log.debug('%s End method. Returns: True' % (method_log_prefix))
        return True

