<?php

/**	 
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	* 
 	* This file is part of "dgef_desafio_aporta (datos.gob.es)".
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
 * dgef_desafio_aporta.entity.inc
 */

/**
 * Implements hook_entity_view_mode_info().
 */
function dgef_desafio_aporta_entity_view_mode_info() {
  $info = array();

  $info['node']['actual_challenge'] = array(
    'label' => 'Desafío Actual',
    'custom settings' => 1,
  );

  $info['node']['actual_meeting'] = array(
    'label' => 'Encuentro Actual',
    'custom settings' => 1,
  );

  $info['node']['aporta_meeting'] = array(
      'label' => 'Encuentro Aporta',
      'custom settings' => 1,
  );
    $info['node']['ponentes_encuentro_aporta'] = array(
        'label' => 'Ponentes Encuentro Aporta',
        'custom settings' => 1,
    );

  $info['node']['actual_winners'] = array(
    'label' => 'Premio Actual',
    'custom settings' => 1,
  );

  $info['node']['agenda'] = array(
    'label' => 'Agenda',
    'custom settings' => 1,
  );

  $info['node']['carousel_view'] = array(
    'label' => 'Vista Carousel',
    'custom settings' => 1,
  );

  $info['node']['challenge_aporta'] = array(
    'label' => 'Desafío Aporta',
    'custom settings' => 1,
  );

  $info['node']['referenced_content'] = array(
    'label' => 'Contenido referenciado',
    'custom settings' => 1,
  );

  $info['node']['speakers'] = array(
    'label' => 'Ponentes',
    'custom settings' => 1,
  );

  $info['paragraphs_item']['owl_carousel'] = array(
    'label' => 'OWL CAROUSEL',
    'custom settings' => 1,
  );

  return $info;
}
