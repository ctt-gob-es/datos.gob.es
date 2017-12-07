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

#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''API functions for get table data in CKANEXT_DGE_DASHBOARD.'''
import codecs
import hashlib
import json
import re
import csv

import logging
import datetime
import sqlalchemy as sa

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
from ckanext.dge_dashboard.commands.dge_dashboard import DgeDashboardJsonCommand

from ckanext.harvest.logic.action.get import (
    harvest_source_show, harvest_job_list, _get_sources_for_user)
from _sqlite3 import IntegrityError

from pylons import config

log = logging.getLogger(__name__)

def _get_complete_filename(destination=None, prefix=None, suffix= None, extension = 'json'):

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

    filename = destination + '/' + prefix + (('_' + suffix) if suffix else '')  + '.' + extension
    return filename

def _write_file(filedata=None, destination=None, prefix=None, suffix= None, extension = 'json'):

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

def _execute_drupal_sql(sql=None):
    if sql:
        try:
            result = None
            results = []
            engine = create_engine(config.get('ckanext.dge_drupal_users.connection', None))
            if engine:
                result = engine.execute(sql)
                value = None
            if result:
                for row in result:
                    results.append(row[0])
            if results and len(results) > 0:
                return "[" + ",".join(results) + "]"
        except Exception as e:
            log.error('Exception %s', e)
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
             concat(', "manual_loading_publishers":', 
             concat(d.manual_loading_publishers, '}')))))) as dict
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

    sql = '''select concat('[', concat(string_agg(s9.dict, ','), ']')) from
             (select concat('{"date": "', concat((to_char(now(), 'YYYY-MM-DD')), 
             concat('", "adm_level": "', concat(s8.adm_level, concat('", ', 
             concat(string_agg(s8.f , ', '), '}')))))) as dict from
             (select concat('"', concat(s7.publisher, concat('": ', s7.total))) as f, 
             s7.adm_level from (select sum(s6.num) as total, 
             (CASE WHEN s6.harvest is False OR s6.guid is False then 'manual_loading_publishers' 
             ELSE 'harvester_publishers' END) as publisher, 
             s6.adm_level as adm_level from (select count(*)as num, 
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
             (select g.id, substring(ge.value, 0, 2) as adm_level from "group" g, 
             group_extra ge where ge.group_id = g.id and g.state like 'active' 
             and g.type like 'organization' and ge.state like 'active' 
             and ge.key like 'C_ID_UD_ORGANICA')s5 where s3.pub = s5.id
             group by s5.adm_level, s3.guid, harvest order by adm_level)s6
             group by s6.adm_level, publisher order by adm_level)s7
             group by s7.adm_level, s7.publisher, s7.total)s8
             group by s8.adm_level)s9;'''

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
        elif what == 'adm_level':
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
                year_month_day_list.append({'y_m':row[0], 'day': row[1]})
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
                             and g.id like s1.publisher_id
                             order by s1.pageviews desc, p.title asc
                             limit 10;'''.format(p0=y_m)

                elif what == 'org':
                    sql = '''select concat('"org_id": "', organization_id, 
                             concat(concat('", "month": "', concat(s1.year_month, 
                             concat('", "day": ', concat(s1.end_day, 
                             concat(', "name": "', concat(p.name, 
                             concat('", "title": "', concat(replace(p.title, '"', E'\\''), 
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
                             from package p, "group" g,
                             (select year_month, end_day, organization_id, 
                             package_name, pageviews, publisher_id, 
                             ROW_NUMBER() OVER (PARTITION BY organization_id 
                             order by pageviews DESC) as row_id
                             from dge_ga_packages where year_month like '{p0}'
                             and organization_id is not null
                             and publisher_id is not null
                             order by organization_id asc, pageviews desc, 
                             package_name asc)s1
                             where s1.row_id <= 10
                             and p.name = s1.package_name
                             and g.id like s1.publisher_id
                             order by s1.organization_id asc, s1.pageviews, 
                             p.title asc;'''.format(p0=y_m)
                if sql:
                    result = model.Session.execute(sql)
                    if result:
                        i = 1
                        for row in result:
                            results.append('{"order": %s, %s}' % (i, row[0]));
                            i = i+1

    string_result = "[" + ",".join(results) + "]"
    string_result = string_result.encode('utf-8')
  
    return _write_file(string_result, destination, prefix, what)


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
                  order by num_datasets desc, g.title asc;'''.format(p0 = date, p1 = dir3)
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