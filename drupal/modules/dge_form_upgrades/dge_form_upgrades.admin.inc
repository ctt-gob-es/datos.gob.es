<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_form_upgrades (datos.gob.es)".
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
 * Returns description admin settings form.
 */
function dge_form_descriptions_admin_settings() {
  $types = node_type_get_types();
  $node_types = array();
  foreach ($types as $node_type) {
    $node_types[$node_type->type] = $node_type->name;
  }

  $enabled_content_types = variable_get('dge_send_content_types', ADD_CONTENT_TYPES);
  $languages = i18n_language_list();

  //Common defaults for text fields
  $defaults = array(
    'value' => '',
    'format' => 'full_html',
  );

  // Display fields only for enabled content types
  foreach($node_types as $type => $type_name) {
    if (in_array($type, $enabled_content_types)) {
      // Text for content type
      $form['content_type_'.$type] = array(
        '#type' => 'fieldset',
        '#title' => t('Add !name form descriptions', array('!name' => $type_name)),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['content_type_'.$type][$type.'_all_access_form_description'] = array(
        '#type' => 'checkbox',
        '#title' => t('Registered users can see the description'),
        '#description' => t('Administrators, site admins, editors and organizations will see the description'),
        '#default_value' => variable_get($type.'_all_access_form_description', 0),
      );
      foreach ($languages as $langcode => $language_name) {
        // Retrieve the default values for 'value' and 'format'
        $content_type_description_field = variable_get($type.'_'.$langcode.'_form_description', $defaults);
        $lang_default = '';
        if ($langcode == 'es') {
          $lang_default = ' ('. t('Default language') . ')';
        }
        $form['content_type_'.$type][$type.'_'.$langcode.'_form_description'] = array(
          '#type' => 'text_format',
          '#title' => t('!name description.', array('!name' => $language_name)) . $lang_default,
          '#default_value' => $content_type_description_field['value'],
          '#format' => $content_type_description_field['format'],
        );
      }
    }
  }

  //Registration descriptions
  $form['user_registration_texts'] = array(
    '#type' => 'fieldset',
    '#title' => t('User registration form descriptions'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  foreach ($languages as $langcode => $language_name) {
    // Retrieve the text info
    $registration_description_field = variable_get('registration_'.$langcode.'_form_description', $defaults);
    $form['user_registration_texts']['registration_'.$langcode.'_form_description'] = array(
      '#type' => 'text_format',
      '#title' => t('!name description', array('!name' => $language_name)),
      '#default_value' => $registration_description_field['value'],
      '#format' => $registration_description_field['format'],
    );
  }

    //Registration descriptions EXPRESS
    $form['express_user_registration_texts'] = array(
      '#type' => 'fieldset',
      '#title' => t('User registration form express consent'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    foreach ($languages as $langcode => $language_name) {
      // Retrieve the text info
      $express_registration_description_field = variable_get('express_registration_'.$langcode.'_form_description', $defaults);
      $form['express_user_registration_texts']['express_registration_'.$langcode.'_form_description'] = array(
        '#type' => 'text_format',
        '#title' => t('!name description', array('!name' => $language_name)),
        '#default_value' => $express_registration_description_field['value'],
        '#format' => $express_registration_description_field['format'],
      );
    }


    //Registration descriptions CONTACTO
    $form['contact_user_registration_texts'] = array(
      '#type' => 'fieldset',
      '#title' => t('ADD CONTACT form express consent'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    foreach ($languages as $langcode => $language_name) {
      // Retrieve the text info
      $contact_registration_description_field = variable_get('contact_registration_'.$langcode.'_form_description', $defaults);
      $form['contact_user_registration_texts']['contact_registration_'.$langcode.'_form_description'] = array(
        '#type' => 'text_format',
        '#title' => t('!name description', array('!name' => $language_name)),
        '#default_value' => $contact_registration_description_field['value'],
        '#format' => $contact_registration_description_field['format'],
      );
    }

    //BOLETÍN descriptions
    $form['boletin_user_registration_texts'] = array(
      '#type' => 'fieldset',
      '#title' => t('ADD BOLETIN form express consent'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    foreach ($languages as $langcode => $language_name) {
      // Retrieve the text info
      $boletin_registration_description_field = variable_get('boletin_registration_'.$langcode.'_form_description', $defaults);
      $form['boletin_user_registration_texts']['boletin_registration_'.$langcode.'_form_description'] = array(
        '#type' => 'text_format',
        '#title' => t('!name description', array('!name' => $language_name)),
        '#default_value' => $boletin_registration_description_field['value'],
        '#format' => $boletin_registration_description_field['format'],
      );
    }

  //Express consent
foreach($node_types as $type => $type_name) {
  if (in_array($type, $enabled_content_types)) {
    // Text for content type
    $form['express_content_type_'.$type] = array(
      '#type' => 'fieldset',
      '#title' => t('Add !name form express consent', array('!name' => $type_name)),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['express_content_type_'.$type][$type.'_express_all_access_form_description'] = array(
      '#type' => 'checkbox',
      '#title' => t('Registered users can see the description'),
      '#description' => t('Administrators, site admins, editors and organizations will see the description'),
      '#default_value' => variable_get($type.'_express_all_access_form_description', 0),
    );
    foreach ($languages as $langcode => $language_name) {
      // Retrieve the default values for 'value' and 'format'
      $express_content_type_description_field = variable_get($type.'_'.$langcode.'_express_form_description', $defaults);
      $lang_default = '';
      if ($langcode == 'es') {
        $lang_default = ' ('. t('Default language') . ')';
      }
      $form['express_content_type_'.$type][$type.'_'.$langcode.'_express_form_description'] = array(
        '#type' => 'text_format',
        '#title' => t('!name description.', array('!name' => $language_name)) . $lang_default,
        '#default_value' => $express_content_type_description_field['value'],
        '#format' => $express_content_type_description_field['format'],
      );
    }
  }
}

  return system_settings_form($form);
}

/**
 * Returns links admin settings form.
 */
function dge_form_links_admin_settings() {
  $types = node_type_get_types();
  $node_types = array();
  foreach ($types as $node_type) {
    $node_types[$node_type->type] = $node_type->name;
  }

  $enabled_content_types = variable_get('dge_send_content_types', ADD_CONTENT_TYPES);

  foreach($node_types as $type => $type_name) {
    if (in_array($type, $enabled_content_types)) {
      $form['dge_form_links_'.$type] = array(
        '#type' => 'fieldset',
        '#title' => t('!name configure button', array('!name' => $type_name))
      );
      $form['dge_form_links_'.$type]['dge_form_links_'.$type.'button_hidden'] = array(
        '#type' => 'checkbox',
        '#title' => t('Display button on the Feed area'),
        '#description' => t('If this checkbox is selected the button will be added to the additional buttons and will be hidden on the block'),
        '#default_value' => variable_get('dge_form_links_'.$type.'button_hidden', 0),
      );
      $form['dge_form_links_'.$type]['dge_form_links_title_'.$type] = array(
        '#type' => 'textfield',
        '#title' => t('Title of the link'),
        '#default_value' => variable_get('dge_form_links_title_'.$type, ''),
        '#description' => t('Text must be in English')
      );
      $form['dge_form_links_'.$type]['dge_form_links_url_'.$type] = array(
        '#type' => 'textfield',
        '#title' => t('Node add URL'),
        '#default_value' => variable_get('dge_form_links_url_'.$type, ''),
        '#description' => t('If the field is empty then the URL will be build using the <a href="@URL">Access configuration</a> value: <strong>"@VALUE"</strong> (RECOMMENDED).',
                          array('@URL' => url('admin/config/dge/access'), '@VALUE' =>  variable_get('dge_access_node_add_redirect_'.$type,''))).
                          '<br/>'.t('Fill it Whitout first slash. Example: informa-sobre/contenido')
      );
    }
  }

  return system_settings_form($form);
}
