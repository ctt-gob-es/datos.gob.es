<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_initiative (datos.gob.es)".
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
 * dgef_initiative.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_initiative_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'initiative';
  $page->task = 'page';
  $page->admin_title = 'initiative';
  $page->admin_description = '';
  $page->path = 'iniciativas';
  $page->access = array(
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
  $handler->name = 'page_initiative__panel';
  $handler->task = 'page';
  $handler->subtask = 'initiative';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'View: initiative_search: Contexto',
        'keyword' => 'view',
        'name' => 'view:initiative_search-ctools_context_1',
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
        'width' => '69.99517357879134',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '30.004826421208673',
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
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Mapa de iniciativas';
  $display->uuid = 'aaab1341-a435-482b-9b10-0e49be4c95de';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2844444f-1b21-4daf-9483-a28c77b21eb9';
    $pane->panel = 'center';
    $pane->type = 'views_exposed';
    $pane->subtype = 'views_exposed';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_view:initiative_search-ctools_context_1_1',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2844444f-1b21-4daf-9483-a28c77b21eb9';
    $display->content['new-2844444f-1b21-4daf-9483-a28c77b21eb9'] = $pane;
    $display->panels['center'][0] = 'new-2844444f-1b21-4daf-9483-a28c77b21eb9';
    $pane = new stdClass();
    $pane->pid = 'new-17772ba1-d095-4dfb-a03c-517f6717e405';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'current_search-initiative';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '17772ba1-d095-4dfb-a03c-517f6717e405';
    $display->content['new-17772ba1-d095-4dfb-a03c-517f6717e405'] = $pane;
    $display->panels['center'][1] = 'new-17772ba1-d095-4dfb-a03c-517f6717e405';
    $pane = new stdClass();
    $pane->pid = 'new-58cbf544-0c1c-4130-9b82-c2f833c5e98e';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'initiative_search-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '58cbf544-0c1c-4130-9b82-c2f833c5e98e';
    $display->content['new-58cbf544-0c1c-4130-9b82-c2f833c5e98e'] = $pane;
    $display->panels['center'][2] = 'new-58cbf544-0c1c-4130-9b82-c2f833c5e98e';
    $pane = new stdClass();
    $pane->pid = 'new-8c9e981f-4e5e-4d44-b13b-19168c0c70b3';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'dge_leaflet-dge_leaflet_baselayer_select';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '8c9e981f-4e5e-4d44-b13b-19168c0c70b3';
    $display->content['new-8c9e981f-4e5e-4d44-b13b-19168c0c70b3'] = $pane;
    $display->panels['center'][3] = 'new-8c9e981f-4e5e-4d44-b13b-19168c0c70b3';
    $pane = new stdClass();
    $pane->pid = 'new-f02fc921-d424-4f8f-be2c-9c487829ef98';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-2uUkbuQA8T7mQP1GEvzynlsfHTkC9Iwk';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'f02fc921-d424-4f8f-be2c-9c487829ef98';
    $display->content['new-f02fc921-d424-4f8f-be2c-9c487829ef98'] = $pane;
    $display->panels['center'][4] = 'new-f02fc921-d424-4f8f-be2c-9c487829ef98';
    $pane = new stdClass();
    $pane->pid = 'new-3e9cbd38-3a57-4487-bdba-fa556a1edde6';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-tvr788V4itiPVYls9bNlVjL5WtH56Ben';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '3e9cbd38-3a57-4487-bdba-fa556a1edde6';
    $display->content['new-3e9cbd38-3a57-4487-bdba-fa556a1edde6'] = $pane;
    $display->panels['center'][5] = 'new-3e9cbd38-3a57-4487-bdba-fa556a1edde6';
    $pane = new stdClass();
    $pane->pid = 'new-2299e7ab-5e4d-4a4b-9405-a6fb1c786b1e';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-zrb4D5UUx8mNZ0OM83ChBiW9hkVGl2wd';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '2299e7ab-5e4d-4a4b-9405-a6fb1c786b1e';
    $display->content['new-2299e7ab-5e4d-4a4b-9405-a6fb1c786b1e'] = $pane;
    $display->panels['center'][6] = 'new-2299e7ab-5e4d-4a4b-9405-a6fb1c786b1e';
    $pane = new stdClass();
    $pane->pid = 'new-148a13b5-0899-4ab6-9bb9-b0536324ec3d';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-11fsXKeW7U3DIxAy98Wb3l6NOvof9hkA';
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '148a13b5-0899-4ab6-9bb9-b0536324ec3d';
    $display->content['new-148a13b5-0899-4ab6-9bb9-b0536324ec3d'] = $pane;
    $display->panels['center'][7] = 'new-148a13b5-0899-4ab6-9bb9-b0536324ec3d';
    $pane = new stdClass();
    $pane->pid = 'new-f1b0c958-b1f0-4be4-b510-a7906af72674';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-fdhHU2AaNbuyEsA6cawkDx71vpQ31ZFK';
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
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = 'f1b0c958-b1f0-4be4-b510-a7906af72674';
    $display->content['new-f1b0c958-b1f0-4be4-b510-a7906af72674'] = $pane;
    $display->panels['center'][8] = 'new-f1b0c958-b1f0-4be4-b510-a7906af72674';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['initiative'] = $page;

  return $pages;

}
