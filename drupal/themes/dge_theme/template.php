<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_theme (datos.gob.es)".
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

function dge_theme_preprocess_html(&$vars) {
  $parameters = drupal_get_query_parameters();
  if (array_key_exists('search_api_views_fulltext', $parameters) &&
    !empty($parameters['search_api_views_fulltext'])) {
    $vars['classes_array'][] = 'search-with-keywords';
  }

  /* ILN A11y: Add conditional stylesheets for IE. */
  drupal_add_css(path_to_theme() . '/css/base-ie.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 8', '!IE' => FALSE), 'preprocess' => FALSE));

  // GMV: TITLE MULTILANGUAGE
   if ($node = menu_get_object() && !empty($node->language_markup_enabled)) {
    $vars['title_prefix'] = array(
      '#type' => 'markup',
      '#markup' => "<div lang='$node->language_original' xml:lang='$node->language_original'>"
    );
    $vars['title_suffix'] = array(
      '#type' => 'markup',
      '#markup' => '</div>'
    );
   }

  /* ILN RDW: Add meta viewport. */
  $viewport = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1.0, minimum-scale=1.0'
    )
  );
  drupal_add_html_head($viewport, 'viewport');
}

/* ILN Styles: modify feed icon */
function dge_theme_feed_icon($variables) {
  $text = t('Subscribe to @feed-title', array('@feed-title' => $variables['title']));
  if ($image = theme('image', array('path' => drupal_get_path('theme', 'dge_theme') . '/images/ico-rss.png', 'width' => 37, 'height' => 38, 'alt' => $text))) {
    return l($image, $variables['url'], array('html' => TRUE, 'attributes' => array('class' => array('xml-icon'), 'title' => $text)));
  }
}
/* ILN A11y: Modify Breadcrumb: title + list links */
function dge_theme_breadcrumb($variables) {
    //var_dump($variables);
  $breadcrumb = $variables['breadcrumb'];
  $output = '';
  if (!empty($breadcrumb)) {
    $breadcrumb[0] = l(t('Home'), NULL);
    // Add page title to breadcrumb if its needed
      if (strpos(end($breadcrumb), '<a') !== false) {
       $breadcrumb[] = drupal_get_title();
    }
    $output .= '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= '<ul>';
    foreach($breadcrumb as $path){
      if (!empty($path)){
        $output .= '<li>' . t($path) . '</li>';
      }
    }
    $output .= '</ul>';
  }
  return $output;
}

/**
 *
 **/
function dge_theme_preprocess_page(&$variables) {
    // OPCION 1 -- UTILIZAR ADDITIONAL_ICONS EN LA TEMPLATE PAGE.TPL.PHP
    /*if (function_exists('dge_basic_get_additional_buttons')) {
      $variables['additional_icons'] = dge_basic_get_additional_buttons();
    }*/
    // OPCION 2 -- SOBREESCRIBIR FEED_ICONS SI SE NECESITA MAYOR REESTRUCTURACION
    if (function_exists('dge_basic_get_additional_buttons')) {
      $icons = dge_basic_add_additional_button();
      $output = NULL;
      if (!empty($icons) && sizeof($icons) > 0) {
        if (!isset($output)) $output = '';
        foreach($icons as $icon) {
          $output .= '<li class="feed-button-item">'.$icon.'</li>';
        }
      }
      $icons_feed = drupal_add_feed();
      if (!empty($icons_feed) && sizeof($icons_feed) > 0) {
        if (!isset($output)) $output = '';
        foreach($icons_feed as $icon) {
          $output .= '<li class="feed-button-item">'.$icon.'</li>';
        }
      }
      if (!empty($output)) {
        $output = '<ul class="catalog feed-buttons">'.$output.'</ul>';
      }
      $variables['feed_icons'] = $output;
    }

  if (isset($variables['node']->type) && $variables['node']->type == "sectores") {
    drupal_add_css(drupal_get_path('theme', 'dge_theme') . '/css/dge-sector.css');
  }
}

/* ILN RWD: Remove default system css */
function dge_theme_css_alter(&$css) {
  $exclude = array(
    'misc/vertical-tabs.css' => FALSE,
    'modules/aggregator/aggregator.css' => FALSE,
    'modules/block/block.css' => FALSE,
    'modules/book/book.css' => FALSE,
    'modules/comment/comment.css' => FALSE,
    'modules/dblog/dblog.css' => FALSE,
    'modules/field/theme/field.css' => FALSE,
    'modules/file/file.css' => FALSE,
    'modules/filter/filter.css' => FALSE,
    'modules/forum/forum.css' => FALSE,
    'modules/help/help.css' => FALSE,
    'modules/menu/menu.css' => FALSE,
    'modules/node/node.css' => FALSE,
    'modules/openid/openid.css' => FALSE,
    'modules/poll/poll.css' => FALSE,
    'modules/profile/profile.css' => FALSE,
    'modules/search/search.css' => FALSE,
    'modules/statistics/statistics.css' => FALSE,
    'modules/syslog/syslog.css' => FALSE,
    'modules/system/admin.css' => FALSE,
    'modules/system/maintenance.css' => FALSE,
    'modules/system/system.css' => FALSE,
    'modules/system/system.admin.css' => FALSE,
    'modules/system/system.base.css' => FALSE,
    'modules/system/system.maintenance.css' => FALSE,
    'modules/system/system.menus.css' => FALSE,
    'modules/system/system.messages.css' => FALSE,
    'modules/system/system.theme.css' => FALSE,
    'modules/taxonomy/taxonomy.css' => FALSE,
    'modules/tracker/tracker.css' => FALSE,
    'modules/update/update.css' => FALSE,
    'modules/user/user.css' => FALSE,
    // ILN RWD: Remove default modules css
    'sites/all/modules/contrib/panels/css/panels.css' => FALSE,
    'sites/all/modules/contrib/panels/plugins/layouts/flexible/flexible.css' => FALSE,
    'sites/all/modules/contrib/views/css/views.css' => FALSE,
    'sites/all/modules/contrib/social_media_links/social_media_links.css' => FALSE,
    'sites/all/modules/contrib/nice_menus/css/nice_menus.css' => FALSE,
    'sites/all/modules/contrib/nice_menus/css/nice_menus_default.css' => FALSE,
    'sites/all/modules/contrib/facetapi/contrib/current_search/current_search.css' => FALSE,
  );
  $css = array_diff_key($css, $exclude);
}

/**
 * Preprocess theme function to print a single record from a row, with fields
 */
function dge_theme_preprocess_views_view_fields(&$vars) {
  $view = $vars['view'];

  $node = null;
  if (isset($vars['row']->_entity_properties['entity object'])) {
    $node = $vars['row']->_entity_properties['entity object'];
  } elseif (isset($vars['row']->_field_data['nid']['entity'])){
    $node = $vars['row']->_field_data['nid']['entity'];
  }

  // Loop through the fields for this view.
  $previous_inline = FALSE;
  $vars['fields'] = array(); // ensure it's at least an empty array.
  foreach ($view->field as $id => $field) {

    // render this even if set to exclude so it can be used elsewhere.
    $field_output = $view->style_plugin->get_field($view->row_index, $id);
    $empty = $field->is_value_empty($field_output, $field->options['empty_zero']);
    if (empty($field->options['exclude']) && (!$empty || (empty($field->options['hide_empty']) && empty($vars['options']['hide_empty'])))) {
      $object = new stdClass();
      $object->handler = &$view->field[$id];
      $object->inline = !empty($vars['options']['inline'][$id]);

      $object->element_type = $object->handler->element_type(TRUE, !$vars['options']['default_field_elements'], $object->inline);
      if ($object->element_type) {
        $class = '';
        if ($object->handler->options['element_default_classes']) {
          $class = 'field-content';
        }

        if ($classes = $object->handler->element_classes($view->row_index)) {
          if ($class) {
            $class .= ' ';
          }
          $class .=  $classes;
        }

        $pre = '<' . $object->element_type;
        if ($class) {
          $pre .= ' class="' . $class . '"';
        }
        $field_output = $pre . '>' . $field_output . '</' . $object->element_type . '>';
      }

      // Protect ourself somewhat for backward compatibility. This will prevent
      // old templates from producing invalid HTML when no element type is selected.
      if (empty($object->element_type)) {
        $object->element_type = 'span';
      }

      $object->content = $field_output;
      if (isset($view->field[$id]->field_alias) && isset($vars['row']->{$view->field[$id]->field_alias})) {
        $object->raw = $vars['row']->{$view->field[$id]->field_alias};
      }
      else {
        $object->raw = NULL; // make sure it exists to reduce NOTICE
      }

      if (!empty($vars['options']['separator']) && $previous_inline && $object->inline && $object->content) {
        $object->separator = filter_xss_admin($vars['options']['separator']);
      }

      $object->class = drupal_clean_css_identifier($id);

      $previous_inline = $object->inline;
      $object->inline_html = $object->handler->element_wrapper_type(TRUE, TRUE);
      if ($object->inline_html === '' && $vars['options']['default_field_elements']) {
        $object->inline_html = $object->inline ? 'span' : 'div';
      }

      // Set up the wrapper HTML.
      $object->wrapper_prefix = '';
      $object->wrapper_suffix = '';

      if ($object->inline_html) {
        $class = '';
        if ($object->handler->options['element_default_classes']) {
          $class = "views-field views-field-" . $object->class;
        }

        if ($classes = $object->handler->element_wrapper_classes($view->row_index)) {
          if ($class) {
            $class .= ' ';
          }
          $class .= $classes;
        }

        $object->wrapper_prefix = '<' . $object->inline_html;
        if ($class) {
          $object->wrapper_prefix .= ' class="' . $class . '"';
        }
        $object->wrapper_prefix .= '>';
        $object->wrapper_suffix = '</' . $object->inline_html . '>';
      }

      // Set up the label for the value and the HTML to make it easier
      // on the template.
      $object->label = check_plain($view->field[$id]->label());
      $object->label_html = '';
      if ($object->label) {
        $object->label_html .= $object->label;
        if ($object->handler->options['element_label_colon']) {
          $object->label_html .= ': ';
        }

        $object->element_label_type = $object->handler->element_label_type(TRUE, !$vars['options']['default_field_elements']);
        if ($object->element_label_type) {
          $class = '';
          if ($object->handler->options['element_default_classes']) {
            $class = 'views-label views-label-' . $object->class;
          }

          $element_label_class = $object->handler->element_label_classes($view->row_index);
          if ($element_label_class) {
            if ($class) {
              $class .= ' ';
            }

            $class .= $element_label_class;
          }

          $pre = '<' . $object->element_label_type;
          if ($class) {
            $pre .= ' class="' . $class . '"';
          }
          $pre .= '>';

          $object->label_html = $pre . $object->label_html . '</' . $object->element_label_type . '>';
        }
      }
    //DGE i18n
    $object_class = get_class($field);
    if ($node && $node->language_markup_enabled &&
         (($object_class == 'entity_views_handler_field_text' && $field->field == 'title') ||
         ($object_class == 'views_handler_field_node' && $field->field == 'title') ||
         ($object_class == 'entity_views_handler_field_field' &&
         in_array($field->definition['type'], array('text', 'text_formatted'))) ||
         ($object_class == 'views_handler_field_field' && !empty($field->options['type']) &&
         in_array($field->options['type'], array('text_plain', 'text_default'))))){
      $tag = ($object->wrapper_suffix != '</p>')?'div':'span';
      $object->content = "<$tag lang='$node->language_original' xml:lang='$node->language_original'>".$object->content."</$tag>";
    }

      $vars['fields'][$id] = $object;
    }
  }
}

function dge_theme_preprocess_field(&$vars) {
  if($vars['element']['#field_name'] == 'field_aporta_workgroup_pre_doc') {
   $url_file = empty($vars['items']['0']['#file']->uri) ? '' : file_create_url($vars['items']['0']['#file']->uri);
   $file_name = (!empty($vars['items']['0']['#file']->description))?$vars['items']['0']['#file']->filename:$vars['items']['0']['#file']->description;
   $vars['items']['0'] = array(
     '#markup' => '<a href="'.$url_file.'" class="dge-document-link" target="_blank" title="'.t('Download the document @filename. Open a new window', array('@filename' => $file_name)).'">'.t('Access').'</a>'
   );
    return;
  }
  elseif($vars['element']['#field_name'] == 'field_aporta_workgroup_pre_pre') {
   $vars['items']['0']['#element']['title'] = t('Access');
    $vars['items']['0']['#element']['attributes']['title'] = t('Aporta presentation link. Open a new window');
    $vars['items']['0']['#element']['attributes']['class'] = 'dge-slideshare-link';
    $vars['items']['0']['#element']['attributes']['target'] = '_blank';
    return;
  }
  elseif($vars['element']['#field_name'] == 'field_aporta_workgroup_pre_vid') {
   $vars['items']['0']['#element']['title'] = t('Access');
   $vars['items']['0']['#element']['attributes']['title'] = t('Aporta video link. Open a new window');
   $vars['items']['0']['#element']['attributes']['class'] = 'dge-youtube-link';
   $vars['items']['0']['#element']['attributes']['target'] = '_blank';
   return;
  }
}

/**
* GMV: REMOVE TIPS FROM LONG TEXTS
*/
function dge_theme_filter_tips($variables) {
  if (user_is_anonymous()) {
    return '';
  } else {
    $tips = $variables['tips'];
    $long = $variables['long'];
    $output = '';

    $multiple = count($tips) > 1;
    if ($multiple) {
      $output = '<h2>' . t('Text Formats') . '</h2>';
    }

    if (count($tips)) {
      if ($multiple) {
        $output .= '<div class="compose-tips">';
      }
      foreach ($tips as $name => $tiplist) {
        if ($multiple) {
          $output .= '<div class="filter-type filter-' . drupal_html_class($name) . '">';
          $output .= '<h3>' . check_plain($name) . '</h3>';
        }

        if (count($tiplist) > 0) {
          $output .= '<ul class="tips">';
          foreach ($tiplist as $tip) {
            $output .= '<li' . ($long ? ' id="filter-' . str_replace("/", "-", $tip['id']) . '">' : '>') . $tip['tip'] . '</li>';
          }
          $output .= '</ul>';
        }

        if ($multiple) {
          $output .= '</div>';
        }
      }
      if ($multiple) {
        $output .= '</div>';
      }
    }

    return $output;
  }
}
function dge_theme_filter_tips_more_info() {
  if(user_is_anonymous()) return '';
  else return '<p>' . l(t('More information about text formats'), 'filter/tips', array('attributes' => array('target' => '_blank'))) . '</p>';
}
/**
* GMV: SORT CHANGE LIST BY SELECT
*/
function dge_theme_search_api_sorts_list(array $variables) {
  $items = array_map('render', $variables['items']);
  $options = $variables['options'];

  $return_html = '';
  if (!empty($variables['items'])) {
    $return_html .= '<div class="search-api-sorts">';
    $return_html .= '<select onchange="location = this.options[this.selectedIndex].value;" class="search-api-sorts-select" title="'.t('Sort by').'">';

    foreach ($variables['items'] as $i => $sort) {
       $name = $sort['#name'];
       $path = $sort['#path'];
       $options = $sort['#options'] + array('attributes' => array());
       $options['attributes'] += array('class' => array());

       $options = array();
       if ($sort['#active']){
          $options['query'] = $sort['#order_options']['query'];
       } else {
          $options['query'] = $sort['#options']['query'];
       }

       //Create ascending option
       $options['query']['order'] = 'asc';
       $return_html .= '<option value="';
       $selected = '';
       if ($sort['#active'] && $sort['#order_options']['query']['order'] != 'asc') {
          $selected = ' selected';
       }
       $return_html .= url($path, $options);
       $return_html .= '"'.$selected.'>';
       $return_html .= t($name).' '.t('ascending');
       $return_html .= "</option>";
       // Create descending option
       $options['query']['order'] = 'desc';
       $return_html .= '<option value="';
       $selected = '';
       if ($sort['#active'] && $sort['#order_options']['query']['order'] == 'asc') {
          $selected = ' selected';
       }
       $return_html .= url($path, $options);
       $return_html .= '"'.$selected.'>';
       $return_html .= t($name).' '.t('descending');
       $return_html .= "</option>";
    }

    $return_html .= '</select></div>';
  }

  return $return_html;
}

/**
* GMV: CHANGE CLOSE ICON
*/
function dge_theme_current_search_deactivate_widget($variables) {
  return '<span class="icon-remove" title="' . t('Remove filter') . '"> </span>';
}

/**
* GMV: ADD NUMBER OF ITEMS TO SELECTED FACETS
*/
function dge_theme_facetapi_link_active($variables) {
  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];
  // Adds count to link if one was passed.
  if (isset($variables['count'])) {
    $link_text .= ' ' . theme('facetapi_count', $variables);
  }

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => theme('facetapi_deactivate_widget', $variables),
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );
  $variables['text'] = t('!facetapi_deactivate_widget !facetapi_accessible_markup', $replacements);

  $variables['options']['html'] = TRUE;
  return theme_link($variables) . $link_text;
}

/**
* GMV: DISABLE LANGUAGE SELECTOR
*/
function dge_theme_form_user_profile_form_alter(&$form, $form_state) {
  // users that edit its profile with this theme cannot change the locale info
  unset($form['locale']);
}

/**
* GMV: REMOVE FILL IN THE BLANK TEXT
*/
function dge_theme_captcha($variables) {
  $element = $variables['element'];
  if(isset($element['captcha_widgets']['captcha_response']['#description'])) {
    unset($element['captcha_widgets']['captcha_response']['#description']);
  }
  if (!empty($element['#description']) && isset($element['captcha_widgets'])) {
    $fieldset = array(
      '#type' => 'fieldset',
      '#title' => t('CAPTCHA'),
      '#children' => drupal_render_children($element),
      '#attributes' => array('class' => array('captcha')),
    );
    return theme('fieldset', array('element' => $fieldset));
  }
  else {
    return '<div class="captcha">' . drupal_render_children($element) . '</div>';
  }
}

/**
* GMV: CHANGE INITIATIVES FOR MAP PRESENTATION
*/
function dge_theme_preprocess_node(&$variables) {
  if (!$variables['page'] && $variables['type'] == 'initiative') {
    //Change node_url
    if (isset($variables['field_initiative_link'][0]['url'])) {
      $variables['node_url'] = $variables['field_initiative_link'][0]['url'];
      hide($variables['content']['field_initiative_link']);
    }
    //Add organization to title
    if (isset($variables['field_initiative_organization'][0]['safe_value'])) {
      $variables['title'] = $variables['title'].' <span class="initiative-organization-title">('.
      $variables['field_initiative_organization'][0]['safe_value'].
      ')</span>';
      hide($variables['content']['field_initiative_organization']);
    }
    //Display Colabora con redes
    if ($variables['field_initiative_collaborate'][0]['value'] == 1) {
      $variables['content']['field_initiative_collaborate'] = array(
       '#weight' => $variables['content']['field_initiative_collaborate']['#weight'],
       '#markup' => '<div class="field field-name-field-initiative-collaborate field-type-text field-label-inline clearfix"><div class="field-items"><div class="field-item even"><div lang="" xml:lang="">'.t('Collaborate with datos.gob.es').'</div></div></div></div>');
    } else {
       hide($variables['content']['field_initiative_collaborate']);
    }

  }
}

/**
 * GMV: DELETE USELESS MENU OPTIONS FROM SITEMAP
 */
function dge_theme_site_map_menu_link(array $variables) {
  $element = $variables['element'];
  $output = '';
  if ($element['#href'] != '#login' && $element['#href'] != '#search') {
    $sub_menu = '';

    if ($element['#below']) {
      $sub_menu = drupal_render($element['#below']);
    }
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
    $output = '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
  }
  return $output;
}

/**
 * GMV: DISPLAY E-MAIL INFO
 */
function dge_theme_preprocess_user_profile(&$variables) {
  $account = $variables['elements']['#account'];
  // Helpful $user_profile variable for templates.
  foreach (element_children($variables['elements']) as $key) {
    $variables['user_profile'][$key] = $variables['elements'][$key];
  }
  $email_info = '<div class="field field-user-email field-type-text"><div class="field-label">'.t('Email').': </div><div class="field-items"><div class="field-item even">'.$account->mail.'</div></div></div>';
  $variables['user_profile']['mail'] = array( '#markup' => $email_info, '#weight' => -30);
  // Preprocess fields.
  field_attach_preprocess('user', $account, $variables['elements'], $variables);
}

/**
 * Theme a webform date element.
 */
function dge_theme_webform_number($variables) {
  $element = $variables['element'];

  if (!isset($element['#attributes']['type'])) {
    $element['#attributes']['type'] = 'number';
  }

  // Step property *must* be a full number with 0 prefix if a decimal.
  if (!empty($element['#step']) && !is_int($element['#step'] * 1)) {
    $decimals = strlen($element['#step']) - strrpos($element['#step'], '.') - 1;
    $element['#step'] = sprintf('%1.' . $decimals . 'F', $element['#step']);
  }

  // If the number is not an integer and step is undefined/empty, set the "any"
  // value to allow any decimal.
  if (empty($element['#integer']) && empty($element['#step'])) {
    $element['#step'] = 'any';
  }
  elseif ($element['#integer'] && empty($element['#step'])) {
    $element['#step'] = 1;
  }

  // Convert properties to attributes on the element if set.
  foreach (array('id', 'name', 'value', 'size', 'min', 'max', 'step') as $property) {
    if (isset($element['#' . $property]) && $element['#' . $property] !== '') {
      $element['#attributes'][$property] = $element['#' . $property];
    }
  }
  _form_set_class($element, array('form-text', 'form-number'));

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 * Returns HTML for the group list title.
 *
 * @param $variables
 *   An associative array containing:
 *   - title: The title of the group list.
 *
 * @ingroup themeable
 */
function dge_theme_current_search_group_title(array $variables) {
  return '<span class="current-search-group-title facet">' . $variables['title'] . '</span>';
}



function dge_theme_custom_breadcrumb() {
  global $language;
  $parent_candidates = dge_theme_get_parent_candidates(drupal_get_path_alias());

  if (empty($parent_candidates)) {
    return $breadcrumb;
  }

  $matched_menus = array();
  $matched_link_titles = array();
  $query = db_select('menu_links', 'ml')
    ->fields('ml', array('menu_name', 'mlid', 'link_path', 'link_title', 'depth', 'weight'))
    ->condition('link_path', $parent_candidates, 'IN')
    // Do not touch admin menu.
    ->condition('menu_name', 'management', '!=')
    // Only consider normal, visible menu links.
    ->condition('hidden', 0);

  if (module_exists('i18n_menu')) {
    $query->condition('language', $language->language);
  }

  $results = $query->execute();

  foreach ($results as $record) {
    // If there is more than one matched link in a menu,
    // use the deepest, heaviest.
    if (!isset($matched_menus[$record->menu_name]) || $record->depth > $matched_menus[$record->menu_name]['depth'] || ($record->depth == $matched_menus[$record->menu_name]['depth'] && $record->weight > $matched_menus[$record->menu_name]['weight'])) {
      $matched_menus[$record->menu_name]['link_path'] = $record->link_path;
      $matched_menus[$record->menu_name]['depth'] = $record->depth;
      $matched_menus[$record->menu_name]['weight'] = $record->weight;
    }

    // Get the Link Title if it can be found in a menu item.
    if ($record->link_title && !isset($matched_link_titles[$record->link_path])) {
      $matched_link_titles[$record->link_path] = $record->link_title;
      if (module_exists('i18n_menu')) {
        $matched_link_titles[$record->link_path] = _i18n_menu_link_title((array)$record, $language->language);
      }
    }
  }

  // Remove current page from breadcrumb.
  array_pop($parent_candidates);

  foreach ($parent_candidates as $link_path) {
    // If the page title is found on a menu item, use it.
    if (isset($matched_link_titles[$link_path])) {
      $breadcrumb[] = l($matched_link_titles[$link_path], $link_path);
    }
    // Otherwise, use slow method to find out the title of a page.
    elseif ($menu_item = menu_get_item($link_path)) {
      $breadcrumb[] = l($menu_item['title'], $link_path);
    }
  }

  return $breadcrumb;
}

/**
 * Returns an array of parent candidates
 *
 * e.g. given the argument 'foo/bar/zee', this returns an array of
 * internal Drupal paths for 'foo', 'foo/bar', 'foo/bar/zee'.
 *
 * @param string $path
 *   A Drupal path alias.
 *
 * @return array
 *   An array of internal Drupal paths.
 */
function dge_theme_get_parent_candidates() {
  global $language;
  $menu_string = array();
  $cont=0;

  foreach(drupal_get_breadcrumb() as $menu_item) {
    $link_element = explode('"', $menu_item)[1];
    if ($link_element === '/' . $language->language) { //Tratamiento de la home
      continue;
    }
    if (arg(0)=="node") { // Tratamiento de nodo
      $node = node_load(arg(1));
      //print_r($node->type);
      if($node->type == 'bulletin') {
        $node_reference = 'boletines';
      }
      elseif ($node->type == 'blog' ) {
        $node_reference = 'noticias';
      }
      elseif ($node->type == 'event') {
        $node_reference = 'eventos';
      }
      elseif ($node->type == 'talk') {
        $node_reference = 'comunidad-risp';
      }
      elseif ($node->type == 'app') {
        $node_reference = 'aplicaciones';
      }
      elseif ($node->type == 'aporta') {
        $node_reference = 'encuentros-aporta';
      }
      elseif ($node->type == 'success') {
        $node_reference = 'casos-exito';
      }
      elseif ($node->type == 'doc') {
        $node_reference = 'documentacion';
      }
      elseif ($node->type == 'request') {
        $node_reference = 'peticiones-datos';
      }
      elseif ($node->type == 'current_aporta') {
        $node_reference = 'encuentros-aporta';
      }
      elseif ($node->type == 'blog_blog') {
        $node_reference = 'blog';
      }
      elseif ($node->type == 'sectores') {
        $node_reference = '<void>';
      }
      elseif ($node->type == 'challenge_aporta') {
        $node_reference = 'desafios-aporta';
      }
      elseif ($node->type == 'aporta_awards') {
        $node_reference = 'premios-aporta';
      }
      else {
        $node_reference = "node/" . $node->tnid;
      }
      $menu_string[] = _dge_theme_get_menu_name($node_reference);
      continue;
    }
    //Páginas
    if($cont === 0) {
      $cont++;
      if(arg(1) == ''){
        $node_reference = arg(0);
        $menu_string[] = _dge_theme_get_menu_name($node_reference, true);
      }
      //AQUÍ SE ESTÁ IMPRIMIENDO LOS TÍTULOS EN ESPAÑOL, MIRANDO DGE_THEME_GET_MENU_NAME
      if($link_element == '/' . $language->language . '/user'){
        if(!empty(arg(2))){
          $node_reference = 'admin/dashboard/' . arg(2);
          $menu_string[] = _dge_theme_get_menu_name($node_reference, true);
        }
      }
      continue;
    }
    if($cont === 1) {
      $node_reference = arg(0) . '/' . arg(1);
      $cont++;
      $menu_string[] = _dge_theme_get_menu_name($node_reference, true);

      continue;
    }
  }

  $return = '';
  if($menu_string[0] === $menu_string[1]){
    $return = $menu_string[0];
  } else {
    $return = implode(' | ', $menu_string);
  }

  if ($return == ''){
    $return = 'home';
  }

  return $return;
}

function _dge_theme_get_menu_name($path, $page = FALSE) {
  $menu_text = '';

  $query = db_select('menu_links', 'ml')
    ->fields('ml')
    ->condition('link_path', $path, '=')
    ->condition('menu_name', 'main-menu', '=')
    ->execute()
    ->fetchAll();
  $menu_text = $query[0]->link_title;

  //Parche SDA-359 Premis aporta
  if($menu_text=="Premis Aporta"){
    $menu_text="Premios Aporta";
  }

  if(!$page){

    if ($query[0]->plid!=0) {
      $query = db_select('menu_links', 'ml')
        ->fields('ml')
        ->condition('mlid', $query[0]->plid, '=')
        ->condition('menu_name', 'main-menu', '=')
        ->execute()
        ->fetchAll();
      $menu_text = $query[0]->link_title . ' | ' . $menu_text;
    }
  } else {
    while ($query[0]->plid!=0) {
      $query = db_select('menu_links', 'ml')
        ->fields('ml')
        ->condition('mlid', $query[0]->plid, '=')
        ->condition('menu_name', 'main-menu', '=')
        ->execute()
        ->fetchAll();
      $menu_text = $query[0]->link_title . ' | ' . $menu_text;
    }
  }

    // añade el evento/noticia/boletin que se esta visualizando
  $fixpath = '';
  if (arg(0) == "node") { // Tratamiento de nodo
    $node = node_load(arg(1));
    if (isset($node->tnid)) {
      $node = node_load($node->tnid);
    }
    if ($node->type == 'aporta_awards' || $node->type == 'challenge_aporta' || $node->type == 'sectores' || $node->type == 'blog_blog' || $node->type == 'current_aporta' || $node->type == 'bulletin' || $node->type == 'blog' || $node->type == 'event' || $node->type == 'talk' || $node->type == 'app'|| $node->type == 'aporta'|| $node->type == 'success'|| $node->type == 'doc'|| $node->type == 'request'){
      $fixpath = $node->title;
      if ($node->type == 'current_aporta') {
        $fixpath .= ": " . $node->field_aporta_subtitle[und][0][value];
      }
    }
  }
  if (!empty($fixpath)) {
    return $menu_text . ' | ' . $fixpath;
  }
  return $menu_text;
}

/**
 *
 */
function dge_theme_preprocess_entity(&$vars) {
  static $_slide_position;
  global $slide_position;
  if ($vars['entity_type'] == 'paragraphs_item' && $vars['elements']['#bundle'] == 'carousel_4') {
    $_slide_position = (!isset($_slide_position)) ? 0 : $_slide_position + 1;
    $slide_position = $_slide_position;
  }

}

/**
 * Default theme function for all RSS rows.
 */
function dge_theme_preprocess_views_view_row_rss(&$vars) {
  $item = &$vars['row'];
  $view= &$vars['view'];

  $id = $item->elements[2]['value'];
  $node	= node_load($id);
  $flag = $node->field_feed_included['und'][0]['value'];

  if($view->name == 'feed_view' && ($flag != 1)){
    $vars['item_elements'] = '';
    $vars['title'] = '';
    $vars['link'] = '';
    $vars['description'] = '';
  } else {
	  $vars['item_elements'] = empty($item->elements) ? '' : format_xml_elements($item->elements);
  }
}

?>
