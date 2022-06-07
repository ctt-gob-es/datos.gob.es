<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_desafio_aporta (datos.gob.es)".
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
 * dgef_desafio_aporta.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_desafio_aporta_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'challenge_aporta_page';
  $page->task = 'page';
  $page->admin_title = 'Desafíos Aporta';
  $page->admin_description = '';
  $page->path = 'desafios-aporta';
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
  $handler->name = 'page_challenge_aporta_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'challenge_aporta_page';
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
  $display->title = 'Desafíos Aporta';
  $display->uuid = '0d1cc830-0277-4321-8761-2c6183c84553';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_challenge_aporta_page__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ec364b44-6f7f-455a-a553-30bec54156ea';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '7781',
    'links' => 1,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'actual_challenge',
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
  $pane->uuid = 'ec364b44-6f7f-455a-a553-30bec54156ea';
  $display->content['new-ec364b44-6f7f-455a-a553-30bec54156ea'] = $pane;
  $display->panels['center'][0] = 'new-ec364b44-6f7f-455a-a553-30bec54156ea';
  $pane = new stdClass();
  $pane->pid = 'new-69be9286-e812-4416-9cb6-51556f06ac39';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'challenge_aporta_view';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
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
  $pane->uuid = '69be9286-e812-4416-9cb6-51556f06ac39';
  $display->content['new-69be9286-e812-4416-9cb6-51556f06ac39'] = $pane;
  $display->panels['center'][1] = 'new-69be9286-e812-4416-9cb6-51556f06ac39';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-69be9286-e812-4416-9cb6-51556f06ac39';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['challenge_aporta_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'winners_aporta_page';
  $page->task = 'page';
  $page->admin_title = 'Premios Aporta';
  $page->admin_description = '';
  $page->path = 'premios-aporta-listado2';
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
  $handler->name = 'page_winners_aporta_page__panel_context_658d099b-1f24-4e7b-9629-b06a7e6a4254';
  $handler->task = 'page';
  $handler->subtask = 'winners_aporta_page';
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
    'name' => '',
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
  $display->title = 'Premios Aporta';
  $display->uuid = 'd9fd7d5b-5e72-48bc-ab9d-1a7d251ac296';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_winners_aporta_page__panel_context_658d099b-1f24-4e7b-9629-b06a7e6a4254';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-043fd9d3-7745-48fb-981d-ce63847f2e32';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '7782',
    'links' => 1,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'actual_winners',
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
  $pane->uuid = '043fd9d3-7745-48fb-981d-ce63847f2e32';
  $display->content['new-043fd9d3-7745-48fb-981d-ce63847f2e32'] = $pane;
  $display->panels['center'][0] = 'new-043fd9d3-7745-48fb-981d-ce63847f2e32';
  $pane = new stdClass();
  $pane->pid = 'new-38f26a25-48f7-4da3-b0a5-72c5a3e84e1e';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'winners_aporta_search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
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
  $pane->uuid = '38f26a25-48f7-4da3-b0a5-72c5a3e84e1e';
  $display->content['new-38f26a25-48f7-4da3-b0a5-72c5a3e84e1e'] = $pane;
  $display->panels['center'][1] = 'new-38f26a25-48f7-4da3-b0a5-72c5a3e84e1e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-043fd9d3-7745-48fb-981d-ce63847f2e32';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['winners_aporta_page'] = $page;

  return $pages;

}
