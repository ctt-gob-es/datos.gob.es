<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_bulletin (datos.gob.es)".
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
 * dgef_bulletin.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgef_bulletin_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_3e4d34a5-1586-47ac-a0e5-7bc2bfa1c1e4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'bulletin_detail',
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
              'bulletin' => 'bulletin',
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
  $display->uuid = '7ed8fe8f-d968-40d2-ab3d-b81b2a7e99f9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-83ebe7dd-98d2-4277-9d49-159ff0f1c8fe';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'bulletin_detail-panel_pane_1';
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
    $pane->uuid = '83ebe7dd-98d2-4277-9d49-159ff0f1c8fe';
    $display->content['new-83ebe7dd-98d2-4277-9d49-159ff0f1c8fe'] = $pane;
    $display->panels['center'][0] = 'new-83ebe7dd-98d2-4277-9d49-159ff0f1c8fe';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_3e4d34a5-1586-47ac-a0e5-7bc2bfa1c1e4'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_bulletin_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'bulletin';
  $page->task = 'page';
  $page->admin_title = 'bulletin';
  $page->admin_description = '';
  $page->path = 'boletines';
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
  $handler->name = 'page_bulletin__panel';
  $handler->task = 'page';
  $handler->subtask = 'bulletin';
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
        'identifier' => 'View: bulletin_search',
        'keyword' => 'view',
        'name' => 'view:bulletin_search-ctools_context_1',
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
  $display->title = 'Boletines';
  $display->uuid = '2fa75328-c2cf-4fd1-865d-cdc5c8e8e44f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f99c18da-b832-4227-9a9f-49fbd98e2331';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views-5534df93bef32048c1974548a7eb6b0a';
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
    $pane->uuid = 'f99c18da-b832-4227-9a9f-49fbd98e2331';
    $display->content['new-f99c18da-b832-4227-9a9f-49fbd98e2331'] = $pane;
    $display->panels['center'][0] = 'new-f99c18da-b832-4227-9a9f-49fbd98e2331';
    $pane = new stdClass();
    $pane->pid = 'new-8549a5d2-4c48-4de2-9e6c-002871d71a0e';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'current_search-bulletin';
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
    $pane->uuid = '8549a5d2-4c48-4de2-9e6c-002871d71a0e';
    $display->content['new-8549a5d2-4c48-4de2-9e6c-002871d71a0e'] = $pane;
    $display->panels['center'][1] = 'new-8549a5d2-4c48-4de2-9e6c-002871d71a0e';
    $pane = new stdClass();
    $pane->pid = 'new-162797d7-0308-49ed-ac72-b86beb10c2d6';
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
    $pane->uuid = '162797d7-0308-49ed-ac72-b86beb10c2d6';
    $display->content['new-162797d7-0308-49ed-ac72-b86beb10c2d6'] = $pane;
    $display->panels['center'][2] = 'new-162797d7-0308-49ed-ac72-b86beb10c2d6';
    $pane = new stdClass();
    $pane->pid = 'new-a56a68ab-d8dd-4fa7-9de0-79a2f23ff075';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'bulletin_search-panel_pane_1';
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
    $pane->uuid = 'a56a68ab-d8dd-4fa7-9de0-79a2f23ff075';
    $display->content['new-a56a68ab-d8dd-4fa7-9de0-79a2f23ff075'] = $pane;
    $display->panels['center'][3] = 'new-a56a68ab-d8dd-4fa7-9de0-79a2f23ff075';
    $pane = new stdClass();
    $pane->pid = 'new-10cc46f2-f1f5-4a38-9eea-866ca6e249f6';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-rIZBtZ9hCgMAqlZ9XjqXujwzVsmCgIEN';
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
    $pane->uuid = '10cc46f2-f1f5-4a38-9eea-866ca6e249f6';
    $display->content['new-10cc46f2-f1f5-4a38-9eea-866ca6e249f6'] = $pane;
    $display->panels['filters'][0] = 'new-10cc46f2-f1f5-4a38-9eea-866ca6e249f6';
    $pane = new stdClass();
    $pane->pid = 'new-2b50439e-d1ed-4644-84e5-7fe66294ecac';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-q74O6MW0ls6P8JHMI4pSbyi6yy2bkthR';
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
    $pane->uuid = '2b50439e-d1ed-4644-84e5-7fe66294ecac';
    $display->content['new-2b50439e-d1ed-4644-84e5-7fe66294ecac'] = $pane;
    $display->panels['filters'][1] = 'new-2b50439e-d1ed-4644-84e5-7fe66294ecac';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['bulletin'] = $page;

  return $pages;

}
