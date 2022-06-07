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
<?php $color = $content['field_color'][0]['#markup']; ?>
<!-- Added style inside header to be able to assign the default color to the hover functionality of the links -->

<style>
    .dge-sector--link a:hover .imagen:after,
    .dge-sector--link a:focus .imagen:after {
      background-color: <?php print($color) ?>;
      opacity: 0.7;
    }

    .dge-news .more-link a:hover {
      color: <?php print($color) ?>;
    }

    .dge-smallcarousel .more-link a:hover {
      color: <?php print($color) ?>;
    }

    .dge-news__content li a:hover .dge-news__img:after,
    .dge-news__content li a:focus .dge-news__img:after,
    .dge-smallcarousel__content li a:hover .dge-smallcarousel__img:after,
    .dge-smallcarousel__content li a:focus .dge-smallcarousel__img:after {
      background-color: <?php print($color) ?>;
      opacity: 0.7;
    }
    .dge-sector--date {
      background-color: <?php print($color) ?>;
    }
  </style>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix" <?php print $attributes; ?>>

  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>

  <?php print render($title_suffix); ?>

  <?php if ($display_submitted) : ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>

  <div class="content" <?php print $content_attributes; ?>>
    <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    ?>
    <?php
    $img_cover = array(
      'style_name' => 'sector_cover',
      'path' => $content['field_image'][0]['#item']['uri'],
      'alt' => $content['field_image'][0]['#item']['alt'],
      'width' => '',
      'height' => '',
      'attributes' => array('class' => ['dge-sector--img']),
      'title' => $content['field_image'][0]['#item']['title'],
    );
    ?>
    <div id="sector-header" class="dge-sector--header">
      <div class="dge-sector--cover_img">
        <?php print theme('image_style', $img_cover); ?>
      </div>
      <div class="dge-sector--cover_title">
        <?php print render($content['title']) ?>
      </div>
    </div>

    <?php
      $breadcrumb = menu_get_active_breadcrumb();
      if (!empty($breadcrumb)) {
        print '<div class="dge-breadcrumb"><ul><li>' . implode($breadcrumb).'</li>'  .'<li>'. $title. '</li>'. '</ul></div>' ;
      } ?>

    <div class="dge-sector--description">
      <?php print render($content['body']) ?>
    </div>

    <div class="dge-sector--content">
      <div class="dge-sector--row">
        <?php $index = 0; while (array_key_exists($index, $content['field_contenido_paragrhaphs'])) : ?>
          <?php
            $bundle_id = $content['field_contenido_paragrhaphs']['#items'][$index]['value'];
            $field_paragrahp = $content['field_contenido_paragrhaphs'][$index]['entity']['paragraphs_item'][$bundle_id];
            $img = array(
              'style_name' => 'sector_link',
              'path' => $field_paragrahp['field_image'][0]['#item']['uri'],
              'alt' => $field_paragrahp['field_image'][0]['#item']['alt'],
              'width' => '',
              'height' => '',
              'attributes' => array('class' => ['dge-sector--image_content']),
              'title' => $field_paragrahp['field_image'][0]['#item']['title'],
            );
            ?>
          <?php if ($index > 0 and $index % 3 == 0) : ?>
      </div>
      <div class="dge-sector--row">
      <?php endif; ?>
      <div class="dge-sector--column">
        <div class="dge-sector--link">
          <a href="<?php print check_url($field_paragrahp['field_link'][0]['#element']['original_url']); ?>">
            <div class="imagen">
              <span class="dge-sector--span">
                <?php print theme('image_style', $img); ?>
              </span>
            </div>
            <div class="dge-sector--description_content">
            <?php if (isset($field_paragrahp['field_fecha'][0]['#markup'])) :?>
              <div class="dge-sector--date"><?php print($field_paragrahp['field_fecha'][0]['#markup']); ?></div>
            <?php endif; ?>
              <span class="dge-sector--title_content" style="color:<?php print($color); ?>;"><?php print($field_paragrahp['field_titulo'][0]['#markup']); ?></span>
              <p><?php print($field_paragrahp['field_descripcion'][0]['#markup']); ?></p>
            </div>
          </a>
        </div>
      </div>
      <?php $index++; ?>
    <?php endwhile; ?>
      </div>
    </div>

    <div class="dge-sector--view">
      <?php
      $index = 0;
      while (array_key_exists($index, $content['field_views_paragrhaphs'])) : ?>
        <?php
          $bundle_id = $content['field_views_paragrhaphs']['#items'][$index]['value'];
          $field_paragrahp = $content['field_views_paragrhaphs'][$index]['entity']['paragraphs_item'][$bundle_id];
          ?>
        <h2 class="dge-sector--view_title"><?php print($field_paragrahp['field_title'][0]['#markup']); ?></h2>
        <div class="dge-sector--view"><?php print render($field_paragrahp['field_view']); ?></div>
        <?php $index++; ?>
      <?php endwhile; ?>
    </div>

  </div>
</div>
