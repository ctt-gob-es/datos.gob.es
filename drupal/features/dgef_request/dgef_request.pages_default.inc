<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_request (datos.gob.es)".
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
 * dgef_request.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgef_request_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_15c2dbe6-c043-4d60-9b2b-ca5ece524bb5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'request_detail',
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
              'request' => 'request',
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
  $display->uuid = '10564ab4-780d-44a2-8ae1-26721935728a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-711cee84-0a77-4c40-be03-a3bcfed3911e';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'request_detail-panel_pane_1';
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
    $pane->uuid = '711cee84-0a77-4c40-be03-a3bcfed3911e';
    $display->content['new-711cee84-0a77-4c40-be03-a3bcfed3911e'] = $pane;
    $display->panels['center'][0] = 'new-711cee84-0a77-4c40-be03-a3bcfed3911e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_15c2dbe6-c043-4d60-9b2b-ca5ece524bb5'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_request_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'request';
  $page->task = 'page';
  $page->admin_title = 'request';
  $page->admin_description = '';
  $page->path = 'peticiones-datos';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_request__panel';
  $handler->task = 'page';
  $handler->subtask = 'request';
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
        'identifier' => 'View: request_search',
        'keyword' => 'view',
        'name' => 'view:request_search-ctools_context_1',
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
    ),
  );
  $display->cache = array();
  $display->title = 'Peticiones de datos';
  $display->uuid = '3bcf6ceb-da6d-4b8b-a71d-80e0555f1ba2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c9bd8766-58a6-4402-aa92-44635ecff376';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views-c22dba73854ace20ac4f2d36eadf8e93';
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
    $pane->uuid = 'c9bd8766-58a6-4402-aa92-44635ecff376';
    $display->content['new-c9bd8766-58a6-4402-aa92-44635ecff376'] = $pane;
    $display->panels['center'][0] = 'new-c9bd8766-58a6-4402-aa92-44635ecff376';
    $pane = new stdClass();
    $pane->pid = 'new-11931554-94d0-4bcb-a9a7-65f5a6117b02';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'current_search-request';
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
    $pane->uuid = '11931554-94d0-4bcb-a9a7-65f5a6117b02';
    $display->content['new-11931554-94d0-4bcb-a9a7-65f5a6117b02'] = $pane;
    $display->panels['center'][1] = 'new-11931554-94d0-4bcb-a9a7-65f5a6117b02';
    $pane = new stdClass();
    $pane->pid = 'new-bf4ca1b9-0b9e-4ca0-8e04-1f01f097d956';
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
    $pane->uuid = 'bf4ca1b9-0b9e-4ca0-8e04-1f01f097d956';
    $display->content['new-bf4ca1b9-0b9e-4ca0-8e04-1f01f097d956'] = $pane;
    $display->panels['center'][2] = 'new-bf4ca1b9-0b9e-4ca0-8e04-1f01f097d956';
    $pane = new stdClass();
    $pane->pid = 'new-5f808faf-e9f6-4a85-8b77-bc6bd5ec80ca';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'request_search-panel_pane_1';
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
    $pane->uuid = '5f808faf-e9f6-4a85-8b77-bc6bd5ec80ca';
    $display->content['new-5f808faf-e9f6-4a85-8b77-bc6bd5ec80ca'] = $pane;
    $display->panels['center'][3] = 'new-5f808faf-e9f6-4a85-8b77-bc6bd5ec80ca';
    $pane = new stdClass();
    $pane->pid = 'new-3e59cc86-5191-4595-9216-79fdfffd9fe0';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-av8uPaH1LLasUMpJMgmF6mRr8weQrYAe';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Categoría',
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
    $pane->uuid = '3e59cc86-5191-4595-9216-79fdfffd9fe0';
    $display->content['new-3e59cc86-5191-4595-9216-79fdfffd9fe0'] = $pane;
    $display->panels['filters'][0] = 'new-3e59cc86-5191-4595-9216-79fdfffd9fe0';
    $pane = new stdClass();
    $pane->pid = 'new-9df40662-53cc-4f29-a1b6-4243d3c56619';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-9NOAoe8uBUl4OUbEn5HgE7l2EDhiYvCq';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Estado',
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
    $pane->uuid = '9df40662-53cc-4f29-a1b6-4243d3c56619';
    $display->content['new-9df40662-53cc-4f29-a1b6-4243d3c56619'] = $pane;
    $display->panels['filters'][1] = 'new-9df40662-53cc-4f29-a1b6-4243d3c56619';
    $pane = new stdClass();
    $pane->pid = 'new-e6d5baae-563b-44af-b23b-5a497f57c6ac';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-SBYYemO38b6Rylfgm1e98kSY1FmpXBW9';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e6d5baae-563b-44af-b23b-5a497f57c6ac';
    $display->content['new-e6d5baae-563b-44af-b23b-5a497f57c6ac'] = $pane;
    $display->panels['filters'][2] = 'new-e6d5baae-563b-44af-b23b-5a497f57c6ac';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['request'] = $page;

  return $pages;

}
