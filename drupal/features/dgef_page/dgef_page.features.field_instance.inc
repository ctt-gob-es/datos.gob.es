<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_page (datos.gob.es)".
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
 * dgef_page.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dgef_page_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_ficheros_externos_adjuntos-field_ext_file_size'.
  $field_instances['field_collection_item-field_ficheros_externos_adjuntos-field_ext_file_size'] = array(
    'bundle' => 'field_ficheros_externos_adjuntos',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Ejemplos: 1.1 MB, 325 bytes, etc',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_ext_file_size',
    'label' => 'Tamaño',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 16,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_ficheros_externos_adjuntos-field_ext_file_tipo'.
  $field_instances['field_collection_item-field_ficheros_externos_adjuntos-field_ext_file_tipo'] = array(
    'bundle' => 'field_ficheros_externos_adjuntos',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Formatos con icono específico: CSV, DOCX, DOC, HTML, JSON, PDF, RDF, SQL, TXT, XSLX, XLS, XML y ZIP',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_ext_file_tipo',
    'label' => 'Tipo',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 6,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_ficheros_externos_adjuntos-field_ext_file_titulo'.
  $field_instances['field_collection_item-field_ficheros_externos_adjuntos-field_ext_file_titulo'] = array(
    'bundle' => 'field_ficheros_externos_adjuntos',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_ext_file_titulo',
    'label' => 'Título',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_ficheros_externos_adjuntos-field_ext_file_url'.
  $field_instances['field_collection_item-field_ficheros_externos_adjuntos-field_ext_file_url'] = array(
    'bundle' => 'field_ficheros_externos_adjuntos',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'URL al documento externo',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_ext_file_url',
    'label' => 'URL',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-page-field_ficheros_externos_adjuntos'.
  $field_instances['node-page-field_ficheros_externos_adjuntos'] = array(
    'bundle' => 'page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'carousel_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Agregar',
          'delete' => 'Eliminar',
          'description' => TRUE,
          'edit' => 'Editar',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ficheros_externos_adjuntos',
    'label' => 'Descargas externas adjuntas',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-page-field_page_descargas'.
  $field_instances['node-page-field_page_descargas'] = array(
    'bundle' => 'page',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'carousel_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'dge_formatters',
        'settings' => array(),
        'type' => 'file_dge_table',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_page_descargas',
    'label' => 'Descargas',
    'required' => 0,
    'settings' => array(
      'description_field' => 1,
      'file_directory' => 'pagefiles',
      'file_extensions' => 'txt pdf doc docx ppt pptx xls xlsx mov mp3 avi mp4 mpeg png gif jpg jpeg zip rar tar gz odt ods odp',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Descargas');
  t('Descargas externas adjuntas');
  t('Ejemplos: 1.1 MB, 325 bytes, etc');
  t('Formatos con icono específico: CSV, DOCX, DOC, HTML, JSON, PDF, RDF, SQL, TXT, XSLX, XLS, XML y ZIP');
  t('Tamaño');
  t('Tipo');
  t('Título');
  t('URL');
  t('URL al documento externo');

  return $field_instances;
}
