<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_comment (datos.gob.es)".
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
 * dgef_comment.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgef_comment_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access dataset comment'.
  $permissions['access dataset comment'] = array(
    'name' => 'access dataset comment',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'dge_comment',
  );

  // Exported permission: 'approve organization comment'.
  $permissions['approve organization comment'] = array(
    'name' => 'approve organization comment',
    'roles' => array(
      'administrator' => 'administrator',
      'organization' => 'organization',
    ),
    'module' => 'dge_comment',
  );

  // Exported permission: 'edit organization comment'.
  $permissions['edit organization comment'] = array(
    'name' => 'edit organization comment',
    'roles' => array(
      'administrator' => 'administrator',
      'organization' => 'organization',
    ),
    'module' => 'dge_comment',
  );

  return $permissions;
}
