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
<?php
global $base_url;
$ga_cid = variable_get('dge_newsletter_ga_cid','');
$utm_source = variable_get('dge_newsletter_utm_source','newsletter');
$utm_medium = variable_get('dge_newsletter_utm_medium','email');
$sanitized_title = str_replace(' ', '-', $build['#node']->title);
$sanitized_title = preg_replace('/[^A-Za-z0-9\-]/', '', $sanitized_title);

$utm_info = array();
if (!empty($utm_source) && !empty($utm_medium)) {
    $utm_info['utm_source'] = $utm_source;
    $utm_info['utm_medium'] = $utm_medium;
    $utm_info['utm_campaign'] = $sanitized_title;
}
?>
    <table style="width:600px;height:100%;padding-top:0;padding-right:0;padding-bottom:0;padding-left:0;text-align:center;border-collapse:collapse;background-color:#ffffff;" width="600" height="100%" cellspacing="0" cellpadding="0" border="0" align="center">
<?php ######### HEADER ######### ?>
    <tr>
        <style>
            a:hover{color: #c8c8c8;}
            a:visited {color: #c8c8c8;}
        </style>
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
            <td width="600" style="width:600px;text-align:center;vertical-align:bottom;">
                <?php print $image; ?>
            </td>
        <?php else: ?>
            <td width="600" height="100" align="center" valign="bottom" style="width:600px;height:100px;vertical-align:middle;">
                <table style="width:600px;height:100%;text-align:center;border-collapse:collapse;background-color:#EA5B3A;" width="600" height="100%" cellspacing="0" cellpadding="0" border="0" align="center">
                    <tr>
                        <td colspan="2" style="width:600px;text-align:center;vertical-align:bottom;">
                            <?php $logo_page_url = file_create_url('sites/all/themes/dge_theme/images/newsletter/dge-nws-header-top.png', array('absolute' => TRUE) );?>
                            <h1 style="margin-top:0px;margin-bottom:0px;"><img src="<?php print $logo_page_url; ?>" alt="Datos.gob.es" width="600" height="60" border="0" style="border:none;vertical-align:bottom;" /></h1>
                        </td>
                    </tr>
                    <tr>
                        <td style="width:485px;text-align:center;vertical-align:bottom;">
                            <img src="<?php print file_create_url(path_to_theme().'/images/newsletter/dge-nws-header-bottom.png'); ?>" alt="Datos.gob.es" width="485" height="70" border="0" style="border:none;vertical-align:bottom;" />
                        </td>
                        <td style="width:115px;text-align:center;vertical-align:middle;">
                            <p style="color:#ffffff;margin-top:0;margin-bottom:3px;font-size:16px;font-family:Arial, Helvetica, sans-serif;">BOLETÍN</p>
                            <p style="color:#ffffff;margin-top:0;margin-bottom:0;font-size:18px;font-family:Arial, Helvetica, sans-serif;text-transform:uppercase;letter-spacing:1.25px;">
                                <?php
                                $bulletin_date = '';
                                if (isset($build['#node']->field_bulletin_date['und'][0]['value'])) {
                                    $bulletin_date = $build['#node']->field_bulletin_date['und'][0]['value'];
                                    $bull_month = format_date(strtotime($bulletin_date), 'custom', "F");
                                    $bull_year = format_date(strtotime($bulletin_date), 'custom', "y");
                                    $bulletin_date = substr($bull_month, 0, 3)." '".$bull_year;
                                }
                                ?><?php print $bulletin_date; ?>
                            </p>
                        </td>
                    </tr>
                </table>
            </td>
        <?php endif ?>
    </tr>

<?php ######### SHARE ORIGINAL CONTENT ######### ?>
<?php
$social_links = service_links_render($build['#node'], TRUE);
theme('service_links_node_format', array(
    'links' => $social_links,
    'label' => variable_get('service_links_label_in_node', t('Bookmark/Search this post with')),
    'view_mode' => 'rss',
    'node_type' => $build['#node']->type,
));
$result = array();
foreach($social_links as $type => $l) {
    $l['title'] = '<img src="' . file_create_url(path_to_theme().'/images/newsletter/'.$type. '.png') . '" alt="" />';
    $result[] = l($l['title'], $l['href'], $l);
}
$rendered_social_links = implode(' ', $result);
?>
    <tr>
        <td width="600" height="60" align="center" valign="bottom" style="width:600px;height:60px;vertical-align:middle;">
            <table style="width:600px;height:100%;text-align:center;border-collapse:collapse;background-color:#FFF" width="600" height="100%" cellspacing="0" cellpadding="0" border="0" align="center">
                <tr>
                    <td width="600" height="23" align="right" style="width:600px;height:23px;padding-top:15px;padding-bottom:20px;vertical-align:bottom;text-align:right;">
                        <span style="color:#ffffff;font-weight:bold;font-size:15px;visibility:hidden;">Compartir en:</span> <?php print $rendered_social_links; ?>
                    </td>
                </tr>
            </table>
        </td>
    </tr>
    <tr>
        <td width="600" height="30" align="center" valign="middle" style="width:600px;height:20px;vertical-align:middle;background-color:#ffffff;">&nbsp;</td>
    </tr>

<?php ######### PARAGRAPS ######### ?>
<?php if (isset($build['#node']->field_bulletin_parag['und'])): ?>
    <?php foreach ($build['#node']->field_bulletin_parag['und'] as $i => $paragraph_id): ?>
    <?php ######### PARAGRAP ######### ?>
    <?php
    $field_collection = field_collection_field_get_entity($paragraph_id);
    $is_quote = FALSE;
    if (isset($field_collection->field_bulletin_parag_quote['und'][0]['value']) &&
        $field_collection->field_bulletin_parag_quote['und'][0]['value']) {
        $is_quote = TRUE;
    }
    $image = NULL;
    $only_image = FALSE;
    ?>
    <tr>
    <td class="paragraph-container" width="600" align="center" valign="middle" style="width:600px;vertical-align:middle;">
    <?php ######### IMAGE DATA ######### ?>
    <?php
    if (isset($field_collection->field_bulletin_parag_image['und'][0])) {
        $bulletin_parag_image_uri = $field_collection->field_bulletin_parag_image['und'][0]['uri'];
        $image_style = 'boletin_mail';
        if (empty($field_collection->field_bulletin_parag_title['und'][0]) &&
            empty($field_collection->field_bulletin_parag_text['und'][0]) &&
            empty($field_collection->field_bulletin_parag_link['und'][0])) {
            $image_style = 'bulletin_big_image';
            $only_image = TRUE;
        }
        $bulletin_parag_style_image_uri = image_style_path($image_style, $bulletin_parag_image_uri);
        if (!file_exists($bulletin_parag_style_image_uri)) {
            image_style_create_derivative(image_style_load($image_style), $bulletin_parag_image_uri, $bulletin_parag_style_image_uri);
        }
        $image_dims = getimagesize(drupal_realpath($bulletin_parag_style_image_uri));
        $image = '<img src="'.file_create_url($bulletin_parag_style_image_uri).'" alt="" '.$image_dims[3].' />';
        if (isset($field_collection->field_bulletin_parag_image_link['und'][0])) {
            $image = l($image,
                $field_collection->field_bulletin_parag_image_link['und'][0]['url'],
                array('absolute' => true, 'html' => TRUE, 'query' => $utm_info));
        }
    }
    $class_image = 'big-paragraph';
    $description_size = '560';
    $with_image = FALSE;
    if (isset($image) && !$only_image) {
        $class_image = 'text-and-image';
        $description_size = '340';
        $with_image = TRUE;
    }
    ?>
    <?php if (isset($image) && !$is_quote): ?>
    <?php if (!$only_image): ?>
    <?php ######### LEFT IMAGE ######### ?>
    <table class="<?php print $class_image; ?>" style="width:600px;padding-top:0px;padding-right:0px;padding-bottom:0px;padding-left:0px;text-align:center;border-collapse:collapse;background-color:#ffffff;" width="600" cellspacing="0" cellpadding="0" border="0" align="center">
    <tr>
    <td width="190" align="left" valign="top" style="width:190px;vertical-align:top;background-color:#ffffff;padding-top:0;padding-bottom:0;padding-left:0px;padding-right:20px;">
        <?php print $image; ?>
    </td>
    <td width="410" colspan="2" align="left" valign="top" style="width:470px;vertical-align:top;background-color:#ffffff;padding-top:0px;padding-bottom:0px;padding-left:0px;padding-right:0px;">
    <?php else: ?>
<?php ######### ONLY IMAGE - CENTERED ######### ?>
    <table class="<?php print $class_image; ?>" style="width:600px;padding-top:0px;padding-right:0px;padding-bottom:0px;padding-left:0px;text-align:center;border-collapse:collapse;background-color:#ffffff;" width="600" cellspacing="0" cellpadding="0" border="0" align="center">
    <tr>
        <td width="600" align="center" valign="top" style="width:600px;vertical-align:top;background-color:#ffffff;padding-top:0;padding-bottom:0;padding-left:0px;padding-right:0px;">
            <?php print $image; ?>
        </td>
        <?php endif ?>
        <?php elseif ($is_quote): ?>
    <?php ######### QUOTE IMAGE ######### ?>
    <?php
    $with_image = TRUE;
    $class_image = 'with-quote';
    $description_size = '440';
    $image_url = file_create_url(path_to_theme().'/images/newsletter/dge-nws-quote.png', array('absolute' => TRUE) );
    ?>
        <table class="<?php print $class_image; ?>" style="width:600px;padding-top:0px;padding-right:15px;padding-bottom:15px;padding-left:0px;text-align:center;border-collapse:collapse;background-color:#EDE4EF;" width="600" cellspacing="0" cellpadding="0" border="0" align="center">
            <tr>
                <td width="100" align="left" valign="top" style="width:100px;vertical-align:top;background-color:#EDE4EF;padding-top:0px;padding-right:0;padding-bottom:0px;padding-left:0px;">
                    <img src="<?php print $image_url; ?>" alt="" width="87" height="103" border="0" style="border:none;"  />
                </td>
                <td width="510" colspan="2" align="left" valign="top" style="width:510px;vertical-align:top;background-color:#EDE4EF;padding-top:20px;padding-right:15px;padding-bottom:10px;padding-left:0px;">
                    <?php endif ?>
                    <?php if (!$only_image): ?>
                        <?php ######### TITLE ######### ?>
                        <?php if (isset($field_collection->field_bulletin_parag_title['und'][0])): ?>
                            <p class="dge-nl-title" style="font-family:arial,helvetica,sans-serif;font-size:16px;line-height:130%;font-weight:bold;font-style:normal;color:#752390;text-align:left;margin-top:0px;margin-bottom:8px;margin-right:0px;padding-top:0px;padding-left:0px;">
                                <?php print $field_collection->field_bulletin_parag_title['und'][0]['safe_value']; ?>
                            </p>
                        <?php endif ?>
                        <?php ######### DESCRIPTION ######### ?>
                        <?php if (isset($field_collection->field_bulletin_parag_text['und'][0])): ?>
                            <div class="dge-nl-text" style="font-family:arial,helvetica,sans-serif;font-size:14px;line-height:130%;color:#545454;text-align:left;margin-top:0px;margin-bottom:10px;margin-right:0px;padding-top:0px;padding-left:0px;">
                                <?php
                                $pg_description = $field_collection->field_bulletin_parag_text['und'][0]['safe_value'];
                                //Fix relative images from WYSIWYG
                                $pg_description = str_replace('<img alt="" src="/sites', '<img alt="" src="'. $base_url .'/sites', $pg_description);
                                $pg_description = str_replace("<img alt='' src='/sites", "<img alt='' src='". $base_url .'/sites', $pg_description);
                                $pg_description = str_replace('<img src="/sites', '<img src="'. $base_url .'/sites', $pg_description);
                                $pg_description = str_replace("<img src='/sites", "<img src='". $base_url .'/sites', $pg_description);
                                ?>
                                <?php print $pg_description; ?>
                            </div>
                        <?php endif ?>
                        <?php ######### LINK ######### ?>
                        <?php if (isset($field_collection->field_bulletin_parag_link['und'][0])): ?>
                            <?php
                            $link_title = $field_collection->field_bulletin_parag_link['und'][0]['title'];
                            if (empty($link_title)) {
                                $link_title = $field_collection->field_bulletin_parag_link['und'][0]['display_url'];
                            }
                            $link = l($link_title, $field_collection->field_bulletin_parag_link['und'][0]['url'], array('query' => $utm_info, 'absolute' => true, 'attributes' => array('style' => 'margin:0 -1px;padding-top:9px;padding-left:14px;padding-right:12px;padding-bottom:8px;color:#ffffff;background-color:#EA5B3A;border-radius:30px;letter-spacing:1.25px;text-decoration:none;')));
                            ?>
                            <p class="dge-nl-link" style="font-family:arial,helvetica,sans-serif;font-size:13px;font-weight:bold;text-align:right;margin-top:24px;margin-bottom:0;margin-right:5px;">
                                <?php print $link; ?>
                            </p>
                        <?php endif ?>
                    <?php endif ?>
                    <?php if ($is_quote): ?>
                    <?php ######### QUOTE IMAGE ######### ?>
                    <?php
                    $with_image = TRUE;
                    $class_image = 'with-quote';
                    $description_size = '440';
                    $image_url_end = file_create_url(path_to_theme().'/images/newsletter/dge-nws-quote-end.png', array('absolute' => TRUE) );
                    ?>
                </td>
                <td width="90" align="right" valign="top" style="width:90px;vertical-align:bottom;background-color:#EDE4EF;padding-top:0px;padding-right:0;padding-bottom:0px;padding-left:0px;">
                    <img src="<?php print $image_url_end; ?>" alt="" width="87" height="103" border="0" style="border:none;"  />
                    <?php endif ?>
                    <?php ######### CLOSE INTERNAL TABLE IF IT WAS CREATED ######### ?>
                    <?php if ($with_image): ?>
                </td>
            </tr>
        </table>
    <?php endif ?>
        </td>
    </tr>
    <tr>
        <td width="600" height="30" align="center" valign="middle" style="width:600px;height:20px;vertical-align:middle;background-color:#ffffff;">&nbsp;</td>
    </tr>
    <?php endforeach; ?>
<?php endif ?>

<?php ######### FOOTER ######### ?>
    <tr>
        <td width="600" height="25" align="center" valign="middle" style="width:600px;height:25px;vertical-align:middle;background-color:#ffffff;">&nbsp;</td>
    </tr>
    <tr>
        <td width="600" height="63" align="center" valign="middle" style="width:600px;height:63px;vertical-align:middle;">
            <table style="width:600px;height:63px;padding-top:0px;padding-right:0px;padding-bottom:0px;padding-left:0px;text-align:center;border-collapse:collapse;background-color:#ffffff;" width="600" height="63" cellspacing="0" cellpadding="0" border="0" align="center">
                <tr><td>
                        <img src="<?php print file_create_url(path_to_theme().'/images/newsletter/dge-nws-institutional-logos.png'); ?>" alt="" width="600" height="63" border="0" style="vertical-align:middle;border:none;" />
                    </td></tr>
            </table>
        </td>
    </tr>
    <tr>
        <td width="600" height="17" align="center" valign="middle" style="width:600px;height:17px;vertical-align:middle;background-color:#ffffff;">&nbsp;</td>
    </tr>
    <tr>
        <td class="social-links" valign="middle" bgcolor="#AAAAAA" align="center" style="border-bottom:1px solid #FFFFFF;padding:10px;vertical-align:middle;">
            <table style="padding:0px;margin:0px;border:0px;">
                <tr><td>
                        <span style="display:inline-block;vertical-align:middle;padding:10px;color:#ffffff;font-size:10px;">SÍGUENOS</span>
                    </td><td>
                        <?php $icon_image_url = file_create_url('sites/default/files/datosgobes/ico-ft-twitter.png', array('absolute' => TRUE) );?>
                        <a style="display:inline-block;vertical-align:middle;margin:0 4px;" href="https://twitter.com/datosgob" target="_blank" title="Twitter. Abre en ventana nueva"><img alt="Twitter. Abre en ventana nueva" src="<?php print $icon_image_url; ?>" style="height:28px; width:28px" height="28p" width="28"></a>
                    </td><td>
                        <?php $icon_image_url = file_create_url('sites/default/files/datosgobes/ico-ft-linkedin.png', array('absolute' => TRUE) );?>
                        <a style="display:inline-block;vertical-align:middle;margin:0 4px;" href="https://www.linkedin.com/company/datos-gob-es" target="_blank" title="LinkedIn. Abre en ventana nueva"><img alt="LinkedIn. Abre en ventana nueva" src="<?php print $icon_image_url; ?>" style="height:28px; width:28px" height="28p" width="28"></a>
                    </td><td>
                        <?php $icon_image_url = file_create_url('sites/default/files/datosgobes/ico-ft-slideshare.png', array('absolute' => TRUE) );?>
                        <a style="display:inline-block;vertical-align:middle;margin:0 4px;" href="http://es.slideshare.net/datosgob" target="_blank" title="Sladeshare. Abre en ventana nueva"><img alt="Sladeshare. Abre en ventana nueva" src="<?php print $icon_image_url; ?>" style="height:28px; width:28px" height="28p" width="28"></a>
                    </td><td>
                        <?php $icon_image_url = file_create_url('sites/default/files/datosgobes/ico-ft-flikr.png', array('absolute' => TRUE) );?>
                        <a style="display:inline-block;vertical-align:middle;margin:0 4px;" href="https://www.flickr.com/photos/datosgob/" target="_blank" title="Flikr. Abre en ventana nueva"><img alt="Flikr. Abre en ventana nueva" src="<?php print $icon_image_url; ?>" style="height:28px; width:28px" height="28p" width="28"></a>
                    </td><td>
                        <?php $icon_image_url = file_create_url('sites/default/files/datosgobes/ico-ft-youtube.png', array('absolute' => TRUE) );?>
                        <a style="display:inline-block;vertical-align:middle;margin:0 4px;" href="https://www.youtube.com/user/datosgob" target="_blank" title="Youtube. Abre en ventana nueva"><img alt="Youtube. Abre en ventana nueva" src="<?php print $icon_image_url; ?>" style="height:28px; width:28px" height="28p" width="28"></a>
                    </td></tr>
            </table>
        </td>
    </tr>
    <tr>
        <td width="600" height="40" align="center" valign="middle" style="width:600px;height:40px;vertical-align:middle;">
            <table style="width:600px;height:40px;padding-top:0px;padding-right:0px;padding-bottom:0px;padding-left:0px;text-align:center;border-collapse:collapse;background-color:#752390;" width="600" height="40" cellspacing="0" cellpadding="0" border="0" align="center">
                <tr>
                    <?php $icon_email_url = file_create_url('sites/all/themes/dge_theme/images/newsletter/dge-ico-contact.png', array('absolute' => TRUE) );?>
                    <td width="600" height="10" colspan="3" align="center" valign="middle" style="width:600px;padding:10px;height:10px;vertical-align:middle;font-family:arial,helvetica,sans-serif;font-size:13px;color:#ffffff;text-align:center;">
                        <p>
                            <img src="<?php print $icon_email_url; ?>" alt="icono contacto" width="27" height="20" border="0" style="vertical-align:middle;border:none;margin-right:7px; color:#ffffff; text-decoration: underline;" /> <a href="mailto:contacto@datos.gob.es" style="color:#ffffff;">contacto@datos.gob.es</a>
                        </p>
                    </td>
                </tr>
                <tr>
                    <td width="600" height="5" colspan="3" align="center" valign="middle" style="width:600px;padding:10px;height:5px;vertical-align:middle;font-family:arial,helvetica,sans-serif;font-size:13px;color:#ffffff;text-align:center;">
                        <?php
                        $node_url = url('node/'. $build['#node']->nid, array('query' => $utm_info, 'absolute' => TRUE, 'https' => FALSE));
                        ?>
                        <a href="<?php print $node_url; ?>" style="color:#ffffff; text-decoration: underline;">Ver en un navegador</a>
                    </td>
                </tr>
            </table>
        </td>
    </tr>
    </table>
<?php if (!empty($ga_cid) ): ?>
    <img src="http://www.google-analytics.com/collect?v=1&tid=<?php print variable_get('googleanalytics_account', 'UA-'); ?>&t=event&ec=email&ea=open&cs=newsletter&cm=email&cn=<?php print $sanitized_title ?>"/>
<?php endif ?>
