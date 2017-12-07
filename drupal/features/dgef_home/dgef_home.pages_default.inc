<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_home (datos.gob.es)".
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
 * dgef_home.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dgef_home_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'Home';
  $page->admin_description = '';
  $page->path = 'home';
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
  $handler->name = 'page_home__panel';
  $handler->task = 'page';
  $handler->subtask = 'home';
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
          1 => 1,
          2 => 6,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Top',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 2,
          1 => 3,
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'children' => array(
          0 => 4,
        ),
        'class' => 'Left',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'children' => array(
          0 => 5,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'middle_left',
        ),
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'middle_right',
        ),
        'parent' => '3',
        'class' => '',
        'hide_empty' => 0,
      ),
      'middle_left' => array(
        'type' => 'region',
        'title' => 'Middle Left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
      'middle_right' => array(
        'type' => 'region',
        'title' => 'Middle Right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
        'hide_empty' => 0,
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'bottom',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'bottom' => array(
        'type' => 'region',
        'title' => 'Bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle_left' => NULL,
      'middle_right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e3b6d5bc-61f2-4da3-9125-3e894c55430c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fca78a4f-d47d-44fc-ba78-2551b03b3337';
    $pane->panel = 'bottom';
    $pane->type = 'block';
    $pane->subtype = 'boxes-home_interact';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'dge-interact',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fca78a4f-d47d-44fc-ba78-2551b03b3337';
    $display->content['new-fca78a4f-d47d-44fc-ba78-2551b03b3337'] = $pane;
    $display->panels['bottom'][0] = 'new-fca78a4f-d47d-44fc-ba78-2551b03b3337';
    $pane = new stdClass();
    $pane->pid = 'new-f91d2b20-4abb-4c2b-bf42-b348ccc3877a';
    $pane->panel = 'bottom';
    $pane->type = 'views';
    $pane->subtype = 'blog_home';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '3',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'dge-news',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f91d2b20-4abb-4c2b-bf42-b348ccc3877a';
    $display->content['new-f91d2b20-4abb-4c2b-bf42-b348ccc3877a'] = $pane;
    $display->panels['bottom'][1] = 'new-f91d2b20-4abb-4c2b-bf42-b348ccc3877a';
    $pane = new stdClass();
    $pane->pid = 'new-84d610d5-b8c7-44ef-95e9-919afa4f85f7';
    $pane->panel = 'bottom';
    $pane->type = 'views';
    $pane->subtype = 'apps_home';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '9',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'dge-apps',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '84d610d5-b8c7-44ef-95e9-919afa4f85f7';
    $display->content['new-84d610d5-b8c7-44ef-95e9-919afa4f85f7'] = $pane;
    $display->panels['bottom'][2] = 'new-84d610d5-b8c7-44ef-95e9-919afa4f85f7';
    $pane = new stdClass();
    $pane->pid = 'new-55689af3-ecd9-4f4b-9e79-50202b32e5f3';
    $pane->panel = 'bottom';
    $pane->type = 'block';
    $pane->subtype = 'dge_twitter-dge_twitter_block';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'dge-twitter',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '55689af3-ecd9-4f4b-9e79-50202b32e5f3';
    $display->content['new-55689af3-ecd9-4f4b-9e79-50202b32e5f3'] = $pane;
    $display->panels['bottom'][3] = 'new-55689af3-ecd9-4f4b-9e79-50202b32e5f3';
    $pane = new stdClass();
    $pane->pid = 'new-77915808-d65f-4c93-8957-10dd3b11323b';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'boxes-home_slogan';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'dge-slogan',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '77915808-d65f-4c93-8957-10dd3b11323b';
    $display->content['new-77915808-d65f-4c93-8957-10dd3b11323b'] = $pane;
    $display->panels['center'][0] = 'new-77915808-d65f-4c93-8957-10dd3b11323b';
    $pane = new stdClass();
    $pane->pid = 'new-3437a4a9-a961-4556-93ee-8e2e23587554';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'boxes-home_contribute';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'dge-iniciativa-aporta',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3437a4a9-a961-4556-93ee-8e2e23587554';
    $display->content['new-3437a4a9-a961-4556-93ee-8e2e23587554'] = $pane;
    $display->panels['center'][1] = 'new-3437a4a9-a961-4556-93ee-8e2e23587554';
    $pane = new stdClass();
    $pane->pid = 'new-303662d0-201d-4bc2-8c8c-4e2394c821c9';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'boxes-4_iodc_madrid_2016';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'dge-highlighted',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '303662d0-201d-4bc2-8c8c-4e2394c821c9';
    $display->content['new-303662d0-201d-4bc2-8c8c-4e2394c821c9'] = $pane;
    $display->panels['center'][2] = 'new-303662d0-201d-4bc2-8c8c-4e2394c821c9';
    $pane = new stdClass();
    $pane->pid = 'new-aa87c723-8f64-4f60-b83a-f8a18ebed43c';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'boxes-home_impact';
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
    $pane->uuid = 'aa87c723-8f64-4f60-b83a-f8a18ebed43c';
    $display->content['new-aa87c723-8f64-4f60-b83a-f8a18ebed43c'] = $pane;
    $display->panels['center'][3] = 'new-aa87c723-8f64-4f60-b83a-f8a18ebed43c';
    $pane = new stdClass();
    $pane->pid = 'new-ae6c5885-86bd-4e6e-bf86-af50af19b990';
    $pane->panel = 'middle_left';
    $pane->type = 'block';
    $pane->subtype = 'dge_ckan_blocks-dge_ckan_blocks_package_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Últimos datasets',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'dge-slogal',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ae6c5885-86bd-4e6e-bf86-af50af19b990';
    $display->content['new-ae6c5885-86bd-4e6e-bf86-af50af19b990'] = $pane;
    $display->panels['middle_left'][0] = 'new-ae6c5885-86bd-4e6e-bf86-af50af19b990';
    $pane = new stdClass();
    $pane->pid = 'new-b79b6bf6-c7da-45bb-89c4-885d5759b15a';
    $pane->panel = 'middle_right';
    $pane->type = 'block';
    $pane->subtype = 'dge_ckan_blocks-dge_ckan_blocks_init_review';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Iniciativas de datos abiertos',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'dge-iniciativas-datos',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b79b6bf6-c7da-45bb-89c4-885d5759b15a';
    $display->content['new-b79b6bf6-c7da-45bb-89c4-885d5759b15a'] = $pane;
    $display->panels['middle_right'][0] = 'new-b79b6bf6-c7da-45bb-89c4-885d5759b15a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
