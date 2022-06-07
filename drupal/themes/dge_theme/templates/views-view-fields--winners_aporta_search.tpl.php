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

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
  <span class = "dge-list__img">
     <?php print $fields['field_image']->content; ?>
  </span>
  <strong class = "dge-list__title">
     <?php print $fields['title2']->content; ?>
     <?php if ($fields['field_aporta_subtitle']): ?>
        <?php print $fields['field_aporta_subtitle']->content;?>
     <?php endif; ?>
  </strong>
  <span class="dge-list__date">
  <?php print $fields['field_aporta_date']->content;?>
  <?php if ($fields['field_collaborator']->content): ?>
  <?php echo " - ";?>
     <?php print $fields['field_collaborator']->content;?>
  <?php endif; ?>
  </span>
  <div class="dge-list__desc">
    <?php print $fields['body']->content;?>
  </div>
    <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>