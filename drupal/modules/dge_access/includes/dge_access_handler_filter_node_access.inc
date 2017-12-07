<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_access (datos.gob.es)".
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
 * Filter by node_access records.
 *
 * @ingroup views_filter_handlers
 */
class dge_access_handler_filter_node_access extends views_handler_filter {
  function admin_summary() { }
  function operator_form(&$form, &$form_state) { }
  function can_expose() {
    return FALSE;
  }

  function options_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Node access'),
      '#description' => t('Level of access to a node'),
      '#options' => array(
        'view' => t('View'),
        'update' => t('Edit'),
        'delete' => t('Delete'),
      ),
      '#default_value' => $this->value ? $this->value : 'view',
    );
    $form['caution'] = array(
      '#markup' => t('Note: for Edit and Delete access, <strong>only node access grants</strong> are checked. Modules can override node access grants to allow or deny actions, so this check does not necessarily reflect whether the user can actually perform the Edit or Delete action.'),
    );
  }

  /**
   * See _node_access_where_sql() for a non-views query based implementation.
   */
  function query() {
    if (!user_access('administer nodes') && module_implements('node_grants')) {
      $access = !empty($this->value) ? $this->value : 'view';
      $table = $this->ensure_my_table();
      $grants = db_or();
      foreach (node_access_grants($access) as $realm => $gids) {
        foreach ($gids as $gid) {
          $grants->condition(db_and()
            ->condition($table . '.gid', $gid)
            ->condition($table . '.realm', $realm)
          );
        }
      }

      $this->query->add_where('AND', $grants);
      $this->query->add_where('AND', $table . '.grant_'. $access, 1, '>=');
    }
  }
}
