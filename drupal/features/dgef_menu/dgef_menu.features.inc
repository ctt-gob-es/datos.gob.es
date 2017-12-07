<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_menu (datos.gob.es)".
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
 * dgef_menu.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgef_menu_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_menu_position_default_menu_positions().
 */
function dgef_menu_menu_position_default_menu_positions() {
  $items = array(
    'aporta_meetings' => array(
      'admin_title' => 'Aporta meetings',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:6:"aporta";s:6:"aporta";}}}',
      'menu_name' => 'main-menu',
      'plid' => 710,
      'mlid' => 895,
      'weight' => 0,
      'machine_name' => 'aporta_meetings',
    ),
    'apps' => array(
      'admin_title' => 'Apps',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:3:"app";s:3:"app";}}}',
      'menu_name' => 'main-menu',
      'plid' => 645,
      'mlid' => 891,
      'weight' => 0,
      'machine_name' => 'apps',
    ),
    'blogs' => array(
      'admin_title' => 'Blogs',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:4:"blog";s:4:"blog";}}}',
      'menu_name' => 'main-menu',
      'plid' => 651,
      'mlid' => 890,
      'weight' => 0,
      'machine_name' => 'blogs',
    ),
    'data_requests' => array(
      'admin_title' => 'Data requests',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:7:"request";s:7:"request";}}}',
      'menu_name' => 'main-menu',
      'plid' => 649,
      'mlid' => 898,
      'weight' => 0,
      'machine_name' => 'data_requests',
    ),
    'docs' => array(
      'admin_title' => 'Docs',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:3:"doc";s:3:"doc";}}}',
      'menu_name' => 'main-menu',
      'plid' => 647,
      'mlid' => 894,
      'weight' => 0,
      'machine_name' => 'docs',
    ),
    'events' => array(
      'admin_title' => 'Events',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:5:"event";s:5:"event";}}}',
      'menu_name' => 'main-menu',
      'plid' => 653,
      'mlid' => 897,
      'weight' => 0,
      'machine_name' => 'events',
    ),
    'interviews' => array(
      'admin_title' => 'Interviews',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:4:"talk";s:4:"talk";}}}',
      'menu_name' => 'main-menu',
      'plid' => 654,
      'mlid' => 896,
      'weight' => 0,
      'machine_name' => 'interviews',
    ),
    'newsletters' => array(
      'admin_title' => 'Newsletters',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:8:"bulletin";s:8:"bulletin";}}}',
      'menu_name' => 'main-menu',
      'plid' => 709,
      'mlid' => 892,
      'weight' => 0,
      'machine_name' => 'newsletters',
    ),
    'success' => array(
      'admin_title' => 'Success',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:7:"success";s:7:"success";}}}',
      'menu_name' => 'main-menu',
      'plid' => 646,
      'mlid' => 893,
      'weight' => 0,
      'machine_name' => 'success',
    ),
    'users' => array(
      'admin_title' => 'Users',
      'enabled' => 1,
      'conditions' => 'a:1:{s:9:"user_page";a:1:{s:16:"user_page_enable";i:1;}}',
      'menu_name' => 'main-menu',
      'plid' => 2,
      'mlid' => 934,
      'weight' => 0,
      'machine_name' => 'users',
    ),
  );
  return $items;
}
