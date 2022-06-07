<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_migrate (datos.gob.es)".
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
 * dgef_migrate.migrate.inc
 */

/**
 * Implements hook_migrate_preset().
 */
function dgef_migrate_migrate_preset() {
  $export = array();

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGENodeApp';
  $migrate->class_name = 'DGENodeApp';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate Apps',
    'source_type' => 'aplicaciones',
    'destination_type' => 'app',
    'dependencies' => array(
      0 => 'DGEUserEditorMigration',
      1 => 'DGEUserOrganizationMigration',
    ),
    'soft_dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_category' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_category',
      'source_field' => 'field_categoria_aplicacion',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:18:"field_app_category";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:26:"field_categoria_aplicacion";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:36:"f736446beTermcategor_as_aplicaciones";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_category:create_term' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_category:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_app_category:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_category:ignore_case' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_category:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_app_category:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_category:source_type' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_category:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_app_category:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:3:"tid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_dataset_url' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_dataset_url',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_app_dataset_url";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_dataset_url:attributes' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_dataset_url:attributes',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:32:"field_app_dataset_url:attributes";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_dataset_url:language' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_dataset_url:language',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_app_dataset_url:language";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_dataset_url:title' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_dataset_url:title',
      'source_field' => 'field_catalogo_utilizado',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_app_dataset_url:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:24:"field_catalogo_utilizado";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_developer' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_developer',
      'source_field' => 'field_desarrollador',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_app_developer";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:19:"field_desarrollador";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_image' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_image',
      'source_field' => 'field_imagen_aplicacion',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:15:"field_app_image";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:23:"field_imagen_aplicacion";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_image:alt' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_image:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_app_image:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_image:file_class' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_image:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_app_image:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_image:preserve_files' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_image:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_app_image:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_image:title' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_image:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_app_image:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_images' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_images',
      'source_field' => 'field_imagen_aplicacion',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:16:"field_app_images";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:23:"field_imagen_aplicacion";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_images:alt' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_images:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_app_images:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_images:file_class' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_images:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_app_images:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_images:preserve_files' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_images:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:31:"field_app_images:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_images:title' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_images:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_app_images:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_license' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_license',
      'source_field' => 'field_licencia',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_app_license";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:14:"field_licencia";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_platform' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_platform',
      'source_field' => 'field_plataforma',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:18:"field_app_platform";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:16:"field_plataforma";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:23:"f736446beTermplataforma";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_platform:create_term' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_platform:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_app_platform:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_platform:ignore_case' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_platform:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_app_platform:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_platform:source_type' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_platform:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_app_platform:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:3:"tid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_publish_date' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_publish_date',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_app_publish_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_publish_date:rrule' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_publish_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:28:"field_app_publish_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_publish_date:timezone' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_publish_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:31:"field_app_publish_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_publish_date:to' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_publish_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:25:"field_app_publish_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_tags' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_tags',
      'source_field' => 'field_etiquetas_aplicacion',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_app_tags";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:26:"field_etiquetas_aplicacion";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGETaxonomyTermTagsApp";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_tags:create_term' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_tags:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_app_tags:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_tags:ignore_case' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_tags:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_app_tags:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_tags:source_type' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_tags:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_app_tags:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:3:"tid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_update_date' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_update_date',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_app_update_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_update_date:rrule' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_update_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_app_update_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_update_date:timezone' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_update_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_app_update_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_update_date:to' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_update_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:24:"field_app_update_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_url' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_url',
      'source_field' => 'field_url',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:13:"field_app_url";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:9:"field_url";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_url:attributes' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_url:attributes',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:24:"field_app_url:attributes";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_url:language' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_url:language',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_app_url:language";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_app_url:title' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_app_url:title',
      'source_field' => 'title',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_app_url:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:5:"title";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_sender_company' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_sender_company',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_sender_company";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_sender_email' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_sender_email',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:18:"field_sender_email";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_sender_name' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_sender_name',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_sender_name";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_sender_phone' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_sender_phone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:18:"field_sender_phone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_sender_show_data' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_sender_show_data',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_sender_show_data";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_sender_terms_of_use' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'field_sender_terms_of_use',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:25:"field_sender_terms_of_use";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGENodeApp',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGENodeApp'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGENodeBlogFromBlog';
  $migrate->class_name = 'DGENodeBlogFromBlog';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate From Blog To Blog (to 28/02/2013)',
    'source_type' => 'blog',
    'destination_type' => 'blog',
    'dependencies' => array(
      0 => 'DGEUserEditorMigration',
    ),
    'soft_dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_date' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_date',
      'source_field' => 'field_fecha_blog',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:15:"field_blog_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:16:"field_fecha_blog";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_date:rrule' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_blog_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_date:timezone' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:24:"field_blog_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_date:to' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:18:"field_blog_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:16:"field_blog_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:description' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_files:description',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:28:"field_blog_files:description";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:destination_dir' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_files:destination_dir',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:32:"field_blog_files:destination_dir";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:destination_file' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_files:destination_file',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:33:"field_blog_files:destination_file";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:display' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_files:display',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:24:"field_blog_files:display";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:file_class' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_files:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_blog_files:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:file_replace' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_files:file_replace',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_blog_files:file_replace";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:preserve_files' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_files:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:31:"field_blog_files:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:source_dir' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_files:source_dir',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_blog_files:source_dir";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:urlencode' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_files:urlencode',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_blog_files:urlencode";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_image' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_image',
      'source_field' => 'field_imagen_blog',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:16:"field_blog_image";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:17:"field_imagen_blog";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_image:alt' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_image:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_blog_image:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_image:file_class' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_image:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_blog_image:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_image:preserve_files' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_image:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:31:"field_blog_image:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_image:title' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_image:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_blog_image:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_source' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_source',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_blog_source";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_tags' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_tags',
      'source_field' => 'field_categoria_blog',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:15:"field_blog_tags";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:20:"field_categoria_blog";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:23:"DGETaxonomyTermTagsBlog";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_tags:create_term' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_tags:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_blog_tags:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_tags:ignore_case' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_tags:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_blog_tags:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_tags:source_type' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'field_blog_tags:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_blog_tags:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:3:"tid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'DGENodeBlogFromBlog',
      'destination_field' => 'uid',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGEUserEditorMigration";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGENodeBlogFromBlog'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGENodeBulletinFromBlog';
  $migrate->class_name = 'DGENodeBulletinFromBlog';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate From Bulletin To Blog (from 28/02/2013)',
    'source_type' => 'blog',
    'destination_type' => 'bulletin',
    'dependencies' => array(
      0 => 'DGEUserEditorMigration',
    ),
    'soft_dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_date' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_date',
      'source_field' => 'field_fecha_blog',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_bulletin_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:16:"field_fecha_blog";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_date:rrule' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:25:"field_bulletin_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_date:timezone' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:28:"field_bulletin_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_date:to' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_bulletin_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_description' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_description',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_bulletin_description";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_description:format' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_description:format',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:33:"field_bulletin_description:format";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_header' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_header',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_bulletin_header";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_header:alt' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_header:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:25:"field_bulletin_header:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_header:destination_dir' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_header:destination_dir',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:37:"field_bulletin_header:destination_dir";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_header:destination_file' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_header:destination_file',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:38:"field_bulletin_header:destination_file";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_header:file_class' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_header:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:32:"field_bulletin_header:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_header:file_replace' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_header:file_replace',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:34:"field_bulletin_header:file_replace";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_header:preserve_files' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_header:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:36:"field_bulletin_header:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_header:source_dir' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_header:source_dir',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:32:"field_bulletin_header:source_dir";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_header:title' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_header:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_bulletin_header:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_header:urlencode' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_header:urlencode',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:31:"field_bulletin_header:urlencode";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_parag' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_parag',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_bulletin_parag";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_parag:revision_id' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_parag:revision_id',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:32:"field_bulletin_parag:revision_id";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_tags' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_tags',
      'source_field' => 'field_categoria_blog',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_bulletin_tags";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:20:"field_categoria_blog";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:23:"DGETaxonomyTermTagsBlog";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_tags:create_term' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_tags:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:31:"field_bulletin_tags:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_tags:ignore_case' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_tags:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:31:"field_bulletin_tags:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_bulletin_tags:source_type' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'field_bulletin_tags:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:31:"field_bulletin_tags:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:3:"tid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'DGENodeBulletinFromBlog',
      'destination_field' => 'uid',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGEUserEditorMigration";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGENodeBulletinFromBlog'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGENodeDocEstrategiaRispFromSaberMas';
  $migrate->class_name = 'DGENodeDocEstrategiaRispFromSaberMas';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate From Saber Mas Estrategias Risp To Doc Estrategias Risp',
    'source_type' => 'saber_mas',
    'destination_type' => 'doc',
    'dependencies' => array(
      0 => 'DGEUserEditorMigration',
    ),
    'soft_dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_date',
      'source_field' => 'field_fecha_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:21:"field_fecha_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:rrule' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_doc_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:timezone' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:23:"field_doc_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:to' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_doc_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_file',
      'source_field' => 'field_fichero_adjunto_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_file";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:31:"field_fichero_adjunto_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:description' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_file:description',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_file:description";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:display' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_file:display',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_doc_file:display";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:file_class' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_file:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:25:"field_doc_file:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:preserve_files' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_file:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_file:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_image',
      'source_field' => 'field_imagen_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:15:"field_doc_image";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:22:"field_imagen_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:alt' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_image:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_doc_image:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:file_class' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_image:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_image:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:preserve_files' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_image:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_doc_image:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:title' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_image:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_doc_image:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_tags',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_tags";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:create_term' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_tags:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:ignore_case' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_tags:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:source_type' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_tags:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tx_type:create_term' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_tx_type:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_tx_type:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tx_type:ignore_case' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_tx_type:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_tx_type:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_youtube' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'field_doc_youtube',
      'source_field' => 'field_video_youtube',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_doc_youtube";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:19:"field_video_youtube";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
      'destination_field' => 'uid',
      'source_field' => 'uid',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:3:"uid";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGEUserEditorMigration";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGENodeDocEstrategiaRispFromSaberMas'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGENodeDocEstudiosFromSaberMas';
  $migrate->class_name = 'DGENodeDocEstudiosFromSaberMas';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate From Saber Mas Estudios To Doc Estudios',
    'source_type' => 'saber_mas',
    'destination_type' => 'doc',
    'dependencies' => array(
      0 => 'DGEUserEditorMigration',
    ),
    'soft_dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_date',
      'source_field' => 'field_fecha_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:21:"field_fecha_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:rrule' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_doc_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:timezone' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:23:"field_doc_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:to' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_doc_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_file',
      'source_field' => 'field_fichero_adjunto_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_file";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:31:"field_fichero_adjunto_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:description' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_file:description',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_file:description";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:display' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_file:display',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_doc_file:display";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:file_class' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_file:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:25:"field_doc_file:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:preserve_files' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_file:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_file:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_image',
      'source_field' => 'field_imagen_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:15:"field_doc_image";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:22:"field_imagen_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:alt' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_image:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_doc_image:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:file_class' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_image:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_image:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:preserve_files' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_image:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_doc_image:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:title' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_image:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_doc_image:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_tags',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_tags";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:create_term' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_tags:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:ignore_case' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_tags:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:source_type' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_tags:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tx_type:create_term' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_tx_type:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_tx_type:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tx_type:ignore_case' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_tx_type:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_tx_type:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_youtube' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'field_doc_youtube',
      'source_field' => 'field_video_youtube',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_doc_youtube";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:19:"field_video_youtube";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGENodeDocEstudiosFromSaberMas',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGENodeDocEstudiosFromSaberMas'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGENodeDocFormacionFromSaberMas';
  $migrate->class_name = 'DGENodeDocFormacionFromSaberMas';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate From Saber Mas Normativa To Doc Normativa',
    'source_type' => 'saber_mas',
    'destination_type' => 'doc',
    'dependencies' => array(
      0 => 'DGEUserEditorMigration',
    ),
    'soft_dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_date',
      'source_field' => 'field_fecha_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:21:"field_fecha_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:rrule' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_doc_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:timezone' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:23:"field_doc_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:to' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_doc_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_file',
      'source_field' => 'field_fichero_adjunto_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_file";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:31:"field_fichero_adjunto_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:description' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_file:description',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_file:description";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:display' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_file:display',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_doc_file:display";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:file_class' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_file:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:25:"field_doc_file:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:preserve_files' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_file:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_file:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_image',
      'source_field' => 'field_imagen_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:15:"field_doc_image";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:22:"field_imagen_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:alt' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_image:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_doc_image:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:file_class' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_image:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_image:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:preserve_files' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_image:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_doc_image:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:title' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_image:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_doc_image:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_tags',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_tags";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:create_term' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_tags:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:ignore_case' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_tags:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:source_type' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_tags:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tx_type:create_term' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_tx_type:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_tx_type:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tx_type:ignore_case' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_tx_type:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_tx_type:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_youtube' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'field_doc_youtube',
      'source_field' => 'field_video_youtube',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_doc_youtube";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:19:"field_video_youtube";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'DGENodeDocFormacionFromSaberMas',
      'destination_field' => 'uid',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGEUserEditorMigration";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGENodeDocFormacionFromSaberMas'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGENodeDocGuiaFromSaberMas';
  $migrate->class_name = 'DGENodeDocGuiaFromSaberMas';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate From Saber Mas Normativa To Doc Normativa',
    'source_type' => 'saber_mas',
    'destination_type' => 'doc',
    'dependencies' => array(
      0 => 'DGEUserEditorMigration',
    ),
    'soft_dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_date',
      'source_field' => 'field_fecha_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:21:"field_fecha_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:rrule' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_doc_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:timezone' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:23:"field_doc_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:to' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_doc_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_file',
      'source_field' => 'field_fichero_adjunto_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_file";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:31:"field_fichero_adjunto_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:description' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_file:description',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_file:description";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:display' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_file:display',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_doc_file:display";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:file_class' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_file:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:25:"field_doc_file:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:preserve_files' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_file:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_file:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_image',
      'source_field' => 'field_imagen_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:15:"field_doc_image";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:22:"field_imagen_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:alt' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_image:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_doc_image:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:file_class' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_image:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_image:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:preserve_files' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_image:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_doc_image:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:title' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_image:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_doc_image:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_tags',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_tags";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:create_term' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_tags:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:ignore_case' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_tags:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:source_type' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_tags:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tx_type:create_term' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_tx_type:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_tx_type:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tx_type:ignore_case' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_tx_type:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_tx_type:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_youtube' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'field_doc_youtube',
      'source_field' => 'field_video_youtube',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_doc_youtube";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:19:"field_video_youtube";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'DGENodeDocGuiaFromSaberMas',
      'destination_field' => 'uid',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGEUserEditorMigration";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGENodeDocGuiaFromSaberMas'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGENodeDocNormativaFromSaberMas';
  $migrate->class_name = 'DGENodeDocNormativaFromSaberMas';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate From Saber Mas Normativa To Doc Normativa',
    'source_type' => 'saber_mas',
    'destination_type' => 'doc',
    'dependencies' => array(
      0 => 'DGEUserEditorMigration',
    ),
    'soft_dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_date',
      'source_field' => 'field_fecha_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:21:"field_fecha_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:rrule' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_doc_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:timezone' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:23:"field_doc_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_date:to' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_doc_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_file',
      'source_field' => 'field_fichero_adjunto_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_file";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:31:"field_fichero_adjunto_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:description' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_file:description',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_file:description";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:display' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_file:display',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_doc_file:display";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:file_class' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_file:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:25:"field_doc_file:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_file:preserve_files' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_file:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_file:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_image',
      'source_field' => 'field_imagen_saber_mas:alt',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:15:"field_doc_image";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:26:"field_imagen_saber_mas:alt";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:alt' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_image:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_doc_image:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:file_class' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_image:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_image:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:preserve_files' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_image:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:30:"field_doc_image:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_image:title' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_image:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_doc_image:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_tags',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:14:"field_doc_tags";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:create_term' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_tags:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:ignore_case' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_tags:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tags:source_type' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_tags:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_doc_tags:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tx_type:create_term' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_tx_type:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_tx_type:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_tx_type:ignore_case' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_tx_type:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_doc_tx_type:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_doc_youtube' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'field_doc_youtube',
      'source_field' => 'field_video_youtube',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_doc_youtube";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:19:"field_video_youtube";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'DGENodeDocNormativaFromSaberMas',
      'destination_field' => 'uid',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGEUserEditorMigration";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGENodeDocNormativaFromSaberMas'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGENodeEncuentroAportaFromSaberMas';
  $migrate->class_name = 'DGENodeEncuentroAportaFromSaberMas';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate From Saber Mas Estudios To Doc Estudios',
    'source_type' => 'saber_mas',
    'destination_type' => 'aporta',
    'dependencies' => array(
      0 => 'DGEUserEditorMigration',
    ),
    'soft_dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_aporta_date' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_aporta_date',
      'source_field' => 'field_fecha_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_aporta_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:21:"field_fecha_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_aporta_date:rrule' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_aporta_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:23:"field_aporta_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_aporta_date:timezone' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_aporta_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_aporta_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_aporta_date:to' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_aporta_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_aporta_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_aporta_image' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_aporta_image',
      'source_field' => 'field_imagen_saber_mas',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:18:"field_aporta_image";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:22:"field_imagen_saber_mas";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_aporta_image:alt' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_aporta_image:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_aporta_image:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_aporta_image:file_class' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_aporta_image:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_aporta_image:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_aporta_image:preserve_files' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_aporta_image:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:33:"field_aporta_image:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_aporta_image:title' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_aporta_image:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:24:"field_aporta_image:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_aporta_subtitle' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_aporta_subtitle',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_aporta_subtitle";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_aporta_workgroup' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_aporta_workgroup',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_aporta_workgroup";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_aporta_workgroup:revision_id' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_aporta_workgroup:revision_id',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:34:"field_aporta_workgroup:revision_id";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_group_aporta_doc' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_group_aporta_doc',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_group_aporta_doc";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_group_aporta_doc:revision_id' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'field_group_aporta_doc:revision_id',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:34:"field_group_aporta_doc:revision_id";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'DGENodeEncuentroAportaFromSaberMas',
      'destination_field' => 'uid',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGEUserEditorMigration";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGENodeEncuentroAportaFromSaberMas'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGEProfile2OrganizationMigration';
  $migrate->class_name = 'DGEProfile2OrganizationMigration';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate Organization Users Profile2',
    'dependencies' => array(
      0 => 'DGEUserOrganizationMigration',
    ),
  );
  $migrate->fields = array(
    'field_ckan_user_id' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'field_ckan_user_id',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:18:"field_ckan_user_id";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_comments_agency' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'field_comments_agency',
      'source_field' => 'field_comentarios_org_perfil',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_comments_agency";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:28:"field_comentarios_org_perfil";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_other_agency' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'field_other_agency',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:18:"field_other_agency";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_other_agency_name' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'field_other_agency_name',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:23:"field_other_agency_name";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_position_agency' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'field_position_agency',
      'source_field' => 'field_cargo_perfil',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_position_agency";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:18:"field_cargo_perfil";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_root_agency' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'field_root_agency',
      'source_field' => 'field_organismo_raiz',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_root_agency";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:20:"field_organismo_raiz";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:23:"f736446beTermorganismos";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_root_agency:create_term' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'field_root_agency:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_root_agency:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_root_agency:ignore_case' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'field_root_agency:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_root_agency:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_root_agency:source_type' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'field_root_agency:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_root_agency:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:3:"tid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_terms_service' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'field_terms_service',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_terms_service";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'language' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'language',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"language";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'revision_uid' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'revision_uid',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:12:"revision_uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'DGEProfile2OrganizationMigration',
      'destination_field' => 'uid',
      'source_field' => 'uid',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:3:"uid";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:28:"DGEUserOrganizationMigration";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:9:"Terminado";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGEProfile2OrganizationMigration'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGETaxonomyTermTagsApp';
  $migrate->class_name = 'DGETaxonomyTermTagsApp';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate Apps Tags',
    'source_vocabulary' => 'tags',
    'destination_vocabulary' => 'app_tags',
    'soft_dependencies' => array(),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'parent' => (object) array(
      'machine_name' => 'DGETaxonomyTermTagsApp',
      'destination_field' => 'parent',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:6:"parent";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGETaxonomyTermTagsApp";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGETaxonomyTermTagsApp',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGETaxonomyTermTagsApp',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGETaxonomyTermTagsApp'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGETaxonomyTermTagsArticle';
  $migrate->class_name = 'DGETaxonomyTermTagsArticle';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate Article/News Tags',
    'source_vocabulary' => 'tags',
    'destination_vocabulary' => 'blog_tags',
    'soft_dependencies' => array(),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'parent' => (object) array(
      'machine_name' => 'DGETaxonomyTermTagsArticle',
      'destination_field' => 'parent',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:6:"parent";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:26:"DGETaxonomyTermTagsArticle";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGETaxonomyTermTagsArticle',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGETaxonomyTermTagsArticle',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGETaxonomyTermTagsArticle'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGETaxonomyTermTagsBlog';
  $migrate->class_name = 'DGETaxonomyTermTagsBlog';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate Blog Tags',
    'source_vocabulary' => 'tags',
    'destination_vocabulary' => 'blog_tags',
    'soft_dependencies' => array(),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'parent' => (object) array(
      'machine_name' => 'DGETaxonomyTermTagsBlog',
      'destination_field' => 'parent',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:6:"parent";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:23:"DGETaxonomyTermTagsBlog";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGETaxonomyTermTagsBlog',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGETaxonomyTermTagsBlog',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGETaxonomyTermTagsBlog'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGETaxonomyTermTagsEvent';
  $migrate->class_name = 'DGETaxonomyTermTagsEvent';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate Blog Tags',
    'source_vocabulary' => 'tags',
    'destination_vocabulary' => 'event_tags',
    'soft_dependencies' => array(),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'parent' => (object) array(
      'machine_name' => 'DGETaxonomyTermTagsEvent',
      'destination_field' => 'parent',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:6:"parent";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:24:"DGETaxonomyTermTagsEvent";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'DGETaxonomyTermTagsEvent',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGETaxonomyTermTagsEvent',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGETaxonomyTermTagsEvent'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGEUserEditorMigration';
  $migrate->class_name = 'DGEUserEditorMigration';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate Editor Users',
    'soft_dependencies' => array(),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'path' => (object) array(
      'machine_name' => 'DGEUserEditorMigration',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGEUserEditorMigration',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGEUserEditorMigration'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'DGEUserOrganizationMigration';
  $migrate->class_name = 'DGEUserOrganizationMigration';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_connection' => 'f736446be_legacy',
    'source_version' => 7,
    'source_system' => 'Drupal 7',
    'description' => 'Migrate Organization Users',
    'soft_dependencies' => array(),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'path' => (object) array(
      'machine_name' => 'DGEUserOrganizationMigration',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'DGEUserOrganizationMigration',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'picture' => (object) array(
      'machine_name' => 'DGEUserOrganizationMigration',
      'destination_field' => 'picture',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"picture";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:2;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:3:"DNM";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'signature' => (object) array(
      'machine_name' => 'DGEUserOrganizationMigration',
      'destination_field' => 'signature',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:9:"signature";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:2;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:3:"DNM";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'signature_format' => (object) array(
      'machine_name' => 'DGEUserOrganizationMigration',
      'destination_field' => 'signature_format',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:16:"signature_format";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:2;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:3:"DNM";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['DGEUserOrganizationMigration'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'f736446beFile';
  $migrate->class_name = 'DrupalFile7Migration';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_dir' => '',
    'description' => 'Migration of files from Drupal 7',
    'user_migration' => 'f736446beUser',
    'soft_dependencies' => array(),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'file_replace' => (object) array(
      'machine_name' => 'f736446beFile',
      'destination_field' => 'file_replace',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:12:"file_replace";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'f736446beFile',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'f736446beFile',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'source_dir' => (object) array(
      'machine_name' => 'f736446beFile',
      'destination_field' => 'source_dir',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:10:"source_dir";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:39:"http://datos.gob.es/sites/default/files";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'f736446beFile',
      'destination_field' => 'uid',
      'source_field' => 'uid',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:3:"uid";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'urlencode' => (object) array(
      'machine_name' => 'f736446beFile',
      'destination_field' => 'urlencode',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:9:"urlencode";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['f736446beFile'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'f736446beNodearticle';
  $migrate->class_name = 'DrupalNode7Migration';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_type' => 'article',
    'destination_type' => 'blog',
    'description' => 'Migration of Noticias nodes from Drupal 7',
    'user_migration' => 'f736446beUser',
    'soft_dependencies' => array(
      0 => 'f736446beFile',
    ),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_date' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_date',
      'source_field' => 'field_fecha_articulo',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:15:"field_blog_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:20:"field_fecha_articulo";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_date:rrule' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_blog_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_date:timezone' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:24:"field_blog_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_date:to' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:18:"field_blog_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_files',
      'source_field' => 'field_fichero_adjunto',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:16:"field_blog_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:21:"field_fichero_adjunto";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:description' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_files:description',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:28:"field_blog_files:description";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:display' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_files:display',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:24:"field_blog_files:display";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:file_class' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_files:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_blog_files:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_files:preserve_files' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_files:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:31:"field_blog_files:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_image' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_image',
      'source_field' => 'field_image',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:16:"field_blog_image";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:11:"field_image";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_image:alt' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_image:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_blog_image:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_image:file_class' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_image:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_blog_image:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_image:preserve_files' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_image:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:31:"field_blog_image:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_image:title' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_image:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_blog_image:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_source' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_source',
      'source_field' => 'field_fuente',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_blog_source";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:12:"field_fuente";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_tags' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_tags',
      'source_field' => 'field_tags',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:15:"field_blog_tags";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:10:"field_tags";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:26:"DGETaxonomyTermTagsArticle";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_tags:create_term' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_tags:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_blog_tags:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_tags:ignore_case' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_tags:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_blog_tags:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_blog_tags:source_type' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'field_blog_tags:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_blog_tags:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:3:"tid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'f736446beNodearticle',
      'destination_field' => 'uid',
      'source_field' => 'uid',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:3:"uid";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGEUserEditorMigration";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['f736446beNodearticle'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'f736446beNodecomunidadrisp';
  $migrate->class_name = 'DrupalNode7Migration';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_type' => 'comunidadrisp',
    'destination_type' => 'talk',
    'description' => 'Migration of Comunidad RISP nodes from Drupal 7',
    'user_migration' => 'f736446beUser',
    'soft_dependencies' => array(
      0 => 'f736446beFile',
    ),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_company' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_company',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_talk_bio_company";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_contact' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_contact',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_talk_bio_contact";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_country' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_country',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_talk_bio_country";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_country:create_term' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_country:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:34:"field_talk_bio_country:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_country:ignore_case' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_country:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:34:"field_talk_bio_country:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_country:source_type' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_country:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:34:"field_talk_bio_country:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_name' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_name',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_talk_bio_name";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_sector' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_sector',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_talk_bio_sector";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_sector:create_term' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_sector:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:33:"field_talk_bio_sector:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_sector:ignore_case' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_sector:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:33:"field_talk_bio_sector:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_sector:source_type' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_sector:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:33:"field_talk_bio_sector:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_spec' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_spec',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_talk_bio_spec";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_web' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_web',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:18:"field_talk_bio_web";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_web:attributes' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_web:attributes',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:29:"field_talk_bio_web:attributes";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_web:language' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_web:language',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_talk_bio_web:language";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_web:title' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_web:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:24:"field_talk_bio_web:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_bio_works' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_bio_works',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_talk_bio_works";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_date' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_date',
      'source_field' => 'field_fecha_blog',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:15:"field_talk_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:16:"field_fecha_blog";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_date:rrule' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_talk_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_date:timezone' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:24:"field_talk_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_date:to' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:18:"field_talk_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_image' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_image',
      'source_field' => 'field_imagen_blog',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:16:"field_talk_image";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:17:"field_imagen_blog";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_image:alt' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_image:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:20:"field_talk_image:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_image:file_class' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_image:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_talk_image:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_image:preserve_files' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_image:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:31:"field_talk_image:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_image:title' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_image:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_talk_image:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_tags' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_tags',
      'source_field' => 'field_tags',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:15:"field_talk_tags";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:10:"field_tags";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:26:"DGETaxonomyTermTagsArticle";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_tags:create_term' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_tags:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_talk_tags:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_tags:ignore_case' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_tags:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_talk_tags:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_talk_tags:source_type' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'field_talk_tags:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_talk_tags:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:3:"tid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'f736446beNodecomunidadrisp',
      'destination_field' => 'uid',
      'source_field' => 'uid',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:3:"uid";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGEUserEditorMigration";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['f736446beNodecomunidadrisp'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'f736446beNodeevento';
  $migrate->class_name = 'DrupalNode7Migration';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_type' => 'evento',
    'destination_type' => 'event',
    'description' => 'Migration of Evento nodes from Drupal 7',
    'user_migration' => 'f736446beUser',
    'soft_dependencies' => array(
      0 => 'f736446beFile',
    ),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_date' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_date',
      'source_field' => 'field_fecha_evento',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:16:"field_event_date";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:18:"field_fecha_evento";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_date:rrule' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_date:rrule',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_event_date:rrule";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_date:timezone' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_date:timezone',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:25:"field_event_date:timezone";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_date:to' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_date:to',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:19:"field_event_date:to";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_image' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_image',
      'source_field' => 'field_image',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:17:"field_event_image";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:11:"field_image";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:13:"f736446beFile";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_image:alt' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_image:alt',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:21:"field_event_image:alt";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_image:file_class' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_image:file_class',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:28:"field_event_image:file_class";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:14:"MigrateFileFid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_image:preserve_files' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_image:preserve_files',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:32:"field_event_image:preserve_files";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_image:title' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_image:title',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:23:"field_event_image:title";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_tags' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_tags',
      'source_field' => 'field_categoria_evento',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:16:"field_event_tags";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:22:"field_categoria_evento";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:24:"DGETaxonomyTermTagsEvent";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_tags:create_term' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_tags:create_term',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:28:"field_event_tags:create_term";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_tags:ignore_case' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_tags:ignore_case',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:28:"field_event_tags:ignore_case";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_event_tags:source_type' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'field_event_tags:source_type',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:28:"field_event_tags:source_type";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:3:"tid";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'f736446beNodeevento',
      'destination_field' => 'uid',
      'source_field' => 'uid',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:3:"uid";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGEUserEditorMigration";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['f736446beNodeevento'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'f736446beNodepage';
  $migrate->class_name = 'DrupalNode7Migration';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'source_type' => 'page',
    'destination_type' => 'page',
    'description' => 'Migration of Página básica nodes from Drupal 7',
    'user_migration' => 'f736446beUser',
    'soft_dependencies' => array(
      0 => 'f736446beFile',
    ),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'comment' => (object) array(
      'machine_name' => 'f736446beNodepage',
      'destination_field' => 'comment',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:7:"comment";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'f736446beNodepage',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'f736446beNodepage',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'uid' => (object) array(
      'machine_name' => 'f736446beNodepage',
      'destination_field' => 'uid',
      'source_field' => 'uid',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:3:"uid";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:3:"uid";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:22:"DGEUserEditorMigration";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['f736446beNodepage'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'f736446beTermcategor_as_aplicaciones';
  $migrate->class_name = 'DrupalTerm7Migration';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'destination_vocabulary' => 'app_categories',
    'description' => 'Migration of Categorías aplicaciones terms from Drupal 7',
    'source_vocabulary' => 'categor_as_aplicaciones',
    'soft_dependencies' => array(),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'parent' => (object) array(
      'machine_name' => 'f736446beTermcategor_as_aplicaciones',
      'destination_field' => 'parent',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:6:"parent";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:36:"f736446beTermcategor_as_aplicaciones";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'f736446beTermcategor_as_aplicaciones',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'f736446beTermcategor_as_aplicaciones',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['f736446beTermcategor_as_aplicaciones'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'f736446beTermorganismos';
  $migrate->class_name = 'DrupalTerm7Migration';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'destination_vocabulary' => 'agencies',
    'description' => 'Migration of Organismos terms from Drupal 7',
    'source_vocabulary' => 'organismos',
    'soft_dependencies' => array(),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'field_ckan_organization_id' => (object) array(
      'machine_name' => 'f736446beTermorganismos',
      'destination_field' => 'field_ckan_organization_id',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:26:"field_ckan_organization_id";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_ckan_organization_name' => (object) array(
      'machine_name' => 'f736446beTermorganismos',
      'destination_field' => 'field_ckan_organization_name',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:28:"field_ckan_organization_name";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_c_id_dep_ud_principal' => (object) array(
      'machine_name' => 'f736446beTermorganismos',
      'destination_field' => 'field_c_id_dep_ud_principal',
      'source_field' => 'field_c_id_dep_ud_principal',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_c_id_dep_ud_principal";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:27:"field_c_id_dep_ud_principal";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_c_id_ud_organica' => (object) array(
      'machine_name' => 'f736446beTermorganismos',
      'destination_field' => 'field_c_id_ud_organica',
      'source_field' => 'field_c_id_ud_organica',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:22:"field_c_id_ud_organica";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:22:"field_c_id_ud_organica";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_reference_id' => (object) array(
      'machine_name' => 'f736446beTermorganismos',
      'destination_field' => 'field_reference_id',
      'source_field' => 'tid',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:18:"field_reference_id";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:3:"tid";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'field_root_designation_unit' => (object) array(
      'machine_name' => 'f736446beTermorganismos',
      'destination_field' => 'field_root_designation_unit',
      'source_field' => 'field_denominacion_ud_raiz',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:27:"field_root_designation_unit";s:14:"' . "\0" . '*' . "\0" . 'sourceField";s:26:"field_denominacion_ud_raiz";s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'parent' => (object) array(
      'machine_name' => 'f736446beTermorganismos',
      'destination_field' => 'parent',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:6:"parent";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:23:"f736446beTermorganismos";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'f736446beTermorganismos',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'f736446beTermorganismos',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['f736446beTermorganismos'] = $migrate;

  $migrate = new stdClass();
  $migrate->disabled = FALSE; /* Edit this to true to make a default migrate disabled initially */
  $migrate->api_version = 1;
  $migrate->machine_name = 'f736446beTermplataforma';
  $migrate->class_name = 'DrupalTerm7Migration';
  $migrate->group_name = 'f736446be';
  $migrate->status = FALSE;
  $migrate->arguments = array(
    'destination_vocabulary' => 'app_platform',
    'description' => 'Migration of Plataforma terms from Drupal 7',
    'source_vocabulary' => 'plataforma',
    'soft_dependencies' => array(),
    'dependencies' => array(),
  );
  $migrate->fields = array(
    'parent' => (object) array(
      'machine_name' => 'f736446beTermplataforma',
      'destination_field' => 'parent',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:6:"parent";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";s:23:"f736446beTermplataforma";s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'path' => (object) array(
      'machine_name' => 'f736446beTermplataforma',
      'destination_field' => 'path',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:4:"path";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";N;s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
    'pathauto' => (object) array(
      'machine_name' => 'f736446beTermplataforma',
      'destination_field' => 'pathauto',
      'source_field' => '',
      'options' => 'O:19:"MigrateFieldMapping":13:{s:19:"' . "\0" . '*' . "\0" . 'destinationField";s:8:"pathauto";s:14:"' . "\0" . '*' . "\0" . 'sourceField";N;s:16:"' . "\0" . '*' . "\0" . 'mappingSource";i:1;s:15:"' . "\0" . '*' . "\0" . 'defaultValue";s:1:"1";s:12:"' . "\0" . '*' . "\0" . 'separator";N;s:18:"' . "\0" . '*' . "\0" . 'sourceMigration";N;s:12:"' . "\0" . '*' . "\0" . 'callbacks";a:0:{}s:9:"' . "\0" . '*' . "\0" . 'dedupe";N;s:12:"' . "\0" . '*' . "\0" . 'arguments";N;s:14:"' . "\0" . '*' . "\0" . 'description";s:0:"";s:13:"' . "\0" . '*' . "\0" . 'issueGroup";s:4:"Done";s:14:"' . "\0" . '*' . "\0" . 'issueNumber";N;s:16:"' . "\0" . '*' . "\0" . 'issuePriority";i:1;}',
    ),
  );
  $export['f736446beTermplataforma'] = $migrate;

  return $export;
}
