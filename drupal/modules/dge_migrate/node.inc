<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

class DGENodeApp extends DrupalNode7Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->removeFieldMapping('uid');
    $this->addFieldMapping('uid', 'uid')
      ->callbacks(array($this, 'getAuthorUser'));
      // Multiple SourceMigration Works, but not if you will edit in config migrate screen
      //->sourceMigration(array('DGEUserOrganizationMigration','DGEUserEditorMigration'));
  }

  protected function getAuthorUser($id) {
    $query = db_select('migrate_map_dgeusereditormigration', 'dge_editor')
      ->fields('dge_editor', array('destid1'))
      ->condition('dge_editor.sourceid1',$id,'=')
      ->range(0, 1)
      ->execute();
    $result = $query->fetchField();
    $query2 = db_select('migrate_map_dgeuserorganizationmigration', 'dge_organization')
      ->fields('dge_organization', array('destid1'))
      ->condition('dge_organization.sourceid1',$id,'=')
      ->range(0, 1)
      ->execute();
    $result2 = $query2->fetchField();

    if($result)
      return $result;
    else if($result2)
      return $result2;
    else
      return 1;
  }

}

class DGENodeBlogFromBlog extends DrupalNode7Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);
  }

  protected function query() {
    $query = parent::query();
    // Migrate From News To Blog (to 28/02/2013)
    $query->condition('n.created', date('U',strtotime('2013-02-28')), '<');

    return $query;
  }

}

class DGENodeBulletinFromBlog extends DrupalNode7Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);
  }

  protected function query() {
    $query = parent::query();
    // Migrate From Bulletin To Blog (from 28/02/2013)
    $query->condition('n.created', date('U',strtotime('2013-02-28')), '>');

    return $query;
  }

}

class DGENodeDocEstrategiaRispFromSaberMas extends DrupalNode7Migration {

  protected $term_source_id = 385;
  protected $field_source_name = 'field_categoria_saber_mas';
  protected $field_destination_name = 'field_doc_tx_type';
  protected $voc_destination_name = 'doc_types';
  protected $term_destination_name = 'Estrategias RISP';

  public function __construct($arguments) {
    parent::__construct($arguments);

    //$this->removeFieldMapping('uid');
    //$this->addFieldMapping($this->field_destination_name, $this->field_source_name)
      //->callbacks(array($this, 'getDocCategory'));
    $this->addFieldMapping($this->field_destination_name)
      ->defaultValue($this->getDocCategory());
    $this->addFieldMapping($this->field_destination_name.':source_type')
      ->defaultValue('tid');

  }

  protected function query() {

    $query = parent::query();
    $query->innerJoin('field_data_field_categoria_saber_mas', 'fdfcsm', 'fdfcsm.entity_id = n.nid');
    $query->condition('fdfcsm.field_categoria_saber_mas_tid', $this->term_source_id, '=');

    return $query;
  }

  public function getDocCategory() {

    $terms = taxonomy_get_term_by_name($this->term_destination_name,$this->voc_destination_name);
    if(empty($terms)) {
      $voc = taxonomy_vocabulary_machine_name_load($this->voc_destination_name);
      $term = new stdClass();
      $term->name = $this->term_destination_name;
      $term->vid = $voc->vid;
      taxonomy_term_save($term);
    }
    else {
      $term = reset($terms);
    }
    return $term->tid;

  }

}

class DGENodeDocEstudiosFromSaberMas extends DrupalNode7Migration {

  protected $term_source_id = 29;
  protected $field_source_name = 'field_categoria_saber_mas';
  protected $field_destination_name = 'field_doc_tx_type';
  protected $voc_destination_name = 'doc_types';
  protected $term_destination_name = 'Informes e Estudios';

  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping($this->field_destination_name)
      ->defaultValue($this->getDocCategory());
    $this->addFieldMapping($this->field_destination_name.':source_type')
      ->defaultValue('tid');

  }

  protected function query() {

    $query = parent::query();
    $query->innerJoin('field_data_field_categoria_saber_mas', 'fdfcsm', 'fdfcsm.entity_id = n.nid');
    $query->condition('fdfcsm.field_categoria_saber_mas_tid', $this->term_source_id, '=');

    return $query;
  }

  public function getDocCategory() {

    $terms = taxonomy_get_term_by_name($this->term_destination_name,$this->voc_destination_name);
    if(empty($terms)) {
      $voc = taxonomy_vocabulary_machine_name_load($this->voc_destination_name);
      $term = new stdClass();
      $term->name = $this->term_destination_name;
      $term->vid = $voc->vid;
      taxonomy_term_save($term);
    }
    else {
      $term = reset($terms);
    }
    return $term->tid;

  }

}

class DGENodeDocNormativaFromSaberMas extends DrupalNode7Migration {

  protected $term_source_id = 28;
  protected $field_source_name = 'field_categoria_saber_mas';
  protected $field_destination_name = 'field_doc_tx_type';
  protected $voc_destination_name = 'doc_types';
  protected $term_destination_name = 'Normativa';

  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping($this->field_destination_name)
      ->defaultValue($this->getDocCategory());
    $this->addFieldMapping($this->field_destination_name.':source_type')
      ->defaultValue('tid');

  }

  protected function query() {

    $query = parent::query();
    $query->innerJoin('field_data_field_categoria_saber_mas', 'fdfcsm', 'fdfcsm.entity_id = n.nid');
    $query->condition('fdfcsm.field_categoria_saber_mas_tid', $this->term_source_id, '=');

    return $query;
  }

  public function getDocCategory() {

    $terms = taxonomy_get_term_by_name($this->term_destination_name,$this->voc_destination_name);
    if(empty($terms)) {
      $voc = taxonomy_vocabulary_machine_name_load($this->voc_destination_name);
      $term = new stdClass();
      $term->name = $this->term_destination_name;
      $term->vid = $voc->vid;
      taxonomy_term_save($term);
    }
    else {
      $term = reset($terms);
    }
    return $term->tid;

  }

}


class DGENodeDocFormacionFromSaberMas extends DrupalNode7Migration {

  protected $term_source_id = 31;
  protected $field_source_name = 'field_categoria_saber_mas';
  protected $field_destination_name = 'field_doc_tx_type';
  protected $voc_destination_name = 'doc_types';
  protected $term_destination_name = 'Materiales formativos';

  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping($this->field_destination_name)
      ->defaultValue($this->getDocCategory());
    $this->addFieldMapping($this->field_destination_name.':source_type')
      ->defaultValue('tid');

  }

  protected function query() {

    $query = parent::query();
    $query->innerJoin('field_data_field_categoria_saber_mas', 'fdfcsm', 'fdfcsm.entity_id = n.nid');
    $query->condition('fdfcsm.field_categoria_saber_mas_tid', $this->term_source_id, '=');

    return $query;
  }

  public function getDocCategory() {

    $terms = taxonomy_get_term_by_name($this->term_destination_name,$this->voc_destination_name);
    if(empty($terms)) {
      $voc = taxonomy_vocabulary_machine_name_load($this->voc_destination_name);
      $term = new stdClass();
      $term->name = $this->term_destination_name;
      $term->vid = $voc->vid;
      taxonomy_term_save($term);
    }
    else {
      $term = reset($terms);
    }
    return $term->tid;

  }

}


class DGENodeDocGuiaFromSaberMas extends DrupalNode7Migration {

  protected $term_source_id = 1538;
  protected $field_source_name = 'field_categoria_saber_mas';
  protected $field_destination_name = 'field_doc_tx_type';
  protected $voc_destination_name = 'doc_types';
  protected $term_destination_name = 'Guías';

  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping($this->field_destination_name)
      ->defaultValue($this->getDocCategory());
    $this->addFieldMapping($this->field_destination_name.':source_type')
      ->defaultValue('tid');

  }

  protected function query() {

    $query = parent::query();
    $query->innerJoin('field_data_field_categoria_saber_mas', 'fdfcsm', 'fdfcsm.entity_id = n.nid');
    $query->condition('fdfcsm.field_categoria_saber_mas_tid', $this->term_source_id, '=');

    return $query;
  }

  public function getDocCategory() {

    $terms = taxonomy_get_term_by_name($this->term_destination_name,$this->voc_destination_name);
    if(empty($terms)) {
      $voc = taxonomy_vocabulary_machine_name_load($this->voc_destination_name);
      $term = new stdClass();
      $term->name = $this->term_destination_name;
      $term->vid = $voc->vid;
      taxonomy_term_save($term);
    }
    else {
      $term = reset($terms);
    }
    return $term->tid;

  }

}


class DGENodeEncuentroAportaFromSaberMas extends DrupalNode7Migration {

  protected $term_source_id = 32;

  public function __construct($arguments) {
    parent::__construct($arguments);

  }

  protected function query() {

    $query = parent::query();
    $query->innerJoin('field_data_field_categoria_saber_mas', 'fdfcsm', 'fdfcsm.entity_id = n.nid');
    $query->condition('fdfcsm.field_categoria_saber_mas_tid', $this->term_source_id, '=');

    return $query;
  }

}