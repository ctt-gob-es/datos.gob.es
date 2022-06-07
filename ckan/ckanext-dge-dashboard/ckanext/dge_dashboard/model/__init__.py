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

import logging
import datetime
import uuid

from sqlalchemy import event
from sqlalchemy import distinct
from sqlalchemy import Table
from sqlalchemy import Column
from sqlalchemy import ForeignKey
from sqlalchemy import types
from sqlalchemy import Index
from sqlalchemy import PrimaryKeyConstraint
from sqlalchemy.engine.reflection import Inspector
from sqlalchemy.orm import backref, relation
from sqlalchemy.exc import InvalidRequestError

from ckan import model
from ckan import logic
from ckan.model.meta import metadata,  mapper, Session
from ckan.model.types import make_uuid
from ckan.model.domain_object import DomainObject
from ckan.model.group import Group
from ckan.lib.munge import munge_title_to_name

log = logging.getLogger(__name__)


DGE_DASHBOARD_PUBLISHED_DATASETS_TABLE_NAME = 'dge_dashboard_published_datasets'
DGE_DASHBOARD_PUBLISHERS_TABLE_NAME = 'dge_dashboard_publishers'
DGE_DASHBOARD_DRUPAL_CONTENTS_TABLE_NAME = 'dge_dashboard_drupal_contents'

__all__ = [
    'DgeDashboardPublishedDataset', DGE_DASHBOARD_PUBLISHED_DATASETS_TABLE_NAME,
    'DgeDashboardPublisher', DGE_DASHBOARD_PUBLISHERS_TABLE_NAME,
    'DgeDashboardDrupalContent', DGE_DASHBOARD_DRUPAL_CONTENTS_TABLE_NAME
]

dge_dashboard_published_datasets_table = None
dge_dashboard_publishers_table = None
dge_dashboard_drupal_contents_table = None

def setup():

    if dge_dashboard_published_datasets_table is None or \
       dge_dashboard_publishers_table is None or \
       dge_dashboard_drupal_contents_table:
        define_dge_dashboard_tables()
        log.debug('dge_dashboard tables defined in memory')

    if not model.package_table.exists():
        log.debug('dge_dashboard table creation deferred')
        return

    if not dge_dashboard_published_datasets_table.exists():
        # Create each table individually rather than
        # using metadata.create_all()
        dge_dashboard_published_datasets_table.create()
        log.debug('%s table created', DGE_DASHBOARD_PUBLISHED_DATASETS_TABLE_NAME)
        #Complete historical values
        complete_historical_values_dge_dashboard_tables(DGE_DASHBOARD_PUBLISHED_DATASETS_TABLE_NAME)
        log.debug('%s table updated with historical data', DGE_DASHBOARD_PUBLISHED_DATASETS_TABLE_NAME)

    if not dge_dashboard_publishers_table.exists():
        # Create each table individually rather than
        # using metadata.create_all()
        dge_dashboard_publishers_table.create()
        log.debug('%s table created', DGE_DASHBOARD_PUBLISHERS_TABLE_NAME)

    if not dge_dashboard_drupal_contents_table.exists():
        # Create each table individually rather than
        # using metadata.create_all()
        dge_dashboard_drupal_contents_table.create()
        log.debug('%s table created', DGE_DASHBOARD_DRUPAL_CONTENTS_TABLE_NAME)
        #Complete historical values
        complete_historical_values_dge_dashboard_tables(DGE_DASHBOARD_DRUPAL_CONTENTS_TABLE_NAME)
        log.debug('%s table updated with historical data', DGE_DASHBOARD_DRUPAL_CONTENTS_TABLE_NAME)

    

class DgeDashboardError(Exception):
    pass

class DgeDashboardDomainObject(DomainObject):
    '''Convenience methods for searching objects
    '''

    @classmethod
    def filter(cls, **kwds):
        query = Session.query(cls).autoflush(False)
        return query.filter_by(**kwds)


class DgeDashboardPublishedDataset(DgeDashboardDomainObject):
    '''A Dge Dashboard Published Dataset is essentially a year-month,
       an organization_id and a value of published datasets by these
       organization until these year-month.
    '''
    def __repr__(self):
        return '<DgeDashboardPublishedDataset year-month=%s key=%s key_value=%s num_datasets=%s>' % \
               (self.yearMonth, self.key, self.key_value, self.num_datasets)

    def __str__(self):
        return self.__repr__().encode('ascii', 'ignore')

    @classmethod
    def get(cls, year_month, key_value):
        '''Finds a single entity in the register.'''
        kwds = {'year_month': year_month, 
                'key_value': key_value}
        o = cls.filter(**kwds).first()
        if o:
            return o
        else:
            return default

    @classmethod
    def create(cls, year_month, key, key_value='', num_datasets=0):
        '''
        Helper function to create an dge_dashboard_published_dataset and save it.
        '''
        pd = cls(year_month=year_month, key=key, key_value=key_value, num_datasets=num_datasets)
        try:
            pd.save()
        except InvalidRequestError:
            Session.rollback()
            pd.save()
        finally:
            # No need to alert administrator so don't log as an error
            log_message = 'year_month {0}, key {1}, key_value {2}, num_datasets {3}'.format(year_month, key, key_value, num_datasets)
            log.debug(log_message)

class DgeDashboardPublisher(DgeDashboardDomainObject):
    '''A Dge Dashboard Publisher is essentially a year-month,
       number of harvester publisher (publishers with published dataset until these year-month through harvester),
       number of manual loading publisher (publishers with published dataset until these year-month through manual load).
    '''
    def __repr__(self):
        return '<DgeDashboardPublisher year-month=%s harvester_publishers=%s manual_loading_publishers=%s>' % \
               (self.yearMonth, self.harvester_publishers, self.manual_loading_publishers)

    def __str__(self):
        return self.__repr__().encode('ascii', 'ignore')

    @classmethod
    def get(cls, year_month):
        '''Finds a single entity in the register.'''
        kwds = {'year_month': year_month}
        o = cls.filter(**kwds).first()
        if o:
            return o
        else:
            return default

    @classmethod
    def create(cls, year_month, harvester_publishers=0, manual_loading_publishers=0):
        '''
        Helper function to create an dge_dashboard_publisher and save it.
        '''
        pd = cls(year_month=year_month, harvester_publishers=harvester_publishers, manual_loading_publishers=manual_loading_publishers)
        try:
            pd.save()
        except InvalidRequestError:
            Session.rollback()
            pd.save()
        finally:
            # No need to alert administrator so don't log as an error
            log_message = 'year_month {0}, harvester_publishers {1}, manual_loading_publishers {2}'.format(year_month, harvester_publishers, manual_loading_publishers)
            log.debug(log_message)

class DgeDashboardDrupalContent(DgeDashboardDomainObject):
    '''A Dge Dashboard Drupal Content is essentially a year-month,
       a drupal_content_type, a key and its value and a value of published contents by these
       key, key_value until these year-month.
    '''
    def __repr__(self):
        return '<DgeDashboardDrupalContent year-month=%s content_type=%s key=%s key_value=%s num_contents=%s>' % \
               (self.yearMonth, self.content_type, self.key, self.key_value, self.num_datasets)

    def __str__(self):
        return self.__repr__().encode('ascii', 'ignore')

    @classmethod
    def get(cls, year_month, content_type, key_value):
        '''Finds a single entity in the register.'''
        kwds = {'year_month': year_month, 
                'content_type': content_type,
                'key_value': key_value}
        o = cls.filter(**kwds).first()
        if o:
            return o
        else:
            return default

    @classmethod
    def create(cls, year_month, content_type, key, key_value='', num_contents=0):
        '''
        Helper function to create an dge_dashboard_drupal_content and save it.
        '''
        pd = cls(year_month=year_month, content_type=content_type, key=key, key_value=key_value, num_contents=num_contents)
        try:
            pd.save()
        except InvalidRequestError:
            Session.rollback()
            pd.save()
        finally:
            # No need to alert administrator so don't log as an error
            log_message = 'year_month {0}, content_type {1}, key {2}, key_value {3}, num_contents {4}'.format(year_month, content_type, key, key_value, num_contents)
            log.debug(log_message)


def define_dge_dashboard_tables():

    global dge_dashboard_published_datasets_table
    dge_dashboard_published_datasets_table = Table(DGE_DASHBOARD_PUBLISHED_DATASETS_TABLE_NAME, metadata,
        Column('year_month', types.UnicodeText, nullable=False),
        Column('key', types.UnicodeText, nullable=False),
        Column('key_value', types.UnicodeText, nullable=False),
        Column('num_datasets', types.Integer, server_default='0'),
        PrimaryKeyConstraint('year_month', 'key_value')
    )
    mapper(
        DgeDashboardPublishedDataset,
        dge_dashboard_published_datasets_table,
    )


    global dge_dashboard_publishers_table
    dge_dashboard_publishers_table = Table(DGE_DASHBOARD_PUBLISHERS_TABLE_NAME, metadata,
        Column('year_month', types.UnicodeText, nullable=False),
        Column('harvester_publishers', types.Integer, server_default='0'),
        Column('manual_loading_publishers', types.Integer, server_default='0'),
        PrimaryKeyConstraint('year_month')
    )
    mapper(
        DgeDashboardPublisher,
        dge_dashboard_publishers_table,
    )


    global dge_dashboard_drupal_contents_table
    dge_dashboard_drupal_contents_table = Table(DGE_DASHBOARD_DRUPAL_CONTENTS_TABLE_NAME, metadata,
        Column('year_month', types.UnicodeText, nullable=False),
        Column('content_type', types.UnicodeText, nullable=False),
        Column('key', types.UnicodeText, nullable=False),
        Column('key_value', types.UnicodeText, nullable=False),
        Column('num_contents', types.Integer, server_default='0'),
        PrimaryKeyConstraint('year_month', 'content_type', 'key_value')
    )
    mapper(
        DgeDashboardDrupalContent,
        dge_dashboard_drupal_contents_table,
    )

def complete_historical_values_dge_dashboard_tables(tablename=None):
    if tablename == DGE_DASHBOARD_PUBLISHED_DATASETS_TABLE_NAME:
        log.debug("Adding historical data in %s", tablename)
        DgeDashboardPublishedDataset.create(year_month='2011-12', key='total', num_datasets= 443);
        DgeDashboardPublishedDataset.create(year_month='2012-03', key='total', num_datasets= 443);
        DgeDashboardPublishedDataset.create(year_month='2012-06', key='total', num_datasets= 458);
        DgeDashboardPublishedDataset.create(year_month='2012-09', key='total', num_datasets= 466);
        DgeDashboardPublishedDataset.create(year_month='2012-12', key='total', num_datasets= 480);
        DgeDashboardPublishedDataset.create(year_month='2013-03', key='total', num_datasets= 558);
        DgeDashboardPublishedDataset.create(year_month='2013-06', key='total', num_datasets= 738);
        DgeDashboardPublishedDataset.create(year_month='2013-09', key='total', num_datasets= 981);
        DgeDashboardPublishedDataset.create(year_month='2013-12', key='total', num_datasets= 1579);
        DgeDashboardPublishedDataset.create(year_month='2014-03', key='total', num_datasets= 1579);
        DgeDashboardPublishedDataset.create(year_month='2014-06', key='total', num_datasets= 2228);
        DgeDashboardPublishedDataset.create(year_month='2014-07', key='total', num_datasets= 2228);
        DgeDashboardPublishedDataset.create(year_month='2014-08', key='total', num_datasets= 2635);
        DgeDashboardPublishedDataset.create(year_month='2014-09', key='total', num_datasets= 2330);
        DgeDashboardPublishedDataset.create(year_month='2014-10', key='total', num_datasets= 2534);
        DgeDashboardPublishedDataset.create(year_month='2014-11', key='total', num_datasets= 2635);
        DgeDashboardPublishedDataset.create(year_month='2014-12', key='total', num_datasets= 4410);
        DgeDashboardPublishedDataset.create(year_month='2015-01', key='total', num_datasets= 6736);
        DgeDashboardPublishedDataset.create(year_month='2015-02', key='total', num_datasets= 7649);
        DgeDashboardPublishedDataset.create(year_month='2015-03', key='total', num_datasets= 7870);
        DgeDashboardPublishedDataset.create(year_month='2015-04', key='total', num_datasets= 8270);
        DgeDashboardPublishedDataset.create(year_month='2015-05', key='total', num_datasets= 8404);
        DgeDashboardPublishedDataset.create(year_month='2015-06', key='total', num_datasets= 8503);
        DgeDashboardPublishedDataset.create(year_month='2015-07', key='total', num_datasets= 8746);
        DgeDashboardPublishedDataset.create(year_month='2015-08', key='total', num_datasets= 8760);
        DgeDashboardPublishedDataset.create(year_month='2015-09', key='total', num_datasets= 8818);
        DgeDashboardPublishedDataset.create(year_month='2015-10', key='total', num_datasets= 9005);
        DgeDashboardPublishedDataset.create(year_month='2015-11', key='total', num_datasets= 8860);
        DgeDashboardPublishedDataset.create(year_month='2015-12', key='total', num_datasets= 9003);
        DgeDashboardPublishedDataset.create(year_month='2016-01', key='total', num_datasets= 9033);
        DgeDashboardPublishedDataset.create(year_month='2016-02', key='total', num_datasets= 9253);
        DgeDashboardPublishedDataset.create(year_month='2016-03', key='total', num_datasets= 10363);
        DgeDashboardPublishedDataset.create(year_month='2016-04', key='total', num_datasets= 10784);
        DgeDashboardPublishedDataset.create(year_month='2016-05', key='total', num_datasets= 11103);
        DgeDashboardPublishedDataset.create(year_month='2016-06', key='total', num_datasets= 11117);
        DgeDashboardPublishedDataset.create(year_month='2016-07', key='total', num_datasets= 11426);
        DgeDashboardPublishedDataset.create(year_month='2016-08', key='total', num_datasets= 11817);
        DgeDashboardPublishedDataset.create(year_month='2016-09', key='total', num_datasets= 11813);
        DgeDashboardPublishedDataset.create(year_month='2016-10', key='total', num_datasets= 12036);
        DgeDashboardPublishedDataset.create(year_month='2016-11', key='total', num_datasets= 12148);
        log.debug("Historical data added in %s", tablename)
    elif tablename == DGE_DASHBOARD_DRUPAL_CONTENTS_TABLE_NAME:
        log.debug("Adding historical data in %s", tablename)
        DgeDashboardDrupalContent.create(year_month='2012-03', content_type='app', key='total', num_contents=  12);
        DgeDashboardDrupalContent.create(year_month='2012-06', content_type='app', key='total', num_contents=  12);
        DgeDashboardDrupalContent.create(year_month='2012-09', content_type='app', key='total', num_contents=  29);
        DgeDashboardDrupalContent.create(year_month='2012-12', content_type='app', key='total', num_contents=  39);
        DgeDashboardDrupalContent.create(year_month='2013-03', content_type='app', key='total', num_contents=  39);
        DgeDashboardDrupalContent.create(year_month='2013-06', content_type='app', key='total', num_contents=  39);
        DgeDashboardDrupalContent.create(year_month='2013-09', content_type='app', key='total', num_contents=  39);
        DgeDashboardDrupalContent.create(year_month='2013-12', content_type='app', key='total', num_contents=  69);
        DgeDashboardDrupalContent.create(year_month='2014-03', content_type='app', key='total', num_contents=  70);
        DgeDashboardDrupalContent.create(year_month='2014-06', content_type='app', key='total', num_contents=  80);
        DgeDashboardDrupalContent.create(year_month='2014-09', content_type='app', key='total', num_contents=  91);
        DgeDashboardDrupalContent.create(year_month='2014-12', content_type='app', key='total', num_contents=  97);
        DgeDashboardDrupalContent.create(year_month='2015-03', content_type='app', key='total', num_contents=  104);
        DgeDashboardDrupalContent.create(year_month='2015-04', content_type='app', key='total', num_contents=  107);
        DgeDashboardDrupalContent.create(year_month='2015-05', content_type='app', key='total', num_contents=  109);
        DgeDashboardDrupalContent.create(year_month='2015-06', content_type='app', key='total', num_contents=  115);
        DgeDashboardDrupalContent.create(year_month='2015-07', content_type='app', key='total', num_contents=  117);
        DgeDashboardDrupalContent.create(year_month='2015-08', content_type='app', key='total', num_contents=  120);
        DgeDashboardDrupalContent.create(year_month='2015-09', content_type='app', key='total', num_contents=  123);
        DgeDashboardDrupalContent.create(year_month='2015-10', content_type='app', key='total', num_contents=  125);
        DgeDashboardDrupalContent.create(year_month='2015-11', content_type='app', key='total', num_contents=  126);
        DgeDashboardDrupalContent.create(year_month='2015-12', content_type='app', key='total', num_contents=  136);
        DgeDashboardDrupalContent.create(year_month='2016-01', content_type='app', key='total', num_contents=  136);
        DgeDashboardDrupalContent.create(year_month='2016-02', content_type='app', key='total', num_contents=  141);
        DgeDashboardDrupalContent.create(year_month='2016-03', content_type='app', key='total', num_contents=  145);
        DgeDashboardDrupalContent.create(year_month='2016-04', content_type='app', key='total', num_contents=  148);
        DgeDashboardDrupalContent.create(year_month='2016-05', content_type='app', key='total', num_contents=  150);
        DgeDashboardDrupalContent.create(year_month='2016-06', content_type='app', key='total', num_contents=  156);
        DgeDashboardDrupalContent.create(year_month='2016-07', content_type='app', key='total', num_contents=  158);
        DgeDashboardDrupalContent.create(year_month='2016-08', content_type='app', key='total', num_contents=  164);
        DgeDashboardDrupalContent.create(year_month='2016-09', content_type='app', key='total', num_contents=  165);
        DgeDashboardDrupalContent.create(year_month='2016-10', content_type='app', key='total', num_contents=  172);
        DgeDashboardDrupalContent.create(year_month='2016-11', content_type='app', key='total', num_contents=  175);
        log.debug("Historical data added in %s", tablename)