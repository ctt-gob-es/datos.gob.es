<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_initiative_import (datos.gob.es)".
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
 * dgef_initiative_import.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dgef_initiative_import_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'initiative_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'initiative_export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    6 => '6',
    8 => '8',
  );
  $handler->display->display_options['cache']['type'] = 'none';
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
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Contenido: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'id';
  /* Campo: Contenido: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'i_title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Campo: Contenido: Enlace al portal */
  $handler->display->display_options['fields']['field_initiative_link']['id'] = 'field_initiative_link';
  $handler->display->display_options['fields']['field_initiative_link']['table'] = 'field_data_field_initiative_link';
  $handler->display->display_options['fields']['field_initiative_link']['field'] = 'field_initiative_link';
  $handler->display->display_options['fields']['field_initiative_link']['label'] = 'i_link';
  $handler->display->display_options['fields']['field_initiative_link']['alter']['text'] = '[field_initiative_link-title]|[field_initiative_link-url]';
  $handler->display->display_options['fields']['field_initiative_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_initiative_link']['type'] = 'link_absolute';
  /* Campo: Contenido: Organismo de la iniciativa */
  $handler->display->display_options['fields']['field_initiative_organization']['id'] = 'field_initiative_organization';
  $handler->display->display_options['fields']['field_initiative_organization']['table'] = 'field_data_field_initiative_organization';
  $handler->display->display_options['fields']['field_initiative_organization']['field'] = 'field_initiative_organization';
  $handler->display->display_options['fields']['field_initiative_organization']['label'] = 'i_organization';
  /* Campo: Contenido: Geoposition */
  $handler->display->display_options['fields']['field_geoposition']['id'] = 'field_geoposition';
  $handler->display->display_options['fields']['field_geoposition']['table'] = 'field_data_field_geoposition';
  $handler->display->display_options['fields']['field_geoposition']['field'] = 'field_geoposition';
  $handler->display->display_options['fields']['field_geoposition']['label'] = 'i_latitude';
  $handler->display->display_options['fields']['field_geoposition']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_geoposition']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_geoposition']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Campo: Contenido: Geoposition */
  $handler->display->display_options['fields']['field_geoposition_1']['id'] = 'field_geoposition_1';
  $handler->display->display_options['fields']['field_geoposition_1']['table'] = 'field_data_field_geoposition';
  $handler->display->display_options['fields']['field_geoposition_1']['field'] = 'field_geoposition';
  $handler->display->display_options['fields']['field_geoposition_1']['label'] = 'i_longitude';
  $handler->display->display_options['fields']['field_geoposition_1']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_geoposition_1']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_geoposition_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Campo: Contenido: Nivel de administración */
  $handler->display->display_options['fields']['field_initiative_admin_level']['id'] = 'field_initiative_admin_level';
  $handler->display->display_options['fields']['field_initiative_admin_level']['table'] = 'field_data_field_initiative_admin_level';
  $handler->display->display_options['fields']['field_initiative_admin_level']['field'] = 'field_initiative_admin_level';
  $handler->display->display_options['fields']['field_initiative_admin_level']['label'] = 'i_admin_level';
  $handler->display->display_options['fields']['field_initiative_admin_level']['type'] = 'taxonomy_term_reference_plain';
  /* Campo: Contenido: Grado de reutilización */
  $handler->display->display_options['fields']['field_initiative_reuse_level']['id'] = 'field_initiative_reuse_level';
  $handler->display->display_options['fields']['field_initiative_reuse_level']['table'] = 'field_data_field_initiative_reuse_level';
  $handler->display->display_options['fields']['field_initiative_reuse_level']['field'] = 'field_initiative_reuse_level';
  $handler->display->display_options['fields']['field_initiative_reuse_level']['label'] = 'i_reuse_level';
  $handler->display->display_options['fields']['field_initiative_reuse_level']['type'] = 'taxonomy_term_reference_plain';
  /* Campo: Contenido: Tipo de buscador */
  $handler->display->display_options['fields']['field_initiative_search_type']['id'] = 'field_initiative_search_type';
  $handler->display->display_options['fields']['field_initiative_search_type']['table'] = 'field_data_field_initiative_search_type';
  $handler->display->display_options['fields']['field_initiative_search_type']['field'] = 'field_initiative_search_type';
  $handler->display->display_options['fields']['field_initiative_search_type']['label'] = 'i_search_type';
  $handler->display->display_options['fields']['field_initiative_search_type']['type'] = 'taxonomy_term_reference_plain';
  /* Campo: Contenido: Categoría */
  $handler->display->display_options['fields']['field_initiative_category']['id'] = 'field_initiative_category';
  $handler->display->display_options['fields']['field_initiative_category']['table'] = 'field_data_field_initiative_category';
  $handler->display->display_options['fields']['field_initiative_category']['field'] = 'field_initiative_category';
  $handler->display->display_options['fields']['field_initiative_category']['label'] = 'i_category';
  $handler->display->display_options['fields']['field_initiative_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_initiative_category']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_initiative_category']['separator'] = '|';
  /* Campo: Contenido: Estrategia apertura de datos */
  $handler->display->display_options['fields']['field_initiative_strategy']['id'] = 'field_initiative_strategy';
  $handler->display->display_options['fields']['field_initiative_strategy']['table'] = 'field_data_field_initiative_strategy';
  $handler->display->display_options['fields']['field_initiative_strategy']['field'] = 'field_initiative_strategy';
  $handler->display->display_options['fields']['field_initiative_strategy']['label'] = 'i_strategy';
  $handler->display->display_options['fields']['field_initiative_strategy']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_initiative_strategy']['type'] = 'link_absolute';
  /* Campo: Contenido: Descarga del catálogo */
  $handler->display->display_options['fields']['field_initiative_download']['id'] = 'field_initiative_download';
  $handler->display->display_options['fields']['field_initiative_download']['table'] = 'field_data_field_initiative_download';
  $handler->display->display_options['fields']['field_initiative_download']['field'] = 'field_initiative_download';
  $handler->display->display_options['fields']['field_initiative_download']['label'] = 'i_download';
  $handler->display->display_options['fields']['field_initiative_download']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_initiative_download']['type'] = 'link_absolute';
  /* Campo: Contenido: Web Service */
  $handler->display->display_options['fields']['field_initiative_webservice']['id'] = 'field_initiative_webservice';
  $handler->display->display_options['fields']['field_initiative_webservice']['table'] = 'field_data_field_initiative_webservice';
  $handler->display->display_options['fields']['field_initiative_webservice']['field'] = 'field_initiative_webservice';
  $handler->display->display_options['fields']['field_initiative_webservice']['label'] = 'i_webservice';
  $handler->display->display_options['fields']['field_initiative_webservice']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_initiative_webservice']['type'] = 'link_absolute';
  /* Campo: Contenido: API Ckan */
  $handler->display->display_options['fields']['field_initiative_api_ckan']['id'] = 'field_initiative_api_ckan';
  $handler->display->display_options['fields']['field_initiative_api_ckan']['table'] = 'field_data_field_initiative_api_ckan';
  $handler->display->display_options['fields']['field_initiative_api_ckan']['field'] = 'field_initiative_api_ckan';
  $handler->display->display_options['fields']['field_initiative_api_ckan']['label'] = 'i_api_ckan';
  $handler->display->display_options['fields']['field_initiative_api_ckan']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_initiative_api_ckan']['type'] = 'link_absolute';
  /* Campo: Contenido: Restful API */
  $handler->display->display_options['fields']['field_initiative_restful_api']['id'] = 'field_initiative_restful_api';
  $handler->display->display_options['fields']['field_initiative_restful_api']['table'] = 'field_data_field_initiative_restful_api';
  $handler->display->display_options['fields']['field_initiative_restful_api']['field'] = 'field_initiative_restful_api';
  $handler->display->display_options['fields']['field_initiative_restful_api']['label'] = 'i_restful';
  $handler->display->display_options['fields']['field_initiative_restful_api']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_initiative_restful_api']['type'] = 'link_absolute';
  /* Campo: Contenido: Punto SPARQL */
  $handler->display->display_options['fields']['field_initiative_sparql']['id'] = 'field_initiative_sparql';
  $handler->display->display_options['fields']['field_initiative_sparql']['table'] = 'field_data_field_initiative_sparql';
  $handler->display->display_options['fields']['field_initiative_sparql']['field'] = 'field_initiative_sparql';
  $handler->display->display_options['fields']['field_initiative_sparql']['label'] = 'i_sparql';
  $handler->display->display_options['fields']['field_initiative_sparql']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_initiative_sparql']['type'] = 'link_absolute';
  /* Campo: Contenido: Licencia */
  $handler->display->display_options['fields']['field_initiative_license']['id'] = 'field_initiative_license';
  $handler->display->display_options['fields']['field_initiative_license']['table'] = 'field_data_field_initiative_license';
  $handler->display->display_options['fields']['field_initiative_license']['field'] = 'field_initiative_license';
  $handler->display->display_options['fields']['field_initiative_license']['label'] = 'i_license';
  /* Campo: Contenido: Canal de solicitud */
  $handler->display->display_options['fields']['field_initiative_channel']['id'] = 'field_initiative_channel';
  $handler->display->display_options['fields']['field_initiative_channel']['table'] = 'field_data_field_initiative_channel';
  $handler->display->display_options['fields']['field_initiative_channel']['field'] = 'field_initiative_channel';
  $handler->display->display_options['fields']['field_initiative_channel']['label'] = 'i_channel';
  $handler->display->display_options['fields']['field_initiative_channel']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_initiative_channel']['type'] = 'link_absolute';
  /* Campo: Contenido: Catálogo de aplicaciones */
  $handler->display->display_options['fields']['field_initiative_catalog']['id'] = 'field_initiative_catalog';
  $handler->display->display_options['fields']['field_initiative_catalog']['table'] = 'field_data_field_initiative_catalog';
  $handler->display->display_options['fields']['field_initiative_catalog']['field'] = 'field_initiative_catalog';
  $handler->display->display_options['fields']['field_initiative_catalog']['label'] = 'i_catalog';
  $handler->display->display_options['fields']['field_initiative_catalog']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_initiative_catalog']['type'] = 'link_absolute';
  /* Campo: Contenido: Recursos formativos */
  $handler->display->display_options['fields']['field_initiative_resources']['id'] = 'field_initiative_resources';
  $handler->display->display_options['fields']['field_initiative_resources']['table'] = 'field_data_field_initiative_resources';
  $handler->display->display_options['fields']['field_initiative_resources']['field'] = 'field_initiative_resources';
  $handler->display->display_options['fields']['field_initiative_resources']['label'] = 'i_resources';
  $handler->display->display_options['fields']['field_initiative_resources']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_initiative_resources']['type'] = 'link_absolute';
  /* Campo: Contenido: Colabora con datos.gob.es */
  $handler->display->display_options['fields']['field_initiative_collaborate']['id'] = 'field_initiative_collaborate';
  $handler->display->display_options['fields']['field_initiative_collaborate']['table'] = 'field_data_field_initiative_collaborate';
  $handler->display->display_options['fields']['field_initiative_collaborate']['field'] = 'field_initiative_collaborate';
  $handler->display->display_options['fields']['field_initiative_collaborate']['label'] = 'i_collaborate';
  $handler->display->display_options['fields']['field_initiative_collaborate']['type'] = 'list_key';
  /* Campo: Contenido: Publicado */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'i_status';
  $handler->display->display_options['fields']['status']['element_type'] = '0';
  $handler->display->display_options['fields']['status']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['status']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
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
    'initiative' => 'initiative',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/export/initiative';
  $export['initiative_export'] = $view;

  return $export;
}
