/*
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "ckanext-dge (datos.gob.es)".
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.

 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

$(document).ready(function(){
  
  if ($("#dgecomments").length){
    var url = $("#dgecomments").attr("data-comments");
    if (typeof url !== typeof undefined && url !== false) {
      var current_page = 0;
      var qs_page = '?page=';

      $.urlParam = function (name) {
        var results = new RegExp('[\?&]' + name + '=([^&#]*)').exec(window.location.href);
        return (results != null) ? results[1] : 0;
      };
      current_page = $.urlParam('page');
      var current_url = $(location).attr('href');
      current_url = current_url.replace($(location).attr('search'), '');
      if (current_url.indexOf('#') != -1) {
        current_url = current_url.substring(0, current_url.indexOf('#'));
      }
      var comment_url = $('#dgecomments').attr('data-comments');

      $('#dgecomments').attr('data-page',current_page);
      $('#dgecomments').load(comment_url+qs_page+current_page, function() {
        $(".pager a").each(function(elem){
          p = $(this).attr('data-page');
          $(this).attr('href',current_url+qs_page+p);
        });
      });
    }
  }

});
