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

?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <div class="contenidoFase">
      <?php if($content['field_fase_image'][0]['#item']['uri']):?>
      <div><img alt="" class="<?php if($content['field_image_position'][0]['#markup']==='Izquierda'){print 'izquierdaImagen';}else{print 'derechaImagen';} ?>" src="<?php print file_create_url($content['field_fase_image'][0]['#item']['uri'])?>" ></div>
      <?php endif;?>
      <div><?php print $content['field_fase_description'][0]['#markup']; ?></div>
    </div>
  </div>
</div>
