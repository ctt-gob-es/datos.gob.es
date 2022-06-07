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
 * dgef_event.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgef_event_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_159a6f35-a7d9-4686-9a2b-babc013f8819';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'event_detail',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'event' => 'event',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:dge_detail_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '2a2b85ea-8a6b-496c-abf5-b4e8d7a76510';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e650c5b1-f91f-4ac9-8859-689f4081b512';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'event_detail-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e650c5b1-f91f-4ac9-8859-689f4081b512';
    $display->content['new-e650c5b1-f91f-4ac9-8859-689f4081b512'] = $pane;
    $display->panels['center'][0] = 'new-e650c5b1-f91f-4ac9-8859-689f4081b512';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_159a6f35-a7d9-4686-9a2b-babc013f8819'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_event_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'event';
  $page->task = 'page';
  $page->admin_title = 'event';
  $page->admin_description = '';
  $page->path = 'eventos';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_event__panel';
  $handler->task = 'page';
  $handler->subtask = 'event';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'View: event_search',
        'keyword' => 'view',
        'name' => 'view:event_search-ctools_context_1',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible:dge_lists_2cols';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'centrado',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '30.061484409310495',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 0,
      ),
      'centrado' => array(
        'type' => 'region',
        'title' => 'Centrado',
        'width' => '69.9385155906895',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'centrado' => NULL,
      'filters' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Eventos';
  $display->uuid = '79623c75-b0f4-4ae6-abef-9fe23c4a75c7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-458ce113-9322-4a4f-8504-12f436a415c0';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-event_search-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '458ce113-9322-4a4f-8504-12f436a415c0';
    $display->content['new-458ce113-9322-4a4f-8504-12f436a415c0'] = $pane;
    $display->panels['center'][0] = 'new-458ce113-9322-4a4f-8504-12f436a415c0';
    $pane = new stdClass();
    $pane->pid = 'new-bac89d89-211a-4a14-988a-570bb20496f0';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'current_search-event';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bac89d89-211a-4a14-988a-570bb20496f0';
    $display->content['new-bac89d89-211a-4a14-988a-570bb20496f0'] = $pane;
    $display->panels['center'][1] = 'new-bac89d89-211a-4a14-988a-570bb20496f0';
    $pane = new stdClass();
    $pane->pid = 'new-9fca610d-e3fb-4731-a849-1bcb88a84c3a';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'search_api_sorts-search-sorts';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '9fca610d-e3fb-4731-a849-1bcb88a84c3a';
    $display->content['new-9fca610d-e3fb-4731-a849-1bcb88a84c3a'] = $pane;
    $display->panels['center'][2] = 'new-9fca610d-e3fb-4731-a849-1bcb88a84c3a';
    $pane = new stdClass();
    $pane->pid = 'new-19621012-a684-4d62-b388-276109928d3c';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'event_search-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '19621012-a684-4d62-b388-276109928d3c';
    $display->content['new-19621012-a684-4d62-b388-276109928d3c'] = $pane;
    $display->panels['center'][3] = 'new-19621012-a684-4d62-b388-276109928d3c';
    $pane = new stdClass();
    $pane->pid = 'new-a559b2b4-dad9-4464-8b1b-b05a94ac1d98';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-cNE0eTHCbtNZiqM9984vkl310jBx4Nk1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Etiquetas',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a559b2b4-dad9-4464-8b1b-b05a94ac1d98';
    $display->content['new-a559b2b4-dad9-4464-8b1b-b05a94ac1d98'] = $pane;
    $display->panels['filters'][0] = 'new-a559b2b4-dad9-4464-8b1b-b05a94ac1d98';
    $pane = new stdClass();
    $pane->pid = 'new-95559a68-1d5c-4e40-97f1-65b6d9d9beaf';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-CA30xR0xhzPrMUtlFPuMTUYN76IPoDuW';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Fecha',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '95559a68-1d5c-4e40-97f1-65b6d9d9beaf';
    $display->content['new-95559a68-1d5c-4e40-97f1-65b6d9d9beaf'] = $pane;
    $display->panels['filters'][1] = 'new-95559a68-1d5c-4e40-97f1-65b6d9d9beaf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['event'] = $page;

  return $pages;

}
