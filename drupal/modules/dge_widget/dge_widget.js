/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
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
 	* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 	* GNU General Public License for more details.
 	*
 	* You should have received a copy of the GNU General Public License
 	* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

//URL
url = "https://" + document.location.hostname + "/";


jQuery(document).ready(function() {
	jQuery('#edit-boton').click(function() {

		organismo = jQuery('select#edit-organismo option:selected').val();
		ancho = jQuery('#edit-ancho').val();
		alto = jQuery('#edit-alto').val();

		if (ancho === '')
			ancho = 800;
		if (alto === '')
			alto = 600;
		ordenacion = jQuery('select#edit-ordenacion option:selected').val();
		sede = jQuery('select#edit-sede option:selected').val();

		cadena_final = '",function(responseTxt,statusTxt,xhr){jQuery("#datosgob_widget p").filter(function() {return (jQuery.trim(jQuery(this).text()) === "&nbsp;" || jQuery.trim(jQuery(this).text()) === "");}).remove();}); ';

		cadena_iframe = '<script src="https://code.jquery.com/jquery-1.9.1.js"></script>';
		cadena_iframe += '<div id="datosgob_widget" style="width: ' + ancho + 'px; height: ' + alto + 'px; overflow-y:scroll;"></div>';

		if (ordenacion === 0 || ordenacion === '0')
			cadena_iframe += '<script>jQuery("#datosgob_widget").load("' + url + 'widget-rss-fecha/' + organismo + cadena_final;
		else
			cadena_iframe += '<script>jQuery("#datosgob_widget").load("' + url + 'widget-rss-alpha/' + organismo + cadena_final;

		if (sede === 0 || sede === '0')
			cadena_iframe += 'jQuery("#datosgob_widget").delegate("a", "click", function(ev){alert("Va a ser redireccionado fuera del dominio actual.");});</script>';
		else
			cadena_iframe += '</script>';

		jQuery('#edit-codigo').val(cadena_iframe);

	});
});
