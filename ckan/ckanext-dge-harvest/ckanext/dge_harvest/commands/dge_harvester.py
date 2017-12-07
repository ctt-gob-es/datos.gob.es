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

import sys
import datetime

from pprint import pprint
from dateutil.parser import parse as dateutil_parse

from ckan import model
from ckan.logic import get_action, ValidationError
from ckan.plugins import toolkit
from ckan.lib.cli import CkanCommand

class DgeHarvester(CkanCommand):
    
    '''Harvests remotely mastered metadata

    Usage:

      dge_harvester catalog_rdf [{limit_num_datasets}]
        - create a RDF serialization of the catalog. 
          Create a file specified in config property 'ckanext.dge_harvest.rdf.filepath'
          or in '/tmp/catalog.rdf' if not exists the property.
          A limit number of datastets can be specified in args. All datasets by default.

      dge_harvester catalog_csv [{limit_num_datasets}]
        - create a RDF serialization of the catalog. 
          Create a file specified in config property 'ckanext.dge_harvest.csv.filepath'
          or in '/tmp/catalog.csv' if not exists the property.
          A limit number of datastets can be specified in args. All datasets by default.
          
      dge_harvester clear_old_harvest_jobs [{source-id}]
        - If no source id is given the history for all jobs that have finished over one month ago 
          except the last job by source if it has finished makes more than one month will be cleared.
          Clears the jobs, objects, object_errors and gather_error related to a harvest job.
          If a source id is given, it only clears the history of the harvest source with the given source id.
          The datasets imported from the harvest source will NOT be deleted!!!

     dge_harvester get_running_harvest_jobs [{minutes}]
        - Gets running harvest_jobs that were created more than {minutes} minutes ago
          and send and email

    The commands should be run from the ckanext-dge-harvest directory and expect
    a development.ini file to be present. Most of the time you will
    specify the config explicitly though:

        paster --plugin=ckanext-dge-harvest dge_harvester catalog_rdf [{limit_num_datasets}] -c ../ckan/development.ini
        paster --plugin=ckanext-dge-harvest dge_harvester catalog_csv [{limit_num_datasets}] -c ../ckan/development.ini
        paster --plugin=ckanext-dge-harvest dge_harvester clear_old_harvest_jobs [{source-id}] -c ../ckan/development.ini
        paster --plugin=ckanext-dge-harvest dge_harvester get_running_harvest_jobs {minutes} -c ../ckan/development.ini

    '''

    summary = __doc__.split('\n')[0]
    usage = __doc__
    max_args = 2
    min_args = 0

    def __init__(self,name):

        super(DgeHarvester,self).__init__(name)

    def command(self):
        method_log_prefix = '[%s][command]' % type(self).__name__
        print "%s Init method. Args=%s" % (method_log_prefix, self.args)
        ini = datetime.datetime.now()
        self._load_config()

        # We'll need a sysadmin user to perform most of the actions
        # We will use the sysadmin site user (named as the site_id)
        context = {'model':model,'session':model.Session,'ignore_auth':True}
        self.admin_user = get_action('get_site_user')(context,{})

        if len(self.args) == 0:
            self.parser.print_usage()
            sys.exit(1)
        cmd = self.args[0]
        if cmd == 'catalog_rdf':
            self.generate_catalog('rdf')
        elif cmd == 'catalog_csv':
            self.generate_catalog('csv')
        elif cmd == 'clear_old_harvest_jobs':
            self.clear_old_harvest_jobs()
        elif cmd == 'get_running_harvest_jobs':
            self.get_running_harvest_job()
        else:
            print '%s Command %s not recognized' % (method_log_prefix, cmd)

        end = datetime.datetime.now()
        print '%s End method. ...Command total runned time: %s milliseconds' % (method_log_prefix, int((end - ini).total_seconds() * 1000))

    def _load_config(self):
        super(DgeHarvester, self)._load_config()

    def generate_catalog(self, _format='rdf'):
        method_log_prefix = '[%s][generate_catalog]' % type(self).__name__
        print '%s Init method. Inputs: _format=%s' % (method_log_prefix, _format)
        context = {
                'model':model,
                'session':model.Session,
                'user': self.admin_user['name'],
                'ignore_auth': True,
            }

        if len(self.args) >= 2:
            try:
                _limit = int(float(unicode(self.args[1])))
            except ValueError as e:
                print '%s Please provide the limit of datasets to export' % (method_log_prefix)
                sys.exit(1)
        else:
            _limit = -1

        data_dict = {
            'format': _format,
            'limit': _limit
        }

        catalog = get_action('dge_harvest_catalog_show')(context,data_dict)

        print '%s End method' % (method_log_prefix)

    def clear_old_harvest_jobs(self):
        source_id = None
        if len(self.args) >= 2:
            source_id = unicode(self.args[1])

        context = {
            'model': model,
            'user': self.admin_user['name'],
            'session': model.Session
        }
        if source_id is not None:
            cleared_sources = get_action('dge_harvest_clear_old_harvest_jobs')(context,{'id':source_id})
        else:
            cleared_sources = get_action('dge_harvest_clear_old_harvest_jobs')(context,{})

        if cleared_sources:
            sources = ''
            for item in cleared_sources:
                print 'Cleared job history for harvest source: %s' % item.get('name', item.get('id', ''))
        else:
            print 'Cleared job history for any harvest source'

    def get_running_harvest_job(self):
        method_log_prefix = '[%s][get_running_harvest_job]' % type(self).__name__
        print '%s Init method' % (method_log_prefix)

        minutes = None
        if len(self.args) >= 2:
            try:
                minutes = int(self.args[1])
            except ValueError as e:
                print '%s Please provide a valid value for minutes' % (method_log_prefix)
                sys.exit(1)
        else:
            print '%s Please provide a value for the minutes' % (method_log_prefix)
            sys.exit(1)

        context = {
            'model': model,
            'user': self.admin_user['name'],
            'session': model.Session
        }
        if minutes <= 0:
            print '%s Please provide a valid value for minutes' % (method_log_prefix)
            sys.exit(1)

        harvest_jobs = get_action('dge_harvest_get_running_harvest_jobs')(context,{'minutes':minutes})
        if harvest_jobs:
            for job in harvest_jobs:
                print '''Job with id %s for harvest source %s has been running longer than the configured threshold. 
                         ''' % (job.get('job_id'), job.get('source_name'))
        else:
            print '''No job has been running longer than the configured threshold.'''