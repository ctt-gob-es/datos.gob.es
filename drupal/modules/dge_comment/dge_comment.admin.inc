<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * Menu callback; present an administrative comment listing.
 */
function dge_comment_admin($type = 'new') {
  global $user;
  $edit = $_POST;

  if(user_access('administer comments')) {
    drupal_set_message(t('You have full access to administer comments'));
    drupal_goto('admin/content/comment');
  }
  if(!dge_access_get_user_organization($user)) {
    drupal_set_message(t('Do not have organization access'));
    drupal_goto('<front>');
  }
  if (isset($edit['operation']) && ($edit['operation'] == 'delete') && isset($edit['comments']) && $edit['comments']) {
    return drupal_get_form('comment_multiple_delete_confirm');
  }
  else {
    return drupal_get_form('dge_comment_admin_overview', $type);
  }
}

/**
 * Form builder for the comment overview administration form.
 *
 * @param $arg
 *   Current path's fourth component: the type of overview form ('approval' or
 *   'new').
 *
 * @ingroup forms
 * @see comment_admin_overview_validate()
 * @see comment_admin_overview_submit()
 * @see theme_comment_admin_overview()
 */
function dge_comment_admin_overview($form, &$form_state, $arg) {
  global $user;

  $organization_tid = dge_access_get_user_organization($user);
  // Build an 'Update options' form.
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update options'),
    '#attributes' => array('class' => array('container-inline views-exposed-form')),
  );

  if ($arg == 'approval') {
    $options['publish'] = t('Publish the selected comments');
  }
  else {
    $options['unpublish'] = t('Unpublish the selected comments');
  }
  //$options['delete'] = t('Delete the selected comments');

  $form['options']['operation'] = array(
    '#type' => 'select',
    '#title' => t('Operation'),
    '#title_display' => 'invisible',
    '#options' => $options,
    '#default_value' => 'publish',
  );
  $form['options']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );

  // Load the comments that need to be displayed.
  $status = ($arg == 'approval') ? COMMENT_NOT_PUBLISHED : COMMENT_PUBLISHED;
  $header = array(
    'subject' => array('data' => t('Subject'), 'field' => 'subject'),
    'author' => array('data' => t('Author'), 'field' => 'name'),
    'posted_in' => array('data' => t('Posted in'), 'field' => 'node_title'),
    'changed' => array('data' => t('Updated'), 'field' => 'c.changed', 'sort' => 'desc'),
    'operations' => array('data' => t('Operations')),
  );

  $query = db_select('comment', 'c')->extend('PagerDefault')->extend('TableSort');
  $query->join('node', 'n', 'n.nid = c.nid');
  $query->join('users', 'u', 'u.uid = n.uid');
  $query->join('profile', 'p', 'p.uid = u.uid');
  $query->join('field_data_field_root_agency', 'fdfra', 'fdfra.entity_id = p.pid');
  $query->condition('field_root_agency_tid',$organization_tid,'=');
  $query->addField('n', 'title', 'node_title');
  $query->addField('n', 'type');
  $query->addTag('node_access');
  $result = $query
    ->fields('c', array('cid', 'subject', 'name', 'changed'))
    ->condition('c.status', $status)
    ->limit(50)
    ->orderByHeader($header)
    ->execute();

  $cids = array();

  // We collect a sorted list of node_titles during the query to attach to the
  // comments later.
  foreach ($result as $row) {
    $cids[] = $row->cid;
    $node_titles[] = $row->node_title;
    $node_types[] = $row->type;
  }
  $comments = comment_load_multiple($cids);

  // Build a table listing the appropriate comments.
  $options = array();
  $destination = drupal_get_destination();

  foreach ($comments as $comment) {
    // Remove the first node title from the node_titles array and attach to
    // the comment.
    $comment->node_title = array_shift($node_titles);
    $node_type = array_shift($node_types);
    $url = 'node/' . $comment->nid;
    if($node_type == 'dataset') {
      $url = dge_comment_build_package_url(dge_comment_dataset_get_package_name(node_load($comment->nid)));
    }
    $comment_body = field_get_items('comment', $comment, 'comment_body');
    $edit_comments = array();
    if(dge_comment_access('edit', $comment)) {
      $edit_comments['data'] = array(
        '#type' => 'link',
        '#title' => t('edit'),
        '#href' => 'comment/' . $comment->cid . '/edit',
        '#options' => array('query' => $destination),
      );
    }
    $options[$comment->cid] = array(
      'subject' => $comment->subject,
      'author' => theme('username', array('account' => $comment)),
      'posted_in' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $comment->node_title,
          '#href' => $url,
        ),
      ),
      'changed' => format_date($comment->changed, 'short'),
      'operations' => $edit_comments,
    );
  }

  $form['comments'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No comments available.'),
    '#attributes' => array('class' => array('views-table cols-8')),
  );

  $form['pager'] = array('#theme' => 'pager');
  module_load_include('inc', 'comment', 'comment.admin');
  $form['#validate'] = array('comment_admin_overview_validate');
  $form['#submit'] = array('comment_admin_overview_submit','dge_comment_admin_overview_submit');

  return $form;
}

/**
 * Returns a menu title which includes the number of unapproved comments for organization users.
 */
function dge_comment_count_unpublished() {
  global $user;
  $organization_tid = dge_access_get_user_organization($user);
  if(!$organization_tid) return t('Unapproved comments');
  $count = db_query('
  	SELECT COUNT(cid) FROM {comment} c
  	INNER JOIN {node} n ON n.nid = c.nid
  	INNER JOIN {users} u ON u.uid = n.uid
  	INNER JOIN {profile} p ON p.uid = u.uid
  	INNER JOIN {field_data_field_root_agency} fdfra ON fdfra.entity_id = p.pid
  	WHERE fdfra.field_root_agency_tid = :organization_tid AND c.status = :status', array(
    ':organization_tid' => $organization_tid,
    ':status' => COMMENT_NOT_PUBLISHED,
  ))->fetchField();
  return t('Unapproved comments (@count)', array('@count' => $count));
}


/**
 * @see comment_admin_overview form submissions.
 *
 * Execute the chosen 'Update option' on the selected comments, such as
 * publishing, unpublishing or deleting.
 */
function dge_comment_admin_overview_submit($form, &$form_state) {
  $form_state['rebuild'] = true;
  $form_state['redirect'] = 'admin/dashboard/comment';
}

function dge_comment_admin_settings() {
   $form['dge_comment_texts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Common texts'),
   );
   $form['dge_comment_texts']['dge_comment_title'] = array(
     '#type' => 'textfield',
     '#title' => t('Comments block title'),
     '#required' => false,
     '#description' => t('The text must be in English'),
     '#default_value' => variable_get('dge_comment_title', 'Comments'),
   );
   $form['dge_comment_texts']['dge_comment_no_comments'] = array(
     '#type' => 'textfield',
     '#title' => t('No comments text'),
     '#required' => false,
     '#description' => t('The text must be in English'),
     '#default_value' => variable_get('dge_comment_no_comments', 'No comments'),
   );
   $form['dge_comment_texts']['dge_comment_new_comment'] = array(
     '#type' => 'textfield',
     '#title' => t('Add new comment link text'),
     '#required' => false,
     '#description' => t('The text must be in English'),
     '#default_value' => variable_get('dge_comment_new_comment', 'Add new comment'),
   );

   $form['dge_comment_form'] = array(
    '#type' => 'fieldset',
    '#title' => t('Form texts'),
   );
   $form['dge_comment_form']['dge_comment_anonymous_conditions'] = array(
     '#type' => 'textfield',
     '#title' => t('Add explanation for anonymous name'),
     '#required' => false,
     '#description' => t('The text must be in English'),
     '#default_value' => variable_get('dge_comment_anonymous_conditions', 'If this field is empty \'Anonymous\' will be shown on the name field.'),
   );
   $defaults = array(
      'value' => '',
      'format' => 'full_html',
   );
   $dge_comment_introducing_text = variable_get('dge_comment_introducing_text',
      $defaults);
   $form['dge_comment_form']['dge_comment_introducing_text'] = array(
      '#type' => 'text_format',
      '#title' => t('Explanatory text'),
      '#description' => t('The text must be in English'),
      '#default_value' => $dge_comment_introducing_text['value'],
      '#required' => false,
      '#format' => 'full_html',
   );

   $form['dge_comment_notification'] = array(
    '#type' => 'fieldset',
    '#title' => t('Messages after post a new comment'),
   );
   $form['dge_comment_notification']['dge_comment_anonymous_message'] = array(
     '#type' => 'textfield',
     '#maxlength' => 256,
     '#title' => t('Needs review comment - Anonymous users'),
     '#description' => t('The text must be in English'),
     '#required' => false,
     '#default_value' => variable_get('dge_comment_anonymous_message', 'Thank you for posting a new comment on datos.gob.es portal. Your comment has been queued for review by site administrators and will be published after approval.'),
   );
   $form['dge_comment_notification']['dge_comment_approved_message'] = array(
     '#type' => 'textfield',
     '#maxlength' => 256,
     '#title' => t('Approved by default - Registered users'),
     '#description' => t('The text must be in English'),
     '#required' => false,
     '#default_value' => variable_get('dge_comment_approved_message', 'Thank you for posting a new comment on datos.gob.es portal. Your comment has been posted.'),
   );


  return system_settings_form($form);
}
