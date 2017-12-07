<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_initiative_import (datos.gob.es)".
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file
 * dgef_initiative_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function dgef_initiative_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'initiative';
  $feeds_importer->config = array(
    'name' => 'initiative',
    'description' => 'Initiatives importer',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
        'delete_uploaded_file' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'id',
            'target' => 'nid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'i_title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'i_title',
            'target' => 'field_initiative_link:title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'i_link',
            'target' => 'field_initiative_link:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'i_organization',
            'target' => 'field_initiative_organization',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'i_latitude',
            'target' => 'field_geoposition:lat',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'i_longitude',
            'target' => 'field_geoposition:lon',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'i_admin_level',
            'target' => 'field_initiative_admin_level',
            'term_search' => '0',
            'autocreate' => 0,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'i_reuse_level',
            'target' => 'field_initiative_reuse_level',
            'term_search' => '0',
            'autocreate' => 0,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'i_search_type',
            'target' => 'field_initiative_search_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'i_category',
            'target' => 'field_initiative_category',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'i_strategy',
            'target' => 'field_initiative_strategy:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'i_download',
            'target' => 'field_initiative_download:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'i_webservice',
            'target' => 'field_initiative_webservice:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'i_api_ckan',
            'target' => 'field_initiative_api_ckan:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'i_sparql',
            'target' => 'field_initiative_sparql:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'i_license',
            'target' => 'field_initiative_license',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'i_channel',
            'target' => 'field_initiative_channel:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'i_catalog',
            'target' => 'field_initiative_catalog:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'i_resources',
            'target' => 'field_initiative_resources:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'i_collaborate',
            'target' => 'field_initiative_collaborate',
            'unique' => FALSE,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'i_old_id',
            'target' => 'field_initiative_old_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          22 => array(
            'source' => 'i_status',
            'target' => 'status',
            'unique' => FALSE,
            'language' => 'und',
          ),
          23 => array(
            'source' => 'i_restful',
            'target' => 'field_initiative_restful_api:url',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'initiative',
        'language' => 'es',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['initiative'] = $feeds_importer;

  return $export;
}
