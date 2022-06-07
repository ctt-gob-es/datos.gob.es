<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_basic (datos.gob.es)".
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

function theme_dge_basic_fields_created($variables) {
  $node = $variables['node'] ;
  $output = '<time datetime="' . format_date($node->created, 'custom', 'c') . '" class="node-created">';
  $output .= format_date($node->created, 'short');
  $output .= '</time>';
  return $output;
}

function theme_dge_basic_fields_title($variables) {
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];
  if($view_mode == 'full' || $view_mode == 'default') $tag = 'h1';
  else $tag = 'h3';
  $entity_uri = entity_uri('node', $node);
  $output = '<'.$tag.' class="node-title">';
  if($view_mode == 'full' || $view_mode == 'default')
    $output .= $node->title;
  else
    $output .= l($node->title, $entity_uri['path']);
  $output .= '</'.$tag.'>';
  return $output;
}

function theme_dge_basic_fields_author($variables) {
  $node = $variables['node'] ;
  $account = user_load($node->uid);
  return $account->name;
}
