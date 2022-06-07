<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_initiative (datos.gob.es)".
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
 * dgef_initiative.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dgef_initiative_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sender_data|node|initiative|form';
  $field_group->group_name = 'group_sender_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'initiative';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact data',
    'weight' => '20',
    'children' => array(
      0 => 'field_sender_company',
      1 => 'field_sender_email',
      2 => 'field_sender_name',
      3 => 'field_sender_phone',
      4 => 'field_sender_terms_of_use',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sender-data field-group-fieldset',
        'required_fields' => 0,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_sender_data|node|initiative|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Datos de contacto');

  return $field_groups;
}
