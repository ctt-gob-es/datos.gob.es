<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_success (datos.gob.es)".
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
 * dgef_success.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgef_success_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_cc945dc5-ef7b-4bcd-885d-52334a4aafe9';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 7;
  $handler->conf = array(
    'title' => 'success_detail',
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
              'success' => 'success',
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
  $display->uuid = '821e4092-d90d-4f05-82e4-d624643901da';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_cc945dc5-ef7b-4bcd-885d-52334a4aafe9';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ca6afdfd-4344-4e09-b0f3-82a6000a3d86';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'success_detail-panel_pane_1';
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
  $pane->uuid = 'ca6afdfd-4344-4e09-b0f3-82a6000a3d86';
  $display->content['new-ca6afdfd-4344-4e09-b0f3-82a6000a3d86'] = $pane;
  $display->panels['center'][0] = 'new-ca6afdfd-4344-4e09-b0f3-82a6000a3d86';
  $pane = new stdClass();
  $pane->pid = 'new-91b897b6-2f5e-46d2-b7fb-9694978a9c13';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'success_detail_draft-panel_pane_2';
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
  $pane->uuid = '91b897b6-2f5e-46d2-b7fb-9694978a9c13';
  $display->content['new-91b897b6-2f5e-46d2-b7fb-9694978a9c13'] = $pane;
  $display->panels['center'][1] = 'new-91b897b6-2f5e-46d2-b7fb-9694978a9c13';
  $pane = new stdClass();
  $pane->pid = 'new-9e2b633f-a921-4c10-bee2-4ad782a83a5b';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'boxes-success_detail_disclaimer';
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
  $pane->uuid = '9e2b633f-a921-4c10-bee2-4ad782a83a5b';
  $display->content['new-9e2b633f-a921-4c10-bee2-4ad782a83a5b'] = $pane;
  $display->panels['center'][2] = 'new-9e2b633f-a921-4c10-bee2-4ad782a83a5b';
  $pane = new stdClass();
  $pane->pid = 'new-5fd10f54-1e62-495f-8516-302d19f4a89d';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'dge_comment-dge_comment_block';
  $pane->shown = FALSE;
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '5fd10f54-1e62-495f-8516-302d19f4a89d';
  $display->content['new-5fd10f54-1e62-495f-8516-302d19f4a89d'] = $pane;
  $display->panels['center'][3] = 'new-5fd10f54-1e62-495f-8516-302d19f4a89d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_cc945dc5-ef7b-4bcd-885d-52334a4aafe9'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_success_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'success';
  $page->task = 'page';
  $page->admin_title = 'success';
  $page->admin_description = '';
  $page->path = 'casos-exito';
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
  $handler->name = 'page_success__panel';
  $handler->task = 'page';
  $handler->subtask = 'success';
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
        'identifier' => 'Contenido',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '8292',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible:dge_lists_2cols_1row';
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
      'texto' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Empresas reutilizadoras';
  $display->uuid = 'd1236933-100b-46bd-8a9a-3d385b2b462f';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_success__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-bc7850cb-b572-431f-840a-ae5dd6dfc91e';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-success_view-panel_pane_1';
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
  $pane->uuid = 'bc7850cb-b572-431f-840a-ae5dd6dfc91e';
  $display->content['new-bc7850cb-b572-431f-840a-ae5dd6dfc91e'] = $pane;
  $display->panels['center'][0] = 'new-bc7850cb-b572-431f-840a-ae5dd6dfc91e';
  $pane = new stdClass();
  $pane->pid = 'new-7515d822-cd52-437c-b58b-06d0935c5236';
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
  $pane->uuid = '7515d822-cd52-437c-b58b-06d0935c5236';
  $display->content['new-7515d822-cd52-437c-b58b-06d0935c5236'] = $pane;
  $display->panels['center'][1] = 'new-7515d822-cd52-437c-b58b-06d0935c5236';
  $pane = new stdClass();
  $pane->pid = 'new-98e4dc3f-22ed-4847-b71d-9d343ab93534';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'current_search-success';
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
  $pane->uuid = '98e4dc3f-22ed-4847-b71d-9d343ab93534';
  $display->content['new-98e4dc3f-22ed-4847-b71d-9d343ab93534'] = $pane;
  $display->panels['center'][2] = 'new-98e4dc3f-22ed-4847-b71d-9d343ab93534';
  $pane = new stdClass();
  $pane->pid = 'new-e2490618-0a85-404a-a804-1f2a2b00dfd0';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'success_view-panel_pane_1';
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
  $pane->uuid = 'e2490618-0a85-404a-a804-1f2a2b00dfd0';
  $display->content['new-e2490618-0a85-404a-a804-1f2a2b00dfd0'] = $pane;
  $display->panels['center'][3] = 'new-e2490618-0a85-404a-a804-1f2a2b00dfd0';
  $pane = new stdClass();
  $pane->pid = 'new-7aa19155-83cc-454b-93bc-23b32d3b567d';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'dge_form_upgrades-dge_form_upd_link_success';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '7aa19155-83cc-454b-93bc-23b32d3b567d';
  $display->content['new-7aa19155-83cc-454b-93bc-23b32d3b567d'] = $pane;
  $display->panels['center'][4] = 'new-7aa19155-83cc-454b-93bc-23b32d3b567d';
  $pane = new stdClass();
  $pane->pid = 'new-e25c4ce5-67f2-4e2e-8de2-82d8a723b810';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-c1VqMrLHD235jeed0dcpFa0f77Vbba7f';
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
  $pane->uuid = 'e25c4ce5-67f2-4e2e-8de2-82d8a723b810';
  $display->content['new-e25c4ce5-67f2-4e2e-8de2-82d8a723b810'] = $pane;
  $display->panels['filters'][0] = 'new-e25c4ce5-67f2-4e2e-8de2-82d8a723b810';
  $pane = new stdClass();
  $pane->pid = 'new-e871f102-01a2-4f74-8e94-fb1c132a2f0d';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-UAwKWnG01BXOiGNEljTLBS1o3EbpO6Zv';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e871f102-01a2-4f74-8e94-fb1c132a2f0d';
  $display->content['new-e871f102-01a2-4f74-8e94-fb1c132a2f0d'] = $pane;
  $display->panels['filters'][1] = 'new-e871f102-01a2-4f74-8e94-fb1c132a2f0d';
  $pane = new stdClass();
  $pane->pid = 'new-0f2ae1b1-878e-4dd7-84e3-4aede53907e5';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-tzfDAJOMuwgPYAmLVQ04hk7mv9uI2Bjr';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Año creación de empresa',
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
  $pane->uuid = '0f2ae1b1-878e-4dd7-84e3-4aede53907e5';
  $display->content['new-0f2ae1b1-878e-4dd7-84e3-4aede53907e5'] = $pane;
  $display->panels['filters'][2] = 'new-0f2ae1b1-878e-4dd7-84e3-4aede53907e5';
  $pane = new stdClass();
  $pane->pid = 'new-1bed4217-ae90-4496-a258-6c1b0fa644f8';
  $pane->panel = 'texto';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_status',
        'settings' => NULL,
        'context' => 'context_entity:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'nid' => '8292',
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
  $pane->uuid = '1bed4217-ae90-4496-a258-6c1b0fa644f8';
  $display->content['new-1bed4217-ae90-4496-a258-6c1b0fa644f8'] = $pane;
  $display->panels['texto'][0] = 'new-1bed4217-ae90-4496-a258-6c1b0fa644f8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e25c4ce5-67f2-4e2e-8de2-82d8a723b810';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['success'] = $page;

  return $pages;

}
