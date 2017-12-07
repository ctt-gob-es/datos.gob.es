<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_ckan (datos.gob.es)".
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

  class dge_ckan_json_label {

    var $file_name;
    var $json_data;

    function dge_ckan_json_label($file_name) {
      $this->file_name = $file_name;
      $this->json_data = $this->read_json();
    }

    function read_json()
    {
      $path = drupal_get_path('module', 'dge_ckan') . '/json/' . $this->file_name;
      $data = file_get_contents($path);
      $json_data = json_decode($data,true);
      return $json_data;
    }
  }

?>
