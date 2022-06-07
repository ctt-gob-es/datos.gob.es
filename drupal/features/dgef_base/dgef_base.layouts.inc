<?php

/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_base (datos.gob.es)".
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
 * dgef_base.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function dgef_base_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'dge_detail_1col';
  $layout->admin_title = 'DGE Detail 1col';
  $layout->admin_description = 'DGE layout de 1 columna para mostrar el detalle de los contenidos.';
  $layout->category = 'DGE';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'dge-layout dge-layout--detail',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => TRUE,
        'fixed_width' => '',
        'column_separation' => '',
        'region_separation' => '',
        'row_separation' => '',
        'hide_empty' => 1,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => '',
        'hide_empty' => 1,
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
        'class' => 'dge-row row dge-drupal-layout',
        'hide_empty' => 1,
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'DGE Content',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'dge-detail',
        'hide_empty' => 1,
      ),
    ),
  );
  $export['dge_detail_1col'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'dge_home_1col';
  $layout->admin_title = 'DGE home 1col';
  $layout->admin_description = 'DGE layout para la página de inicio';
  $layout->category = 'DGE';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'dge-layout dge-layout--home',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => TRUE,
        'fixed_width' => '',
        'column_separation' => '0',
        'region_separation' => '0',
        'row_separation' => '0',
        'hide_empty' => 1,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
        ),
        'parent' => 'canvas',
        'class' => '',
        'hide_empty' => 1,
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
        'class' => 'dge-row dge-rowhome--sup',
        'hide_empty' => 1,
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'DGE Home Sup',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 1,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'dge_home_mid',
        ),
        'parent' => 'main',
        'class' => 'dge-row dge-rowhome-mid',
        'hide_empty' => 1,
      ),
      'dge_home_mid' => array(
        'type' => 'region',
        'title' => 'DGE Home Mid',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'dge_home_inf',
        ),
        'parent' => 'main',
        'class' => 'dge-row dge-homerow--inf',
        'hide_empty' => 1,
      ),
      'dge_home_inf' => array(
        'type' => 'region',
        'title' => 'DGE Home Inf',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $export['dge_home_1col'] = $layout;

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'dge_lists_2cols';
  $layout->admin_title = 'DGE lists 2cols';
  $layout->admin_description = 'DGE layout para 2 columnas, principalmente listados que llevan filtros en la columna izquierda';
  $layout->category = 'DGE';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => 'dge-layout dge-layout--list',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => TRUE,
        'fixed_width' => '',
        'column_separation' => '',
        'region_separation' => '',
        'row_separation' => '',
        'hide_empty' => 1,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => '',
        'hide_empty' => 1,
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'filters',
          1 => 'center',
        ),
        'parent' => 'main',
        'class' => 'dge-row row wrapper',
        'hide_empty' => 1,
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'DGE Results col',
        'width' => '75.29226787237245',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'dge-results primary',
        'hide_empty' => 1,
      ),
      'filters' => array(
        'type' => 'region',
        'title' => 'DGE Filters',
        'width' => '24.707732127627548',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'dge-filters filters secondary',
        'hide_empty' => 1,
      ),
    ),
  );
  $export['dge_lists_2cols'] = $layout;

  return $export;
}
