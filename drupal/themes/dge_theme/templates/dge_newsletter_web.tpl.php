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
 * Theme implementation to format the web newsletter.
 *
 * Available variables:
 * - $newsletter: loaded node with newsletter type
 *
 * @see template_preprocess_dge_newsletter_web()
 */
?>
<?php
  $language_attrs = '';
  if($newsletter->language_markup_enabled == true) {
    $language_attrs= " lang='$newsletter->language_original' xml:lang='$newsletter->language_original'";
  }
?>
<div class="node-bulletin dge-detail--bulletin dge-detail--newsletter dge-newsletter-template">
  <?php //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        //++ SOCIAL LINKS +++++++++++++++++++++++++++++++++++++++++++++++++
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ?>
  <div class="dge-detail__share">
    <strong class="dge-detail__share-title"><?php print t('Share'); ?></strong>
    <div class="dge-detail__share-cont">
    <?php
      $raw_social_links = service_links_render($newsletter, TRUE);
      $social_links = theme('links', array('links' => $raw_social_links));
      print $social_links;
    ?>
    </div>
  </div>
  <?php //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        //++ DATE +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ?>
  <?php
    $bulletin_date = '';
    $bulletin_date_ext = '';
    if (isset($newsletter->field_bulletin_date['und'][0]['value'])) {
      $bulletin_date = $newsletter->field_bulletin_date['und'][0]['value'];
      $bulletin_date = format_date(strtotime($bulletin_date), 'custom', "d-m-Y");
      $bulletin_date_ext = format_date(strtotime($bulletin_date), 'custom', "Y-m-d\TH:i:sP");
    }
  ?>
  <p class="dge-detail__date">
    <strong><?php print t('Date'); ?>: </strong>
    <span>
      <span class="date-display-single" property="dc:date" datatype="xsd:dateTime" content="<?php print $bulletin_date_ext; ?>"><?php print $bulletin_date; ?></span>
    </span>
  </p>
  <?php //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        //++ DESCRIPTION ++++++++++++++++++++++++++++++++++++++++++++++++++
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ?>
  <?php if (isset($newsletter->field_bulletin_description['und']) && is_array($newsletter->field_bulletin_description['und']) &&
        sizeof($newsletter->field_bulletin_description['und']) > 0): ?>
    <div class="dge-detail__desc"<?php print $language_attrs; ?>>
      <div class="dge-detail__desc-cont">
        <?php foreach ($newsletter->field_bulletin_description['und'] as $i => $description): ?>
          <?php print $description['safe_value']; ?>
        <?php endforeach ?>
      </div>
    </div>
  <?php endif ?>
  <?php //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        //++ NEWSLETTER REPRESENTATION ++++++++++++++++++++++++++++++++++++
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ?>
  <div class="newsletter-content-area sent-newsletter">
    <div class="newsletter-content">
      <?php //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            //++ HEADER +++++++++++++++++++++++++++++++++++++++++++++++++++
            //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ?>
      <?php if (isset($newsletter->field_bulletin_header['und'][0])): ?>
        <?php
          $bulletin_header_image_uri = $newsletter->field_bulletin_header['und'][0]['uri'];
          $bulletin_header_style_image_uri = image_style_path('bulletin_header',$bulletin_header_image_uri);
          if (!file_exists($bulletin_header_style_image_uri)) {
            image_style_create_derivative(image_style_load('bulletin_header'), $bulletin_header_image_uri, $bulletin_header_style_image_uri);
          }
          $image_dims = getimagesize(drupal_realpath($bulletin_header_style_image_uri));
          $image = '<img class="newsletter-header" src="'.file_create_url($bulletin_header_style_image_uri).'" alt="'.$newsletter->field_bulletin_header['und'][0]['alt'].'" '.$image_dims[3].' />';
        ?>
        <div class="newsletter-direct-header dge-newsletter-header">
          <?php print $image; ?>
        </div>
      <?php else: ?>
        <?php
          $bulletin_date = '';
          if (isset($newsletter->field_bulletin_date['und'][0]['value'])) {
            $bulletin_date = $newsletter->field_bulletin_date['und'][0]['value'];
            $bull_month = format_date(strtotime($bulletin_date), 'custom', "F");
            $bull_year = format_date(strtotime($bulletin_date), 'custom', "y");
            $bulletin_date = '<abbr title="'.$bull_month.'">'.substr($bull_month, 0, 3).'</abbr> &#714;'.$bull_year;
          }
        ?>
        <div class="newsletter-standard-header dge-newsletter-header">
          <div class="dge-header-container">
            <div class="dge-header-content">
              <h2><span class="dge-newsletter-title-header" lang="en" xml:lang="en">Boletín</span>
              <span class="dge-newsletter-date-header"><?php print $bulletin_date; ?></span></h2>
            </div>
          </div>
        </div>
      <?php endif ?>
      <?php //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            //++ SOCIAL LINKS ACCOUNTS ++++++++++++++++++++++++++++++++++++
            //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ?>
      <div class="dge-newsletter-share-links">
        <div class="dge-newsletter-social-title"><?php print t('Follow us'); ?></div>
        <div class="dge-newsletter-social-list ">
          <?php print $social_links; ?>
        </div>
      </div>
      <?php //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            //++ PARAGRAPHS +++++++++++++++++++++++++++++++++++++++++++++++
            //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ?>
      <?php if (isset($newsletter->field_bulletin_parag['und'])): ?>
        <?php foreach ($newsletter->field_bulletin_parag['und'] as $i => $paragraph_id): ?>
        <?php //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
              //++ PARAGRAPH ++++++++++++++++++++++++++++++++++++++++++++++
              //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ?>
          <?php
            // Get paragraph data
            $field_collection = field_collection_field_get_entity($paragraph_id);

            $main_style = 'complete-paragraph';
            $is_quote = FALSE;
            $only_image = FALSE;
            $image = NULL;

            // Check is Quote
            if (isset($field_collection->field_bulletin_parag_quote['und'][0]['value']) &&
                  $field_collection->field_bulletin_parag_quote['und'][0]['value']) {
              $is_quote = TRUE;
              $main_style = 'quote-paragraph';
            }

            // Get image
            if (isset($field_collection->field_bulletin_parag_image['und'][0]['uri']) && !$is_quote) {
              $bulletin_parag_image_uri = $field_collection->field_bulletin_parag_image['und'][0]['uri'];
              $image_style = 'boletin_mail';
              if (empty($field_collection->field_bulletin_parag_title['und'][0]) &&
                  empty($field_collection->field_bulletin_parag_text['und'][0]) &&
                  empty($field_collection->field_bulletin_parag_link['und'][0])) {
                $image_style = 'bulletin_big_image';
                $main_style = 'only-image-paragraph';
                $only_image = TRUE;
              }
              $bulletin_parag_style_image_uri = image_style_path($image_style, $bulletin_parag_image_uri);
              if (!file_exists($bulletin_parag_style_image_uri)) {
                    image_style_create_derivative(image_style_load($image_style), $bulletin_parag_image_uri, $bulletin_parag_style_image_uri);
              }
              $title = (!empty($field_collection->field_bulletin_parag_image['und'][0]['title']))?' tilte="'.$field_collection->field_bulletin_parag_image['und'][0]['title'].'"':'';
              $image_dims = getimagesize(drupal_realpath($bulletin_parag_style_image_uri));
              $image = '<img src="'.file_create_url($bulletin_parag_style_image_uri).'" alt="'.$field_collection->field_bulletin_parag_image['und'][0]['alt'].'" '.$image_dims[3].$title.' />';
              if (isset($field_collection->field_bulletin_parag_image_link['und'][0])) {
                $image = l($image,
                           $field_collection->field_bulletin_parag_image_link['und'][0]['url'],
                           array('html' => TRUE));
              }
            }
            if (empty($image) && !$is_quote) {
              $main_style = 'no-image-paragraph';
            }
          ?>
          <div class="dge-newsletter-paragraph field-collection-item-field-bulletin-parag clearfix <?php print $main_style; ?>"<?php print $language_attrs; ?>>
            <div class="content">
              <?php if (isset($image)): ?>
                <div class="field-name-field-bulletin-parag-image"><?php print $image; ?></div>
              <?php endif ?>
              <?php if (isset($field_collection->field_bulletin_parag_title['und'][0])): ?>
                <div class="field field-name-field-bulletin-parag-title field-type-text">
                  <div class="field-item"><h3><?php print $field_collection->field_bulletin_parag_title['und'][0]['safe_value']; ?></h3></div>
                </div>
              <?php endif ?>
              <?php if (isset($field_collection->field_bulletin_parag_text['und'][0])): ?>
                <div class="field field-name-field-bulletin-parag-text field-type-text-long">
                   <div class="field-item"><?php print $field_collection->field_bulletin_parag_text['und'][0]['safe_value']; ?></div>
                </div>
              <?php endif ?>
              <?php if (isset($field_collection->field_bulletin_parag_link['und'][0])): ?>
                <div class="field field-name-field-bulletin-parag-link field-type-link-field">
                  <div class="field-item"><?php
                    $link = array(
                      '#theme' => 'link',
                      '#text' => $field_collection->field_bulletin_parag_link['und'][0]['title'],
                      '#path' => $field_collection->field_bulletin_parag_link['und'][0]['url'],
                      '#options' => array(
                        'attributes' => array('class' => array('cool-class'), 'id' => 'cool-id'),
                        'html' => FALSE,
                    ));?><?php print render($link); ?>
                  </div>
                </div>
              <?php endif ?>
            </div>
          </div>
        <?php endforeach ?>
      <?php endif ?>
      <?php //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            //++ INSTITUTIONAL LINKS ++++++++++++++++++++++++++++++++++++++
            //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ?>
      <div class="dge-newsletter-institutional-links">
    <img style="display: block;margin: 0px auto;"alt="Gobierno de España. Ministerio de Hacienda y Administraciones Públicas. Ministerio de Industria y Energía.Red.es.Aporta" src="/sites/default/files/datosgobes/dge-nws-institutional-logos.png" />

      </div>
      <div class="dge-newsletter-social-links">
        <h2><?php print t('Follow us'); ?></h2>
        <ul>
          <li><a href="https://twitter.com/datosgob" target="_blank" title="Twitter. Abre en ventana nueva"><img alt="Twitter. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-ft-twitter.svg" style="height:29px; width:29px"></a></li>
          <li><a href="https://www.linkedin.com/company/datos-gob-es" target="_blank" title="LinkedIn. Abre en ventana nueva"><img alt="LinkedIn. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-ft-linkedin.svg" style="height:29px; width:29px"></a></li>
          <li><a href="http://es.slideshare.net/datosgob" target="_blank" title="Sladeshare. Abre en ventana nueva"><img alt="Sladeshare. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-ft-slideshare.svg" style="height:29px; width:29px"></a></li>
          <li><a href="https://www.flickr.com/photos/datosgob/" target="_blank" title="Flikr. Abre en ventana nueva"><img alt="Flikr. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-ft-flikr.svg" style="height:29px; width:29px"></a></li>
          <li><a href="https://www.youtube.com/user/datosgob" target="_blank" title="Youtube. Abre en ventana nueva"><img alt="Youtube. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-ft-youtube.svg" style="height:29px; width:29px"></a></li>
        </ul>
      </div>
      <?php //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            //++ FOOTER +++++++++++++++++++++++++++++++++++++++++++++++++++
            //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ?>
      <div class="dge-newsletter-footer">
          <div class="newsletter-footer-email"><img src="/sites/all/themes/dge_theme/images/newsletter/dge-ico-contact.png" alt="icono contacto" /> <a href="mailto:contacto@datos.gob.es">contacto@datos.gob.es</a> </div>
      </div>
    </div>
  </div>
  <?php //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        //++ TAGS +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ ?>
  <?php if (isset($newsletter->field_bulletin_tags['und']) && is_array($newsletter->field_bulletin_tags['und']) &&
        sizeof($newsletter->field_bulletin_tags['und']) > 0): ?>
    <div class="dge-detail__tags"<?php print $language_attrs; ?>>
      <div class="item-list">
        <?php
          $result = array();
          foreach($newsletter->field_bulletin_tags['und'] as $i => $rawtag) {
            $term=taxonomy_term_load($rawtag['tid']);
            $result[] = array(
              'title' => $term->name,
              'href' => url('taxonomy/term/' . $term->tid)
            );
          }
          $tag_links = theme('links', array('links' => $result));
        ?>
        <?php print $tag_links; ?>
      </div>
    </div>
  <?php endif ?>
</div>
