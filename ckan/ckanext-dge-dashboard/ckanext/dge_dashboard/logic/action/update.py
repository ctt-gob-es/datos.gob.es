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

'''API functions for updating tables in CKANEXT_DGE_DASHBOARD.'''

import logging
import json

from ckan.logic import check_access
from pylons import config
from sqlalchemy import create_engine
from os import path

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
                sql += '''DELETE FROM dge_dashboard_published_datasets where year_month like '{p0}' and key not like '{p1}';'''.format(
                    p0=import_date, p1=not_key)
            for result in results:
                sql += '''INSERT INTO dge_dashboard_published_datasets (year_month, key, key_value, num_datasets)
                          VALUES ('{p1}', '{p2}', '{p3}', {p4});'''.format(p1=result[0], p2=result[1], p3=result[2],
                                                                           p4=result[3])
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
            results.append((import_date, key, row[0], row[1]))

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
                sql += '''DELETE FROM dge_dashboard_published_datasets where year_month like '{p0}' and key like '{p1}';'''.format(
                    p0=import_date, p1=key)
            for result in results:
                sql += '''INSERT INTO dge_dashboard_published_datasets (year_month, key, key_value, num_datasets)
                          VALUES ('{p1}', '{p2}', '{p3}', {p4});'''.format(p1=result[0], p2=result[1], p3=result[2],
                                                                           p4=result[3])
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
    sql_both = '''with subquery as ( select *from (select * ,( CASE WHEN s5.harvest is False OR 
              s5.guid is False then 'manual_loading_publishers' ELSE 'harvester_publishers' END ) 
              AS publisher from (select s3.pub,s3.guid AS guid, ( CASE WHEN s4.owner_org IS NULL 
              THEN false ELSE true end ) AS harvest FROM (SELECT DISTINCT s1.owner_org, s2.pub, s2.guid
              FROM   (SELECT p1.id, p1.owner_org FROM   package p1 WHERE  p1.state LIKE 'active' 
              AND p1.type LIKE 'dataset' AND p1.private = false)s1 , (SELECT pe1.pub, pe1.package_id, 
              ( CASE WHEN pe2.package_id IS NULL THEN false ELSE true end ) AS guid 
              FROM   (SELECT pe.value AS pub, pe.package_id FROM   package_extra pe 
              WHERE  pe.state LIKE 'active' AND pe.key LIKE 'publisher') pe1 LEFT OUTER JOIN 
              (SELECT pe.package_id FROM   package_extra pe WHERE pe.state LIKE 'active' 
              AND pe.key LIKE 'guid') pe2 ON pe1.package_id = pe2.package_id)s2 
              WHERE  s1.id = s2. package_id) s3 LEFT OUTER JOIN (SELECT DISTINCT p2.owner_org 
              FROM   package p2 WHERE p2.state LIKE 'active' AND p2.type LIKE 'harvest' 
                AND p2.private = false) s4 ON s4.owner_org = s3.owner_org) s5 ) as s6)
              SELECT Concat('[', Concat(String_agg(s11.dict, ','), ']')) FROM   (
              SELECT Concat('{"date": "', Concat(( To_char(Now(), 'YYYY-MM-DD') ), Concat( '", "adm_level": "', 
                      Concat(s10.adm_level, Concat('", ', Concat( String_agg( s10.f, ', '), '}')))))) AS dict
              FROM   (SELECT Concat('"', Concat(s9.publisher, Concat('": ', s9.total))) AS f, s9.adm_level                          
              FROM (SELECT count(s8.pub) as total , s8.new_publisher as publisher, s8.adm_level
              FROM(SELECT DISTINCT q1.pub,(CASE WHEN q2.publisher is not null THEN 'both'
                  WHEN q1.publisher = 'manual_loading_publishers' THEN 'manual_loading_publishers'
                WHEN q1.publisher = 'harvester_publishers' THEN 'harvester_publishers' END) AS new_publisher, s7.adm_level
              FROM subquery q1 LEFT JOIN subquery q2 on q1.pub = q2.pub 
              AND ((q1.publisher = 'harvester_publishers' AND q2.publisher = 'manual_loading_publishers')or
              (q1.publisher = 'manual_loading_publishers' AND q2.publisher = 'harvester_publishers')),
              (SELECT g.id, Substring(ge.value, 0, 2) AS adm_level FROM   "group" g, group_extra ge 
              WHERE  ge.group_id = g.id AND g.state LIKE 'active' AND g.type LIKE 'organization' 
              AND ge.state LIKE 'active' AND ge.key LIKE 'C_ID_UD_ORGANICA')s7 WHERE  q1.pub = s7.id) s8
              GROUP BY s8.adm_level,s8.new_publisher ORDER BY adm_level)s9 GROUP  BY s9.adm_level, s9.publisher, 
                  s9.total)s10 GROUP  BY s10.adm_level)s11;'''

    result = model.Session.execute(sql)
    result_both = model.Session.execute(sql_both)
    result_both = result_both.fetchone() if result_both else None
    result_both = json.loads(result_both[0] if result_both else 'null')
    harvester_publishers = 0
    manual_loading_publishers = 0
    both = sum(map(lambda d: d.get('both', 0), result_both or []))
    log.debug("Processing the data obtained...")
    harvester_publishers_pub = []
    manual_loading_publishers_pub = []

    for row in result:
        pub = row[0]
        guid = row[1]
        harvest = row[2]
        #log.debug( 'tratado pub %s' % pub)
        if guid == True and harvest == True:
            #log.debug( 'pub  %s federa' % pub)
            if pub not in harvester_publishers_pub:
                harvester_publishers_pub.append(pub)
                harvester_publishers = harvester_publishers + 1
                if pub in manual_loading_publishers_pub:
                    #log.debug( 'pub %s ya estaba en manual' % pub)
                    manual_loading_publishers = manual_loading_publishers - 1
                    harvester_publishers = harvester_publishers - 1
            #else:
                #log.debug( 'pub %s que federa ya se habia procesado' % pub)
        else:
           # log.debug( 'pub  %s manual' % pub)
            if pub not in manual_loading_publishers_pub:
                manual_loading_publishers_pub.append(pub)
                manual_loading_publishers = manual_loading_publishers + 1
                if pub in harvester_publishers_pub:
                    #log.debug( 'pub %s ya estaba en federado' % pub)
                    harvester_publishers = harvester_publishers - 1
                    manual_loading_publishers = manual_loading_publishers - 1
            #else:
                #log.debug( 'pub  %s manual ya se habia procesado' % pub)
        log.debug('harvester_publishers=%d  manual_loading_publishers=%d' % (harvester_publishers, manual_loading_publishers))

    results.append((import_date, harvester_publishers,
                    manual_loading_publishers, both))

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
            sql += '''INSERT INTO dge_dashboard_publishers (year_month, harvester_publishers, manual_loading_publishers, "both")
                      VALUES ('{p1}', '{p2}', '{p3}', '{p4}');'''.format(p1=result[0], p2=result[1], p3=result[2], p4=result[3])
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
                 (content_type like 'app' OR content_type like 'success' OR content_type like 'initiative' OR content_type like 'request');'''.format(
            p0=import_date)
        result = model.Session.execute(sql)
        total = result.fetchone()[0]
        log.debug("Updating data...")
        sql = '''begin;'''
        if total > 0:
            sql += '''DELETE FROM dge_dashboard_drupal_contents where year_month like '{p0}' and 
                     (content_type like 'app' OR content_type like 'success' OR content_type like 'initiative' OR content_type like 'request');'''.format(
                p0=import_date)
        for result in results:
            sql += '''INSERT INTO dge_dashboard_drupal_contents (year_month, content_type, key, key_value, num_contents)
                      VALUES ('{p1}', '{p2}', '{p3}', '{p4}', {p5});'''.format(p1=result[0], p2=result[1], p3=result[2],
                                                                               p4=result[3], p5=result[4])
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
                      VALUES ('{p1}', '{p2}', '{p3}', '{p4}', {p5});'''.format(p1=result[0], p2=result[1], p3=result[2],
                                                                               p4=result[3], p5=result[4])
        sql += '''
                commit;
                '''
        model.Session.execute(sql)
    else:
        print "Results: "
        for row in results:
            print row
