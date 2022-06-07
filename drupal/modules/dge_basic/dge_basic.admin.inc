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
 * @file
 */

/**
 * Returns admin settings form.
 */
function dge_basic_admin_login() {
  $form['dge_basic_https_login'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Force login to https destination'),
    '#default_value' => variable_get('dge_basic_https_login', FALSE),
  );

  $form['dge_basic_https_base_path'] = array(
    '#type' => 'textfield',
    '#title' => t('HTTPS base path'),
    '#default_value' => variable_get('dge_basic_https_base_path', ''),
  );
  return system_settings_form($form);
}

/**
 * Returns link extra domains.
 */
function dge_basic_link_extra_domains_config_form($form) {
  $domains = variable_get('link_extra_domains', array());
  $values = implode('|',$domains);
  $form['dge_basic_link_extra_domains'] = array(
    '#type' => 'textfield',
    '#title' => t('Link extra domains (required by link module validation)'),
    '#default_value' => $values,
    '#description' => t('Separated by |. Example: eus|barcelona')
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send')
  );
  return $form;
}

function dge_basic_link_extra_domains_config_form_submit($form, &$form_state) {
  $domains =  $form_state['values']['dge_basic_link_extra_domains'];
  $values = explode('|',$domains);
  variable_set('link_extra_domains',$values);
}
