/*
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_date_calendar_filter (datos.gob.es)".
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
    var dates;

    Drupal.behaviors.dge_date_calendar_filter = {
        attach: function(context, settings) {
           var datePattern = 'dd/mm/yy';
           var drupalDatePattern = 'yy_mm_dd';

           if (Drupal.settings['dge_date_calendar_filter']['dates'] != null) {
             var json_dates = JSON.parse(Drupal.settings['dge_date_calendar_filter']['dates']);
             dates = json_dates.dates;
           }

           if ($.fn.datepicker) {
             var numCalendars = 1;
             if (window.matchMedia("(min-width: 80em)").matches) {
                numCalendars = 3;
		       } else if (window.matchMedia("(min-width: 40em)").matches) {
                numCalendars = 2;
			    }

             $("#datepicker").datepicker({
               numberOfMonths: numCalendars,
				   beforeShowDay: function(date) {
					   try{
					      var date1 = $.datepicker.parseDate(datePattern, $("#cal_start_date").val(), null);
					   } catch(error){
                     $("#cal_start_date").val("");
                     $("#cal_end_date").val("");
                     var date1 = null;
                  }
					   try {
					      var date2 = $.datepicker.parseDate(datePattern, $("#cal_end_date").val(), null);
					   } catch(error){
						   var date2 = null;
                     $("#cal_end_date").val("");
                  }
                  var classes = "";
                  if (containsEvents($.datepicker.formatDate( drupalDatePattern, date ))){
                     classes = "date-with-events";
                  }
					   return [true, date1 && ((date.getTime() == date1.getTime()) || (date2 && date >= date1 && date <= date2)) ? classes+" dge-selected-range" : classes+""];
				   },
				   onSelect: function(dateText, inst) {
					   try {
					      var date1 = $.datepicker.parseDate(datePattern, $("#cal_start_date").val(), null);
                  } catch(error){
                     $("#cal_start_date").val("");
                     $("#cal_end_date").val("");
                  }
                  try {
					      var date2 = $.datepicker.parseDate(datePattern, $("#cal_end_date").val(), null);
					   } catch(error){
                     $("#cal_end_date").val("");
                  }
                  var date = $.datepicker.parseDate($.datepicker._defaults.dateFormat, dateText);
					   if (!date1 || date2) {
						   $("#cal_start_date").val($.datepicker.formatDate( datePattern, date ));
						   $("#cal_end_date").val("");
					   } else {
						   date2 = date;
						   if (date1 <= date2) {
						      $("#cal_end_date").val($.datepicker.formatDate( datePattern, date ));
					      } else {
					  	      $("#cal_end_date").val($("#cal_start_date").val());
					  	      $("#cal_start_date").val($.datepicker.formatDate( datePattern, date ));
					      }
					   }
				   }
			    });
             $( window ).resize(function() {
                var numCalendars = 1;
                if (window.matchMedia("(min-width: 80em)").matches) {
                   numCalendars = 3;
   		       } else if (window.matchMedia("(min-width: 40em)").matches) {
                   numCalendars = 2;
   			    }
                if (numCalendars != $( "#datepicker" ).datepicker( "option", "numberOfMonths")) {
                   $( "#datepicker" ).datepicker( "option", "numberOfMonths", numCalendars );
                }
             });
           }
        }
     }

     function containsEvents(date){
        for (var x in dates) {
          if (dates[x] == date) {
            return true;
          }
        }
        return false;
     }

})(jQuery);
