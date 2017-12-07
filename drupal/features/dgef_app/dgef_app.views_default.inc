<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_app (datos.gob.es)".
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
 * dgef_app.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dgef_app_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'app_detail';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'app_detail';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'dge-detail dge-detail--app';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h1';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'dge-detail__title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Categoría */
  $handler->display->display_options['fields']['field_app_category']['id'] = 'field_app_category';
  $handler->display->display_options['fields']['field_app_category']['table'] = 'field_data_field_app_category';
  $handler->display->display_options['fields']['field_app_category']['field'] = 'field_app_category';
  $handler->display->display_options['fields']['field_app_category']['label'] = '';
  $handler->display->display_options['fields']['field_app_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_category']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_app_category']['element_wrapper_class'] = 'dge-detail__category';
  $handler->display->display_options['fields']['field_app_category']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_app_category']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_app_category']['multi_type'] = 'ul';
  /* Field: Content: Fecha de publicación */
  $handler->display->display_options['fields']['field_app_publish_date']['id'] = 'field_app_publish_date';
  $handler->display->display_options['fields']['field_app_publish_date']['table'] = 'field_data_field_app_publish_date';
  $handler->display->display_options['fields']['field_app_publish_date']['field'] = 'field_app_publish_date';
  $handler->display->display_options['fields']['field_app_publish_date']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_app_publish_date']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_app_publish_date']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_app_publish_date']['element_wrapper_class'] = 'dge-detail__date';
  $handler->display->display_options['fields']['field_app_publish_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_publish_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Fecha de actualización */
  $handler->display->display_options['fields']['field_app_update_date']['id'] = 'field_app_update_date';
  $handler->display->display_options['fields']['field_app_update_date']['table'] = 'field_data_field_app_update_date';
  $handler->display->display_options['fields']['field_app_update_date']['field'] = 'field_app_update_date';
  $handler->display->display_options['fields']['field_app_update_date']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_app_update_date']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_app_update_date']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_app_update_date']['element_wrapper_class'] = 'dge-detail__date';
  $handler->display->display_options['fields']['field_app_update_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_update_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: URL al catálogo/s origen de los datos */
  $handler->display->display_options['fields']['field_app_dataset_url']['id'] = 'field_app_dataset_url';
  $handler->display->display_options['fields']['field_app_dataset_url']['table'] = 'field_data_field_app_dataset_url';
  $handler->display->display_options['fields']['field_app_dataset_url']['field'] = 'field_app_dataset_url';
  $handler->display->display_options['fields']['field_app_dataset_url']['label'] = 'URL';
  $handler->display->display_options['fields']['field_app_dataset_url']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_app_dataset_url']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_app_dataset_url']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_app_dataset_url']['element_wrapper_class'] = 'dge-detail__url';
  $handler->display->display_options['fields']['field_app_dataset_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_dataset_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_app_dataset_url']['delta_offset'] = '0';
  /* Field: Content: URL acceso aplicación */
  $handler->display->display_options['fields']['field_app_url']['id'] = 'field_app_url';
  $handler->display->display_options['fields']['field_app_url']['table'] = 'field_data_field_app_url';
  $handler->display->display_options['fields']['field_app_url']['field'] = 'field_app_url';
  $handler->display->display_options['fields']['field_app_url']['label'] = 'URL';
  $handler->display->display_options['fields']['field_app_url']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_app_url']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_app_url']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_app_url']['element_wrapper_class'] = 'dge-detail__url';
  $handler->display->display_options['fields']['field_app_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_app_url']['delta_offset'] = '0';
  /* Field: Content: Plataforma */
  $handler->display->display_options['fields']['field_app_platform']['id'] = 'field_app_platform';
  $handler->display->display_options['fields']['field_app_platform']['table'] = 'field_data_field_app_platform';
  $handler->display->display_options['fields']['field_app_platform']['field'] = 'field_app_platform';
  $handler->display->display_options['fields']['field_app_platform']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_app_platform']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_app_platform']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_app_platform']['element_wrapper_class'] = 'dge-detail__platform';
  $handler->display->display_options['fields']['field_app_platform']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_platform']['delta_offset'] = '0';
  /* Field: Content: Autor/Desarrollador */
  $handler->display->display_options['fields']['field_app_developer']['id'] = 'field_app_developer';
  $handler->display->display_options['fields']['field_app_developer']['table'] = 'field_data_field_app_developer';
  $handler->display->display_options['fields']['field_app_developer']['field'] = 'field_app_developer';
  $handler->display->display_options['fields']['field_app_developer']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_app_developer']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_app_developer']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_app_developer']['element_wrapper_class'] = 'dge-detail__author';
  $handler->display->display_options['fields']['field_app_developer']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_developer']['type'] = 'text_plain';
  /* Field: Content: Licencia */
  $handler->display->display_options['fields']['field_app_license']['id'] = 'field_app_license';
  $handler->display->display_options['fields']['field_app_license']['table'] = 'field_data_field_app_license';
  $handler->display->display_options['fields']['field_app_license']['field'] = 'field_app_license';
  $handler->display->display_options['fields']['field_app_license']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_app_license']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_app_license']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_app_license']['element_wrapper_class'] = 'dge-detail__license';
  $handler->display->display_options['fields']['field_app_license']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_license']['type'] = 'text_plain';
  /* Field: Content: Image/logo */
  $handler->display->display_options['fields']['field_app_image']['id'] = 'field_app_image';
  $handler->display->display_options['fields']['field_app_image']['table'] = 'field_data_field_app_image';
  $handler->display->display_options['fields']['field_app_image']['field'] = 'field_app_image';
  $handler->display->display_options['fields']['field_app_image']['label'] = '';
  $handler->display->display_options['fields']['field_app_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_app_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_app_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_app_image']['element_wrapper_class'] = 'dge-detail__img';
  $handler->display->display_options['fields']['field_app_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_app_image']['settings'] = array(
    'image_style' => 'app_logo',
    'image_link' => '',
  );
  /* Field: Content: Descripción */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_class'] = 'dge-detail__desc-cont';
  $handler->display->display_options['fields']['body']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['body']['element_label_class'] = 'dge-detail__desc-title';
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'dge-detail__desc';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Imagen */
  $handler->display->display_options['fields']['field_app_images']['id'] = 'field_app_images';
  $handler->display->display_options['fields']['field_app_images']['table'] = 'field_data_field_app_images';
  $handler->display->display_options['fields']['field_app_images']['field'] = 'field_app_images';
  $handler->display->display_options['fields']['field_app_images']['label'] = '';
  $handler->display->display_options['fields']['field_app_images']['element_type'] = '0';
  $handler->display->display_options['fields']['field_app_images']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_app_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_images']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_app_images']['element_wrapper_class'] = 'dge-detail__gallery';
  $handler->display->display_options['fields']['field_app_images']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_app_images']['settings'] = array(
    'image_style' => 'app_images',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_app_images']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_app_images']['multi_type'] = 'ul';
  /* Field: Content: Etiquetas */
  $handler->display->display_options['fields']['field_app_tags']['id'] = 'field_app_tags';
  $handler->display->display_options['fields']['field_app_tags']['table'] = 'field_data_field_app_tags';
  $handler->display->display_options['fields']['field_app_tags']['field'] = 'field_app_tags';
  $handler->display->display_options['fields']['field_app_tags']['label'] = '';
  $handler->display->display_options['fields']['field_app_tags']['element_type'] = '0';
  $handler->display->display_options['fields']['field_app_tags']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_app_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_tags']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_app_tags']['element_wrapper_class'] = 'dge-detail__tags';
  $handler->display->display_options['fields']['field_app_tags']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_app_tags']['multi_type'] = 'ul';
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
    'app' => 'app',
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
  $export['app_detail'] = $view;

  $view = new view();
  $view->name = 'apps_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'apps_admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Apps';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todo -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primero';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'You do not have any app currently';
  /* Relationship: Content: Autor */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'uid';
  /* Field: Content: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Content: Language Markup Enabled */
  $handler->display->display_options['fields']['language_markup_enabled']['id'] = 'language_markup_enabled';
  $handler->display->display_options['fields']['language_markup_enabled']['table'] = 'node';
  $handler->display->display_options['fields']['language_markup_enabled']['field'] = 'language_markup_enabled';
  $handler->display->display_options['fields']['language_markup_enabled']['label'] = 'Traducción automática';
  $handler->display->display_options['fields']['language_markup_enabled']['link_to_entity'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Content: Publicado */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Autor';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'app' => 'app',
  );
  /* Filter criterion: Content access: DGE Access Node */
  $handler->display->display_options['filters']['dge_access_node_access']['id'] = 'dge_access_node_access';
  $handler->display->display_options['filters']['dge_access_node_access']['table'] = 'node_access';
  $handler->display->display_options['filters']['dge_access_node_access']['field'] = 'dge_access_node_access';
  $handler->display->display_options['filters']['dge_access_node_access']['value'] = 'update';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/dashboard/apps';
  $export['apps_admin'] = $view;

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
  $handler->display->display_options['css_class'] = 'dge-app dge-app--home';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'más';
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
  $handler->display->display_options['style_options']['wrapper_class'] = 'dge-app__content';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Image/logo */
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
  $handler->display->display_options['fields']['field_app_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_app_image']['settings'] = array(
    'image_style' => 'home_carousel',
    'image_link' => '',
  );
  /* Field: Content: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="dge-app__img">[field_app_image]</span>
<strong class="dge-app__title">[title]</strong>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'app' => 'app',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Home */
  $handler = $view->new_display('block', 'Home', 'block');
  $handler->display->display_options['link_url'] = 'aplicaciones';
  $export['apps_home'] = $view;

  $view = new view();
  $view->name = 'apps_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_app';
  $view->human_name = 'apps_search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'dge-list dge-list--apps';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
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
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No hay resultados';
  /* Field: Indexed Node: Image/logo */
  $handler->display->display_options['fields']['field_app_image']['id'] = 'field_app_image';
  $handler->display->display_options['fields']['field_app_image']['table'] = 'search_api_index_app';
  $handler->display->display_options['fields']['field_app_image']['field'] = 'field_app_image';
  $handler->display->display_options['fields']['field_app_image']['label'] = '';
  $handler->display->display_options['fields']['field_app_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_app_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_app_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_image']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_app_image']['element_wrapper_class'] = 'dge-list__img';
  $handler->display->display_options['fields']['field_app_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_app_image']['settings'] = array(
    'image_style' => 'app_teaser',
    'image_link' => '',
  );
  /* Field: Indexed Node: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_app';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'dge-list__title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Autor/Desarrollador */
  $handler->display->display_options['fields']['field_app_developer']['id'] = 'field_app_developer';
  $handler->display->display_options['fields']['field_app_developer']['table'] = 'search_api_index_app';
  $handler->display->display_options['fields']['field_app_developer']['field'] = 'field_app_developer';
  $handler->display->display_options['fields']['field_app_developer']['label'] = '';
  $handler->display->display_options['fields']['field_app_developer']['element_type'] = '0';
  $handler->display->display_options['fields']['field_app_developer']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_app_developer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_developer']['element_wrapper_type'] = 'em';
  $handler->display->display_options['fields']['field_app_developer']['element_wrapper_class'] = 'dge-list__dev';
  $handler->display->display_options['fields']['field_app_developer']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_developer']['type'] = 'text_plain';
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_app';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '255';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'dge-list__desc';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Indexed Node: Categoría */
  $handler->display->display_options['fields']['field_app_category']['id'] = 'field_app_category';
  $handler->display->display_options['fields']['field_app_category']['table'] = 'search_api_index_app';
  $handler->display->display_options['fields']['field_app_category']['field'] = 'field_app_category';
  $handler->display->display_options['fields']['field_app_category']['label'] = '';
  $handler->display->display_options['fields']['field_app_category']['element_type'] = '0';
  $handler->display->display_options['fields']['field_app_category']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_app_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_category']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_app_category']['element_wrapper_class'] = 'dge-list__tags';
  $handler->display->display_options['fields']['field_app_category']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_app_category']['list']['mode'] = 'list';
  $handler->display->display_options['fields']['field_app_category']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_app_category']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_app_category']['bypass_access'] = 0;
  /* Filter criterion: Indexed Node: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_app';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_app';
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
    4 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:value' => 'body:value',
    'field_app_developer' => 'field_app_developer',
    'field_app_license' => 'field_app_license',
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
  $handler->display->display_options['exposed_block'] = TRUE;

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
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_app';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_app';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '400';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_app';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_app';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Node: Autor */
  $handler->display->display_options['fields']['author']['id'] = 'author';
  $handler->display->display_options['fields']['author']['table'] = 'search_api_index_app';
  $handler->display->display_options['fields']['author']['field'] = 'author';
  $handler->display->display_options['fields']['author']['label'] = '';
  $handler->display->display_options['fields']['author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['author']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['author']['view_mode'] = 'full';
  $handler->display->display_options['fields']['author']['bypass_access'] = 0;
  /* Field: Indexed Node: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_app';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_app';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_app';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['path'] = 'rss-aplicaciones.xml';
  $handler->display->display_options['displays'] = array(
    'panel_pane_1' => 'panel_pane_1',
    'default' => 0,
    'ctools_context_1' => 0,
  );
  $export['apps_search'] = $view;

  return $export;
}
