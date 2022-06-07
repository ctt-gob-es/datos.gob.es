<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_views (datos.gob.es)".
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
 * dgef_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dgef_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'success_home';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'success_home';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Empresas reutilizadoras';
  $handler->display->display_options['css_class'] = 'dge-smallcarousel dge-smallcarousel--home';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'ver más';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'dge-smallcarousel__content';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Campo: Contenido: Imagen/logo */
  $handler->display->display_options['fields']['field_success_image']['id'] = 'field_success_image';
  $handler->display->display_options['fields']['field_success_image']['table'] = 'field_data_field_success_image';
  $handler->display->display_options['fields']['field_success_image']['field'] = 'field_success_image';
  $handler->display->display_options['fields']['field_success_image']['label'] = '';
  $handler->display->display_options['fields']['field_success_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_success_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_success_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_success_image']['settings'] = array(
    'image_style' => 'home_carousel',
    'image_link' => '',
  );
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="dge-smallcarousel__img">[field_success_image]</span>
<strong class="dge-smallcarousel__title"><span>[title]</span></strong>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Sort criterion: Contenido: Fecha de publicación */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Contenido: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'success' => 'success',
  );
  /* Filter criterion: Contenido: Idioma */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Empresas Reutilizadoras */
  $handler = $view->new_display('block', 'Empresas Reutilizadoras', 'block');
  $handler->display->display_options['link_url'] = 'casos-exito';
  $export['success_home'] = $view;

  $view = new view();
  $view->name = 'apps_home';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'apps_home';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Aplicaciones';
  $handler->display->display_options['css_class'] = 'dge-smallcarousel dge-smallcarousel--home';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'ver más';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'dge-smallcarousel__content';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Campo: Contenido: Image/logo */
  $handler->display->display_options['fields']['field_app_image']['id'] = 'field_app_image';
  $handler->display->display_options['fields']['field_app_image']['table'] = 'field_data_field_app_image';
  $handler->display->display_options['fields']['field_app_image']['field'] = 'field_app_image';
  $handler->display->display_options['fields']['field_app_image']['label'] = '';
  $handler->display->display_options['fields']['field_app_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_app_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_app_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_app_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_app_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_image']['empty'] = '<img src="/sites/default/files/app/logo/dge-img-default.jpg" alt="" />';
  $handler->display->display_options['fields']['field_app_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_app_image']['settings'] = array(
    'image_style' => 'home_carousel',
    'image_link' => '',
  );
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="dge-smallcarousel__img">[field_app_image]</span>
<strong class="dge-smallcarousel__title"><span>[title]</span></strong>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Sort criterion: Contenido: Fecha de publicación */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Contenido: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'app' => 'app',
  );
  /* Filter criterion: Contenido: Idioma */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Aplicaciones */
  $handler = $view->new_display('block', 'Aplicaciones', 'block');
  $handler->display->display_options['link_url'] = 'aplicaciones';
  $export['apps_home'] = $view;

  $view = new view();
  $view->name = 'blog_home';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'blog_home';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Actualidad';
  $handler->display->display_options['css_class'] = 'dge-news dge-news--home';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'ver más';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'dge-news__content';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Contenido: Imagen */
  $handler->display->display_options['fields']['field_blog_image']['id'] = 'field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['table'] = 'field_data_field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['field'] = 'field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['label'] = '';
  $handler->display->display_options['fields']['field_blog_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_blog_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_blog_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_blog_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_blog_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blog_image']['settings'] = array(
    'image_style' => 'blog_carousel',
    'image_link' => '',
  );
  /* Campo: Contenido: Imagen */
  $handler->display->display_options['fields']['field_event_image']['id'] = 'field_event_image';
  $handler->display->display_options['fields']['field_event_image']['table'] = 'field_data_field_event_image';
  $handler->display->display_options['fields']['field_event_image']['field'] = 'field_event_image';
  $handler->display->display_options['fields']['field_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_event_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_event_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_event_image']['empty'] = '[field_blog_image]';
  $handler->display->display_options['fields']['field_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_image']['settings'] = array(
    'image_style' => 'blog_carousel',
    'image_link' => '',
  );
  /* Campo: Contenido: Imagen */
  $handler->display->display_options['fields']['field_talk_image']['id'] = 'field_talk_image';
  $handler->display->display_options['fields']['field_talk_image']['table'] = 'field_data_field_talk_image';
  $handler->display->display_options['fields']['field_talk_image']['field'] = 'field_talk_image';
  $handler->display->display_options['fields']['field_talk_image']['label'] = '';
  $handler->display->display_options['fields']['field_talk_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_talk_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_talk_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_talk_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_talk_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_talk_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_talk_image']['empty'] = '[field_event_image]';
  $handler->display->display_options['fields']['field_talk_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_talk_image']['settings'] = array(
    'image_style' => 'blog_carousel',
    'image_link' => '',
  );
  /* Campo: Contenido: Fecha de publicación */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_wrapper_type'] = 'em';
  $handler->display->display_options['fields']['created']['element_wrapper_class'] = 'dge-news__date';
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="dge-news__img">[field_talk_image]</span>
<em class="dge-news__date">[created]</em>
<strong class="dge-news__title">[title]</strong>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Sort criterion: Contenido: Fecha de publicación */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Contenido: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenido: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bulletin' => 'bulletin',
    'talk' => 'talk',
    'event' => 'event',
    'blog' => 'blog',
  );
  /* Filter criterion: Contenido: Idioma */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
  );

  /* Display: Noticias */
  $handler = $view->new_display('block', 'Noticias', 'block_1');
  $handler->display->display_options['link_url'] = 'noticias';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Contenido: Imagen */
  $handler->display->display_options['fields']['field_blog_image']['id'] = 'field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['table'] = 'field_data_field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['field'] = 'field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['label'] = '';
  $handler->display->display_options['fields']['field_blog_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_blog_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_blog_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_blog_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_blog_image']['empty'] = '<img src="/sites/default/files/blog/image/dge-img-default.jpg" alt="" />';
  $handler->display->display_options['fields']['field_blog_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blog_image']['settings'] = array(
    'image_style' => 'blog_carousel',
    'image_link' => '',
  );
  /* Campo: Contenido: Imagen */
  $handler->display->display_options['fields']['field_event_image']['id'] = 'field_event_image';
  $handler->display->display_options['fields']['field_event_image']['table'] = 'field_data_field_event_image';
  $handler->display->display_options['fields']['field_event_image']['field'] = 'field_event_image';
  $handler->display->display_options['fields']['field_event_image']['label'] = '';
  $handler->display->display_options['fields']['field_event_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_event_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_event_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_event_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_event_image']['empty'] = '[field_blog_image]';
  $handler->display->display_options['fields']['field_event_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_event_image']['settings'] = array(
    'image_style' => 'blog_carousel',
    'image_link' => '',
  );
  /* Campo: Contenido: Imagen */
  $handler->display->display_options['fields']['field_talk_image']['id'] = 'field_talk_image';
  $handler->display->display_options['fields']['field_talk_image']['table'] = 'field_data_field_talk_image';
  $handler->display->display_options['fields']['field_talk_image']['field'] = 'field_talk_image';
  $handler->display->display_options['fields']['field_talk_image']['label'] = '';
  $handler->display->display_options['fields']['field_talk_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_talk_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_talk_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_talk_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_talk_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_talk_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_talk_image']['empty'] = '[field_event_image]';
  $handler->display->display_options['fields']['field_talk_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_talk_image']['settings'] = array(
    'image_style' => 'blog_carousel',
    'image_link' => '',
  );
  /* Campo: Contenido: Fecha de publicación */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_wrapper_type'] = 'em';
  $handler->display->display_options['fields']['created']['element_wrapper_class'] = 'dge-news__date';
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="dge-news__img">[field_talk_image]</span>
<em class="dge-news__date">[created]</em>
<strong class="dge-news__title">[title]</strong>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $export['blog_home'] = $view;

  return $export;
}
