<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_translations (datos.gob.es)".
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
 * dgef_translations.features.translations_es.inc
 */

/**
 * Implements hook_translations_es_defaults().
 */
function dgef_translations_translations_es_defaults() {
  $translations = array();
  $translatables = array();
  $translations['es:default']['18481533dcb0416a0a8ac17099a416fe'] = array(
    'source' => 'Image/logo',
    'context' => 'field_instance:app-field_app_image:label',
    'location' => 'localize_fields_ui.module',
    'translation' => 'Imagen/Logo',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Image/logo', array(), array('context' => 'field_instance:app-field_app_image:label'));
  $translations['es:default']['ac863f346e618f9a959b5c95d5d28941'] = array(
    'source' => 'App',
    'context' => '',
    'location' => '/es/admin/config/development/dge_devel',
    'translation' => 'Aplicación',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('App', array(), array('context' => ''));
  return $translations;
}
