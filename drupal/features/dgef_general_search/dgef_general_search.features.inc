<?php

/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_general_search (datos.gob.es)".
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
 * dgef_general_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgef_general_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dgef_general_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function dgef_general_search_default_search_api_index() {
  $items = array();
  $items['buscador_general'] = entity_import('search_api_index', '{
    "name" : "global_index",
    "machine_name" : "buscador_general",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [
          "app",
          "page",
          "blog",
          "bulletin",
          "success",
          "doc",
          "aporta",
          "talk",
          "event",
          "request"
        ]
      },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_bulletin_description:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_bulletin_parag" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_bulletin_parag:field_bulletin_parag_text:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_bulletin_parag:field_bulletin_parag_title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_request_tx_status" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "language" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" },
        "source" : { "type" : "integer", "entity_type" : "node" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "string" },
        "title2" : { "type" : "text", "boost" : "2.0" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "lang_field" : "language",
            "languages" : { "es" : "es", "en" : "en", "ca" : "ca", "gl" : "gl", "eu" : "eu" }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title2" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_bulletin_description:value" : true,
              "field_bulletin_parag:field_bulletin_parag_title" : true,
              "field_bulletin_parag:field_bulletin_parag_text:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title2" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_bulletin_description:value" : true,
              "field_bulletin_parag:field_bulletin_parag_title" : true,
              "field_bulletin_parag:field_bulletin_parag_text:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "title2" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_bulletin_description:value" : true,
              "field_bulletin_parag:field_bulletin_parag_title" : true,
              "field_bulletin_parag:field_bulletin_parag_text:value" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title2" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_bulletin_description:value" : true,
              "field_bulletin_parag:field_bulletin_parag_title" : true,
              "field_bulletin_parag:field_bulletin_parag_text:value" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title2" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_bulletin_description:value" : true,
              "field_bulletin_parag:field_bulletin_parag_title" : true,
              "field_bulletin_parag:field_bulletin_parag_text:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
