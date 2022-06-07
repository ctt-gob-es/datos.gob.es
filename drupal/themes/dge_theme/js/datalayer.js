/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_theme (datos.gob.es)".
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

(function ($) {

    /**
   * Function to add a datalayer object to events.
   */
  Drupal.behaviors.dataLayer = {
    attach: function(context, settings) {
        //Add event for newsletter subscription
        var exists;
        var text;
        var seccion2 = get_section_2();
        if (seccion2 == ''){
          seccion2 = 'home';
        }
        seccion2 = RemoveAccents(seccion2);
        exists = $('#simplenews-block-form-21')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#simplenews-block-form-21')[0].addEventListener("submit", function(event) {

            var option = '';
            var tipo = $('.simplenews-subscribe');
            if ( tipo.length > 0 ) {
              var radio = $('#simplenews-block-form-21 input[name=action2]')[0];
              if ( typeof(radio) != "undefined" && radio !== null ) {
                radio =  $('#simplenews-block-form-21 input[name=action2]:checked')[0].value;
                if(radio == 'unsubscribe'){
                  option = 'darse de baja';
                } else {
                  option = 'suscribirse';
                }
              } else {
                option = 'suscribirse';
              }
            } else {
              option = 'darse de baja';
            }
            switch ( option ) {
              case 'suscribirse':
                var mail = $('#simplenews-block-form-21 #edit-mail');
                if ( typeof(radio) != "undefined" && radio !== null ) {
                  mail = $('#simplenews-block-form-21 #edit-mail').val();
                  if ( mail.length == 0 ) {
                    break;
                  }
                }
                var check =  $('#simplenews-block-form-21 #edit-condiciones:checked')[0];
                if ( typeof(check) != "undefined" && check !== null ) {
                  dataLayer.push({
                    'event_action': 'accion_newsletter',
                    'variable_evento': 'accionNewsletter',
                    'event_label': option,
                    'event_category': seccion2,
                    'event': 'ev.accion_newsletter'
                  });
                }
                break;
              case 'darse de baja':
                var check =  $('#simplenews-block-form-21')[0];
                if ( typeof(check) != "undefined" && check !== null ) {
                  dataLayer.push({
                    'event_action': 'accion_newsletter',
                    'variable_evento': 'accionNewsletter',
                    'event_label': option,
                    'event_category': seccion2,
                    'event': 'ev.accion_newsletter'
                  });
                }
                break;
            }
          });
        }
        //Add event for menu search
        exists = $('#dge-search-header-search-form')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#dge-search-header-search-form')[0].addEventListener("submit", function(event) {
            text = $('#dge-search-header-search-form #edit-search-block-form').val().toLowerCase();
            if(text.length == 0){
              text = 'campo vacio';
            }
            text = RemoveAccents(text);
            dataLayer.push({
              'event_action': 'buscar',
              'variable_evento': 'terminoBusqueda',
              'event_label': text,
              'event_category': seccion2,
              'event': 'ev.buscar'
            });
          });
        }
        //Add event for search page search
        exists = $('#views-exposed-form-general-search-panel-pane-1')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#views-exposed-form-general-search-panel-pane-1')[0].addEventListener("submit", function(event) {
            text = $('#views-exposed-form-general-search-panel-pane-1 #edit-search-keyword').val().toLowerCase();
            if(text.length == 0){
              text = 'campo vacio';
            }
            text = RemoveAccents(text);
            dataLayer.push({
              'event_action': 'buscar',
              'variable_evento': 'terminoBusqueda',
              'event_label': text,
              'event_category': seccion2,
              'event': 'ev.buscar'
            });
          });
        }
        //Add event for APORTA iniciative search
        exists = $('#views-exposed-form-aporta-search-panel-pane-1')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#views-exposed-form-aporta-search-panel-pane-1')[0].addEventListener("submit", function(event) {
            text = $('#views-exposed-form-aporta-search-panel-pane-1 #edit-search-api-views-fulltext').val().toLowerCase();
            if(text.length == 0){
              text = 'campo vacio';
            }
            text = RemoveAccents(text);
            dataLayer.push({
              'event_action': 'buscar',
              'variable_evento': 'terminoBusqueda',
              'event_label': text,
              'event_category': seccion2,
              'event': 'ev.buscar'
            });
          });
        }
        //Add event for iniciative map search
        exists = $('#views-exposed-form-initiative-search-ctools-context-1')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#views-exposed-form-initiative-search-ctools-context-1')[0].addEventListener("submit", function(event) {
            text = $('#views-exposed-form-initiative-search-ctools-context-1 #edit-search-api-views-fulltext').val().toLowerCase();
            if(text.length == 0){
              text = 'campo vacio';
            }
            text = RemoveAccents(text);
            dataLayer.push({
              'event_action': 'buscar',
              'variable_evento': 'terminoBusqueda',
              'event_label': text,
              'event_category': seccion2,
              'event': 'ev.buscar'
            });
          });
        }
        //Add event for app search
        exists = $('#views-exposed-form-apps-search-panel-pane-1')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#views-exposed-form-apps-search-panel-pane-1')[0].addEventListener("submit", function(event) {
            text = $('#views-exposed-form-apps-search-panel-pane-1 #edit-search-api-views-fulltext').val().toLowerCase();
            if(text.length == 0){
              text = 'campo vacio';
            }
            text = RemoveAccents(text);
            dataLayer.push({
              'event_action': 'buscar',
              'variable_evento': 'terminoBusqueda',
              'event_label': text,
              'event_category': seccion2,
              'event': 'ev.buscar'
            });
          });
        }
        //Add event for success search
        exists = $('#views-exposed-form-success-view-panel-pane-1')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#views-exposed-form-success-view-panel-pane-1')[0].addEventListener("submit", function(event) {
            text = $('#views-exposed-form-success-view-panel-pane-1 #edit-search-api-views-fulltext').val().toLowerCase();
            if(text.length == 0){
              text = 'campo vacio';
            }
            text = RemoveAccents(text);
            dataLayer.push({
              'event_action': 'buscar',
              'variable_evento': 'terminoBusqueda',
              'event_label': text,
              'event_category': seccion2,
              'event': 'ev.buscar'
            });
          });
        }
        //Add event for documentation search
        exists = $('#views-exposed-form-doc-search-panel-pane-1')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#views-exposed-form-doc-search-panel-pane-1')[0].addEventListener("submit", function(event) {
            text = $('#views-exposed-form-doc-search-panel-pane-1 #edit-search-api-views-fulltext').val().toLowerCase();
            if(text.length == 0){
              text = 'campo vacio';
            }
            text = RemoveAccents(text);
            dataLayer.push({
              'event_action': 'buscar',
              'variable_evento': 'terminoBusqueda',
              'event_label': text,
              'event_category': seccion2,
              'event': 'ev.buscar'
            });
          });
        }
        //Add event for data availability search
        exists = $('#views-exposed-form-request-search-panel-pane-1')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#views-exposed-form-request-search-panel-pane-1')[0].addEventListener("submit", function(event) {
            text = $('#views-exposed-form-request-search-panel-pane-1 #edit-search-api-views-fulltext').val().toLowerCase();
            if(text.length == 0){
              text = 'campo vacio';
            }
            text = RemoveAccents(text);
            dataLayer.push({
              'event_action': 'buscar',
              'variable_evento': 'terminoBusqueda',
              'event_label': text,
              'event_category': seccion2,
              'event': 'ev.buscar'
            });
          });
        }
        //Add event for news search
        exists = $('#views-exposed-form-blog-search-panel-pane-1')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#views-exposed-form-blog-search-panel-pane-1')[0].addEventListener("submit", function(event) {
            text = $('#views-exposed-form-blog-search-panel-pane-1 #edit-search-api-views-fulltext').val().toLowerCase();
            if(text.length == 0){
              text = 'campo vacio';
            }
            text = RemoveAccents(text);
            dataLayer.push({
              'event_action': 'buscar',
              'variable_evento': 'terminoBusqueda',
              'event_label': text,
              'event_category': seccion2,
              'event': 'ev.buscar'
            });
          });
        }
        //Add event for bulletin search
        exists = $('#views-exposed-form-bulletin-search-panel-pane-1')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#views-exposed-form-bulletin-search-panel-pane-1')[0].addEventListener("submit", function(event) {
            text = $('#views-exposed-form-bulletin-search-panel-pane-1 #edit-search-api-views-fulltext').val().toLowerCase();
            if(text.length == 0){
              text = 'campo vacio';
            }
            text = RemoveAccents(text);
            dataLayer.push({
              'event_action': 'buscar',
              'variable_evento': 'terminoBusqueda',
              'event_label': text,
              'event_category': seccion2,
              'event': 'ev.buscar'
            });
          });
        }
        //Add event for events search
        exists = $('#views-exposed-form-event-search-panel-pane-1')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#views-exposed-form-event-search-panel-pane-1')[0].addEventListener("submit", function(event) {
            text = $('#views-exposed-form-event-search-panel-pane-1 #edit-search-api-views-fulltext').val().toLowerCase();
            if(text.length == 0){
              text = 'campo vacio';
            }
            text = RemoveAccents(text);
            dataLayer.push({
              'event_action': 'buscar',
              'variable_evento': 'terminoBusqueda',
              'event_label': text,
              'event_category': seccion2,
              'event': 'ev.buscar'
            });
          });
        }
        //Add event for RISP community search
        exists = $('#views-exposed-form-talk-search-panel-pane-1')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#views-exposed-form-talk-search-panel-pane-1')[0].addEventListener("submit", function(event) {
            text = $('#views-exposed-form-talk-search-panel-pane-1 #edit-search-api-views-fulltext').val().toLowerCase();
            if(text.length == 0){
              text = 'campo vacio';
            }
            text = RemoveAccents(text);
            dataLayer.push({
              'event_action': 'buscar',
              'variable_evento': 'terminoBusqueda',
              'event_label': text,
              'event_category': seccion2,
              'event': 'ev.buscar'
            });
          });
        }
        //Add event for user registration
        exists = $('#user-register-form')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#user-register-form')[0].addEventListener("submit", function(event) {
            var required =  $("#user-register-form .required");
            var stop = 0;
            for ( i = 0; i < required.length; i++ ){
              if ( required[i].value == '' ) {
                stop++;
              }
            }
            if ( stop > 0 ) {
              return '';
            }
            var other = $('#edit-profile-agency-data-field-other-agency-und:checked')[0];
            var label = '';
            if ( typeof(other) != "undefined" && other !== null ) {
              label = RemoveAccents($('#user-register-form #edit-profile-agency-data-field-other-agency-name-und-0-value').val().toLowerCase());
            } else {
              label = RemoveAccents($('#user-register-form #edit-profile-agency-data-field-root-agency-und option:selected').text().toLowerCase());
            }
            dataLayer.push({
              'event_action': 'crear_cuenta',
              'variable_evento': 'organizacion', //TODO otra organizacion: valor
              'event_label': label ,
              'event_category': 'Cuenta de usuario',
              'event': 'ev.crear_cuenta'
            });
          });
        }
        //Add event for course access youtube
        exists = $('.node-type-aporta a.dge-youtube-link')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('.node-type-aporta a.dge-youtube-link').on("click", function(event) {
            dataLayer.push({
              'event_action': 'ver_curso',
              'variable_evento': 'nombreCurso | tipo', //TODO pendiente variables de eventos
              'event_label': RemoveAccents($('#views-exposed-form-aporta-search-panel-pane-1 #edit-search-api-views-fulltext').val().toLowerCase()),
              'event_category': seccion2,
              'event': 'ev.ver_curso'
            });
          });
        }
        //Add event for course access slideshare
        exists = $('.node-type-aporta a.dge-slideshare-link')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('.node-type-aporta a.dge-slideshare-link').on("click", function(event) {
            var labelCourse = $('#views-exposed-form-aporta-search-panel-pane-1 #edit-search-api-views-fulltext').val().toLowerCase();
            var labelCourseSplit = labelCourse.split("-");
            var tamanoLabel = labelCourseSplit.length;
            var labelFinal = "";
            for (var controli=0;controli<tamanoLabel;controli++){
              labelFinal += labelCourseSplit[controli] + " ";
            }
            dataLayer.push({
              'event_action': 'ver_curso',
              'variable_evento': 'nombreCurso | tipo', //TODO pendiente variables de eventos
              'event_label': RemoveAccents(labelFinal),
             // 'event_label': RemoveAccents($('#views-exposed-form-aporta-search-panel-pane-1 #edit-search-api-views-fulltext').val().toLowerCase()),
              'event_category': seccion2,
              'event': 'ev.ver_curso'
            });
          });
        }
        //Add event for course access
        var iframe = $('.view-doc-detail iframe')[0];
        if ( typeof(iframe) != "undefined" && iframe !== null ) {
          $('.view-doc-detail iframe').load(function(){
            exists = $('.view-doc-detail iframe').contents().find('#oculto a');
            if ( typeof(exists) != "undefined" && exists !== null ) {
              $('.view-doc-detail iframe').contents().find('#oculto a').on("click", function(event) {
                var tipo = $('.materiales-formativos');
                if ( typeof(tipo) != "undefined" && tipo !== null ) {
                  tipo = 'materiales-formativos';
                } else {
                  tipo = 'normativa';
                }
                var titulo = $('.view-doc-detail iframe').contents().find('h1').text().toLowerCase();
                var label = titulo + '|' + tipo;
                dataLayer.push({
                  'event_action': 'ver_curso',
                  'variable_evento': 'nombreCurso | tipo', //TODO pendiente variables de eventos
                  'event_label': RemoveAccents(label),
                  'event_category': seccion2,
                  'event': 'ev.ver_curso'
                });
              });
            }
          });
        }
        //Add event for data request
        exists = $('#request-node-form')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#request-node-form')[0].addEventListener("submit", function(event) {
            var required =  $("#request-node-form .required");
            var stop = 0;
            for ( i = 0; i < required.length; i++ ){
              if ( required[i].value == '' ) {
                stop++;
              }
            }
            if ( stop > 0 ) {
              return '';
            }
            var options = $("#request-node-form #edit-field-request-category-und option:selected");
            var values = $.map(options ,function(option) {
                return option.innerHTML;
            });
            var final = '';
            if ( values.length >= 1 ) {
              for(i = 0; i < values.length; i++) {
                if ( i == 0 ) {
                  final = values[i];
                } else {
                  final = final + ':' + values[i];
                }
              }
            }
            final = final.toLowerCase();
            dataLayer.push({
              'event_action': 'enviar_formulario',
              'variable_evento': 'tipoFormulario | categoriaFormulario',
              'event_label': 'disponibilidad de datos | ' + RemoveAccents(final),
              'event_category': seccion2,
              'event': 'ev.enviar_formulario'
            });
          });
        }
        //Add event for app recommendations
        exists = $('.node-app-form')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('.node-app-form')[0].addEventListener("submit", function(event) {
            var required =  $(".node-app-form .required");
            var stop = 0;
            for ( i = 0; i < required.length; i++ ){
              if ( required[i].value == '' ) {
                stop++;
              }
            }
            if ( stop > 0 ) {
              return '';
            }
            var options = $(".node-app-form #edit-field-app-category-und option:selected");
            var values = $.map(options ,function(option) {
                return option.innerHTML;
            });
            var final = '';
            if ( values.length >= 1 ) {
              for(i = 0; i < values.length; i++) {
                if ( i == 0 ) {
                  final = values[i];
                } else {
                  final = final + ':' + values[i];
                }
              }
            }
            final = final.toLowerCase();
            dataLayer.push({
              'event_action': 'enviar_formulario',
              'variable_evento': 'tipoFormulario | categoriaFormulario',
              'event_label': 'aplicaciones | ' + RemoveAccents(final),
              'event_category': seccion2,
              'event': 'ev.enviar_formulario'
            });
          });
        }
        //Add event for initiatives recommendations
        exists = $('.node-initiative-form')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('.node-initiative-form')[0].addEventListener("submit", function(event) {
            var required =  $(".node-initiative-form .required");
            var stop = 0;
            for ( i = 0; i < required.length; i++ ){
              if ( required[i].value == '' ) {
                stop++;
              }
            }
            if ( stop > 0 ) {
              return '';
            }
            var options = $(".node-initiative-form #edit-field-initiative-category-und option:selected");
            var values = $.map(options ,function(option) {
                return option.innerHTML;
            });
            var final = '';
            if ( values.length >= 1 ) {
              for(i = 0; i < values.length; i++) {
                if ( i == 0 ) {
                  final = values[i];
                } else {
                  final = final + ':' + values[i];
                }
              }
            }
            final = final.toLowerCase();
            dataLayer.push({
              'event_action': 'enviar_formulario',
              'variable_evento': 'tipoFormulario | categoriaFormulario',
              'event_label': 'aplicaciones | ' + RemoveAccents(final),
              'event_category': seccion2,
              'event': 'ev.enviar_formulario'
            });
          });
        }
        //Add event for casos de reutilizacion
        exists = $('#success-node-form')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#success-node-form')[0].addEventListener("submit", function(event) {
            var required =  $("#success-node-form .required");
            var stop = 0;
            for ( i = 0; i < required.length; i++ ){
              if ( required[i].value == '' ) {
                stop++;
              }
            }
            if ( stop > 0 ) {
              return '';
            }
            var options = $("#success-node-form #edit-field-success-category-und option:selected");
            var values = $.map(options ,function(option) {
                return option.innerHTML;
            });
            var final = '';
            if ( values.length >= 1 ) {
              for(i = 0; i < values.length; i++) {
                if ( i == 0 ) {
                  final = values[i];
                } else {
                  final = final + ':' + values[i];
                }
              }
            }
            final = final.toLowerCase();
            dataLayer.push({
              'event_action': 'enviar_formulario',
              'variable_evento': 'tipoFormulario | categoriaFormulario',
              'event_label': 'casos de reutilizacion | ' + RemoveAccents(final),
              'event_category': seccion2,
              'event': 'ev.enviar_formulario'
            });
          });
        }
        //Add event for client contact
        exists = $('#webform-client-form-1')[0];
        if ( typeof(exists) != "undefined" && exists !== null ) {
          $('#webform-client-form-1')[0].addEventListener("submit", function(event) {
            dataLayer.push({
              'event_action': 'enviar_formulario',
              'variable_evento': 'tipoFormulario | categoriaFormulario',
              'event_label': 'sugerencias/mejoras | campo vacio',
              'event_category': seccion2,
              'event': 'ev.enviar_formulario'
            });
          });
        }
        //Add event for download document
        $('a[href*="pdf"]').on("click", function(event) {
          $elementoPadre = $(this).parent();
          $elementoHermano = $elementoPadre.siblings('.dge-file-list-name');
          dataLayer.push({
            'event_category': seccion2, // Nombre de la ruta desde la que se lanza el evento.
            'event_action': 'descargar', // Acción del evento.
            'variable_evento': $elementoHermano.text() + ' | pdf',
            'event_label':  $elementoHermano.text()  + ' | pdf', // Información adicional.
            'event': 'ev.descargar_documento'
          });
        });
        $('a[href*="docx"]').on("click", function(event) {
          $elementoPadre = $(this).parent();
          $elementoHermano = $elementoPadre.siblings('.dge-file-list-name');
          dataLayer.push({
            'event_category': seccion2, // Nombre de la ruta desde la que se lanza el evento.
            'event_action': 'descargar', // Acción del evento.
            'variable_evento': $elementoHermano.text() + ' | docx',
            'event_label':  $elementoHermano.text() + ' | docx', // Información adicional.
            'event': 'ev.descargar_documento'
          });
        });
        $('a[href*="odt"]').on("click", function(event) {
          $elementoPadre = $(this).parent();
          $elementoHermano = $elementoPadre.siblings('.dge-file-list-name');
          dataLayer.push({
            'event_category': seccion2, // Nombre de la ruta desde la que se lanza el evento.
            'event_action': 'descargar', // Acción del evento
            'variable_evento': $elementoHermano.text() + ' | odt',
            'event_label': $elementoHermano.text() + ' | odt', // Información adicional.
            'event': 'ev.descargar_documento'
          });
         });
         $('a[href*="pptx"]').on("click", function(event) {
          $elementoPadre = $(this).parent();
          $elementoHermano = $elementoPadre.siblings('.dge-file-list-name');
          dataLayer.push({
            'event_category': seccion2, // Nombre de la ruta desde la que se lanza el evento.
            'event_action': 'descargar', // Acción del evento
            'variable_evento': $elementoHermano.text() + ' | PPTX',
            'event_label': $elementoHermano.text() + ' | PPTX', // Información adicional.
            'event': 'ev.descargar_documento'
          });
         });
    }}
})(jQuery);

get_section_2 = function ()
{
return '<?php echo $seccion_s2 ?>';
}
function RemoveAccents(strAccents) {
  var strAccents = strAccents.split('');
  var strAccentsOut = new Array();
  var strAccentsLen = strAccents.length;
  var accents = 'ÀÁÂÃÄÅàáâãäåÒÓÔÕÕÖØòóôõöøÈÉÊËèéêëðÇçÐÌÍÎÏìíîïÙÚÛÜùúûüÑñŠšŸÿýŽž';
  var accentsOut = "AAAAAAaaaaaaOOOOOOOooooooEEEEeeeeeCcDIIIIiiiiUUUUuuuuNnSsYyyZz";
  for (var y = 0; y < strAccentsLen; y++) {
    if (accents.indexOf(strAccents[y]) != -1) {
      strAccentsOut[y] = accentsOut.substr(accents.indexOf(strAccents[y]), 1);
    } else
      strAccentsOut[y] = strAccents[y];
  }
  strAccentsOut = strAccentsOut.join('');
  strAccentsOut = strAccentsOut.toLowerCase();
  return strAccentsOut;
}