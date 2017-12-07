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

'''API functions for updating tables in CKANEXT_DGE_DASHBOARD.'''

import hashlib
import json
import pprint
import logging
import datetime

from pylons import config
from sqlalchemy import and_, or_, create_engine

from ckan.lib.search.index import PackageSearchIndex
from ckan.plugins import PluginImplementations
from ckan.logic import get_action
from ckanext.harvest.interfaces import IHarvester
from ckan.lib.search.common import SearchIndexError, make_connection


from ckan.model import Package
from ckan import logic
from ckan.plugins import toolkit


from ckan.logic import NotFound, check_access

from ckanext.harvest.plugin import DATASET_TYPE_NAME
from ckanext.harvest.queue import get_gather_publisher, resubmit_jobs

from ckanext.harvest.model import HarvestSource, HarvestJob, HarvestObject
from ckanext.harvest.logic import HarvestJobExists
from ckanext.harvest.logic.dictization import harvest_job_dictize

from ckanext.harvest.logic.action.get import (
    harvest_source_show, harvest_job_list, _get_sources_for_user)
from _sqlite3 import IntegrityError

from pylons import config

log = logging.getLogger(__name__)

def dge_dashboard_update_published_datasets(context, data_dict):
    '''
    Update dge_dashboard_published_datasets table
    adding num total created datasets before given date param

    :param date: the creation date of datasets must be before this
    :type date: string
    
    :param import_date: year-month of creation date of datasets
    :type import_date: string
    
    :param num_resources: True only if calculate num_datasets by num_resources
    :type num_resources: boolean

    :param save: True only if update database, False if only print
    :type save: boolean.
    '''

    check_access('dge_dashboard_update_published_datasets', context, data_dict)

    date = data_dict.get('date')
    import_date = data_dict.get('import_date')
    num_resources = data_dict.get('num_resources', False)
    save = data_dict.get('save', False)

    model = context['model']
    results = []
    if num_resources == False:
        not_key = 'num_resources'
        log.debug("Getting total data ....")
        # total active, public dataset pusblished before than {p0} date
        sql = '''select count(*) from 
                (select h.* from (select ROW_NUMBER() OVER (PARTITION BY pr.continuity_id order by pr.revision_timestamp asc) as rn, * from package_revision pr 
                 where pr.revision_timestamp < '{p0}'::timestamp and pr.type like 'dataset') h where h.rn = 1 ) sc, 
                (select h.* from (select ROW_NUMBER() OVER (PARTITION BY pr.continuity_id order by pr.revision_timestamp desc) as rn, * from package_revision pr 
                 where pr.revision_timestamp < '{p0}'::timestamp and pr.type like 'dataset') h 
                 where h.rn = 1 and h.state like 'active'
                 and h.private = false and h.expired_timestamp >=  '{p0}'::timestamp) slu 
                 where sc.continuity_id = slu.continuity_id;'''.format(p0=date)
        result = model.Session.execute(sql)
        value = result.fetchone()[0]
        results.append((import_date, 'total', '', value))
        
        log.debug("Getting data by organization ....")
        # total active, public dataset pusblished before than {p0} date by organization_id
        sql = '''select count(*), slu.owner_org from 
                 (select pr.continuity_id, pr.owner_org, min(pr.revision_timestamp) 
                 from package_revision pr 
                 where pr.type like 'dataset' and pr.state like 'active' 
                 and pr.private = false
                 and pr.revision_timestamp < '{p0}'::timestamp
                 group by pr.continuity_id, pr.owner_org) sc,
                 (select pr.continuity_id, pr.owner_org, max(pr.revision_timestamp) 
                 from package_revision pr 
                 where pr.type like 'dataset' and pr.state like 'active' and pr.private = false
                 and pr.revision_timestamp < '{p0}'::timestamp
                 and expired_timestamp >=  '{p0}'::timestamp
                 group by pr.continuity_id, pr.owner_org) slu
                 where sc.continuity_id = slu.continuity_id
                 and sc.owner_org = slu.owner_org
                 group by slu.owner_org'''.format(p0=date)
        result = model.Session.execute(sql)
        for row in result:
            results.append((import_date, 'organization_id', row[1], row[0]))
    
        log.debug("Getting data by administration level ....")
        # total active, public dataset pusblished before than {p0} date by administration level
        sql = '''select count(*), substring(dir3.value, 0, 2) as adm from 
                 (select h.* from (select ROW_NUMBER() OVER (PARTITION BY pr.continuity_id order by pr.revision_timestamp asc) as rn, * from package_revision pr where pr.revision_timestamp < '{p0}'::timestamp and pr.type like 'dataset') h 
                 where h.rn = 1 ) sc, 
                 (select h.* from (select ROW_NUMBER() OVER (PARTITION BY pr.continuity_id  order by pr.revision_timestamp desc) as rn, * from package_revision pr where pr.revision_timestamp < '{p0}'::timestamp and pr.type like 'dataset') h 
                 where h.rn = 1  and h.state like 'active'  and h.private = false
                 and h.expired_timestamp >=  '{p0}'::timestamp) slu,
                 (select h.* from (select ROW_NUMBER() OVER (PARTITION BY per.continuity_id  order by per.revision_timestamp desc) as rn, * from package_extra_revision per where per.revision_timestamp < '{p0}'::timestamp and per.key like 'publisher') h 
                 where h.rn = 1  and h.state like 'active'
                 and h.expired_timestamp >=  '{p0}'::timestamp)pub,
                 (select h.* from (select ROW_NUMBER() OVER (PARTITION BY ger.continuity_id  order by ger.revision_timestamp desc) as rn, * from group_extra_revision ger where ger.revision_timestamp < '{p0}'::timestamp and ger.key like 'C_ID_UD_ORGANICA') h 
                 where h.rn = 1  and h.state like 'active'
                 and h.expired_timestamp >=  '{p0}'::timestamp)dir3
                 where sc.continuity_id = slu.continuity_id
                 and pub.package_id = sc.continuity_id
                 and dir3.group_id like pub.value group by adm'''.format(p0=date)
        result = model.Session.execute(sql)
        for row in result:
            results.append((import_date, 'administration_level', row[1], row[0]))

        if save:
            # check if there are saved data from this {p0} date
            sql = '''select count(*) from dge_dashboard_published_datasets
                    where year_month like '{p0}'
                    and key not like '{p1}';'''.format(p0=import_date, p1=not_key)
            result = model.Session.execute(sql)
            total = result.fetchone()[0]
            log.debug("Updating data...")
            sql = '''begin;'''
            if total > 0:
                sql += '''DELETE FROM dge_dashboard_published_datasets where year_month like '{p0}' and key not like '{p1}';'''.format(p0=import_date, p1=not_key)
            for result in results:
                sql += '''INSERT INTO dge_dashboard_published_datasets (year_month, key, key_value, num_datasets)
                          VALUES ('{p1}', '{p2}', '{p3}', {p4});'''.format(p1 = result[0], p2 = result[1], p3 = result[2], p4 = result[3])
            sql += '''
                    commit;
                   '''
            model.Session.execute(sql)
        else:
            print "Results: "
            for row in results:
                print row
    else:
        log.debug("Getting data by num_resources ....")
        key = 'num_resources'
        # total active, public dataset pusblished before than {p0} date by num_resources
        sql = '''select s1.num, count(s1.num) from
                (select pkg.continuity_id, rsc.num  as num from
                (select slu.continuity_id from 
                (select h.* from (select ROW_NUMBER() OVER (PARTITION BY pr.continuity_id order by pr.revision_timestamp asc) as rn, * from package_revision pr where pr.revision_timestamp < '{p0}'::timestamp and pr.type like 'dataset') h where h.rn = 1 ) sc, 
                (select h.* from (select ROW_NUMBER() OVER (PARTITION BY pr.continuity_id  order by pr.revision_timestamp desc) as rn, * from package_revision pr where pr.revision_timestamp < '{p0}'::timestamp and pr.type like 'dataset') h where h.rn = 1
                 and h.state like 'active' and h.private = false and h.expired_timestamp >=  '{p0}'::timestamp) slu 
                 where sc.continuity_id = slu.continuity_id) as pkg,
                 (select slu.package_id, count(*) num from 
                (select h.* from (select ROW_NUMBER() OVER (PARTITION BY rr.continuity_id order by rr.revision_timestamp asc) as rn, * from resource_revision rr where rr.revision_timestamp < '{p0}'::timestamp) h where h.rn = 1 ) sc, 
                (select h.* from (select ROW_NUMBER() OVER (PARTITION BY rr.continuity_id  order by rr.revision_timestamp desc) as rn, * from resource_revision rr where rr.revision_timestamp < '{p0}'::timestamp) h where h.rn = 1
                 and h.state like 'active' and h.expired_timestamp >=  '{p0}'::timestamp) slu 
                 where sc.continuity_id = slu.continuity_id group by slu.package_id order by num desc) as rsc
                 where rsc.package_id = pkg.continuity_id order by rsc.num desc) s1
                 group by s1.num order by num;'''.format(p0=date)
        result = model.Session.execute(sql)
        for row in result:
            results.append((import_date, key , row[0], row[1]))

        if save:
            # check if there are saved data from this {p0} date
            sql = '''select count(*) from dge_dashboard_published_datasets
                    where year_month like '{p0}'
                    and key like '{p1}';'''.format(p0=import_date, p1=key)
            result = model.Session.execute(sql)
            total = result.fetchone()[0]
            log.debug("Updating data...")
            sql = '''begin;'''
            if total > 0:
                sql += '''DELETE FROM dge_dashboard_published_datasets where year_month like '{p0}' and key like '{p1}';'''.format(p0=import_date, p1=key)
            for result in results:
                sql += '''INSERT INTO dge_dashboard_published_datasets (year_month, key, key_value, num_datasets)
                          VALUES ('{p1}', '{p2}', '{p3}', {p4});'''.format(p1 = result[0], p2 = result[1], p3 = result[2], p4 = result[3])
            sql += '''
                    commit;
                   '''
            model.Session.execute(sql)
        else:
            print "Results: "
            for row in results:
                print row

def dge_dashboard_update_publishers(context, data_dict):
    '''
    Update dge_dashboard_publishers table adding num publishers 
    who create datasets manually before given date param and
    num publishers who create datasets throw harvester

    :param date: the creation date of datasets must be before this
    :type date: string
    
    :param import_date: year-month of creation date of datasets
    :type import_date: string

    :param save: True only if update database, False if only print
    :type save: boolean.
    '''

    check_access('dge_dashboard_update_publishers', context, data_dict)

    date = data_dict.get('date')
    import_date = data_dict.get('import_date')
    save = data_dict.get('save', False)

    model = context['model']
    results = []
    log.debug("Getting data ....")
    sql = '''select s3.pub, s3.guid, (CASE WHEN s4.owner_org is NULL then False ELSE True END) as harvest 
             from (select distinct s1.owner_org, s2.pub, s2.guid
             from (select slu.id, slu.owner_org
             from (select h.* from (select ROW_NUMBER() OVER (PARTITION BY pr.continuity_id order by pr.revision_timestamp asc) as rn, * from package_revision pr where pr.revision_timestamp < '{p0}'::timestamp and pr.type like 'dataset') h where h.rn = 1 ) sc, 
             (select h.* from (select ROW_NUMBER() OVER (PARTITION BY pr.continuity_id  order by pr.revision_timestamp desc) as rn, * from package_revision pr where pr.revision_timestamp < '{p0}'::timestamp and pr.type like 'dataset') h 
             where h.rn = 1 and h.state like 'active' and h.type like 'dataset'
             and h.private = false and h.expired_timestamp >=  '{p0}'::timestamp) slu 
             where sc.continuity_id = slu.continuity_id)s1,
             (select pe1.pub, pe1.package_id, (CASE WHEN pe2.package_id IS NULL then False ELSE True END) as guid from 
             (select slu.value as pub, slu.package_id from 
             (select h.* from (select ROW_NUMBER() OVER (PARTITION BY per.continuity_id  order by per.revision_timestamp desc) as rn, * from package_extra_revision per where per.revision_timestamp < '{p0}'::timestamp and per.key like 'publisher') h 
             where h.rn = 1 and h.state like 'active' and h.key like 'publisher'
             and h.expired_timestamp >=  '{p0}'::timestamp) slu ) pe1 left outer join
             (select slu.package_id from 
             (select h.* from (select ROW_NUMBER() OVER (PARTITION BY per.continuity_id  order by per.revision_timestamp desc) as rn, * from package_extra_revision per where per.revision_timestamp < '{p0}'::timestamp and per.key like 'guid') h 
             where h.rn = 1 and h.state like 'active' and h.key like 'guid'
             and h.expired_timestamp >=  '{p0}'::timestamp)slu ) pe2 on pe1.package_id = pe2.package_id)s2
             where s1.id = s2. package_id) s3 left outer join
             (select distinct slu.owner_org from 
             (select h.* from (select ROW_NUMBER() OVER (PARTITION BY pr.continuity_id order by pr.revision_timestamp asc) as rn, * from package_revision pr where pr.revision_timestamp < '{p0}'::timestamp and pr.type like 'harvest') h 
             where h.rn = 1 ) sc, 
             (select h.* from (select ROW_NUMBER() OVER (PARTITION BY pr.continuity_id  order by pr.revision_timestamp desc) as rn, * from package_revision pr where pr.revision_timestamp < '{p0}'::timestamp and pr.type like 'harvest') h 
             where h.rn = 1 and h.state like 'active' and h.type like 'harvest'
             and h.private = false and h.expired_timestamp >=  '{p0}'::timestamp) slu 
             where sc.continuity_id = slu.continuity_id )s4 on
             s4.owner_org = s3.owner_org'''.format(p0=date)
    result = model.Session.execute(sql)
    harvester_publishers = 0
    manual_loading_publishers = 0
    log.debug("Processing the data obtained...")
    for row in result:
        guid = row[1]
        harvest = row[2]
        if guid == True and harvest == True:
            harvester_publishers = harvester_publishers + 1;
        else:
            manual_loading_publishers = manual_loading_publishers + 1;
    results.append((import_date, harvester_publishers, manual_loading_publishers))

    if save:
        # check if there are saved data from this {p0} date
        sql = '''select count(*) from dge_dashboard_publishers
                 where year_month like '{p0}';'''.format(p0=import_date)
        result = model.Session.execute(sql)
        total = result.fetchone()[0]
        log.debug("Updating data...")
        sql = '''begin;'''
        if total > 0:
            sql += '''DELETE FROM dge_dashboard_publishers where year_month like '{p0}';'''.format(p0=import_date)
        for result in results:
            sql += '''INSERT INTO dge_dashboard_publishers (year_month, harvester_publishers, manual_loading_publishers)
                      VALUES ('{p1}', '{p2}', '{p3}');'''.format(p1 = result[0], p2 = result[1], p3 = result[2])
        sql += '''
                commit;
               '''
        model.Session.execute(sql)
    else:
        print "Results: "
        for row in results:
            print row

def dge_dashboard_update_drupal_published_contents(context, data_dict):
    '''
    Update dge_dashboard_drupal_contents table
    adding num total created drupal contents before given date param

    :param date: the creation date of datasets must be before this
    :type date: string
    
    :param import_date: year-month of creation date of datasets
    :type import_date: string

    :param save: True only if update database, False if only print
    :type save: boolean.
    '''

    check_access('dge_dashboard_update_drupal_published_contents', context, data_dict)

    date = data_dict.get('date')
    import_date = data_dict.get('import_date')
    save = data_dict.get('save', False)

    model = context['model']
    engine = create_engine(config.get('ckanext.dge_drupal_users.connection', None))
    
    results = []
    log.debug("Getting total data from app, success, intiative and request ....")
   # total active, public dataset pusblished before than {p0} date
    sql = '''SELECT Count(*) As num, n.type As type FROM node n WHERE 
             n.status = 1 AND n.language = 'es' AND
             (n.type like 'app' OR n.type like 'success' OR n.type like 'initiative' OR n.type like 'request') AND
             FROM_UNIXTIME(n.created) < DATE_FORMAT(CURRENT_DATE, '{p0}')
             GROUP BY type;'''.format(p0=date)
    result = engine.execute(sql)
    for row in result:
        results.append((import_date, row[1], 'total', '', row[0]))

    if save:
        # check if there are saved data from this {p0} date
        sql = '''select count(*) from dge_dashboard_drupal_contents
                 where year_month like '{p0}' and
                 (content_type like 'app' OR content_type like 'success' OR content_type like 'initiative' OR content_type like 'request');'''.format(p0=import_date)
        result = model.Session.execute(sql)
        total = result.fetchone()[0]
        log.debug("Updating data...")
        sql = '''begin;'''
        if total > 0:
            sql += '''DELETE FROM dge_dashboard_drupal_contents where year_month like '{p0}' and 
                     (content_type like 'app' OR content_type like 'success' OR content_type like 'initiative' OR content_type like 'request');'''.format(p0=import_date)
        for result in results:
            sql += '''INSERT INTO dge_dashboard_drupal_contents (year_month, content_type, key, key_value, num_contents)
                      VALUES ('{p1}', '{p2}', '{p3}', '{p4}', {p5});'''.format(p1 = result[0], p2 = result[1], p3 = result[2], p4 = result[3], p5 = result[4])
        sql += '''
                commit;
                '''
        model.Session.execute(sql)
    else:
        print "Results: "
        for row in results:
            print row


def dge_dashboard_update_drupal_comments(context, data_dict):
    '''
    Update dge_dashboard_drupal_contents table
    adding num total comments by type before given date param and 
    and num comments by type and organization before given date param

    :param date: the creation date of datasets must be before this
    :type date: string

    :param import_date: year-month of creation date of datasets
    :type import_date: string

    :param save: True only if update database, False if only print
    :type save: boolean.
    '''

    check_access('dge_dashboard_update_drupal_comments', context, data_dict)

    date = data_dict.get('date')
    import_date = data_dict.get('import_date')
    save = data_dict.get('save', False)

    model = context['model']
    engine = create_engine(config.get('ckanext.dge_drupal_users.connection', None))

    results = []
    log.debug("Getting total comments ....")
    sql = '''SELECT COUNT(c.cid) As comentarios FROM comment c, node n WHERE
             c.nid = n.nid AND n.type != 'dataset' AND
             YEAR(FROM_UNIXTIME(c.created)) = YEAR('{p0}' - INTERVAL 1 MONTH) AND
             MONTH(FROM_UNIXTIME(c.created)) = MONTH('{p0}' - INTERVAL 1 MONTH);'''.format(p0=date)
    result = engine.execute(sql)
    for row in result:
        results.append((import_date, 'content_comments', 'total', '', row[0]))

    sql = '''SELECT COUNT(c.cid) As comentarios FROM comment c, node n WHERE
             c.nid = n.nid AND n.type = 'dataset' AND
             YEAR(FROM_UNIXTIME(c.created)) = YEAR('{p0}' - INTERVAL 1 MONTH) AND
             MONTH(FROM_UNIXTIME(c.created)) = MONTH('{p0}' - INTERVAL 1 MONTH);'''.format(p0=date)
    result = engine.execute(sql)
    for row in result:
        results.append((import_date, 'dataset_comments', 'total', '', row[0]))


    log.debug("Getting comments by organization ....")
    # getting the drupal equivalence between organizations
    orgs = dict()
    sql = '''SELECT fo.entity_id tid, fc.field_ckan_organization_id_value ckan_id FROM
             field_data_field_c_id_ud_organica fo, field_data_field_ckan_organization_id fc
             WHERE fo.entity_id = fc.entity_id;'''
    result = engine.execute(sql)
    for row in result:
        orgs[row[0]] = row[1]

    sql = '''SELECT ra.field_root_agency_tid As agency, COUNT(c.cid) As comentarios
             FROM comment c, node n, node_type ntp, users u, profile p,
             field_data_field_root_agency ra WHERE c.nid = n.nid AND
             ntp.type = n.type AND n.type != 'dataset' AND u.uid = n.uid AND
             p.uid = u.uid AND p.type = 'agency_data' AND p.pid = ra.entity_id AND
             YEAR(FROM_UNIXTIME(c.created)) = YEAR('{p0}' - INTERVAL 1 MONTH) AND
             MONTH(FROM_UNIXTIME(c.created)) = MONTH('{p0}' - INTERVAL 1 MONTH)
             GROUP BY agency ORDER BY agency;'''.format(p0=date)
    result = engine.execute(sql)
    for row in result:
        if row[0]:
           results.append((import_date, 'content_comments', 'org', orgs[row[0]], row[1]))

    sql = '''SELECT ra.field_root_agency_tid As agency, COUNT(c.cid) As comentarios
             FROM comment c, node n, node_type ntp, users u, profile p,
             field_data_field_root_agency ra WHERE c.nid = n.nid AND
             ntp.type = n.type AND n.type = 'dataset' AND u.uid = n.uid AND
             p.uid = u.uid AND p.type = 'agency_data' AND p.pid = ra.entity_id AND
             YEAR(FROM_UNIXTIME(c.created)) = YEAR('{p0}' - INTERVAL 1 MONTH) AND
             MONTH(FROM_UNIXTIME(c.created)) = MONTH('{p0}' - INTERVAL 1 MONTH)
             GROUP BY agency ORDER BY agency;'''.format(p0=date)
    result = engine.execute(sql)
    for row in result:
        if row[0]:
           results.append((import_date, 'dataset_comments', 'org', orgs[row[0]], row[1]))

    if save:
        # check if there are saved data from this {p0} date
        sql = '''select count(*) from dge_dashboard_drupal_contents
                 where year_month like '{p0}' and
                 (content_type like 'dataset_comments' OR content_type like 'content_comments') and
                 (key = 'total' OR key ='org');'''.format(p0=import_date)
        result = model.Session.execute(sql)
        total = result.fetchone()[0]
        log.debug("Updating data...")
        sql = '''begin;'''
        if total > 0:
            sql += '''DELETE FROM dge_dashboard_drupal_contents where year_month like '{p0}' and
                     (content_type like 'dataset_comments' OR content_type like 'content_comments') and
                     (key = 'total' OR key ='org');'''.format(p0=import_date)
        for result in results:
            sql += '''INSERT INTO dge_dashboard_drupal_contents (year_month, content_type, key, key_value, num_contents)
                      VALUES ('{p1}', '{p2}', '{p3}', '{p4}', {p5});'''.format(p1 = result[0], p2 = result[1], p3 = result[2], p4 = result[3], p5 = result[4])
        sql += '''
                commit;
                '''
        model.Session.execute(sql)
    else:
        print "Results: "
        for row in results:
            print row
