<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_app (datos.gob.es)".
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
 * dgef_app.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgef_app_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create app content'.
  $permissions['create app content'] = array(
    'name' => 'create app content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'editor' => 'editor',
      'organization' => 'organization',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any app content'.
  $permissions['delete any app content'] = array(
    'name' => 'delete any app content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own app content'.
  $permissions['delete own app content'] = array(
    'name' => 'delete own app content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any app content'.
  $permissions['edit any app content'] = array(
    'name' => 'edit any app content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own app content'.
  $permissions['edit own app content'] = array(
    'name' => 'edit own app content',
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
