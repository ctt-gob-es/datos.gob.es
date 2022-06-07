<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
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
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file
 * dgef_base.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function dgef_base_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'List of institutional banners';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_institutional_banners';
  $fe_block_boxes->body = '<ul>
	<li><a class="dge-entidades__link" href="http://www.minetur.gob.es/es-ES/Paginas/index.aspx" target="_blank"><img alt="Ir a Ministeio de Industria y Energía. Gobierno de España. Abre en ventana nueva" src="/sites/default/files/datosgobes/logo_minhap-minetur_gob-es.jpg" /></a></li>
	<li><a class="dge-entidades__link" href="http://red.es/" target="_blank"><img alt="Ir a Red punto es. Abre en ventana nueva" src="/sites/default/files/datosgobes/logo_red-es.jpg" /></a></li>
	<li><a class="dge-entidades__link" href="http://datos.gob.es/proyecto-aporta" target="_blank"><img alt="Ver Proyecto Aporta" src="/sites/default/files/datosgobes/logo_iniciativa-aporta.jpg" /></a></li>
</ul>
';

  $export['footer_institutional_banners'] = $fe_block_boxes;

  return $export;
}
