<?php
/**
 * @file
 * dgef_layout_panel.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function dgef_layout_panel_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'dge_lists_2cols_1row';
  $layout->admin_title = 'DGE lists 2cols+1row';
  $layout->admin_description = 'DGE layout para 2 columnas, principalmente listados que llevan filtros en la columna izquierda. Añadida 1 row.';
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
          0 => 1,
          1 => 'main-row',
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
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'texto',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 1,
      ),
      'texto' => array(
        'type' => 'region',
        'title' => 'Texto',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $export['dge_lists_2cols_1row'] = $layout;

  return $export;
}
