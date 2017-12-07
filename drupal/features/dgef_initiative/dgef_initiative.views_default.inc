<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_initiative (datos.gob.es)".
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
 * dgef_initiative.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dgef_initiative_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'initiative_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_initiative_index';
  $view->human_name = 'initiative_search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '500';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'leaflet';
  $handler->display->display_options['style_options']['entity_type'] = 'node';
  $handler->display->display_options['style_options']['data_source'] = 'field_geoposition';
  $handler->display->display_options['style_options']['name_field'] = 'nid';
  $handler->display->display_options['style_options']['description_field'] = '#rendered_entity';
  $handler->display->display_options['style_options']['view_mode'] = 'teaser';
  $handler->display->display_options['style_options']['map'] = 'dge_leaflet';
  $handler->display->display_options['style_options']['height'] = '600';
  $handler->display->display_options['style_options']['hide_empty'] = 0;
  $handler->display->display_options['style_options']['zoom']['initialZoom'] = '-1';
  $handler->display->display_options['style_options']['zoom']['minZoom'] = '0';
  $handler->display->display_options['style_options']['zoom']['maxZoom'] = '18';
  $handler->display->display_options['style_options']['icon']['iconType'] = 'html';
  $handler->display->display_options['style_options']['icon']['html'] = 'field_initiative_icon';
  $handler->display->display_options['style_options']['icon']['htmlClass'] = 'dge-marker';
  $handler->display->display_options['style_options']['vector_display']['stroke'] = 0;
  $handler->display->display_options['style_options']['vector_display']['fill'] = 0;
  $handler->display->display_options['style_options']['vector_display']['clickable'] = 0;
  /* Relationship: Indexed Node: Nivel de administración */
  $handler->display->display_options['relationships']['field_initiative_admin_level']['id'] = 'field_initiative_admin_level';
  $handler->display->display_options['relationships']['field_initiative_admin_level']['table'] = 'search_api_index_initiative_index';
  $handler->display->display_options['relationships']['field_initiative_admin_level']['field'] = 'field_initiative_admin_level';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_initiative_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Indexed Node: Geoposition */
  $handler->display->display_options['fields']['field_geoposition']['id'] = 'field_geoposition';
  $handler->display->display_options['fields']['field_geoposition']['table'] = 'search_api_index_initiative_index';
  $handler->display->display_options['fields']['field_geoposition']['field'] = 'field_geoposition';
  $handler->display->display_options['fields']['field_geoposition']['label'] = '';
  $handler->display->display_options['fields']['field_geoposition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geoposition']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_geoposition']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_geoposition']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  /* Field: Taxonomy term: Initiative icon */
  $handler->display->display_options['fields']['field_initiative_icon']['id'] = 'field_initiative_icon';
  $handler->display->display_options['fields']['field_initiative_icon']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['field_initiative_icon']['field'] = 'field_initiative_icon';
  $handler->display->display_options['fields']['field_initiative_icon']['relationship'] = 'field_initiative_admin_level';
  $handler->display->display_options['fields']['field_initiative_icon']['label'] = '';
  $handler->display->display_options['fields']['field_initiative_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_initiative_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_initiative_icon']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_initiative_index';
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
    6 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_initiative_license' => 'field_initiative_license',
    'field_initiative_organization' => 'field_initiative_organization',
    'title2' => 'title2',
  );

  /* Display: Contexto */
  $handler = $view->new_display('ctools_context', 'Contexto', 'ctools_context_1');
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Content pane Map */
  $handler = $view->new_display('panel_pane', 'Content pane Map', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['initiative_search'] = $view;

  return $export;
}
