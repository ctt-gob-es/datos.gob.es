<?php


/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_i18n (datos.gob.es)".
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
function dge_i18n_admin_settings() {
  $form = array();

  $types = node_type_get_types();
  $nodetypes = array();
  foreach ($types as $node_type) {
    $nodetypes[$node_type->type] = $node_type->name;
  }

  $form['dge_i18n_content_types'] = array(
    '#type' => 'select',
    '#multiple' => true,
    '#title' => t("Workflow content types enabled"),
    '#options' => $nodetypes,
    '#description' => t('This content types are enabled for language original flow translations'),
    '#default_value' => variable_get('dge_i18n_content_types',array()),
  );

  $vocs = taxonomy_vocabulary_get_names();
  $vocabularies = array();
  foreach ($vocs as $machine_name => $vocabulary) {
    $vocabularies[$vocabulary->vid] = $vocabulary->name;
  }

  $form['dge_i18n_vocabularies'] = array(
    '#type' => 'select',
    '#multiple' => true,
    '#title' => t("Workflow vocabularies enabled"),
    '#options' => $vocabularies,
    '#description' => t('This vocabularies are enabled for language original flow translations'),
    '#default_value' => variable_get('dge_i18n_vocabularies',array()),
  );

  $menus = menu_get_menus();
  $menu_options = array();
  foreach ($menus as $machine_name => $menu) {
    $menu_options[$machine_name] = $menu;
  }

  $form['dge_i18n_menus'] = array(
    '#type' => 'select',
    '#multiple' => true,
    '#title' => t("Menus with node translation"),
    '#options' => $menu_options,
    '#description' => t('If a menu item links to a node its current language translated node will be displayed'),
    '#default_value' => variable_get('dge_i18n_menus',array()),
  );

  return system_settings_form($form);
}
