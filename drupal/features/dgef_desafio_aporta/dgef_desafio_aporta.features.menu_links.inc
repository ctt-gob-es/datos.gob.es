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
 * dgef_desafio_aporta.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dgef_desafio_aporta_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-nav_premios-aporta:node/7782.
  $menu_links['menu-footer-nav_premios-aporta:node/7782'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'node/7782',
    'router_path' => 'node/%',
    'link_title' => 'Premios Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_premios-aporta:node/7782',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 37,
    'customized' => 1,
    'language' => 'es',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_iniciativa-aporta:<front>',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Premios Aporta');

  return $menu_links;
}
