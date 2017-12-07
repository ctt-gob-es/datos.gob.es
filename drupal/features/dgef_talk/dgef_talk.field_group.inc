<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_talk (datos.gob.es)".
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
 * dgef_talk.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dgef_talk_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_talk_bio|node|talk|form';
  $field_group->group_name = 'group_talk_bio';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'talk';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'BIO',
    'weight' => '2',
    'children' => array(
      0 => 'field_talk_bio_company',
      1 => 'field_talk_bio_contact',
      2 => 'field_talk_bio_country',
      3 => 'field_talk_bio_name',
      4 => 'field_talk_bio_sector',
      5 => 'field_talk_bio_spec',
      6 => 'field_talk_bio_web',
      7 => 'field_talk_bio_works',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-talk-bio field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_talk_bio|node|talk|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('BIO');

  return $field_groups;
}
