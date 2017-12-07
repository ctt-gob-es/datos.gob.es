<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_data_requests (datos.gob.es)".
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
function dge_data_requests_admin_settings() {
  $form['dge_data_requests_email'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mail to anonymous sender user after publishing request update'),
  );
  $form['dge_data_requests_email']['dge_data_requests_mail_is_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#default_value' => variable_get('dge_data_requests_mail_is_enabled', 1),
  );
  $form['dge_data_requests_email']['dge_data_requests_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_requests_mail_subject',
                       '[datos.gob.es] Tu consulta de disponibilidad de datos ha sido actualizada'),
  );
  $form['dge_data_requests_email']['dge_data_requests_mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_requests_mail_body',
               'Se han realizado cambios en tu consulta de disponibilidad de datos "[node:title]".\nPuedes visualizarlos en el siguiente enlace: [node:url]\n\n\nSaludos cordiales,\n\ndatos.gob.es\nMinisterio de Energía, Turismo y Agenda Digital\n\nMinisterio de Hacienda y Función Pública'),
  );
  $form['dge_data_requests_email']['dge_data_requests_mail_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From (mail)'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_requests_mail_email', variable_get('site_mail')),
  );

  return system_settings_form($form);
}
