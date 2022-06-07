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
 *
 */
?>
<div class="elementosAporta">
	<div class="aporta-left-content">
		<div class="todoAporta">
			<div class="imagenAporta">
		<?php print $fields['field_aporta_image']->content?>
			</div>
			<div class="datosAportaPrincipal">
				<div class="datosAporta">
					<div class="subDatosAporta">
						<img alt="<?php print t("icono calendario") ?>" src="/sites/all/themes/dge_theme/images/svg/calendar.svg"><span class="highlight">¿Cuándo?</span>
						<div id="dateaporta">
							<?php print $fields['field_aporta_date']->content;?>
						</div>
						<div id="location">
							<img alt="<?php print t("icono mapa") ?>" src="/sites/all/themes/dge_theme/images/svg/ping-map.svg"><span class="highlight">¿Dónde?</span>
							<div class="location">
								<?php print render($fields['field_place']->content);?><br/>
								<?php if ($fields['field_address']):?>
								(<?php print render($fields['field_address']->content);?>)
								<?php endif;?>
							</div>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
	<div class="aporta-right-content">
		<div id="titulosPrincipales">
			<h2><?php print ($fields['title']->content)?></h2>
			<div id="titulosPrincipales2-old">
				<h3><?php print render ($fields['field_aporta_subtitle']->content);?></h3>
				<div class="aporta-old">
					<?php print (str_replace('-',' de ', $fields['field_aporta_date']->content));?>
					<?php if (isset($fields['field_collaborator'])):?>
					<?php print " - ";?>
					<?php print ($fields['field_collaborator']->content);?>
					<?php endif;?>
				</div>
				<?php print render ($fields['body']->content)?>
			</div>
    </div>
	</div>
</div>
<div class="dge-documents">
	<div class="dge-detail__docs clearfix">
		<?php if (isset($fields['field_group_aporta_doc']) || isset($fields['field_ficheros_externos_adjuntos'])):?>

		<h2 class="dge-detail__docs-title">Documentación</h2>
		<?php if (isset($fields['field_group_aporta_doc'])):?>
		<?php print ($fields['field_group_aporta_doc']->content)?>
		<?php endif;?>
		<?php if (isset($fields['field_ficheros_externos_adjuntos'])):?>
		<?php print ($fields['field_ficheros_externos_adjuntos']->content)?>
		<?php endif;?>
		<?php endif;?>
	</div>
</div>
<?php if (isset($fields['field_aporta_workgroup'])):?>
<div class="dge-detail__workshops">
	<?php print $fields['field_aporta_workgroup']->content;?>
</div>
<?php endif;?>

<?php print $fields['field_content_related']->content; ?>
<?php print $fields['field_related_content']->content; ?>
