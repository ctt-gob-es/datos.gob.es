<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_ckan (datos.gob.es)".
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
 * Implementation of the module settings form.
 */
function dge_ckan_admin_settings() {
  $form = array();

  $form['ckan_host'] = array(
    '#type' => 'textfield',
    '#title' => t("CKAN host"),
    '#description' => t('Example: http://172.22.194.80/api/3/'),
    '#default_value' => variable_get('ckan_host', ''),
  );

  $form['ckan_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t("CKAN API Key"),
    '#default_value' => variable_get('ckan_api_key', ''),
  );

  $form['ckan_url'] = array(
    '#type' => 'textfield',
    '#title' => t("CKAN Public URL"),
    '#description' => t('Example: http://172.22.194.80'),
    '#default_value' => variable_get('ckan_url', ''),
  );

  $form['ckan_pagina_dataset'] = array(
    '#type' => 'textfield',
    '#title' => t("CKAN dataset page"),
    '#description' => t('Example: dataset'),
    '#default_value' => variable_get('ckan_pagina_dataset', ''),
  );

  $vocabulary = taxonomy_get_vocabularies();
  $checklist_vocab_array = array();
  foreach ($vocabulary as $item) {
    $key = $item->vid;
    $value = $item->name;
    $checklist_vocab_array[$key] = $value;
  }

  $form['dge_organization_vocabulary'] = array(
    '#type'             => 'select',
    '#title'            => t('Select organization list'),
    '#position'         => 'left' ,
    '#options'          => $checklist_vocab_array ,
    '#default_value'    => variable_get('dge_organization_vocabulary',2),
  );
  return system_settings_form($form);
}

/**
 * Test page
 */
function dge_ckan_page_test() {
  global $conf;
  libraries_load('dge_ckan_php_client');
  if ($library = libraries_detect('dge_ckan_php_client') && !empty($library['installed'])) {
    drupal_set_message(t('DGE CKAN PHP Client is not installed'),'error');
  }
  $apiUrl = variable_get('ckan_host', '');
  $apiKey = variable_get('ckan_api_key', '');

  $Ckan = new DgeCkanClient($apiUrl, $apiKey, $conf);

  $ckanResults = $Ckan->package_search('organization:irs-gov');
  $ckanResults = json_decode($ckanResults, true);

  $output = '';
  if($ckanResults['success'] == 1) {
    drupal_set_message(t('CKAN Connexion is OK'));
    $output = t('RAW result').': '. print_r($ckanResults,TRUE);

  }
  else {
    drupal_set_message(t('CKAN Connexion error'),'error');

  }
  if(isset($conf['proxy_server']) && $conf['proxy_server'] != '') {
    $output .= '<br />'.t('Proxy server is configurated. IP !ip', array('!ip' => $conf['proxy_server']));
  }
  return $output . '<br />'. t('CKAN example connexion URL').': '.print_r($Ckan->getCurlRequest(),TRUE);

}
