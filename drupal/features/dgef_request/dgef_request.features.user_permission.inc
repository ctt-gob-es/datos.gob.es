<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_request (datos.gob.es)".
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
 * dgef_request.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgef_request_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create request content'.
  $permissions['create request content'] = array(
    'name' => 'create request content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'editor' => 'editor',
      'organization' => 'organization',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any request content'.
  $permissions['delete any request content'] = array(
    'name' => 'delete any request content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own request content'.
  $permissions['delete own request content'] = array(
    'name' => 'delete own request content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any request content'.
  $permissions['edit any request content'] = array(
    'name' => 'edit any request content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own request content'.
  $permissions['edit own request content'] = array(
    'name' => 'edit own request content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'organization' => 'organization',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
