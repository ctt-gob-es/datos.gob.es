<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * Returns admin settings form.
 */
function dge_newsletter_admin_settings() {

  $form['dge_newsletter_sympa'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sympa SMTP settings'),
  );
  $form['dge_newsletter_sympa']['dge_newsletter_sympa_distribution_list'] = array(
    '#type' => 'textfield',
    '#title' => t('Distribution list'),
    '#required' => true,
    '#default_value' => variable_get('dge_newsletter_sympa_distribution_list'),
  );
  $form['dge_newsletter_sympa']['dge_newsletter_sympa_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Sympa Email'),
    '#required' => true,
    '#default_value' => variable_get('dge_newsletter_sympa_email'),
  );
  $form['dge_newsletter_sympa']['dge_newsletter_sympa_mail_box'] = array(
    '#type' => 'textfield',
    '#title' => t('Mail box'),
    '#required' => true,
    '#default_value' => variable_get('dge_newsletter_sympa_mail_box'),
  );
  $form['dge_newsletter_sympa']['dge_newsletter_sympa_alter_mail_headers'] = array(
    '#type' => 'checkbox',
    '#title' => t('Alter mail headers'),
    '#default_value' => variable_get('dge_newsletter_sympa_alter_mail_headers', 0),
  );
  $form['dge_newsletter_mail'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sympa Mail settings'),
  );
  $form['dge_newsletter_mail']['dge_newsletter_sympa_subscription_command'] = array(
    '#type' => 'textfield',
    '#title' => t('Subscription command'),
    '#description' => t('Don\'t forget the %email token'),
    '#required' => true,
    '#default_value' => variable_get('dge_newsletter_sympa_subscription_command', 'QUIET ADD suscriptores %email'),
  );
  $form['dge_newsletter_mail']['dge_newsletter_sympa_unsubscription_command'] = array(
    '#type' => 'textfield',
    '#title' => t('Unsubscription command'),
    '#description' => t('Don\'t forget the %email token'),
    '#required' => true,
    '#default_value' => variable_get('dge_newsletter_sympa_unsubscription_command', 'QUIET DEL suscriptores %email'),
  );

  return system_settings_form($form);
}
