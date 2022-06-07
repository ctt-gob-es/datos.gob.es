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
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */


 /* ILN:
 1. Control Cite in CSS class container "dge-cite1 / dge-cite0"
 2. Control image_link and image in case image exists and image and image_link exists
 */
?>
<?php
  if(isset($content['field_bulletin_parag_text']['#object']->field_bulletin_parag_image[LANGUAGE_NONE])) :
    $imgClass = 'dge-image1';
  else:
    $imgClass = 'dge-image0';
  endif;
  if(isset($content['field_bulletin_parag_text']['#object']->field_bulletin_parag_quote[LANGUAGE_NONE][0]['value']) &&
          $content['field_bulletin_parag_text']['#object']->field_bulletin_parag_quote[LANGUAGE_NONE][0]['value'] == 1):
    $citeClass = 'dge-cite1';
  else :
    $citeClass = 'dge-cite0';
  endif;
?>
<div class="<?php print $classes; ?> clearfix <?php print $citeClass .' '. $imgClass ?>"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
  <?php if(isset($content['field_bulletin_parag_text']['#object']->field_bulletin_parag_image[LANGUAGE_NONE])) : ?>
    <?php
      $img = array(
        'path' => $content['field_bulletin_parag_text']['#object']->field_bulletin_parag_image[LANGUAGE_NONE][0]['uri'],
        'alt' => $content['field_bulletin_parag_text']['#object']->field_bulletin_parag_image[LANGUAGE_NONE][0]['alt'],
        'width' => $content['field_bulletin_parag_text']['#object']->field_bulletin_parag_image[LANGUAGE_NONE][0]['width'],
        'height' => $content['field_bulletin_parag_text']['#object']->field_bulletin_parag_image[LANGUAGE_NONE][0]['height'],
        'attributes' => array(),
        'title' => $content['field_bulletin_parag_text']['#object']->field_bulletin_parag_image[LANGUAGE_NONE][0]['title']
      );
    ?>
    <?php if (isset($content['field_bulletin_parag_text']['#object']->field_bulletin_parag_image_link[LANGUAGE_NONE])) : ?>
      <div class="field-name-field-bulletin-parag-image">
        <a href="<?php print $content['field_bulletin_parag_text']['#object']->field_bulletin_parag_image_link[LANGUAGE_NONE][0]['url']; ?>">
          <?php print theme_image($img); ?>
        </a>
      </div>
    <?php else: ?>
      <div class="field-name-field-bulletin-parag-image">
        <?php print theme_image($img); ?>
      </div>
    <?php endif; ?>
  <?php elseif (isset($content['field_bulletin_parag_image']) && !isset($content['field_bulletin_parag_title']) &&
                !isset($content['field_bulletin_parag_text']) && !isset($content['field_bulletin_parag_link']) && $citeClass == 'dge-cite0'): ?>
    <?php
      $img = array(
        'path' => $content['field_bulletin_parag_image']['#object']->field_bulletin_parag_image[LANGUAGE_NONE][0]['uri'],
        'alt' => $content['field_bulletin_parag_image']['#object']->field_bulletin_parag_image[LANGUAGE_NONE][0]['alt'],
        'width' => $content['field_bulletin_parag_image']['#object']->field_bulletin_parag_image[LANGUAGE_NONE][0]['width'],
        'height' => $content['field_bulletin_parag_image']['#object']->field_bulletin_parag_image[LANGUAGE_NONE][0]['height'],
        'attributes' => array(),
        'title' => $content['field_bulletin_parag_image']['#object']->field_bulletin_parag_image[LANGUAGE_NONE][0]['title']
      );
    ?>
    <?php if (isset($content['field_bulletin_parag_image']['#object']->field_bulletin_parag_image_link[LANGUAGE_NONE])) : ?>
      <div class="field-name-field-bulletin-parag-big-image rtecenter">
        <a href="<?php print $content['field_bulletin_parag_image']['#object']->field_bulletin_parag_image_link[LANGUAGE_NONE][0]['url']; ?>">
          <?php print theme_image($img); ?>
        </a>
      </div>
    <?php else: ?>
      <div class="field-name-field-bulletin-parag-big-image">
        <?php print theme_image($img); ?>
      </div>
    <?php endif; ?>
  <?php endif; ?>
  <?php print render($content['field_bulletin_parag_title']); ?>
  <?php print render($content['field_bulletin_parag_text']); ?>
  <?php print render($content['field_bulletin_parag_link']); ?>
  </div>
</div>
