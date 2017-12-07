<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_twitter (datos.gob.es)".
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
function dge_twitter_admin_settings() {
  $form['dge_twitter'] = array(
    '#markup' => t('See DGE Twitter Block in blocks page.'),
  );

  $form['dge_twitter_oauth'] = array(
    '#type' => 'fieldset',
    '#title' => t('OAuth settings'),
  );
  $form['dge_twitter_oauth']['dge_twitter_block_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer key'),
    '#required' => true,
    '#default_value' => variable_get('dge_twitter_block_consumer_key'),
  );
  $form['dge_twitter_oauth']['dge_twitter_block_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer secret'),
    '#required' => true,
    '#default_value' => variable_get('dge_twitter_block_consumer_secret'),
  );
  $form['dge_twitter_oauth']['dge_twitter_block_access_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Access token'),
    '#required' => true,
    '#default_value' => variable_get('dge_twitter_block_access_token'),
  );
  $form['dge_twitter_oauth']['dge_twitter_block_access_token_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Access token secret'),
    '#required' => true,
    '#default_value' => variable_get('dge_twitter_block_access_token_secret'),
  );

  $form['dge_twitter_block'] = array(
    '#type' => 'fieldset',
    '#title' => t('Block configuration'),
  );
  $form['dge_twitter_block']['dge_twitter_block_screen_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter account'),
    '#required' => true,
    '#default_value' => variable_get('dge_twitter_block_screen_name'),
  );
  $form['dge_twitter_block']['dge_twitter_block_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of tweets'),
    '#required' => true,
    '#default_value' => variable_get('dge_twitter_block_count', 9),
  );
  $form['dge_twitter_block']['dge_twitter_block_avatar'] = array(
    '#type' => 'select',
    '#title' => t('Show avatar'),
    '#options' => array('none' => 'None', 'profile' => 'Profile image', 'icon' => 'Twitter icon'),
    '#default_value' => variable_get('dge_twitter_block_avatar', 'none'),
  );

  $form['dge_twitter_ajax'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced configuration'),
  );
  $form['dge_twitter_ajax']['dge_twitter_block_ajax'] = array(
    '#type' => 'checkbox',
    '#title' => t('Retrieve tweets with ajax'),
    '#default_value' => variable_get('dge_twitter_block_ajax', 0),
  );
  $form['dge_twitter_ajax']['dge_twitter_block_cache'] = array(
    '#type' => 'textfield',
    '#title' => t('Cache time'),
    '#required' => false,
    '#default_value' => variable_get('dge_twitter_block_cache', 60),
    '#description' => 'Note: 60 for 1 minute',
  );

  return system_settings_form($form);
}
