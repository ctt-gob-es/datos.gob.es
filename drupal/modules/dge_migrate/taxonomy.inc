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

class DGETaxonomyTermTagsApp extends DrupalTerm7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
  protected function query() {

    $query = parent::query();
    $query->innerJoin('field_data_field_etiquetas_aplicacion', 'fdfea', 'fdfea.field_etiquetas_aplicacion_tid = td.tid');
    return $query;
  }

}

class DGETaxonomyTermTagsArticle extends DrupalTerm7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
  protected function query() {

    $query = parent::query();
    $query->innerJoin('field_data_field_tags', 'fdft', 'fdft.field_tags_tid = td.tid');
    return $query;
  }

}

class DGETaxonomyTermTagsBlog extends DrupalTerm7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
  protected function query() {

    $query = parent::query();
    $query->innerJoin('field_data_field_categoria_blog', 'fdfcb', 'fdfcb.field_categoria_blog_tid = td.tid');
    return $query;
  }

}

class DGETaxonomyTermTagsEvent extends DrupalTerm7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
  protected function query() {

    $query = parent::query();
    $query->innerJoin('field_data_field_categoria_evento', 'fdfcb', 'fdfcb.field_categoria_evento_tid = td.tid');
    return $query;
  }

}
