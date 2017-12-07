<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
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

  // Exported menu link: main-menu_acerca-de-la-iniciativa-aporta:<front>.
  $menu_links['main-menu_acerca-de-la-iniciativa-aporta:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Acerca de la Iniciativa APORTA',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_acerca-de-la-iniciativa-aporta:<front>',
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
    'parent_identifier' => 'main-menu_iniciativa-aporta:<void1>',
  );
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
  // Exported menu link: main-menu_api:http://172.22.195.73:8060/ckan/api.
  $menu_links['main-menu_api:http://172.22.195.73:8060/ckan/api'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://172.22.195.73:8060/ckan/api',
    'router_path' => '',
    'link_title' => 'API',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_api:http://172.22.195.73:8060/ckan/api',
      'external' => 1,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_catlogo-de-datos:<void2>',
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
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_impacto:<void3>',
  );
  // Exported menu link: main-menu_aporta-meetings-menu-position-rule:menu-position/6.
  $menu_links['main-menu_aporta-meetings-menu-position-rule:menu-position/6'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/6',
    'router_path' => 'menu-position/%',
    'link_title' => 'Aporta meetings (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_aporta-meetings-menu-position-rule:menu-position/6',
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
    'parent_identifier' => 'main-menu_encuentros-aporta:encuentros-aporta',
  );
  // Exported menu link: main-menu_apps-menu-position-rule:menu-position/2.
  $menu_links['main-menu_apps-menu-position-rule:menu-position/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/2',
    'router_path' => 'menu-position/%',
    'link_title' => 'Apps (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_apps-menu-position-rule:menu-position/2',
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
    'parent_identifier' => 'main-menu_aplicaciones:aplicaciones',
  );
  // Exported menu link: main-menu_asesoramiento-y-soporte:<front>.
  $menu_links['main-menu_asesoramiento-y-soporte:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Asesoramiento y Soporte',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_asesoramiento-y-soporte:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_blogs-menu-position-rule:menu-position/1.
  $menu_links['main-menu_blogs-menu-position-rule:menu-position/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/1',
    'router_path' => 'menu-position/%',
    'link_title' => 'Blogs (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_blogs-menu-position-rule:menu-position/1',
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
    'parent_identifier' => 'main-menu_noticias-:blog',
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
    'weight' => -49,
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
  // Exported menu link: main-menu_casos-de-xito:casos-exito.
  $menu_links['main-menu_casos-de-xito:casos-exito'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'casos-exito',
    'router_path' => 'casos-exito',
    'link_title' => 'Casos de Éxito',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_casos-de-xito:casos-exito',
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
  // Exported menu link: main-menu_comunidad-risp:comunidad-risp.
  $menu_links['main-menu_comunidad-risp:comunidad-risp'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'comunidad-risp',
    'router_path' => 'comunidad-risp',
    'link_title' => 'Comunidad RISP',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_comunidad-risp:comunidad-risp',
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
    'parent_identifier' => 'main-menu_actualidad:<void5>',
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
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_contact:node/2',
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
    'parent_identifier' => 'main-menu_informa-sobre:node/27',
  );
  // Exported menu link: main-menu_contacte:node/3.
  $menu_links['main-menu_contacte:node/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Contacte',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_contacte:node/3',
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
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_contacto:node/1',
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
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_contacto:node/4',
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
  // Exported menu link: main-menu_cuadro-de-mando:<front>.
  $menu_links['main-menu_cuadro-de-mando:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Cuadro de Mando',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_cuadro-de-mando:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_impacto:<void3>',
  );
  // Exported menu link: main-menu_data-requests-menu-position-rule:menu-position/9.
  $menu_links['main-menu_data-requests-menu-position-rule:menu-position/9'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/9',
    'router_path' => 'menu-position/%',
    'link_title' => 'Data requests (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_data-requests-menu-position-rule:menu-position/9',
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
    'parent_identifier' => 'main-menu_peticiones-de-datos:peticiones-datos',
  );
  // Exported menu link: main-menu_docs-menu-position-rule:menu-position/5.
  $menu_links['main-menu_docs-menu-position-rule:menu-position/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/5',
    'router_path' => 'menu-position/%',
    'link_title' => 'Docs (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_docs-menu-position-rule:menu-position/5',
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
    'parent_identifier' => 'main-menu_documentacin:documentacion',
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
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_encuentros-aporta:encuentros-aporta.
  $menu_links['main-menu_encuentros-aporta:encuentros-aporta'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'encuentros-aporta',
    'router_path' => 'encuentros-aporta',
    'link_title' => 'Encuentros APORTA',
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
    'weight' => -49,
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
  // Exported menu link: main-menu_events-menu-position-rule:menu-position/8.
  $menu_links['main-menu_events-menu-position-rule:menu-position/8'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/8',
    'router_path' => 'menu-position/%',
    'link_title' => 'Events (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_events-menu-position-rule:menu-position/8',
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
    'parent_identifier' => 'main-menu_eventos:eventos',
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
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_informa-sobre:node/26',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'es',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_informa-sobre:node/27.
  $menu_links['main-menu_informa-sobre:node/27'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/27',
    'router_path' => 'node/%',
    'link_title' => 'Informa sobre',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_informa-sobre:node/27',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'en',
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
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_informa-sobre:node/28',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
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
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_informa-sobre:node/29',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'gl',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_informa-sobre:node/30.
  $menu_links['main-menu_informa-sobre:node/30'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/30',
    'router_path' => 'node/%',
    'link_title' => 'Informa sobre',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_informa-sobre:node/30',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'eu',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_iniciativa-aporta:<void1>.
  $menu_links['main-menu_iniciativa-aporta:<void1>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<void1>',
    'router_path' => '<void1>',
    'link_title' => 'Iniciativa aporta',
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
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_interviews-menu-position-rule:menu-position/7.
  $menu_links['main-menu_interviews-menu-position-rule:menu-position/7'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/7',
    'router_path' => 'menu-position/%',
    'link_title' => 'Interviews (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_interviews-menu-position-rule:menu-position/7',
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
    'parent_identifier' => 'main-menu_comunidad-risp:comunidad-risp',
  );
  // Exported menu link: main-menu_kontaktua:node/5.
  $menu_links['main-menu_kontaktua:node/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/5',
    'router_path' => 'node/%',
    'link_title' => 'Kontaktua',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_kontaktua:node/5',
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
    'parent_identifier' => 'main-menu_informa-sobre:node/30',
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
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_impacto:<void3>',
  );
  // Exported menu link: main-menu_mis-casos-de-xito:admin/dashboard/success.
  $menu_links['main-menu_mis-casos-de-xito:admin/dashboard/success'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/dashboard/success',
    'router_path' => 'admin/dashboard/success',
    'link_title' => 'Mis casos de éxito',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_mis-casos-de-xito:admin/dashboard/success',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_mi-cuenta:user',
  );
  // Exported menu link: main-menu_newsletters-menu-position-rule:menu-position/3.
  $menu_links['main-menu_newsletters-menu-position-rule:menu-position/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/3',
    'router_path' => 'menu-position/%',
    'link_title' => 'Newsletters (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_newsletters-menu-position-rule:menu-position/3',
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
    'parent_identifier' => 'main-menu_boletines:boletines',
  );
  // Exported menu link: main-menu_noticias-:blog.
  $menu_links['main-menu_noticias-:blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Noticias ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_noticias-:blog',
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
    'parent_identifier' => 'main-menu_actualidad:<void5>',
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
  // Exported menu link: main-menu_peticiones-de-datasets-no-asignadas:admin/dashboard/unassigned-requests.
  $menu_links['main-menu_peticiones-de-datasets-no-asignadas:admin/dashboard/unassigned-requests'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/dashboard/unassigned-requests',
    'router_path' => 'admin/dashboard/unassigned-requests',
    'link_title' => 'Peticiones de Datasets no asignadas',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'external' => 0,
      'alter' => TRUE,
      'identifier' => 'main-menu_peticiones-de-datasets-no-asignadas:admin/dashboard/unassigned-requests',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_mi-cuenta:user',
  );
  // Exported menu link: main-menu_peticiones-de-datos:peticiones-datos.
  $menu_links['main-menu_peticiones-de-datos:peticiones-datos'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'peticiones-datos',
    'router_path' => 'peticiones-datos',
    'link_title' => 'Peticiones de Datos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_peticiones-de-datos:peticiones-datos',
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
    'parent_identifier' => 'main-menu_interacta:<void4>',
  );
  // Exported menu link: main-menu_punto-sparql:http://172.22.195.73:8060/ckan/sparql.
  $menu_links['main-menu_punto-sparql:http://172.22.195.73:8060/ckan/sparql'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://172.22.195.73:8060/ckan/sparql',
    'router_path' => '',
    'link_title' => 'Punto Sparql',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_punto-sparql:http://172.22.195.73:8060/ckan/sparql',
      'external' => 1,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_catlogo-de-datos:<void2>',
  );
  // Exported menu link: main-menu_search:<void6>.
  $menu_links['main-menu_search:<void6>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<void6>',
    'router_path' => '<void6>',
    'link_title' => 'Search',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'unaltered_hidden' => 0,
      'external' => TRUE,
      'identifier' => 'main-menu_search:<void6>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_success-menu-position-rule:menu-position/4.
  $menu_links['main-menu_success-menu-position-rule:menu-position/4'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-position/4',
    'router_path' => 'menu-position/%',
    'link_title' => 'Success (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
      ),
      'external' => 0,
      'identifier' => 'main-menu_success-menu-position-rule:menu-position/4',
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
    'parent_identifier' => 'main-menu_casos-de-xito:casos-exito',
  );
  // Exported menu link: main-menu_user:<void7>.
  $menu_links['main-menu_user:<void7>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<void7>',
    'router_path' => '<void7>',
    'link_title' => 'User',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'unaltered_hidden' => 0,
      'external' => TRUE,
      'identifier' => 'main-menu_user:<void7>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
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
  // Exported menu link: menu-footer-nav_acerca-de-iniciativa-aporta:<front>.
  $menu_links['menu-footer-nav_acerca-de-iniciativa-aporta:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Acerca de iniciativa Aporta',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_acerca-de-iniciativa-aporta:<front>',
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
  // Exported menu link: menu-footer-nav_api:<front>.
  $menu_links['menu-footer-nav_api:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Api',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_api:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
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
  // Exported menu link: menu-footer-nav_asesoramiento-y-soporte:<front>.
  $menu_links['menu-footer-nav_asesoramiento-y-soporte:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Asesoramiento y Soporte',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_asesoramiento-y-soporte:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
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
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_contacto:<front>',
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
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_actualidad:<front>',
  );
  // Exported menu link: menu-footer-nav_casos-de-xito:casos-exito.
  $menu_links['menu-footer-nav_casos-de-xito:casos-exito'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'casos-exito',
    'router_path' => 'casos-exito',
    'link_title' => 'Casos de Éxito',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_casos-de-xito:casos-exito',
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
  // Exported menu link: menu-footer-nav_catlogo-de-datos:catalogo.
  $menu_links['menu-footer-nav_catlogo-de-datos:catalogo'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'catalogo',
    'router_path' => 'catalogo',
    'link_title' => 'Catálogo de datos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_catlogo-de-datos:catalogo',
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
  // Exported menu link: menu-footer-nav_comunidad-risp:comunidad-risp.
  $menu_links['menu-footer-nav_comunidad-risp:comunidad-risp'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'comunidad-risp',
    'router_path' => 'comunidad-risp',
    'link_title' => 'Comunidad RISP',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_comunidad-risp:comunidad-risp',
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
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-nav_cuadro-de-mando:<front>.
  $menu_links['menu-footer-nav_cuadro-de-mando:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Cuadro de mando',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_cuadro-de-mando:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_impacto:<front>',
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
  // Exported menu link: menu-footer-nav_faq:faq.
  $menu_links['menu-footer-nav_faq:faq'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'faq',
    'router_path' => 'faq',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_faq:faq',
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
    'link_title' => 'Iniciativa aporta',
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
    'weight' => -47,
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
    'weight' => -50,
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
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_contacto:<front>',
  );
  // Exported menu link: menu-footer-nav_noticias:blog.
  $menu_links['menu-footer-nav_noticias:blog'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Noticias',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_noticias:blog',
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
  // Exported menu link: menu-footer-nav_peticiones-de-datos:peticiones-datos.
  $menu_links['menu-footer-nav_peticiones-de-datos:peticiones-datos'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => 'peticiones-datos',
    'router_path' => 'peticiones-datos',
    'link_title' => 'Peticiones de Datos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_peticiones-de-datos:peticiones-datos',
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
  // Exported menu link: menu-footer-nav_punto-sparql:<front>.
  $menu_links['menu-footer-nav_punto-sparql:<front>'] = array(
    'menu_name' => 'menu-footer-nav',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Punto Sparql',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-nav_punto-sparql:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-nav_catlogo-de-datos:<front>',
  );
  // Exported menu link: menu-footer_accesibilidad:node/16.
  $menu_links['menu-footer_accesibilidad:node/16'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/16',
    'router_path' => 'node/%',
    'link_title' => 'Accesibilidad',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer_accesibilidad:node/16',
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
  );
  // Exported menu link: menu-footer_aviso-legal:node/11.
  $menu_links['menu-footer_aviso-legal:node/11'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/11',
    'router_path' => 'node/%',
    'link_title' => 'Aviso legal',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer_aviso-legal:node/11',
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
  );
  // Exported menu link: menu-footer_contacto:node/1.
  $menu_links['menu-footer_contacto:node/1'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Contacto',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer_contacto:node/1',
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
  );
  // Exported menu link: menu-footer_faq:faq.
  $menu_links['menu-footer_faq:faq'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'faq',
    'router_path' => 'faq',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer_faq:faq',
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
  );
  // Exported menu link: menu-footer_poltica-de-cookies:node/21.
  $menu_links['menu-footer_poltica-de-cookies:node/21'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/21',
    'router_path' => 'node/%',
    'link_title' => 'Política de cookies',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer_poltica-de-cookies:node/21',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-header-actions_buscar:<front>.
  $menu_links['menu-header-actions_buscar:<front>'] = array(
    'menu_name' => 'menu-header-actions',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Buscar',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-header-actions_buscar:<front>',
      'external' => 0,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-header-actions_login:user/login.
  $menu_links['menu-header-actions_login:user/login'] = array(
    'menu_name' => 'menu-header-actions',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Login',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-header-actions_login:user/login',
      'external' => 0,
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
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('API');
  t('Accesibilidad');
  t('Acerca de iniciativa Aporta');
  t('Acerca de la Iniciativa APORTA');
  t('Actualidad');
  t('Api');
  t('Aplicaciones');
  t('Aporta meetings (menu position rule)');
  t('Apps (menu position rule)');
  t('Asesoramiento y Soporte');
  t('Aviso legal');
  t('Blogs (menu position rule)');
  t('Boletines');
  t('Buscar');
  t('Caso de Éxito');
  t('Casos de Éxito');
  t('Catálogo de datos');
  t('Comparte tu Aplicación');
  t('Comunidad RISP');
  t('Conjuntos de Datos');
  t('Contact');
  t('Contacte');
  t('Contacto');
  t('Cuadro de Mando');
  t('Cuadro de mando');
  t('Data requests (menu position rule)');
  t('Docs (menu position rule)');
  t('Documentación');
  t('Encuentros APORTA');
  t('Encuentros Aporta');
  t('Eventos');
  t('Events (menu position rule)');
  t('FAQ');
  t('Impacto');
  t('Informa sobre');
  t('Iniciativa aporta');
  t('Inicio');
  t('Interactúa');
  t('Interviews (menu position rule)');
  t('Kontaktua');
  t('Login');
  t('Mapa de Iniciativas');
  t('Mapa de iniciativas');
  t('Mapa web');
  t('Mis casos de éxito');
  t('Newsletters (menu position rule)');
  t('Noticias');
  t('Noticias ');
  t('Peticiones de Datasets no asignadas');
  t('Peticiones de Datos');
  t('Petición de datos');
  t('Política de cookies');
  t('Punto Sparql');
  t('Search');
  t('Success (menu position rule)');
  t('User');
  t('Users (menu position rule)');

  return $menu_links;
}
