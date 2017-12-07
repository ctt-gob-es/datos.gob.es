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
  </div>
  <?php
      }
    }
  ?>
</body>
</html>
