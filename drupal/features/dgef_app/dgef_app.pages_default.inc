<?php
/**	 
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	* 
 	* This file is part of "dgef_app (datos.gob.es)".
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
 * dgef_app.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgef_app_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_33fd6415-e268-4f35-9147-9be69dc8847d';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 10;
  $handler->conf = array(
    'title' => 'app_detail',
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
              'app' => 'app',
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
  $display->uuid = 'ad27555f-c358-4901-9742-001b86a6114f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-66d44d34-62a6-4ced-be03-9e4ff8be7332';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'app_detail-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '66d44d34-62a6-4ced-be03-9e4ff8be7332';
    $display->content['new-66d44d34-62a6-4ced-be03-9e4ff8be7332'] = $pane;
    $display->panels['center'][0] = 'new-66d44d34-62a6-4ced-be03-9e4ff8be7332';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-66d44d34-62a6-4ced-be03-9e4ff8be7332';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_33fd6415-e268-4f35-9147-9be69dc8847d'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_app_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'apps';
  $page->task = 'page';
  $page->admin_title = 'apps';
  $page->admin_description = '';
  $page->path = 'aplicaciones';
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
  $handler->name = 'page_apps__panel';
  $handler->task = 'page';
  $handler->subtask = 'apps';
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
      1 => array(
        'identifier' => 'View: apps_search',
        'keyword' => 'view',
        'name' => 'view:apps_search-ctools_context_1',
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
          0 => 'left',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Centrado',
        'width' => '69.9758781848334',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '30.024121815166588',
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
      'left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Aplicaciones';
  $display->uuid = '61669234-735e-4534-ab6f-45dcc4294ea0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d461ff81-2972-493c-8f12-4de1d55d1cc2';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-apps_search-panel_pane_1';
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
    $pane->uuid = 'd461ff81-2972-493c-8f12-4de1d55d1cc2';
    $display->content['new-d461ff81-2972-493c-8f12-4de1d55d1cc2'] = $pane;
    $display->panels['center'][0] = 'new-d461ff81-2972-493c-8f12-4de1d55d1cc2';
    $pane = new stdClass();
    $pane->pid = 'new-e38aa569-66ad-4e25-b05e-b8e96f8b6016';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'current_search-apps';
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
    $pane->uuid = 'e38aa569-66ad-4e25-b05e-b8e96f8b6016';
    $display->content['new-e38aa569-66ad-4e25-b05e-b8e96f8b6016'] = $pane;
    $display->panels['center'][1] = 'new-e38aa569-66ad-4e25-b05e-b8e96f8b6016';
    $pane = new stdClass();
    $pane->pid = 'new-d6c3bf6b-d868-4f95-b8a0-912a586125b8';
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
    $pane->uuid = 'd6c3bf6b-d868-4f95-b8a0-912a586125b8';
    $display->content['new-d6c3bf6b-d868-4f95-b8a0-912a586125b8'] = $pane;
    $display->panels['center'][2] = 'new-d6c3bf6b-d868-4f95-b8a0-912a586125b8';
    $pane = new stdClass();
    $pane->pid = 'new-ed09eb15-af2f-4660-a488-a9bd90a536f5';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'apps_search-panel_pane_1';
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
    $pane->uuid = 'ed09eb15-af2f-4660-a488-a9bd90a536f5';
    $display->content['new-ed09eb15-af2f-4660-a488-a9bd90a536f5'] = $pane;
    $display->panels['center'][3] = 'new-ed09eb15-af2f-4660-a488-a9bd90a536f5';
    $pane = new stdClass();
    $pane->pid = 'new-fd6922d9-c522-4e98-8b8f-a71bc5857af2';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-fpgwIysLzHUY1TjiUHQANafz3P41u6Z9';
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
    $pane->uuid = 'fd6922d9-c522-4e98-8b8f-a71bc5857af2';
    $display->content['new-fd6922d9-c522-4e98-8b8f-a71bc5857af2'] = $pane;
    $display->panels['filters'][0] = 'new-fd6922d9-c522-4e98-8b8f-a71bc5857af2';
    $pane = new stdClass();
    $pane->pid = 'new-e7f46dd3-544f-4dd3-a0ed-55696cb60ad1';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-wQDfWBV5nnQKpVhtQ40hnYG9nkDTGikU';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Plataforma',
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
    $pane->uuid = 'e7f46dd3-544f-4dd3-a0ed-55696cb60ad1';
    $display->content['new-e7f46dd3-544f-4dd3-a0ed-55696cb60ad1'] = $pane;
    $display->panels['filters'][1] = 'new-e7f46dd3-544f-4dd3-a0ed-55696cb60ad1';
    $pane = new stdClass();
    $pane->pid = 'new-9d38c011-c83c-441e-874e-5fc5b002cdcc';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-xWFtO68KSTYpThpQy3OtGA9egrXZIWZv';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '9d38c011-c83c-441e-874e-5fc5b002cdcc';
    $display->content['new-9d38c011-c83c-441e-874e-5fc5b002cdcc'] = $pane;
    $display->panels['filters'][2] = 'new-9d38c011-c83c-441e-874e-5fc5b002cdcc';
    $pane = new stdClass();
    $pane->pid = 'new-2a3a53eb-a060-4970-b64a-5287db2b085b';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-37VszB8QP3TfI1R0UlclBqGIpChX92Jn';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Fecha de publicación',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '2a3a53eb-a060-4970-b64a-5287db2b085b';
    $display->content['new-2a3a53eb-a060-4970-b64a-5287db2b085b'] = $pane;
    $display->panels['filters'][3] = 'new-2a3a53eb-a060-4970-b64a-5287db2b085b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fd6922d9-c522-4e98-8b8f-a71bc5857af2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['apps'] = $page;

  return $pages;

}
