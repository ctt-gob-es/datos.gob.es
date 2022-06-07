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
 * dgef_desafio_aporta.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dgef_desafio_aporta_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agenda_2|node|current_aporta|form';
  $field_group->group_name = 'group_agenda_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'current_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_agenda';
  $field_group->data = array(
    'label' => 'Agenda',
    'weight' => '58',
    'children' => array(
      0 => 'field_content_agenda',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-agenda-2 field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_agenda|node|current_aporta|form';
  $field_group->group_name = 'group_agenda';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'current_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_all';
  $field_group->data = array(
    'label' => 'Agenda',
    'weight' => '30',
    'children' => array(
      0 => 'group_aporta_doc_new',
      1 => 'group_agenda_2',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_aporta_doc_new|node|current_aporta|form';
  $field_group->group_name = 'group_aporta_doc_new';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'current_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_agenda';
  $field_group->data = array(
    'label' => 'Documentación general',
    'weight' => '60',
    'children' => array(
      0 => 'field_group_aporta_doc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Documentación general',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-aporta-doc field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_base_challenge|node|aporta_awards|form';
  $field_group->group_name = 'group_base_challenge';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aporta_awards';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_global_content';
  $field_group->data = array(
    'label' => 'Bases del desafío',
    'weight' => '5',
    'children' => array(
      0 => 'field_bases_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-base-challenge field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_base_challenge|node|challenge_aporta|form';
  $field_group->group_name = 'group_base_challenge';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_content';
  $field_group->data = array(
    'label' => 'Bases del desafío',
    'weight' => '47',
    'children' => array(
      0 => 'field_bases_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-base-challenge field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_all|node|current_aporta|form';
  $field_group->group_name = 'group_content_all';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'current_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Grupos de Contenido',
    'weight' => '3',
    'children' => array(
      0 => 'group_location',
      1 => 'group_general',
      2 => 'group_inscriptions',
      3 => 'group_agenda',
      4 => 'group_ponents',
      5 => 'group_related_content',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content-all field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description_challenge|node|challenge_aporta|form';
  $field_group->group_name = 'group_description_challenge';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_selected_items';
  $field_group->data = array(
    'label' => 'Descripción',
    'weight' => '76',
    'children' => array(
      0 => 'field_selected_description',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-description-challenge field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description|paragraphs_item|fase|form';
  $field_group->group_name = 'group_description';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'fase';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_content';
  $field_group->data = array(
    'label' => 'Descripción',
    'weight' => '6',
    'children' => array(
      0 => 'field_fase_description',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-description field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_evaluation|node|aporta_awards|form';
  $field_group->group_name = 'group_evaluation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aporta_awards';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_global_content';
  $field_group->data = array(
    'label' => 'Evaluación',
    'weight' => '8',
    'children' => array(
      0 => 'field_evaluation_title',
      1 => 'field_evaluation_fases',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-evaluation field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_evaluation|node|challenge_aporta|form';
  $field_group->group_name = 'group_evaluation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_content';
  $field_group->data = array(
    'label' => 'Evaluación',
    'weight' => '51',
    'children' => array(
      0 => 'field_evaluation_title',
      1 => 'field_evaluation_fases',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-evaluation field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fases|node|challenge_aporta|form';
  $field_group->group_name = 'group_fases';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_content';
  $field_group->data = array(
    'label' => 'Fases',
    'weight' => '49',
    'children' => array(
      0 => 'field_fase',
      1 => 'field_fase_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_content|node|carousel|form';
  $field_group->group_name = 'group_general_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'carousel';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'general content',
    'weight' => '0',
    'children' => array(
      0 => 'group_title',
      1 => 'group_slide',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_content|node|challenge_aporta|form';
  $field_group->group_name = 'group_general_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contenido General',
    'weight' => '3',
    'children' => array(
      0 => 'group_base_challenge',
      1 => 'group_principal',
      2 => 'group_inscriptions',
      3 => 'group_fases',
      4 => 'group_persons_challenge',
      5 => 'group_evaluation',
      6 => 'group_selected_persons',
      7 => 'group_winners',
      8 => 'group_related_cont',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-general-content field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_content|paragraphs_item|fase|form';
  $field_group->group_name = 'group_general_content';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'fase';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General information',
    'weight' => '0',
    'children' => array(
      0 => 'group_description',
      1 => 'group_image',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-general-content field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|aporta_awards|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aporta_awards';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_global_content';
  $field_group->data = array(
    'label' => 'Contenido General',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'field_aporta_subtitle',
      2 => 'field_image',
      3 => 'field_aporta_date',
      4 => 'field_collaborator',
      5 => 'field_inscriptions_taxonomy_2',
      6 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|current_aporta|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'current_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_all';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '28',
    'children' => array(
      0 => 'body',
      1 => 'field_aporta_subtitle',
      2 => 'field_aporta_date',
      3 => 'field_aporta_image',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_global_content|node|aporta_awards|form';
  $field_group->group_name = 'group_global_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aporta_awards';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contenido Global',
    'weight' => '3',
    'children' => array(
      0 => 'group_general',
      1 => 'group_base_challenge',
      2 => 'group_inscriptions',
      3 => 'group_persons_challenge',
      4 => 'group_evaluation',
      5 => 'group_related_content',
      6 => 'group_selected_persons',
      7 => 'group_winners',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-global-content field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_horizontal_winners|node|challenge_aporta|form';
  $field_group->group_name = 'group_horizontal_winners';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_winners';
  $field_group->data = array(
    'label' => 'Horizontal Premiado',
    'weight' => '5',
    'children' => array(
      0 => 'group_principal_horizontal',
      1 => 'group_meeting',
      2 => 'group_winners_content',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-horizontal-winners field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_image|paragraphs_item|fase|form';
  $field_group->group_name = 'group_image';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'fase';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_content';
  $field_group->data = array(
    'label' => 'Imagen',
    'weight' => '7',
    'children' => array(
      0 => 'field_fase_image',
      1 => 'field_image_position',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-image field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inscriptions|node|aporta_awards|form';
  $field_group->group_name = 'group_inscriptions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aporta_awards';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_global_content';
  $field_group->data = array(
    'label' => 'Inscripciones',
    'weight' => '6',
    'children' => array(
      0 => 'field_inscriptions_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-inscriptions field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inscriptions|node|challenge_aporta|form';
  $field_group->group_name = 'group_inscriptions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_content';
  $field_group->data = array(
    'label' => 'Inscripciones',
    'weight' => '48',
    'children' => array(
      0 => 'field_inscriptions_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-inscriptions field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inscriptions|node|current_aporta|form';
  $field_group->group_name = 'group_inscriptions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'current_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_all';
  $field_group->data = array(
    'label' => 'Inscripciones',
    'weight' => '31',
    'children' => array(
      0 => 'field_content_inscriptions',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-inscriptions field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|current_aporta|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'current_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_all';
  $field_group->data = array(
    'label' => 'Localización',
    'weight' => '29',
    'children' => array(
      0 => 'field_location',
      1 => 'field_photo_place',
      2 => 'field_place_description',
      3 => 'field_location_gmaps',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meeting|node|challenge_aporta|form';
  $field_group->group_name = 'group_meeting';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_horizontal_winners';
  $field_group->data = array(
    'label' => 'Encuentro',
    'weight' => '16',
    'children' => array(
      0 => 'field_winners_meeting',
      1 => 'field_winners_title_meeting',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-meeting field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_persons_challenge|node|aporta_awards|form';
  $field_group->group_name = 'group_persons_challenge';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aporta_awards';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_global_content';
  $field_group->data = array(
    'label' => 'Jurado',
    'weight' => '7',
    'children' => array(
      0 => 'field_person_challenge',
      1 => 'field_jury_description',
      2 => 'field_person_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-persons-challenge field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_persons_challenge|node|challenge_aporta|form';
  $field_group->group_name = 'group_persons_challenge';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_content';
  $field_group->data = array(
    'label' => 'Jurado',
    'weight' => '50',
    'children' => array(
      0 => 'field_person_challenge',
      1 => 'field_person_title',
      2 => 'field_jury_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-persons-challenge field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ponents|node|current_aporta|form';
  $field_group->group_name = 'group_ponents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'current_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_all';
  $field_group->data = array(
    'label' => 'Ponentes',
    'weight' => '32',
    'children' => array(
      0 => 'field_description_ponents',
      1 => 'field_ponents_paragraph',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-ponents field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_principal_horizontal|node|challenge_aporta|form';
  $field_group->group_name = 'group_principal_horizontal';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_horizontal_winners';
  $field_group->data = array(
    'label' => 'Principal Horizontal',
    'weight' => '14',
    'children' => array(
      0 => 'field_winners_description',
      1 => 'field_winners_video',
      2 => 'field_video_subtitle',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-principal-horizontal field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_principal|node|challenge_aporta|form';
  $field_group->group_name = 'group_principal';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_content';
  $field_group->data = array(
    'label' => 'Apartado principal',
    'weight' => '46',
    'children' => array(
      0 => 'body',
      1 => 'field_image',
      2 => 'field_aporta_subtitle',
      3 => 'field_inscriptions_taxonomy',
      4 => 'field_aporta_date',
      5 => 'field_collaborator',
      6 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-principal field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_content|node|aporta_awards|form';
  $field_group->group_name = 'group_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aporta_awards';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_global_content';
  $field_group->data = array(
    'label' => 'Contenido Relacionado',
    'weight' => '11',
    'children' => array(
      0 => 'field_related_content',
      1 => 'field_content_related',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_content|node|current_aporta|form';
  $field_group->group_name = 'group_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'current_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content_all';
  $field_group->data = array(
    'label' => 'Contenido relacionado',
    'weight' => '34',
    'children' => array(
      0 => 'field_related_content',
      1 => 'field_content_related',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Contenido relacionado',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-related-content field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_cont|node|challenge_aporta|form';
  $field_group->group_name = 'group_related_cont';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_content';
  $field_group->data = array(
    'label' => 'Contenido Relacionado',
    'weight' => '54',
    'children' => array(
      0 => 'field_content_related',
      1 => 'field_related_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_selected_image|node|challenge_aporta|form';
  $field_group->group_name = 'group_selected_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_selected_items';
  $field_group->data = array(
    'label' => 'Imagen',
    'weight' => '77',
    'children' => array(
      0 => 'field_selected_image',
      1 => 'field_image_position',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-selected-image field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_selected_items|node|challenge_aporta|form';
  $field_group->group_name = 'group_selected_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_selected_persons';
  $field_group->data = array(
    'label' => 'Elementos Seleccionados',
    'weight' => '75',
    'children' => array(
      0 => 'group_description_challenge',
      1 => 'group_selected_image',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-selected-items field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_selected_persons|node|aporta_awards|form';
  $field_group->group_name = 'group_selected_persons';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aporta_awards';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_global_content';
  $field_group->data = array(
    'label' => 'Seleccionados',
    'weight' => '9',
    'children' => array(
      0 => 'field_selected_description',
      1 => 'field_selected_ideas',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-selected-persons field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_selected_persons|node|challenge_aporta|form';
  $field_group->group_name = 'group_selected_persons';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_content';
  $field_group->data = array(
    'label' => 'Seleccionados',
    'weight' => '52',
    'children' => array(
      0 => 'field_selected_ideas',
      1 => 'group_selected_items',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-selected-persons field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slide|node|carousel|form';
  $field_group->group_name = 'group_slide';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'carousel';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_content';
  $field_group->data = array(
    'label' => 'Diapositiva',
    'weight' => '10',
    'children' => array(
      0 => 'field_carousel2',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-slide field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_winners_content|node|challenge_aporta|form';
  $field_group->group_name = 'group_winners_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_horizontal_winners';
  $field_group->data = array(
    'label' => 'Premiados Contenido',
    'weight' => '15',
    'children' => array(
      0 => 'field_winners_content',
      1 => 'field_finalist_content',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-winners-content field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_winners|node|aporta_awards|form';
  $field_group->group_name = 'group_winners';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'aporta_awards';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_global_content';
  $field_group->data = array(
    'label' => 'Premiados',
    'weight' => '10',
    'children' => array(
      0 => 'field_winners_description',
      1 => 'field_winnersp',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-winners field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_winners|node|challenge_aporta|form';
  $field_group->group_name = 'group_winners';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge_aporta';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_content';
  $field_group->data = array(
    'label' => 'Premiados',
    'weight' => '53',
    'children' => array(
      0 => 'group_horizontal_winners',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-winners field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda');
  t('Apartado principal');
  t('Bases del desafío');
  t('Contenido General');
  t('Contenido Global');
  t('Contenido Relacionado');
  t('Contenido relacionado');
  t('Descripción');
  t('Diapositiva');
  t('Documentación general');
  t('Elementos Seleccionados');
  t('Encuentro');
  t('Evaluación');
  t('Fases');
  t('General');
  t('General information');
  t('Grupos de Contenido');
  t('Horizontal Premiado');
  t('Imagen');
  t('Inscripciones');
  t('Jurado');
  t('Localización');
  t('Ponentes');
  t('Premiados');
  t('Premiados Contenido');
  t('Principal Horizontal');
  t('Seleccionados');
  t('general content');

  return $field_groups;
}
