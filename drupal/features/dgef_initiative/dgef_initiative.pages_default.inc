<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
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
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
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
      'filters' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Mapa de iniciativas';
  $display->uuid = 'aaab1341-a435-482b-9b10-0e49be4c95de';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_initiative__panel';
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
  $pane->pid = 'new-6f7adeb4-a2a9-4059-abb8-3ae020285485';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'accessible link',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p class="accessible-link-p"><a href="/es/accessible-initiatives" title="Versión accesible">Versión accesible</a></p>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-search-api-sorts',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6f7adeb4-a2a9-4059-abb8-3ae020285485';
  $display->content['new-6f7adeb4-a2a9-4059-abb8-3ae020285485'] = $pane;
  $display->panels['center'][1] = 'new-6f7adeb4-a2a9-4059-abb8-3ae020285485';
  $pane = new stdClass();
  $pane->pid = 'new-17772ba1-d095-4dfb-a03c-517f6717e405';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'current_search-initiative';
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
  $pane->uuid = '17772ba1-d095-4dfb-a03c-517f6717e405';
  $display->content['new-17772ba1-d095-4dfb-a03c-517f6717e405'] = $pane;
  $display->panels['center'][2] = 'new-17772ba1-d095-4dfb-a03c-517f6717e405';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '58cbf544-0c1c-4130-9b82-c2f833c5e98e';
  $display->content['new-58cbf544-0c1c-4130-9b82-c2f833c5e98e'] = $pane;
  $display->panels['center'][3] = 'new-58cbf544-0c1c-4130-9b82-c2f833c5e98e';
  $pane = new stdClass();
  $pane->pid = 'new-8b7f76b2-ffd4-4f98-a5de-eeea527050cc';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'boxes-iniciativas_contactar';
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
  $pane->uuid = '8b7f76b2-ffd4-4f98-a5de-eeea527050cc';
  $display->content['new-8b7f76b2-ffd4-4f98-a5de-eeea527050cc'] = $pane;
  $display->panels['center'][4] = 'new-8b7f76b2-ffd4-4f98-a5de-eeea527050cc';
  $pane = new stdClass();
  $pane->pid = 'new-22d6d20b-b655-4ce5-8e12-7188de52d78c';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'dge_form_upgrades-dge_form_upd_link_initiative';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '22d6d20b-b655-4ce5-8e12-7188de52d78c';
  $display->content['new-22d6d20b-b655-4ce5-8e12-7188de52d78c'] = $pane;
  $display->panels['center'][5] = 'new-22d6d20b-b655-4ce5-8e12-7188de52d78c';
  $pane = new stdClass();
  $pane->pid = 'new-7981e837-ec89-4a30-82cf-eb91737b0aa1';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'dge_initiatives-dge_initiative_csv_button';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '7981e837-ec89-4a30-82cf-eb91737b0aa1';
  $display->content['new-7981e837-ec89-4a30-82cf-eb91737b0aa1'] = $pane;
  $display->panels['center'][6] = 'new-7981e837-ec89-4a30-82cf-eb91737b0aa1';
  $pane = new stdClass();
  $pane->pid = 'new-8c9e981f-4e5e-4d44-b13b-19168c0c70b3';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'dge_leaflet-dge_leaflet_baselayer_select';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Capa Base',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-facetapi',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8c9e981f-4e5e-4d44-b13b-19168c0c70b3';
  $display->content['new-8c9e981f-4e5e-4d44-b13b-19168c0c70b3'] = $pane;
  $display->panels['filters'][0] = 'new-8c9e981f-4e5e-4d44-b13b-19168c0c70b3';
  $pane = new stdClass();
  $pane->pid = 'new-f02fc921-d424-4f8f-be2c-9c487829ef98';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-2uUkbuQA8T7mQP1GEvzynlsfHTkC9Iwk';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Nivel de Administración',
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
  $pane->uuid = 'f02fc921-d424-4f8f-be2c-9c487829ef98';
  $display->content['new-f02fc921-d424-4f8f-be2c-9c487829ef98'] = $pane;
  $display->panels['filters'][1] = 'new-f02fc921-d424-4f8f-be2c-9c487829ef98';
  $pane = new stdClass();
  $pane->pid = 'new-3e9cbd38-3a57-4487-bdba-fa556a1edde6';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-tvr788V4itiPVYls9bNlVjL5WtH56Ben';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Temática',
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
  $pane->uuid = '3e9cbd38-3a57-4487-bdba-fa556a1edde6';
  $display->content['new-3e9cbd38-3a57-4487-bdba-fa556a1edde6'] = $pane;
  $display->panels['filters'][2] = 'new-3e9cbd38-3a57-4487-bdba-fa556a1edde6';
  $pane = new stdClass();
  $pane->pid = 'new-2299e7ab-5e4d-4a4b-9405-a6fb1c786b1e';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-zrb4D5UUx8mNZ0OM83ChBiW9hkVGl2wd';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Grado de reutilización',
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
  $pane->uuid = '2299e7ab-5e4d-4a4b-9405-a6fb1c786b1e';
  $display->content['new-2299e7ab-5e4d-4a4b-9405-a6fb1c786b1e'] = $pane;
  $display->panels['filters'][3] = 'new-2299e7ab-5e4d-4a4b-9405-a6fb1c786b1e';
  $pane = new stdClass();
  $pane->pid = 'new-148a13b5-0899-4ab6-9bb9-b0536324ec3d';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-11fsXKeW7U3DIxAy98Wb3l6NOvof9hkA';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Punto de consulta',
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
  $pane->uuid = '148a13b5-0899-4ab6-9bb9-b0536324ec3d';
  $display->content['new-148a13b5-0899-4ab6-9bb9-b0536324ec3d'] = $pane;
  $display->panels['filters'][4] = 'new-148a13b5-0899-4ab6-9bb9-b0536324ec3d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['initiative'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'initiative_accessible';
  $page->task = 'page';
  $page->admin_title = 'initiative_accessible';
  $page->admin_description = '';
  $page->path = 'accessible-initiatives';
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
  $handler->name = 'page_initiative_accessible__panel';
  $handler->task = 'page';
  $handler->subtask = 'initiative_accessible';
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
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible:dge_lists_2cols';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'filters' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Iniciativas';
  $display->uuid = 'e026402d-99ea-40af-9cc5-09429d5fbf4b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_initiative_accessible__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4840b7dc-42f4-4e21-bdaf-20d0cc311887';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'views-ad504505988640dee9726f436b4c119a';
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
  $pane->uuid = '4840b7dc-42f4-4e21-bdaf-20d0cc311887';
  $display->content['new-4840b7dc-42f4-4e21-bdaf-20d0cc311887'] = $pane;
  $display->panels['center'][0] = 'new-4840b7dc-42f4-4e21-bdaf-20d0cc311887';
  $pane = new stdClass();
  $pane->pid = 'new-4b99a04e-894a-47c1-b3e3-54fa4735b1fb';
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
  $pane->uuid = '4b99a04e-894a-47c1-b3e3-54fa4735b1fb';
  $display->content['new-4b99a04e-894a-47c1-b3e3-54fa4735b1fb'] = $pane;
  $display->panels['center'][1] = 'new-4b99a04e-894a-47c1-b3e3-54fa4735b1fb';
  $pane = new stdClass();
  $pane->pid = 'new-232e9514-eb3f-433c-925e-8678d005ef98';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'current_search-initiative';
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
  $pane->uuid = '232e9514-eb3f-433c-925e-8678d005ef98';
  $display->content['new-232e9514-eb3f-433c-925e-8678d005ef98'] = $pane;
  $display->panels['center'][2] = 'new-232e9514-eb3f-433c-925e-8678d005ef98';
  $pane = new stdClass();
  $pane->pid = 'new-966faed5-4ee0-4470-9912-f40a8235f6a3';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'initiative_search-panel_pane_2';
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
  $pane->uuid = '966faed5-4ee0-4470-9912-f40a8235f6a3';
  $display->content['new-966faed5-4ee0-4470-9912-f40a8235f6a3'] = $pane;
  $display->panels['center'][3] = 'new-966faed5-4ee0-4470-9912-f40a8235f6a3';
  $pane = new stdClass();
  $pane->pid = 'new-9cff3e54-092b-4852-a56c-6dcb422a7e3d';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'boxes-iniciativas_contactar';
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
  $pane->uuid = '9cff3e54-092b-4852-a56c-6dcb422a7e3d';
  $display->content['new-9cff3e54-092b-4852-a56c-6dcb422a7e3d'] = $pane;
  $display->panels['center'][4] = 'new-9cff3e54-092b-4852-a56c-6dcb422a7e3d';
  $pane = new stdClass();
  $pane->pid = 'new-1a086c87-84df-4b62-bf44-67e8e900de39';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'dge_form_upgrades-dge_form_upd_link_initiative';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '1a086c87-84df-4b62-bf44-67e8e900de39';
  $display->content['new-1a086c87-84df-4b62-bf44-67e8e900de39'] = $pane;
  $display->panels['center'][5] = 'new-1a086c87-84df-4b62-bf44-67e8e900de39';
  $pane = new stdClass();
  $pane->pid = 'new-ea5c56ee-04bc-4c79-aba0-30e879bbdbb2';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'dge_initiatives-dge_initiative_csv_button';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'ea5c56ee-04bc-4c79-aba0-30e879bbdbb2';
  $display->content['new-ea5c56ee-04bc-4c79-aba0-30e879bbdbb2'] = $pane;
  $display->panels['center'][6] = 'new-ea5c56ee-04bc-4c79-aba0-30e879bbdbb2';
  $pane = new stdClass();
  $pane->pid = 'new-bbfb13a5-e07c-439e-b719-ac4baa72d8a3';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-2uUkbuQA8T7mQP1GEvzynlsfHTkC9Iwk';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Nivel de administración',
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
  $pane->uuid = 'bbfb13a5-e07c-439e-b719-ac4baa72d8a3';
  $display->content['new-bbfb13a5-e07c-439e-b719-ac4baa72d8a3'] = $pane;
  $display->panels['filters'][0] = 'new-bbfb13a5-e07c-439e-b719-ac4baa72d8a3';
  $pane = new stdClass();
  $pane->pid = 'new-196ae765-7fd2-4188-96de-5a3ca0d19ecf';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-tvr788V4itiPVYls9bNlVjL5WtH56Ben';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '196ae765-7fd2-4188-96de-5a3ca0d19ecf';
  $display->content['new-196ae765-7fd2-4188-96de-5a3ca0d19ecf'] = $pane;
  $display->panels['filters'][1] = 'new-196ae765-7fd2-4188-96de-5a3ca0d19ecf';
  $pane = new stdClass();
  $pane->pid = 'new-0e6f9d34-a196-4e57-b824-23a197b78660';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-zrb4D5UUx8mNZ0OM83ChBiW9hkVGl2wd';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Grado de reutilización',
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
  $pane->uuid = '0e6f9d34-a196-4e57-b824-23a197b78660';
  $display->content['new-0e6f9d34-a196-4e57-b824-23a197b78660'] = $pane;
  $display->panels['filters'][2] = 'new-0e6f9d34-a196-4e57-b824-23a197b78660';
  $pane = new stdClass();
  $pane->pid = 'new-995d9e1f-6a8f-4172-88e2-c50ccda27861';
  $pane->panel = 'filters';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-11fsXKeW7U3DIxAy98Wb3l6NOvof9hkA';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Punto de consulta',
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
  $pane->uuid = '995d9e1f-6a8f-4172-88e2-c50ccda27861';
  $display->content['new-995d9e1f-6a8f-4172-88e2-c50ccda27861'] = $pane;
  $display->panels['filters'][3] = 'new-995d9e1f-6a8f-4172-88e2-c50ccda27861';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bbfb13a5-e07c-439e-b719-ac4baa72d8a3';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['initiative_accessible'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'send_content_initiative';
  $page->task = 'page';
  $page->admin_title = 'Send content initiative';
  $page->admin_description = '';
  $page->path = 'informa-sobre/iniciativas';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'create initiative content',
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
  $handler->name = 'page_send_content_initiative__panel';
  $handler->task = 'page';
  $handler->subtask = 'send_content_initiative';
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
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '262a462a-1cd2-4522-b375-bec33205d0e9';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_send_content_initiative__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-860b81e1-7b86-4101-ba4d-379cebccb389';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'dge_send_content-dge_send_content_initiative';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Comparte tu Iniciativa',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'dge-form dge-h2-hidden',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '860b81e1-7b86-4101-ba4d-379cebccb389';
  $display->content['new-860b81e1-7b86-4101-ba4d-379cebccb389'] = $pane;
  $display->panels['center'][0] = 'new-860b81e1-7b86-4101-ba4d-379cebccb389';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-860b81e1-7b86-4101-ba4d-379cebccb389';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['send_content_initiative'] = $page;

  return $pages;

}
