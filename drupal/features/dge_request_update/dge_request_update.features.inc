<?php

/**	 
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	* 
 	* This file is part of "dge_request_update (datos.gob.es)".
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
 * dge_request_update.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dge_request_update_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_sort().
 */
function dge_request_update_default_search_api_sort() {
  $items = array();
  $items['request_index__field_number_subscriptors'] = entity_import('search_api_sort', '{
    "index_id" : "request_index",
    "field" : "field_number_subscriptors",
    "name" : "Solicitantes",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "request_index__field_number_subscriptors",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "number_subscriptors" },
    "rdf_mapping" : []
  }');
  return $items;
}
