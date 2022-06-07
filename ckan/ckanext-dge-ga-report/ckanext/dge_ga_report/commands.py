# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge_ga_report (datos.gob.es)".
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

import os
import re
import logging
import datetime
import time
import sys

from pylons import config
from ckan.lib.cli import CkanCommand
import ckanext.dge_ga_report.ga_model as ga_model

log = logging.getLogger('ckanext.dge_ga_report')
PACKAGE_URL = '/catalogo/'
DEFAULT_RESOURCE_URL_TAG = '/downloads/'

RESOURCE_URL_REGEX = re.compile('/catalogo/[a-z0-9-_]+/resource/([a-z0-9-_]+)')
DATASET_EDIT_REGEX = re.compile('/catalogo/edit/([a-z0-9-_]+)')


class DgeGaReportInitDB(CkanCommand):
    """Initialise the extension's database tables
    
    Usage: paster dge_ga_report_initdb
    """
    summary = __doc__.split('\n')[0]
    usage = __doc__
    max_args = 0
    min_args = 0
    datetime_format = '%d/%m/%Y %H:%M:%S.%f'

    def command(self): 
        init = datetime.datetime.now()
        s_args = (self.args if self.args else '(no args)')
        print '[%s] - Init DgeGaReportInitDB command with args: %s.' % (init.strftime(DgeGaReportInitDB.datetime_format), s_args)
        try:
            log = logging.getLogger('ckanext.dge_ga_report')
            self._load_config()

            import ckan.model as model
            model.Session.remove()
            model.Session.configure(bind=model.meta.engine)

            ga_model.init_tables()
            log.info("DB tables are setup")
        except Exception as e:
            print 'Exception %s' % e
            sys.exit(1)
        finally:
            end = datetime.datetime.now()
            print '[%s] - End DgeGaReportInitDB command with args %s. Executed command in %s milliseconds.' % (end.strftime(DgeGaReportInitDB.datetime_format), s_args, (end-init).total_seconds()*1000)
        sys.exit(0)

class DgeGaReportGetAuthToken(CkanCommand):
    """ Get's the Google auth token

    Usage: paster dge_ga_report_getauthtoken <credentials_file>

    Where <credentials_file> is the file name containing the details
    for the service (obtained from https://code.google.com/apis/console).
    By default this is set to credentials.json
    """
    summary = __doc__.split('\n')[0]
    usage = __doc__
    max_args = 1
    min_args = 0
    datetime_format = '%d/%m/%Y %H:%M:%S.%f'

    def command(self):
        """
        In this case we don't want a valid service, but rather just to
        force the user through the auth flow. We allow this to complete to
        act as a form of verification instead of just getting the token and
        assuming it is correct.
        """ 
        init = datetime.datetime.now()
        s_args = (self.args if self.args else '(no args)')
        print '[%s] - Init DgeGaReportGetAuthToken command with args: %s.' % (init.strftime(DgeGaReportGetAuthToken.datetime_format), s_args)
        try:
            from ga_auth import init_service
            init_service('token.dat',
                          self.args[0] if self.args else 'credentials.json')
        except Exception as e:
            print 'Exception %s' % e
            sys.exit(1)
        finally:
            end = datetime.datetime.now()
            print '[%s] - End DgeGaReportGetAuthToken command with args %s. Executed command in %s milliseconds.' % (end.strftime(DgeGaReportGetAuthToken.datetime_format), s_args, (end-init).total_seconds()*1000)
        sys.exit(0)




class DgeGaReportLoadAnalytics(CkanCommand):
    """Parse data from Google Analytics API and store it
    in the ga_model

    Usage: paster dge_ga_report_loadanalytics <save|print> <kind-stat> <time-period>

    Where:
    
      <save-print> is:
        save        - save data in database
        print       - print data in console, not save in database

      <kind-stat> is:
        sessions    - sessions and sessions by section
        pages       - pageviews for datasets and totalevents for resources

      <time-period> is:
        latest      - (default) just the 'latest' data
        YYYY-MM     - just data for the specific month
        last_month  - just data for tha last month

    """
    summary = __doc__.split('\n')[0]
    usage = __doc__
    max_args = 4
    min_args = 3
    datetime_format = '%d/%m/%Y %H:%M:%S.%f'

    def __init__(self, name):
        super(DgeGaReportLoadAnalytics, self).__init__(name)
        from download_analytics import DownloadAnalytics
        self.stat_names = (DownloadAnalytics.PACKAGE_STAT, DownloadAnalytics.RESOURCE_STAT, DownloadAnalytics.VISIT_STAT, 'dge_ga')
        self.parser.add_option('-d', '--delete-first',
                               action='store_true',
                               default=False,
                               dest='delete_first',
                               help='Delete data for the period first')
        self.parser.add_option('-s', '--stat',
                               metavar="STAT",
                               dest='stat',
                               help='Only calulcate a particular stat (or collection of stats)- one of: %s' %
                                    '|'.join(self.stat_names))

        self.token = ""

    def command(self):
        """Grab raw data from Google Analytics and save to the database"""
        init = datetime.datetime.now()
        s_args = (self.args if self.args else '(no args)')
        print '[%s] - Init DgeGaReportLoadAnalytics command with args: %s.' % (init.strftime(DgeGaReportLoadAnalytics.datetime_format), s_args)
        try:
            self._load_config()
            from download_analytics import DownloadAnalytics
            from ga_auth import (init_service, get_profile_id)

            ga_token_filepath = config.get('ckanext-dge-ga-report.token.filepath', '')
            if not ga_token_filepath or not os.path.exists(ga_token_filepath):
                print 'ERROR: In the CKAN config you need to specify the filepath of the ' \
                      'Google Analytics token file under key: googleanalytics.token.filepath'
                #return
                sys.exit(1)

            try:
                self.token, svc = init_service(ga_token_filepath, None)
            except TypeError:
                print ('Unable to create a service. Have you correctly run the getauthtoken task and '
                       'specified the correct token file in the CKAN config under '
                       '"ckanext-dge-ga-report.token.filepath"?')
                #return
                sys.exit(1)
            save_print = self.args[0] if self.args else 'print'
            save = True if save_print == 'save' else False

            kind = self.args[1] if self.args else None
            if kind is None or kind not in DownloadAnalytics.KIND_STATS:
                print ('A valid kind of statistics that you want to load must be '
                       'specified: %s' % DownloadAnalytics.KIND_STATS)
                #return
                sys.exit(1)

            downloader = DownloadAnalytics(svc, self.token, profile_id=get_profile_id(svc),
                                           delete_first=self.options.delete_first,
                                           stat=self.options.stat,
                                           print_progress=True,
                                           kind_stats = kind,
                                           save_stats = save)

            time_period = self.args[2] if self.args else 'latest'
            if time_period == 'latest':
                downloader.latest()
            elif time_period == 'last_month':
                now = datetime.datetime.now()
                if now.month == 1:
                    last_month = datetime.datetime(now.year-1, 12, 1, 0, 0, 0)
                else:
                    last_month = datetime.datetime(now.year, now.month-1, 1, 0, 0, 0)
                downloader.specific_month(last_month)
            else:
                # The month to use
                for_date = datetime.datetime.strptime(time_period, '%Y-%m')
                downloader.specific_month(for_date)
        except Exception as e:
            print 'Exception %s' % e
            sys.exit(1)
        finally:
            end = datetime.datetime.now()
            print '[%s] - End DgeGaReportLoadAnalytics command with args %s. Executed command in %s milliseconds.' % (end.strftime(DgeGaReportLoadAnalytics.datetime_format), s_args, (end-init).total_seconds()*1000)
        sys.exit(0)