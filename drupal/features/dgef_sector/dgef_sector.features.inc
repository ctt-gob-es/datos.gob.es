<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_sector (datos.gob.es)".
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
 * dgef_sector.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgef_sector_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_menu_position_default_menu_positions().
 */
function dgef_sector_menu_position_default_menu_positions() {
  $items = array(
    'sectores' => array(
      'admin_title' => 'Sectores',
      'enabled' => 1,
      'conditions' => 'a:1:{s:12:"content_type";a:1:{s:12:"content_type";a:1:{s:8:"sectores";s:8:"sectores";}}}',
      'menu_name' => 'main-menu',
      'plid' => 1213,
      'mlid' => 1343,
      'weight' => 0,
      'machine_name' => 'sectores',
    ),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function dgef_sector_node_info() {
  $items = array(
    'sectores' => array(
      'name' => t('Sectores'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function dgef_sector_paragraphs_info() {
  $items = array(
    'free_content' => array(
      'name' => 'Contenido libre',
      'bundle' => 'free_content',
      'locked' => '1',
    ),
    'views_sector' => array(
      'name' => 'Opciones vistas sectores',
      'bundle' => 'views_sector',
      'locked' => '1',
    ),
  );
  return $items;
}
