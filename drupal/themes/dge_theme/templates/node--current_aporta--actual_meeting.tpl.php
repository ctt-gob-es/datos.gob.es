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
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2><?php print $title_attributes; ?><a href="<?php print $node_url; ?>"></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted;?>
    </div>
  <?php endif; ?>

	<div class="content"<?php print $content_attributes; ?>>
		<?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
		?>

		<div class="elementosAporta">
			<div class="aporta-left-content">
				<div class="todoAporta">
					<div class="imagenAporta">
						<img src="<?php print file_create_url($content['field_aporta_image'][0]['#item']['uri'])?>">
					</div>
					<div class="datosAportaPrincipal">
						<div class="datosAporta">
							<div class="subDatosAporta">
								<img alt="<?php print t("icono calendario") ?>" src="/sites/all/themes/dge_theme/images/svg/calendar.svg"><span class="highlight">¿Cuándo?</span>
								<div id="dateaporta">
									<?php print (str_replace('-',' de ',$content['field_aporta_date'][0]['#markup']));?>
								</div>
								<div id="location">
									<img src="/sites/all/themes/dge_theme/images/svg/ping-map.svg"><span class="highlight">¿Dónde?</span>
									<div class="location">
										<?php print render ($content['field_location'][0]['#markup']);?><br/>
										<?php if ($content['field_location_gmaps']):?>
										(<?php print render ($content['field_location_gmaps'][0]['#markup']);?>)
										<?php endif;?>
									</div>
								</div>
								<?php if ($content['field_location_gmaps']):?>
								<div id="viewmap">
									<a id="mapaMorado" href="<?php print $node_url . "#tabs-5"; ?>"> <img src="/sites/all/themes/dge_theme/images/ico_map.png">Ver en maps</a>
								</div>
								<?php endif;?>
							</div>
						</div>
					</div>
				</div>
			</div>
			<div class="aporta-right-content">
				<div id="titulosPrincipales">
					<h2><?php print (node_load($node->nid)->title);?></h2>
				</div>
				<div id="titulosPrincipales2">
					<h3><?php print render ($content['field_aporta_subtitle']['#items'][0]['value']);?></h3>
				</div>
				<?php print render ($content['body'])?>
				<div id="botonAportaInfo">
					<a class="encuentroAporta" href="<?php print $node_url; ?>">Ver información sobre el evento </a>
					<div id="links_Aporta">
					<?php if ($content['field_content_agenda']):?>
							<a href="<?php print $node_url . "#tabs-1"; ?>"><img id="imagenLinksAporta" src="/sites/all/themes/dge_theme/images/svg/list-calendar.svg" style="width:20px">Ver agenda</a>
					<?php endif;?>
					<?php if ($content['field_description_ponents'] || $content['field_ponents_paragraph']):?>
						<a href="<?php print $node_url . "#tabs-3"; ?>"><img id="imagenLinksAporta" src="/sites/all/themes/dge_theme/images/svg/profile.svg" style="width:20px">Ver ponentes</a>
					<?php endif;?>
					</div>
				</div>
			</div>
		</div>
	</div>
</div>
<div id="encuentrosAnteriores">
	<h4>Encuentros anteriores</h4>
</div>
