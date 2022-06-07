<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_newsletter (datos.gob.es)".
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
 * Returns admin settings form.
 */
function dge_newsletter_admin_settings()
{
    /*$form['dge_newsletter_email'] = [
        '#type'  => 'fieldset',
        '#title' => t('Sympa Newsletter Email'),
    ];
    $form['dge_newsletter_email']['dge_newsletter_ga_cid'] = [
        '#type'          => 'textfield',
        '#title'         => t('Google Analytics CID'),
        '#required'      => false,
        '#default_value' => variable_get('dge_newsletter_ga_cid', ''),
    ];
    $form['dge_newsletter_email']['dge_newsletter_utm_source'] = [
        '#type'          => 'textfield',
        '#title'         => t('Google Analytics UTM_SOURCE'),
        '#required'      => false,
        '#default_value' => variable_get('dge_newsletter_utm_source', 'newsletter'),
    ];
    $form['dge_newsletter_email']['dge_newsletter_utm_medium'] = [
        '#type'          => 'textfield',
        '#title'         => t('Google Analytics UTM_MEDIUM'),
        '#required'      => false,
        '#default_value' => variable_get('dge_newsletter_utm_medium', 'email'),
    ];
    $form['dge_newsletter_email']['dge_newsletter_unsubscribe_url'] = [
        '#type'          => 'textfield',
        '#title'         => t('Unsubscribe URL'),
        '#required'      => false,
        '#default_value' => variable_get('dge_newsletter_unsubscribe_url', '<front>'),
    ];
    $form['dge_newsletter_sympa'] = [
        '#type'  => 'fieldset',
        '#title' => t('Sympa SMTP settings'),
    ];
    $form['dge_newsletter_sympa']['dge_newsletter_sympa_from'] = [
        '#type'          => 'textfield',
        '#title'         => t('From email'),
        '#required'      => true,
        '#default_value' => variable_get('dge_newsletter_sympa_from'),
    ];
    $form['dge_newsletter_sympa']['dge_newsletter_sympa_email'] = [
        '#type'          => 'textfield',
        '#title'         => t('Send newsletter email'),
        '#required'      => true,
        '#default_value' => variable_get('dge_newsletter_sympa_email'),
    ];
    $form['dge_newsletter_sympa']['dge_newsletter_sympa_mail_box'] = [
        '#type'          => 'textfield',
        '#title'         => t('Registratrion newsletter email'),
        '#required'      => true,
        '#default_value' => variable_get('dge_newsletter_sympa_mail_box'),
    ];
    $form['dge_newsletter_sympa']['dge_newsletter_sympa_alter_mail_headers'] = [
        '#type'          => 'checkbox',
        '#title'         => t('Alter mail headers'),
        '#default_value' => variable_get('dge_newsletter_sympa_alter_mail_headers', 0),
    ];
    $form['dge_newsletter_mail'] = [
        '#type'  => 'fieldset',
        '#title' => t('Sympa Mail settings'),
    ];
    $form['dge_newsletter_mail']['dge_newsletter_sympa_subscription_command'] = [
        '#type'          => 'textfield',
        '#title'         => t('Subscription command'),
        '#description'   => t('Don\'t forget the %email token'),
        '#required'      => true,
        '#default_value' => variable_get('dge_newsletter_sympa_subscription_command', 'QUIET ADD suscriptores %email'),
    ];
    $form['dge_newsletter_mail']['dge_newsletter_sympa_unsubscription_command'] = [
        '#type'          => 'textfield',
        '#title'         => t('Unsubscription command'),
        '#description'   => t('Don\'t forget the %email token'),
        '#required'      => true,
        '#default_value' => variable_get('dge_newsletter_sympa_unsubscription_command', 'QUIET DEL suscriptores %email'),
    ];

    $form['dge_newsletter_send_email'] = [
        '#type'  => 'fieldset',
        '#title' => t('Sympa Newsletter Send settings'),
    ];
    $form['dge_newsletter_send_email']['dge_newsletter_sympa_send_email'] = [
        '#type'          => 'checkbox',
        '#title'         => t('Send newsletter mails with specific Sympa configurations'),
        '#default_value' => variable_get('dge_newsletter_sympa_send_email', 0),
    ];
    $form['dge_newsletter_send_email']['dge_newsletter_sympa_send_mark_as_sent'] = [
        '#type'          => 'checkbox',
        '#title'         => t('Register newsletter as sent after Sympa email'),
        '#default_value' => variable_get('dge_newsletter_sympa_send_mark_as_sent', 0),
    ];*/
    $form['dge_newsletter_sendinblue'] = [
        '#type'  => 'fieldset',
        '#title' => t('Datos de authenticación de SendInBlue'),
    ];
    $form['dge_newsletter_sendinblue']['info'] = [
      '#type'          => 'markup',
      '#title'         => t('SendInBlue List ID'),
      '#required'      => false,
      '#markup'=>'<p></p>'
    ];
    $form['dge_newsletter_sendinblue']['dge_newsletter_sendinblue_api_key'] = [
        '#type'          => 'textfield',
        '#title'         => t('SendInBlue API Key'),
        '#required'      => false,
        '#default_value' => variable_get('dge_newsletter_sendinblue_api_key', ''),
        '#attributes'=>array('style'=>'width:100%')
    ];
    $form['dge_newsletter_sendinblue']['dge_newsletter_sendinblue_list_id'] = [
        '#type'          => 'textfield',
        '#title'         => t('SendInBlue List ID'),
        '#required'      => false,
        '#default_value' => variable_get('dge_newsletter_sendinblue_list_id', ''),

    ];
    $form['dge_newsletter_sendinblue']['dge_newsletter_sendinblue_from'] = [
        '#type'          => 'textfield',
        '#title'         => t('From email'),
        '#default_value' => variable_get('dge_newsletter_sendinblue_from'),
    ];
    $form['dge_newsletter_sendinblue']['dge_newsletter_sendinblue_test_list_id'] = [
      '#type'          => 'textfield',
      '#title'         => t('SendInBlue TEST List ID'),
      '#required'      => false,
      '#default_value' => variable_get('dge_newsletter_sendinblue_test_list_id', ''),
    ];

    $form['dge_newsletter_unsuscribe_mail'] = [
      '#type'  => 'fieldset',
      '#title' => t('Newsletter unsuscribe mail configuration'),
    ];
    $form['dge_newsletter_unsuscribe_mail']['dge_newsletter_unsuscribe_send_email'] = [
      '#type'          => 'textfield',
      '#title'         => t('Send newsletter unsuscribe email (CCO)'),
      '#required'      => true,
      '#default_value' => variable_get('dge_newsletter_unsuscribe_send_email'),
    ];
    $form['dge_newsletter_unsuscribe_mail']['dge_newsletter_unsuscribe_email_subject'] = [
      '#type'          => 'textfield',
      '#title'         => t('Newsletter unsuscribe email subject'),
      '#default_value' => variable_get('dge_newsletter_unsuscribe_email_subject'),
    ];
    $form['dge_newsletter_unsuscribe_mail']['dge_newsletter_unsuscribe_email_content'] = [
      '#type'          => 'textarea',
      '#title'         => t('Newsletter unsuscribe email content'),
      '#required'      => true,
      '#default_value' => variable_get('dge_newsletter_unsuscribe_email_content'),
    ];

    libraries_load('dge_sendinblue_php_client');
    if ($library = libraries_detect('dge_sendinblue_php_client') && !empty($library['installed'])) {
      drupal_set_message(t('DGE SENDINBLUE PHP Client is not installed'),'error');
    }
    if (variable_get('dge_newsletter_sendinblue_api_key') && variable_get('dge_newsletter_sendinblue_list_id') && variable_get('dge_newsletter_sendinblue_test_list_id')) {
        try {
            $client = new  DgeSendInBlueClient(variable_get('dge_newsletter_sendinblue_api_key'), variable_get('dge_newsletter_sendinblue_list_id'));
            $client_test = new  DgeSendInBlueClient(variable_get('dge_newsletter_sendinblue_api_key'), variable_get('dge_newsletter_sendinblue_test_list_id'));

            $form['dge_newsletter_sendinblue']['info']['#markup'] = '<div class="messages status">
                    <div><strong> Conexión exitosa</strong></div>
                    <div><strong>Account:</strong> '.$client->account->getEmail().'</div>
                    <div><strong>Lista de suscriptores:</strong> '.$client->list->getName().'</div>
                    <div><strong>Lista de PRUEBA:</strong> '.$client_test->list->getName().'</div>
             </div>';
        } catch (Exception $e) {
          $form['dge_newsletter_sendinblue']['info']['#markup'] = '<div class="messages error">
          <div>Error de Conexion: <strong>'.$e->getMessage().'</strong></div></div>';
        }
    }
    return system_settings_form($form);
}
