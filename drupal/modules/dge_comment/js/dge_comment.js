/*
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_comment (datos.gob.es)".
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

(function($) {
    Drupal.behaviors.dge_comment = {
        attach: function () {
            var qs_page = '?page=';
            var comment_url = Drupal.settings['dge_comment']['comment_url'];
            var current_url = Drupal.settings['dge_comment']['current_url'];
            var data_page = Drupal.settings['dge_comment']['data_page'];

            $('#dge-content-comment').load(comment_url+qs_page+data_page, function() {
                $(".pager a").each(function(elem){
                    p = $(this).attr('data-page');
                    $(this).attr('href',current_url+qs_page+p);
                });
            })
        }
    }
})(jQuery);
