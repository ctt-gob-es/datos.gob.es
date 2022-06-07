<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_menu (datos.gob.es)".
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
 * dgef_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dgef_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_actualidad:<void5>.
  $menu_links['main-menu_actualidad:<void5>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<void5>',
    'router_path' => '<void5>',
    'link_title' => 'Actualidad',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_actualidad:<void5>',
      'external' => TRUE,
      'unaltered_hidden' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_advice-and-support:node/3472.
  $menu_links['main-menu_advice-and-support:node/3472'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3472',
    'router_path' => 'node/%',
    'link_title' => 'Advice and Support',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'page',
      'identifier' => 'main-menu_advice-and-support:node/3472',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_aholkularitza-eta-laguntza:node/3475.
  $menu_links['main-menu_aholkularitza-eta-laguntza:node/3475'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3475',
    'router_path' => 'node/%',
    'link_title' => 'Aholkularitza eta Laguntza',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'page',
      'identifier' => 'main-menu_aholkularitza-eta-laguntza:node/3475',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'language' => 'eu',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_aplicaciones:aplicaciones.
  $menu_links['main-menu_aplicaciones:aplicaciones'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'aplicaciones',
    'router_path' => 'aplicaciones',
    'link_title' => 'Aplicaciones',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_aplicaciones:aplicaciones',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_impacto:<void3>',
  );
  // Exported menu link: main-menu_aporta-awards-menu-position-rule:menu-position/13.
  $menu_links['main-menu_aporta-awards-menu-position-rule:menu-position/13'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/13',
    'router_path' => 'menu-position/%',
    'link_title' => 'Aporta Awards (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_aporta-awards-menu-position-rule:menu-position/13',
    ),
    'module' => 'menu_position',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'main-menu_premios-aporta:premios-aporta',
  );
  // Exported menu link: main-menu_aporta-awards:premios-aporta.
  $menu_links['main-menu_aporta-awards:premios-aporta'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'premios-aporta',
    'router_path' => 'premios-aporta',
    'link_title' => 'Aporta Awards',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'page',
      'identifier' => 'main-menu_aporta-awards:premios-aporta',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -38,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_innovacin:<void9>',
  );
  // Exported menu link: main-menu_aporta-challenge-menu-position-rule:menu-position/12.
  $menu_links['main-menu_aporta-challenge-menu-position-rule:menu-position/12'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/12',
    'router_path' => 'menu-position/%',
    'link_title' => 'Aporta Challenge (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_aporta-challenge-menu-position-rule:menu-position/12',
    ),
    'module' => 'menu_position',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'main-menu_desafo-aporta:desafios-aporta',
  );
  // Exported menu link: main-menu_aporta-challenge:desafios-aporta.
  $menu_links['main-menu_aporta-challenge:desafios-aporta'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'desafios-aporta',
    'router_path' => 'desafios-aporta',
    'link_title' => 'Aporta Challenge',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'page',
      'identifier' => 'main-menu_aporta-challenge:desafios-aporta',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_innovacin:<void9>',
  );
  // Exported menu link: main-menu_aporta-erronka:desafios-aporta.
  $menu_links['main-menu_aporta-erronka:desafios-aporta'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'desafios-aporta',
    'router_path' => 'desafios-aporta',
    'link_title' => 'Aporta erronka',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'page',
      'identifier' => 'main-menu_aporta-erronka:desafios-aporta',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'eu',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_innovacin:<void9>',
  );
  // Exported menu link: main-menu_aporta-sariak:premios-aporta.
  $menu_links['main-menu_aporta-sariak:premios-aporta'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'premios-aporta',
    'router_path' => 'premios-aporta',
    'link_title' => 'Aporta Sariak',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'page',
      'identifier' => 'main-menu_aporta-sariak:premios-aporta',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -37,
    'customized' => 1,
    'language' => 'eu',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_innovacin:<void9>',
  );
  // Exported menu link: main-menu_asesoramento-e-soporte:node/3474.
  $menu_links['main-menu_asesoramento-e-soporte:node/3474'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3474',
    'router_path' => 'node/%',
    'link_title' => 'Asesoramento e soporte',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'page',
      'identifier' => 'main-menu_asesoramento-e-soporte:node/3474',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'language' => 'gl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_asesoramiento-y-soporte:node/3471.
  $menu_links['main-menu_asesoramiento-y-soporte:node/3471'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3471',
    'router_path' => 'node/%',
    'link_title' => 'Asesoramiento y Soporte',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'page',
      'identifier' => 'main-menu_asesoramiento-y-soporte:node/3471',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'es',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_assessorament-i-suport:node/3473.
  $menu_links['main-menu_assessorament-i-suport:node/3473'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3473',
    'router_path' => 'node/%',
    'link_title' => 'Assessorament i suport',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'page',
      'identifier' => 'main-menu_assessorament-i-suport:node/3473',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'ca',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_boletines:boletines.
  $menu_links['main-menu_boletines:boletines'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'boletines',
    'router_path' => 'boletines',
    'link_title' => 'Boletines',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_boletines:boletines',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_actualidad:<void5>',
  );
  // Exported menu link: main-menu_caso-de-xito:informa-sobre/casos-exito.
  $menu_links['main-menu_caso-de-xito:informa-sobre/casos-exito'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'informa-sobre/casos-exito',
    'router_path' => 'informa-sobre/casos-exito',
    'link_title' => 'Caso de Éxito',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_caso-de-xito:informa-sobre/casos-exito',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_informa-sobre:node/26',
  );
  // Exported menu link: main-menu_catlogo-de-datos:<void2>.
  $menu_links['main-menu_catlogo-de-datos:<void2>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<void2>',
    'router_path' => '<void2>',
    'link_title' => 'Catálogo de datos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_catlogo-de-datos:<void2>',
      'external' => TRUE,
      'unaltered_hidden' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_comparte-tu-aplicacin:informa-sobre/aplicaciones.
  $menu_links['main-menu_comparte-tu-aplicacin:informa-sobre/aplicaciones'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'informa-sobre/aplicaciones',
    'router_path' => 'informa-sobre/aplicaciones',
    'link_title' => 'Comparte tu Aplicación',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_comparte-tu-aplicacin:informa-sobre/aplicaciones',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_informa-sobre:node/26',
  );
  // Exported menu link: main-menu_conjuntos-de-datos:catalogo.
  $menu_links['main-menu_conjuntos-de-datos:catalogo'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'catalogo',
    'router_path' => 'catalogo',
    'link_title' => 'Conjuntos de Datos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_conjuntos-de-datos:catalogo',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_catlogo-de-datos:<void2>',
  );
  // Exported menu link: main-menu_contact:node/2.
  $menu_links['main-menu_contact:node/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_contact:node/2',
      'node_type' => 'webform',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_report-on:node/27',
  );
  // Exported menu link: main-menu_contacte:node/3.
  $menu_links['main-menu_contacte:node/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Contacte',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_contacte:node/3',
      'node_type' => 'webform',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'ca',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_informa-sobre:node/28',
  );
  // Exported menu link: main-menu_contacto:node/1.
  $menu_links['main-menu_contacto:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Contacto',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_contacto:node/1',
      'node_type' => 'webform',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'es',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_informa-sobre:node/26',
  );
  // Exported menu link: main-menu_contacto:node/4.
  $menu_links['main-menu_contacto:node/4'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/4',
    'router_path' => 'node/%',
    'link_title' => 'Contacto',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_contacto:node/4',
      'node_type' => 'webform',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'gl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_informa-sobre:node/29',
  );
  // Exported menu link: main-menu_cuadro-de-mando:dashboard.
  $menu_links['main-menu_cuadro-de-mando:dashboard'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dashboard',
    'router_path' => 'dashboard',
    'link_title' => 'Cuadro de Mando',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_cuadro-de-mando:dashboard',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_impacto:<void3>',
  );
  // Exported menu link: main-menu_desafiament-aporta:desafios-aporta.
  $menu_links['main-menu_desafiament-aporta:desafios-aporta'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'desafios-aporta',
    'router_path' => 'desafios-aporta',
    'link_title' => 'Desafiament Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'page',
      'identifier' => 'main-menu_desafiament-aporta:desafios-aporta',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'language' => 'ca',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_innovacin:<void9>',
  );
  // Exported menu link: main-menu_desafo-aporta:desafios-aporta.
  $menu_links['main-menu_desafo-aporta:desafios-aporta'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'desafios-aporta',
    'router_path' => 'desafios-aporta',
    'link_title' => 'Desafío Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'challenge_aporta',
      'identifier' => 'main-menu_desafo-aporta:desafios-aporta',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'language' => 'es',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_innovacin:<void9>',
  );
  // Exported menu link: main-menu_disponibilidad-de-datos:peticiones-datos.
  $menu_links['main-menu_disponibilidad-de-datos:peticiones-datos'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'peticiones-datos',
    'router_path' => 'peticiones-datos',
    'link_title' => 'Disponibilidad de datos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_disponibilidad-de-datos:peticiones-datos',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_documentacin:documentacion.
  $menu_links['main-menu_documentacin:documentacion'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'documentacion',
    'router_path' => 'documentacion',
    'link_title' => 'Documentación',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_documentacin:documentacion',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_empresas-reutilizadoras:casos-exito.
  $menu_links['main-menu_empresas-reutilizadoras:casos-exito'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'casos-exito',
    'router_path' => 'casos-exito',
    'link_title' => 'Empresas reutilizadoras',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_empresas-reutilizadoras:casos-exito',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_impacto:<void3>',
  );
  // Exported menu link: main-menu_encuentros-aporta:encuentros-aporta.
  $menu_links['main-menu_encuentros-aporta:encuentros-aporta'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'encuentros-aporta',
    'router_path' => 'encuentros-aporta',
    'link_title' => 'Encuentros Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_encuentros-aporta:encuentros-aporta',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_iniciativa-aporta:<void1>',
  );
  // Exported menu link: main-menu_eventos:eventos.
  $menu_links['main-menu_eventos:eventos'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'eventos',
    'router_path' => 'eventos',
    'link_title' => 'Eventos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_eventos:eventos',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_actualidad:<void5>',
  );
  // Exported menu link: main-menu_honi-buruzko-informazioa:node/30.
  $menu_links['main-menu_honi-buruzko-informazioa:node/30'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/30',
    'router_path' => 'node/%',
    'link_title' => 'Honi buruzko informazioa',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_honi-buruzko-informazioa:node/30',
      'node_type' => 'page',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'eu',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_impacto:<void3>.
  $menu_links['main-menu_impacto:<void3>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<void3>',
    'router_path' => '<void3>',
    'link_title' => 'Impacto',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_impacto:<void3>',
      'external' => TRUE,
      'unaltered_hidden' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_informa-sobre:node/26.
  $menu_links['main-menu_informa-sobre:node/26'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/26',
    'router_path' => 'node/%',
    'link_title' => 'Informa sobre',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_informa-sobre:node/26',
      'node_type' => 'page',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'es',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_informa-sobre:node/28.
  $menu_links['main-menu_informa-sobre:node/28'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/28',
    'router_path' => 'node/%',
    'link_title' => 'Informa sobre',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_informa-sobre:node/28',
      'node_type' => 'page',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'ca',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_informa-sobre:node/29.
  $menu_links['main-menu_informa-sobre:node/29'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/29',
    'router_path' => 'node/%',
    'link_title' => 'Informa sobre',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_informa-sobre:node/29',
      'node_type' => 'page',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'gl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_iniciativa-aporta:<void1>.
  $menu_links['main-menu_iniciativa-aporta:<void1>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<void1>',
    'router_path' => '<void1>',
    'link_title' => 'Iniciativa Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_iniciativa-aporta:<void1>',
      'external' => TRUE,
      'unaltered_hidden' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_iniciativas:accessible-initiatives.
  $menu_links['main-menu_iniciativas:accessible-initiatives'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'accessible-initiatives',
    'router_path' => 'accessible-initiatives',
    'link_title' => 'Iniciativas',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_iniciativas:accessible-initiatives',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_mapa-de-iniciativas:iniciativas',
  );
  // Exported menu link: main-menu_inicio:<front>.
  $menu_links['main-menu_inicio:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Inicio',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_inicio:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_innovacin:<void9>.
  $menu_links['main-menu_innovacin:<void9>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<void9>',
    'router_path' => '<void9>',
    'link_title' => 'Innovación',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'unaltered_hidden' => 0,
      'external' => TRUE,
      'identifier' => 'main-menu_innovacin:<void9>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_interacta:<void4>.
  $menu_links['main-menu_interacta:<void4>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<void4>',
    'router_path' => '<void4>',
    'link_title' => 'Interactúa',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_interacta:<void4>',
      'external' => TRUE,
      'unaltered_hidden' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_kontaktua:node/5.
  $menu_links['main-menu_kontaktua:node/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/5',
    'router_path' => 'node/%',
    'link_title' => 'Kontaktua',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_kontaktua:node/5',
      'node_type' => 'webform',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'eu',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_honi-buruzko-informazioa:node/30',
  );
  // Exported menu link: main-menu_mapa-de-iniciativas:iniciativas.
  $menu_links['main-menu_mapa-de-iniciativas:iniciativas'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'iniciativas',
    'router_path' => 'iniciativas',
    'link_title' => 'Mapa de Iniciativas',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_mapa-de-iniciativas:iniciativas',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_impacto:<void3>',
  );
  // Exported menu link: main-menu_peticin-de-datos:informa-sobre/peticion-datos.
  $menu_links['main-menu_peticin-de-datos:informa-sobre/peticion-datos'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'informa-sobre/peticion-datos',
    'router_path' => 'informa-sobre/peticion-datos',
    'link_title' => 'Petición de datos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_peticin-de-datos:informa-sobre/peticion-datos',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_informa-sobre:node/26',
  );
  // Exported menu link: main-menu_premios-aporta:premios-aporta.
  $menu_links['main-menu_premios-aporta:premios-aporta'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'premios-aporta',
    'router_path' => 'premios-aporta',
    'link_title' => 'Premios Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'page',
      'identifier' => 'main-menu_premios-aporta:premios-aporta',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
    'language' => 'gl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_innovacin:<void9>',
  );
  // Exported menu link: main-menu_premis-aporta:premios-aporta.
  $menu_links['main-menu_premis-aporta:premios-aporta'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'premios-aporta',
    'router_path' => 'premios-aporta',
    'link_title' => 'Premis Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'node_type' => 'page',
      'identifier' => 'main-menu_premis-aporta:premios-aporta',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -36,
    'customized' => 1,
    'language' => 'ca',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_innovacin:<void9>',
  );
  // Exported menu link: main-menu_report-on:node/27.
  $menu_links['main-menu_report-on:node/27'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/27',
    'router_path' => 'node/%',
    'link_title' => 'Report on',
    'options' => array(
      'attributes' => array(),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_report-on:node/27',
      'node_type' => 'page',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_sectores:<void>.
  $menu_links['main-menu_sectores:<void>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<void>',
    'router_path' => '<void>',
    'link_title' => 'Sectores',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'unaltered_hidden' => 0,
      'external' => TRUE,
      'identifier' => 'main-menu_sectores:<void>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_users-menu-position-rule:menu-position/10.
  $menu_links['main-menu_users-menu-position-rule:menu-position/10'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/10',
    'router_path' => 'menu-position/%',
    'link_title' => 'Users (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_users-menu-position-rule:menu-position/10',
    ),
    'module' => 'menu_position',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'main-menu_mi-cuenta:user',
  );
  // Exported menu link: menu-footer-nav_acerca-de-iniciativa-aporta:node/3466.
  $menu_links['menu-footer-nav_acerca-de-iniciativa-aporta:node/3466'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'node/3466',
    'router_path' => 'node/%',
    'link_title' => 'Acerca de iniciativa Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_acerca-de-iniciativa-aporta:node/3466',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_iniciativa-aporta:<front>',
  );
  // Exported menu link: menu-footer-nav_actualidad:<front>.
  $menu_links['menu-footer-nav_actualidad:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Actualidad',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_actualidad:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-nav_agricultura:node/17728.
  $menu_links['menu-footer-nav_agricultura:node/17728'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'node/17728',
    'router_path' => 'node/%',
    'link_title' => 'Agricultura',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_agricultura:node/17728',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_sectores:<front>',
  );
  // Exported menu link: menu-footer-nav_api:apidata.
  $menu_links['menu-footer-nav_api:apidata'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'apidata',
    'router_path' => 'apidata',
    'link_title' => 'API',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_api:apidata',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_catlogo-de-datos:<front>',
  );
  // Exported menu link: menu-footer-nav_aplicaciones:aplicaciones.
  $menu_links['menu-footer-nav_aplicaciones:aplicaciones'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'aplicaciones',
    'router_path' => 'aplicaciones',
    'link_title' => 'Aplicaciones',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_aplicaciones:aplicaciones',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_impacto:<front>',
  );
  // Exported menu link: menu-footer-nav_aporta-awards:node/12915.
  $menu_links['menu-footer-nav_aporta-awards:node/12915'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'node/12915',
    'router_path' => 'node/%',
    'link_title' => 'Aporta Awards',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_aporta-awards:node/12915',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_innovacin:<front>',
  );
  // Exported menu link: menu-footer-nav_aporta-sariak:node/12918.
  $menu_links['menu-footer-nav_aporta-sariak:node/12918'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'node/12918',
    'router_path' => 'node/%',
    'link_title' => 'Aporta Sariak',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_aporta-sariak:node/12918',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'eu',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_innovacin:<front>',
  );
  // Exported menu link: menu-footer-nav_asesoramiento-y-soporte:node/3471.
  $menu_links['menu-footer-nav_asesoramiento-y-soporte:node/3471'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'node/3471',
    'router_path' => 'node/%',
    'link_title' => 'Asesoramiento y soporte',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_asesoramiento-y-soporte:node/3471',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_interacta:<front>',
  );
  // Exported menu link: menu-footer-nav_aviso-legal:node/11.
  $menu_links['menu-footer-nav_aviso-legal:node/11'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'node/11',
    'router_path' => 'node/%',
    'link_title' => 'Aviso legal',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_aviso-legal:node/11',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_contacto:<front>',
  );
  // Exported menu link: menu-footer-nav_blog:blog.
  $menu_links['menu-footer-nav_blog:blog'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_blog:blog',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_innovacin:<front>',
  );
  // Exported menu link: menu-footer-nav_boletines:boletines.
  $menu_links['menu-footer-nav_boletines:boletines'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'boletines',
    'router_path' => 'boletines',
    'link_title' => 'Boletines',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_boletines:boletines',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_actualidad:<front>',
  );
  // Exported menu link: menu-footer-nav_catlogo-de-datos:<front>.
  $menu_links['menu-footer-nav_catlogo-de-datos:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Catálogo de datos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_catlogo-de-datos:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-nav_conjunto-de-datos:catalogo.
  $menu_links['menu-footer-nav_conjunto-de-datos:catalogo'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'catalogo',
    'router_path' => 'catalogo',
    'link_title' => 'Conjunto de datos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_conjunto-de-datos:catalogo',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_catlogo-de-datos:<front>',
  );
  // Exported menu link: menu-footer-nav_contacto:<front>.
  $menu_links['menu-footer-nav_contacto:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Contacto',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_contacto:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -43,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-nav_cuadro-de-mando:dashboard.
  $menu_links['menu-footer-nav_cuadro-de-mando:dashboard'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'dashboard',
    'router_path' => 'dashboard',
    'link_title' => 'Cuadro de mando',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_cuadro-de-mando:dashboard',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_impacto:<front>',
  );
  // Exported menu link: menu-footer-nav_desafo-aporta:desafios-aporta.
  $menu_links['menu-footer-nav_desafo-aporta:desafios-aporta'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'desafios-aporta',
    'router_path' => 'desafios-aporta',
    'link_title' => 'Desafío Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_desafo-aporta:desafios-aporta',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_innovacin:<front>',
  );
  // Exported menu link: menu-footer-nav_disponibilidad-de-datos:peticiones-datos.
  $menu_links['menu-footer-nav_disponibilidad-de-datos:peticiones-datos'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'peticiones-datos',
    'router_path' => 'peticiones-datos',
    'link_title' => 'Disponibilidad de datos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_disponibilidad-de-datos:peticiones-datos',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_interacta:<front>',
  );
  // Exported menu link: menu-footer-nav_documentacin:documentacion.
  $menu_links['menu-footer-nav_documentacin:documentacion'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'documentacion',
    'router_path' => 'documentacion',
    'link_title' => 'Documentación',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_documentacin:documentacion',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_interacta:<front>',
  );
  // Exported menu link: menu-footer-nav_empresas-reutilizadoras:casos-exito.
  $menu_links['menu-footer-nav_empresas-reutilizadoras:casos-exito'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'casos-exito',
    'router_path' => 'casos-exito',
    'link_title' => 'Empresas reutilizadoras',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_empresas-reutilizadoras:casos-exito',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_impacto:<front>',
  );
  // Exported menu link: menu-footer-nav_encuentros-aporta:encuentros-aporta.
  $menu_links['menu-footer-nav_encuentros-aporta:encuentros-aporta'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'encuentros-aporta',
    'router_path' => 'encuentros-aporta',
    'link_title' => 'Encuentros Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_encuentros-aporta:encuentros-aporta',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_iniciativa-aporta:<front>',
  );
  // Exported menu link: menu-footer-nav_entrevistas:comunidad-risp.
  $menu_links['menu-footer-nav_entrevistas:comunidad-risp'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'comunidad-risp',
    'router_path' => 'comunidad-risp',
    'link_title' => 'Entrevistas',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_entrevistas:comunidad-risp',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_actualidad:<front>',
  );
  // Exported menu link: menu-footer-nav_eventos:eventos.
  $menu_links['menu-footer-nav_eventos:eventos'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'eventos',
    'router_path' => 'eventos',
    'link_title' => 'Eventos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_eventos:eventos',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_actualidad:<front>',
  );
  // Exported menu link: menu-footer-nav_faq:faq-page.
  $menu_links['menu-footer-nav_faq:faq-page'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'faq-page',
    'router_path' => 'faq-page',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_faq:faq-page',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_contacto:<front>',
  );
  // Exported menu link: menu-footer-nav_impacto:<front>.
  $menu_links['menu-footer-nav_impacto:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Impacto',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_impacto:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-nav_informa-sobre:node/26.
  $menu_links['menu-footer-nav_informa-sobre:node/26'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'node/26',
    'router_path' => 'node/%',
    'link_title' => 'Informa sobre',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_informa-sobre:node/26',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_interacta:<front>',
  );
  // Exported menu link: menu-footer-nav_iniciativa-aporta:<front>.
  $menu_links['menu-footer-nav_iniciativa-aporta:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Iniciativa Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_iniciativa-aporta:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-nav_innovacin:<front>.
  $menu_links['menu-footer-nav_innovacin:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Innovación',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_innovacin:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-nav_interacta:<front>.
  $menu_links['menu-footer-nav_interacta:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Interactúa',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_interacta:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-nav_mapa-de-iniciativas:iniciativas.
  $menu_links['menu-footer-nav_mapa-de-iniciativas:iniciativas'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'iniciativas',
    'router_path' => 'iniciativas',
    'link_title' => 'Mapa de iniciativas',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_mapa-de-iniciativas:iniciativas',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_impacto:<front>',
  );
  // Exported menu link: menu-footer-nav_mapa-web:sitemap.
  $menu_links['menu-footer-nav_mapa-web:sitemap'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'sitemap',
    'router_path' => 'sitemap',
    'link_title' => 'Mapa web',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_mapa-web:sitemap',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_contacto:<front>',
  );
  // Exported menu link: menu-footer-nav_noticias:noticias.
  $menu_links['menu-footer-nav_noticias:noticias'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'noticias',
    'router_path' => 'noticias',
    'link_title' => 'Noticias',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_noticias:noticias',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_actualidad:<front>',
  );
  // Exported menu link: menu-footer-nav_premios-aporta:node/10304.
  $menu_links['menu-footer-nav_premios-aporta:node/10304'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'node/10304',
    'router_path' => 'node/%',
    'link_title' => 'Premios Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_premios-aporta:node/10304',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'gl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_innovacin:<front>',
  );
  // Exported menu link: menu-footer-nav_premios-aporta:node/12917.
  $menu_links['menu-footer-nav_premios-aporta:node/12917'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'node/12917',
    'router_path' => 'node/%',
    'link_title' => 'Premios Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_premios-aporta:node/12917',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'es',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_innovacin:<front>',
  );
  // Exported menu link: menu-footer-nav_premis-aporta:node/12916.
  $menu_links['menu-footer-nav_premis-aporta:node/12916'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'node/12916',
    'router_path' => 'node/%',
    'link_title' => 'Premis Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_premis-aporta:node/12916',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'ca',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_innovacin:<front>',
  );
  // Exported menu link: menu-footer-nav_punto-sparql:sparql.
  $menu_links['menu-footer-nav_punto-sparql:sparql'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'sparql',
    'router_path' => 'sparql',
    'link_title' => 'Punto SPARQL',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_punto-sparql:sparql',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_catlogo-de-datos:<front>',
  );
  // Exported menu link: menu-footer-nav_sectores:<front>.
  $menu_links['menu-footer-nav_sectores:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Sectores',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_sectores:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('API');
  t('Acerca de iniciativa Aporta');
  t('Actualidad');
  t('Advice and Support');
  t('Agricultura');
  t('Aholkularitza eta Laguntza');
  t('Aplicaciones');
  t('Aporta Awards');
  t('Aporta Awards (menu position rule)');
  t('Aporta Challenge');
  t('Aporta Challenge (menu position rule)');
  t('Aporta Sariak');
  t('Aporta erronka');
  t('Asesoramento e soporte');
  t('Asesoramiento y Soporte');
  t('Asesoramiento y soporte');
  t('Assessorament i suport');
  t('Aviso legal');
  t('Blog');
  t('Boletines');
  t('Caso de Éxito');
  t('Catálogo de datos');
  t('Comparte tu Aplicación');
  t('Conjunto de datos');
  t('Conjuntos de Datos');
  t('Contact');
  t('Contacte');
  t('Contacto');
  t('Cuadro de Mando');
  t('Cuadro de mando');
  t('Desafiament Aporta');
  t('Desafío Aporta');
  t('Disponibilidad de datos');
  t('Documentación');
  t('Empresas reutilizadoras');
  t('Encuentros Aporta');
  t('Entrevistas');
  t('Eventos');
  t('FAQ');
  t('Honi buruzko informazioa');
  t('Impacto');
  t('Informa sobre');
  t('Iniciativa Aporta');
  t('Iniciativas');
  t('Inicio');
  t('Innovación');
  t('Interactúa');
  t('Kontaktua');
  t('Mapa de Iniciativas');
  t('Mapa de iniciativas');
  t('Mapa web');
  t('Noticias');
  t('Petición de datos');
  t('Premios Aporta');
  t('Premis Aporta');
  t('Punto SPARQL');
  t('Report on');
  t('Sectores');
  t('Users (menu position rule)');

  return $menu_links;
}
