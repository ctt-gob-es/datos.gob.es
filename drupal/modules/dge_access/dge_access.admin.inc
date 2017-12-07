<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_access (datos.gob.es)".
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
 * Returns admin settings form.
 */
function dge_access_admin_settings() {

  $types = node_type_get_types();
  $nodetypes = array();
  foreach ($types as $node_type) {
    $nodetypes[$node_type->type] = $node_type->name;
  }

  $form['dge_access_content_types'] = array(
    '#type' => 'select',
    '#multiple' => true,
    '#title' => t('Control organization access by node type'),
    '#options' => $nodetypes,
    '#description' => t('This content types are enabled for organization access control'),
    '#default_value' => variable_get('dge_access_content_types',array('app')),
  );

  $form['dge_access_redirect'] = array(
    '#type' => 'fieldset',
    '#title' => t('Redirect node add form'),
    '#description' => t('Fill it Whitout first slash. Example: informa-sobre/aplicaciones')
  );

  foreach($nodetypes as $type => $type_name) {
    $form['dge_access_redirect']['dge_access_node_add_redirect_'.$type] = array(
      '#type' => 'textfield',
      '#title' => t('!name node add url for anonymous user', array('!name' => $type_name)),
      '#default_value' => variable_get('dge_access_node_add_redirect_'.$type,''),
    );
  }

  return system_settings_form($form);
}