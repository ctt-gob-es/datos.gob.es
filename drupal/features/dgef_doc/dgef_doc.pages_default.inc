<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_doc (datos.gob.es)".
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
 * dgef_doc.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgef_doc_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_d393dfd3-a4e9-4475-8f49-108632e791ba';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'doc_detail',
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
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'doc' => 'doc',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
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
  $display->uuid = '3a37f8ae-bba0-4e6a-8237-f11c55d7013e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0999ac61-1572-4447-a17d-287312bc8323';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'doc_detail-panel_pane_1';
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
    $pane->uuid = '0999ac61-1572-4447-a17d-287312bc8323';
    $display->content['new-0999ac61-1572-4447-a17d-287312bc8323'] = $pane;
    $display->panels['center'][0] = 'new-0999ac61-1572-4447-a17d-287312bc8323';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_d393dfd3-a4e9-4475-8f49-108632e791ba'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_doc_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'docs';
  $page->task = 'page';
  $page->admin_title = 'docs';
  $page->admin_description = '';
  $page->path = 'documentacion';
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
  $handler->name = 'page_docs__panel';
  $handler->task = 'page';
  $handler->subtask = 'docs';
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
        'identifier' => 'View: doc_search',
        'keyword' => 'view',
        'name' => 'view:doc_search-ctools_context_1',
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
  $display->title = 'Documentación';
  $display->uuid = 'f729cd1d-b2ff-437b-a0eb-2c26c41b2086';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f080455a-5ba2-4950-9568-5db7a1218de0';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-doc_search-panel_pane_1';
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
    $pane->uuid = 'f080455a-5ba2-4950-9568-5db7a1218de0';
    $display->content['new-f080455a-5ba2-4950-9568-5db7a1218de0'] = $pane;
    $display->panels['center'][0] = 'new-f080455a-5ba2-4950-9568-5db7a1218de0';
    $pane = new stdClass();
    $pane->pid = 'new-7a9c024d-feea-4ba1-b97c-a68eb526f503';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'current_search-doc';
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
    $pane->uuid = '7a9c024d-feea-4ba1-b97c-a68eb526f503';
    $display->content['new-7a9c024d-feea-4ba1-b97c-a68eb526f503'] = $pane;
    $display->panels['center'][1] = 'new-7a9c024d-feea-4ba1-b97c-a68eb526f503';
    $pane = new stdClass();
    $pane->pid = 'new-573748f1-a4a5-44b4-9ba4-d488d43666f7';
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
    $pane->uuid = '573748f1-a4a5-44b4-9ba4-d488d43666f7';
    $display->content['new-573748f1-a4a5-44b4-9ba4-d488d43666f7'] = $pane;
    $display->panels['center'][2] = 'new-573748f1-a4a5-44b4-9ba4-d488d43666f7';
    $pane = new stdClass();
    $pane->pid = 'new-f962ca67-cc22-448d-b07f-179cff765ed4';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'doc_search-panel_pane_1';
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
    $pane->uuid = 'f962ca67-cc22-448d-b07f-179cff765ed4';
    $display->content['new-f962ca67-cc22-448d-b07f-179cff765ed4'] = $pane;
    $display->panels['center'][3] = 'new-f962ca67-cc22-448d-b07f-179cff765ed4';
    $pane = new stdClass();
    $pane->pid = 'new-0572354d-853d-43a8-b7ce-fdffde324273';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-tGuhIKoTW5vlSowpbtEhFAK1vesDwR0J';
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
    $pane->uuid = '0572354d-853d-43a8-b7ce-fdffde324273';
    $display->content['new-0572354d-853d-43a8-b7ce-fdffde324273'] = $pane;
    $display->panels['filters'][0] = 'new-0572354d-853d-43a8-b7ce-fdffde324273';
    $pane = new stdClass();
    $pane->pid = 'new-679106fc-1d42-447b-8c80-b49210ca841c';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-FqEqX8keRmZg18xL56ugt5ieZxVVcfaz';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Fecha del documento',
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
    $pane->uuid = '679106fc-1d42-447b-8c80-b49210ca841c';
    $display->content['new-679106fc-1d42-447b-8c80-b49210ca841c'] = $pane;
    $display->panels['filters'][1] = 'new-679106fc-1d42-447b-8c80-b49210ca841c';
    $pane = new stdClass();
    $pane->pid = 'new-6ef20a4e-75cc-44ea-bee6-d656594bc097';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-LgQDHBhyLlxC0A62rl376B4PpVNRqKKU';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Tipo',
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
    $pane->uuid = '6ef20a4e-75cc-44ea-bee6-d656594bc097';
    $display->content['new-6ef20a4e-75cc-44ea-bee6-d656594bc097'] = $pane;
    $display->panels['filters'][2] = 'new-6ef20a4e-75cc-44ea-bee6-d656594bc097';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['docs'] = $page;

  return $pages;

}
