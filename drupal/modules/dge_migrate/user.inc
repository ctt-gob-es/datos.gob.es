<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_migrate (datos.gob.es)".
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

class DGEUserOrganizationMigration extends DrupalUser7Migration {

  protected $organization_role_id = 5;
  protected $organization_role_name = 'organization';

  public function __construct($arguments) {

    parent::__construct($arguments);
    $this->removeFieldMapping('roles');
    $this->addFieldMapping('roles')
      ->separator(',')
      ->defaultValue(DRUPAL_AUTHENTICATED_RID.','.$this->get_role_destination($this->organization_role_name));

  }

  protected function query() {
    $query = parent::query();

    // Only Organismo user
    $subquery_in = db_select('users', 'u');
    $subquery_in->fields('u',array('uid'));
    $subquery_in->innerJoin('users_roles', 'ur', 'ur.uid=u.uid');
    $subquery_in->condition('ur.rid', $this->organization_role_id, '=');

    // No any other role
    $subquery_notin = db_select('users', 'u');
    $subquery_notin->fields('u',array('uid'));
    $subquery_notin->innerJoin('users_roles', 'ur', 'ur.uid=u.uid');
    $subquery_notin->condition('ur.rid', $this->organization_role_id, '<>');

    // Only Organismo Users
    $query->condition('u.uid', $subquery_in, 'IN');
    $query->condition('u.uid', $subquery_notin, 'NOT IN');

    return $query;
  }

  protected function get_role_destination($role_name) {
    $rid = Database::getConnection('default')
      ->select('role', 'r')
      ->fields('r',array('rid'))
      ->condition('r.name',$role_name,'=')
      ->execute()->fetchField();
    return $rid;
  }
}

class DGEUserEditorMigration extends DrupalUser7Migration {

  protected $administrator_role_id = 3;
  protected $editor_role_id = 8;
  protected $editor_role_name = 'editor';

  public function __construct($arguments) {

    parent::__construct($arguments);
    $this->removeFieldMapping('roles');
    $this->addFieldMapping('roles')
      ->separator(',')
      ->defaultValue(DRUPAL_AUTHENTICATED_RID.','.$this->get_role_destination($this->editor_role_name));

  }

  protected function query() {
    $query = parent::query();

    // Only No Organismo user (Editors)
    $subquery_in = db_select('users', 'u');
    $subquery_in->fields('u',array('uid'));
    $subquery_in->innerJoin('users_roles', 'ur', 'ur.uid=u.uid');
    $or = db_or();
    $or->condition('ur.rid', $this->administrator_role_id, '=');
    $or->condition('ur.rid', $this->editor_role_id, '=');
    $subquery_in->condition($or);

    // Only Editor Users
    $query->condition('u.uid', $subquery_in, 'IN');
    $query->condition('u.uid', '1', '<>');

    return $query;
  }

  protected function get_role_destination($role_name) {
    $rid = Database::getConnection('default')
      ->select('role', 'r')
      ->fields('r',array('rid'))
      ->condition('r.name',$role_name,'=')
      ->execute()->fetchField();
    return $rid;
  }
}