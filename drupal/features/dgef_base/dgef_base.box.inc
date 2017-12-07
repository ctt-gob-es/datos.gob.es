<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_base (datos.gob.es)".
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
 * dgef_base.box.inc
 */

/**
 * Implements hook_default_box().
 */
function dgef_base_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'dge_social_media_links';
  $box->plugin_key = 'i18n';
  $box->title = '';
  $box->description = 'Bloque de iconos sociales';
  $box->options = array(
    'body' => array(
      'value' => '<ul>
	<li><a href="https://twitter.com/datosgob" target="_blank"><img alt="Síguenos en Twitter. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-hd-twitter.png" /></a></li>
	<li><a href="https://www.linkedin.com/company/datos-gob-es" target="_blank"><img alt="Síguenos en LinkedIn. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-hd-linkedin.png" /></a></li>
	<li><a href="http://es.slideshare.net/datosgob" target="_blank"><img alt="Síguenos en Sladeshare. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-hd-slideshare.png" /></a></li>
	<li><a href="https://www.flickr.com/photos/datosgob/" target="_blank"><img alt="Síguenos en Flikr. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-hd-flikr.png" /></a></li>
	<li><a href="https://www.youtube.com/user/datosgob" target="_blank"><img alt="Síguenos en Youtube. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-hd-youtube.png" /></a></li>
</ul>
',
      'format' => 'full_html',
    ),
    'i18n_boxes' => array(
      'language' => '__LOCALIZE__',
    ),
    'additional_classes' => '',
  );
  $export['dge_social_media_links'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'dge_social_media_links_alt';
  $box->plugin_key = 'i18n';
  $box->title = 'Síguenos';
  $box->description = 'DGE Social media links (Footer)';
  $box->options = array(
    'body' => array(
      'value' => '<ul>
	<li><a href="https://twitter.com/datosgob" target="_blank"><img alt="Twitter. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-ft-twitter.png" /></a></li>
	<li><a href="https://www.linkedin.com/company/datos-gob-es" target="_blank"><img alt="LinkedIn. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-ft-linkedin.png" /></a></li>
	<li><a href="http://es.slideshare.net/datosgob" target="_blank"><img alt="Sladeshare. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-ft-slideshare.png" /></a></li>
	<li><a href="https://www.flickr.com/photos/datosgob/" target="_blank"><img alt="Flikr. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-ft-flikr.png" /></a></li>
	<li><a href="https://www.youtube.com/user/datosgob" target="_blank"><img alt="Youtube. Abre en ventana nueva" src="/sites/default/files/datosgobes/ico-ft-youtube.png" /></a></li>
</ul>
',
      'format' => 'full_html',
    ),
    'i18n_boxes' => array(
      'language' => '__LOCALIZE__',
    ),
    'additional_classes' => '',
  );
  $export['dge_social_media_links_alt'] = $box;

  return $export;
}
