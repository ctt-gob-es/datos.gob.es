<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_bulletin (datos.gob.es)".
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
 * dgef_bulletin.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgef_bulletin_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create bulletin content'.
  $permissions['create bulletin content'] = array(
    'name' => 'create bulletin content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any bulletin content'.
  $permissions['delete any bulletin content'] = array(
    'name' => 'delete any bulletin content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own bulletin content'.
  $permissions['delete own bulletin content'] = array(
    'name' => 'delete own bulletin content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any bulletin content'.
  $permissions['edit any bulletin content'] = array(
    'name' => 'edit any bulletin content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own bulletin content'.
  $permissions['edit own bulletin content'] = array(
    'name' => 'edit own bulletin content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
