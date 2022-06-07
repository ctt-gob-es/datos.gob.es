<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_leaflet (datos.gob.es)".
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
 */
function dge_leaflet_drush_command() {
  $items = array();

  // The key in the $items array is the name of the command.
  $items['dl-leaflet'] = array(
    'callback' => 'dge_leaflet_download_plugin',
    'description' => dt('Download and install the Leaflet library.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(
      'path' => dt('Optional. A path where to install the Leaflet library. If omitted Drush will use the default location.'),
    ),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function dge_leaflet_drush_help($section) {
  switch ($section) {
    case 'drush:dl-leaflet':
      return dt('Download and install the Leaflet 0.7.5 library from http://leafletjs.com, default location is sites/all/libraries.');
  }
}

/**
 * Command to download the Leaflet library.
 */
function dge_leaflet_download_plugin() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  $library = libraries_detect('leaflet');

  // Download the archive.
  if ($filepath = drush_download_file($library['download url'])) {
    $filename = basename($filepath);
    $dirname = basename($filepath, '.zip');

    // Remove any existing Openlayers library directory.
    if (is_dir($dirname) || is_dir('leaflet')) {
      drush_delete_dir($dirname, TRUE);
      drush_delete_dir('leaflet', TRUE);
      drush_log(dt('A existing Leaflet library was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the archive.
    drush_tarball_extract($filename);
    drush_move_dir($dirname, 'leaflet', TRUE);
    $dirname = 'leaflet';
  }

  if (is_dir($dirname)) {
    drush_log(dt('Leaflet library has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the Leaflet library to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}
