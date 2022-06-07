<?php

/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_event (datos.gob.es)".
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
 * dgef_event.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function dgef_event_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'event';
  $item->label = 'event';
  $item->settings = array(
    'items' => array(
      'custom_text' => array(
        'id' => 'text',
        'label' => 'custom_text',
        'text' => '[facetapi_results:result-count] event found <span class="keyword-search">for "[facetapi_results:keys]"</span>',
        'plural' => 1,
        'text_plural' => '[facetapi_results:result-count] events found <span class="keyword-search">for "[facetapi_results:keys]"</span>',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 0,
        'element' => '0',
        'css' => 0,
        'classes' => '',
        'weight' => '-50',
      ),
      'dge_search_field_group' => array(
        'id' => 'group',
        'label' => 'dge_search_field_group',
        'field_pattern' => '[facetapi_facet:facet-label]:',
        'nofollow' => 1,
        'weight' => '-49',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '1',
    ),
  );
  $export['event'] = $item;

  return $export;
}
