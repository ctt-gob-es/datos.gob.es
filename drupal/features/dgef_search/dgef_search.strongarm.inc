<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_search (datos.gob.es)".
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file
 * dgef_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dgef_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_search_api_facetapi_DAY';
  $strongarm->value = 'F j, Y';
  $export['date_format_search_api_facetapi_DAY'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_search_api_facetapi_HOUR';
  $strongarm->value = 'H:__';
  $export['date_format_search_api_facetapi_HOUR'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_search_api_facetapi_MINUTE';
  $strongarm->value = 'H:i';
  $export['date_format_search_api_facetapi_MINUTE'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_search_api_facetapi_MONTH';
  $strongarm->value = 'F Y';
  $export['date_format_search_api_facetapi_MONTH'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_search_api_facetapi_SECOND';
  $strongarm->value = 'H:i:s';
  $export['date_format_search_api_facetapi_SECOND'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_search_api_facetapi_YEAR';
  $strongarm->value = 'Y';
  $export['date_format_search_api_facetapi_YEAR'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:apachesolr@solr';
  $strongarm->value = -1;
  $export['facetapi:block_cache:apachesolr@solr'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_facets_search_ids';
  $strongarm->value = array(
    'app' => array(
      'search_api_views:apps_search:ctools_context_1' => 'search_api_views:apps_search:ctools_context_1',
      'search_api_views:apps_search:page' => 'search_api_views:apps_search:page',
      'search_api_views:apps_search:panel_pane_1' => 'search_api_views:apps_search:panel_pane_1',
    ),
    'success_index' => array(
      'search_api_views:success_view:ctools_context_1' => 'search_api_views:success_view:ctools_context_1',
      'search_api_views:success_view:panel_pane_1' => 'search_api_views:success_view:panel_pane_1',
    ),
    'blog_index' => array(
      'search_api_views:blog_search:ctools_context_1' => 'search_api_views:blog_search:ctools_context_1',
      'search_api_views:blog_search:panel_pane_1' => 'search_api_views:blog_search:panel_pane_1',
    ),
    'talk_index' => array(
      'search_api_views:talk_search:ctools_context_1' => 'search_api_views:talk_search:ctools_context_1',
      'search_api_views:talk_search:panel_pane_1' => 'search_api_views:talk_search:panel_pane_1',
    ),
    'event_index' => array(
      'search_api_views:event_search:ctools_context_1' => 'search_api_views:event_search:ctools_context_1',
      'search_api_views:event_search:panel_pane_1' => 'search_api_views:event_search:panel_pane_1',
    ),
    'doc_index' => array(
      'search_api_views:doc_search:ctools_context_1' => 'search_api_views:doc_search:ctools_context_1',
      'search_api_views:doc_search:panel_pane_1' => 'search_api_views:doc_search:panel_pane_1',
    ),
    'request_index' => array(
      'search_api_views:request_search:ctools_context_1' => 'search_api_views:request_search:ctools_context_1',
      'search_api_views:request_search:panel_pane_1' => 'search_api_views:request_search:panel_pane_1',
    ),
    'initiative_index' => array(
      'search_api_views:initiative_search:ctools_context_1' => 'search_api_views:initiative_search:ctools_context_1',
      'search_api_views:initiative_search:panel_pane_1' => 'search_api_views:initiative_search:panel_pane_1',
    ),
    'bulletin_index' => array(
      'search_api_views:bulletin_search:panel_pane_1' => 'search_api_views:bulletin_search:panel_pane_1',
    ),
    'buscador_general' => array(
      'SearchApiQuery' => 'SearchApiQuery',
      'search_api_views:general_search:panel_pane_1' => 'search_api_views:general_search:panel_pane_1',
    ),
  );
  $export['search_api_facets_search_ids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_solr_last_optimize';
  $strongarm->value = 1470129636;
  $export['search_api_solr_last_optimize'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_solr_site_hash';
  $strongarm->value = '1010ye';
  $export['search_api_solr_site_hash'] = $strongarm;

  return $export;
}
