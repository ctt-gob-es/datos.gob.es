<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_aporta_meeting (datos.gob.es)".
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
 * dgef_aporta_meeting.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgef_aporta_meeting_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_04761d62-15b8-4e44-8734-32c0dacb3d10';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 9;
  $handler->conf = array(
    'title' => 'aporta_detail',
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
              'aporta' => 'aporta',
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
  $display->uuid = '0abcaf9a-f569-48e3-8372-13f0fa93c7b3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-301f633c-de43-4ba0-8ef6-424dca0f03d8';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'aporta_detail-panel_pane_1';
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
    $pane->uuid = '301f633c-de43-4ba0-8ef6-424dca0f03d8';
    $display->content['new-301f633c-de43-4ba0-8ef6-424dca0f03d8'] = $pane;
    $display->panels['center'][0] = 'new-301f633c-de43-4ba0-8ef6-424dca0f03d8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_04761d62-15b8-4e44-8734-32c0dacb3d10'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_aporta_meeting_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'aporta';
  $page->task = 'page';
  $page->admin_title = 'aporta';
  $page->admin_description = '';
  $page->path = 'encuentros-aporta';
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
  $handler->name = 'page_aporta__panel';
  $handler->task = 'page';
  $handler->subtask = 'aporta';
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
        'identifier' => 'View: aporta_search',
        'keyword' => 'view',
        'name' => 'view:aporta_search-ctools_context_1',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
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
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Centrado',
        'width' => 100,
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
      'left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Encuentros Aporta';
  $display->uuid = '4ff54d5b-a3d2-4df6-828b-92a82702bd66';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e82c3280-1ec5-4ced-af37-92d267a94a86';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-aporta_search-panel_pane_1';
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
    $pane->uuid = 'e82c3280-1ec5-4ced-af37-92d267a94a86';
    $display->content['new-e82c3280-1ec5-4ced-af37-92d267a94a86'] = $pane;
    $display->panels['center'][0] = 'new-e82c3280-1ec5-4ced-af37-92d267a94a86';
    $pane = new stdClass();
    $pane->pid = 'new-c62ec863-8f37-4684-a375-e041b1215209';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'current_search-aporta';
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
    $pane->uuid = 'c62ec863-8f37-4684-a375-e041b1215209';
    $display->content['new-c62ec863-8f37-4684-a375-e041b1215209'] = $pane;
    $display->panels['center'][1] = 'new-c62ec863-8f37-4684-a375-e041b1215209';
    $pane = new stdClass();
    $pane->pid = 'new-47420163-a824-4ae3-84fa-e0b106b4126e';
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
    $pane->uuid = '47420163-a824-4ae3-84fa-e0b106b4126e';
    $display->content['new-47420163-a824-4ae3-84fa-e0b106b4126e'] = $pane;
    $display->panels['center'][2] = 'new-47420163-a824-4ae3-84fa-e0b106b4126e';
    $pane = new stdClass();
    $pane->pid = 'new-2dbfa7a5-b0eb-4622-9757-b40f801393ce';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'aporta_search-panel_pane_1';
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
    $pane->uuid = '2dbfa7a5-b0eb-4622-9757-b40f801393ce';
    $display->content['new-2dbfa7a5-b0eb-4622-9757-b40f801393ce'] = $pane;
    $display->panels['center'][3] = 'new-2dbfa7a5-b0eb-4622-9757-b40f801393ce';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['aporta'] = $page;

  return $pages;

}
