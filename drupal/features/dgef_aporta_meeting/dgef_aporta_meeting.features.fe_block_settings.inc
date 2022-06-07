<?php

/**	 
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
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
 	* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 	* GNU General Public License for more details.
 	* 
 	* You should have received a copy of the GNU General Public License
 	* along with this program. If not, see <http://www.gnu.org/licenses/>.

 	*/


/**
 * @file
 * dgef_aporta_meeting.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function dgef_aporta_meeting_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['current_search-aporta'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'aporta',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dge_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views--exp-aporta_search-panel_pane_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '-exp-aporta_search-panel_pane_1',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dge_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
