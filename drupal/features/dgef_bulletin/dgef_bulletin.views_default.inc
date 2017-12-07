<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_bulletin (datos.gob.es)".
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
 * dgef_bulletin.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dgef_bulletin_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'bulletin_detail';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'bulletin_detail';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'dge-detail dge-detail--bulletin';
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
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h1';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'dge-detail__title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Cabecera */
  $handler->display->display_options['fields']['field_bulletin_header']['id'] = 'field_bulletin_header';
  $handler->display->display_options['fields']['field_bulletin_header']['table'] = 'field_data_field_bulletin_header';
  $handler->display->display_options['fields']['field_bulletin_header']['field'] = 'field_bulletin_header';
  $handler->display->display_options['fields']['field_bulletin_header']['label'] = '';
  $handler->display->display_options['fields']['field_bulletin_header']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bulletin_header']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_bulletin_header']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin_header']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bulletin_header']['element_wrapper_class'] = 'dge-detail__header';
  $handler->display->display_options['fields']['field_bulletin_header']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin_header']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bulletin_header']['settings'] = array(
    'image_style' => 'bulletin_image',
    'image_link' => '',
  );
  /* Field: Content: Fecha */
  $handler->display->display_options['fields']['field_bulletin_date']['id'] = 'field_bulletin_date';
  $handler->display->display_options['fields']['field_bulletin_date']['table'] = 'field_data_field_bulletin_date';
  $handler->display->display_options['fields']['field_bulletin_date']['field'] = 'field_bulletin_date';
  $handler->display->display_options['fields']['field_bulletin_date']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_bulletin_date']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_bulletin_date']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_bulletin_date']['element_wrapper_class'] = 'dge-detail__date';
  $handler->display->display_options['fields']['field_bulletin_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Descripción */
  $handler->display->display_options['fields']['field_bulletin_description']['id'] = 'field_bulletin_description';
  $handler->display->display_options['fields']['field_bulletin_description']['table'] = 'field_data_field_bulletin_description';
  $handler->display->display_options['fields']['field_bulletin_description']['field'] = 'field_bulletin_description';
  $handler->display->display_options['fields']['field_bulletin_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bulletin_description']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_bulletin_description']['element_class'] = 'dge-detail__desc-cont';
  $handler->display->display_options['fields']['field_bulletin_description']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_bulletin_description']['element_label_class'] = 'dge-detail__desc-title';
  $handler->display->display_options['fields']['field_bulletin_description']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bulletin_description']['element_wrapper_class'] = 'dge-detail__desc';
  $handler->display->display_options['fields']['field_bulletin_description']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin_description']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_bulletin_description']['multi_type'] = 'ul';
  /* Field: Content: Descripción */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_class'] = 'dge-detail__desc-cont';
  $handler->display->display_options['fields']['body']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['body']['element_label_class'] = 'dge-detail__desc-title';
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'dge-detail__desc';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Párrafo */
  $handler->display->display_options['fields']['field_bulletin_parag']['id'] = 'field_bulletin_parag';
  $handler->display->display_options['fields']['field_bulletin_parag']['table'] = 'field_data_field_bulletin_parag';
  $handler->display->display_options['fields']['field_bulletin_parag']['field'] = 'field_bulletin_parag';
  $handler->display->display_options['fields']['field_bulletin_parag']['label'] = '';
  $handler->display->display_options['fields']['field_bulletin_parag']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bulletin_parag']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_bulletin_parag']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin_parag']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bulletin_parag']['element_wrapper_class'] = 'dge-detail__desc';
  $handler->display->display_options['fields']['field_bulletin_parag']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin_parag']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_bulletin_parag']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_bulletin_parag']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_bulletin_parag']['multi_type'] = 'ul';
  /* Field: Content: Etiquetas */
  $handler->display->display_options['fields']['field_bulletin_tags']['id'] = 'field_bulletin_tags';
  $handler->display->display_options['fields']['field_bulletin_tags']['table'] = 'field_data_field_bulletin_tags';
  $handler->display->display_options['fields']['field_bulletin_tags']['field'] = 'field_bulletin_tags';
  $handler->display->display_options['fields']['field_bulletin_tags']['label'] = '';
  $handler->display->display_options['fields']['field_bulletin_tags']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bulletin_tags']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_bulletin_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin_tags']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bulletin_tags']['element_wrapper_class'] = 'dge-detail__tags';
  $handler->display->display_options['fields']['field_bulletin_tags']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_bulletin_tags']['multi_type'] = 'ul';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bulletin' => 'bulletin',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['bulletin_detail'] = $view;

  $view = new view();
  $view->name = 'bulletin_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_bulletin_index';
  $view->human_name = 'bulletin_search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'search_api_views_cache';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todo -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primero';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No hay resultados';
  /* Field: Indexed Node: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Filter criterion: Indexed Node: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Buscar';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:value' => 'body:value',
    'title2' => 'title2',
  );

  /* Display: Contexto */
  $handler = $view->new_display('ctools_context', 'Contexto', 'ctools_context_1');
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'dge-list dge-list--blogs';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'dge-list__elm';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'dge-list__lst';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'dge-list__title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Fecha */
  $handler->display->display_options['fields']['field_bulletin_date']['id'] = 'field_bulletin_date';
  $handler->display->display_options['fields']['field_bulletin_date']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['fields']['field_bulletin_date']['field'] = 'field_bulletin_date';
  $handler->display->display_options['fields']['field_bulletin_date']['label'] = '';
  $handler->display->display_options['fields']['field_bulletin_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bulletin_date']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_bulletin_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin_date']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_bulletin_date']['element_wrapper_class'] = 'dge-list__date';
  $handler->display->display_options['fields']['field_bulletin_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '255';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'dge-list__desc';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Indexed Node: Etiquetas */
  $handler->display->display_options['fields']['field_bulletin_tags']['id'] = 'field_bulletin_tags';
  $handler->display->display_options['fields']['field_bulletin_tags']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['fields']['field_bulletin_tags']['field'] = 'field_bulletin_tags';
  $handler->display->display_options['fields']['field_bulletin_tags']['label'] = '';
  $handler->display->display_options['fields']['field_bulletin_tags']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bulletin_tags']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_bulletin_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin_tags']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bulletin_tags']['element_wrapper_class'] = 'dge-list__tags';
  $handler->display->display_options['fields']['field_bulletin_tags']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bulletin_tags']['list']['mode'] = 'list';
  $handler->display->display_options['fields']['field_bulletin_tags']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_bulletin_tags']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_bulletin_tags']['bypass_access'] = 0;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_dge');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'url';
  $handler->display->display_options['row_options']['description_field'] = 'body';
  $handler->display->display_options['row_options']['creator_field'] = 'author';
  $handler->display->display_options['row_options']['date_field'] = 'created';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'nid',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '400';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Node: Autor */
  $handler->display->display_options['fields']['author']['id'] = 'author';
  $handler->display->display_options['fields']['author']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['fields']['author']['field'] = 'author';
  $handler->display->display_options['fields']['author']['label'] = '';
  $handler->display->display_options['fields']['author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['author']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['author']['view_mode'] = 'full';
  $handler->display->display_options['fields']['author']['bypass_access'] = 0;
  /* Field: Indexed Node: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_bulletin_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['path'] = 'rss-boletines.xml';
  $handler->display->display_options['displays'] = array(
    'panel_pane_1' => 'panel_pane_1',
    'default' => 0,
    'ctools_context_1' => 0,
  );
  $export['bulletin_search'] = $view;

  return $export;
}
