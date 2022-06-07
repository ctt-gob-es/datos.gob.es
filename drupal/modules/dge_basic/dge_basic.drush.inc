<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_basic (datos.gob.es)".
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
 * Implements hook_drush_command().
 *
 * @see drush_parse_command() for a list of recognized keys.
 *
 * @return
 *   An associative array describing our command.
 */
function dge_basic_drush_command(){
  $items = array();

  $items['dge-load-translation'] = array(
    'callback' => 'dge_basic_drush_load_translation',
    'description' => "Reload translations.",
    'arguments'   => array(),
    'examples'    => array(
      'drush dgelt' => 'Reload translations from sites/all/modules/custom/dge_basic/translations',
    ),
    'aliases'     => array('dgelt'),
    'topic'       => TRUE,
    'bootstrap'   => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['dge-delete-vocab-terms'] = array(
    'callback' => 'dge_basic_drush_delete_vocab_terms',
    'description' => "Delete all terms of vocab.",
    'arguments'   => array('vid'),
    'examples'    => array(
      'drush dge-delete-all-terms 3' => 'Delete all terms for vocabulary 3',
    ),
    'topic'       => TRUE,
    'bootstrap'   => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items['dge-show-vocab-terms'] = array(
    'callback' => 'dge_basic_drush_show_vocab_terms',
    'description' => "Show all terms of vocab.",
    'arguments'   => array('vid'),
    'examples'    => array(
      'drush dge-show-all-terms 3' => 'Delete all terms for vocabulary 3',
    ),
    'topic'       => TRUE,
    'bootstrap'   => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Drush command callback for dge-load-translation (dgelt).
 */
function dge_basic_drush_load_translation() {

  drush_print('Updating language translations.');

  $po_files = array(
    //'es.po' => 'default',
    'fields-en.po' => 'field',
  );

  foreach($po_files as $filename => $group) {
    drush_print("* Processing $filename ...");

    $file = new stdClass();
    $file->filename = $filename;
    $file->uri = drupal_get_path('module', 'dge_basic') . '/translations/' . $filename;
    $file->filemime = 'application/octet-stream';

    $success = _locale_import_po($file, 'en', LOCALE_IMPORT_OVERWRITE, $group);

    if ($success) {
      drush_print('OK');
    }
    else {
      drush_print('FAIL');
    }
  }
}

/**
 * Drush command callback delete all vocab terms.
 */
function dge_basic_drush_delete_vocab_terms($vid) {
  $terms = taxonomy_get_tree((int) $vid);
  foreach ($terms as $t) {
    taxonomy_term_delete($t->tid);
    drush_print('Deleted '.$t->name);
  }
}

function dge_basic_drush_show_vocab_terms($vid) {
  $terms = taxonomy_get_tree((int) $vid);
  foreach ($terms as $t) {
    drush_print($t->name);
  }
}
