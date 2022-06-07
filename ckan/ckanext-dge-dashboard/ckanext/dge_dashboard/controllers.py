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

import csv
import datetime
import json
import logging
import urlparse
import urllib
from datetime import datetime

import ckan.lib.base as base
import ckan.lib.helpers as h
import ckan.model as model
import ckanext.dge_dashboard.helpers as ddh
import ckanext.dge_ga_report.ga_model as ga_model
import paste.deploy.converters as converters
from ckan.common import c, response, _
from ckan.lib.base import BaseController
from ckan.lib.base import render
from ckan.plugins import toolkit
from pylons import config

log = logging.getLogger(__name__)
global_special_org_id = "a8693443-d272-48eb-b02e-a465ef2356f5"


class DGEDashboardController(BaseController):

    def _write_error_csv(self, filename=datetime.now().strftime("%Y-%m-%d")):
        aux_filename = '%s.csv' % datetime.now().strftime("%Y-%m-%d")
        response.headers['Content-Type'] = "text/csv; charset=utf-8"
        response.headers['Content-Disposition'] = str(
            'attachment; filename=%s' % (filename if filename else aux_filename))
        writer = csv.writer(response)
        writer.writerow([_('Error loading data')])

    def dashboard(self):
        return render('dashboard/dashboard.html')

    def my_dashboard(self):
        user = c.user
        org_id = None
        orgs = toolkit.get_action('organization_list_for_user')(data_dict={'permission': 'read'})
        if orgs and len(orgs) > 0:
            org_id = orgs[0].get('id', None) if orgs[0] else None
        aux = org_id.encode('ascii', 'ignore')
        if c.userobj:
            if ((c.userobj.sysadmin == True) or (aux == global_special_org_id)):
                return render('my_dashboard/administrator_dashboard.html')
            else:
                return render('my_dashboard/organization_dashboard.html')
        else:
            base.abort(401, _('Not authorized to see this page'))

    def org_datasets_csv(self):
        '''
        Returns a CSV with the number of views for each dataset and
        its resources downloads.
        '''
        response_data = None
        aux_filename = "%s_datasets_%s.csv" % ('org', datetime.now().strftime("%Y-%m-%d"))
        try:
            organization = ddh._dge_dashboard_user_organization()
            org_id = organization.get('id', None) if organization else None
            if org_id:
                filename = config.get('ckanext.dge_dashboard.chart.org.most_visited_datasets.csv_url_data.filename', None)
                filename = filename.format(org_id) if filename else None
                if filename:
                    url = ddh._dge_dashboard_get_backend(config.get('ckanext.dge_dashboard.chart.org.most_visited_datasets.csv_url_data', None))
                    url = url.format(org_id) if url else None
                    if url:
                        log.info('url = %s' % url)
                        response_data = urllib.urlopen(url)
                    if response_data:
                        reader = csv.reader(response_data)
                        response.headers['Content-Type'] = "text/csv; charset=utf-8"
                        response.headers['Content-Disposition'] = str(
                            'attachment; filename=%s' % aux_filename)
                        writer = csv.writer(response)
                        prefix_url = config.get(
                            'ckan.site_url') + h.url_for(controller='package', action='search') + "/"
                        month_name_dict = {}
                        read_header = False
                        for row in reader:
                            if not read_header:
                                read_header = True
                                column_resources = '%s(%s)' % (
                                    _('Resource'), _('Downloads'))
                                writer.writerow([_('Month').encode('utf-8'), _('Url').encode('utf-8'), _('Dataset').encode('utf-8'), _(
                                    'Public_Private').encode('utf-8'), _('Publisher').encode('utf-8'), _('Visits').encode('utf-8'), column_resources.encode('utf-8')])
                            else:
                                month_name = month_name_dict.get(row[0], None)
                                if not month_name:
                                    month_name = ddh.dge_dashboard_get_month(
                                        row[0], row[1])
                                    month_name_dict[row[0]] = month_name
                                dataset_title = row[3]
                                if row[2] == row[3]:
                                    dataset_title = '[%s] %s' % (_('Deleted').encode('utf-8'), row[3])

                                dataset_public_private = ''
                                if row[4] is not None and row[4].lower() == 'true':
                                    dataset_public_private = _('Private').encode('utf-8')
                                elif row[4] is not None and row[4].lower() == 'false':
                                    dataset_public_private = _('Public').encode('utf-8')

                                writer.writerow([
                                                month_name.encode('utf-8'),
                                                prefix_url + row[2],
                                                dataset_title,
                                                dataset_public_private,
                                                row[5],
                                                row[6],
                                                row[7]
                                                ])
                if not filename or not url or not response_data:
                    self._write_error_csv(aux_filename)
            else:
                base.abort(401, _('Not authorized to see this page'))
        except Exception as e:
            log.error('Exception in org_datasets_csv: %s', e)
            self._write_error_csv(aux_filename)

    def org_users_csv(self):
        '''
        Returns a CSV with the users of an organization.
        '''
        filename = "%s_users_%s.csv" % (
            'org', datetime.now().strftime("%Y-%m-%d"))
        try:
            json_result_data, json_column_titles, total, data_date, error_loading_data = ddh.dge_dashboard_organization_data_users()
            if error_loading_data:
                self._write_error_csv(filename)
            else:
                result_data = json.loads(
                    json_result_data) if json_result_data else []
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str(
                    'attachment; filename=%s' % filename)
                column_titles = [_('Updated date date').encode(
                    'utf-8'), _('Username').encode('utf-8')]
                writer = csv.writer(response)
                writer.writerow(column_titles)
                for result in result_data:
                    row = [
                        result.get('date', '').encode('utf-8'),
                        result.get('username', '').encode('utf-8')
                    ]
                    writer.writerow(row)
        except Exception as e:
            log.error('Exception in org_users_csv: %s', e)
            self._write_error_csv(filename)

    def adm_drupal_contents_csv(self):
        '''
        Returns a CSV with the number of drupal contents by content type
        '''
        filename = "contents_number_%s.csv" % (datetime.now().strftime("%Y-%m-%d"))
        try:
            json_result_data, json_column_titles, total, data_date, error_loading_data = ddh.dge_dashboard_administrator_published_drupal_contents()
            if error_loading_data:
                self._write_error_csv(filename)
            else:
                result_data = json.loads(json_result_data) if json_result_data else []
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
                column_titles = [_('Updated date').encode('utf-8'), _('Content type').encode('utf-8'),
                                 _('Content number').encode('utf-8')]
                writer = csv.writer(response)
                writer.writerow(column_titles)
                for result in result_data:
                    row = [
                        result.get('date', '').encode('utf-8'),
                        result.get('content_type', '').encode('utf-8'),
                        result.get('num_contents', 0)
                    ]
                    writer.writerow(row)
        except Exception as e:
            log.error('Exception in adm_drupal_contents_csv: %s', e)
            self._write_error_csv(filename)

    def adm_drupal_contents_by_likes_csv(self):
        filename = "likes_%s.csv" % (datetime.now().strftime("%Y-%m-%d"))
        try:
            likes_info, column_titles, error_loading_data = \
                ddh.dge_dashboard_administrator_drupal_contents_by_likes()
            if error_loading_data:
                self._write_error_csv(filename)
            else:
                rows = json.loads(likes_info['data'])
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
                writer = csv.writer(response)
                writer.writerow([col.encode('utf-8') for col in json.loads(column_titles)])
                site_url = config.get('ckan.site_url')
                for row in rows:
                    writer.writerow([
                        row.get('name', '').encode('utf-8'),
                        self.__create_absolute_link(site_url, row.get('url', u'')).encode('utf-8'),
                        int(row.get('likes', 0)),
                        row.get('content_type', '').encode('utf-8')
                    ])
        except Exception as e:
            log.error('Exception in adm_drupal_contents_by_likes_csv: %s', e)
            self._write_error_csv(filename)

    def adm_drupal_contents_top10_voted_datasets_csv(self):
        filename = "top10_voted_datasets_%s.csv" % (datetime.now().strftime("%Y-%m-%d"))
        try:
            top10_info, column_titles, error_loading_data = \
                ddh.dge_dashboard_administrator_drupal_top10_voted_datasets()
            if error_loading_data:
                self._write_error_csv(filename)
            else:
                rows = json.loads(top10_info['data'])
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
                writer = csv.writer(response)
                writer.writerow([col.encode('utf-8') for col in json.loads(column_titles)])
                site_url = config.get('ckan.site_url')
                for row in rows:
                    writer.writerow([
                        row.get('name', '').encode('utf-8'),
                        self.__create_absolute_link(site_url, row.get('url', u'')).encode('utf-8'),
                        int(row.get('likes', 0))
                    ])
        except Exception as e:
            log.error('Exception in adm_drupal_contents_top10_voted_datasets_csv: %s', e)
            self._write_error_csv(filename)

    def adm_users_by_org_csv(self):
        '''
        Returns a CSV with the number of users by organizationn
        '''
        filename = "users_organization_%s.csv" % (datetime.now().strftime("%Y-%m-%d"))
        try:
            json_result_data, json_column_titles, total, data_date, error_loading_data = ddh.dge_dashboard_administrator_data_users()
            if error_loading_data:
                self._write_error_csv(filename)
            else:
                result_data = json.loads(json_result_data) if json_result_data else []
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
                column_titles = [_('Updated date').encode('utf-8'), _('Organization name').encode('utf-8'),
                                 _('Users number').encode('utf-8')]
                writer = csv.writer(response)
                writer.writerow(column_titles)
                for result in result_data:
                    row = [
                        result.get('date', '').encode('utf-8'),
                        result.get('organization', '').encode('utf-8'),
                        result.get('num_users', 0)
                    ]
                    writer.writerow(row)
        except Exception as e:
            log.error('Exception in adm_users_by_org_csv: %s', e)
            self._write_error_csv(filename)

    def adm_datasets_by_res_csv(self):
        '''
        Returns a CSV with the number of datasets by resoucers number
        '''
        filename = "datasets_resources_%s.csv" % (datetime.now().strftime("%Y-%m-%d"))
        try:
            json_result_data, json_month_name_list, month_name_list, json_column_titles, error_loading_data = ddh.dge_dashboard_administrator_data_num_datasets_by_num_resources()
            if error_loading_data:
                self._write_error_csv(filename)
            else:
                result_data = json.loads(json_result_data) if json_result_data else []
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
                column_titles = [_('Month').encode('utf-8'), _('Resources Number').encode('utf-8'),
                                 _('Datasets Number').encode('utf-8')]
                writer = csv.writer(response)
                writer.writerow(column_titles)
                for result in result_data:
                    row = [
                        result.get('month', '').encode('utf-8'),
                        result.get('num_resources', 0),
                        result.get('num_datasets', 0)
                    ]
                    writer.writerow(row)
        except Exception as e:
            log.error('Exception in adm_datasets_by_res_csv: %s', e)
            self._write_error_csv(filename)

    def most_visited_datasets_csv(self):
        '''
        Returns a CSV with the most_visited_datasets.
        '''
        filename = "most_visited_datasets_%s.csv" % datetime.now().strftime("%Y-%m-%d")
        try:
            json_result_data, json_month_name_list, month_name_list, json_column_titles, visible_visits = ddh.dge_dashboard_data_most_visited_datasets(
                True)
            visible_visits = converters.asbool(
                config.get('ckanext.dge_dashboard.chart.most_visited_datasets.num_visits.csv.visible', False))
            result_data = json.loads(json_result_data) if json_result_data else []
            response.headers['Content-Type'] = "text/csv; charset=utf-8"
            response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
            column_titles = [_('Month').encode('utf-8'), _('Url').encode('utf-8'), _('Dataset').encode('utf-8'),
                             _('Publisher').encode('utf-8')]
            if visible_visits:
                column_titles.append(_('Visits').encode('utf-8'))
            writer = csv.writer(response)
            writer.writerow(column_titles)
            prefix_url = config.get('ckan.site_url') + h.url_for(controller='package', action='search') + "/"
            for result in result_data:
                row = [
                    result.get('month', '').encode('utf-8'),
                    prefix_url + result.get('url', ''),
                    result.get('title', '').encode('utf-8'),
                    result.get('publisher', '').encode('utf-8')
                ]
                if visible_visits:
                    row.append(result.get('visits', 0))
                writer.writerow(row)
        except Exception as e:
            log.error('Exception in most_visited_datasets_csv: %s', e)
            self._write_error_csv(filename)

    def adm_datasets_by_org_csv(self):
        '''
        Returns a CSV with the number of users by organizationn
        '''

        # Checking if user is allowed to access to
        user = c.user
        org_id = None
        orgs = toolkit.get_action('organization_list_for_user')(data_dict={'permission': 'read'})
        if orgs and len(orgs) > 0:
            org_id = orgs[0].get('id', None) if orgs[0] else None
        aux = org_id.encode('ascii', 'ignore')
        abort_request = False
        if c.userobj:
            if not ((c.userobj.sysadmin) or (aux == global_special_org_id)):
                abort_request = True
        else:
            abort_request = True

        if abort_request:
            base.abort(401, _('Not authorized to see this page'))
        filename = "datasets_by_organization_%s.csv" % (datetime.now().strftime("%Y-%m-%d"))

        try:
            result_data, column_titles, error_loading_data = ddh.dge_dashboard_administrator_datasets_by_org()
            if error_loading_data:
                self._write_error_csv(filename)
            else:
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
                column_titles.insert(0, _('Organization name').encode('utf-8'))
                writer = csv.writer(response)
                writer.writerow(column_titles)
                # Remove additional header
                del column_titles[0]
                for result in result_data:
                    row = []
                    row.append(result.get('title', '').encode('utf-8'))
                    # Get organization data
                    org_data = result.get('data', {})
                    for date in column_titles:
                        if date in org_data:
                            row.append(org_data[date])
                        else:
                            row.append(' ')
                    writer.writerow(row)
        except Exception as e:
            log.error('Exception in adm_datasets_by_org_csv: %s', e)
            self._write_error_csv(filename)

    def adm_organizations_by_level(self):
        '''
        Returns a CSV with the organizations by level with the type of federation
        '''
        filename = "orgs_by_level_%s.csv" % (datetime.now().strftime("%Y-%m-%d"))
        try:
            json_result_data, json_column_titles, data_date, error_loading_data = ddh.dge_dashboard_administrator_organizations_by_level()
            if error_loading_data:
                self._write_error_csv(filename)
            else:
                result_data = json.loads(json_result_data) if json_result_data else []
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
                column_titles = [_('Updated date').encode('utf-8'), _('Organization').encode('utf-8'),
                                 _('Administration level').encode('utf-8'), _('Type of actualization').encode('utf-8')]
                writer = csv.writer(response)
                writer.writerow(column_titles)
                for result in result_data:
                    row = [
                        result.get('date', '').encode('utf-8'),
                        result.get('organization', '').encode('utf-8'),
                        result.get('category', '').encode('utf-8'),
                        result.get('type_actualization', '').encode('utf-8')
                    ]
                    writer.writerow(row)
        except Exception as e:
            log.error('Exception in adm_organizations_by_level: %s', e)
            self._write_error_csv(filename)

    @staticmethod
    def __create_absolute_link(prefix, path):
        url = path.lstrip('/')
        p_url = urlparse.urlparse(url)
        if not (p_url.scheme or p_url.netloc):
            url = prefix.rstrip('/') + u'/' + url
        return url
