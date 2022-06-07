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

import re
import sys
import traceback
from datetime import datetime

from ckan import model
from ckan.lib.cli import CkanCommand
from ckan.logic import get_action


class DgeDashboardInitDBCommand(CkanCommand):
    '''Usage:
    dge_dashboard_init_db [paster --plugin=ckanext-dge-dashboard dge_dashboard_initdb_command -c /etc/ckan/default/production.ini]
        - Creates the necessary tables in the database and complete them with historical data
    '''

    summary = __doc__.split('\n')[0]
    usage = __doc__
    max_args = 0
    min_args = 0
    datetime_format = '%d/%m/%Y %H:%M:%S.%f'

    def __init__(self, name):
        super(DgeDashboardInitDBCommand, self).__init__(name)

    def _load_config(self):
        super(DgeDashboardInitDBCommand, self)._load_config()

    def command(self):
        init = datetime.now()
        s_args = (self.args if self.args else '(no args)')
        print '[%s] - Init DgeDashboardInitDBCommand command with args: %s.' % (
            init.strftime(DgeDashboardInitDBCommand.datetime_format), s_args)
        try:
            self._load_config()
            # We'll need a sysadmin user to perform most of the actions
            # We will use the sysadmin site user (named as the site_id)
            context = {'model': model, 'session': model.Session, 'ignore_auth': True}
            self.admin_user = get_action('get_site_user')(context, {})
            model.Session.remove()
            model.Session.configure(bind=model.meta.engine)
            from ckanext.dge_dashboard.model import setup as db_setup
            db_setup()
            print 'DB tables created'
        except Exception as e:
            print 'Exception %s' % e
            sys.exit(1)
        finally:
            end = datetime.now()
            print '[%s] - End DgeDashboardInitDBCommand command with args %s. Executed command in %s milliseconds.' % (
                end.strftime(DgeDashboardInitDBCommand.datetime_format), s_args, (end - init).total_seconds() * 1000)
        sys.exit(0)


class DgeDashboardLoadCommand(CkanCommand):
    ''' Save data to the database dga_dashboard tables
    Usage:

    dge_dashboard_load published_datasets [paster --plugin=ckanext-dge-dashboard dge_dashboard_load published_datasets {save|print} {latest|YYYY-MM|last_month} -c /etc/ckan/default/production.ini]
        - Updates dge_dashboard_published_datasets table with public and active datasets created until and during the given month. Params:
          - {save|print}: save if save data in database; print if only print data, not save in database
          - {lastest|YYYY-MM|last_month}: just data for...
                 actual month if None
                 specific month if YYYY-MM
                 last month if last_month


    dge_dashboard_load published_datasets_by_num_resources [paster --plugin=ckanext-dge-dashboard dge_dashboard_load published_datasets_by_num_resources {save|print} {latest|YYYY-MM|last_month} -c /etc/ckan/default/production.ini]
        - Updates update_published_datasets_by_num_resources table with public and active datasets created until and during the given month. Params
          - {save|print}: save if save data in database; print if only print data, not save in database
          - {latest|YYYY-MM|last_month}: just data for...
                 actual month if None
                 specific month if YYYY-MM
                 last month if last_month


    dge_dashboard_load publishers [paster --plugin=ckanext-dge-dashboard dge_dashboard_load publishers {save|print} {latest|YYYY-MM|last_month} -c /etc/ckan/default/production.ini]
        - Updates dge_dashboard_publishers table with num harvester publishers and manual loadings publishers than
          have published datasets until and during the given month. Params:
          - {latest|save|print}: save if save data in database; print if only print data, not save in database
          - {latest|YYYY-MM|last_month}: just data for...
                 actual month if None
                 specific month if YYYY-MM
                 last month if last_month


    dge_dashboard_load drupal_published_contents [paster --plugin=ckanext-dge-dashboard dge_dashboard_load drupal_published_contents {save|print} {latest|YYYY-MM|last_month} -c /etc/ckan/default/production.ini]
        - Updates update_drupal_published_contents table with drupal contents created until and during the given month. Params:
          - {save|print}: save if save data in database; print if only print data, not save in database
          - {latest|YYYY-MM|last_month}: just data for...
                 actual month if None
                 specific month if YYYY-MM
                 last month if last_month


    dge_dashboard_load drupal_comments [paster --plugin=ckanext-dge-dashboard dge_dashboard_load drupal_comments {save|print} {latest|YYYY-MM|last_month} -c /etc/ckan/default/production.ini]
        - Updates update_drupal_published_contents table with drupal comments created until and during the given month. Params:
          - {save|print}: save if save data in database; print if only print data, not save in database
          - {latest|YYYY-MM|last_month}: 
                latest      - (default) just data for the current month
                YYYY-MM     - just data for the specific month
                last_month  - just data for the last month
          
    '''

    summary = __doc__.split('\n')[0]
    usage = __doc__
    max_args = 3
    min_args = 0
    datetime_format = '%d/%m/%Y %H:%M:%S.%f'

    def __init__(self, name):
        super(DgeDashboardLoadCommand, self).__init__(name)

    def command(self):
        init = datetime.now()
        s_args = (self.args if self.args else '(no args)')
        print '[%s] - Init DgeDashboardLoadCommand command with args: %s.' % (
            init.strftime(DgeDashboardLoadCommand.datetime_format), s_args)
        try:
            self._load_config()

            # We'll need a sysadmin user to perform most of the actions
            # We will use the sysadmin site user (named as the site_id)
            context = {'model': model, 'session': model.Session, 'ignore_auth': True}
            self.admin_user = get_action('get_site_user')(context, {})
            if len(self.args) == 0 or len(self.args) > 3:
                self.parser.print_usage()
                sys.exit(1)
            cmd = self.args[0]
            if cmd == 'published_datasets':
                self.published_datasets(num_resources=False)
            elif cmd == 'published_datasets_by_num_resources':
                self.published_datasets(num_resources=True)
            elif cmd == 'publishers':
                self.publishers()
            elif cmd == 'drupal_published_contents':
                self.drupal_published_contents()
            elif cmd == 'drupal_comments':
                self.drupal_comments()
            else:
                print 'Command %s not recognized' % cmd
        except Exception as e:
            print 'Exception %s' % (e)
            print traceback.print_exc()
            sys.exit(1)
        finally:
            end = datetime.now()
            print '[%s] - End DgeDashboardLoadCommand command with args %s. Executed command in %s milliseconds.' % (
                end.strftime(DgeDashboardLoadCommand.datetime_format), s_args, (end - init).total_seconds() * 1000)
        sys.exit(0)

    def _load_config(self):
        super(DgeDashboardLoadCommand, self)._load_config()

    def _validate_args(self, method_log_prefix=''):
        for_date = None
        save = False
        time_period = None
        if len(self.args) == 3:
            dtype = self.args[1]
            if dtype != 'save' and dtype != 'print':
                print '%s Please provide a valid type (save or print)' % (method_log_prefix)
                sys.exit()
            else:
                if dtype == 'save':
                    save = True

            time_period = self.args[2]
            if time_period == 'latest':
                time_period = datetime.now().strftime("%Y-%m")
            elif time_period == 'last_month':
                now = datetime.now()
                if now.month == 1:
                    last_month = datetime(now.year - 1, 12, 1, 0, 0, 0)
                else:
                    last_month = datetime(now.year, now.month - 1, 1, 0, 0, 0)
                time_period = last_month.strftime("%Y-%m")

            try:
                for_date = datetime.strptime(time_period, '%Y-%m')
            except ValueError as e:
                print '%s Please provide a valid second param (latest|YYYY-MM|last_month)' % (method_log_prefix)
                sys.exit(1)

            if for_date:
                year = for_date.year
                month = for_date.month
            if month == 12:
                calculation_date = datetime(year + 1, 1, 1, 0, 0, 0)
            else:
                calculation_date = datetime(year, month + 1, 1, 0, 0, 0)
            return save, time_period, calculation_date
        else:
            print '%s Please provide valid params {print|save} {latest|YYYY-MM|last_month}' % (method_log_prefix)
            sys.exit(1)

    def _set_context(self):
        return {
            'model': model,
            'session': model.Session,
            'user': self.admin_user['name'],
            'ignore_auth': True,
        }

    def published_datasets(self, num_resources=False):
        method_log_prefix = '[%s][published_datasets]' % (type(self).__name__)
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        save, time_period, calculation_date = self._validate_args(method_log_prefix)
        get_action('dge_dashboard_update_published_datasets')(context, {'date': str(calculation_date),
                                                                        'import_date': time_period,
                                                                        'num_resources': num_resources, 'save': save})
        if save:
            print 'Updated dge_dashboard_published_datasets table with data of %s' % time_period
        print '%s End method.' % (method_log_prefix)
        sys.exit(0)

    def publishers(self):
        method_log_prefix = '[%s][publishers]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        save, time_period, calculation_date = self._validate_args(method_log_prefix)
        get_action('dge_dashboard_update_publishers')(context,
                                                      {'date': str(calculation_date), 'import_date': time_period,
                                                       'save': save})
        if save:
            print 'Updated dge_dashboard_publishers table with data of %s' % time_period

        print '%s End method' % (method_log_prefix)

    def drupal_published_contents(self, num_resources=False):
        method_log_prefix = '[%s][drupal_published_contents]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        save, time_period, calculation_date = self._validate_args(method_log_prefix)
        get_action('dge_dashboard_update_drupal_published_contents')(context,
                                                                     {'date': calculation_date.strftime("%Y/%m/%d"),
                                                                      'import_date': time_period, 'save': save})
        if save:
            print 'Updated dge_dashboard_update_drupal_published_contents table with data of %s' % time_period
        print '%s End method' % (method_log_prefix)

    def drupal_comments(self):
        method_log_prefix = '[%s][drupal_comments]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        save, time_period, calculation_date = self._validate_args(method_log_prefix)
        get_action('dge_dashboard_update_drupal_comments')(context, {'date': calculation_date.strftime("%Y/%m/%d"),
                                                                     'import_date': time_period, 'save': save})
        if save:
            print 'Updated dge_dashboard_drupal_contents table with data of %s' % time_period
        print '%s End method' % (method_log_prefix)


class DgeDashboardJsonCommand(CkanCommand):
    ''' Command that generates json from the database files tables data 
    Usage:

    dge_dashboard_json published_datasets [paster --plugin=ckanext-dge-dashboard dge_dashboard_json published_datasets total|all|org|adm_level|num_res {destination} {prefix} -c /etc/ckan/default/production.ini]
        - Write json files with dge_dashboard_published_datasets table data. Params:
          - total|all|org|adm_level|num_res: If total, only total data; 
                                             if all, all data; 
                                             if org, organizations data;
                                             if adm_level, administration_level data;
                                             if num_res, num_resources;
          - {destination}: Destination directory of files
          - {prefix}: Prefix of filename. The filename will be {prefix}_{value of param1}.json

    dge_dashboard_json current_published_datasets_by_administration_level [paster --plugin=ckanext-dge-dashboard dge_dashboard_json current_published_datasets_by_administration_level {destination} {filename} -c /etc/ckan/default/production.ini]
        Write a json file with number of published datasets by administration level at this moment. Params:
         - {destination}: Destination directory of files
         - {filename}: The complete filename will be {filename}.json

    dge_dashboard_json current_distribution_format [paster --plugin=ckanext-dge-dashboard dge_dashboard_json current_distribution_format {[total|adm_level]} {destination} {filename} -c /etc/ckan/default/production.ini]
        Write a json file with number of distribution format global and by administration level at this moment. Params:
         - {total|adm_level|org}: total if total values, adm_level if values by administration level, org if values by organization
         - {destination}: Destination directory of files
         - {prefix}: Prefix of filename. The filename will be {prefix}_{value of param1}.json

    dge_dashboard_json current_published_datasets_by_category [paster --plugin=ckanext-dge-dashboard dge_dashboard_json current_published_datasets_by_category {destination} {filename} -c /etc/ckan/default/production.ini]
        Write a json file with number of published datasets by category at this moment. Params:
         - {destination}: Destination directory of files
         - {filename}: The complete filename will be {filename}.json

    dge_dashboard_json publishers [paster --plugin=ckanext-dge-dashboard dge_dashboard_json publishers {destination} {prefix} -c /etc/ckan/default/production.ini]
        - Write json files with dge_dashboard_publishers table data. Params:
          - {destination}: Destination directory of files
          - {filename}: The complete filename will be {filename}.json

    dge_dashboard_json current_publishers_by_administration_level [paster --plugin=ckanext-dge-dashboard dge_dashboard_json current_publishers_by_administration_level {destination} {prefix} -c /etc/ckan/default/production.ini]
        - Write json files with dge_dashboard_publishers by administration level in two groups, harvester publishers and manual loading publishers. Params:
          - {destination}: Destination directory of files
          - {filename}: The complete filename will be {filename}.json

    dge_dashboard_json drupal_published_datasets [paster --plugin=ckanext-dge-dashboard dge_dashboard_json drupal_published_content {total|org} {comments|no_comments} {destination} {prefix} -c /etc/ckan/default/production.ini]
        - Write json files with dge_dashboard_published_datasets table data. Params:
          - contents|comments|org_comments: If contents, only total data of app, intitatives, requests and success type contents; 
                                            if comments, total comments;
                                            if org_comments, organization comments;
          - {destination}: Destination directory of files
          - {prefix}: Prefix of filename. The filename will be {prefix}_{value of param1}.json

    dge_dashboard_json current_drupal_published_contents [paster --plugin=ckanext-dge-dashboard dge_dashboard_json current_drupal_published_contents {destination} {filename} -c /etc/ckan/default/production.ini]
        - Write json files with num of drupal published contents by content type. Params:
          - {destination}: Destination directory of files
          - {filename}: The complete filename will be {filename}.json

    dge_dashboard_json current_users [paster --plugin=ckanext-dge-dashboard dge_dashboard_json current_users_by_org {org|adm_level} {destination} {prefix} -c /etc/ckan/default/production.ini]
        - Write json files with active users .Params:
          - {org|adm_level|num_org}: org if active users users by organization plus usernames;
                                     num_org if number of active users by organization
                                     adm_level if active users by administration level;
          - {destination}: Destination directory of files
          - {filename}: The complete filename will be {filename}.json

    dge_dashboard_json current_assigned_request_by_state [paster --plugin=ckanext-dge-dashboard dge_dashboard_json current_assigned_request_by_state {total|org} {destination} {prefix} -c /etc/ckan/default/production.ini]
        Write a json file with number of assigned request by state at this moment. Params:
         - {total|org}: total if total values, org if values by organization
         - {destination}: Destination directory of files
         - {prefix}: Prefix of filename. The filename will be {prefix}_{value of param2}.json

    dge_dashboard_json visits [paster --plugin=ckanext-dge-dashboard dge_dashboard_json visits {destination} {filename} -c /etc/ckan/default/production.ini]
        - Write json files with visits to datos.gob.es. Params:
          - {destination}: Destination directory of files
          - {filename}: The complete filename will be {filename}.json

    dge_dashboard_json visits_by_section [paster --plugin=ckanext-dge-dashboard dge_dashboard_json visits_by_section {destination} {filename} -c /etc/ckan/default/production.ini]
        - Write json files with visits to datos.gob.es. Params:
          - {destination}: Destination directory of files
          - {filename}: The complete filename will be {filename}.json

    dge_dashboard_json visits [paster --plugin=ckanext-dge-dashboard dge_dashboard_json visits {total|section} {destination} {prefix} -c /etc/ckan/default/production.ini]
        Write a json file with number of visits to portal totals or by sections. Params:
         - {total|section}: total if total values, section if values by section
         - {destination}: Destination directory of files
         - {prefix}: Prefix of filename. The filename will be {prefix}_{value of param1}.json

    dge_dashboard_json visited_datasets [paster --plugin=ckanext-dge-dashboard dge_dashboard_json visited_datasets {total|org} {destination} {prefix} -c /etc/ckan/default/production.ini]
        Write a json file with the most visited datasets. Params:
         - {total|org}: total if total values, org if values by organization
         - {destination}: Destination directory of files
         - {prefix}: Prefix of filename. The filename will be {prefix}_{value of param1}.json

    dge_dashboard_json organization_by_administration_level [paster --plugin=ckanext-dge-dashboard dge_dashboard_json organization_by_administration_level {destination} {filename} -c /etc/ckan/default/production.ini]
        Write a json file with the most visited datasets. Params:
         - {destination}: Destination directory of files
         - {filename}: The complete filename will be {filename}.json
         
    dge_dashboard_json dge_dashboard_json_organization_name [paster --plugin=ckanext-dge-dashboard dge_dashboard_json organization_name {destination} {filename} -c /etc/ckan/default/production.ini]
        Write a json file with the most visited datasets. Params:
         - {destination}: Destination directory of files
         - {filename}: The complete filename will be {filename}.json

    '''

    PUBLISHED_DATASETS_TYPES = ['total', 'all', 'adm_level', 'org', 'num_res']
    DISTRIBUTION_FORMAT_TYPES = ['total', 'adm_level', 'org']
    DRUPAL_PUBLISHED_CONTENTS = ['contents', 'comments', 'org_comments']
    USERS_TYPES = ['org', 'adm_level', 'num_org']
    REQUEST_TYPES = ['total', 'org']
    VISIT_TYPES = ['total', 'section']
    COMMENTS_TYPES = ['total', 'org']
    VISITED_DATASET_TYPES = ['total', 'org']

    FILENAME_REGEX = '^[a-zA-Z0-9][a-zA-Z0-9_-]+[a-zA-Z0-9]$'

    summary = __doc__.split('\n')[0]
    usage = __doc__
    max_args = 4
    min_args = 3
    datetime_format = '%d/%m/%Y %H:%M:%S.%f'

    def __init__(self, name):
        super(DgeDashboardJsonCommand, self).__init__(name)

    def command(self):
        init = datetime.now()
        s_args = (self.args if self.args else '(no args)')
        print '[%s] - Init DgeDashboardJsonCommand command with args: %s.' % (
            init.strftime(DgeDashboardJsonCommand.datetime_format), s_args)
        try:
            self._load_config()
            # We'll need a sysadmin user to perform most of the actions
            # We will use the sysadmin site user (named as the site_id)
            context = {'model': model, 'session': model.Session, 'ignore_auth': True}
            self.admin_user = get_action('get_site_user')(context, {})
            if len(self.args) == 0 or len(self.args) > 4:
                self.parser.print_usage()
                sys.exit(1)
            cmd = self.args[0]
            if cmd == 'published_datasets':
                self.published_datasets()
            elif cmd == 'current_published_datasets_by_administration_level':
                self.current_published_datasets_by_administration_level()
            elif cmd == 'current_distribution_format':
                self.current_distribution_format()
            elif cmd == 'current_published_datasets_by_category':
                self.current_published_datasets_by_category()
            elif cmd == 'publishers':
                self.publishers()
            elif cmd == 'current_publishers_by_administration_level':
                self.current_publishers_by_administration_level()
            elif cmd == 'drupal_published_contents':
                self.drupal_published_contents()
            elif cmd == 'current_drupal_published_contents':
                self.current_drupal_published_contents()
            elif cmd == 'current_users':
                self.current_users()
            elif cmd == 'current_assigned_request_by_state':
                self.current_assigned_request_by_state()
            elif cmd == 'visits':
                self.visits()
            elif cmd == 'visited_datasets':
                self.visited_datasets()
            elif cmd == 'organization_by_administration_level':
                self.organization_by_administration_level()
            elif cmd == 'organization_name':
                self.organization_name()
            elif cmd == 'content_by_likes':
                self.current_drupal_content_by_likes()
            elif cmd == 'top10_voted_dataset':
                self.current_drupal_top10_voted_datasets()
            else:
                print 'Command %s not recognized' % cmd
        except Exception as e:
            print 'Exception: %s \n%s\n' % (e, traceback.format_exc())
            sys.exit(1)
        finally:
            end = datetime.now()
            print '[%s] - End DgeDashboardJsonCommand command with args %s. Executed command in %s milliseconds.' % (
                end.strftime(DgeDashboardJsonCommand.datetime_format), s_args, (end - init).total_seconds() * 1000)
        sys.exit(0)

    def _load_config(self):
        super(DgeDashboardJsonCommand, self)._load_config()

    def _validate_destination_filename(self, destination, filename, is_prefix=False, method_log_prefix=''):
        if destination is None or len(destination) == 0 or len(destination.strip(' \t\n\r')) == 0:
            print '%s Please provide a destination' % (method_log_prefix)
            sys.exit(1)
        else:
            destination = destination.strip(' \t\n\r')
        name = 'destination' if is_prefix else 'prefix'
        if filename is None or len(filename) == 0 or len(filename.strip(' \t\n\r')) == 0:
            print '%s Please provide a %s' % (method_log_prefix, name)
            sys.exit(1)
        else:
            filename = filename.strip(' \t\n\r')
            pattern = re.compile(self.FILENAME_REGEX)
            if not pattern.match(filename):
                print '%s Please provide a valid %s. Regular expression: %s' % (method_log_prefix, name, filename_regex)
        return destination, filename

    def _set_context(self):
        return {
            'model': model,
            'session': model.Session,
            'user': self.admin_user['name'],
            'ignore_auth': True,
        }

    def published_datasets(self):
        method_log_prefix = '[%s][published_datasets]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        types = self.PUBLISHED_DATASETS_TYPES
        if len(self.args) == 4:
            dtype = self.args[1]
            destination = self.args[2]
            prefix = self.args[3]
            if dtype not in types:
                print '%s Please provide a valid type %s' % (method_log_prefix, types)
                sys.exit()
            destination, prefix = self._validate_destination_filename(destination, prefix, True, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_published_datasets')(context, {'what': dtype,
                                                                                        'destination': destination,
                                                                                        'prefix': prefix})
            if outfilename:
                print 'Writed json with %s data in %s' % (dtype, outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: %s {destination} {prefix}' % (method_log_prefix, types)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)

    def current_published_datasets_by_administration_level(self):
        method_log_prefix = '[%s][current_published_datasets_by_administration_level]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        if len(self.args) == 3:
            destination = self.args[1]
            filename = self.args[2]
            destination, filename = self._validate_destination_filename(destination, filename, False, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_current_published_datasets_by_administration_level')(context, {
                'destination': destination, 'filename': filename})
            if outfilename:
                print 'Writed json in %s' % (outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: {destination} {filename}' % (method_log_prefix)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)

    def current_distribution_format(self):
        method_log_prefix = '[%s][current_distribution_format]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        types = self.DISTRIBUTION_FORMAT_TYPES
        if len(self.args) == 4:
            dtype = self.args[1]
            destination = self.args[2]
            prefix = self.args[3]
            if dtype not in types:
                print '%s Please provide a valid type %s' % (method_log_prefix, types)
                sys.exit()
            destination, prefix = self._validate_destination_filename(destination, prefix, True, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_current_distribution_format')(context, {'what': dtype,
                                                                                                 'destination': destination,
                                                                                                 'prefix': prefix})
            if outfilename:
                print 'Writed json with %s data in %s' % (dtype, outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: %s, {destination} {prefix}' % (method_log_prefix)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)

    def current_published_datasets_by_category(self):
        method_log_prefix = '[%s][current_published_datasets_by_category]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        if len(self.args) == 3:
            destination = self.args[1]
            filename = self.args[2]
            destination, filename = self._validate_destination_filename(destination, filename, False, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_current_published_datasets_by_category')(context, {
                'destination': destination, 'filename': filename})
            if outfilename:
                print 'Writed json in %s' % (outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: {destination} {filename}' % (method_log_prefix)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)

    def publishers(self):
        method_log_prefix = '[%s][publishers]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        if len(self.args) == 3:
            destination = self.args[1]
            filename = self.args[2]
            destination, filename = self._validate_destination_filename(destination, filename, False, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_publishers')(context, {'destination': destination,
                                                                                'filename': filename})
            if outfilename:
                print 'Writed json in %s' % (outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: {destination} {filename}' % (method_log_prefix)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)

    def current_publishers_by_administration_level(self):
        method_log_prefix = '[%s][current_publishers_by_administration_level]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        if len(self.args) == 3:
            destination = self.args[1]
            filename = self.args[2]
            destination, filename = self._validate_destination_filename(destination, filename, False, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_current_publishers_by_administration_level')(context, {
                'destination': destination, 'filename': filename})
            if outfilename:
                print 'Writed json in %s' % (outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: {destination} {filename}' % (method_log_prefix)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)

    def drupal_published_contents(self):
        method_log_prefix = '[%s][drupal_published_contents]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        types = self.DRUPAL_PUBLISHED_CONTENTS
        if len(self.args) == 4:
            dtype = self.args[1]
            destination = self.args[2]
            prefix = self.args[3]
            if dtype not in types:
                print '%s Please provide a valid type %s' % (method_log_prefix, types)
                sys.exit()
            destination, prefix = self._validate_destination_filename(destination, prefix, True, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_drupal_published_contents')(context, {'what': dtype,
                                                                                               'destination': destination,
                                                                                               'prefix': prefix})
            if outfilename:
                print 'Writed json with %s data in %s' % (dtype, outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: %s, {destination} {prefix}' % (method_log_prefix, types)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)

    def current_drupal_published_contents(self):
        method_log_prefix = '[%s][current_drupal_published_contents]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        if len(self.args) == 3:
            destination = self.args[1]
            filename = self.args[2]
            destination, filename = self._validate_destination_filename(destination, filename, False, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_current_drupal_published_contents')(context, {
                'destination': destination, 'filename': filename})
            if outfilename:
                print 'Writed json in %s' % (outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: {destination} {filename}' % (method_log_prefix)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)

    def current_drupal_content_by_likes(self):
        method_log_prefix = '[%s][current_drupal_content_by_likes]' % type(self).__name__
        print '%s Init method.' % method_log_prefix
        context = self._set_context()
        if len(self.args) == 3:
            destination = self.args[1]
            filename = self.args[2]
            destination, filename = self._validate_destination_filename(destination, filename, False, method_log_prefix)
            out_filename = get_action('dge_dashboard_json_drupal_content_by_likes')(context, {
                'destination': destination, 'filename': filename})
            if out_filename:
                print 'Written json in %s' % out_filename
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: {destination} {filename}' % method_log_prefix
            sys.exit(1)
        print '%s End method' % method_log_prefix

    def current_drupal_top10_voted_datasets(self):
        method_log_prefix = '[%s][current_drupal_top10_voted_datasets]' % type(self).__name__
        print '%s Init method.' % method_log_prefix
        context = self._set_context()
        if len(self.args) == 3:
            destination = self.args[1]
            filename = self.args[2]
            destination, filename = self._validate_destination_filename(destination, filename, False, method_log_prefix)
            out_filename = get_action('dge_dashboard_json_drupal_top10_voted_datasets')(context, {
                'destination': destination, 'filename': filename})
            if out_filename:
                print 'Written json in %s' % out_filename
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: {destination} {filename}' % method_log_prefix
            sys.exit(1)
        print '%s End method' % method_log_prefix

    def current_users(self):
        method_log_prefix = '[%s][current_users]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        types = self.USERS_TYPES
        if len(self.args) == 4:
            dtype = self.args[1]
            destination = self.args[2]
            prefix = self.args[3]
            if dtype not in types:
                print '%s Please provide a valid type %s' % (method_log_prefix, types)
                sys.exit()
            destination, prefix = self._validate_destination_filename(destination, prefix, True, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_current_users')(context,
                                                                         {'what': dtype, 'destination': destination,
                                                                          'prefix': prefix})
            if outfilename:
                print 'Writed json with %s data in %s' % (dtype, outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: %s, {destination} {prefix}' % (method_log_prefix, types)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)

    def current_assigned_request_by_state(self):
        method_log_prefix = '[%s][current_assigned_request_by_state]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        types = self.REQUEST_TYPES
        if len(self.args) == 4:
            dtype = self.args[1]
            destination = self.args[2]
            prefix = self.args[3]
            if dtype not in types:
                print '%s Please provide a valid type %s' % (method_log_prefix, types)
                sys.exit()
            destination, prefix = self._validate_destination_filename(destination, prefix, True, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_current_assigned_request_by_state')(context, {'what': dtype,
                                                                                                       'destination': destination,
                                                                                                       'prefix': prefix})
            if outfilename:
                print 'Writed json with %s data in %s' % (dtype, outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: %s, {destination} {prefix}' % (method_log_prefix, types)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)

    def visits(self):
        method_log_prefix = '[%s][visits]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        types = self.VISIT_TYPES
        if len(self.args) == 4:
            dtype = self.args[1]
            destination = self.args[2]
            prefix = self.args[3]
            if dtype not in types:
                print '%s Please provide a valid type %s' % (method_log_prefix, types)
                sys.exit()
            destination, prefix = self._validate_destination_filename(destination, prefix, True, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_visits')(context, {'what': dtype, 'destination': destination,
                                                                            'prefix': prefix})
            if outfilename:
                print 'Writed json with %s data in %s' % (dtype, outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: %s, {destination} {prefix}' % (method_log_prefix, types)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)

    def visited_datasets(self):
        method_log_prefix = '[%s][visited_datasets]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        types = self.VISITED_DATASET_TYPES
        if len(self.args) == 4:
            dtype = self.args[1]
            destination = self.args[2]
            prefix = self.args[3]
            if dtype not in types:
                print '%s Please provide a valid type %s' % (method_log_prefix, types)
                sys.exit()
            destination, prefix = self._validate_destination_filename(destination, prefix, True, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_visited_datasets')(context,
                                                                            {'what': dtype, 'destination': destination,
                                                                             'prefix': prefix})
            if outfilename:
                print 'Writed json with %s data in %s' % (dtype, outfilename)
            else:
                print 'No file was created'

            print 'Writing csv files...'
            get_action('dge_dashboard_csv_visited_datasets')(context,
                                                                {'what': dtype, 'destination': destination,
                                                                 'prefix': prefix})
            print 'Writed csv files'

        else:
            print '%s Please provide valid params: %s, {destination} {prefix}' % (method_log_prefix, types)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)

    def organization_by_administration_level(self):
        method_log_prefix = '[%s][organization_by_administration_level]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        if len(self.args) == 3:
            destination = self.args[1]
            filename = self.args[2]
            destination, filename = self._validate_destination_filename(destination, filename, False, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_organization_by_administration_level')(context,{'destination': destination, 'filename': filename})
            if outfilename:
                print 'Writed json in %s' % (outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: {destination} {filename}' % (method_log_prefix)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)


    def organization_name(self):
        method_log_prefix = '[%s][organization_name]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        if len(self.args) == 3:
            destination = self.args[1]
            filename = self.args[2]
            destination, filename = self._validate_destination_filename(destination, filename, False, method_log_prefix)
            outfilename = get_action('dge_dashboard_json_organization_name')(context,{'destination': destination, 'filename': filename})
            if outfilename:
                print 'Writed json in %s' % (outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: {destination} {filename}' % (method_log_prefix)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)
        

class DgeDashboardCsvCommand(CkanCommand):
    ''' Command that generates csv from the database files tables data 
    Usage:
      dge_dashboard_csv published_datasets_by_root_org [paster --plugin=ckanext-dge-dashboard dge_dashboard_csv published_datasets_by_root_org {save|print} {YYYY-MM|last_month|latest} {destination} {filename} -c /etc/ckan/default/production.ini]
          - {save|print}: save if save data in file; print if only print data, not save in file
          - {latest|YYYY-MM|last_month}: 
                latest      - (default) just data for the current month
                YYYY-MM     - just data for the specific month
                last_month  - just data for the last month
          - {destination}: Destination directory of files
          - {filename}: The complete filename will be {filename}.json

  
    '''

    summary = __doc__.split('\n')[0]
    usage = __doc__
    max_args = 5
    min_args = 3
    datetime_format = '%d/%m/%Y %H:%M:%S.%f'

    def __init__(self, name):
        super(DgeDashboardCsvCommand, self).__init__(name)

    def command(self):
        init = datetime.now()
        s_args = (self.args if self.args else '(no args)')
        print '[%s] - Init DgeDashboardCsvCommand command with args: %s.' % (
            init.strftime(DgeDashboardCsvCommand.datetime_format), s_args)
        try:
            self._load_config()
            # We'll need a sysadmin user to perform most of the actions
            # We will use the sysadmin site user (named as the site_id)
            context = {'model': model, 'session': model.Session, 'ignore_auth': True}
            self.admin_user = get_action('get_site_user')(context, {})
            if len(self.args) == 0 or len(self.args) > 5:
                self.parser.print_usage()
                sys.exit(1)
            cmd = self.args[0]
            if cmd == 'published_datasets_by_root_org':
                self.published_datasets_by_root_org()
            else:
                print 'Command %s not recognized' % cmd
        except Exception as e:
            print 'Exception %s' % e
            sys.exit(1)
        finally:
            end = datetime.now()
            print '[%s] - End DgeDashboardCsvCommand command with args %s. Executed command in %s milliseconds.' % (
                end.strftime(DgeDashboardCsvCommand.datetime_format), s_args, (end - init).total_seconds() * 1000)
        sys.exit(0)

    def _load_config(self):
        super(DgeDashboardCsvCommand, self)._load_config()

    def _validate_time_period(self, method_log_prefix='', time_period=None):
        for_date = None
        if time_period:
            if time_period == 'latest':
                time_period = datetime.now().strftime("%Y-%m")
            elif time_period == 'last_month':
                now = datetime.now()
                if now.month == 1:
                    last_month = datetime(now.year - 1, 12, 1, 0, 0, 0)
                else:
                    last_month = datetime(now.year, now.month - 1, 1, 0, 0, 0)
                time_period = last_month.strftime("%Y-%m")

            try:
                for_date = datetime.strptime(time_period, '%Y-%m')
            except ValueError as e:
                print '%s Please provide a valid second param (latest|YYYY-MM|last_month)' % (method_log_prefix)
                sys.exit(1)

            if for_date:
                year = for_date.year
                month = for_date.month
            if month == 12:
                calculation_date = datetime(year + 1, 1, 1, 0, 0, 0)
            else:
                calculation_date = datetime(year, month + 1, 1, 0, 0, 0)
            return time_period, calculation_date
        else:
            print '%s Please provide valid params {print|save} {latest|YYYY-MM|last_month}' % (method_log_prefix)
            sys.exit(1)

    def _validate_destination_filename(self, destination, filename, is_prefix=False, method_log_prefix=''):
        if destination is None or len(destination) == 0 or len(destination.strip(' \t\n\r')) == 0:
            print '%s Please provide a destination' % (method_log_prefix)
            sys.exit(1)
        else:
            destination = destination.strip(' \t\n\r')
        name = 'destination' if is_prefix else 'prefix'
        if filename is None or len(filename) == 0 or len(filename.strip(' \t\n\r')) == 0:
            print '%s Please provide a %s' % (method_log_prefix, name)
            sys.exit(1)
        else:
            filename = filename.strip(' \t\n\r')
            pattern = re.compile(DgeDashboardJsonCommand.FILENAME_REGEX)
            if not pattern.match(filename):
                print '%s Please provide a valid %s. Regular expression: %s' % (method_log_prefix, name, filename_regex)
        return destination, filename

    def _set_context(self):
        return {
            'model': model,
            'session': model.Session,
            'user': self.admin_user['name'],
            'ignore_auth': True,
        }

    def published_datasets_by_root_org(self):
        method_log_prefix = '[%s][published_datasets_by_root_org]' % type(self).__name__
        print '%s Init method.' % (method_log_prefix)
        context = self._set_context()
        save = False
        destination = None
        filename = None
        if len(self.args) >= 3 and len(self.args) <= 5:
            dtype = self.args[1]
            time_period = self.args[2]
            if len(self.args) >= 4:
                destination = self.args[3]
            if len(self.args) >= 5:
                filename = self.args[4]
            if dtype != 'save' and dtype != 'print':
                print '%s Please provide a valid type (save or print)' % (method_log_prefix)
                sys.exit()
            else:
                if dtype == 'save':
                    save = True
            time_period, calculation_date = self._validate_time_period(method_log_prefix, time_period)
            if save:
                destination, filename = self._validate_destination_filename(destination, filename, False,
                                                                            method_log_prefix)
            print destination
            print filename
            outfilename = get_action('dge_dashboard_csv_published_datasets_by_root_org')(context,
                                                                                         {'date': str(calculation_date),
                                                                                          'import_date': time_period,
                                                                                          'save': save,
                                                                                          'destination': destination,
                                                                                          'filename': filename})
            if outfilename:
                print 'Writed json with %s data in %s' % (dtype, outfilename)
            else:
                print 'No file was created'
        else:
            print '%s Please provide valid params: {save|print} {YYYY-MM|last_month|latest} {destination} {filename} {destination} {prefix}' % (
                method_log_prefix)
            sys.exit(1)
        print '%s End method' % (method_log_prefix)
