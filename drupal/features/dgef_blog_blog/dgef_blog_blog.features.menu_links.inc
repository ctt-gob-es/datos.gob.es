<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_blog_blog (datos.gob.es)".
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
 * dgef_blog_blog.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dgef_blog_blog_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_blog-menu-position-rule:menu-position/12.
  $menu_links['main-menu_blog-menu-position-rule:menu-position/12'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/12',
    'router_path' => 'menu-position/%',
    'link_title' => 'Blog (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_blog-menu-position-rule:menu-position/12',
    ),
    'module' => 'menu_position',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'main-menu_blog:blog',
  );
  // Exported menu link: main-menu_blog:blog.
  $menu_links['main-menu_blog:blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_blog:blog',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_innovacin:<void9>',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  t('Blog (menu position rule)');

  return $menu_links;
}
