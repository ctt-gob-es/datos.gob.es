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

  /* FORM 0 - Mail to anonymous sender user after publishing request update *************************** */
  $form['dge_data_requests_email'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mail to anonymous sender user after publishing request update'),
  );
  $form['dge_data_requests_email']['dge_data_requests_mail_is_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#default_value' => variable_get('dge_data_requests_mail_is_enabled', 0),
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
               "Se han realizado cambios en tu consulta de disponibilidad de datos \"[node:title]\".\nPuedes visualizarlos en el siguiente enlace: [node:url]\n\n\nSaludos cordiales,\n\ndatos.gob.es\nMinisterio de Energía, Turismo y Agenda Digital\n\nMinisterio de Hacienda y Función Pública"),
  );
  $form['dge_data_requests_email']['dge_data_requests_mail_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From (mail)'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_requests_mail_email', variable_get('site_mail')),
  );

  /* FORM 1 - CORREO PARA ORGANISMO TRAS SUSCRIPCIÓN *************************** */
  $form['dge_data_subscription_email'] = array(
    '#type' => 'fieldset',
    '#title' => t('CORREO PARA ORGANISMO TRAS SUSCRIPCIÓN'),
  );
  $form['dge_data_subscription_email']['dge_data_subscription_mail_is_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#default_value' => variable_get('dge_data_subscription_mail_is_enabled', 0),
  );
  $form['dge_data_subscription_email']['dge_data_subscription_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#required' => true,
    '#description' => t('Avalilable tokens: [node:title], [node:url], [subscriptor:name], [subscriptor:email], [subscriptor:organization]'),
    '#default_value' => variable_get('dge_data_subscription_mail_subject',
                       '[datos.gob.es] Nueva suscripción'),
  );
  $form['dge_data_subscription_email']['dge_data_subscription_mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#required' => true,
    '#description' => t('Avalilable tokens: [node:title], [node:url], [subscriptor:name], [subscriptor:email], [subscriptor:organization]'),
    '#default_value' => variable_get('dge_data_subscription_mail_body',
               "Se ha realizado una suscripción a \"[node:title]\".\nPuedes visualizarlos en el siguiente enlace: [node:url]\n\nSaludos cordiales,\n\ndatos.gob.es\nMinisterio de Energía, Turismo y Agenda Digital\n\nMinisterio de Hacienda y Función Pública"),
  );
  $form['dge_data_subscription_email']['dge_data_subscription_mail_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From (mail)'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_subscription_mail_email', variable_get('site_mail')),
  );

  /* FORM 2 - Correo para suscriptiores tras comentario publicado *************************** */
  $form['dge_data_requests_comment_email'] = array(
    '#type' => 'fieldset',
    '#title' => t('Correo para suscriptiores tras comentario publicado'),
  );
  $form['dge_data_requests_comment_email']['dge_data_requests_comment_mail_is_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#default_value' => variable_get('dge_data_requests_comment_mail_is_enabled', 0),
  );
  $form['dge_data_requests_comment_email']['dge_data_requests_comment_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_requests_comment_mail_subject',
                       '[datos.gob.es] La disponibilidad de datos a la que estas suscrito ha recibido un nuevo comentario'),
  );
  $form['dge_data_requests_comment_email']['dge_data_requests_comment_mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_requests_comment_mail_body',
               "Se han realizado comentarios en la disponibilidad de datos \"[node:title]\".\nPuedes visualizarlos en el siguiente enlace: [node:url]\n\nSaludos cordiales,\n\ndatos.gob.es\nMinisterio de Energía, Turismo y Agenda Digital\n\nMinisterio de Hacienda y Función Pública"),
  );
  $form['dge_data_requests_comment_email']['dge_data_requests_comment_mail_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From (mail)'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_requests_comment_mail_email', variable_get('site_mail')),
  );

  /* FORM 3 - Correo tras respuesta a petición de datos *************************** */
  $form['dge_data_requests_response_email'] = array(
    '#type' => 'fieldset',
    '#title' => t('Correo tras respuesta a petición de datos'),
  );
  $form['dge_data_requests_response_email']['dge_data_requests_response_mail_is_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#default_value' => variable_get('dge_data_requests_response_mail_is_enabled', 0),
  );
  $form['dge_data_requests_response_email']['dge_data_requests_response_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#required' => true,
    '#description' => t('Avalilable tokens: [node:title], [node:url], [subscriptor:name], [subscriptor:email], [subscriptor:organization]'),
    '#default_value' => variable_get('dge_data_requests_response_mail_subject',
                       '[datos.gob.es] La disponibilidad de datos a la que estas suscrito ha recibido una respuesta a petición de datos'),
  );
  $form['dge_data_requests_response_email']['dge_data_requests_response_mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#required' => true,
    '#description' => t('Avalilable tokens: [node:title], [node:url], [subscriptor:name], [subscriptor:email], [subscriptor:organization]'),
    '#default_value' => variable_get('dge_data_requests_response_mail_body',
               "Se ha realizado una respuesta en la disponibilidad de datos \"[node:title]\".\nPuedes visualizarlos en el siguiente enlace: [node:url]\n\nSaludos cordiales,\n\ndatos.gob.es\nMinisterio de Energía, Turismo y Agenda Digital\n\nMinisterio de Hacienda y Función Pública"),
  );
  $form['dge_data_requests_response_email']['dge_data_requests_response_mail_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From (mail)'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_requests_response_mail_email', variable_get('site_mail')),
  );

  /* FORM 4 - Correo para suscriptiores tras modificación de petición de datos *************************** */
  $form['dge_data_requests_modification_email'] = array(
    '#type' => 'fieldset',
    '#title' => t('Correo para suscriptiores tras modificación de petición de datos'),
  );
  $form['dge_data_requests_modification_email']['dge_data_requests_modification_mail_is_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#default_value' => variable_get('dge_data_requests_modification_mail_is_enabled', 0),
  );
  $form['dge_data_requests_modification_email']['dge_data_requests_modification_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#required' => true,
    '#description' => t('Avalilable tokens: [node:title], [node:url], [subscriptor:name], [subscriptor:email], [subscriptor:organization]'),
    '#default_value' => variable_get('dge_data_requests_modification_mail_subject',
                       '[datos.gob.es] La disponibilidad de datos a la que estas suscrito se ha modificado'),
  );
  $form['dge_data_requests_modification_email']['dge_data_requests_modification_mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#required' => true,
    '#description' => t('Avalilable tokens: [node:title], [node:url], [subscriptor:name], [subscriptor:email], [subscriptor:organization]'),
    '#default_value' => variable_get('dge_data_requests_modification_mail_body',
               "Se ha modificado la disponibilidad de datos \"[node:title]\".\nPuedes visualizarlos en el siguiente enlace: [node:url]\n\nSaludos cordiales,\n\ndatos.gob.es\nMinisterio de Energía, Turismo y Agenda Digital\n\nMinisterio de Hacienda y Función Pública"),
  );
  $form['dge_data_requests_modification_email']['dge_data_requests_modification_mail_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From (mail)'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_requests_modification_mail_email', variable_get('site_mail')),
  );

  /* FORM 5 - Correo para organismos tras asignarles una petición de datos *************************** */
  $form['dge_data_requests_assigned_org_mail'] = array(
    '#type' => 'fieldset',
    '#title' => t('Correo para organismos tras asignarles una petición de datos'),
  );
  $form['dge_data_requests_assigned_org_mail']['dge_data_requests_assigned_org_mail_is_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#default_value' => variable_get('dge_data_requests_assigned_org_mail_is_enabled', 0),
  );
  $form['dge_data_requests_assigned_org_mail']['dge_data_requests_assigned_org_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#required' => true,
    '#description' => t('Avalilable tokens: [node:title], [node:url]'),
    '#default_value' => variable_get('dge_data_requests_assigned_org_mail_subject',
                       '[datos.gob.es] Disponibilidad de datos asignada a su organismo'),
  );
  $form['dge_data_requests_assigned_org_mail']['dge_data_requests_assigned_org_mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#required' => true,
    '#description' => t('Avalilable tokens: [node:title], [node:url]'),
    '#default_value' => variable_get('dge_data_requests_assigned_org_mail_body', "Estimado:\n\nSe le ha asignado una consulta de disponibilidad de datos recibida en la plataforma datos.gob.es. El título es \"[node:title]\" y puedes acceder a ella a través de la URL [node:url]\n\n" .
      "Para contestar al usuario se debe entrar en el portal con tu usuario y editar la consulta incluyendo una Respuesta y actualizando el Estado en el que se encuentra la gestión de dicha consulta. Tiene todo el detalle de cómo realizar la gestión de estas consultas en el apartado 8 de la “Guía para organismos públicos” disponible en datos.gob.es: https://datos.gob.es/es/documentacion/guias-de-datosgobes \n\n" .
      "Si necesita alguna aclaración o le quedan dudas, puede contactarnos a través del buzón de soporte soporte@datos.gob.es o llamando al número de teléfono 912 127 620 ext. 4422.\n\nSaludos cordiales,\n\n" .
      "datos.gob.es\nEntidad pública Red.es\nMinisterio de Asuntos Económicos y Transformación Digital\n"),
  );
  $form['dge_data_requests_assigned_org_mail']['dge_data_requests_assigned_org_mail_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From (mail)'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_requests_assigned_org_mail_email', variable_get('site_mail')),
  );

  /* FORM 6 - Correo para organismos tras la publicación de una petición de datos *************************** */
  $form['dge_data_requests_published_org_mail'] = array(
    '#type' => 'fieldset',
    '#title' => t('Correo para organismos tras la publicación de una petición de datos'),
  );
  $form['dge_data_requests_published_org_mail']['dge_data_requests_published_org_mail_is_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#default_value' => variable_get('dge_data_requests_published_org_mail_is_enabled', 0),
  );
  $form['dge_data_requests_published_org_mail']['dge_data_requests_published_org_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#required' => true,
    '#description' => t('Avalilable tokens: [node:title], [node:url], [subscriptor:name], [subscriptor:email], [subscriptor:organization]'),
    '#default_value' => variable_get('dge_data_requests_published_org_mail_subject',
                       '[datos.gob.es] La disponibilidad de datos asignada a tu organismo se ha publicado'),
  );
  $form['dge_data_requests_published_org_mail']['dge_data_requests_published_org_mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#required' => true,
    '#description' => t('Avalilable tokens: [node:title], [node:url], [subscriptor:name], [subscriptor:email], [subscriptor:organization]'),
    '#default_value' => variable_get('dge_data_requests_published_org_mail_body',
               "Se ha publicado la disponibilidad de datos \"[node:title]\" que está asignada a tu organismo.\nPuedes visualizarlos en el siguiente enlace: [node:url]\n\nSaludos cordiales,\n\ndatos.gob.es\nEntidad pública Red.es\nMinisterio de Asuntos Económicos y Transformación Digital"),
  );
  $form['dge_data_requests_published_org_mail']['dge_data_requests_published_org_mail_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From (mail)'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_requests_published_org_mail_email', variable_get('site_mail')),
  );

  /* FORM 7 - Correo para usuarios tras desunirse de una petición de datos *************************** */
  $form['dge_data_requests_leave_mail'] = array(
    '#type' => 'fieldset',
    '#title' => t('Correo para usuarios tras desunirse de una petición de datos'),
  );
  $form['dge_data_requests_leave_mail']['dge_data_requests_leave_mail_is_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#default_value' => variable_get('dge_data_requests_leave_mail_is_enabled', 0),
  );
  $form['dge_data_requests_leave_mail']['dge_data_requests_leave_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#required' => true,
    '#description' => t('Avalilable tokens: [node:title], [node:url], [subscriptor:name], [subscriptor:email], [subscriptor:organization]'),
    '#default_value' => variable_get('dge_data_requests_leave_mail_subject',
                       '[datos.gob.es] Te has desunido de la disponibilidad de datos [node:title]'),
  );
  $form['dge_data_requests_leave_mail']['dge_data_requests_leave_mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#required' => true,
    '#description' => t('Avalilable tokens: [node:title], [node:url], [subscriptor:name], [subscriptor:email], [subscriptor:organization]'),
    '#default_value' => variable_get('dge_data_requests_leave_mail_body',
               "Te has desunido correctamente de la la disponibilidad de datos \"[node:title]\" que se encuentra en la URL [node:url].\n\nSaludos cordiales,\n\ndatos.gob.es\nEntidad pública Red.es\nMinisterio de Asuntos Económicos y Transformación Digital"),
  );
  $form['dge_data_requests_leave_mail']['dge_data_requests_leave_mail_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From (mail)'),
    '#required' => true,
    '#default_value' => variable_get('dge_data_requests_leave_mail_email', variable_get('site_mail')),
  );

  return system_settings_form($form);
}
