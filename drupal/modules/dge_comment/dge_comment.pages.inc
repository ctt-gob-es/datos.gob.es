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

/*
 * @see comment_reply
 */

function dge_comment_reply($node, $pid = NULL) {
  //limpiar cache de dataset en usuarios anonimos
  $node_type   ='dataset';
  if ($node->type === $node_type) {
    $nid=$node->nid;
    cache_clear_all('field:node:'.$nid, 'cache_field');
  }

  drupal_set_title(t(variable_get('dge_comment_new_comment', 'Add new comment')).': '.$node->title);
  $url = 'node/' . $node->nid;
  if($node->type == 'dataset') {
    $url = dge_comment_build_package_url(dge_comment_dataset_get_package_name($node));
  }
  drupal_set_breadcrumb(array(l(t('Home'), NULL), l($node->title, $url)));
  $op = isset($_POST['op']) ? $_POST['op'] : '';
  $build = array();

  // The user is previewing a comment prior to submitting it.
  if ($op == t('Preview')) {
    if (user_access('post comments')) {
      $build['comment_form'] = drupal_get_form("comment_node_{$node->type}_form", (object) array('pid' => $pid, 'nid' => $node->nid));
    }
    else {
      drupal_set_message(t('You are not authorized to post comments.'), 'error');
      drupal_goto("node/$node->nid");
    }
  }
  else {
    // $pid indicates that this is a reply to a comment.
    if ($pid) {
      if (user_access('access comments')) {
        // Load the comment whose cid = $pid
        $comment = db_query('SELECT c.*, u.uid, u.name AS registered_name, u.signature, u.signature_format, u.picture, u.data FROM {comment} c INNER JOIN {users} u ON c.uid = u.uid WHERE c.cid = :cid AND c.status = :status', array(
          ':cid' => $pid,
          ':status' => COMMENT_PUBLISHED,
        ))->fetchObject();
        if ($comment) {
          // If that comment exists, make sure that the current comment and the
          // parent comment both belong to the same parent node.
          if ($comment->nid != $node->nid) {
            // Attempting to reply to a comment not belonging to the current nid.
            drupal_set_message(t('The comment you are replying to does not exist.'), 'error');
            drupal_goto("node/$node->nid");
          }
          // Display the parent comment
          $comment->node_type = 'comment_node_' . $node->type;
          field_attach_load('comment', array($comment->cid => $comment));
          $comment->name = $comment->uid ? $comment->registered_name : $comment->name;
          $build['comment_parent'] = comment_view($comment, $node);
        }
        else {
          drupal_set_message(t('The comment you are replying to does not exist.'), 'error');
          drupal_goto("node/$node->nid");
        }
      }
      else {
        drupal_set_message(t('You are not authorized to view comments.'), 'error');
        drupal_goto("node/$node->nid");
      }
    }

    // Should we show the reply box?
    if ($node->comment != COMMENT_NODE_OPEN) {
      drupal_set_message(t("This discussion is closed: you can't post new comments."), 'error');
      drupal_goto("node/$node->nid");
    }
    elseif (user_access('post comments')) {
      $edit = array('nid' => $node->nid, 'pid' => $pid);
      $build['comment_form'] = drupal_get_form("comment_node_{$node->type}_form", (object) $edit);
    }
    else {
      drupal_set_message(t('You are not authorized to post comments.'), 'error');
      drupal_goto("node/$node->nid");
    }
  }

  drupal_page_is_cacheable(FALSE);
  return $build;
}

/**
 * Dataset widget view
 */
function dge_comment_dataset_comment_view($package_id) {
  global $base_path;

  $result_package = db_select('field_data_field_ckan_package_id', 'n')
    ->fields('n')
    ->condition(' field_ckan_package_id_value', $package_id,'=')
    ->execute()
    ->fetchAssoc();
  $entity_id = $result_package['entity_id'];

  $output = '';
  $empty_text = '<p class="empty-comments">'.t(variable_get('dge_comment_no_comments', 'No comments')).'</p>';
  $package = dge_comment_ckan_load_package($package_id);
  $result_package = db_select('field_data_field_ckan_package_id', 'n')
    ->fields('n')
    ->condition(' field_ckan_package_id_value', $package_id,'=')
    ->execute()
    ->fetchAssoc();
  $entity_id = $result_package['entity_id'];
  if(!$package) {
    return t('Package does not exist');
  }
  $dataset = dge_comment_dataset_load_by_package($package_id);
  if(!$dataset) {
    $package = dge_comment_ckan_load_package($package_id);
    $dataset = dge_comment_dataset_create($package);
    $result_package = db_select('field_data_field_ckan_package_id', 'n')
    ->fields('n')
    ->condition(' field_ckan_package_id_value', $package_id,'=')
    ->execute()
    ->fetchAssoc();
    $entity_id = $result_package['entity_id'];
    $additions = array();
    $additions['comments'] = array( '#type' => 'markup', '#markup' => $empty_text);
    $additions['comment_messages'] = array('#theme' => 'comment_messages');
    $additions['link_comment'] = array(
      '#theme' => 'link',
      '#text' => t(variable_get('dge_comment_new_comment', 'Add new comment')),
      '#path' => $base_path . 'package/comment/add/' . $package_id,
      '#options' => array(
        'attributes' => array('title' => t(variable_get('dge_comment_new_comment', 'Add new comment')),
                              'class' => array('comments-add-link')),
        'html' => FALSE,
      ),
    );
    $additions['rate_widget'] = rate_generate_widget(1, 'node',$entity_id);
    //Create fake node
    $node = new stdClass();
    $node->type = 'dataset';

    $additions += array(
      '#theme' => 'comment_wrapper',
      '#node' => $node,
      'comment_form' => array(),
    );
		//render comments
    $output .= drupal_render($additions);
  }
  else {
    if ($dataset->comment && empty($dataset->in_preview)) {
      $additions['rate_widget'] = rate_generate_widget(1, 'node', $entity_id);
      $additions = dge_comment_node_page_additions($dataset);
      $output .= drupal_render($additions);
    }
  }

  return $output;
}

/*
 * Comment widget view
 */
function dge_comment_content_comment_view($node) {

  $output = '';
  $empty_text = '<p class="empty-comments">'.t(variable_get('dge_comment_no_comments', 'No comments')).'</p>';
  if(!$node) {
    return t('Content does not exist');
  }
  else {
    if ($node->comment && empty($node->in_preview)) {
      $additions['rate_widget'] = rate_generate_widget(1, 'node', $node->nid);
      $additions = dge_comment_node_page_additions($node);

      if(empty($additions))
        $output .= $empty_text;
      else
        $output .= drupal_render($additions);
    }
  }
  return $output;
}

/**
 * Add comment to dataset filter
 */
function dge_comment_dataset_comment_add($package_id) {
  $package = dge_comment_ckan_load_package($package_id);
  if(!$package) {
    dge_ckan_error_exit(
      '<front>',
      t('Package does not exist'),
      'dge_comment_dataset_comment_add after load package'
    );
  }
  $dataset = dge_comment_dataset_load_by_package($package_id);
  if(!$dataset) {
    $dataset = dge_comment_dataset_create($package);
  }
  else {
    $dataset = dge_comment_dataset_update($dataset, $package);
  }

  if(!isset($dataset->nid)) {
    dge_ckan_error_exit(
      '<front>',
      t('Dataset does not exist'),
      'dge_comment_dataset_comment_add after load dataset'
    );
  }
  drupal_goto('comment/reply/'.$dataset->nid);
  return;
}

/**
 * Redirect to dataset
 */
function dge_comment_dataset_redirect($package_name, $fragment) {
  $url = dge_comment_build_package_url($package_name);
  $url = !empty($fragment) ? $url.'#'.$fragment : $url;
  drupal_goto($url);
}
