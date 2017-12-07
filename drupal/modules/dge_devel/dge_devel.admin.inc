<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_devel (datos.gob.es)".
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
 */

/**
 * Returns admin settings form.
 */
function dge_devel_admin_settings() {
  $form['dge_devel'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Error logging for each severity level.'),
  );

  $form['dge_devel']['dge_devel_debug'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('DGE Watchdog debug enabled'),
    '#description'   => t('If it is enabled then Drupal DGE logs messages marked as debug (severity level WATCHDOG_DEBUG)'),
    '#default_value' => variable_get('dge_devel_debug', FALSE),
  );

  $form['dge_devel']['dge_devel_debug_print'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Print debug screen message'),
    '#description'   => t('Only works if "Watchdog debug enabled" is checked'),
    '#default_value' => variable_get('dge_devel_debug_print', FALSE),
  );
  return system_settings_form($form);
}


function dge_devel_app_import_date() {

  $result = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('type', 'app','=')
    ->condition('language', 'es','=')
    //->range(0,3)
    ->execute();
  
  $nodes_list = array();
  while($record = $result->fetchAssoc()){
    $nodes_list[] = $record['nid'];
  }
  $nodes = node_load_multiple($nodes_list);
  if(function_exists('dpm'))
    dpm($nodes);
  else
    drupal_set_message('Updated nodes:'.print_r($nodes_list, TRUE));

  foreach($nodes as $node) {
    $node->field_app_publish_date[LANGUAGE_NONE][0]['value'] = substr(date('c',$node->created),0,19);
    node_save($node);
  }

  return 'Update '.count($nodes).' nodes';

}