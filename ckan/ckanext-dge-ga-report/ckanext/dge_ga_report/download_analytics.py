# Copyright (C) 2017 Entidad Pública Empresarial Red.es
# 
# This file is part of "ckanext-dge-ga-report (datos.gob.es)".
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
import datetime
import collections
import requests
import time
import re
import logging
import urllib

from pylons import config
import ga_model

log = logging.getLogger(__name__)

FORMAT_MONTH = '%Y-%m'
MIN_VIEWS = 50
MIN_VISITS = 20



class DownloadAnalytics(object):
    '''Downloads and stores analytics info'''

    KIND_STAT_PACKAGE_RESOURCES = 'pages'
    KIND_STAT_VISITS = 'sessions'
    KIND_STATS = [KIND_STAT_PACKAGE_RESOURCES, KIND_STAT_VISITS]

    PACKAGE_STAT = 'dge_ga_package'
    RESOURCE_STAT = 'dge_ga_resource'
    VISIT_STAT = 'dge_ga_visit'

    URL_PREFIX = '^(|/es|/en|/eu|/ca|/gl)/'
    URL_SUFFIX = '/[a-z0-9-_]+'
    PACKAGE_URL_REGEX = URL_PREFIX + 'catalogo' + URL_SUFFIX + '/?$'
    PACKAGE_URL_EXCLUDED_REGEXS = [URL_PREFIX + 'catalogo/new/?$']

    SECTIONS = [ 
                {
                 'key': 'all',
                 'name': '', 
                 'url_regex': '',
                 'exluded_url_regex': []
                },
                {
                 'key': 'section',
                 'name': 'catalogo', 
                 'url_regex': URL_PREFIX + 'catalogo(' + URL_SUFFIX + ')?/?$',
                 'exluded_url_regex': [URL_PREFIX + 'catalogo/new/?$']
                },
                {
                 'key': 'section',
                 'name': 'iniciativas', 
                 'url_regex': URL_PREFIX + 'iniciativas(' + URL_SUFFIX + ')?/?$',
                 'exluded_url_regex': []
                }, 
                {
                 'key': 'section',
                 'name': 'documentacion', 
                 'url_regex': URL_PREFIX + 'documentacion(' + URL_SUFFIX + ')?/?$',
                 'exluded_url_regex': []
                }, 
                {
                 'key': 'section',
                 'name': 'aplicaciones', 
                 'url_regex': URL_PREFIX + 'aplicaciones(' + URL_SUFFIX + ')?/?$',
                 'exluded_url_regex': []
                },
                {
                 'key': 'section',
                 'name': 'casos-exito', 
                 'url_regex': URL_PREFIX + 'casos-exito(' + URL_SUFFIX + ')?/?$',
                 'exluded_url_regex': []
                },
                {
                 'key': 'section',
                 'name': 'peticiones-datos', 
                 'url_regex': URL_PREFIX + 'peticiones-datos(' + URL_SUFFIX + ')?/?$',
                 'exluded_url_regex': []}, 
                {
                 'key': 'section',
                 'name': 'dashboard', 
                 'url_regex': URL_PREFIX + 'dashboard(' + URL_SUFFIX + ')?/?$',
                 'exluded_url_regex': []
                }
            ]
    

    def __init__(self, service=None, token=None, profile_id=None, 
                 delete_first=False, stat=None, print_progress=False, 
                 kind_stats=None, save_stats=False):
        self.period = config.get('ckanext-dge-ga-report.period', 'monthly')
        self.hostname = config.get('ckanext-dge-ga-report.hostname', None)
        self.service = service
        self.profile_id = profile_id
        self.delete_first = delete_first
        self.stat = stat
        self.token = token
        self.print_progress = print_progress
        self.kind_stats = kind_stats
        self.save_stats = save_stats

    def specific_month(self, date):
        import calendar

        first_of_this_month = datetime.datetime(date.year, date.month, 1)
        _, last_day_of_month = calendar.monthrange(int(date.year), int(date.month))
        last_of_this_month = datetime.datetime(date.year, date.month, last_day_of_month)
        # if this is the latest month, note that it is only up until today
        now = datetime.datetime.now()
        if now.year == date.year and now.month == date.month:
            last_day_of_month = now.day
            last_of_this_month = now
        periods = ((date.strftime(FORMAT_MONTH),
                    last_day_of_month,
                    first_of_this_month, last_of_this_month),)
        self.download_and_store(periods)

    def latest(self):
        if self.period == 'monthly':
            # from first of this month to today
            now = datetime.datetime.now()
            first_of_this_month = datetime.datetime(now.year, now.month, 1)
            periods = ((now.strftime(FORMAT_MONTH),
                        now.day,
                        first_of_this_month, now),)
        else:
            raise NotImplementedError
        self.download_and_store(periods)

    @staticmethod
    def get_full_period_name(period_name, period_complete_day):
        if period_complete_day:
            return period_name + ' (up to %ith)' % period_complete_day
        else:
            return period_name

    def download_and_store(self, periods):
        for period_name, period_complete_day, start_date, end_date in periods:
            log.info('Period "%s" (%s - %s)',
                     self.get_full_period_name(period_name, period_complete_day),
                     start_date.strftime('%Y-%m-%d'),
                     end_date.strftime('%Y-%m-%d'))
            print 'period_name=%s' % period_name
            if self.save_stats and self.delete_first:
                log.info('Deleting existing Analytics for this period "%s"',
                         period_name)
                ga_model.delete(period_name)

#             accountName = config.get('googleanalytics.account', '')
#             path_prefix = '~'  # i.e. it is a regex
#             # Possibly there is a domain in the path.
#             # I'm not sure why, but on the data.gov.uk property we see
#             # the domain gets added to the GA path. e.g.
#             #   '/data.gov.uk/data/search'
#             #   '/co-prod2.dh.bytemark.co.uk/apps/test-app'
#             # but on other properties we don't. e.g.
#             #   '/data/search'
#             path_prefix += '(/%s)?' % accountName

            if self.stat in (None, DownloadAnalytics.PACKAGE_STAT) and \
               self.kind_stats == DownloadAnalytics.KIND_STAT_PACKAGE_RESOURCES:
                # Clean out old dge_ga_package data before storing the new
                stat = DownloadAnalytics.PACKAGE_STAT
                if self.save_stats:
                    ga_model.pre_update_dge_ga_package_stats(period_name)
                log.info('Downloading analytics for package views')
                data = self.download(start_date, end_date, 
                                     DownloadAnalytics.PACKAGE_URL_REGEX, 
                                     DownloadAnalytics.PACKAGE_URL_EXCLUDED_REGEXS,
                                     stat)
                if data:
                    if self.save_stats:
                        log.info('Storing package views (%i rows)', len(data.get(stat, [])))
                        print 'Storing package views (%i rows)' % (len(data.get(stat, [])))
                        self.store(period_name, period_complete_day, data, stat)
                        # Create the All records
                        ga_model.post_update_dge_ga_package_stats()
                    else:
                        print 'The result contains %i rows:' % (len(data.get(stat, [])))
                        for row in data.get(stat):
                            print row

            if self.stat in (None, DownloadAnalytics.RESOURCE_STAT) and\
               self.kind_stats == DownloadAnalytics.KIND_STAT_PACKAGE_RESOURCES:
                # Clean out old dge_ga_package data before storing the new
                stat = DownloadAnalytics.RESOURCE_STAT
                if self.save_stats:
                    ga_model.pre_update_dge_ga_resource_stats(period_name)

                log.info('Downloading analytics for resource views')
                data = self.download(start_date, end_date, 
                                     DownloadAnalytics.PACKAGE_URL_REGEX,
                                     DownloadAnalytics.PACKAGE_URL_EXCLUDED_REGEXS,
                                     stat)
                if data:
                    if self.save_stats:
                        log.info('Storing resource views (%i rows)', len(data.get(stat, [])))
                        print 'Storing resource views (%i rows)' % (len(data.get(stat, [])))
                        self.store(period_name, period_complete_day, data, stat)
                        # Create the All records
                        ga_model.post_update_dge_ga_resource_stats()
                    else:
                        print 'The result contains %i rows:' % (len(data.get(stat, [])))
                        for row in data.get(stat):
                            print row

            if self.stat in (None, DownloadAnalytics.VISIT_STAT) and \
               self.kind_stats == DownloadAnalytics.KIND_STAT_VISITS:
                # Clean out old dge_ga_package data before storing the new
                stat = DownloadAnalytics.VISIT_STAT
                if self.save_stats:
                    ga_model.pre_update_dge_ga_visit_stats(period_name)

                visits = []
                for section in DownloadAnalytics.SECTIONS:
                    key = section.get('key', None)
                    name = section.get('name', None)
                    path = section.get('url_regex', '')
                    excluded_paths = section.get('exluded_url_regex', [])
                    if name or key:
                        log.info('Downloading analytics for %s sessions', name, key)
                        print 'Downloading analytics for %s %s sessions' % (name, key)
                        data = self.download(start_date, end_date, path, excluded_paths, stat)
                        if data:
                            visits.append((key, name, data.get(stat, 0)))
                if visits and len(visits) >= 1:
                    if self.save_stats:
                        log.info('Storing session visits (%i rows)', len(visits))
                        print 'Storing session visits (%i rows)' % (len(visits))
                        self.store(period_name, period_complete_day, {stat:visits}, stat)
                    else:
                        print 'The result contains %i rows:' % (len(visits))
                        for row in visits:
                            print row

    def download(self, start_date, end_date, path=None, exludedPaths= None, stat=None):
        '''Get views & visits data for particular paths & time period from GA
        '''
        if start_date and end_date and path is not None and stat:
            if stat not in [DownloadAnalytics.PACKAGE_STAT, DownloadAnalytics.RESOURCE_STAT, DownloadAnalytics.VISIT_STAT]:
                return {}
            start_date = start_date.strftime('%Y-%m-%d')
            end_date = end_date.strftime('%Y-%m-%d')
            print 'Downloading analytics for stat %s, since %s, until %s with path %s' %(stat, start_date, end_date, path)

            query = None
            if stat == DownloadAnalytics.PACKAGE_STAT:
                if path:
                    query = 'ga:pagePath=~%s' % path
                metrics = 'ga:pageviews'
                sort = '-ga:pageviews'
                dimensions = "ga:pagePath"

            if stat == DownloadAnalytics.RESOURCE_STAT:
                query = 'ga:eventCategory==Resource;ga:eventAction==Download'
                if path:
                    query += ';ga:pagePath=~%s' % path
                metrics = 'ga:totalEvents'
                sort = '-ga:totalEvents'
                dimensions = "ga:eventLabel, ga:pagePath"
            
            if stat == DownloadAnalytics.VISIT_STAT:
                if path:
                    query = 'ga:pagePath=~%s' % path
                metrics = 'ga:sessions'
                sort = '-ga:sessions'
                dimensions = ''

            if exludedPaths:
                for path in exludedPaths:
                    if query: 
                        query += ';ga:pagePath!~%s' % path
                    else:
                        query = 'ga:pagePath!~%s' % path
            if self.hostname:
                if query:
                    query += ';ga:hostname=~%s' % self.hostname
                else:
                    query = 'ga:hostname=~%s' % self.hostname

            # Supported query params at
            # https://developers.google.com/analytics/devguides/reporting/core/v3/reference
            try:
                args = {}
                args["sort"] = sort
                args["max-results"] = 100000
                args["dimensions"] = dimensions
                args["start-date"] = start_date
                args["end-date"] = end_date
                args["metrics"] = metrics
                args["ids"] = "ga:" + self.profile_id
                args["filters"] = query
                args["alt"] = "json"
                
                #print "args=%s" % args
                
                results = self._get_ga_data(args)

            except Exception, e:
                log.exception(e)
                print 'EXCEPTION %s' % e
                return dict(url=[])

            log.info('There are %d results', results.get('totalResults', 0) if results else 0)
            print 'There are %d results' % results.get('totalResults', 0) if results else 0
            if stat == DownloadAnalytics.PACKAGE_STAT:
                packages = []
                pattern = re.compile('^' + DownloadAnalytics.PACKAGE_URL_REGEX)
                excluded_patterns = []
                for regex in DownloadAnalytics.PACKAGE_URL_EXCLUDED_REGEXS:
                    excluded_patterns.append(re.compile('^' + regex))
                for entry in results.get('rows'):
                    (path, pageviews) = entry
                    url = strip_off_host_prefix(path)  # strips off domain e.g. datos.gob.es
                    url = strip_off_language_prefix(url)  # strips off language
                    if not pattern.match(url):
                        continue
                    for excluded_pattern in excluded_patterns:
                        if excluded_pattern.match(url):
                            continue
                    packages.append( (url, pageviews) ) # Temporary hack
                return {stat:packages}
            elif stat == DownloadAnalytics.RESOURCE_STAT:
                resources = []
                pattern = re.compile('^' + DownloadAnalytics.PACKAGE_URL_REGEX)
                excluded_patterns = []
                for regex in DownloadAnalytics.PACKAGE_URL_EXCLUDED_REGEXS:
                    excluded_patterns.append(re.compile('^' + regex))
                for entry in results.get('rows'):
                    (event_label, page_path, total_events) = entry
                    page_url = strip_off_host_prefix(page_path)  # strips off domain e.g. datos.gob.es
                    page_url = strip_off_language_prefix(page_url)  # strips off language
                    res_url = urllib.unquote_plus(event_label)
                    if not pattern.match(page_url):
                        continue
                    for excluded_pattern in excluded_patterns:
                        if excluded_pattern.match(page_url):
                            continue
                    resources.append( (res_url, page_url, total_events) ) # Temporary hack
                return {stat:resources}
            elif stat == DownloadAnalytics.VISIT_STAT:
                rows = results.get('rows') if results else None
                print rows
                visits = 0
                if rows and len(rows) >= 1:
                    for entry in rows:
                        if entry:
                            visits = entry[0]
                            break
                return {stat:visits}
        else:
            log.info("Not all parameters were received")
            print ("Not all parameters were received")
            return {}

    def store(self, period_name, period_complete_day, data, stat):
        if self.save_stats:
            if stat and stat == DownloadAnalytics.PACKAGE_STAT and stat in data:
                ga_model.update_dge_ga_package_stats(period_name, period_complete_day, data[stat],
                                          print_progress=self.print_progress)

            if stat and stat == DownloadAnalytics.RESOURCE_STAT and stat in data:
                ga_model.update_dge_ga_resource_stats(period_name, period_complete_day, data[stat],
                                          print_progress=self.print_progress)

            if stat and stat == DownloadAnalytics.VISIT_STAT and stat in data:
                ga_model.update_dge_ga_visit_stats(period_name, period_complete_day, data[stat],
                                          print_progress=self.print_progress)

    def _get_ga_data(self, params):
        '''Returns the GA data specified in params.
        Does all requests to the GA API and retries if needed.

        Returns a dict with the data, or dict(url=[]) if unsuccessful.
        '''
        try:
            data = self._get_ga_data_simple(params)
        except DownloadError:
            log.info('Will retry requests after a pause')
            time.sleep(300)
            try:
                data = self._get_ga_data_simple(params)
            except DownloadError:
                return dict(url=[])
            except Exception, e:
                log.exception(e)
                log.error('Uncaught exception in get_ga_data_simple (see '
                          'above)')
                return dict(url=[])
        except Exception, e:
            log.exception(e)
            log.error('Uncaught exception in get_ga_data_simple (see above)')
            return dict(url=[])
        return data

    def _get_ga_data_simple(self, params):
        '''Returns the GA data specified in params.
        Does all requests to the GA API.

        Returns a dict with the data, or raises DownloadError if unsuccessful.
        '''
        ga_token_filepath = os.path.expanduser(
            config.get('ckanext-dge-ga-report.token.filepath', ''))
        if not ga_token_filepath:
            log.error('In the CKAN config you need to specify the filepath '
                      'of the Google Analytics token file under key: '
                      'googleanalytics.token.filepath')
            return

        try:
            from ga_auth import init_service
            self.token, svc = init_service(ga_token_filepath, None)
        except Exception, auth_exception:
            log.error('OAuth refresh failed')
            log.exception(auth_exception)
            return dict(url=[])

        headers = {'authorization': 'Bearer ' + self.token}
        response = self._do_ga_request(params, headers)
        # allow any exceptions to bubble up

        data_dict = response.json()

        # If there are 0 results then the rows are missed off, so add it in
        if 'rows' not in data_dict:
            data_dict['rows'] = []
        return data_dict

    @classmethod
    def _do_ga_request(cls, params, headers):
        '''Makes a request to GA. Assumes the token init request is already done.

        Returns the response (requests object).
        On error it logs it and raises DownloadError.
        '''
        # Because of issues of invalid responses when using the ga library, we
        # are going to make these requests ourselves.
        ga_url = 'https://www.googleapis.com/analytics/v3/data/ga'
        try:
            response = requests.get(ga_url, params=params, headers=headers)
        except requests.exceptions.RequestException, e:
            log.error("Exception getting GA data: %s" % e)
            raise DownloadError()
        if response.status_code != 200:
            log.error("Error getting GA data: %s %s" % (response.status_code,
                                                        response.content))
            raise DownloadError()
        return response


global host_re
host_re = None


def strip_off_host_prefix(url):
    '''Strip off the hostname that gets prefixed to the GA Path on datos.gob.es
    UA-1 but not on others.

    >>> strip_off_host_prefix('/datos.gob.es/catalogo/weekly_fuel_prices')
    '/catalogo/weekly_fuel_prices'
    >>> strip_off_host_prefix('/catalogo/weekly_fuel_prices')
    '/catalogo/weekly_fuel_prices'
    '''
    global host_re
    if not host_re:
        host_re = re.compile('^\/[^\/]+\.')
    # look for a dot in the first part of the path
    if host_re.search(url):
        # there is a dot, so must be a host name - strip it off
        return '/' + '/'.join(url.split('/')[2:])
    return url

def strip_off_language_prefix(url):
    '''Strip off the language that gets prefixed to the GA Path on datos.gob.es
    UA-1 but not on others.

    >>> strip_off_language_prefix('/es/catalogo/weekly_fuel_prices')
    '/catalogo/weekly_fuel_prices'
    >>> strip_off_language_prefix('/catalogo/weekly_fuel_prices')
    '/catalogo/weekly_fuel_prices'
    '''
    languages = config['ckan.locales_offered']
    if languages:
        for l in languages.split():
            prefix = '/%s/' % l
            if url.find(prefix) == 0:
                url = url[len(prefix)-1:]
                if url.endswith('/'):
                    return url[:-1]
    return url


class DownloadError(Exception):
    pass
