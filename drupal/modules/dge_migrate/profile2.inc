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

class DGEProfile2OrganizationMigration extends DrupalMigration {

  protected $organization_profile_type = 'datos_de_organismo';
  protected $organization_role_id = 5;
  protected $organization_role_name = 'organization';

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->version2 = new DrupalVersion7($arguments);
    $this->profileFields = $this->version2->getSourceFields('profile2', $this->organization_profile_type);

    // Redefine the source (it was defined in DrupalUserMigration) so the
    // profile fields are included.
    $this->source = new MigrateSourceSQL($this->query(),
      array('uid' => 'User ID') + $this->profileFields, NULL, array('map_joinable' => FALSE));

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'pid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationProfile2::getKeySchema()
    );
    $this->destination = new MigrateDestinationProfile2('agency_data');

    //$this->addUnmigratedDestinations(array('id'));

    // Map Profile2 Member fields.
    //$this->addFieldMapping('field_cargo_perfil', 'field_position_agency');
    //$this->addFieldMapping('field_name_last', 'field_name_last');
    //$this->addFieldMapping('field_title', 'field_title');
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Get Profile2 source values keyed by the Profile2 pid (instead of UID).
    $profile_id = Database::getConnection('default', $this->sourceConnection)
      ->select('profile', 'p')
      ->fields('p',array('pid'))
      ->condition('p.uid', $row->uid)
      ->condition('p.type',$this->organization_profile_type,'=')
      ->execute()->fetchField();
    $this->version2->getSourceValues($row, $profile_id);
  }

  /**
   * Query for the basic user data. Same query is used for all currently-supported
   * versions of Drupal.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    // Do not attempt to migrate the anonymous user row.
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('profile', 'p')
      ->fields('p')
      ->condition('p.type',$this->organization_profile_type,'=');

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
    $query->innerJoin('users', 'u', 'u.uid=p.uid');
    $query->condition('u.uid', $subquery_in, 'IN');
    $query->condition('u.uid', $subquery_notin, 'NOT IN');

    $query->innerJoin('field_data_field_organismo_raiz','fdfor','fdfor.entity_id = p.pid');
    $query->innerJoin('taxonomy_term_data','ttd','ttd.tid = fdfor.field_organismo_raiz_tid');
    $query->isNotNull('ttd.name');
    return $query;

  }

}