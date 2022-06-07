/*
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
*
* This file is part of "dge (datos.gob.es)".
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

$(document).ready(function(){
function rateVote (widget, data, token) {
  var langs=['es','en','eu','gl','ca'];
  var lang='es';
  
  var url = window.location.href;
  var hostname = (new URL(url)).hostname;
  langs.forEach(function(e){
    if(url.includes(hostname+'/'+e+'/')){
      lang= e
    }
  })

  var basePath='/'+lang+'/rate/vote/js';
  widget.trigger('eventBeforeRate', [data]);

  $(".rate-button").toggleClass("rate-button-is-loading");
  
  var random = Math.floor(Math.random() * 99999);
  var q = (basePath.match(/\?/) ? '&' : '?') + 'widget_id=' + data.widget_id + '&content_type=' + data.content_type + '&content_id=' + data.content_id + '&widget_mode=' + data.widget_mode + '&token=' + token + '&destination=' + encodeURIComponent(`${data.content_type}/${data.content_id}`) + '&r=' + random;
  if (data.value) {
    q = q + '&value=' + data.value;
  }
  // fetch all widgets with this id as class
  $.get(basePath + q, function(response) {
    $(".rate-button").toggleClass("rate-button-is-loading");
    
    if (response.match(/^https?\:\/\/[^\/]+\/(.*)$/)) {
      // We got a redirect.
      document.location = response;
    }
    else {
      // get parent object
      console.log(widget)
      // var p = widget.parent();       
      // Invoke JavaScript hook.
      widget.trigger('eventAfterRate', [data]);
      widget.before(response);        
      widget.remove();
      $('#dgecomments').trigger('dge_comments_loaded')
    }
  });

  return false;
}

$('#dgecomments').on("dge_comments_loaded",function(){     
     
    $('.rate-widget:not(.rate-processed)').addClass('rate-processed').each(function () {
      console.log('ready to vote')
    
      var widget = $(this);         
    
    var ids = widget.attr('id').split('--');
    ids = ids[0].match(/^rate\-([a-z]+)\-([0-9]+)\-([0-9]+)\-([0-9])$/);
    var data = {
      content_type: ids[1],
      content_id: ids[2],
      widget_id: ids[3],
      widget_mode: ids[4]
    };
    $('a.rate-button', widget).click(function(e) {
      e.preventDefault();
      var token = this.getAttribute('href').match(/rate\=([a-zA-Z0-9\-_]{32,64})/)[1];
      return rateVote(widget, data, token);
    });
  });
}); 
});
