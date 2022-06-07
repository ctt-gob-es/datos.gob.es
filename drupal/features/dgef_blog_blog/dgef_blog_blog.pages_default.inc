<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_blog_blog (datos.gob.es)".
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
 * dgef_blog_blog.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgef_blog_blog_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_00b9a14d-0054-47ef-80ed-1263f9af6d90';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 12;
  $handler->conf = array(
    'title' => 'blog_blog_detail',
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
              'blog_blog' => 'blog_blog',
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
  $display->uuid = 'caadb8d8-e4d9-47df-a41c-01c7eae5423d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_00b9a14d-0054-47ef-80ed-1263f9af6d90';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-aad55676-107a-4fd2-9be0-297d77d6d50d';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'blog_blog_detail-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '0',
          'paths' => 'node/*/revisions/*/view',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
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
  $pane->uuid = 'aad55676-107a-4fd2-9be0-297d77d6d50d';
  $display->content['new-aad55676-107a-4fd2-9be0-297d77d6d50d'] = $pane;
  $display->panels['center'][0] = 'new-aad55676-107a-4fd2-9be0-297d77d6d50d';
  $pane = new stdClass();
  $pane->pid = 'new-150fc790-e357-4677-a27b-7861930f9462';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'blog_detail_draft-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'node/*/revisions/*/view',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'arguments' => array(
      'vid' => '%node:vid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '150fc790-e357-4677-a27b-7861930f9462';
  $display->content['new-150fc790-e357-4677-a27b-7861930f9462'] = $pane;
  $display->panels['center'][1] = 'new-150fc790-e357-4677-a27b-7861930f9462';
  $pane = new stdClass();
  $pane->pid = 'new-5c520b96-3efb-4350-a784-3852d7a1ec65';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'dge_comment-dge_comment_block';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5c520b96-3efb-4350-a784-3852d7a1ec65';
  $display->content['new-5c520b96-3efb-4350-a784-3852d7a1ec65'] = $pane;
  $display->panels['center'][2] = 'new-5c520b96-3efb-4350-a784-3852d7a1ec65';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-aad55676-107a-4fd2-9be0-297d77d6d50d';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_00b9a14d-0054-47ef-80ed-1263f9af6d90'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_blog_blog_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'blog_blog';
  $page->task = 'page';
  $page->admin_title = 'New Blog';
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
  $handler->name = 'page_blog_blog__panel_context_c16b2a61-1ef1-45bb-be89-4d4d2518cff4';
  $handler->task = 'page';
  $handler->subtask = 'blog_blog';
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
        'identifier' => 'View: Blog search',
        'keyword' => 'view',
        'name' => 'view:blog_blog_search-ctools_context_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Contenido',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '17705',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'flexible:dge_lists_2cols_1row';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'filters' => NULL,
      'texto' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Blog';
  $display->uuid = '554f2315-e4c3-49bb-a0f7-b52f07f56009';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_blog_blog__panel_context_c16b2a61-1ef1-45bb-be89-4d4d2518cff4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cd215f7d-95d5-4c5e-a80d-a4826adf43a3';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'views-706b3a2f45104a5dad8dd9636bd39919';
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
  $pane->uuid = 'cd215f7d-95d5-4c5e-a80d-a4826adf43a3';
  $display->content['new-cd215f7d-95d5-4c5e-a80d-a4826adf43a3'] = $pane;
  $display->panels['center'][0] = 'new-cd215f7d-95d5-4c5e-a80d-a4826adf43a3';
  $pane = new stdClass();
  $pane->pid = 'new-2d800c22-4aaf-4423-be05-fa8debf3fd25';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'search_api_sorts-search-sorts';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Ordenar por:',
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
  $pane->uuid = '2d800c22-4aaf-4423-be05-fa8debf3fd25';
  $display->content['new-2d800c22-4aaf-4423-be05-fa8debf3fd25'] = $pane;
  $display->panels['center'][1] = 'new-2d800c22-4aaf-4423-be05-fa8debf3fd25';
  $pane = new stdClass();
  $pane->pid = 'new-22bf0bb4-9132-49d1-8cde-0c0dd156ebdb';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'current_search-blog_blog';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '22bf0bb4-9132-49d1-8cde-0c0dd156ebdb';
  $display->content['new-22bf0bb4-9132-49d1-8cde-0c0dd156ebdb'] = $pane;
  $display->panels['center'][2] = 'new-22bf0bb4-9132-49d1-8cde-0c0dd156ebdb';
  $pane = new stdClass();
  $pane->pid = 'new-3b865979-e063-4430-abb3-701d4ff4caab';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'blog_blog_search-panel_pane_1';
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
  $pane->uuid = '3b865979-e063-4430-abb3-701d4ff4caab';
  $display->content['new-3b865979-e063-4430-abb3-701d4ff4caab'] = $pane;
  $display->panels['center'][3] = 'new-3b865979-e063-4430-abb3-701d4ff4caab';
  $pane = new stdClass();
  $pane->pid = 'new-4a9095d9-f6e0-4f85-9fd1-14ac6fa2d41e';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-GFcMYR0Jh5HQrN0zVOkioAXisquUmJFp';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Etiqueta',
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
  $pane->uuid = '4a9095d9-f6e0-4f85-9fd1-14ac6fa2d41e';
  $display->content['new-4a9095d9-f6e0-4f85-9fd1-14ac6fa2d41e'] = $pane;
  $display->panels['filters'][0] = 'new-4a9095d9-f6e0-4f85-9fd1-14ac6fa2d41e';
  $pane = new stdClass();
  $pane->pid = 'new-6c9dfabd-c357-47ea-9b2d-065c1c0f07d6';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-FBGqm6qmwkDP39XH73676k0bJwUfKqCL';
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
  $pane->uuid = '6c9dfabd-c357-47ea-9b2d-065c1c0f07d6';
  $display->content['new-6c9dfabd-c357-47ea-9b2d-065c1c0f07d6'] = $pane;
  $display->panels['filters'][1] = 'new-6c9dfabd-c357-47ea-9b2d-065c1c0f07d6';
  $pane = new stdClass();
  $pane->pid = 'new-7119eec3-0ff4-4e78-9dbe-3435f2bdb277';
  $pane->panel = 'texto';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '17705',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'teaser',
    'link_node_title' => 0,
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
  $pane->uuid = '7119eec3-0ff4-4e78-9dbe-3435f2bdb277';
  $display->content['new-7119eec3-0ff4-4e78-9dbe-3435f2bdb277'] = $pane;
  $display->panels['texto'][0] = 'new-7119eec3-0ff4-4e78-9dbe-3435f2bdb277';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['blog_blog'] = $page;

  return $pages;

}
