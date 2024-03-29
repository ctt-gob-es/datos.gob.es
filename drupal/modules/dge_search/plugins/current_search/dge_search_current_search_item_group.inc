<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_search (datos.gob.es)".
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
 * Current search item plugin that displays the active facet items in a group.
 *
 * This plugins displays displays active items grouped by field in a horizontal
 * list.
 *
 * Extend original CurrentSearchGroup with language special markup for accesibility
 * @see dge_i18n
 */
class DGESearchCurrentSearchGroup extends CurrentSearchGroup {

  /**
   * Implements CurrentSearchItem::execute().
   */
  public function execute(FacetapiAdapter $adapter) {
    $groups = array();

    // Makes sure facet builds are initialized.
    $adapter->processFacets();

    // Adds other current search module's CSS.
    $path = drupal_get_path('module', 'current_search');
    drupal_add_css($path . '/current_search.css');

    // Adds active facets to the current search block.
    $searcher = $adapter->getSearcher();
    foreach ($adapter->getAllActiveItems() as $item) {
      $facet_name = $item['facets'][0];
      $facet_value = $item['value'];
      $groups[$facet_name][$facet_value] = $item;
    }

    // Initializes links attributes, adds rel="nofollow" if configured.
    $attributes = ($this->settings['nofollow']) ? array('rel' => 'nofollow') : array();

    // Gets the translated pattern with token replacements in tact.
    $field_pattern = $this->translate('field_pattern', $this->settings['field_pattern']);

    // Iterates over groups, builds list.
    $build = array();
    foreach ($groups as $facet_name => $group) {
      $items = array();

      // Builds list items.
      foreach ($group as $item) {
        $markup = $adapter->getMappedValue($item['facets'][0], $item['value']);

        $text = empty($markup['#html']) ? check_plain($markup['#markup']) : $markup['#markup'];

        // Create markup accesibility
        if($adapter->getEnabledFacets()[$item['facets'][0]]['field type'] == 'taxonomy_term') {
          $term = taxonomy_term_load($item['value']);

          if(isset($term->language_markup_enabled) && $term->language_markup_enabled)
            $text = dge_i18n_get_markup_html_wrapper($term, $text);
        }
        if ($facet_name == 'field_initiative_sparql:url') {
          $text = 'SPARQL';
        }

        $variables = array(
          'text' => $text,
          'path' => $this->getFacetPath($item, $adapter),
          'options' => array(
            'attributes' => $attributes,
            'html' => TRUE,
            'query' => $this->getQueryString($item, $adapter),
          ),
        );
        $items[] = theme('current_search_link_active', $variables);
      }

      // If there are items, add the render array.
      if ($items) {
        $build[$facet_name]['#theme_wrappers'] = array('current_search_group_wrapper');
        $build[$facet_name]['#id'] = drupal_html_id("current-search-group-$searcher-{$this->configName}-{$facet_name}");
        $build[$facet_name]['#facet_name'] = $facet_name;

        // Performs token replacemenets and themes the group title.
        $data = array('facetapi_facet' => facetapi_facet_load($facet_name, $searcher));
        $facet_field = field_info_field($data['facetapi_facet']['field']);
        if (isset($facet_field['bundles']['node'][0])) {
           $field = field_info_instance('node', $facet_field['field_name'], $facet_field['bundles']['node'][0]);
           $title = i18n_field_translate_property($field, 'label').':';
        } else {
           $title = filter_xss(token_replace($field_pattern, $data));
        }
        if ($facet_name == 'field_initiative_sparql:url') {
          $title = t('Query point').':';
        }
        $build[$facet_name]['title']['#markup'] = theme('current_search_group_title', array('title' => $title));

        // Builds the list.
        $build[$facet_name]['list'] = array(
          '#theme' => 'item_list',
          '#items' => $items,
          '#attributes' => array('class' => array('inline')),
        );
      }
    }

    return $build;
  }

  /**
   * Implements CurrentSearchItem::settingsForm().
   */
  public function settingsForm(&$form, &$form_state) {

    $form['field_pattern'] = array(
      '#type' => 'textfield',
      '#title' => t('Field pattern'),
      '#default_value' => $this->settings['field_pattern'],
      '#maxlength' => 255,
      '#description' => t('The pattern of the field label preceeding the links. Token replacement patterns are allowed.'),
    );

    $form['nofollow'] = array(
      '#type' => 'checkbox',
      '#title' => t('Prevent crawlers from following active item links'),
      '#default_value' => $this->settings['nofollow'],
      '#description' => t('Add the <code>rel="nofollow"</code> attribute to active item links to maximize SEO by preventing crawlers from indexing duplicate content and getting stuck in loops.'),
    );

    // Adds token tree.
    $form['tokens'] = $this->getTokenTree(array('facetapi_facet'));
  }

  /**
   * Implements CurrentSearchItem::getDefaultSettings().
   */
  public function getDefaultSettings() {
    return array(
      'field_pattern' => '[facetapi_facet:facet-label]:',
      'nofollow' => 1,
    );
  }
}
