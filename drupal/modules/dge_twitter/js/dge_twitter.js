/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_twitter (datos.gob.es)".
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

(function($) {

    Drupal.behaviors.dge_twitter = {
      attach: function(context, settings) {
         var base_path = [location.protocol, '//', location.host, location.pathname].join('');
         if (base_path.indexOf("/", base_path.length - "/".length) !== -1) {
            base_path = base_path.substring(0, base_path.length - 1);
         }
         if (base_path.indexOf("home", base_path.length - "home".length) !== -1) {
            base_path = base_path.substring(0, base_path.length - 5);
         }
         var url = base_path + "/twitter/tweets";
         jQuery.getJSON(url, function(json) {
            if (json.RESULT && json.RESULT == '0') {
               $('#dgetweets').html(json.DATA);
               if ( $.isFunction($.fn.bxSlider)) {
                  if (window.matchMedia("(min-width: 80em)").matches) {
            			$('.dge-twitter__lst').bxSlider({
            				minSlides: 4,
            				maxSlides: 4,
            				moveSlides: 1,
            				pager: false,
            				slideWidth: 310,
            				slideMargin: 70
            			});
            		}else if (window.matchMedia("(min-width: 80em)").matches) {
            			$('.dge-twitter__lst').bxSlider({
            				minSlides: 4,
            				maxSlides: 4,
            				moveSlides: 1,
            				pager: false,
            				slideWidth: 310,
            				slideMargin: 15
            			});
            		}else if (window.matchMedia("(min-width: 60em)").matches) {
            			$('.dge-twitter__lst').bxSlider({
            				minSlides: 3,
            				maxSlides: 3,
            				moveSlides: 1,
            				pager: false,
            				slideWidth: 310,
            				slideMargin: 70
            			});
            		}else if (window.matchMedia("(min-width: 30em)").matches) {
            			$('.dge-twitter__lst').bxSlider({
            				minSlides: 2,
            				maxSlides: 2,
            				moveSlides: 1,
            				pager: false,
            				slideWidth: 310,
            				slideMargin: 70
            			});
            		}else{
            			$('.dge-twitter__lst').bxSlider({
            				minSlides: 1,
            				maxSlides: 1,
            				moveSlides: 1,
            				pager: false,
            				slideWidth: 320,
            				slideMargin: 0
            			});
            		}
               }
            }
         });
      }
   }

})(jQuery);
