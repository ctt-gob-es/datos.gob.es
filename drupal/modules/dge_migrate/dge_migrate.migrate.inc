<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_migrate (datos.gob.es)".
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
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function dge_migrate_migrate_api() {

  /*
   * @see /migrate_d2d/migrate_d2d_ui/migrate_d2d_ui.migrate.inc line 286 to 298
   */
  $migrate_name = substr(md5('datosgobes'), 0, 9);

  $api = array(
    'api' => 2,
    'migrations' => array(
      'DGEProfile2OrganizationMigration' => array(
        'class_name' => 'DGEProfile2OrganizationMigration',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate Organization Users Profile2',
        'dependencies' => array('DGEUserOrganizationMigration'),
      ),
      'DGEUserOrganizationMigration' => array(
        'class_name' => 'DGEUserOrganizationMigration',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate Organization Users',
      ),
      'DGEUserEditorMigration' => array(
        'class_name' => 'DGEUserEditorMigration',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate Editor Users',
      ),
      'DGETaxonomyTermTagsApp' => array(
        'class_name' => 'DGETaxonomyTermTagsApp',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate Apps Tags',
        'source_vocabulary' => 'tags',
        'destination_vocabulary' => 'app_tags'
      ),
      'DGETaxonomyTermTagsArticle' => array(
        'class_name' => 'DGETaxonomyTermTagsArticle',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate Article/News Tags',
        'source_vocabulary' => 'tags',
        'destination_vocabulary' => 'blog_tags'
      ),
      'DGETaxonomyTermTagsBlog' => array(
        'class_name' => 'DGETaxonomyTermTagsBlog',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate Blog Tags',
        'source_vocabulary' => 'tags',
        'destination_vocabulary' => 'blog_tags'
      ),
      'DGETaxonomyTermTagsEvent' => array(
        'class_name' => 'DGETaxonomyTermTagsEvent',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate Blog Tags',
        'source_vocabulary' => 'tags',
        'destination_vocabulary' => 'event_tags'
      ),
      'DGENodeApp' => array(
        'class_name' => 'DGENodeApp',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate Apps',
        'source_type' => 'aplicaciones',
        'destination_type' => 'app',
        'dependencies' => array('DGEUserOrganizationMigration','DGEUserEditorMigration'),
      ),
      'DGENodeBlogFromBlog' => array(
        'class_name' => 'DGENodeBlogFromBlog',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate From Blog To Blog (to 28/02/2013)',
        'source_type' => 'blog',
        'destination_type' => 'blog',
        'dependencies' => array('DGEUserEditorMigration'),
      ),
      'DGENodeBulletinFromBlog' => array(
        'class_name' => 'DGENodeBulletinFromBlog',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate From Bulletin To Blog (from 28/02/2013)',
        'source_type' => 'blog',
        'destination_type' => 'bulletin',
        'dependencies' => array('DGEUserEditorMigration'),
      ),
      'DGENodeDocEstrategiaRispFromSaberMas' => array(
        'class_name' => 'DGENodeDocEstrategiaRispFromSaberMas',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate From Saber Mas Estrategias Risp To Doc Estrategias Risp',
        'source_type' => 'saber_mas',
        'destination_type' => 'doc',
        'dependencies' => array('DGEUserEditorMigration'),
      ),
      'DGENodeDocEstudiosFromSaberMas' => array(
        'class_name' => 'DGENodeDocEstudiosFromSaberMas',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate From Saber Mas Estudios To Doc Estudios',
        'source_type' => 'saber_mas',
        'destination_type' => 'doc',
        'dependencies' => array('DGEUserEditorMigration'),
      ),
      'DGENodeDocNormativaFromSaberMas' => array(
        'class_name' => 'DGENodeDocNormativaFromSaberMas',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate From Saber Mas Normativa To Doc Normativa',
        'source_type' => 'saber_mas',
        'destination_type' => 'doc',
        'dependencies' => array('DGEUserEditorMigration'),
      ),
      'DGENodeDocFormacionFromSaberMas' => array(
        'class_name' => 'DGENodeDocFormacionFromSaberMas',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate From Saber Mas Normativa To Doc Normativa',
        'source_type' => 'saber_mas',
        'destination_type' => 'doc',
        'dependencies' => array('DGEUserEditorMigration'),
      ),
      'DGENodeDocGuiaFromSaberMas' => array(
        'class_name' => 'DGENodeDocGuiaFromSaberMas',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate From Saber Mas Normativa To Doc Normativa',
        'source_type' => 'saber_mas',
        'destination_type' => 'doc',
        'dependencies' => array('DGEUserEditorMigration'),
      ),
      'DGENodeEncuentroAportaFromSaberMas' => array(
        'class_name' => 'DGENodeEncuentroAportaFromSaberMas',
        'group_name' => $migrate_name,
        'source_connection' => $migrate_name.'_legacy',
        'source_version' => 7,
        'source_system' =>  'Drupal 7',
        'description' => 'Migrate From Saber Mas Estudios To Doc Estudios',
        'source_type' => 'saber_mas',
        'destination_type' => 'aporta',
        'dependencies' => array('DGEUserEditorMigration'),
      )
    ),
  );
  return $api;
}
