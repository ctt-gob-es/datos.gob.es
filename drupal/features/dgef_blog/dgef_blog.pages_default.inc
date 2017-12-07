<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_blog (datos.gob.es)".
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
 * dgef_blog.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgef_blog_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_036c3474-9235-4652-b098-4c1ba8d4042c';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'blog_detail',
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
              'blog' => 'blog',
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
  $display->uuid = 'fdaae351-1da1-40b4-b873-408e07983e84';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-64e54214-2532-46b7-b6a6-347048d67ee4';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'blog_detail-panel_pane_1';
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
    $pane->uuid = '64e54214-2532-46b7-b6a6-347048d67ee4';
    $display->content['new-64e54214-2532-46b7-b6a6-347048d67ee4'] = $pane;
    $display->panels['center'][0] = 'new-64e54214-2532-46b7-b6a6-347048d67ee4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_036c3474-9235-4652-b098-4c1ba8d4042c'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_blog_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'blog';
  $page->task = 'page';
  $page->admin_title = 'blog';
  $page->admin_description = '';
  $page->path = 'blog';
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
  $handler->name = 'page_blog__panel';
  $handler->task = 'page';
  $handler->subtask = 'blog';
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
        'identifier' => 'View: blog_search',
        'keyword' => 'view',
        'name' => 'view:blog_search-ctools_context_1',
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
  $display->title = 'Noticias';
  $display->uuid = '6785803b-1aa7-45ef-8682-b48e4a235c89';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-65f58156-d654-4ace-8fb6-c26c1246af88';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-blog_search-panel_pane_1';
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
    $pane->uuid = '65f58156-d654-4ace-8fb6-c26c1246af88';
    $display->content['new-65f58156-d654-4ace-8fb6-c26c1246af88'] = $pane;
    $display->panels['center'][0] = 'new-65f58156-d654-4ace-8fb6-c26c1246af88';
    $pane = new stdClass();
    $pane->pid = 'new-d683f08a-8b67-4e68-ae8d-8a458d994840';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'current_search-blog';
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
    $pane->uuid = 'd683f08a-8b67-4e68-ae8d-8a458d994840';
    $display->content['new-d683f08a-8b67-4e68-ae8d-8a458d994840'] = $pane;
    $display->panels['center'][1] = 'new-d683f08a-8b67-4e68-ae8d-8a458d994840';
    $pane = new stdClass();
    $pane->pid = 'new-5a9cf659-1e30-4ae7-9220-36a020c61c0f';
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
    $pane->uuid = '5a9cf659-1e30-4ae7-9220-36a020c61c0f';
    $display->content['new-5a9cf659-1e30-4ae7-9220-36a020c61c0f'] = $pane;
    $display->panels['center'][2] = 'new-5a9cf659-1e30-4ae7-9220-36a020c61c0f';
    $pane = new stdClass();
    $pane->pid = 'new-29419c9f-9db9-4934-9681-7f6e8310a94b';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'blog_search-panel_pane_1';
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
    $pane->uuid = '29419c9f-9db9-4934-9681-7f6e8310a94b';
    $display->content['new-29419c9f-9db9-4934-9681-7f6e8310a94b'] = $pane;
    $display->panels['center'][3] = 'new-29419c9f-9db9-4934-9681-7f6e8310a94b';
    $pane = new stdClass();
    $pane->pid = 'new-7ed4cb7a-2239-461f-acdc-f335c7b3f0b8';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-16ltO8GhJidECF4OjfUWpcb6zwAjI7En';
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
    $pane->uuid = '7ed4cb7a-2239-461f-acdc-f335c7b3f0b8';
    $display->content['new-7ed4cb7a-2239-461f-acdc-f335c7b3f0b8'] = $pane;
    $display->panels['filters'][0] = 'new-7ed4cb7a-2239-461f-acdc-f335c7b3f0b8';
    $pane = new stdClass();
    $pane->pid = 'new-51865e1a-9aca-400b-b095-05411bd9631b';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-zi4NEWz1qbH4GQWTuw318q1i8o0wQowj';
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
    $pane->uuid = '51865e1a-9aca-400b-b095-05411bd9631b';
    $display->content['new-51865e1a-9aca-400b-b095-05411bd9631b'] = $pane;
    $display->panels['filters'][1] = 'new-51865e1a-9aca-400b-b095-05411bd9631b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['blog'] = $page;

  return $pages;

}
