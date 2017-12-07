<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_initiatives (datos.gob.es)".
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
function dge_initiatives_admin_settings() {

  $form['dge_initiative_csv_button_hidden'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hidden button on the block'),
    '#description' => t('If this checkbox is selected the button will be added to the additional buttons and will be hidden on the block'),
    '#default_value' => variable_get('dge_initiative_csv_button_hidden', 0),
  );
  $form['dge_initiative_csv_button_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Button title'),
    '#required' => true,
    '#description' => t('Text must be in English.'),
    '#default_value' => variable_get('dge_initiative_csv_button_title', 'Download initiatives on CSV'),
  );

  return system_settings_form($form);
}
