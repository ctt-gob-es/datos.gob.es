# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge (datos.gob.es)".
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

import json
import pytz
import datetime
import urllib
import sys

from ckan.plugins import toolkit

from ckan.controllers.organization import OrganizationController
from ckan.controllers.package import PackageController
from ckan.controllers.util import UtilController
from ckan.controllers.feed import FeedController, _package_search, _create_atom_id, _FixedAtom1Feed
from ckan.lib.base import BaseController
from ckan.lib.base import render
from ckan.common import OrderedDict, c, g, request, response, _
from urllib import urlencode
import ckan.model as model
import ckan.lib.base as base
import ckan.lib.helpers as h
import ckan.logic.auth as logic_auth
import ckan.logic.action as logic_action
import ckan.authz as authz
import webhelpers.feedgenerator
from pylons import config

import logging
from ckan.logic.action.create import _check_access
from ckanext.dcat.controllers import check_access_header

CONTENT_TYPES = {
    'rdf': 'application/rdf+xml',
    'xml': 'application/rdf+xml',
    'n3': 'text/n3',
    'ttl': 'text/turtle',
    'jsonld': 'application/ld+json',
    'csv': 'text/csv'
}

log = logging.getLogger(__name__)


class DGEController(BaseController):

    def yasgui(self):
        return render('yasgui/sparql.html')

    def accessible_yasgui(self):
        return render('yasgui/accessible-sparql.html')

    def swagger(self):
        return render('apidata/apidata.html')

    def accessible_swagger(self):
        return render('apidata/accessible-apidata.html')

    def organism(self):
        organization_list = []
        try:
            prefix = config.get('ckanext.dge.organism.uri', 'http://datos.gob.es/recurso/sector-publico/org/Organismo')
            sql = '''select g.title, ge.value, ge.value
                     from "group" g, group_extra ge
                     where ge.key like 'C_ID_UD_ORGANICA'
                     and ge.group_id LIKE g.id
                     and g.type like 'organization'
                     and ge.state like 'active'
                     and g.state like 'active'
                     order by g.title asc;'''
            result = model.Session.execute(sql)
            for row in result:
                org_name = row[0] if row[0] else None
                dir3 = row[1] if row[1] else None
                if org_name and dir3:
                    organization_list.append({
                                              'title': org_name,
                                              'dir3': dir3,
                                              'uri': '%s/%s' % (prefix, dir3)
                                              }) 
        except Exception as e:
            log.error('Exception in organism: %s', e)
        c.organization_list = organization_list
        return render('static/organism.html')

    def default_spatial_coverage(self):
        return render('static/default_spatial_coverage.html')

    def spatial_coverage(self, type, name):
        spatial_dict = {}
        data = None
        item = None
        apidatahost = config.get('ckanext.dge.apidata.host', None)
        apidataurl = config.get('ckanext.dge.apidata.url.spatial', None)
        apidatatype = None
        if type:
            if type == 'Provincia':
                apidatatype = 'Province'
            elif type == 'Autonomia':
                apidatatype = 'Autonomous-region'
            elif type == 'Pais':
                apidatatype = 'Country'
            else:
                apidatatype = None
        if apidatahost and apidataurl and apidatatype and name:
            url = u'%s/%s/%s/%s' % (apidatahost, apidataurl, apidatatype, name)
            if url:
                url = urllib.quote(url.encode('utf8'), ':/')
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
            if data:
                items = data.get('result', {}).get('items', {})
                if items and items[0]:
                    item = items[0]
        spatial_dict['type'] = type
        spatial_dict['name'] = name
        spatial_dict['label'] = name
        if item:
            spatial_dict['label'] = item.get('label', '')
            spatial_dict['about'] = item.get('_about', '')
            rows = []
            rows.append({'key': 'rdfs:label', 'value': item.get('label', '')})
            if type == 'Provincia':
                rows.append({'key': 'esadm:autonomia', 'value': item.get('autonomia', '')})
            if type == 'Provincia' or type == 'Autonomia':
                rows.append({'key': 'esadm:pais', 'value': item.get('pais', '')})
                rows.append({'key': 'owl:sameAs', 'value': item.get('sameAs', '')})
            complete_type = item.get('type', '')
            if complete_type:
                s_type = complete_type.split('#')
                type = s_type[-1] if s_type else type
            rows.append({'key': 'rdf:type', 'value': 'esadm:%s' % type})
            spatial_dict['rows'] = rows
        c.spatial_dict = spatial_dict
        request.environ['PATH_INFO'] = urllib.quote(request.environ['PATH_INFO'])
        return render('static/spatial-coverage.html')
    
    def default_theme(self):
        return render('static/default_theme.html')

    def theme(self, name):
        apidatahost = config.get('ckanext.dge.apidata.host', None)
        apidataurl = config.get('ckanext.dge.apidata.url.sector', None)
        data = None
        theme_dict = {}
        item = None
        if apidatahost and apidataurl and name:
            url = '%s/%s/%s' % (apidatahost, apidataurl, name)
            if url:
                error_loading_data = False
                response = urllib.urlopen(url)
                if response:
                    data = json.loads(response.read())
            if data:
                items = data.get('result', {}).get('items')
                if items and items[0]:
                    item = items[0]
        theme_dict['name'] = name
        theme_dict['type'] = 'sector'
        theme_dict['label'] = name
        if item:
            theme_dict['label'] = item.get('prefLabel', '')
            theme_dict['about'] = item.get('_about', '')
            rows = []
            rows.append({'key': 'skos:inScheme', 'value': item.get('inScheme', '')})
            rows.append({'key': 'skos :prefLabel', 'value': item.get('prefLabel', '')})
            complete_type = item.get('type', '')
            type = ''
            if complete_type:
                s_type = complete_type.split('#')
                type = s_type[-1] if s_type else 'Concept'
            rows.append({'key': 'rdf:type', 'value': 'skos:%s' % (type)})
            theme_dict['rows'] = rows
        c.theme_dict = theme_dict
        return render('static/theme.html')

    def read_dataset(self, _id, _format=None):

        if not _format:
            _format = check_access_header()

        if not _format:
            return PackageController().read(_id)

        toolkit.response.headers.update(
            {'Content-type': CONTENT_TYPES[_format]})

        try:
            result = toolkit.get_action('dge_harvest_dataset_show')({}, {'id': _id,
                                                                         'format': _format})
        except toolkit.ObjectNotFound:
            toolkit.abort(404)

        return result


class DGEOrganizationController(OrganizationController):

    def index(self):
        context = {'model': model, 'session': model.Session,
                   'user': c.user or c.author, 'for_view': True,
                   'with_private': False}
        try:
            self._check_access('sysadmin', context)
        except toolkit.NotAuthorized:
            base.abort(401, _('Not authorized to see this page'))

        return super(DGEOrganizationController, self).index()

class DGEPackageController(PackageController):

    def _get_package_owner_org(self, id):
        """
        Given the id of a package this method will return the owner_org_ id of the
        package, or 'dataset' if no type is currently set
        """
        pkg = model.Package.get(id)
        if pkg:
            return pkg.owner_org or None 
        return None

    def search(self):
        from ckan.lib.search import SearchError
        
        package_type = self._guess_package_type()
        if (package_type == 'harvest'):
            user = authz.get_user_id_for_username(c.user, allow_none=True)
            if not user:
                base.abort(401, _('Not authorized to see this page'))
        return super(DGEPackageController, self).search()

    def read(self, id):
        context = {'model': model, 'session': model.Session,
                   'user': c.user or c.author, 'for_view': True,
                   'auth_user_obj': c.userobj}
        data_dict = {'id': id, 'include_tracking': True}
        package_type = self._get_package_type(id)
        try:
            if (package_type == 'harvest'):
                data_dict['owner_org'] = self._get_package_owner_org(id)
                _check_access('dge_harvest_source_show', context, data_dict)
        except toolkit.NotAuthorized:
            base.abort(401, _('Not authorized to see this page'))
        return super(DGEPackageController, self).read(id)

    def history(self, id):
        context = {'model': model, 'session': model.Session,
                   'user': c.user or c.author, 'auth_user_obj': c.userobj}
        data_dict = {'id': id}
        package_type = self._get_package_type(id)
        try:
            if (package_type == 'harvest'):
                data_dict['owner_org'] = self._get_package_owner_org(id)
                _check_access('dge_harvest_source_show', context, data_dict)
        except toolkit.NotAuthorized:
            base.abort(401, _('Not authorized to see this page'))
        return super(DGEPackageController, self).history(id)

def _encode_params(params):
    return [(k, v.encode('utf-8') if isinstance(v, basestring) else str(v)) for k, v in params]


def url_with_params(url, params):
    params = _encode_params(params)
    print params
    return url + u'?' + urlencode(params)

    
class DGEUtilController(UtilController):


    def redirect_search(self):
        ''' redirect to the url parameter. '''
        search_filter = base.request.params.get('search_filter')
        search_block_form = base.request.params.get('search_block_form')
        if search_filter == 'drupal':
            params = (('search_keyword', search_block_form),)
            return base.redirect(url_with_params('/' + h.lang()+ '/site-search',  params))
        else:
            params = (('q', search_block_form), ('sort', u'metadata_modified desc'))
            return base.redirect(url_with_params('/' + h.lang()+ '/catalogo',  params))

class DGEFeedController(FeedController):

    def _dge_date_str_to_datetime(self, date_str):
        try: 
            datetime_ = h.date_str_to_datetime(date_str)
        except TypeError:
            return None
        except ValueError:
            return None

        #Timezone in dge is always Europe/Madrid
        from_timezone = pytz.timezone('Europe/Madrid')
        to_timezone = pytz.timezone('UTC')
        datetime_ = from_timezone.localize(datetime_)

        return datetime_
    
    def _alternate_url(self, params, **kwargs):
        search_params = params.copy()
        search_params.update(kwargs)
 
        # Can't count on the page sizes being the same on the search results
        # view.  So provide an alternate link to the first page, regardless
        # of the page we're looking at in the feed.
        search_params.pop('page', None)
        return self._feed_url(search_params,
                              controller='ckanext.dge.controllers:DGEPackageController',
                              action='search')
    
    def general(self):
        data_dict, params = self._parse_url_params()
        data_dict['q'] = '*:*'

        item_count, results = _package_search(data_dict)

        navigation_urls = self._navigation_urls(params,
                                                item_count=item_count,
                                                limit=data_dict['rows'],
                                                controller='ckanext.dge.controllers:DGEFeedController',
                                                action='general')

        feed_url = self._feed_url(params,
                                  controller='ckanext.dge.controllers:DGEFeedController',
                                  action='general')

        alternate_url = self._alternate_url(params)
        return self.output_feed(results,
                                feed_title=g.site_title,
                                feed_description= 'Conjuntos de datos recientemente creados o actualizados en %s' % g.site_title,
                                feed_link=alternate_url,
                                feed_guid=_create_atom_id
                                (u'/feeds/dataset.atom'),
                                feed_url=feed_url,
                                navigation_urls=navigation_urls)
 
    def output_feed(self, results, feed_title, feed_description,
                    feed_link, feed_url, navigation_urls, feed_guid):
        author_name = config.get('ckan.feeds.author_name', '').strip() or \
            config.get('ckan.site_id', '').strip()
        author_link = config.get('ckan.feeds.author_link', '').strip() or \
            config.get('ckan.site_url', '').strip()

        feed = _FixedAtom1Feed(
            title=feed_title,
            link=feed_link,
            description=feed_description,
            language='es',
            author_name=author_name,
            author_link=author_link,
            feed_guid=feed_guid,
            feed_url=feed_url,
            previous_page=navigation_urls['previous'],
            next_page=navigation_urls['next'],
            first_page=navigation_urls['first'],
            last_page=navigation_urls['last'],
        )
        
        for pkg in results:
            description= pkg.get('description', '').get('es', '')
            feed.add_item(
                title=pkg.get('title', ''),
                link=self.base_url + h.url_for(controller='package',
                                               action='read',
                                               id=pkg['name']),
                description=description,
                updated=self._dge_date_str_to_datetime(pkg.get('metadata_modified')),
                published=self._dge_date_str_to_datetime(pkg.get('metadata_created')),
                unique_id=_create_atom_id(u'/catalogo/%s' % pkg['name']),
                author_name=pkg.get('author_name', ''),
                author_email=pkg.get('author_email', ''),
                categories=[t['name'] for t in pkg.get('tags', [])],
                enclosure=None,
                )
        response.content_type = feed.mime_type
        return feed.writeString('utf-8')

