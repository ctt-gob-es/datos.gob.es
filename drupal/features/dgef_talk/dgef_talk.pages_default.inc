<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_talk (datos.gob.es)".
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
 * dgef_talk.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgef_talk_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_1e59aa40-90f9-4d79-b1c1-1970da9bfd8f';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 8;
  $handler->conf = array(
    'title' => 'talk_detail',
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
              'talk' => 'talk',
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
  $display->uuid = '4decb2ff-93f3-4162-ab30-775c52bec9f0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-595b601a-b7c3-4bba-ae3e-8e56490c8a1b';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'talk_detail-panel_pane_1';
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
    $pane->uuid = '595b601a-b7c3-4bba-ae3e-8e56490c8a1b';
    $display->content['new-595b601a-b7c3-4bba-ae3e-8e56490c8a1b'] = $pane;
    $display->panels['center'][0] = 'new-595b601a-b7c3-4bba-ae3e-8e56490c8a1b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_1e59aa40-90f9-4d79-b1c1-1970da9bfd8f'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_talk_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'talk';
  $page->task = 'page';
  $page->admin_title = 'talk';
  $page->admin_description = '';
  $page->path = 'comunidad-risp';
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
  $handler->name = 'page_talk__panel';
  $handler->task = 'page';
  $handler->subtask = 'talk';
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
        'identifier' => 'View: talk_search',
        'keyword' => 'view',
        'name' => 'view:talk_search-ctools_context_1',
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
  $display->title = 'Comunidad RISP';
  $display->uuid = '35c0ac3b-91bd-4567-9fe4-bc38c7883c4b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-014e07f4-10c2-44a4-9702-6409856ee376';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-talk_search-panel_pane_1';
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
    $pane->uuid = '014e07f4-10c2-44a4-9702-6409856ee376';
    $display->content['new-014e07f4-10c2-44a4-9702-6409856ee376'] = $pane;
    $display->panels['center'][0] = 'new-014e07f4-10c2-44a4-9702-6409856ee376';
    $pane = new stdClass();
    $pane->pid = 'new-1f9644e5-9bcd-4850-9a4d-e1b628505b9c';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'current_search-talk';
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
    $pane->uuid = '1f9644e5-9bcd-4850-9a4d-e1b628505b9c';
    $display->content['new-1f9644e5-9bcd-4850-9a4d-e1b628505b9c'] = $pane;
    $display->panels['center'][1] = 'new-1f9644e5-9bcd-4850-9a4d-e1b628505b9c';
    $pane = new stdClass();
    $pane->pid = 'new-74961d93-606f-4c24-b340-2bb628d5616f';
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
    $pane->uuid = '74961d93-606f-4c24-b340-2bb628d5616f';
    $display->content['new-74961d93-606f-4c24-b340-2bb628d5616f'] = $pane;
    $display->panels['center'][2] = 'new-74961d93-606f-4c24-b340-2bb628d5616f';
    $pane = new stdClass();
    $pane->pid = 'new-929bc80a-d9ec-423d-884e-595ded3bf5c8';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'talk_search-panel_pane_1';
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
    $pane->uuid = '929bc80a-d9ec-423d-884e-595ded3bf5c8';
    $display->content['new-929bc80a-d9ec-423d-884e-595ded3bf5c8'] = $pane;
    $display->panels['center'][3] = 'new-929bc80a-d9ec-423d-884e-595ded3bf5c8';
    $pane = new stdClass();
    $pane->pid = 'new-8267dbe7-cc35-4dd4-805a-8aa7c99fe388';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-iS7UvO1f00MICvP8AZ5IWStT1y6hXFZG';
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
    $pane->uuid = '8267dbe7-cc35-4dd4-805a-8aa7c99fe388';
    $display->content['new-8267dbe7-cc35-4dd4-805a-8aa7c99fe388'] = $pane;
    $display->panels['filters'][0] = 'new-8267dbe7-cc35-4dd4-805a-8aa7c99fe388';
    $pane = new stdClass();
    $pane->pid = 'new-84251ee7-b8cd-44f7-9095-5dad454d369e';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-78iEdGrc9p9Sy4aHR4YONahtQvO1ZZ8D';
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
    $pane->uuid = '84251ee7-b8cd-44f7-9095-5dad454d369e';
    $display->content['new-84251ee7-b8cd-44f7-9095-5dad454d369e'] = $pane;
    $display->panels['filters'][1] = 'new-84251ee7-b8cd-44f7-9095-5dad454d369e';
    $pane = new stdClass();
    $pane->pid = 'new-e7be9905-6b8a-4970-9619-088837016957';
    $pane->panel = 'filters';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-DDI6WY4jRI4kKMeO1kAPElC1Dbyc71Jw';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Sector',
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
    $pane->uuid = 'e7be9905-6b8a-4970-9619-088837016957';
    $display->content['new-e7be9905-6b8a-4970-9619-088837016957'] = $pane;
    $display->panels['filters'][2] = 'new-e7be9905-6b8a-4970-9619-088837016957';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['talk'] = $page;

  return $pages;

}
