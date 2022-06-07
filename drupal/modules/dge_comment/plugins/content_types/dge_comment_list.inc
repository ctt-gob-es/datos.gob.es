<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_comment (datos.gob.es)".
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

$plugin = array(
  'single' => TRUE,
  'title' => t('Comment List'),
  'icon' => 'icon_comment.png',
  'description' => t('A list of comments in all languages.'),
  'required context' => array(
      new ctools_context_required(t('Node'), 'node'),
      ),
  'category' => t('Comment'),
  'render callback'  => 'dge_comment_comments_list_render',
  'defaults' => array('anon_links' => false),
);

function dge_comment_comments_list_render($subtype, $conf, $panel_args, $context) {
  $node = $context[0]->data;
  $block = new stdClass();
  $block->module = 'comments';
  $block->delta  = $node->nid;
  $block->title = '';

  $output = $comment_messages;
  $additions = dge_comment_node_page_additions($node);

  $output .= drupal_render($additions);

  $block->content = $output;

  return $block;
}
