<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_i18n (datos.gob.es)".
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
 * Overview page for a node's translations.
 *
 * @param $node
 *   Node object.
 */
function dge_i18n_node_translation_overview($node) {
  include_once DRUPAL_ROOT . '/includes/language.inc';
  module_load_include('inc', 'i18n_node', 'i18n_node.pages');

  if (!empty($node->tnid)) {
    // Already part of a set, grab that set.
    $tnid = $node->tnid;
    $translations = translation_node_get_translations($node->tnid);
  }
  else {
    // We have no translation source nid, this could be a new set, emulate that.
    $tnid = $node->nid;
    $translations = array($node->language => $node);
  }

  $type = variable_get('translation_language_type', LANGUAGE_TYPE_INTERFACE);
  $header = array(t('Language'), t('Title'), t('Status'), t('Language original'), t('Operations'));

  // Modes have different allowed languages
  foreach (i18n_node_language_list($node) as $langcode => $language_name) {
    if ($langcode == LANGUAGE_NONE) {
      // Never show language neutral on the overview.
      continue;
    }
    $options = array();
    if (isset($translations[$langcode])) {
      // Existing translation in the translation set: display status.
      // We load the full node to check whether the user can edit it.
      $translation_node = node_load($translations[$langcode]->nid);
      $path = 'node/' . $translation_node->nid;
      $title = i18n_node_translation_link($translation_node->title, $path, $langcode);
      if (node_access('update', $translation_node)) {
        $text = t('edit');
        $path = 'node/' . $translation_node->nid . '/edit';
        $options[] = i18n_node_translation_link($text, $path, $langcode);
      }
      $status = $translation_node->status ? t('Published') : t('Not published');
      $status .= $translation_node->translate ? ' - <span class="marker">' . t('outdated') . '</span>' : '';
      if ($translation_node->nid == $tnid) {
        $language_name = t('<strong>@language_name</strong> (source)', array('@language_name' => $language_name));
      }
      $dge_i18n = dge_i18n_db_select('node', $translation_node->nid );
      $language_original = isset($dge_i18n['language_original']) ? $dge_i18n['language_original'] : 'n/a';
    }
    else {
      // No such translation in the set yet: help user to create it.
      $title = t('n/a');
      if (node_access('create', $node->type)) {
        $text = t('add translation');
        $path = 'node/add/' . str_replace('_', '-', $node->type);
        $query = array('query' => array('translation' => $node->nid, 'target' => $langcode));
        $options[] = i18n_node_translation_link($text, $path, $langcode, $query);
      }
      $status = t('Not translated');
      $language_original = 'n/a';
    }
    $rows[] = array($language_name, $title, $status, $language_original, implode(" | ", $options));
  }

  drupal_set_title(t('Translations of %title', array('%title' => $node->title)), PASS_THROUGH);

  $build['translation_node_overview'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  if (user_access('administer content translations')) {
    $build['translation_node_select'] = drupal_get_form('i18n_node_select_translation', $node, $translations);
  }
  $build['translation_node_language_original_reset'] = array(
    '#theme' => 'link',
    '#text' => 'Reset language original',
    '#path' => 'node/'.$tnid.'/translate/reset_original',
    '#options' => array('attributes' => array('title' => 'Reset language original'), 'html' => false),
  );
  if (user_access('access alter dge_i18n_node')) {
     $build['translation_node_language_switcher_break'] = array(
      '#markup' => t('<br />'),
     );
     $build['translation_node_language_switcher'] = array(
       '#theme' => 'link',
       '#text' => 'Change DGE i18n language information',
       '#path' => 'node/'.$node->nid.'/translate/dge_i18n_node',
       '#options' => array('attributes' => array('title' => 'Change DGE i18n language information'), 'html' => false),
     );
  }
  return $build;
}

function dge_i18n_language_original_reset_form($form, &$form_state, $node) {

  if (!empty($node->tnid)) {
    // Already part of a set, grab that set.
    $tnid = $node->tnid;
    $translations = translation_node_get_translations($node->tnid);
  }
  else {
    // We have no translation source nid, this could be a new set, emulate that.
    $tnid = $node->nid;
    $translations = array($node->language => $node);
  }

  $form['#translations'] = $translations;
  $form['nid'] = array('#type' => 'value', '#value' => $node->tnid);
  return confirm_form($form,
    t('Are you sure you want to delete language original field for %title and all translations?', array('%title' => $node->title)),
    'node/' . $node->tnid,
    t('This action cannot be undone. You must create all translations manually after delete this field.'),
    t('Delete'),
    t('Cancel')
  );

}

function dge_i18n_language_original_reset_form_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $nid = $form_state['values']['nid'];
    $translations = $form['#translations'];
    foreach($translations as $translation) {
      dge_i18n_db_delete('node', $translation->nid);
    }
    $form_state['redirect'] = 'node/'.$nid.'/translate';
  }
  else {
    $form_state['redirect'] = '<front>';
  }
}

/**
 * Callback for term translation tab.
 *
 * @param $type
 *   Should be always 'taxonomy_term'
 * @pram $term
 *   Taxonomy term object
 */
function dge_i18n_taxonomy_term_translation_page($type, $term) {
  module_load_include('admin.inc', 'i18n_taxonomy');
  $vocabulary = taxonomy_vocabulary_load($term->vid);
  $translation_set = !empty($term->i18n_tsid) ? i18n_translation_set_load($term->i18n_tsid) : NULL;

  $translation_overview = dge_i18n_taxonomy_translation_term_overview($term);

  $translation_term_form = drupal_get_form('i18n_taxonomy_translation_term_form', $vocabulary, $translation_set, $term);

  return $translation_overview + $translation_term_form;
}

/**
 * Callback for term translation tab.
 */
function dge_i18n_taxonomy_translation_term_overview($term) {
  include_once DRUPAL_ROOT . '/includes/language.inc';
  module_load_include('inc', 'i18n_taxonomy', 'i18n_taxonomy.pages');
  if ($term->i18n_tsid) {
    // Already part of a set, grab that set.
    $i18n_tsid = $term->i18n_tsid;
    $translation_set = i18n_translation_set_load($term->i18n_tsid);
    $translations = $translation_set->get_translations();
  }
  else {
    // We have no translation source nid, this could be a new set, emulate that.
    $i18n_tsid = $term->tid;
    $translations = array($term->language => $term);
  }
  $type = variable_get('translation_language_type', LANGUAGE_TYPE_INTERFACE);
  $header = array(t('Language'), t('Title'), t('Language original'), t('Operations'));

  foreach (i18n_language_list() as $langcode => $language_name) {
    $options = array();
    if (isset($translations[$langcode])) {
      // Existing translation in the translation set: display status.
      // We load the full node to check whether the user can edit it.
      $translation_term = taxonomy_term_load($translations[$langcode]->tid);
      $path = 'taxonomy/term/' . $translation_term->tid;
      $title = l($translation_term->name, $path);

      $options['edit'] = array(
        '#type' => 'link',
        '#title' => t('edit'),
        '#href' => $path . '/edit',
        '#options' => array(
          'query' => drupal_get_destination(),
        ),
      );

      if ($translation_term->tid == $i18n_tsid) {
        $language_name = t('<strong>@language_name</strong> (source)', array('@language_name' => $language_name));
      }
      $dge_i18n = dge_i18n_db_select('taxonomy_term', $translation_term->tid );
      $language_original = isset($dge_i18n['language_original']) ? $dge_i18n['language_original'] : 'n/a';
    }
    else {
      // No such translation in the set yet: help user to create it.
      $title = t('n/a');
      $options['add'] = array(
        '#type' => 'link',
        '#title' => t('add translation'),
        '#href' => 'admin/structure/taxonomy/' . $term->vocabulary_machine_name . '/add',
        '#options' => array(
          'query' => array('translation' => $term->tid, 'target' => $langcode) + drupal_get_destination()
        ),
      );
      $language_original = 'n/a';
    }
    $rows[$langcode] = array(
      'language' => $language_name,
      'title' => $title,
      'language_original' => $language_original,
      'operations' => array('data' => $options),
    );
  }

  drupal_set_title(t('Translations of term %title', array('%title' => $term->name)), PASS_THROUGH);

  $build['translation_overview'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  return $build;
}

function dge_i18n_language_node_vars_form($form, &$form_state, $node) {
  if(dge_i18n_check_node_autotranslation($node)){
    $form['dge_i18n_node_language'] = array(
      '#markup' => t('<strong>Node language:</strong> '.$node->language),
    );

    $languages = language_list();
    $lang_options = array();
    foreach ($languages as $lang => $language) {
      $lang_options[$lang] = $lang;
    }
    $form['dge_i18n_language_original'] = array(
      '#title' => t('Language original'),
      '#type' => 'select',
      '#options' => $lang_options,
      '#default_value' => (!empty($node->language_original))?$node->language_original:$node->language,
    );
    $form['dge_i18n_markup_enabled'] = array(
      '#type' =>  'checkbox',
      '#title' => t('Markup enabled'),
      '#default_value' => (!empty($node->language_markup_enabled))?$node->language_markup_enabled:FALSE,
    );
    $form['submit'] = array(
       '#type' => 'submit',
       '#value' => t('Submit'),
    );
  }
  return $form;
}

function dge_i18n_language_node_vars_form_validate($form, &$form_state) {
   $languages = language_list();
   $language_keys = array_keys($languages);
   if (empty($form_state['values']['dge_i18n_language_original']) || ! in_array($form_state['values']['dge_i18n_language_original'], $language_keys)) {
     form_set_error('dge_i18n_language_original', t('Wrong language.'));
   }
}

function dge_i18n_language_node_vars_form_submit($form, &$form_state) {
   if ($node = menu_get_object()) {
     $node->language_original = $form_state['values']['dge_i18n_language_original'];
     $node->language_markup_enabled = (!empty($form_state['values']['dge_i18n_markup_enabled']))?$form_state['values']['dge_i18n_markup_enabled']:FALSE;//$form_state['values']['dge_i18n_markup_enabled'];
     $node->dge_i18n_flag_updated = true;
     node_save($node);
     dge_i18n_db_update('node', $node->nid, $node->language_original);
     drupal_set_message(t('DGE i18n language information modified'));
     drupal_goto('node/'. $node->nid. '/translate');
   }
}
