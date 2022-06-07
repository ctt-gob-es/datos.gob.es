<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_desafio_aporta (datos.gob.es)".
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
 * dgef_desafio_aporta.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dgef_desafio_aporta_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'challenge_aporta_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_challenge_index';
  $view->human_name = 'Desafío Aporta';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'dge-list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todo -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primero';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'dge-list__elm';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'dge-list__lst';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Campo: Indexed Contenido: Imagen */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_challenge_index';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'aporta_image_list',
    'image_link' => '',
  );
  /* Campo: Indexed Contenido: Title #2 */
  $handler->display->display_options['fields']['title2']['id'] = 'title2';
  $handler->display->display_options['fields']['title2']['table'] = 'search_api_index_challenge_index';
  $handler->display->display_options['fields']['title2']['field'] = 'title2';
  $handler->display->display_options['fields']['title2']['label'] = '';
  $handler->display->display_options['fields']['title2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title2']['link_to_entity'] = 0;
  /* Campo: Indexed Contenido: Subtítulo */
  $handler->display->display_options['fields']['field_aporta_subtitle']['id'] = 'field_aporta_subtitle';
  $handler->display->display_options['fields']['field_aporta_subtitle']['table'] = 'search_api_index_challenge_index';
  $handler->display->display_options['fields']['field_aporta_subtitle']['field'] = 'field_aporta_subtitle';
  $handler->display->display_options['fields']['field_aporta_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['text'] = '[title2] : [field_aporta_subtitle]';
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['path'] = 'desafios-aporta/[title2]';
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_aporta_subtitle']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_aporta_subtitle']['element_class'] = 'dge-list__subtitle';
  $handler->display->display_options['fields']['field_aporta_subtitle']['element_label_colon'] = FALSE;
  /* Campo: Indexed Contenido: Fecha */
  $handler->display->display_options['fields']['field_aporta_date']['id'] = 'field_aporta_date';
  $handler->display->display_options['fields']['field_aporta_date']['table'] = 'search_api_index_challenge_index';
  $handler->display->display_options['fields']['field_aporta_date']['field'] = 'field_aporta_date';
  $handler->display->display_options['fields']['field_aporta_date']['label'] = '';
  $handler->display->display_options['fields']['field_aporta_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aporta_date']['settings'] = array(
    'format_type' => 'aporta_date_new',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Campo: Indexed Contenido: Colaborador */
  $handler->display->display_options['fields']['field_collaborator']['id'] = 'field_collaborator';
  $handler->display->display_options['fields']['field_collaborator']['table'] = 'search_api_index_challenge_index';
  $handler->display->display_options['fields']['field_collaborator']['field'] = 'field_collaborator';
  $handler->display->display_options['fields']['field_collaborator']['label'] = '';
  $handler->display->display_options['fields']['field_collaborator']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_collaborator']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_collaborator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_collaborator']['element_wrapper_type'] = 'p';
  /* Campo: Indexed Contenido: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_challenge_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '255';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Indexed Contenido: Fecha */
  $handler->display->display_options['sorts']['field_aporta_date']['id'] = 'field_aporta_date';
  $handler->display->display_options['sorts']['field_aporta_date']['table'] = 'search_api_index_challenge_index';
  $handler->display->display_options['sorts']['field_aporta_date']['field'] = 'field_aporta_date';
  $handler->display->display_options['sorts']['field_aporta_date']['order'] = 'DESC';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'desafio-aporta-prueba';
  $export['challenge_aporta_view'] = $view;

  $view = new view();
  $view->name = 'global_aporta';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_aporta_global';
  $view->human_name = 'Global Aporta';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Global Aporta';
  $handler->display->display_options['css_class'] = 'dge-list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todo -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primero';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'dge-list__elm';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'dge-list__lst';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Indexed Contenido: Imagen */
  $handler->display->display_options['fields']['field_aporta_image_1']['id'] = 'field_aporta_image_1';
  $handler->display->display_options['fields']['field_aporta_image_1']['table'] = 'search_api_index_aporta_global';
  $handler->display->display_options['fields']['field_aporta_image_1']['field'] = 'field_aporta_image';
  $handler->display->display_options['fields']['field_aporta_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_aporta_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aporta_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_aporta_image_1']['settings'] = array(
    'image_style' => 'aporta_image_list',
    'image_link' => '',
  );
  /* Campo: Indexed Contenido: Title #2 */
  $handler->display->display_options['fields']['title2']['id'] = 'title2';
  $handler->display->display_options['fields']['title2']['table'] = 'search_api_index_aporta_global';
  $handler->display->display_options['fields']['title2']['field'] = 'title2';
  $handler->display->display_options['fields']['title2']['label'] = '';
  $handler->display->display_options['fields']['title2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title2']['link_to_entity'] = 0;
  /* Campo: Indexed Contenido: Subtítulo */
  $handler->display->display_options['fields']['field_aporta_subtitle']['id'] = 'field_aporta_subtitle';
  $handler->display->display_options['fields']['field_aporta_subtitle']['table'] = 'search_api_index_aporta_global';
  $handler->display->display_options['fields']['field_aporta_subtitle']['field'] = 'field_aporta_subtitle';
  $handler->display->display_options['fields']['field_aporta_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['text'] = '[title2] : [field_aporta_subtitle]';
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['path'] = 'encuentros-aporta/[title2]';
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_aporta_subtitle']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_aporta_subtitle']['element_class'] = 'dge-list__subtitle';
  $handler->display->display_options['fields']['field_aporta_subtitle']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_aporta_subtitle']['element_label_colon'] = FALSE;
  /* Campo: Indexed Contenido: Fecha */
  $handler->display->display_options['fields']['field_aporta_date']['id'] = 'field_aporta_date';
  $handler->display->display_options['fields']['field_aporta_date']['table'] = 'search_api_index_aporta_global';
  $handler->display->display_options['fields']['field_aporta_date']['field'] = 'field_aporta_date';
  $handler->display->display_options['fields']['field_aporta_date']['label'] = '';
  $handler->display->display_options['fields']['field_aporta_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aporta_date']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_aporta_date']['element_wrapper_class'] = 'dge-list__date';
  $handler->display->display_options['fields']['field_aporta_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_aporta_date']['settings'] = array(
    'format_type' => 'aporta_date_new',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Campo: Indexed Contenido: Colaborador */
  $handler->display->display_options['fields']['field_collaborator']['id'] = 'field_collaborator';
  $handler->display->display_options['fields']['field_collaborator']['table'] = 'search_api_index_aporta_global';
  $handler->display->display_options['fields']['field_collaborator']['field'] = 'field_collaborator';
  $handler->display->display_options['fields']['field_collaborator']['label'] = '';
  $handler->display->display_options['fields']['field_collaborator']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_collaborator']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_collaborator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_collaborator']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_collaborator']['element_default_classes'] = FALSE;
  /* Campo: Indexed Contenido: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_aporta_global';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '255';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Indexed Contenido: ID del nodo */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'search_api_index_aporta_global';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';
  /* Filter criterion: Indexed Contenido: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_aporta_global';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'global-aporta';
  $export['global_aporta'] = $view;

  $view = new view();
  $view->name = 'view_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Vista Bloque';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Prueba';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'carousel_view';
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
    'carousel' => 'carousel',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['view_block'] = $view;

  $view = new view();
  $view->name = 'winners_aporta_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_winners_aporta_index';
  $view->human_name = 'Premios Aporta search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'dge-list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todo -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primero';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'dge-list__elm';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'dge-list__lst';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Indexed Contenido: Imagen */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_winners_aporta_index';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'aporta_image_list',
    'image_link' => '',
  );
  /* Campo: Indexed Contenido: Title #2 */
  $handler->display->display_options['fields']['title2']['id'] = 'title2';
  $handler->display->display_options['fields']['title2']['table'] = 'search_api_index_winners_aporta_index';
  $handler->display->display_options['fields']['title2']['field'] = 'title2';
  $handler->display->display_options['fields']['title2']['label'] = '';
  $handler->display->display_options['fields']['title2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title2']['link_to_entity'] = 0;
  /* Campo: Indexed Contenido: Subtítulo */
  $handler->display->display_options['fields']['field_aporta_subtitle']['id'] = 'field_aporta_subtitle';
  $handler->display->display_options['fields']['field_aporta_subtitle']['table'] = 'search_api_index_winners_aporta_index';
  $handler->display->display_options['fields']['field_aporta_subtitle']['field'] = 'field_aporta_subtitle';
  $handler->display->display_options['fields']['field_aporta_subtitle']['label'] = '';
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['text'] = '[title2] : [field_aporta_subtitle]';
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['path'] = 'premios-aporta/[title2]';
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_aporta_subtitle']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_aporta_subtitle']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_aporta_subtitle']['element_class'] = 'dge-list__subtitle';
  $handler->display->display_options['fields']['field_aporta_subtitle']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_aporta_subtitle']['element_label_colon'] = FALSE;
  /* Campo: Indexed Contenido: Fecha */
  $handler->display->display_options['fields']['field_aporta_date']['id'] = 'field_aporta_date';
  $handler->display->display_options['fields']['field_aporta_date']['table'] = 'search_api_index_winners_aporta_index';
  $handler->display->display_options['fields']['field_aporta_date']['field'] = 'field_aporta_date';
  $handler->display->display_options['fields']['field_aporta_date']['label'] = '';
  $handler->display->display_options['fields']['field_aporta_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aporta_date']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_aporta_date']['element_wrapper_class'] = 'dge-list__date';
  $handler->display->display_options['fields']['field_aporta_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_aporta_date']['settings'] = array(
    'format_type' => 'aporta_date_new',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Campo: Indexed Contenido: Colaborador */
  $handler->display->display_options['fields']['field_collaborator']['id'] = 'field_collaborator';
  $handler->display->display_options['fields']['field_collaborator']['table'] = 'search_api_index_winners_aporta_index';
  $handler->display->display_options['fields']['field_collaborator']['field'] = 'field_collaborator';
  $handler->display->display_options['fields']['field_collaborator']['label'] = '';
  $handler->display->display_options['fields']['field_collaborator']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_collaborator']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_collaborator']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_collaborator']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_collaborator']['element_default_classes'] = FALSE;
  /* Campo: Indexed Contenido: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_winners_aporta_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '255';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Indexed Contenido: Fecha */
  $handler->display->display_options['sorts']['field_aporta_date']['id'] = 'field_aporta_date';
  $handler->display->display_options['sorts']['field_aporta_date']['table'] = 'search_api_index_winners_aporta_index';
  $handler->display->display_options['sorts']['field_aporta_date']['field'] = 'field_aporta_date';
  $handler->display->display_options['sorts']['field_aporta_date']['order'] = 'DESC';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'premios-aporta-view';
  $export['winners_aporta_search'] = $view;

  return $export;
}
