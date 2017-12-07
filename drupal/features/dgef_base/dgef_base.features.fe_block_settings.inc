<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_base (datos.gob.es)".
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
 * dgef_base.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function dgef_base_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-footer_institutional_banners'] = array(
    'cache' => -1,
    'css_class' => 'dge-entidades',
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'footer_institutional_banners',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => 'footer_post',
        'status' => 1,
        'theme' => 'dge_theme',
        'weight' => -54,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['boxes-dge_social_media_links'] = array(
    'cache' => -2,
    'css_class' => 'dge-social-links',
    'custom' => 0,
    'delta' => 'dge_social_media_links',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'dge_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['boxes-dge_social_media_links_alt'] = array(
    'cache' => -2,
    'css_class' => 'dge-social-links dge-social-links--hightlighted',
    'custom' => 0,
    'delta' => 'dge_social_media_links_alt',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => 'footer_pre',
        'status' => 1,
        'theme' => 'dge_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Síguenos',
    'visibility' => 0,
  );

  $export['boxes-footer_menu'] = array(
    'cache' => -2,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'footer_menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dge_theme',
        'weight' => -1,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['dge_basic-dge-basic-user-info-block'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'dge-basic-user-info-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'dge_basic',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'dge_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['dge_basic-dge-basic-user-login-block'] = array(
    'cache' => 1,
    'css_class' => 'block-user',
    'custom' => 0,
    'delta' => 'dge-basic-user-login-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'dge_basic',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => 'sub_navigation',
        'status' => 1,
        'theme' => 'dge_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['dge_search-dge_search_header_search_block'] = array(
    'cache' => 1,
    'css_class' => 'block-search',
    'custom' => 0,
    'delta' => 'dge_search_header_search_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'dge_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => 'sub_navigation',
        'status' => 1,
        'theme' => 'dge_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['dge_twitter-dge_twitter_block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'dge_twitter_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'dge_twitter',
    'node_types' => array(),
    'pages' => 'node/41',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dge_theme',
        'weight' => -26,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Últimos tweets',
    'visibility' => 1,
  );

  $export['lang_dropdown-language'] = array(
    'cache' => -1,
    'css_class' => 'dge-menu-lang',
    'custom' => 0,
    'delta' => 'language',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'lang_dropdown',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'dge_theme',
        'weight' => -41,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu_block-1'] = array(
    'cache' => -1,
    'css_class' => 'dge-main-menu',
    'custom' => 0,
    'delta' => 1,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'dge_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Navigation',
    'visibility' => 0,
  );

  $export['menu_block-2'] = array(
    'cache' => -1,
    'css_class' => 'dge-submenu',
    'custom' => 0,
    'delta' => 2,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => 'sub_navigation',
        'status' => 1,
        'theme' => 'dge_theme',
        'weight' => -56,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu_block-3'] = array(
    'cache' => -1,
    'css_class' => 'dge-menu dge-menu--webmap',
    'custom' => 0,
    'delta' => 3,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'dge_theme',
        'weight' => -56,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Content Index',
    'visibility' => 0,
  );

  $export['menu_block-4'] = array(
    'cache' => -1,
    'css_class' => 'dge-menu--moreinfo',
    'custom' => 0,
    'delta' => 4,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => 'footer_post',
        'status' => 1,
        'theme' => 'dge_theme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'css_class' => 'block-search',
    'custom' => 0,
    'delta' => 'form',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dge_theme',
        'weight' => -54,
      ),
      'seven' => array(
        'region' => 'dashboard_sidebar',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['simplenews-0'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'simplenews',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dge_theme',
        'weight' => -41,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['social_media_links-social-media-links'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'social-media-links',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'social_media_links',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dge_theme',
        'weight' => -40,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['workbench-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'workbench',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'dge_theme',
        'weight' => -27,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -99,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
