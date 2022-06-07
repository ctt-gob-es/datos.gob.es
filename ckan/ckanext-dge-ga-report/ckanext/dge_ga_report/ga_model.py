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

# -*- coding:utf-8 -*-
import logging
import re
import urllib
import datetime

from ckan.model.domain_object import DomainObject

from sqlalchemy import Table, Column, MetaData, PrimaryKeyConstraint
from sqlalchemy import types
from sqlalchemy.orm import mapper
from sqlalchemy.sql.expression import cast
from sqlalchemy import func
from sqlalchemy.exc import InvalidRequestError

import ckan.model as model


from lib import GaProgressBar
from paste.util.PySourceColor import null

log = logging.getLogger(__name__)

DGE_GA_PACKAGE_TABLE_NAME = 'dge_ga_packages'
DGE_GA_RESOURCE_TABLE_NAME = 'dge_ga_resources'
DGE_GA_VISIT_TABLE_NAME = 'dge_ga_visits'

global dge_ga_package_table
global dge_ga_resource_table
global dge_ga_visit_table

dge_ga_package_table = None
dge_ga_resource_table = None
dge_ga_visit_table = None

metadata = MetaData()

class DgeGaDomainObject(DomainObject):
    '''Convenience methods for searching objects
    '''

    @classmethod
    def filter(cls, **kwds):
        query = Session.query(cls).autoflush(False)
        return query.filter_by(**kwds)

class DgeGaPackage(DgeGaDomainObject):
    '''
    A DgeGaPackage contains information about a dataset: pageviews, date, 
    organization and publisher.
    '''
    def __init__(self, **kwargs):
        for k,v in kwargs.items():
            setattr(self, k, v)

    def __repr__(self):
        return '''<DgeGaPackage year_month=%s, end_day=%s, pageviews=%s, url=%s, 
                  package_name=%s, organization_id=%s, publisher_id=%s>''' % \
               (self.year_month, self.end_day, self.pageviews, self.url, 
                self.package_name, self.organization_id, self.publisher_id)

    def __str__(self):
        return self.__repr__().encode('ascii', 'ignore')

    @classmethod
    def get(cls, year_month, url, package_name):
        '''Finds a single entity in the register.'''
        kwds = {'year_month': year_month, 
                'url': url,
                'package_name': package_name}
        o = cls.filter(**kwds).first()
        if o:
            return o
        else:
            return default

    @classmethod
    def create(cls, year_month, end_day, pageviews, url, package_name, 
               owner_org_id, publisher_id):
        '''
        Helper function to create an dge_ga_package and save it.
        '''
        pd = cls(year_month=year_month, end_day=end_day, 
                 pageviews=pageviews, url=url, package_name=package_name, 
                 organization_id=organization_id, publisher_id=publisher_id)
        try:
            pd.save()
        except InvalidRequestError:
            Session.rollback()
            pd.save()
        finally:
            # No need to alert administrator so don't log as an error
            log_message = '''year_month=%s, end_day=%s, pageviews=%s, url=%s, 
                          package_name=%s, organization_id=%s, publisher_id=%s''' % \
                          (year_month, end_day, str(pageviews), url, 
                          package_name, organization_id, publisher_id)
            log.debug(log_message)
            print log_message

class DgeGaResource(DgeGaDomainObject):
    '''
    A DgeGaResource contains information about a resource: 
    pageviews, date, package, organization and publisher.
    '''
    def __init__(self, **kwargs):
        for k,v in kwargs.items():
            setattr(self, k, v)

    def __repr__(self):
        return '''<DgeGaResource year_month=%s, end_day=%s, total_events=%s, 
                url=%s, package_url=%s, resource_name=%s, resource_id=%s, 
                package_name=%s, organization_id=%s, publisher_id=%s>''' % \
               (self.year_month, self.str(end_day), self.total_events, self.url, 
                self.package_url, self.resource_name, self.resource_id, self.package_name, 
                self.organization_id, self.publisher_id)

    def __str__(self):
        return self.__repr__().encode('ascii', 'ignore')

    @classmethod
    def get(cls, year_month, url, package_url, resource_id):
        '''Finds a single entity in the register.'''
        kwds = {'year_month': year_month, 
                'url': url, 
                'package_url': package_url, 
                'resource_id': resource_id}
        o = cls.filter(**kwds).first()
        if o:
            return o
        else:
            return default

    @classmethod
    def create(cls, year_month, end_day, total_events, url, package_url, resource_id, 
               package_name, organization_id, publisher_id):
        '''
        Helper function to create an dge_ga_resource and save it.
        '''
        pd = cls(year_month=year_month, end_day=end_day, 
                 total_events=total_events, url=url, package_url=package_url, 
                 resource_id=resource_id, package_name=package_name, 
                 organization_id=organization_id, publisher_id=publisher_id)
        try:
            pd.save()
        except InvalidRequestError:
            Session.rollback()
            pd.save()
        finally:
            # No need to alert administrator so don't log as an error
            log_message = '''year_month=%s, end_day=%s, total_events=%s, url=%s, 
                             package_url=%s, resource_id=%s, package_name=%s, 
                             organization_id=%s, publisher_id=%s
                          ''' % (year_month, str(end_day), str(total_events), 
                                 url, package_url, resource_id, package_name, 
                                 organization_id, publisher_id)
            log.debug(log_message)
            print log_message

class DgeGaVisit(DgeGaDomainObject):
    '''
    A DgeGaVisit contains information about visits to datos.gob.es and 
    visits to datos.gob.es sections.
    '''
    def __init__(self, **kwargs):
        for k,v in kwargs.items():
            setattr(self, k, v)

    def __repr__(self):
        return '''<DgeGaResource year_month=%s, end_day=%s, sessions=%s, key=%s, key_value=%s>''' % \
               (self.year_month, self.end_day, self.sessions, self.key, self.key.value)

    def __str__(self):
        return self.__repr__().encode('ascii', 'ignore')

    @classmethod
    def get(cls, year_month, key, key_value):
        '''Finds a single entity in the register.'''
        kwds = {'year_month': year_month, 
                'key': key, 
                'key_value': key_value}
        o = cls.filter(**kwds).first()
        if o:
            return o
        else:
            return default

    @classmethod
    def create(cls, year_month, end_day, sessions, key, key_value):
        '''
        Helper function to create an dge_ga_visit and save it.
        '''
        pd = cls(year_month=year_month, end_day=end_day, 
                 sessions=sessions, key=key, key_value=key_value)
        try:
            pd.save()
        except InvalidRequestError:
            Session.rollback()
            pd.save()
        finally:
            # No need to alert administrator so don't log as an error
            log_message = 'year_month=%s, end_day=%s, sessions=%s, key=%s, key_value=%s' % \
             (year_month, str(end_day), str(sessions), key, key_value) 
            log.debug(log_message)
            print log_message


dge_ga_package_table = Table(DGE_GA_PACKAGE_TABLE_NAME, metadata,
                          Column('year_month', types.UnicodeText, nullable = False),
                          Column('end_day', types.Integer, nullable = False),
                          Column('pageviews', types.Integer, nullable = False, server_default='0'),
                          Column('url', types.UnicodeText, nullable = False),
                          Column('package_name', types.UnicodeText, nullable = False, server_default=u''),
                          Column('organization_id', types.UnicodeText, nullable = True),
                          Column('publisher_id', types.UnicodeText, nullable = True),
                          PrimaryKeyConstraint('year_month', 'url', 'package_name'))
mapper(DgeGaPackage, dge_ga_package_table)


dge_ga_resource_table = Table(DGE_GA_RESOURCE_TABLE_NAME, metadata,
                          Column('year_month', types.UnicodeText, nullable = False),
                          Column('end_day', types.Integer, nullable = False),
                          Column('total_events', types.Integer, nullable = False, server_default='0'),
                          Column('url', types.UnicodeText, nullable = False),
                          Column('package_url', types.UnicodeText, nullable = False),
                          Column('resource_id', types.UnicodeText, nullable = False, server_default=u''),
                          Column('package_name', types.UnicodeText, nullable = True),
                          Column('organization_id', types.UnicodeText, nullable = True),
                          Column('publisher_id', types.UnicodeText, nullable = True),
                          PrimaryKeyConstraint('year_month', 'url', 'package_url', 'resource_id'))
mapper(DgeGaResource, dge_ga_resource_table)


dge_ga_visit_table = Table(DGE_GA_VISIT_TABLE_NAME, metadata,
                          Column('year_month', types.UnicodeText, nullable = False),
                          Column('end_day', types.Integer, nullable = False),
                          Column('sessions', types.Integer, nullable = False, server_default='0'),
                          Column('key', types.UnicodeText, nullable = False),
                          Column('key_value', types.UnicodeText, nullable = False, server_default=u''),
                          PrimaryKeyConstraint('year_month', 'key','key_value'))
mapper(DgeGaVisit, dge_ga_visit_table)

def init_tables():
    engine = model.meta.engine
    if (dge_ga_package_table not in metadata.sorted_tables and \
       dge_ga_resource_table not in metadata.sorted_tables and\
       dge_ga_visit_table not in metadata.sorted_tables) or \
       (not dge_ga_package_table.exists(model.meta.engine) and \
        not dge_ga_resource_table.exists(model.meta.engine) and \
        not dge_ga_visit_table.exists(model.meta.engine)):
        metadata.create_all(model.meta.engine)
        log.debug('All dge_ga_tables created')
        print 'All dge_ga_tables created'
        complete_historical_values_dge_ga_tables(DGE_GA_VISIT_TABLE_NAME)
    else:
        if not dge_ga_package_table.exists(model.meta.engine):
            dge_ga_package_table.create(model.meta.engine)
            log.debug('%s table created', DGE_GA_PACKAGE_TABLE_NAME)
            print '%s table created' % (DGE_GA_PACKAGE_TABLE_NAME)
        else:
            log.debug('%s table already exists', DGE_GA_PACKAGE_TABLE_NAME)
            print '%s table already exists' % (DGE_GA_PACKAGE_TABLE_NAME)

        if not dge_ga_resource_table.exists(model.meta.engine):
            dge_ga_resource_table.create(model.meta.engine);
            log.debug('%s table created', DGE_GA_RESOURCE_TABLE_NAME)
            print '%s table created' % (DGE_GA_RESOURCE_TABLE_NAME)
        else:
            log.debug('%s table already exists', DGE_GA_RESOURCE_TABLE_NAME)
            print '%s table already exists' % (DGE_GA_RESOURCE_TABLE_NAME)

        if not dge_ga_visit_table.exists(model.meta.engine):
            dge_ga_visit_table.create(model.meta.engine);
            log.debug('%s table created', DGE_GA_VISIT_TABLE_NAME)
            print '%s table created' % (DGE_GA_VISIT_TABLE_NAME)
            complete_historical_values_dge_ga_tables(DGE_GA_VISIT_TABLE_NAME)
        else:
            log.debug('%s table already exists', DGE_GA_VISIT_TABLE_NAME)
            print '%s table already exists' % (DGE_GA_VISIT_TABLE_NAME)

cached_tables = {}

def get_table(name):
    if name not in cached_tables:
        meta = MetaData()
        meta.reflect(bind=model.meta.engine)
        table = meta.tables[name]
        cached_tables[name] = table
    return cached_tables[name]

def complete_historical_values_dge_ga_tables(tablename=None):
    if tablename == DGE_GA_VISIT_TABLE_NAME:
        log.debug("Adding historical data in %s", tablename)
        print "Adding historical data in %s" % (tablename)
        DgeGaVisit.create(year_month='2011-11', end_day=30, sessions=3436, key='all', key_value='')
        DgeGaVisit.create(year_month='2011-12', end_day=31, sessions=2129, key='all', key_value='')
        DgeGaVisit.create(year_month='2012-01', end_day=31, sessions=4304, key='all', key_value='')
        DgeGaVisit.create(year_month='2012-02', end_day=29, sessions=4883, key='all', key_value='')
        DgeGaVisit.create(year_month='2012-03', end_day=31, sessions=4569, key='all', key_value='')
        DgeGaVisit.create(year_month='2012-04', end_day=30, sessions=4215, key='all', key_value='')
        DgeGaVisit.create(year_month='2012-05', end_day=31, sessions=5614, key='all', key_value='')
        DgeGaVisit.create(year_month='2012-06', end_day=30, sessions=9705, key='all', key_value='')
        DgeGaVisit.create(year_month='2012-07', end_day=31, sessions=6929, key='all', key_value='')
        DgeGaVisit.create(year_month='2012-08', end_day=31, sessions=4716, key='all', key_value='')
        DgeGaVisit.create(year_month='2012-09', end_day=30, sessions=6469, key='all', key_value='')
        DgeGaVisit.create(year_month='2012-10', end_day=31, sessions=10181, key='all', key_value='')
        DgeGaVisit.create(year_month='2012-11', end_day=30, sessions=9192, key='all', key_value='')
        DgeGaVisit.create(year_month='2012-12', end_day=31, sessions=7989, key='all', key_value='')
        DgeGaVisit.create(year_month='2013-01', end_day=31, sessions=8197, key='all', key_value='')
        DgeGaVisit.create(year_month='2013-02', end_day=28, sessions=8383, key='all', key_value='')
        DgeGaVisit.create(year_month='2013-03', end_day=31, sessions=8729, key='all', key_value='')
        DgeGaVisit.create(year_month='2013-04', end_day=30, sessions=12309, key='all', key_value='')
        DgeGaVisit.create(year_month='2013-05', end_day=31, sessions=12172, key='all', key_value='')
        DgeGaVisit.create(year_month='2013-06', end_day=30, sessions=11589, key='all', key_value='')
        DgeGaVisit.create(year_month='2013-07', end_day=31, sessions=11424, key='all', key_value='')
        DgeGaVisit.create(year_month='2013-08', end_day=31, sessions=8009, key='all', key_value='')
        DgeGaVisit.create(year_month='2013-09', end_day=30, sessions=11273, key='all', key_value='')
        DgeGaVisit.create(year_month='2013-10', end_day=31, sessions=13978, key='all', key_value='')
        DgeGaVisit.create(year_month='2013-11', end_day=30, sessions=14329, key='all', key_value='')
        DgeGaVisit.create(year_month='2013-12', end_day=31, sessions=12755, key='all', key_value='')
        DgeGaVisit.create(year_month='2014-01', end_day=31, sessions=16925, key='all', key_value='')
        DgeGaVisit.create(year_month='2014-02', end_day=28, sessions=15131, key='all', key_value='')
        DgeGaVisit.create(year_month='2014-03', end_day=31, sessions=17044, key='all', key_value='')
        DgeGaVisit.create(year_month='2014-04', end_day=30, sessions=15550, key='all', key_value='')
        DgeGaVisit.create(year_month='2014-05', end_day=31, sessions=17047, key='all', key_value='')
        DgeGaVisit.create(year_month='2014-06', end_day=30, sessions=14011, key='all', key_value='')
        DgeGaVisit.create(year_month='2014-07', end_day=31, sessions=15533, key='all', key_value='')
        DgeGaVisit.create(year_month='2014-08', end_day=31, sessions=11531, key='all', key_value='')
        DgeGaVisit.create(year_month='2014-09', end_day=30, sessions=18702, key='all', key_value='')
        DgeGaVisit.create(year_month='2014-10', end_day=31, sessions=30879, key='all', key_value='')
        DgeGaVisit.create(year_month='2014-11', end_day=30, sessions=30642, key='all', key_value='')
        DgeGaVisit.create(year_month='2014-12', end_day=31, sessions=33593, key='all', key_value='')
        DgeGaVisit.create(year_month='2015-01', end_day=31, sessions=31333, key='all', key_value='')
        DgeGaVisit.create(year_month='2015-02', end_day=28, sessions=33655, key='all', key_value='')
        DgeGaVisit.create(year_month='2015-03', end_day=31, sessions=38037, key='all', key_value='')
        DgeGaVisit.create(year_month='2015-04', end_day=30, sessions=36535, key='all', key_value='')
        DgeGaVisit.create(year_month='2015-05', end_day=31, sessions=43418, key='all', key_value='')
        DgeGaVisit.create(year_month='2015-06', end_day=30, sessions=41957, key='all', key_value='')
        DgeGaVisit.create(year_month='2015-07', end_day=31, sessions=32245, key='all', key_value='')
        DgeGaVisit.create(year_month='2015-08', end_day=31, sessions=17601, key='all', key_value='')
        DgeGaVisit.create(year_month='2015-09', end_day=30, sessions=23452, key='all', key_value='')
        DgeGaVisit.create(year_month='2015-10', end_day=31, sessions=35257, key='all', key_value='')
        DgeGaVisit.create(year_month='2015-11', end_day=30, sessions=37968, key='all', key_value='')
        DgeGaVisit.create(year_month='2015-12', end_day=31, sessions=34513, key='all', key_value='')
        DgeGaVisit.create(year_month='2016-01', end_day=31, sessions=37076, key='all', key_value='')
        DgeGaVisit.create(year_month='2016-02', end_day=29, sessions=40630, key='all', key_value='')
        DgeGaVisit.create(year_month='2016-03', end_day=31, sessions=41106, key='all', key_value='')
        DgeGaVisit.create(year_month='2016-04', end_day=30, sessions=43842, key='all', key_value='')
        DgeGaVisit.create(year_month='2016-05', end_day=31, sessions=47457, key='all', key_value='')
        DgeGaVisit.create(year_month='2016-06', end_day=30, sessions=40985, key='all', key_value='')
        DgeGaVisit.create(year_month='2016-07', end_day=31, sessions=33355, key='all', key_value='')
        DgeGaVisit.create(year_month='2016-08', end_day=31, sessions=30432, key='all', key_value='')
        DgeGaVisit.create(year_month='2016-09', end_day=30, sessions=37721, key='all', key_value='')
        DgeGaVisit.create(year_month='2016-10', end_day=31, sessions=42648, key='all', key_value='')
        DgeGaVisit.create(year_month='2016-11', end_day=30, sessions=44961, key='all', key_value='')
        DgeGaVisit.create(year_month='2016-12', end_day=31, sessions=23445, key='all', key_value='')
        DgeGaVisit.create(year_month='2017-01', end_day=31, sessions=23164, key='all', key_value='')
        DgeGaVisit.create(year_month='2017-02', end_day=28, sessions=27608, key='all', key_value='')
        log.debug("Historical data added in %s", tablename)
        print "Historical data added in %s" % (tablename)


class Identifier:
    
    def __init__(self):
        from download_analytics import DownloadAnalytics
        Identifier.package_re = re.compile('^' + DownloadAnalytics.PACKAGE_URL_REGEX)

    def get_package_ref(self, url):
        package_ref = None
        package_match = Identifier.package_re.match(url)
        if package_match:
            index = url.find('/catalogo/')
            if index > -1:
                s_url = url[index:].split('/')
                if len(s_url) >= 3:
                    package_ref = s_url[2]
        return package_ref

    def get_package_information(self, url):
        # Example urls:
        #       /catalogo/l01280066-cursos-infantiles
        #       /catalogo/d7fc8964-e9da-42ab-8385-cbac70479f4b
        package_ref = self.get_package_ref(url)
#         print 'Getting package for package_ref %s' % package_ref if package_ref else ''
        if package_ref:
            package = model.Package.get(package_ref)
            if package:
                org = None
                pub = None
                if hasattr(package, 'owner_org'):
                    org = model.Group.get(package.owner_org)
                if package.extras:
                    pub_id = package.extras.get('publisher', None)
                    if pub_id and org and pub_id == org.id:
                        pub = org
                    else:
                        pub = model.Group.get(pub_id)
                return package.name, (org.id if org else None), \
                       (pub.id if pub else None)
            else:
                #print 'No package found'
                return None, None, None
        return None, None, None

    def get_resource_information(self, resource_url, package_url):
        package_ref = self.get_package_ref(package_url)
#         print 'Getting resource for resource_url %s and package_ref %s' % (
#                 resource_url if resource_url else '', 
#                 package_ref if package_ref else '')
        if package_ref:
            package = model.Package.get(package_ref)
            if package:
                org = None
                pub = None
                if hasattr(package, 'owner_org'):
                    org = model.Group.get(package.owner_org)
                if package.extras:
                    pub_id = package.extras.get('publisher', None)
                    if pub_id and org and pub_id == org.id:
                        pub = org
                    else:
                        pub = model.Group.get(pub_id)
                resources = package.resources
                if resources:
                    resource_urls = [resource_url]
                    res_url = None
                    try:
                        res_url = urllib.unquote_plus(resource_url)
                        resource_urls.append(res_url)
                    except:
                        pass
                    try:
                        resource_urls.append(resource_url.encode('latin-1').decode('utf-8'))
                    except:
                        pass
                    try:
                        if res_url:
                            resource_urls.append(res_url.encode('latin-1').decode('utf-8'))
                    except:
                        pass
                    
                    if resource_url.endswith('/'):
                        res_url_1 = resource_url[:-1]
                        resource_urls.append(res_url_1)
                        res_url_2 = None
                        try:
                            res_url_2 = urllib.unquote_plus(res_url_1)
                            resource_urls.append(res_url_2)
                        except:
                            pass
                        try:
                            resource_urls.append(res_url_1.encode('latin-1').decode('utf-8'))
                        except:
                            pass
                        try:
                            resource_urls.append(res_url_2.encode('latin-1').decode('utf-8'))
                        except:
                            pass

                    for resource in resources:
                        if resource.url in resource_urls:
                            return resource.id, package.name, \
                                   (org.id if org else None), \
                                   (pub.id if pub else None)
                #print 'No resource found' 
                return None, package.name, (org.id if org else None), \
                       (pub.id if pub else None)
            else:
                #print 'No package found'
                return None, None, None, None
        return None, None, None, None

def delete(period_name):
    '''
    Deletes table data for the specified period, or specify 'all'
    for all periods.
    '''
    for object_type in (DgeGaPackage, DgeGaResource, DgeGaVisit):
        q = model.Session.query(object_type)
        if period_name != 'All':
            q = q.filter_by(period_name=period_name)
        q.delete()
    model.repo.commit_and_remove()

def pre_update_dge_ga_package_stats(period_name):
    q = model.Session.query(DgeGaPackage).\
        filter(DgeGaPackage.year_month==period_name)
    log.debug("Deleting %d '%s' %s records" % (q.count(), period_name, DGE_GA_PACKAGE_TABLE_NAME))
    print ("Deleting %d '%s' %s records" % (q.count(), period_name, DGE_GA_PACKAGE_TABLE_NAME))
    q.delete()

    model.Session.flush()
    model.Session.commit()
    model.repo.commit_and_remove()
    log.debug('...done')
    print '...done'

def pre_update_dge_ga_resource_stats(period_name):
    q = model.Session.query(DgeGaResource).\
        filter(DgeGaResource.year_month==period_name)
    log.debug("Deleting %d '%s' %s records" % (q.count(), period_name, DGE_GA_RESOURCE_TABLE_NAME))
    print ("Deleting %d '%s' %s records" % (q.count(), period_name, DGE_GA_RESOURCE_TABLE_NAME))
    q.delete()

    model.Session.flush()
    model.Session.commit()
    model.repo.commit_and_remove()
    log.debug('...done')
    print '...done'

def pre_update_dge_ga_visit_stats(period_name):
    q = model.Session.query(DgeGaVisit).\
        filter(DgeGaVisit.year_month==period_name)
    log.debug("Deleting %d '%s' %s records" % (q.count(), period_name, DGE_GA_VISIT_TABLE_NAME))
    print ("Deleting %d '%s' %s records" % (q.count(), period_name, DGE_GA_VISIT_TABLE_NAME))
    q.delete()

    model.Session.flush()
    model.Session.commit()
    model.repo.commit_and_remove()
    log.debug('...done')
    print '...done'

def _get_previous_dge_ga_package_stats(url):
    pack_name = None
    org_id = None
    pub_id = None
    url = url.replace("'","''")
    if url:
        try:
            query = '''select distinct package_name, organization_id, publisher_id
                       from dge_ga_packages
                       where url like '{p0}'
                       and package_name != '' 
                       and organization_id != '' and organization_id is not null 
                       and publisher_id != '' and publisher_id is not null
                       and year_month not like 'All';'''.format(p0=url)

            result = model.Session.execute(query)
            row_count = 0
            if result:
                for row in result:
                    row_count = row_count + 1
                    if row_count == 1:
                        pack_name = row[0]
                        org_id = row[1]
                        pub_id = row[2]

                    if row_count > 2:
                        print ("WARNING url {} -> Found {} distinct values for (package_name, organization_id, publisher_id)".format(url, row_count))
                    if row_count == 0:
                        print ("WARNING url {} -> Not found values for (package_name, organization_id, publisher_id)".format(url))
        except Exception as e:
            print "Exception {}"
            print str(e)
            try:
                print "EXCEPTION res_url {}, pack_url {} -> Exception {}".format(resource_url, package_url, str(e))
            except:
                print "Exception {}".format(str(e))

    return pack_name, org_id, pub_id

def _get_previous_dge_ga_resource_stats(resource_url, package_url):
    res_id = None
    pack_name = None
    org_id = None
    pub_id = None
    if resource_url and package_url:
        try:
            try:
                resource_url = unicode(resource_url).encode('utf-8')
            except Exception as ex:
                print 'exception coding... {}'.format(str(ex))
                pass
            items = set (
                (result[0], result[1], result[2], result[3]) for result in model.Session.query(DgeGaResource.resource_id, DgeGaResource.package_name, DgeGaResource.organization_id, DgeGaResource.publisher_id).\
                filter(DgeGaResource.package_url==package_url).\
                filter(DgeGaResource.url==resource_url).\
                filter(DgeGaResource.year_month!='All').\
                filter(DgeGaResource.resource_id!=None).\
                filter(DgeGaResource.package_name!='All').\
                filter(DgeGaResource.package_name!=None).\
                filter(DgeGaResource.organization_id!='').\
                filter(DgeGaResource.organization_id!=None).\
                filter(DgeGaResource.publisher_id!='').\
                filter(DgeGaResource.publisher_id!=None).\
                all())
            row_count = 0
            if items:
                for row in items:
                    row_count = row_count + 1
                    if row_count == 1:
                        res_id = row[0]
                        pack_name = row[1]
                        org_id = row[2]
                        pub_id = row[3]
                if row_count > 2:
                    print ("WARNING res_url {}, pack_url {} -> Found {} distinct values for (res_id, package_name, organization_id, publisher_id)".format(resource_url, package_url, row_count))
                if row_count == 0:
                    print ("WARNING res_url {}, pack_url {} -> Not found values for (res_id, package_name, organization_id, publisher_id)".format(resource_url, package_url))
        except Exception as e:
            try:
                print "EXCEPTION res_url {}, pack_url {} -> Exception {}".format(resource_url, package_url, str(e))
            except:
                print str(e)

    return res_id, pack_name, org_id, pub_id

def update_dge_ga_package_stats(period_name, period_complete_day, url_data,
                     print_progress=False):
    '''
    Given a list of urls and number of hits for each during a given period,
    stores them in DgeGaPackage under the period.
    '''
    print "Updating dge_ga_package..."
    progress_total = len(url_data)
    progress_count = 0
    if print_progress:
        progress_bar = GaProgressBar(progress_total)
    urls_in_dge_ga_package_this_period = set(
        result[0] for result in model.Session.query(DgeGaPackage.url)
                                     .filter(DgeGaPackage.year_month==period_name)
                                     .all())
    processed_urls = []
    #dict with key:<url> and value: (<package_name>, <org_id>, <pub_id>)
    processed_urls_dict = {} 

    identifier = Identifier()
    for url, views in url_data:
        progress_count += 1
        if print_progress:
            progress_bar.update(progress_count)

        if url in urls_in_dge_ga_package_this_period:
            item = model.Session.query(DgeGaPackage).\
                filter(DgeGaPackage.year_month==period_name).\
                filter(DgeGaPackage.url==url).first()
            item.pageviews = int(item.pageviews or 0) + int(views or 0)
            model.Session.add(item)
        else:
            pack_name, org_id, pub_id = identifier.get_package_information(url)

            #Only if package not found, possible purged dataset, check previous stats
            if pack_name is None:
                #get persisted data from other periods
                if url not in processed_urls:
                    pack_name, org_id, pub_id = _get_previous_dge_ga_package_stats(url)
                    processed_urls.append(url)
                    processed_urls_dict[url] = (pack_name, org_id, pub_id)
                else:
                    url_dict = processed_urls_dict.get(url, None)
                    if url_dict:
                        pack_name = url_dict[0]
                        org_id = url_dict[1]
                        pub_id = url_dict[2]

            if pack_name is None:
                pack_name = u''
            values = {
                      'year_month': period_name,
                      'end_day': period_complete_day,
                      'url': url,
                      'pageviews': views,
                      'package_name': pack_name,
                      'organization_id': org_id,
                      'publisher_id': pub_id
                      }
            model.Session.add(DgeGaPackage(**values))
            urls_in_dge_ga_package_this_period.add(url)
        model.Session.commit()
    print "...Updated dge_ga_package"

def update_dge_ga_resource_stats(period_name, period_complete_day, url_data,
                     print_progress=False):
    '''
    Given a list of urls and number of hits for each during a given period,
    stores them in DgeGaResource under the period.
    '''
    print "Updating dge_ga_resource..."
    progress_total = len(url_data)
    progress_count = 0
    if print_progress:
        progress_bar = GaProgressBar(progress_total)
    urls_in_dge_ga_resource_this_period = set(
        (result[0], result[1]) for result in model.Session.query(DgeGaResource.url, DgeGaResource.package_url)
                                     .filter(DgeGaResource.year_month==period_name)
                                     .all())
    identifier = Identifier()
    processed_urls = []
    #dict with key:<resource_url-package_url> and value: (<res_id>, <package_name>, <org_id>, <pub_id>)
    processed_urls_dict = {} 
    for resource_url, package_url, events in url_data:
        progress_count += 1
        if print_progress:
            progress_bar.update(progress_count)

            if (resource_url, package_url) in urls_in_dge_ga_resource_this_period:
                item = model.Session.query(DgeGaResource).\
                                 filter(DgeGaResource.year_month==period_name).\
                                 filter(DgeGaResource.url==resource_url).\
                                 filter(DgeGaResource.package_url==package_url).first()
                item.total_events = int(item.total_events or 0) + int(events or 0)
                model.Session.add(item)
            else:
                res_id, pack_name, org_id, pub_id = identifier.get_resource_information(resource_url, package_url)

                #Only if package not found, possible purged dataset, check previous stats
                if pack_name is None or res_id is None:
                    #get persisted data from other periods
                    url = '%s-%s'%(resource_url, package_url)
                    if url not in processed_urls:
                        res_id, pack_name, org_id, pub_id = _get_previous_dge_ga_resource_stats(resource_url, package_url)
                        processed_urls.append(url)
                        processed_urls_dict[url] = (res_id, pack_name, org_id, pub_id)
                    else:
                        url_dict = processed_urls_dict.get(url, None)
                        if url_dict:
                            res_id = url_dict[0]
                            pack_name = url_dict[1]
                            org_id = url_dict[2]
                            pub_id = url_dict[3]

                if res_id is None:
                    res_id = u''

                values = {
                          'year_month': period_name,
                          'end_day': period_complete_day,
                          'url': resource_url,
                          'package_url': package_url,
                          'total_events': events,
                          'resource_id' : res_id,
                          'package_name': pack_name,
                          'organization_id': org_id,
                          'publisher_id': pub_id
                         }
                model.Session.add(DgeGaResource(**values))
                urls_in_dge_ga_resource_this_period.add((resource_url, package_url))
            model.Session.commit()
    print "... Updated dge_ga_resource"

def update_dge_ga_visit_stats(period_name, period_complete_day, data,
                     print_progress=False):
    '''
    Given a list of sections and number of sessions for each during a given period,
    stores them in DgeGaVisit under the period.
    '''
    print "Updating dge_ga_visits..."
    progress_total = len(data)
    progress_count = 0
    if print_progress:
        progress_bar = GaProgressBar(progress_total)
    for key, key_value, sessions in data:
        progress_count += 1
        if print_progress:
            progress_bar.update(progress_count)
        values = {
                  'year_month': period_name,
                  'end_day': period_complete_day,
                  'sessions': sessions,
                  'key' : key,
                  'key_value': key_value
                 }
        model.Session.add(DgeGaVisit(**values))
        model.Session.commit()
    print "... Updated dge_ga_visits"

def post_update_dge_ga_package_stats():

    """ Check the distinct url field in dge_ga_package and make sure
        it has an All record.  If not then create one.

        After running this then every URL should have an All
        record regardless of whether the URL has an entry for
        the month being currently processed.
    """
    q = model.Session.query(DgeGaPackage).\
        filter_by(year_month='All')
    log.debug("Deleting %d 'All' dge_ga_package records..." % q.count())
    print ("Deleting %d 'All' dge_ga_package records..." % q.count())
    q.delete()

    # For dataset URLs:
    # Calculate the total views/visits for All months
    log.debug('Calculating DgeGaPackage "All" records')
    print 'Calculating DgeGaPackage "All" records'
    query = '''select package_name, organization_id, publisher_id, sum(pageviews::int)
               from dge_ga_packages
               where package_name != ''
               and organization_id != ''
               and publisher_id != ''
               group by package_name, organization_id, publisher_id
               order by sum(pageviews::int) desc
               '''
    res = model.Session.execute(query).fetchall()

    # Get datasets with more than a organizaton
    query = '''select t.package_name from (select p.package_name, 
               count(p.organization_id) orgs from (select distinct 
               package_name, organization_id, publisher_id from 
               dge_ga_packages where package_name != '' and 
               organization_id != '' and publisher_id != '') p 
               group by p.package_name) t where orgs > 1;
               '''
    res2 = model.Session.execute(query).fetchall()
    
    duplicated = {}
    for package_name, org_id, pub_id, views in res:
        if not any(d['package_name'] == package_name for d in res2):
            values = {
                      'year_month': "All",
                      'end_day': 0,
                      'url': '',
                      'pageviews': views,
                      'package_name': package_name,
                      'organization_id': org_id,
                      'publisher_id': pub_id,
                      }
            model.Session.add(DgeGaPackage(**values))
            model.Session.commit()
        else:
            if package_name in duplicated:
                duplicated[package_name] = duplicated[package_name] + views
            else:
                duplicated[package_name] = views

    # Insert duplicated datasets
    for key in duplicated:
        query = '''select organization_id, publisher_id from dge_ga_packages 
                 where package_name = '%s'
                 and lower(year_month) != 'all' order by year_month desc limit 1;'''
        res3 = model.Session.execute(query % key).fetchall()
        if len(res3) > 0:
            values = {
                    'year_month': "All",
                    'end_day': 0,
                    'url': '',
                    'pageviews': duplicated[key],
                    'package_name': key,
                    'organization_id': res3[0][0],
                    'publisher_id': res3[0][1],
                }
            model.Session.add(DgeGaPackage(**values))
            model.Session.commit()

    log.debug('... Created dge_ga_package "All" records')
    print '... Created dge_ga_package "All" records'

def post_update_dge_ga_resource_stats():

    """ Check the distinct url field in dge_ga_resource and make sure
        it has an All record.  If not then create one.

        After running this then every URL should have an All
        record regardless of whether the URL has an entry for
        the month being currently processed.
    """
    init = datetime.datetime.now()
    q = model.Session.query(DgeGaResource).\
        filter_by(year_month='All')
    log.debug("Deleting %d 'All' dge_ga_resource records..." % q.count())
    print("Deleting %d 'All' dge_ga_resource records..." % q.count())
    q.delete()

    # For resource URLs:
    # Calculate the total events for All months
    log.debug('Calculating DgeGaResource "All" records')
    print ('Calculating DgeGaResource "All" records')
    '''SDA-890
        Se modifica la query para obtener estadisticas 'All' incluyendo la url del recurso
        ya que la información que se esta dando sobre los datos de descargas es por url de distribucion.
        No se tiene en cuenta la url del package, ya que se ha podido acceder a la
        descarga desde el conjunto de datos /catalogo/<name_conjunto_datos)
        o desde la pagina de visualización de la distribucion /catalogo/<name_conjunto_datos/resource/<id_resource)
        La package del url se construira a partir del package_name para que no se tengan en cuenta
        desde donde se hace la visita
    '''
    query = '''select url, resource_id, concat('/catalogo/', package_name) as package_url, package_name,
               organization_id, publisher_id, sum(total_events::int),
               concat(resource_id, concat('|', concat(package_name, concat('|' , url)))) as res_id
               from dge_ga_resources
               where resource_id != '' and package_name != ''
               and organization_id != '' and publisher_id != ''
               and lower(year_month) != 'all'
               group by url, resource_id, package_name, organization_id, publisher_id
               order by sum(total_events::int) desc
               '''
    res = model.Session.execute(query).fetchall()

    # Get datasets with more than a organizaton
    query = '''select concat(t.resource_id, concat('|', concat(t.package_name, concat('|' ,t.url)))) as res_id,
               t.resource_id, t.url, t.package_name, t.orgs from (select p.resource_id, p.url,
               p.package_name, count(p.organization_id) orgs from (select distinct
               resource_id, url, package_name,  organization_id, publisher_id from
               dge_ga_resources where resource_id != '' and
               organization_id != '' and publisher_id != '' and lower(year_month) != 'all') p
               group by p.resource_id, p.url, p.package_name) t where orgs > 1;
               '''
    res2 = model.Session.execute(query).fetchall()

    duplicated = {}
    deleted_resources = []
    for url, resource_id, package_url, package_name, org_id, pub_id, events, res_id in res:
        if not any(d['res_id'] == res_id for d in res2):
            values = {
                'year_month': "All",
                'end_day': 0,
                'url': url,
                'package_url': package_url,
                'total_events': events,
                'resource_id': resource_id,
                'package_name': package_name,
                'organization_id': org_id,
                'publisher_id': pub_id,
            }
            model.Session.add(DgeGaResource(**values))
            model.Session.commit()
        else:
            if resource_id in duplicated:
                duplicated[res_id] = duplicated[res_id] + events
            else:
                duplicated[res_id] = events

    # Insert duplicated resources
    for key in duplicated:
        query = '''select organization_id, publisher_id, package_name,
                 concat('/catalogo/', package_name) as packageurl, resource_id, url
                 from dge_ga_resources
                 where concat(resource_id, concat('|', concat(package_name, concat('|' ,url)))) = '%s'
                 and lower(year_month) != 'all' order by year_month desc limit 1;'''
        res3 = model.Session.execute(query % key).fetchall()
        if len(res3) > 0:
            values = {
                'year_month': "All",
                'end_day': 0,
                'url': res3[0][5],
                'package_url': res3[0][3],
                'total_events': duplicated[key],
                'resource_id': res[0][4],
                'package_name': res3[0][2],
                'organization_id': res3[0][0],
                'publisher_id': res3[0][1],
            }
            model.Session.add(DgeGaResource(**values))
            model.Session.commit()

    end = datetime.datetime.now()
    log.debug("... Created 'All' dge_ga_resource records in %s milliseconds" % (
        (end-init).total_seconds()*1000))
    print("... Created 'All' dge_ga_resource records in %s milliseconds" %
          ((end-init).total_seconds()*1000))
