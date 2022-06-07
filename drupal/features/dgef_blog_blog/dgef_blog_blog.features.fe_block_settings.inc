<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_blog_blog (datos.gob.es)".
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
 * dgef_blog_blog.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function dgef_blog_blog_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-boxes_add__i18n'] = array(
    'cache' => -2,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'boxes_add__i18n',
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
        'weight' => -67,
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

  $export['current_search-blog_blog'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'blog_blog',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
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

  $export['current_search-standard'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'standard',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dge_theme',
        'weight' => -57,
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

  $export['dge_comment-dge_comment_block'] = array(
    'cache' => 1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'dge_comment_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'dge_comment',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'dge_theme',
        'weight' => -42,
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

  $export['facetapi-FBGqm6qmwkDP39XH73676k0bJwUfKqCL'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'FBGqm6qmwkDP39XH73676k0bJwUfKqCL',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
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

  $export['facetapi-GFcMYR0Jh5HQrN0zVOkioAXisquUmJFp'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'GFcMYR0Jh5HQrN0zVOkioAXisquUmJFp',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-706b3a2f45104a5dad8dd9636bd39919'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '706b3a2f45104a5dad8dd9636bd39919',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
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

  $export['views-blog_blog_home-block_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'blog_blog_home-block_1',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'dge_theme' => array(
        'region' => '',
        'status' => 0,
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

  return $export;
}
