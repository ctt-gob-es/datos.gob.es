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
 * dgef_desafio_aporta.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgef_desafio_aporta_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create current_aporta content'.
  $permissions['create current_aporta content'] = array(
    'name' => 'create current_aporta content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create paragraph content finalists_challenge'.
  $permissions['create paragraph content finalists_challenge'] = array(
    'name' => 'create paragraph content finalists_challenge',
    'roles' => array(),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'delete any current_aporta content'.
  $permissions['delete any current_aporta content'] = array(
    'name' => 'delete any current_aporta content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own current_aporta content'.
  $permissions['delete own current_aporta content'] = array(
    'name' => 'delete own current_aporta content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete paragraph content finalists_challenge'.
  $permissions['delete paragraph content finalists_challenge'] = array(
    'name' => 'delete paragraph content finalists_challenge',
    'roles' => array(),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'edit any current_aporta content'.
  $permissions['edit any current_aporta content'] = array(
    'name' => 'edit any current_aporta content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own current_aporta content'.
  $permissions['edit own current_aporta content'] = array(
    'name' => 'edit own current_aporta content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'update paragraph content finalists_challenge'.
  $permissions['update paragraph content finalists_challenge'] = array(
    'name' => 'update paragraph content finalists_challenge',
    'roles' => array(),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content finalists_challenge'.
  $permissions['view paragraph content finalists_challenge'] = array(
    'name' => 'view paragraph content finalists_challenge',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  return $permissions;
}
