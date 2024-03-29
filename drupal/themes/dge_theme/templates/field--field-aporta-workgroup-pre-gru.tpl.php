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
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used and is here as a starting point for customization only.
 * @see theme_field()
 *
 * Available variables:
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @ingroup themeable
 */
?>
<!--
THIS FILE IS NOT USED AND IS HERE AS A STARTING POINT FOR CUSTOMIZATION ONLY.
See http://api.drupal.org/api/function/theme_field/7 for details.
After copying this file to your theme's folder and customizing it, remove this
HTML comment.
-->
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php if (!$label_hidden): ?>
        <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?></div>
    <?php endif; ?>
    <div class="field-items"<?php print $content_attributes;  ?>>
        <?php foreach ($items as $delta => $item): ?>
            <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta];  ?>>

                <div class="imagenAgenda ponentes">
                    <?php
                    print render ($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_ponen'][0]['node'][key($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_ponen'][0]['node'])]['field_photo']);
                    ?>
                </div>
                <div class="dge-box-aporta-old">
                    <?php if ($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_ponen']): ?>
                        <div class="field_ponente">
                            <?php
                            print render($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_ponen'][0]['node'][key($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_ponen'][0]['node'])]['title']);
                            ?>

                        </div>
                    <?php endif; ?>

                    <?php if (isset($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_ponen'])): ?>
                        <div class="field_cargo ponentes">
                            <?php
                            print render($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_ponen'][0]['node'][key($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_ponen'][0]['node'])]['field_position']);
                            print render($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_ponen'][0]['node'][key($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_ponen'][0]['node'])]['field_departament']);
                            ?>
                        </div>
                    <?php endif; ?>

                    <div class="dge-box-bottom">
                        <!-- <?php /* if($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_vid']):?>
          <div class="visitasYoutube">
            <span>
              <?php
              $response = chr_curl_http_request("https://www.googleapis.com/youtube/v3/videos?part=statistics&id=".$variableMinutosFinal[0]."&key=AIzaSyDFheRQSOY9DxFHyKmS-bxIdqX74gp6Ch8");
              $jsonVisitas = drupal_json_decode($response->data);
              echo $jsonVisitas['items'][0]['statistics']['viewCount'] . "";
              ?>
            </span>
          </div>
          <?php endif; */ ?> -->

                        <div tabindex="0" class="dge-detail__share2">
                            <strong class="dge-detail__share2-title"><?php print t('Compartir'); ?></strong>
                            <div class="dge-detail__share2-cont">
                                <?php
                                $response2 = chr_curl_http_request("https://www.googleapis.com/youtube/v3/videos?part=snippet&id=" . $variableMinutosFinal[0] . "&key=AIzaSyDFheRQSOY9DxFHyKmS-bxIdqX74gp6Ch8");
                                $jsonVisitas2 = drupal_json_decode($response2->data);
                                $newsletter = "";
                                $raw_social_links = service_links_render($newsletter, TRUE);
                                $node = menu_get_object();
                                $raw_social_links['service-links-twitter']['query']['url'] = $item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_vid'][0]['#element']['url'];
                                $raw_social_links['service-links-twitter']['query']['text'] = $node->title . " - " . $jsonVisitas2['items'][0]['snippet']['title'];
                                $raw_social_links['service-links-linkedin']['query']['text'] = $node->title . " - " . $jsonVisitas2['items'][0]['snippet']['title'];
                                $raw_social_links['service-links-google-plus']['query']['text'] = $node->title . " - " . $jsonVisitas2['items'][0]['snippet']['title'];
                                $raw_social_links['service-links-facebook']['query']['text'] = $node->title . " - " . $jsonVisitas2['items'][0]['snippet']['title'];
                                $raw_social_links['service-links-linkedin']['query']['url'] = $item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_vid'][0]['#element']['url'];
                                $raw_social_links['service-links-google-plus']['query']['url'] = $item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_vid'][0]['#element']['url'];
                                $raw_social_links['service-links-facebook']['query']['u'] = $item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_vid'][0]['#element']['url'];

                                $social_links = theme('links', array('links' => $raw_social_links));
                                print $social_links;
                                ?>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="field_documentacion">
                    <?php if ($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_vidos']): ?>
                        <a class="videoYoutubeEncuentro" target="_blank"
                           href="<?php echo $item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_vidos'][0]['#element']['original_url']; ?>"><?php print t('Entrevista') ?>
                        </a>
                    <?php endif; ?>
                    <?php if ($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_vid']): ?>
                        <a class="videoYoutubeEncuentro derecha" target="_blank"
                           href="<?php echo $item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_vid'][0]['#element']['original_url']; ?>"><?php print t('Video') ?>
                        </a>
                    <?php endif; ?>
                    <?php if (isset($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_doc']) && isset($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_pre'])): ?>
                        <a class="videoYoutubeEncuentro derecha" target="_blank"
                           href="<?php echo file_create_url($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_doc']['#items'][0]['uri']); ?>"><?php print t('Presentación') ?></a>
                    <?php else: ?>
                        <?php if (isset($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_doc'])): ?>
                            <a class="videoYoutubeEncuentro derecha" target="_blank"
                               href="<?php echo file_create_url($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_doc']['#items'][0]['uri']); ?>"><?php print t('Presentación') ?></a>
                        <?php endif; ?>
                        <?php if (isset($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_pre'])): ?>
                            <a class="videoYoutubeEncuentro derecha" target="_blank"
                               href="<?php echo file_create_url($item['entity']['field_collection_item'][key($item['entity']['field_collection_item'])]['field_aporta_workgroup_pre_pre']['#items'][0]['original_url']); ?>"><?php print t('Presentación') ?></a>
                        <?php endif; ?>
                    <?php endif; ?>


                </div>
            </div>
        <?php endforeach; ?>
    </div>
</div>
