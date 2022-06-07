<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
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
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
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
    'aporta_awards' => array(
      'admin_title' => 'Aporta Awards',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:13:"aporta_awards";s:13:"aporta_awards";}}}',
      'menu_name' => 'main-menu',
      'plid' => 1217,
      'mlid' => 1218,
      'weight' => 0,
      'machine_name' => 'aporta_awards',
    ),
    'aporta_meetings' => array(
      'admin_title' => 'Aporta meetings',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:6:"aporta";s:6:"aporta";}}}',
      'menu_name' => 'main-menu',
      'plid' => 710,
      'mlid' => 895,
      'weight' => -6,
      'machine_name' => 'aporta_meetings',
    ),
  );
  return $items;
}
