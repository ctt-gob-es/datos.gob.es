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
 * dgef_sector.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgef_sector_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create paragraph content free_content'.
  $permissions['create paragraph content free_content'] = array(
    'name' => 'create paragraph content free_content',
    'roles' => array(
      'editor' => 'editor',
      'super editor' => 'super editor',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'create paragraph content views_sector'.
  $permissions['create paragraph content views_sector'] = array(
    'name' => 'create paragraph content views_sector',
    'roles' => array(
      'editor' => 'editor',
      'super editor' => 'super editor',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'create sectores content'.
  $permissions['create sectores content'] = array(
    'name' => 'create sectores content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
      'super editor' => 'super editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any sectores content'.
  $permissions['delete any sectores content'] = array(
    'name' => 'delete any sectores content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own sectores content'.
  $permissions['delete own sectores content'] = array(
    'name' => 'delete own sectores content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
      'super editor' => 'super editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete paragraph content free_content'.
  $permissions['delete paragraph content free_content'] = array(
    'name' => 'delete paragraph content free_content',
    'roles' => array(
      'editor' => 'editor',
      'super editor' => 'super editor',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'delete paragraph content views_sector'.
  $permissions['delete paragraph content views_sector'] = array(
    'name' => 'delete paragraph content views_sector',
    'roles' => array(
      'editor' => 'editor',
      'super editor' => 'super editor',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'edit any sectores content'.
  $permissions['edit any sectores content'] = array(
    'name' => 'edit any sectores content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
      'super editor' => 'super editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own sectores content'.
  $permissions['edit own sectores content'] = array(
    'name' => 'edit own sectores content',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
      'super editor' => 'super editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'update paragraph content free_content'.
  $permissions['update paragraph content free_content'] = array(
    'name' => 'update paragraph content free_content',
    'roles' => array(
      'editor' => 'editor',
      'super editor' => 'super editor',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'update paragraph content views_sector'.
  $permissions['update paragraph content views_sector'] = array(
    'name' => 'update paragraph content views_sector',
    'roles' => array(
      'editor' => 'editor',
      'super editor' => 'super editor',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view any unpublished sectores content'.
  $permissions['view any unpublished sectores content'] = array(
    'name' => 'view any unpublished sectores content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view paragraph content free_content'.
  $permissions['view paragraph content free_content'] = array(
    'name' => 'view paragraph content free_content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content views_sector'.
  $permissions['view paragraph content views_sector'] = array(
    'name' => 'view paragraph content views_sector',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  return $permissions;
}
