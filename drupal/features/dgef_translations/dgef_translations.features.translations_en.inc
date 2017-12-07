<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file
 * dgef_translations.features.translations_en.inc
 */

/**
 * Implements hook_translations_en_defaults().
 */
function dgef_translations_translations_en_defaults() {
  $translations = array();
  $translatables = array();
  $translations['en:blocks']['6b5f6ac4bdf9780962ce96ac86c85c7b'] = array(
    'source' => '<img src="/sites/all/themes/dge_theme/images/test_site/slogan.png">',
    'context' => 'boxes:home_slogan:body',
    'location' => 'blocks:boxes:home_slogan:body',
    'translation' => 'EN BOXES <img src="/sites/all/themes/dge_theme/images/test_site/slogan.png">',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<img src="/sites/all/themes/dge_theme/images/test_site/slogan.png">', array(), array('context' => 'boxes:home_slogan:body'));
  $translations['en:boxes']['d258e0837223b346798e5e4ac3f99df4'] = array(
    'source' => '<img src="/sites/all/themes/dge_theme/images/test_site/slogan.png">',
    'context' => 'i18n:home_slogan:body',
    'location' => 'boxes:i18n:home_slogan:body',
    'translation' => 'EN I18N <img src="/sites/all/themes/dge_theme/images/test_site/slogan.png">',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<img src="/sites/all/themes/dge_theme/images/test_site/slogan.png">', array(), array('context' => 'i18n:home_slogan:body'));
  return $translations;
}
