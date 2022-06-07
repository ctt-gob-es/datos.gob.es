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
 * dgef_blog_blog.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgef_blog_blog_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create blog_blog content'.
  $permissions['create blog_blog content'] = array(
    'name' => 'create blog_blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
      'super editor' => 'super editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any blog_blog content'.
  $permissions['delete any blog_blog content'] = array(
    'name' => 'delete any blog_blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own blog_blog content'.
  $permissions['delete own blog_blog content'] = array(
    'name' => 'delete own blog_blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
      'super editor' => 'super editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any blog_blog content'.
  $permissions['edit any blog_blog content'] = array(
    'name' => 'edit any blog_blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
      'super editor' => 'super editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own blog_blog content'.
  $permissions['edit own blog_blog content'] = array(
    'name' => 'edit own blog_blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
      'super editor' => 'super editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
