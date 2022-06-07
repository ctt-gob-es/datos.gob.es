<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_success (datos.gob.es)".
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
 * dgef_success.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgef_success_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create success content'.
  $permissions['create success content'] = array(
    'name' => 'create success content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'editor' => 'editor',
      'organization' => 'organization',
      'site manager' => 'site manager',
      'super editor' => 'super editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any success content'.
  $permissions['delete any success content'] = array(
    'name' => 'delete any success content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own success content'.
  $permissions['delete own success content'] = array(
    'name' => 'delete own success content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
      'super editor' => 'super editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any success content'.
  $permissions['edit any success content'] = array(
    'name' => 'edit any success content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
      'super editor' => 'super editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own success content'.
  $permissions['edit own success content'] = array(
    'name' => 'edit own success content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'organization' => 'organization',
      'site manager' => 'site manager',
      'super editor' => 'super editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
