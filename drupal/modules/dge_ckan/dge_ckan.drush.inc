<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
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
 	* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 	* GNU General Public License for more details.
 	*
 	* You should have received a copy of the GNU General Public License
 	* along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

define('CKAN_DELETED_DATASET', '[ELIMINADO]');

/**
 * Implementation of hook_drush_command().
 */
function dge_ckan_drush_command() {
    $items = array();
    $items['dataset-comments-update'] = array(
      'callback' => 'dge_ckan_update_dataset_status',
      'description' => 'Drush command to update the status of dataset contens.',
      'aliases' => array('dcu'),
      'examples' => array(
        'Update dataset node status' => 'drush dcu',
      ),
    );
    return $items;
}

/*
 * Callback function for hook_drush_command().
 */
function dge_ckan_update_dataset_status() {
  $ckan = dge_ckan_init_class();

  drush_print('Se obtienen los datasets de ckan');
  $response = $ckan->request(
    'package_list'
  );

  if($response['success']) {
    $datasets = $response['result'];

    // Se obtienen los name registrados
    $query = db_select('field_data_field_ckan_package_name', 'f');
    $query->condition('f.bundle', 'dataset', '=');
    $query->fields('f', array('entity_id', 'field_ckan_package_name_value'));
    $query->execute();
    $result = $query->execute();

    // Se comprueba que los names registrados sean válidos
    $deleted_nodes = array();
    while($record = $result->fetchAssoc()){
      if (! in_array($record['field_ckan_package_name_value'], $datasets)) {
        $deleted_nodes[] = $record['entity_id'];
        drush_log(dt("The dataset with id !node and name !index is alive.", array(
            '!node' => $record['entity_id'],
            '!index' => $record['field_ckan_package_name_value'])
          ), 'ok');
      } else {
        drush_log(dt("The dataset with id !node and name !index is alive.", array(
            '!node' => $record['entity_id'],
            '!index' => $record['field_ckan_package_name_value'])
          ), 'error');
      }
    }
    drush_log(dt("Datasets ready for update: !index .", array(
        '!index' => sizeof($deleted_nodes))
      ));

    $count = 0;
    while (!empty($deleted_nodes)) {
        // Procesar de 10 en 10 por motivos de optimizacion
        $node_ids = array_splice($deleted_nodes, 0, 10);

        // Cargar los 10 nodos
        $nodes = node_load_multiple($node_ids);

        foreach($nodes as $node) {

          if (strpos($node->title, CKAN_DELETED_DATASET) !== 0) {
            // Marcar title como ELIMINADO
            $node->title = set_title_to_eliminated($node->title);
            node_save($node);
            drush_log(dt("Set node !nid as deleted dataset with the new name !node.", array(
                '!nid' => $node->nid,
                '!node' => $node->title)
              ), 'ok');

            $count++;
          } else {
            drush_log(dt("The node !nid was setted as deleted previously: !node.", array(
                '!nid' => $node->nid,
                '!node' => $node->title)
              ), 'ok');
          }
        }
        drush_log(dt("Pending dataset nodes waiting for being processed: !count.", array(
            '!count' => sizeof($deleted_nodes))
          ));
    }

    drush_log(dt("End of execution. Updated nodes: !count.", array(
        '!count' => $count)
      ));
  }
}

/*
 * Generate the note title for deleted datasets.
 */
function set_title_to_eliminated($title) {
    $new_title = CKAN_DELETED_DATASET . ' ' . $title;
    if (strlen($new_title) > 250) {
        $new_title = substr($new_title, 0, 247) . '...';
    }
    return $new_title;
}
