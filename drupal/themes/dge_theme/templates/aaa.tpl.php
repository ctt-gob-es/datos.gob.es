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
  <div class="content"<?php print $content_attributes; ?>>
    <div class="dge-box-left">
      <div class="tituloWinnersParagraph">
      <?php print render ($content['field_winners_title']);?>
      <?php print render ($content['field_winners_subtitle']);?>
      </div>
      <div class="descripcionParagraph">
        <?php print render ($content['field_winners_description_item']);?>
      </div>
      <div class="redesWinnersParagraph">

          <a class="twitter" href='<?php print $content['field_twitter']['#items'][0]['url']?>'><?php print $content['field_twitter']['#items'][0]['title']?></a>
          <a class="linkedin" href='<?php print $content['field_linkedin']['#items'][0]['url']?>'><?php print $content['field_linkedin']['#items'][0]['title']?></a>
          <a class="youtube" href='<?php print $content['field_idea_youtube']['#items'][0]['url']?>'><?php print $content['field_idea_youtube']['#items'][0]['title']?></a>

        <div class="visitasYoutube">

          <?php
            $response = chr_curl_http_request("https://www.googleapis.com/youtube/v3/videos?part=statistics&id=".$variableMinutosFinal[0]."&key=AIzaSyDFheRQSOY9DxFHyKmS-bxIdqX74gp6Ch8");
            $jsonVisitas = drupal_json_decode($response->data);
            echo $jsonVisitas['items'][0]['statistics']['viewCount'] . " visitas <span class='numvisit'></span>";
          ?>
          <div class="dge-detail__share2">
            <strong class="dge-detail__share2-title"><?php print t('Share'); ?></strong>
            <div class="dge-detail__share2-cont">
            <?php
            $response2 = chr_curl_http_request("https://www.googleapis.com/youtube/v3/videos?part=snippet&id=".$variableMinutosFinal[0]."&key=AIzaSyDFheRQSOY9DxFHyKmS-bxIdqX74gp6Ch8");
            $jsonVisitas2 = drupal_json_decode($response2->data);
            $raw_social_links = service_links_render($newsletter, TRUE);
            $node = menu_get_object();

              $raw_social_links = service_links_render($newsletter, TRUE);
              $raw_social_links['service-links-twitter']['query']['text'] =  $node->title . " - " . $jsonVisitas2['items'][0]['snippet']['title'];
              $raw_social_links['service-links-linkedin']['query']['text'] = $node->title . " - " .$jsonVisitas2['items'][0]['snippet']['title'];
              $raw_social_links['service-links-google-plus']['query']['text'] = $node->title . " - " .$jsonVisitas2['items'][0]['snippet']['title'];
              $raw_social_links['service-links-facebook']['query']['text'] = $node->title . " - " . $jsonVisitas2['items'][0]['snippet']['title'];
              $raw_social_links['service-links-twitter']['query']['url'] =  $content['field_winners_video_2']['#items'][0]['value'];
              $raw_social_links['service-links-linkedin']['query']['url'] =  $content['field_winners_video_2']['#items'][0]['value'];
              $raw_social_links['service-links-google-plus']['query']['url'] =  $content['field_winners_video_2']['#items'][0]['value'];
              $raw_social_links['service-links-facebook']['query']['u'] = $content['field_winners_video_2']['#items'][0]['value'];

              $social_links = theme('links', array('links' => $raw_social_links));
              print $social_links;
            ?>
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="dge-box-right">
      <div class="videoWinnersParagraph">
        <iframe allowfullscreen="" height="500" style="border: 0;" src="<?php
          $urlYoutube = explode("t=",$content['field_winners_video_2']['#items'][0]['value']);
          $minutos = explode('m',$urlYoutube[1]);
          $minutosFinales = $minutos[0] * 60;
          $segundos = explode('s', $minutos[1]);
          $segundosFinales = $segundos[0] + $minutosFinales;
          $variable= str_replace("youtube.com/watch?v=","youtube.com/embed/",$content['field_winners_video_2']['#items'][0]['value']);
          $variable= str_replace("youtu.be/","youtube.com/embed/",$variable);
          $variable = str_replace("&feature=youtu.be#","?",$variable);
          $variable = str_replace("&index=","#",$variable);
          $variable = str_replace("&list=","#",$variable);
          $variableMinutos = explode("/",$variable);
          $variableMinutos2 = explode("?",$variableMinutos[4]);
          $variableMinutosFinal = explode("#",$variableMinutos2[0]);
          echo $variable;
        ?>?rel=0&amp;showinfo=0&amp;start=<?php echo $segundosFinales?>"></iframe>
      </div>
    </div>
 </div>
</div>