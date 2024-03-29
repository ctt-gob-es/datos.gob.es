<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
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
 	* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 	* GNU General Public License for more details.
 	*
 	* You should have received a copy of the GNU General Public License
 	* along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

function get_json_value($field_name, $json_data)
{
  $field_value = array_key_exists($field_name, $json_data) ? $json_data[$field_name] : '';

  return $field_value;
}

function get_json_key_value($field_name, $field_key, $json_data)
{
  $field = get_json_value($field_name, $json_data);
  $field_value = "";
  if($field != ''){
    $field_value = get_json_value($field_key, $field);
  }

  return $field_value;
}

function get_json_date_value($field_name, $json_data, $format)
{
  $field_value = array_key_exists($field_name, $json_data) ? date($format, strtotime($json_data[$field_name])) : '';

  return $field_value;
}

function get_json_multiple_value($field_name, $json_data)
{
  $field = get_json_value($field_name, $json_data);
  $field_string = "";
  if($field != ''){
    foreach ($field as $field_value) {
      $field_string .= ($field_value != '') ? $field_value.", " : '';
    }
    $field_string = substr($field_string, 0, -2);
  }

  return $field_string;
}

function get_json_array_value($field_name, $field_key, $json_data, $label_data)
{
  $field = get_json_value($field_name, $json_data);
  $field_string = "";
  if($field != ''){
    foreach ($field as $field_value) {
        $field_string .= get_json_label($field_name, $field_key, $field_value, $label_data).", ";
    }
    $field_string = substr($field_string, 0, -2);
  }

  return $field_string;
}

function get_json_array_key_value($field_name, $field_key, $json_data)
{
  $field = get_json_value($field_name, $json_data);
  $field_string = "";
  if($field != ''){
    foreach ($field as $field_value) {
        $field_string .= $field_value[$field_key].", ";
    }
    $field_string = substr($field_string, 0, -2);
  }

  return $field_string;
}

function get_json_label($field_name, $field_key, $field_value, $label_data)
{
  $json_label = "";

  foreach ($label_data['dataset_fields'] as $field) {
    $name = get_json_value('field_name', $field);
    if($name == $field_name){
      $choices = get_json_value('choices', $field);
      foreach ($choices as $choice) {
        $value = get_json_value('value', $choice);
        if($value == $field_value){
          $json_label = get_json_key_value('label', $field_key, $choice);
        }
      }
    }
  }
  return $json_label;
}

function get_frequency_label($json_data, $label_data)
{
  $json_label = "";

  $frequency_types = ['seconds', 'minutes', 'hours', 'days', 'weeks', 'months', 'years'];

  $frequency_value = get_json_key_value('frequency', 'value', $json_data);
  $frequency_type = get_json_key_value('frequency', 'type', $json_data);
  if (in_array($frequency_type, $frequency_types)) {
    foreach ($label_data['frequency_fields'] as $field) {

      $json_label = get_json_value($frequency_value,get_json_value($frequency_type, $field));

      if($json_label == ''){
        $json_label= 'Cada ' . $frequency_value . ' ' . get_json_value($frequency_type,get_json_value('types', $field));
      }
    }
  }
  return $json_label;
}
?>
