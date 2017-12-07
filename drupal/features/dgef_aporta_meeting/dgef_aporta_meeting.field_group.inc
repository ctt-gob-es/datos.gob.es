<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_aporta_meeting (datos.gob.es)".
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
 * dgef_aporta_meeting.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dgef_aporta_meeting_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_aporta_doc|node|aporta|form';
  $field_group->group_name = 'group_aporta_doc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documentación general',
    'weight' => '6',
    'children' => array(
      0 => 'field_group_aporta_doc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-aporta-doc field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_aporta_doc|node|aporta|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_aporta_gen_doc|node|aporta|form';
  $field_group->group_name = 'group_aporta_gen_doc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documentación general',
    'weight' => '8',
    'children' => array(
      0 => 'field_group_aporta_gen_doc_file',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-aporta-gen-doc field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_aporta_gen_doc|node|aporta|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_aporta_workgroup_pre|field_collection_item|field_aporta_workgroup|form';
  $field_group->group_name = 'group_aporta_workgroup_pre';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_aporta_workgroup';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Presentaciones',
    'weight' => '5',
    'children' => array(
      0 => 'field_aporta_workgroup_pre_pon',
      1 => 'field_aporta_workgroup_pre_doc',
      2 => 'field_aporta_workgroup_pre_pre',
      3 => 'field_aporta_workgroup_pre_vid',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-aporta-workgroup-pre field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_aporta_workgroup_pre|field_collection_item|field_aporta_workgroup|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Documentación general');
  t('Presentaciones');

  return $field_groups;
}
