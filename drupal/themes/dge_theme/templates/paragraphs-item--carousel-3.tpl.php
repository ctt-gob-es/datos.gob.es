<?php

/**
 	* Copyright (C) 2022 Entidad P�blica Empresarial Red.es
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
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
 hide($content['field_menu_title']);
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes;?>>
   <?php if (isset($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_event_image'])): ?>
   <?php print render ($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_event_image']);?>
   <?php endif;?>
   <?php if (isset($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_blog_image'])): ?>
   <?php print render ($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_blog_image']);?>
   <?php endif;?>
   <?php if (isset($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_aporta_image'])): ?>
   <?php print render ($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_aporta_image']);?>
   <?php endif;?>
  <?php if (isset($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_app_image'])): ?>
  <?php print render ($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_app_image']);?>
  <?php endif;?>
  <?php if (isset($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_image'])): ?>
  <?php print render ($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_image']);?>
  <?php endif;?>
  <?php if (isset($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_doc_image'])): ?>
  <?php print render ($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_doc_image']);?>
  <?php endif;?>
  <?php if (isset($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_success_image'])): ?>
  <?php print render ($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_success_image']);?>
  <?php endif;?>
  <?php if (isset($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_talk_image'])): ?>
  <?php print render ($content['field_reference'][0]['node'][$content['field_reference']['#items'][0]['target_id']]['field_talk_image']);?>
  <?php endif;?>
	<?php $node = node_load($content['field_reference']['#items'][0]['target_id']);
	$nid = $content['field_reference']['#items'][0]['target_id'];
	$options = array('absolute' => TRUE);
	$url = url('node/' . $nid, $options);?>
    <div class="titleMenu"><?php print $content['field_menu_title'][0]['#markup']?></div>
	<div class="contentMenu"> <a class="title" href='<?php echo $url?>'><?php echo $node->title?></a></div>

 </div>
</div>