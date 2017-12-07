<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_widget (datos.gob.es)".
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
 * Theme implementation
 *
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="es" version="XHTML+RDFa 1.0" dir="ltr">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <title><?php print $title; ?> | datos.gob.es</title>
  <style type="text/css">
   a{font-family: Arial; font-family: Arial; color: #6D1E7E; text-decoration: none; }
  </style>
</head>
<body>
<?php
  module_load_include('inc', 'dge_ckan', 'dge_ckan_json_label');
  $nti_dge_dataset_label = new dge_ckan_json_label('nti_dge_dataset.json');
  $frequency_label = new dge_ckan_json_label('frequency_label.json');
  $baseurl= $_SERVER["HTTP_HOST"];
  $baseurl = "http://" . $baseurl . "/catalogo/";

  if($response['success']) {
    foreach($response['result']['results'] as $result) {
	$url = $baseurl . get_json_value('name', $result);	
?>
  <div>
    <div>
      <span class="datosgob_titulo"><a href="<?php print $url; ?>" target="_blank"><?php print get_json_value('title', $result); ?></a></span>
    </div>
    <div class="datosgob_descripcion">
	<p>
	      <?php print get_json_multiple_value('description', $result); ?>
	</p>
    </div>
    <div class="datosgob_categorias">
      <span>Categorías: </span>
      <div><?php print get_json_array_value('theme', 'es', $result, $nti_dge_dataset_label->json_data); ?></div>
    </div>
    <div class="datosgob_etiquetas">
      <span>Etiquetas: </span>
      <div><?php print get_json_array_key_value('tags', 'display_name', $result); ?></div>
    </div>
    <div class="datosgob_publicador">
      <span>Publicador: </span>
      <div><?php print get_json_key_value('organization', 'title', $result); ?></div>
    </div>
    <div class="datosgob_condreutilizacion">
      <span>Condiciones de reutilización: </span>
      <div><?php print get_json_value('license_url', $result); ?></div>
    </div>
    <div class="datosgob_feccreacion">
      <span>Fecha creación: </span>
      <div>
        <span class="date-display-single" property="dc:issued" datatype="xsd:dateTime" content="<?php print get_json_value('metadata_created', $result); ?>"><?php print get_json_date_value('metadata_created', $result, 'm/d/Y'); ?></span>
      </div>
    </div>
    <div class="datosgob_fecactualizacion">
      <span>Fecha actualización: </span>
      <div>
        <span class="date-display-single" property="dc:modified" datatype="xsd:dateTime" content="<?php print get_json_value('metadata_modified', $result); ?>"><?php print get_json_date_value('metadata_modified', $result, 'm/d/Y'); ?></span>
      </div>
    </div>
    <div class="datosgob_frecactualizacion">
      <span>Frecuencia de actualización: </span>
      <div><?php print get_frequency_label($result, $frequency_label->json_data); ?></div>
    </div>
    <div class="datosgob_cobgeografica">
      <span>Cobertura Geográfica: </span>
      <div><?php print get_json_array_value('spatial', 'es', $result, $nti_dge_dataset_label->json_data); ?></div>
    </div>
    <div class="datosgob_idiomas">
      <span>Idiomas: </span>
      <div><?php print get_json_array_value('language', 'es', $result, $nti_dge_dataset_label->json_data); ?></div>
    </div>
    <div class="datosgob_fordistribucion">
      <span>Distribuciones: </span>
      <div>
        <ul>
        <?php
          $resources = get_json_value('resources', $result);
          foreach ($resources as $resources_value) {
            $resources_url = $resources_value['url'];
            $resources_format = $resources_value['format'];
            $resources_size = $resources_value['size'];
          ?>
          <li>
            <div>
              <div class="field">
                <div class="field-label">
                  Nombre:&nbsp;
                </div>
                <div class="field-items">
                <?php
                  $resources_name_translated = get_json_value('name_translated', $resources_value);
                  $resources_name_translated_string = "";
                  if($resources_name_translated != ''){
                    foreach ($resources_name_translated as $resources_name_translated_value) {
                ?>
                  <div class="field-item" property="dc:title">
                    <?php print $resources_name_translated_value ?>
                  </div>
                <?php
                    }
                  }
                ?>
                </div>
              </div>
              <div class="field">
                <div class="field-label">
                  URL:&nbsp;
                </div>
                <div class="field-items">
                  <div class="field-item" property="dcat:accessURL">
                    <?php print $resources_url; ?>
                  </div>
                </div>
              </div>
              <div class="field">
                <div class="field-label">
                  Formato:&nbsp;
                </div>
                <div class="field-items">
                  <div class="field-item" property="dcat:mediaType">
                    <?php print $resources_format; ?>
                  </div>
                </div>
              </div>
              <div class="field">
                <div class="field-label">
                  Tamaño:&nbsp;
                </div>
                <div class="field-items">
                  <div class="field-item" property="dcat:byteSize">
                    <?php print $resources_size; ?>
                  </div>
                </div>
              </div>
            </div>
          </li>
          <?php
          }
          ?>
        </ul>
      </div>
    </div>
  </div>
  <?php
      }
    }
  ?>
</body>
</html>
