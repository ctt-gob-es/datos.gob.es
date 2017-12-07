<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file
 * Default theme implementation to format the simplenews newsletter body.
 *
 * Copy this file in your theme directory to create a custom themed body.
 * Rename it to override it. Available templates:
 *   simplenews-newsletter-body--[tid].tpl.php
 *   simplenews-newsletter-body--[view mode].tpl.php
 *   simplenews-newsletter-body--[tid]--[view mode].tpl.php
 * See README.txt for more details.
 *
 * Available variables:
 * - $build: Array as expected by render()
 * - $build['#node']: The $node object
 * - $title: Node title
 * - $language: Language code
 * - $view_mode: Active view mode
 * - $simplenews_theme: Contains the path to the configured mail theme.
 * - $simplenews_subscriber: The subscriber for which the newsletter is built.
 *   Note that depending on the used caching strategy, the generated body might
 *   be used for multiple subscribers. If you created personalized newsletters
 *   and can't use tokens for that, make sure to disable caching or write a
 *   custom caching strategy implemention.
 *
 * @see template_preprocess_simplenews_newsletter_body()
 */
?>
<table bgcolor="#ffffff" class="content" align="center" cellpadding="0" cellspacing="0" border="0">
  <!-- HEADER -->
  <tr>
  <?php if (isset($build['#node']->field_bulletin_header['und'][0])): ?>
	 <?php
		$bulletin_header_image_uri = $build['#node']->field_bulletin_header['und'][0]['uri'];
		$bulletin_header_style_image_uri = image_style_path('bulletin_header',$bulletin_header_image_uri);
		if (!file_exists($bulletin_header_style_image_uri)) {
		  image_style_create_derivative(image_style_load('bulletin_header'), $bulletin_header_image_uri, $bulletin_header_style_image_uri);
		}
		$image_dims = getimagesize(drupal_realpath($bulletin_header_style_image_uri));
		$image = '<img class="newsletter-header" src="'.file_create_url($bulletin_header_style_image_uri).'" alt="" '.$image_dims[3].' />';
	 ?>
	 <td bgcolor="#ffffff" class="image-header" style="border-bottom:4px solid #E05206">
		 <?php print $image; ?>
	 </td>
  <?php else: ?>
    <td bgcolor="#ffffff" class="header" style="border-bottom:4px solid #E05206;padding: 30px 30px 5px 30px;" >
      <table width="270" align="left" border="0" cellpadding="0" cellspacing="0" >
        <tr>
          <td height="90" style="padding: 0 20px 20px 0;">
          	<?php $logo_page_url = file_create_url('sites/default/files/logo_0.png', array('absolute' => TRUE) );?>
            <img class="fix" src="<?php print $logo_page_url; ?>" width="250" height="auto" border="0" alt="">
          </td>
        </tr>
      </table>
      <!--[if (gte mso 9)|(IE)]>
      <table width="265" align="left" cellpadding="0" cellspacing="0" border="0">
      <tr>
      <td>
      <![endif]-->
      <table class="col265" align="left" border="0" cellpadding="0" cellspacing="0" style="width: 100%; max-width: 265px;">
        <tr>
          <td height="70">
            <table width="100%" border="0" cellspacing="0" cellpadding="0">
              <tr>
                <td class="subtitle" style="padding: 20px 0 0 3px;" align="right">
                      Newsletter
                </td>
              </tr>
				  <tr>
                <td class="h1" style="padding: 5px 0 0 0;" align="right">
                	<?php
                	  $bulletin_date = '';
                	  if (isset($build['#node']->field_bulletin_date['und'][0]['value'])) {
                	    $bulletin_date = $build['#node']->field_bulletin_date['und'][0]['value'];
                	    $bulletin_date = format_date(strtotime($bulletin_date), 'custom', "M Y");
                	  }
			    		?><?php print $bulletin_date; ?>
                </td>
              </tr>
            </table>
          </td>
        </tr>
      </table>
      <!--[if (gte mso 9)|(IE)]>
      </td>
      </tr>
      </table>
      <![endif]-->
    </td>
  <?php endif ?>
  </tr>
  
  <!-- MAIN CONTENT -->
  <?php if (isset($build['#node']->field_bulletin_parag['und'])): ?>
    <?php foreach ($build['#node']->field_bulletin_parag['und'] as $i => $paragraph_id): ?>
		<?php
		  $field_collection = field_collection_field_get_entity($paragraph_id);
		  $is_quote = False;
		  if (isset($field_collection->field_bulletin_parag_quote['und'][0]['value']) &&
			           $field_collection->field_bulletin_parag_quote['und'][0]['value']) {
			 $is_quote = True;
		  }
		?>
      <!-- PARAGRAPH -->
      <tr>
        <td class="innerpadding" style="border-bottom: 1px solid #f2eeed;">
          <!-- Imagen izquierda -->
			    <?php
			    	$class_image = 'without-image';
			    	$description_size = '560';
					$with_image = FALSE;
			    ?>
			    <?php if (isset($field_collection->field_bulletin_parag_image['und'][0])): ?>
					<?php
					  $class_image = 'with-image';
					  $description_size = '340';
					  $with_image = TRUE;
					?>
				 <?php endif; ?>
				 <?php if (isset($field_collection->field_bulletin_parag_image['und'][0]) && $i % 2 == 0): ?>
			    	<?php
				    	$bulletin_parag_image_uri = $field_collection->field_bulletin_parag_image['und'][0]['uri'];
	               $bulletin_parag_style_image_uri = image_style_path('boletin_mail',$bulletin_parag_image_uri);
	               if (!file_exists($bulletin_parag_style_image_uri)) {
	                  image_style_create_derivative(image_style_load('boletin_mail'), $bulletin_parag_image_uri, $bulletin_parag_style_image_uri);
	               }
	               $image_dims = getimagesize(drupal_realpath($bulletin_parag_style_image_uri));
	               $image = '<img src="'.file_create_url($bulletin_parag_style_image_uri).'" alt="" '.$image_dims[3].' />';
						if (isset($field_collection->field_bulletin_parag_image_link['und'][0])) {
												$image = l($image,
												           $field_collection->field_bulletin_parag_image_link['und'][0]['url'],
												           array('absolute' => true, 'html' => TRUE));
						}
				   ?>
				    	<table width="200" align="left" border="0" cellpadding="0" cellspacing="0">
		            <tr>
		              <td height="152" style="padding: 0 20px 20px 0;">
		                <?php print $image; ?>
		              </td>
		            </tr>
		          </table>
			    	<?php else: ?>
			    		<?php if (!$with_image && $is_quote): ?>
			    			<?php
			    				$class_image = 'with-quote';
			    				$description_size = '440';
			    				$image_url = file_create_url(path_to_theme().'/images/ico-ia-tabs-07-soporte.png', array('absolute' => TRUE) );
			    			?>
			    		<table width="120" align="left" border="0" cellpadding="0" cellspacing="0">
		            <tr>
		              <td height="135" style="padding: 0 20px 20px 0;">
		                <img src="<?php print $image_url; ?>" alt="" width="100" height="100" />
		              </td>
		            </tr>
		          </table>
			    	<?php endif ?>
          <?php endif ?>
          <!--[if (gte mso 9)|(IE)]>
          <table width="<?php print $description_size; ?>" align="left" cellpadding="0" cellspacing="0" border="0">
            <tr>
              <td>
          <![endif]-->
          <table class="col<?php print $description_size; ?>" align="left" border="0" cellpadding="0" cellspacing="0" style="width:100%;max-width:<?php print $description_size; ?>px;">
            <tr>
              <td>
                <table width="100%" border="0" cellspacing="0" cellpadding="0">
                	<!-- titulo -->
			    				<?php if (isset($field_collection->field_bulletin_parag_title['und'][0])): ?>
			    					<tr>
			    						<td class="h2"><?php print $field_collection->field_bulletin_parag_title['und'][0]['safe_value']; ?></td>
			    					</tr>
			    				<?php endif ?>
			    				<!-- texto -->
			    				<?php if (isset($field_collection->field_bulletin_parag_text['und'][0])): ?>
			    				  <tr>
			    						<td class="bodycopy"><?php print $field_collection->field_bulletin_parag_text['und'][0]['safe_value']; ?></td>
			    					</tr>
			    				<?php endif ?>
                  <!-- enalce -->
			    				<?php if (isset($field_collection->field_bulletin_parag_link['und'][0])): ?>
			    					<?php
			    						$link_title = $field_collection->field_bulletin_parag_link['und'][0]['title'];
			    						if (empty($link_title)) {
			    							$link_title = $field_collection->field_bulletin_parag_link['und'][0]['display_url'];
			    						}
			    						$link = l($link_title, $field_collection->field_bulletin_parag_link['und'][0]['url'], array('absolute' => true, 'attributes' => array('class' => 'paragraph_link')));
			    					?>
			    					<tr>
			    						<td class="paragraph-link-mail" style="padding: 10px 0 0 0;"><?php print $link; ?></td>
			    					</tr>
			    				<?php endif ?>
                </table>
              </td>
            </tr>
          </table>
          <!--[if (gte mso 9)|(IE)]>
              </td>
            </tr>
          </table>
          <![endif]-->
			 <?php if (isset($field_collection->field_bulletin_parag_image['und'][0]) && $i % 2 != 0): ?>
				<?php
					$bulletin_parag_image_uri = $field_collection->field_bulletin_parag_image['und'][0]['uri'];
					$bulletin_parag_style_image_uri = image_style_path('boletin_mail',$bulletin_parag_image_uri);
					if (!file_exists($bulletin_parag_style_image_uri)) {
						image_style_create_derivative(image_style_load('boletin_mail'), $bulletin_parag_image_uri, $bulletin_parag_style_image_uri);
					}
					$image_dims = getimagesize(drupal_realpath($bulletin_parag_style_image_uri));
					$image = '<img src="'.file_create_url($bulletin_parag_style_image_uri).'" alt="" '.$image_dims[3].' />';
					if (isset($field_collection->field_bulletin_parag_image_link['und'][0])) {
											$image = l($image,
														  $field_collection->field_bulletin_parag_image_link['und'][0]['url'],
														  array('absolute' => true, 'html' => TRUE));
					}
				?>
					<table width="200" align="left" border="0" cellpadding="0" cellspacing="0">
					<tr>
					  <td height="152" style="padding: 0 0 20px 20px;">
						 <?php print $image; ?>
					  </td>
					</tr>
				 </table>
			 <?php endif ?>
        </td>
      </tr>
		<?php endforeach; ?>
  <?php endif ?>
  <!-- FOOTER -->
  <tr>
    <td class="innerpadding">
      <a href="http://datos.gob.es/" title="" class="" target="_blank" style="word-wrap: break-word;-ms-text-size-adjust: 100%;-webkit-text-size-adjust: 100%;"><img align="left" alt="" src="https://gallery.mailchimp.com/b14d8404a7ca8d65281827feb/images/footer.1e35662.png" width="560" style="max-width: 600px;padding-bottom: 0;display: inline !important;vertical-align: bottom;border: 0;outline: none;text-decoration: none;-ms-interpolation-mode: bicubic;" class="mcnImage"><br></a>
    </td>
  </tr>
  <tr>
    <td class="social-links" bgcolor="#AAAAAA" align="center" style="border:2px solid #FFF;border-width: 2px 0;padding:10px;">
    	<?php $icon_image_url = file_create_url('sites/default/files/datosgobes/ico-ft-twitter.png', array('absolute' => TRUE) );?>
      <a href="https://twitter.com/datosgob" target="_blank" title="Twitter. Abre en ventana nueva"><img alt="Twitter. Abre en ventana nueva" src="<?php print $icon_image_url; ?>" style="height:45px; width:45px"></a>&nbsp;&nbsp;&nbsp;&nbsp;<?php $icon_image_url = file_create_url('sites/default/files/datosgobes/ico-ft-linkedin.png', array('absolute' => TRUE) );?><a href="https://www.linkedin.com/company/datos-gob-es" target="_blank" title="LinkedIn. Abre en ventana nueva"><img alt="LinkedIn. Abre en ventana nueva" src="<?php print $icon_image_url; ?>" style="height:45px; width:45px"></a>&nbsp;&nbsp;&nbsp;&nbsp;<?php $icon_image_url = file_create_url('sites/default/files/datosgobes/ico-ft-slideshare.png', array('absolute' => TRUE) );?><a href="http://es.slideshare.net/datosgob" target="_blank" title="Sladeshare. Abre en ventana nueva"><img alt="Sladeshare. Abre en ventana nueva" src="<?php print $icon_image_url; ?>" style="height:45px; width:45px"></a>&nbsp;&nbsp;&nbsp;&nbsp;<?php $icon_image_url = file_create_url('sites/default/files/datosgobes/ico-ft-flikr.png', array('absolute' => TRUE) );?><a href="https://www.flickr.com/photos/datosgob/" target="_blank" title="Flikr. Abre en ventana nueva"><img alt="Flikr. Abre en ventana nueva" src="<?php print $icon_image_url; ?>" style="height:45px; width:45px"></a>&nbsp;&nbsp;&nbsp;&nbsp;<?php $icon_image_url = file_create_url('sites/default/files/datosgobes/ico-ft-youtube.png', array('absolute' => TRUE) );?><a href="https://www.youtube.com/user/datosgob" target="_blank" title="Youtube. Abre en ventana nueva"><img alt="Youtube. Abre en ventana nueva" src="<?php print $icon_image_url; ?>" style="height:45px; width:45px"></a>
    </td>
  </tr>
  <tr>
    <td class="footer" bgcolor="#6E2585">
      <table width="100%" border="0" cellspacing="0" cellpadding="0">
        <tr>
          <td align="center" class="footercopy" valign="middle" style="height:70px">
            contacto@datos.gob.es <br><br>
            <?php $unsubscribe_url = '#';?>
            <?php $node_url = url('boletines/'. $build['#node']->nid .'/mail-view', array('absolute' => TRUE));?>
            <a href="<?php print $unsubscribe_url; ?>" class="unsubscribe"><font color="#ffffff">Darse de baja</font></a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;<a href="<?php print $node_url; ?>" class="unsubscribe"><font color="#ffffff">Ver en un navegador</font></a>
          </td>
        </tr>
      </table>
    </td>
  </tr>
</table>
