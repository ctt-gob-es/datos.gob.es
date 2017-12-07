# Copyright (C) 2017 Entidad Pública Empresarial Red.es
# 
# This file is part of "ckanext-dge-dashboard (datos.gob.es)".
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

import json
import pytz
import datetime
import csv

from ckan.plugins import toolkit

from ckan.lib.base import BaseController
from ckan.lib.base import render
from ckan.common import OrderedDict, c, g, request, response, _
from urllib import urlencode
from datetime import datetime

import ckan.model as model
import ckan.lib.base as base
import ckan.lib.helpers as h
import ckan.logic.auth as logic_auth
import ckan.logic.action as logic_action
import ckan.authz as authz
import ckanext.dge_ga_report.ga_model as ga_model
import ckanext.dge_dashboard.helpers as ddh
import webhelpers.feedgenerator
import paste.deploy.converters as converters
import urllib, json
from pylons import config



import logging
from ckan.logic.action.create import _check_access

log = logging.getLogger(__name__)

class DGEDashboardController(BaseController):

    def _write_error_csv(self, filename=datetime.now().strftime("%Y-%m-%d")):
        aux_filename = '%s.csv' % datetime.now().strftime("%Y-%m-%d")
        response.headers['Content-Type'] = "text/csv; charset=utf-8"
        response.headers['Content-Disposition'] = str('attachment; filename=%s' % (filename if filename else aux_filename))
        writer = csv.writer(response)
        writer.writerow([_('Error loading data')])

    def dashboard(self):
        return render('dashboard/dashboard.html')
    
    def my_dashboard(self):
        user = c.user
        if c.userobj:
            if c.userobj.sysadmin == True:
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
        filename="%s_datasets_%s.csv" % ('org', datetime.now().strftime("%Y-%m-%d"))
        user = c.user
        org_id = None
        if c.userobj:
            if c.userobj.sysadmin == False:
                orgs = toolkit.get_action('organization_list_for_user')(data_dict={'permission': 'read'})
                if orgs and len(orgs) > 0:
                    org_id = orgs[0].get('id', None) if orgs[0] else None
                    filename="%s_datasets_%s.csv" % (orgs[0].get('name', 'org') if orgs[0] else 'org', 
                                                     datetime.now().strftime("%Y-%m-%d")) 
        if org_id:
            try:
                q = model.Session.query(ga_model.DgeGaPackage.year_month,
                                        ga_model.DgeGaPackage.end_day,
                                        ga_model.DgeGaPackage.pageviews,
                                        ga_model.DgeGaPackage.package_name,
                                        model.Package.title,
                                        model.Group.title,
                                        model.Group.id)\
                    .filter(ga_model.DgeGaPackage.organization_id==org_id)\
                    .filter(ga_model.DgeGaPackage.publisher_id==model.Group.id)\
                    .filter(ga_model.DgeGaPackage.package_name == model.Package.name)\
                    .order_by('dge_ga_packages.year_month::text desc')\
                    .order_by('dge_ga_packages.pageviews::int desc')\
                    .order_by('package.title::text asc')
                dataset_entries = q.all()
                packages = []
                if dataset_entries:
                    for month, day, views, url, title, pub_title, pub_id in dataset_entries:
                        q2 = model.Session.query(ga_model.DgeGaResource.total_events,
                                                 model.Resource.url,
                                                 model.Resource.extras)\
                                .filter(ga_model.DgeGaResource.year_month==month)\
                                .filter(ga_model.DgeGaResource.end_day==day)\
                                .filter(ga_model.DgeGaResource.organization_id==org_id)\
                                .filter(ga_model.DgeGaResource.publisher_id==pub_id)\
                                .filter(ga_model.DgeGaResource.package_name == url)\
                                .filter(model.Resource.id == ga_model.DgeGaResource.resource_id)\
                                .order_by('dge_ga_resources.total_events::int desc')\
                                .order_by('dge_ga_resources.url::text asc')
                        resource_entries = q2.all()
                        resources = ''
                        if resource_entries:
                            for total_events, res_url, extras in resource_entries:
                                resources = '%s%s%s(%s)' % (resources, (';' if resources else ''), res_url, total_events)
                        packages.append((month, day, views, url, title, pub_title, resources))
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
                writer = csv.writer(response)
                column_resources = '%s(%s)' % (_('Resource'), _('Downloads'))
                writer.writerow([_('Month').encode('utf-8'), _('Url').encode('utf-8'), _('Dataset').encode('utf-8'), _('Publisher').encode('utf-8'), _('Visits').encode('utf-8'), column_resources.encode('utf-8')])
                prefix_url = config.get('ckan.site_url') + h.url_for(controller='package', action='search') + "/"
                month_name_dict = {}
                for month, day, views, url, title, pub, resources in packages:
                    month_name = month_name_dict.get(month, None)
                    if not month_name:
                        month_name = ddh.dge_dashboard_get_month(month, day)
                        month_name_dict[month] = month_name
                    writer.writerow([month_name.encode('utf-8'), 
                                     prefix_url + url,
                                     title.encode('utf-8'),
                                     pub.encode('utf-8'),
                                     views,
                                     resources.encode('utf-8')])
            except Exception as e:
                log.error('Exception in org_datasets_csv: %s', e)
                self._write_error_csv(filename)
        else: 
            base.abort(401, _('Not authorized to see this page'))


    def org_users_csv(self):
        '''
        Returns a CSV with the users of an organization.
        '''
        filename="%s_users_%s.csv" % ('org', datetime.now().strftime("%Y-%m-%d"))
        try:
            json_result_data, json_column_titles, total, data_date, error_loading_data = ddh.dge_dashboard_organization_data_users()
            if error_loading_data:
                self._write_error_csv(filename)
            else:
                result_data = json.loads(json_result_data) if json_result_data else []
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
                column_titles = [_('Updated date date').encode('utf-8'), _('Username').encode('utf-8')]
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
        filename="contents_number_%s.csv" % (datetime.now().strftime("%Y-%m-%d"))
        try:
            json_result_data, json_column_titles, total, data_date, error_loading_data = ddh.dge_dashboard_administrator_published_drupal_contents()
            if error_loading_data:
                self._write_error_csv(filename)
            else:
                result_data = json.loads(json_result_data) if json_result_data else []
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
                column_titles = [_('Updated date').encode('utf-8'), _('Content type').encode('utf-8'), _('Content number').encode('utf-8')]
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


    def adm_users_by_org_csv(self):
        '''
        Returns a CSV with the number of users by organizationn
        '''
        filename="users_organization_%s.csv" % (datetime.now().strftime("%Y-%m-%d"))
        try:
            json_result_data, json_column_titles, total, data_date, error_loading_data = ddh.dge_dashboard_administrator_data_users()
            if error_loading_data:
                self._write_error_csv(filename)
            else:
                result_data = json.loads(json_result_data) if json_result_data else []
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
                column_titles = [_('Updated date').encode('utf-8'), _('Organization name').encode('utf-8'), _('Users number').encode('utf-8')]
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
        filename="datasets_resources_%s.csv" % (datetime.now().strftime("%Y-%m-%d"))
        try:
            json_result_data, json_month_name_list, month_name_list, json_column_titles, error_loading_data = ddh.dge_dashboard_administrator_data_num_datasets_by_num_resources()
            if error_loading_data:
                self._write_error_csv(filename)
            else:
                result_data = json.loads(json_result_data) if json_result_data else []
                response.headers['Content-Type'] = "text/csv; charset=utf-8"
                response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
                column_titles = [_('Month').encode('utf-8'), _('Resources Number').encode('utf-8'), _('Datasets Number').encode('utf-8')]
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
        filename="most_visited_datasets_%s.csv" % datetime.now().strftime("%Y-%m-%d")
        try:
            json_result_data, json_month_name_list, month_name_list, json_column_titles, visible_visits = ddh.dge_dashboard_data_most_visited_datasets(True)
            visible_visits = converters.asbool(
                      config.get('ckanext.dge_dashboard.chart.most_visited_datasets.num_visits.csv.visible', False))
            result_data = json.loads(json_result_data) if json_result_data else []
            response.headers['Content-Type'] = "text/csv; charset=utf-8"
            response.headers['Content-Disposition'] = str('attachment; filename=%s' % filename)
            column_titles = [_('Month').encode('utf-8'), _('Url').encode('utf-8'), _('Dataset').encode('utf-8'), _('Publisher').encode('utf-8')]
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

