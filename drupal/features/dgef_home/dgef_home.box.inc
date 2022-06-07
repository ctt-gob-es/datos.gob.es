<?php

/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_home (datos.gob.es)".
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
 * dgef_home.box.inc
 */

/**
 * Implements hook_default_box().
 */
function dgef_home_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = '4_iodc_madrid_2016';
  $box->plugin_key = 'i18n';
  $box->title = '';
  $box->description = 'Banner 4º IODC Madrid';
  $box->options = array(
    'body' => array(
      'value' => '<div class="home-iodc">
<div class="custom-content btTableRow">
<div class="rowItem btTextLeft">
<div class="rowItemContent">
<div class="btSuperTitle black-background">4<sup>th</sup> IODC</div>

<div class="dash">
<h2>Madrid. October 6-7, 2016 <br />
Global goals, local impact</h2>
</div>

<div class="btSubTitle black-background">#IODC16</div>
</div>
</div>

<div class="rowItem btTextCenter">
<div class="rowItemContent"><a class="btBtn btnBanner" href="http://opendatacon.org">+ info</a></div>
</div>
</div>
</div>
',
      'format' => 'full_html',
    ),
    'i18n_boxes' => array(
      'language' => '__LOCALIZE__',
    ),
    'additional_classes' => '',
  );
  $export['4_iodc_madrid_2016'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'home_contribute';
  $box->plugin_key = 'i18n';
  $box->title = 'Aporta';
  $box->description = 'Home Contribute';
  $box->options = array(
    'body' => array(
      'value' => '<p>Líneas de actuación</p>

<div class="home-contribute">
<ul>
	<li><a href="#"><img alt="" src="/sites/default/files/datosgobes/ico-ia-01-difusion.png" />Difusión, Sensibilización y formación</a></li>
	<li><a href="#"><img alt="" src="/sites/default/files/datosgobes/ico-ia-02-catalogo.png" />Catálogo Nacional de datos abiertos</a></li>
	<li><a href="#"><img alt="" src="/sites/default/files/datosgobes/ico-ia-03-esadisticas.png" />Estadísticas sectoriales</a></li>
	<li><a href="#"><img alt="" src="/sites/default/files/datosgobes/ico-ia-04-cpp.png" />CPP Colaboración público-privada</a></li>
	<li><a href="#"><img alt="" src="/sites/default/files/datosgobes/ico-ia-05-ambito.png" />Ámbito legislativo y cooperación nacional</a></li>
	<li><a href="#"><img alt="" src="/sites/default/files/datosgobes/ico-ia-06-cooperacion.png" />Cooperación internacional</a></li>
	<li><a href="#"><img alt="" src="/sites/default/files/datosgobes/ico-ia-07-soporte.png" />Asesoramiento y soporte</a></li>
</ul>
</div>',
      'format' => 'full_html',
    ),
    'i18n_boxes' => array(
      'language' => '__LOCALIZE__',
    ),
    'additional_classes' => '',
  );
  $export['home_contribute'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'home_impact';
  $box->plugin_key = 'i18n';
  $box->title = 'Impacto';
  $box->description = 'Home Impact';
  $box->options = array(
    'body' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'i18n_boxes' => array(
      'language' => '__LOCALIZE__',
    ),
    'additional_classes' => '',
  );
  $export['home_impact'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'home_interact';
  $box->plugin_key = 'i18n';
  $box->title = 'Interactúa';
  $box->description = 'Home Interact';
  $box->options = array(
    'body' => array(
      'value' => '<div class="home-interact">
<div class="interact-support">
<ul>
	<li><a href="#"><img alt="" src="/sites/default/files/datosgobes/ico-interactua-01-soporte.png" /> Asesoramiento<br />
	y soporte</a></li>
	<li><a href="documentacion"><img alt="" src="/sites/default/files/datosgobes/ico-interactua-02-manuales.png" /> Manuales<br />
	y guias</a></li>
</ul>
</div>

<div class="interact-share">
<ul>
	<li><a href="informa-sobre/peticion-datos"><img alt="" src="/sites/default/files/datosgobes/ico-interactua-03-datos.png" />Peticiones<br />
	de datos</a></li>
	<li><a href="informa-sobre/aplicaciones"><img alt="" src="/sites/default/files/datosgobes/ico-interactua-04-app.png" />Aplicaciones</a></li>
	<li><a href="informa-sobre/casos-exito"><img alt="" src="/sites/default/files/datosgobes/ico-interactua-05-exito.png" />Casos de Éxito</a></li>
	<li><a href="contacto"><img alt="" src="/sites/default/files/datosgobes/ico-interactua-06-sugerencias.png" />Sugerencias<br />
	y mejoras</a></li>
</ul>
</div>
</div>
',
      'format' => 'full_html',
    ),
    'i18n_boxes' => array(
      'language' => '__LOCALIZE__',
    ),
    'additional_classes' => '',
  );
  $export['home_interact'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'home_map';
  $box->plugin_key = 'i18n';
  $box->title = 'Iniciativas de datos abiertos';
  $box->description = 'Home Map';
  $box->options = array(
    'body' => array(
      'value' => '<p><img src="/sites/all/themes/dge_theme/images/test_site/front_map.png" /></p>
',
      'format' => 'full_html',
    ),
    'i18n_boxes' => array(
      'language' => '__LOCALIZE__',
    ),
    'additional_classes' => '',
  );
  $export['home_map'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'home_slogan';
  $box->plugin_key = 'i18n';
  $box->title = '';
  $box->description = 'Home Slogan';
  $box->options = array(
    'body' => array(
      'value' => '<p>Iniciativa de <strong>datos abiertos</strong> del Gobierno de España</p>
',
      'format' => 'full_html',
    ),
    'i18n_boxes' => array(
      'language' => '__LOCALIZE__',
    ),
    'additional_classes' => '',
  );
  $export['home_slogan'] = $box;

  return $export;
}
