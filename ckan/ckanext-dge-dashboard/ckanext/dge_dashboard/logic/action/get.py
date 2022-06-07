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

#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''API functions for get table data in CKANEXT_DGE_DASHBOARD.'''
import re
from datetime import datetime

import csv
import json
import logging
import traceback
from ckan.logic import check_access
from ckanext.dge_dashboard.commands.dge_dashboard import DgeDashboardJsonCommand
from pylons import config
from sqlalchemy import create_engine

log = logging.getLogger(__name__)


def _get_complete_filename(destination=None, prefix=None, suffix=None, extension='json'):
    if destination is None or len(destination) == 0 or len(destination.strip(' \t\n\r')) == 0:
        log.info('No destination directory')
        return None
    else:
        destination = destination.strip(' \t\n\r')
        if destination[-1] == '/':
            destination = destination[:-1]

    if prefix is None or len(prefix) == 0 or len(prefix.strip(' \t\n\r')) == 0:
        log.info('No prefix')
        return None
    else:
        prefix = prefix.strip(' \t\n\r')
        pattern = re.compile(DgeDashboardJsonCommand.FILENAME_REGEX)
        if not pattern.match(prefix):
            log.info('No valid prefix')
            return None

    if suffix and len(suffix) > 0 and len(suffix.strip(' \t\n\r')) > 0:
        suffix = suffix.strip(' \t\n\r')
        pattern = re.compile(DgeDashboardJsonCommand.FILENAME_REGEX)
        if not pattern.match(suffix):
            log.info('No valid suffix')
            return None
    else:
        suffix = None

    filename = destination + '/' + prefix + (('_' + suffix) if suffix else '') + '.' + extension
    return filename


def _write_file(filedata=None, destination=None, prefix=None, suffix=None, extension='json'):
    if filedata is None:
        log.info('No data for write in file')
        return None
    filename = _get_complete_filename(destination, prefix, suffix, extension)
    if filename:
        try:
            outfile = open(filename, 'w')
            try:
                outfile.write(filedata)
                outfile.close()
            except Exception as e:
                log.error('Exception %s', e)
                filename = None
            finally:
                outfile.close()
        except Exception as e:
            log.error('Exception %s', e)
            filename = None
    return filename


def _execute_fetchone_sql(model=None, sql=None):
    if sql and model:
        try:
            result = model.Session.execute(sql)
            row = result.fetchone() if result else None
            if row and len(row) > 0:
                return row[0]
        except Exception as e:
            log.error('Exception %s', e)
            return None
    return None


def _execute_drupal_sql(sql=None, json_query=True, encoding='latin1'):
    if sql:
        try:
            result = None
            results = []
            conn_string = config.get('ckanext.dge_drupal_users.connection', None)
            if conn_string:
                engine = create_engine(conn_string, encoding=encoding)
                if engine:
                    result = engine.execute(sql)
                if result:
                    for row in result:
                        results.append(row[0] if json_query else row)
                if results and len(results) > 0:
                    return "[" + ",".join(results) + "]" if json_query else results
        except Exception as e:
            log.error('Exception: %s\n%s\n' % (e, traceback.format_exc()))
            return None
    return None


def dge_dashboard_json_published_datasets(context, data_dict):
    '''
    Get dge_dashboard_published_datasets table data and write json files

    :param what: what data must be get
    :type what: values: total|all|org|adm_level|num_res

    :param destination: directory destination of json file
    :type destination: string

    :param prefix: filename prefix of json file
    :type prefix: string
    '''

    check_access('dge_dashboard_json_published_datasets', context, data_dict)

    what = data_dict.get('what')
    destination = data_dict.get('destination')
    prefix = data_dict.get('prefix')

    model = context['model']

    sql = None

    if what in DgeDashboardJsonCommand.PUBLISHED_DATASETS_TYPES:
        if what == 'all':
            sql = '''select concat('[', concat(string_agg(r.dict, ','), ']'))
                     from (select concat('{', concat(s.ym, concat(', ', 
                     concat(s.num, concat(', ', concat(s.key, concat(', ', 
                     concat(s.key_value, '}')))))))) dict from 
                     (select concat('"year": "', concat(d.year_month, '"')) as ym, 
                     concat('"num_datasets": ', d.num_datasets) as num, 
                     concat('"key": "', concat(d.key, '"')) as key, 
                     concat('"key_value": "', concat(d.key_value, '"')) as key_value
                     from dge_dashboard_published_datasets d
                     where key like 'total' order by year_month asc) s)r;'''
        elif what == 'total':
            sql = '''select concat('[', concat(string_agg(r.dict, ','), ']'))
                     from (select concat('{', concat(s.ym, concat(', ', 
                     concat(s.value, '}')))) dict from 
                     (select concat('"year": "', concat(d.year_month, '"')) as ym, 
                     concat('"value": ', d.num_datasets) as value
                     from dge_dashboard_published_datasets d
                     where key like 'total' order by year_month asc) s)r;'''
        elif what == 'org':
            sql = '''select concat('[', concat(string_agg(r.dict, ','), ']'))
                     from (select concat('{', concat(s.ym, concat(', ', 
                     concat(s.value, concat(', ', concat(s.org, '}')))))) dict 
                     from (select concat('"year": "', concat(d.year_month, '"')) as ym, 
                     concat('"value": ', d.num_datasets) as value, 
                     concat('"org": "', concat(d.key_value, '"')) as org
                     from dge_dashboard_published_datasets d where
                     key like 'organization_id' order by year_month asc) s)r;'''
        elif what == 'adm_level':
            sql = '''select concat('[', concat(string_agg(r.dict, ','), ']'))
                     from (select concat('{"year": "', concat(s.ym, 
                     concat('", ', concat(string_agg(s.ff , ', '), '}')))) as dict 
                     from (select concat('"', concat(d.key_value, concat('"', 
                     concat(': ', d.num_datasets)))) as ff, d.year_month  as ym
                     from dge_dashboard_published_datasets d where 
                     key like 'administration_level'order by year_month asc )s 
                     group by ym )r;'''
        elif what == 'num_res':
            sql = '''select concat('[', concat(string_agg(r.dict, ','), ']'))
                     from (select concat('{', concat(s.ym, concat(', ', 
                     concat(s.value, concat(', ', concat(s.num_res, '}')))))) dict 
                     from (select concat('"year": "', concat(d.year_month, '"')) as ym, 
                     concat('"value": ', d.num_datasets) as value, 
                     concat('"num_res": "', concat(d.key_value, '"')) as num_res
                     from dge_dashboard_published_datasets d where
                     key like 'num_resources' order by year_month asc) s)r;'''

    result = _execute_fetchone_sql(model, sql)
    return _write_file(result, destination, prefix, what)


def dge_dashboard_json_current_published_datasets_by_administration_level(context, data_dict):
    '''
    Get current published datasets by administration level
    
    :param destination: directory destination of json file
    :type destination: string
    
    :param filename: filename of json file
    :type filename: string
    '''

    check_access('dge_dashboard_json_current_published_datasets_by_administration_level', context, data_dict)

    destination = data_dict.get('destination')
    filename = data_dict.get('filename')

    model = context['model']

    sql = '''select concat('[', concat(string_agg(r.dict, ','), ']'))from
             (select concat('{"date": "', concat((to_char(now(), 'YYYY-MM-DD')), 
             concat('", ', concat(s.v, concat(', ', concat(s.n, '}')))))) as dict 
             from (select concat('"administration_level": "', 
             concat(substring(g.value, 0, 2), '"')) as v, 
             concat('"num_datasets": ', count(*)) as n from package_extra pe, 
             package p, group_extra g where p.private = False 
             and p.type like 'dataset' and p.state like 'active'
             and p.id = pe.package_id and pe.key like 'publisher' 
             and pe.state like 'active' and g.group_id = pe.value 
             and g.key like 'C_ID_UD_ORGANICA'
             group by v order by v asc)s ) r;'''

    result = _execute_fetchone_sql(model, sql)
    return _write_file(result, destination, filename, None)


def dge_dashboard_json_current_distribution_format(context, data_dict):
    '''
    Get current distribution format global or by administration level
    
    :param what: type of data to get, 'adm_level' = administration_level, 'total' = total, 'org' = organization
    :type what: string
    
    :param destination: directory destination of json file
    :type destination: string
    
    :param prefix: filename prefix of json file
    :type prefix: string
    '''

    check_access('dge_dashboard_json_current_distribution_format', context, data_dict)

    what = data_dict.get('what')
    destination = data_dict.get('destination')
    prefix = data_dict.get('prefix')

    model = context['model']
    sql = None

    if what in DgeDashboardJsonCommand.DISTRIBUTION_FORMAT_TYPES:
        sql = '''select concat('[', concat(string_agg(s2.dict, ','), ']')) from
                 (select concat('{"date": "', concat((to_char(now(), 'YYYY-MM-DD')), 
                 concat('", "format": "', concat(s1.f, concat('", "value": ', 
                 concat(s1.num, '}')))))) as dict from (select r.format as f, 
                 count(*) num from package p, resource r where
                 p.private = False and p.type like 'dataset' 
                 and p.state like 'active' and p.id = r.package_id 
                 and r.state like 'active' group by f
                 order by num desc)s1)s2; '''
        if what == 'adm_level':
            sql = '''select concat('[', concat(string_agg(s2.dict, ','), ']')) 
                     from (select concat('{"date":"', 
                     concat((to_char(now(), 'YYYY-MM-DD')), 
                     concat('", "format":"', concat(s1.f, concat('", "level":"', 
                     concat(s1.v, concat('", "value":', concat(num, '}')))))))) as dict 
                     from (select substring(g.value, 0, 2) as v, r.format as f, 
                     count(*) num from package_extra pe, package p, 
                     group_extra g, resource r where p.private = False 
                     and p.type like 'dataset' and p.state like 'active'
                     and p.id = pe.package_id and pe.key like 'publisher' 
                     and pe.state like 'active' and g.group_id = pe.value 
                     and g.key like 'C_ID_UD_ORGANICA'
                     and p.id = r.package_id and r.state like 'active'
                     group by v, f
                     order by v, num desc, f asc)s1)s2;'''
        elif what == 'org':
            sql = '''select concat('[', concat(string_agg(s2.dict, ','), ']')) 
                     from (select concat('{"date": "', 
                     concat((to_char(now(), 'YYYY-MM-DD')), 
                     concat('", "format": "', concat(s1.f, 
                     concat('", "org_id": "', concat(s1.o ,
                     concat('", "value": ', concat(s1.num, '}')))))))) as dict 
                     from (select r.format as f, p.owner_org as o, count(*) num 
                     from package p, resource r where p.private = False and 
                     p.type like 'dataset' and p.state like 'active'
                     and p.id = r.package_id and r.state like 'active'
                     group by f, o
                     order by num desc, o asc, f desc)s1)s2;'''

    result = _execute_fetchone_sql(model, sql)
    return _write_file(result, destination, prefix, what)


def dge_dashboard_json_current_published_datasets_by_category(context, data_dict):
    '''
    Get current published datasets by category
    
    :param destination: directory destination of json file
    :type destination: string
    
    :param filename: filename of json file
    :type filename: string
    '''

    check_access('dge_dashboard_json_current_published_datasets_by_category', context, data_dict)

    destination = data_dict.get('destination')
    filename = data_dict.get('filename')

    model = context['model']

    sql = '''select concat('[', concat(string_agg(r.dict, ','), ']'))from
             (select concat('{"date": "', concat((to_char(now(), 'YYYY-MM-DD')), 
             concat('", "theme": "', concat(s1.theme, concat('", "value": ', 
             concat(s1.num, '}')))))) as dict from (select s.theme, 
             count(*) as num from (select p.name, 
             regexp_split_to_table(regexp_replace(regexp_replace(regexp_replace(pe.value, '"', '', 'g'), ']' , ''), '\[', ''), E', ') as theme FROM package_extra pe, package p
             where pe.key like 'theme'
             and p.state like 'active'
             and p.private = false
             and pe.package_id  = p.id
             order by package_id) as s
             group by theme order by count(*) desc) as s1)as r;'''

    result = _execute_fetchone_sql(model, sql)
    return _write_file(result, destination, filename, None)


def dge_dashboard_json_publishers(context, data_dict):
    '''
    Get dge_dashboard_publishers table data and write json files

    :param destination: directory destination of json file
    :type destination: string

    :param filename: json filename
    :type filename: string
    '''

    check_access('dge_dashboard_json_publishers', context, data_dict)

    destination = data_dict.get('destination')
    filename = data_dict.get('filename')

    model = context['model']

    sql = '''select concat('[', concat(string_agg(r.dict, ','), ']'))from
             (select concat('{"year": "', concat(d.year_month, 
             concat('", "harvester_publishers":', concat(d.harvester_publishers, 
             concat(', "manual_loading_publishers":', concat(d.manual_loading_publishers,
             concat(', "both":', concat(d.both, '}')))))))) as dict
             from dge_dashboard_publishers d)r;'''

    result = _execute_fetchone_sql(model, sql)
    return _write_file(result, destination, filename, None)


def dge_dashboard_json_current_publishers_by_administration_level(context, data_dict):
    '''
    Get current publishers by administration level in two groups: harvester publishers and manual loading publishers
     and write json files

    :param destination: directory destination of json file
    :type destination: string

    :param filename: json filename
    :type filename: string
    '''

    check_access('dge_dashboard_json_current_publishers_by_administration_level', context, data_dict)

    destination = data_dict.get('destination')
    filename = data_dict.get('filename')

    model = context['model']

    sql = '''with subquery as ( select *from (select * ,( CASE WHEN s5.harvest is False OR 
              s5.guid is False then 'manual_loading_publishers' ELSE 'harvester_publishers' END ) 
              AS publisher from (select s3.pub,s3.guid AS guid, ( CASE WHEN s4.owner_org IS NULL 
              THEN false ELSE true end ) AS harvest FROM (SELECT DISTINCT s1.owner_org, s2.pub, s2.guid
              FROM (SELECT p1.id, p1.owner_org FROM package p1 WHERE  p1.state LIKE 'active' 
              AND p1.type LIKE 'dataset' AND p1.private = false)s1 , (SELECT pe1.pub, pe1.package_id, 
              ( CASE WHEN pe2.package_id IS NULL THEN false ELSE true end ) AS guid 
              FROM (SELECT pe.value AS pub, pe.package_id FROM package_extra pe 
              WHERE pe.state LIKE 'active' AND pe.key LIKE 'publisher') pe1 LEFT OUTER JOIN 
              (SELECT pe.package_id FROM package_extra pe WHERE pe.state LIKE 'active' 
              AND pe.key LIKE 'guid') pe2 ON pe1.package_id = pe2.package_id)s2 
              WHERE s1.id = s2. package_id) s3 LEFT OUTER JOIN (SELECT DISTINCT p2.owner_org 
              FROM package p2 WHERE p2.state LIKE 'active' AND p2.type LIKE 'harvest' 
                AND p2.private = false) s4 ON s4.owner_org = s3.owner_org) s5 ) as s6)
              SELECT Concat('[', Concat(String_agg(s11.dict, ','), ']')) FROM (
              SELECT Concat('{"date": "', Concat(( To_char(Now(), 'YYYY-MM-DD') ), Concat( '", "adm_level": "', 
                Concat(s10.adm_level, Concat('", ', Concat( String_agg( s10.f, ', '), '}')))))) AS dict
              FROM (SELECT Concat('"', Concat(s9.publisher, Concat('": ', s9.total))) AS f, s9.adm_level 							
              FROM (SELECT count(s8.pub) as total , s8.new_publisher as publisher, s8.adm_level
              FROM(SELECT DISTINCT q1.pub,(CASE WHEN q2.publisher is not null THEN 'both'
                WHEN q1.publisher = 'manual_loading_publishers' THEN 'manual_loading_publishers'
	            WHEN q1.publisher = 'harvester_publishers' THEN 'harvester_publishers' END) AS new_publisher, s7.adm_level
              FROM subquery q1 LEFT JOIN subquery q2 on q1.pub = q2.pub 
              AND ((q1.publisher = 'harvester_publishers' AND q2.publisher = 'manual_loading_publishers')or
              (q1.publisher = 'manual_loading_publishers' AND q2.publisher = 'harvester_publishers')),
              (SELECT g.id, CASE WHEN Substring(ge.value, 0, 2) in ('A','E','J','L','U','P') 
              THEN Substring(ge.value, 0, 2) ELSE 'I' end AS adm_level FROM "group" g, group_extra ge 
              WHERE  ge.group_id = g.id AND g.state LIKE 'active' AND g.type LIKE 'organization' 
              AND ge.state LIKE 'active' AND ge.key LIKE 'C_ID_UD_ORGANICA')s7 WHERE  q1.pub = s7.id) s8
              GROUP BY s8.adm_level,s8.new_publisher ORDER BY adm_level)s9 GROUP BY s9.adm_level, s9.publisher, 
                s9.total)s10 GROUP BY s10.adm_level)s11;'''

    result = _execute_fetchone_sql(model, sql)
    return _write_file(result, destination, filename, None)


def dge_dashboard_json_drupal_published_contents(context, data_dict):
    '''
    Get dge_dashboard_drupal_contents table data and write json files

    :param what: what data must be get
    :type what: values: total|comments|org_comments

    :param destination: directory destination of json file
    :type destination: string

    :param prefix: filename prefix of json file
    :type prefix: string
    '''

    check_access('dge_dashboard_json_drupal_published_contents', context, data_dict)

    what = data_dict.get('what')
    destination = data_dict.get('destination')
    prefix = data_dict.get('prefix')

    model = context['model']

    sql = None

    if what in DgeDashboardJsonCommand.DRUPAL_PUBLISHED_CONTENTS:
        if what == 'contents':
            sql = '''select concat('[', concat(string_agg(s2.dict, ','), ']')) 
                     from (select concat('{"date": "', concat(s1.year_month, 
                     concat('", ', concat(string_agg(s1.c , ', '), '}')))) as dict
                     from (select concat('"', concat(content_type, 
                     concat('": ', num_contents))) c, year_month
                     from dge_dashboard_drupal_contents where key like 'total'
                     and (content_type like 'app' OR content_type like 'success' 
                     OR content_type like 'initiative' OR content_type like 'request'))s1
                     group by s1.year_month order by s1.year_month)s2;'''
        elif what == 'comments':
            sql = '''select concat('[', concat(string_agg(s2.dict, ','), ']')) 
                      from(select concat('{"year": "', concat(s1.year_month, 
                      concat('", ', concat(string_agg(s1.c , ', '), '}')))) as dict 
                      from (select concat('"', concat(content_type, 
                      concat('": ', num_contents))) c, year_month
                      from dge_dashboard_drupal_contents where key like 'total'
                      and (content_type like 'dataset_comments' OR 
                      content_type like 'content_comments'))s1
                      group by s1.year_month order by s1.year_month)s2;'''
        elif what == 'org_comments':
            sql = '''select concat('[', concat(string_agg(s2.dict, ','), ']')) 
                     from (select concat('{"year": "', concat(s1.year_month,
                     concat('", "org": "', concat(key_value, '", ',
                     concat(string_agg(s1.c , ', '), '}'))))) as dict from
                     (select concat('"', concat(content_type, 
                     concat('": ', num_contents))) c, key_value, year_month from 
                     dge_dashboard_drupal_contents where key like 'org' and
                     (content_type like 'dataset_comments' OR 
                     content_type like 'content_comments'))s1 
                     group by s1.year_month, s1.key_value 
                     order by s1.year_month)s2;'''

    result = _execute_fetchone_sql(model, sql)
    if result and (what == 'comments' or what == 'org_comments'):
        data = json.loads(result)
        for row in data:
            if not "dataset_comments" in row:
                row['dataset_comments'] = 0L
            if not "content_comments" in row:
                row['content_comments'] = 0L
        result = json.dumps(data)
    return _write_file(result, destination, prefix, what)


def dge_dashboard_json_drupal_content_by_likes(context, data_dict):
    check_access('dge_dashboard_update_drupal_content_by_likes', context, data_dict)
    destination = data_dict.get('destination')
    filename = data_dict.get('filename')

    sql = """
            SELECT 
                node.title as node_title ,
                case when node.type='dataset'
                 then  concat("catalogo/",ckan_url.field_ckan_package_name_value)  
                   else u_alias.alias
                end as node_url,
                node.type as node_type,
                SUM(votingapi_cache_node_points_count.value) AS node_number_likes 
            from node
              LEFT JOIN votingapi_vote votingapi_cache_node_points_count ON node.nid = votingapi_cache_node_points_count.entity_id    
              left join url_alias u_alias on ( u_alias.source=concat("node/",node.nid) )
              left join field_data_field_ckan_package_name ckan_url on ( ckan_url.entity_id = node.nid )
            WHERE (( (node.status = '1') ) AND (node.type IN('blog', 'event', 'blog_blog', 'talk', 'app', 'aporta','request', 'bulletin'))) 
            GROUP BY node_title
            having SUM(votingapi_cache_node_points_count.value) > 0 
            ORDER BY node_number_likes  DESC;"""

    rows = _execute_drupal_sql(sql, json_query=False)
    if not rows:
        rows = []

    return _write_file(
        json.dumps({
            'update_date': datetime.now().strftime('%d/%m/%Y'),
            'data': [{
                'name': row[0] if row[0] else '',
                'url': row[1] if row[1] else '',
                'likes': row[3] if row[3] else 0,
                'content_type': row[2] if row[2] else ''}
                for row in rows]
        }, ensure_ascii=False),
        destination, filename)


def dge_dashboard_json_drupal_top10_voted_datasets(context, data_dict):
    check_access('dge_dashboard_json_drupal_top10_voted_datasets', context, data_dict)
    destination = data_dict.get('destination')
    filename = data_dict.get('filename')

    sql = """
            SELECT 
                node.title as node_title ,      
                case
                  when node.type='dataset' then  concat('catalogo/',ckan_url.field_ckan_package_name_value)
                  else u_alias.alias    
                end as node_url,
                SUM(votingapi_cache_node_points_count.value) AS node_number_likes     
            from node
                LEFT JOIN votingapi_vote votingapi_cache_node_points_count ON node.nid = votingapi_cache_node_points_count.entity_id    
              left join url_alias u_alias on ( u_alias.source=concat("node/",node.nid) )
              left join field_data_field_ckan_package_name ckan_url on ( ckan_url.entity_id = node.nid )
            WHERE (( (node.status = '1') ) AND (node.type ='dataset')) 
            GROUP BY node_title
            having SUM(votingapi_cache_node_points_count.value) >0
            ORDER BY node_number_likes  DESC;"""

    rows = _execute_drupal_sql(sql, json_query=False)
    if not rows:
        rows = []

    return _write_file(
        json.dumps({
            'update_date': datetime.now().strftime('%d/%m/%Y'),
            'data': [
                {
                    'name': row[0] if row[0] else u'',
                    'url': row[1] if row[1] else u'',
                    'likes': row[2] if row[2] else 0
                }
                for row in rows]
        }, ensure_ascii=False),
        destination,
        filename)


def dge_dashboard_json_current_drupal_published_contents(context, data_dict):
    '''
    Get dge_dashboard_drupal_contents table data and write json files

    :param destination: directory destination of json file
    :type destination: string

    :param filename: json filename
    :type filename: string
    '''

    check_access('dge_dashboard_json_current_drupal_published_contents', context, data_dict)

    destination = data_dict.get('destination')
    filename = data_dict.get('filename')

    model = context['model']

    sql = '''SELECT concat('{"date": "', concat((DATE_FORMAT(now(), '%%Y-%%m-%%d')), 
             concat('", "content_type":"', concat(s1.tp, concat('", "num_contents": ', 
             concat(s1.num, '}')))))) as dict FROM (SELECT n.type tp, 
             Count(*) As num FROM node n WHERE n.status = 1 AND n.language = 'es' 
             AND n.type != 'dataset' GROUP BY tp ORDER BY num DESC, tp ASC) s1;'''

    result = _execute_drupal_sql(sql)
    return _write_file(result, destination, filename, None)


def dge_dashboard_json_current_users(context, data_dict):
    '''
    Get active users by organization and write them into json file

    :param what: what data must be get
    :type what: values: org|adm_level|num_org

    :param destination: directory destination of json file
    :type destination: string

    :param prefix: filename prefix of json file
    :type prefix: string
    '''

    check_access('dge_dashboard_json_current_users_by_org', context, data_dict)

    what = data_dict.get('what')
    destination = data_dict.get('destination')
    prefix = data_dict.get('prefix')

    model = context['model']

    sql = None
    if what in DgeDashboardJsonCommand.USERS_TYPES:
        if what == 'org':
            log.debug("Getting drupal active users by organization")

            sql = '''SELECT concat('{"date": "', 
                     concat((DATE_FORMAT(now(), '%%Y-%%m-%%d')), 
                     concat('", "org_id":"', concat(s1.ckan_id, 
                     concat('", "users": "', 
                     concat(group_concat(s1.username), '"}')))))) as dict FROM
                     (SELECT fc.field_ckan_organization_id_value ckan_id, 
                     u.name username FROM profile p, field_data_field_root_agency ra, 
                     users u, taxonomy_term_data vo,
                     field_data_field_c_id_ud_organica fo, 
                     field_data_field_ckan_organization_id fc WHERE
                     p.pid = ra.entity_id AND p.uid = u.uid 
                     AND ra.field_root_agency_tid = vo.tid AND
                     ra.entity_type = 'profile2' AND p.type = 'agency_data' 
                     AND ra.bundle = 'agency_data' AND u.status=1 AND vo.vid = 3 
                     AND fo.entity_id = fc.entity_id 
                     AND fo.entity_id = ra.field_root_agency_tid
                     ORDER BY ckan_id, username asc)s1 GROUP BY s1.ckan_id;'''
            log.debug("Getting drupal active users by organization---finished")
        elif what == 'adm_level':
            log.debug("Getting drupal active users by adm_level")

            sql = '''SELECT concat('{"date": "', 
                     concat((DATE_FORMAT(now(), '%%Y-%%m-%%d')), 
                     concat('", "adm_level":"', concat(s1.adm_level, 
                     concat('", "num_users": ', concat(s1.total_users, '}')))))) as dict 
                     FROM (SELECT LEFT(uo.field_c_id_ud_organica_value,1) adm_level, 
                     COUNT(u.name) total_users FROM profile p, 
                     field_data_field_root_agency ra, users u, 
                     taxonomy_term_data vo, field_data_field_c_id_ud_organica uo
                     WHERE p.pid = ra.entity_id AND p.uid = u.uid 
                     AND ra.field_root_agency_tid = vo.tid 
                     AND ra.entity_type = 'profile2' AND p.type = 'agency_data' 
                     AND ra.bundle = 'agency_data' AND uo.entity_type = 'taxonomy_term' 
                     AND uo.entity_id = vo.tid AND u.status=1 AND vo.vid = 3 
                     GROUP BY adm_level ORDER BY total_users DESC) s1;'''
        elif what == 'num_org':
            log.debug("Getting drupal active users by num_org")

            sql = '''SELECT concat('{"date": "', 
                     concat((DATE_FORMAT(now(), '%%Y-%%m-%%d')), 
                     concat('", "org_name":"', concat(s1.org, 
                     concat('", "num_users": ', concat(s1.total_users, '}')))))) as dict 
                     FROM (SELECT vo.name org, Count(u.uid) AS total_users FROM
                     profile p, field_data_field_root_agency ra, users u, 
                     taxonomy_term_data vo WHERE p.pid = ra.entity_id 
                     AND p.uid = u.uid AND ra.field_root_agency_tid = vo.tid 
                     AND ra.entity_type = 'profile2' AND p.type = 'agency_data' 
                     AND ra.bundle = 'agency_data' AND u.status=1 AND vo.vid = 3 
                     GROUP BY vo.tid ORDER BY total_users DESC, org ASC) s1;'''

    result = _execute_drupal_sql(sql)
    if result:
        result = result.decode('latin1').encode('utf-8')
        log.debug("FINISHED")
    return _write_file(result, destination, prefix, what)


def dge_dashboard_json_current_assigned_request_by_state(context, data_dict):
    '''
    Get current assigned request global or by organization
    
    :param what: type of data to get, 'total' = total, 'org' = organization
    :type destination: string
    
    :param destination: directory destination of json file
    :type destination: string
    
    :param prefix: filename of json file
    :type prefix: string
    '''

    check_access('dge_dashboard_json_current_assigned_request_by_state', context, data_dict)

    what = data_dict.get('what')
    destination = data_dict.get('destination')
    prefix = data_dict.get('prefix')

    model = context['model']

    if what in DgeDashboardJsonCommand.REQUEST_TYPES:
        sql = '''(SELECT concat('{"date": "', concat((DATE_FORMAT(now(), '%%Y-%%m-%%d')), 
                 concat('", "state": "', concat(s1.estado, concat('", "value": ', 
                 concat(s1.num, '}')))))) as states FROM (SELECT vo.name estado, 
                 COUNT(n.nid) num FROM field_data_field_request_tx_status rs, 
                 node n, taxonomy_term_data vo WHERE n.nid = rs.entity_id 
                 AND n.status = 1 
                 AND rs.entity_type = 'node'
                 AND rs.field_request_tx_status_tid  = vo.tid 
                 AND n.language = 'es' GROUP BY estado) s1); '''
        if what == 'org':
            sql = '''SELECT concat('{"date": "', concat((DATE_FORMAT(now(), '%%Y-%%m-%%d')), 
                     concat('", "org_id": "', concat(s1.ckan_id, 
                     concat('", "state": "', concat(s1.estado, 
                     concat('", "value":', concat(s1.num, '}')))))))) as dict FROM 
                     (SELECT fc.field_ckan_organization_id_value ckan_id, 
                     vo.name estado, COUNT(n.nid) num FROM
                     field_data_field_request_tx_status rs, node n, 
                     taxonomy_term_data vo, users u, profile p, 
                     field_data_field_root_agency ra, field_data_field_c_id_ud_organica fo, 
                     field_data_field_ckan_organization_id fc
                     WHERE n.nid = rs.entity_id AND rs.entity_type = 'node' 
                     AND rs.field_request_tx_status_tid  = vo.tid AND
                     n.status=1 AND n.language = 'es' AND u.uid = n.uid 
                     AND p.uid = u.uid AND p.type = 'agency_data' AND
                     p.pid = ra.entity_id AND fo.entity_id = fc.entity_id AND 
                     fo.entity_id = ra.field_root_agency_tid
                     GROUP BY estado, ckan_id ORDER BY ckan_id) s1;'''

    result = _execute_drupal_sql(sql)
    return _write_file(result, destination, prefix, what)


def dge_dashboard_json_visits(context, data_dict):
    '''
    Get general visits to datos.gob.es or visits to datos.gob.es by sections 
    
    :param what: type of data to get, 'total' = total, 'section' = sections
    :type destination: string
    
    :param destination: directory destination of json file
    :type destination: string
    
    :param prefix: filename prefix of json file
    :type prefix: string
    '''

    check_access('dge_dashboard_json_visits', context, data_dict)

    what = data_dict.get('what')
    destination = data_dict.get('destination')
    prefix = data_dict.get('prefix')

    model = context['model']

    if what in DgeDashboardJsonCommand.VISIT_TYPES:
        sql = '''select concat('[', concat(string_agg(s.dict, ','), ']'))from
                 (select concat('{"date": "', concat(year_month, 
                 concat('", "value": ', concat(sessions, '}')))) as dict
                 from dge_ga_visits where key like 'all' 
                 and (key_value is null or key_value like '')
                 order by year_month asc)s;'''
        if what == 'section':
            sql = '''select concat('[', concat(string_agg(s2.dict, ','), ']')) 
                     from (select concat('{"date": "', concat(year_month, 
                     concat('", ', concat(string_agg(s1.ses, ','), '}')))) as dict 
                     from (select year_month, concat('"', concat(key_value, 
                     concat('": ', sessions))) ses from dge_ga_visits where 
                     key like 'section' and key_value is not null and 
                     key_value not like '' 
                     order by year_month asc, key_value asc)s1
                     group by year_month)s2;'''

    result = _execute_fetchone_sql(model, sql)
    return _write_file(result, destination, prefix, what)


def dge_dashboard_json_visited_datasets(context, data_dict):
    '''
    Get general visits to datos.gob.es or visits to datos.gob.es by sections 
    
    :param what: type of data to get, 'total' = total, 'org' = by organization
    :type destination: string
    
    :param destination: directory destination of json file
    :type destination: string
    
    :param prefix: filename prefix of json file
    :type prefix: string
    '''

    check_access('dge_dashboard_json_visited_datasets', context, data_dict)

    what = data_dict.get('what')
    destination = data_dict.get('destination')
    prefix = data_dict.get('prefix')

    model = context['model']
    results = []
    string_result = None

    if what in DgeDashboardJsonCommand.VISITED_DATASET_TYPES:
        year_month_day_list = []
        sql = '''select distinct year_month, end_day from dge_ga_packages
                     order by year_month desc;'''
        result = model.Session.execute(sql)
        if result:
            for row in result:
                year_month_day_list.append({'y_m': row[0], 'day': row[1]})
        if year_month_day_list:
            for item in year_month_day_list:
                y_m = item.get('y_m', '')
                day = item.get('day', 0)
                sql = None
                if what == 'total':
                    sql = '''select concat('"month": "', concat(s1.year_month, 
                             concat('", "day": ', concat(s1.end_day, 
                             concat(', "name": "', concat(p.name, 
                             concat('", "title": "', concat(replace(p.title, '"', E'\\''), 
                             concat('", "publisher": "', concat(g.title, 
                             concat('", "visits": ', s1.pageviews))))))))))) as dict from 
                             package p, "group" g, (select year_month, end_day, 
                             package_name, pageviews, publisher_id from 
                             dge_ga_packages where year_month like '{p0}'
                             and organization_id is not null
                             and publisher_id is not null)s1
                             where p.name = s1.package_name
                             and p.private = false
                             and g.id like s1.publisher_id
                             order by s1.pageviews desc, p.title asc
                             limit 10;'''.format(p0=y_m)

                elif what == 'org':
                    '''
                        SDA-926 - Modificada query para obtener los 10 conjuntos de datos más visitados no eliminados,
                        es decir, que aún se encuentran en la tabla package
                    '''
                    sql = '''select concat('"org_id": "', organization_id,
                             concat(concat('", "month": "', concat(s1.year_month,
                             concat('", "day": ', concat(s1.end_day,
                             concat(', "name": "', concat(s1.package_name,
                             concat('", "title": "', concat(replace(s1.package_title, '"', E'\\''),
                             concat('", "publisher": "', concat(g.title,
                             concat('", "visits": ', concat(s1.pageviews,
                             concat(', "downloads": ',
                             (select coalesce(sum(dgr.total_events),0) from
                             dge_ga_resources dgr
                             where dgr.organization_id = s1.organization_id
                             and dgr.package_name = s1.package_name
                             and dgr.publisher_id = s1.publisher_id
                             and dgr.year_month = s1.year_month
                             and dgr.end_day = s1.end_day
                             and dgr.resource_id is not null)))))))))))))))) as dict
                             from "group" g,
                             (select year_month, end_day, organization_id,
                             package_name, pageviews, publisher_id, p.title as package_title,
                             ROW_NUMBER() OVER (PARTITION BY organization_id
                             order by pageviews DESC) as row_id
                             from dge_ga_packages, package p where year_month like '{p0}'
                             and organization_id is not null
                             and publisher_id is not null
                             and package_name = p.name
                             and p.state = 'active'
                             order by organization_id asc, pageviews desc,
                             package_name asc)s1
                             where s1.row_id <= 10
                             and g.id like s1.publisher_id
                             order by s1.organization_id asc, s1.pageviews,
                             s1.package_title asc;'''.format(p0=y_m)
                if sql:
                    result = model.Session.execute(sql)
                    if result:
                        i = 1
                        for row in result:
                            results.append('{"order": %s, %s}' % (i, row[0]));
                            i = i + 1

    string_result = "[" + ",".join(results) + "]"
    string_result = string_result.encode('utf-8')
    return _write_file(string_result, destination, prefix, what)


def dge_dashboard_csv_visited_datasets(context, data_dict):
    '''
    Get datasets visits and resources downloads by org

    :param what: type of data to get, 'total' = total, 'org' = by organization
    :type destination: string

    :param destination: directory destination of json file
    :type destination: string

    :param prefix: filename prefix of json file
    :type prefix: string
    '''
    check_access('dge_dashboard_csv_visited_datasets', context, data_dict)

    what = data_dict.get('what')
    destination = data_dict.get('destination')
    prefix = data_dict.get('prefix')

    model = context['model']

    if what in DgeDashboardJsonCommand.VISITED_DATASET_TYPES and what == 'org':
        organization_list = []
        sql = '''select distinct organization_id from dge_ga_packages;'''
        result = model.Session.execute(sql)
        if result:
            for row in result:
                organization_list.append(row[0])
        if organization_list:
            for org_id in organization_list:
                if org_id:
                    try:
                        sql = '''select dgp.year_month,	dgp.end_day,dgp.package_name,
	                            (case when (p.title is not null and p.state = 'active') then replace(p.title, '"', E'\\'') else dgp.package_name end) as title,
                                (case when (p.title is not null and p.state = 'active') then p.private else null end) as private,
	                            (case when g.title is not null then replace(g.title, '"', E'\\'') else dgp.publisher_id end) as pub,
	                            dgp.pageviews, res.dist from dge_ga_packages dgp
 	                            left join (	select aux.year_month, aux.package_name, string_agg(aux.distr, ';') as dist
	                            from (select dgr.year_month, dgr.package_name,
	                            concat(dgr.url , concat('(', concat(dgr.total_events , ')'))) as distr
	                            from dge_ga_resources dgr where dgr.organization_id = '{p0}') aux
	                            group by aux.year_month, aux.package_name) res on
	                            res.package_name = dgp.package_name and res.year_month = dgp.year_month
	                            left join package p on p.name = dgp.package_name
	                            left join "group" g on g.id = dgp.organization_id
	                            where dgp.organization_id = '{p0}'
	                            order by dgp.year_month desc, dgp.pageviews desc;'''.format(p0=org_id)
                        result = model.Session.execute(sql)
                        if result:
                            suffix = '%s_%s' % (what, org_id)
                            output_file = _get_complete_filename(destination, prefix, suffix, 'csv')
                            if output_file:
                                try:
                                    outfile = open(output_file, "w")
                                    try:
                                        print 'dge_dashboard_csv_visited_datasets - Writing csv with visited datasets to org %s ' % (
                                            org_id)
                                        writer = csv.writer(outfile)
                                        column_resources = '%s(%s)' % (
                                            'Resource', 'Downloads')
                                        writer.writerow(['Month'.encode('utf-8'), 'Day'.encode('utf-8'), 'Url'.encode('utf-8'), 'Dataset'.encode(
                                            'utf-8'), 'Private'.encode('utf-8'), 'Publisher'.encode('utf-8'), 'Visits'.encode('utf-8'), column_resources.encode('utf-8')])
                                        for month, day, name, title, private, pub, views, resources in result:
                                            writer.writerow([
                                                            (month if month is not None else ''),
                                                            (day if day is not None else ''),
                                                            name if name is not None else '',
                                                            (title.encode(
                                                                'utf-8') if title is not None else ''),
                                                            (private if private is not None else ''),
                                                            (pub.encode(
                                                                'utf-8') if pub is not None else ''),
                                                            views if views is not None else '',
                                                            (resources.encode('utf-8') if resources is not None else '')])
                                        print 'dge_dashboard_csv_visited_datasets - Writed csv with visited datasets to org %s data in %s' % (
                                                org_id, output_file)
                                    except Exception as e:
                                        print 'Exception in dge_dashboard_csv_visited_datasets %s' % e
                                        log.error(
                                            'Exception in dge_dashboard_csv_visited_datasets %s', e)
                                        output_file = None
                                    finally:
                                        outfile.close()
                                except Exception as e:
                                    print 'Exception in dge_dashboard_csv_visited_datasets %s' % e
                                    log.error(
                                        'Exception in dge_dashboard_csv_visited_datasets %s', e)
                                    output_file = None
                    except Exception as e:
                        print 'Exception in dge_dashboard_csv_visited_datasets %s' % e
                        log.error(
                            'Exception in dge_dashboard_csv_visited_datasets %s', e)


def dge_dashboard_csv_published_datasets_by_root_org(context, data_dict):
    '''
    Get dataset number by root organization

    :param date: the creation date of datasets must be before this
    :type date: string

    :param import_date: year-month of creation date of datasets
    :type import_date: string

    :param save: True only if save in file, False if only print
    :type save: boolean.
    
    :param destination: directory destination of csv file
    :type destination: string
    
    :param filename: filename prefix of csv file
    :type filename: string
    '''
    check_access('dge_dashboard_csv_published_datasets_by_root_org', context, data_dict)

    date = data_dict.get('date')
    import_date = data_dict.get('import_date')
    save = data_dict.get('save', False)
    destination = data_dict.get('destination')
    filename = data_dict.get('filename')
    model = context['model']
    results = []
    log.debug("Getting root organizations ....")
    sql = '''select ge.group_id, g.title, ge.value from group_extra ge, "group" g 
             where key like 'C_ID_UD_ORGANICA' and value in 
             (select distinct value from group_extra 
              where key like 'C_ID_DEP_UD_PRINCIPAL' and value is not null)
             and ge.group_id like g.id order by g.title asc;'''
    result = model.Session.execute(sql)
    for row in result:
        log.debug("Getting datasets number from root organization: %s ....", row[1])
        dir3 = row[2] if row[2] else ''
        sql2 = '''select g.title, count(p.*) num_datasets from "group" g 
                  left OUTER JOIN ( (select slu.id, slu.owner_org from 
                  (select h.* from (select ROW_NUMBER() OVER 
                  (PARTITION BY pr.continuity_id 
                  order by pr.revision_timestamp asc) as rn, * 
                  from package_revision pr where 
                  pr.revision_timestamp < '{p0}'::timestamp 
                  and pr.type like 'dataset') h where h.rn = 1 ) sc, 
                  (select h.* from (select ROW_NUMBER() OVER 
                  (PARTITION BY pr.continuity_id 
                  order by pr.revision_timestamp desc) as rn, * 
                  from package_revision pr where 
                  pr.revision_timestamp < '{p0}'::timestamp 
                  and pr.type like 'dataset') h where h.rn = 1
                  and h.state like 'active' and h.type like 'dataset'
                  and h.private = false
                  and h.expired_timestamp >= '{p0}'::timestamp) slu 
                  where sc.continuity_id = slu.continuity_id)) as p
                  on g.id = p.owner_org where 
                  g.id in (select distinct ge.group_id
                  from group_extra ge
                  where key like 'C_ID_DEP_UD_PRINCIPAL' and value like '{p1}' 
                  and group_id not like (select ge.group_id from group_extra ge
                  where key like 'C_ID_UD_ORGANICA' and value like '{p1}')) 
                  group by g.id, g.title
                  order by num_datasets desc, g.title asc;'''.format(p0=date, p1=dir3)
        subresult = model.Session.execute(sql2)
        for subrow in subresult:
            results.append((import_date, row[1].encode('utf-8'), subrow[0].encode('utf-8'), subrow[1]))

    if results:
        titleRow = ('Date', 'Root Organization', 'Organization', 'Dataset Number')
        if save:
            filename = _get_complete_filename(destination, filename, None, 'csv')
            if filename:
                try:
                    outfile = open(filename, 'w')
                    try:
                        writer = csv.writer(outfile)
                        writer.writerow(titleRow)
                        for row in results:
                            writer.writerow(row)
                    except Exception as e:
                        log.error('Exception %s', e)
                        filename = None
                    finally:
                        outfile.close()
                except Exception as e:
                    log.error('Exception %s', e)
                    filename = None
        else:
            filename = None
            print 'Results:'
            print titleRow;
            for row in results:
                print (row)
    return filename


def dge_dashboard_json_organization_by_administration_level(context, data_dict):
    '''
    Get current publishers by administration level in two groups: harvester publishers and manual loading publishers
     and write json files

    :param destination: directory destination of json file
    :type destination: string

    :param filename: json filename
    :type filename: string
    '''

    check_access('dge_dashboard_json_organization_by_administration_level', context, data_dict)

    destination = data_dict.get('destination')
    filename = data_dict.get('filename')

    model = context['model']

    sql = '''select concat('[', concat(string_agg(s8.dict, ','), ']')) from
             (select concat('{"date": "', concat((to_char(now(), 'YYYY-MM-DD')), 
			 concat ('", "organization": "', concat(s7.title)),
			 concat ('", "adm_level": "', concat(s7.adm_level)),
             concat('", "type_actualization": "', concat(s7.publisher, '"', '}')))) as dict from
			 (select s6.title as title, 
             (CASE when s6.harvest is False OR s6.guid is False then 'manual' 
             ELSE 'federacion' END) as publisher, 
             s6.adm_level as adm_level from (select s5.title as title, 
             s3.guid as guid, (CASE WHEN s4.owner_org is NULL then False 
             ELSE True END) as harvest, s5.adm_level from 
             (select distinct s1.owner_org, s2.pub, s2.guid from (select p1.id, 
             p1.owner_org from package p1 where p1.state like 'active' 
             and p1.type like 'dataset'and p1.private = false)s1,
             (select pe1.pub, pe1.package_id, (CASE WHEN pe2.package_id IS NULL then False 
             ELSE True END) as guid from (select pe.value as pub, 
             pe.package_id from package_extra pe where pe.state like 'active' 
             and pe.key like 'publisher') pe1 left outer join (select pe.package_id 
             from package_extra pe where pe.state like 'active' 
             and pe.key like 'guid') pe2 on pe1.package_id = pe2.package_id)s2
             where s1.id = s2. package_id) s3 left outer join
             (select distinct p2.owner_org from package p2 where 
             p2.state like 'active' and p2.type like 'harvest' 
             and p2.private = false)s4 on s4.owner_org = s3.owner_org,
             (select g.id,g,title, substring(ge.value, 0, 2) as adm_level from "group" g, 
             group_extra ge where ge.group_id = g.id and g.state like 'active' 
             and g.type like 'organization' and ge.state like 'active' 
             and ge.key like 'C_ID_UD_ORGANICA')s5 where s3.pub = s5.id
             group by s5.title, s5.adm_level, s3.guid, harvest order by title)s6
             group by s6.title, s6.adm_level, publisher order by title)s7
			 group by s7.adm_level, s7.publisher, s7.title order by title)s8;'''

    result = _execute_fetchone_sql(model, sql)
    string_result = result.encode('utf-8')

    return _write_file(string_result, destination, filename, None)


def dge_dashboard_json_organization_name(context, data_dict):
    '''
    Get dge_dashboard_drupal_contents table data and write json files

    :param destination: directory destination of json file
    :type destination: string

    :param filename: json filename
    :type filename: string
    '''

    check_access('dge_dashboard_json_organization_name', context, data_dict)

    destination = data_dict.get('destination')
    filename = data_dict.get('filename')

    model = context['model']

    sql = '''select concat('[', concat(string_agg(r.dict, ','), ']'))from
             (select concat('{"id": "', concat(g.id, 
             concat('", "title": "', concat(g.title,'"}')))) as dict
             from "group" g where state='active' and type='organization')r;'''

    result = _execute_fetchone_sql(model, sql)
    string_result = result.encode('utf-8')
    return _write_file(string_result, destination, filename, None)
