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

  Drupal.behaviors.addAriaLabel= {
    attach: function (context, settings) {
      var lang = $('html')[0].lang;
      var search;
      var input;
      var date_field;
      var year;
      var logo;
      var caption;
      switch(lang) {
        case "es":
          search = "Buscar documentación";
          input = "Campo para búsqueda de documentación";
          date_field = "Campo de fecha";
          year = "Año";
          logo = "Logo de ";
          caption = "";
          break;
        case "en":
          search = "Search documentation";
          input = "Input for documentation search";
          date_field = "Date field";
          year = "Year";
          logo = "";
          caption = "";
          break;
        case "ca":
          search = "Cerca documentació";
          input = "Camp per cerca de documentació";
          date_field = "Camp de data";
          year = "Any";
          logo = "";
          caption = "";
          break;
        case "gl":
          search = "Busca documentación";
          input = "Campo de busca de documentación";
          date_field = "Campo de data";
          year = "Ano";
          logo = "";
          caption = "";
          break;
        case "eu":
          search = "Bilatu dokumentazioa";
          input = "Dokumentazioa bilatzeko eremua";
          date_field = "Data eremua";
          year = "Urtea";
          logo = "";
          caption = "";
          break;
      }
      jQuery(".form-type-date-popup input.date-clear").attr("title", date_field);
      jQuery(".field-name-field-success-launch-date select").attr({"title": year});
      jQuery("#views-exposed-form-doc-search-panel-pane-1 #edit-search-api-views-fulltext").attr({"aria-label": search, title: search, alt: input});
      /* Add alt app and success images */
      jQuery(".view-app-detail .dge-detail__img img").attr("alt", logo + jQuery.trim(jQuery(".page-title span").text()));
      jQuery(".view-apps-search li.dge-list--elm").each(function(e) {
        jQuery(this).find(".dge-list__img img").attr("alt", logo + jQuery.trim(jQuery(this).find(".dge-list__title a").text()));
      });
      jQuery(".view-app-detail .dge-detail__gallery-cont li").each(function(e) {
        console.log(this);
        jQuery(this).find("img").attr("alt", logo + jQuery.trim(jQuery(".page-title span").text())+ " " + jQuery.trim(e));
      });
      jQuery(".view-general-search li.dge-list--elm").each(function(e) {
        jQuery(this).find(".dge-list__img img").attr("alt", logo + jQuery.trim(jQuery(this).find(".dge-list__title a").text()));
      });
      jQuery(".view-success-detail .dge-detail__img img").attr("alt", logo + jQuery.trim(jQuery(".page-title span").text()));
      jQuery(".view-success-view li.dge-list--elm").each(function(e) {
        jQuery(this).find(".dge-list__img img").attr("alt", logo + jQuery.trim(jQuery(this).find(".dge-list__title a").text()));
      });
      jQuery(".node-aporta-awards .aporta-left-content .imagenAporta img").attr({
        "alt": logo +jQuery.trim(jQuery("#titulosPrincipales h2").text()),
        "title": logo +jQuery.trim(jQuery("#titulosPrincipales h2").text())
      });
      jQuery(".node-aporta-awards .imageAporta img").attr({
        "alt": logo +jQuery.trim(jQuery(".aporta-desafio-content #title").text()),
        "title": logo +jQuery.trim(jQuery(".aporta-desafio-content #title").text())
      });
    }
  };

  Drupal.behaviors.addCheckBoxAccesible= {
    attach: function (context, settings) {
      jQuery(".node-webform .form-type-checkbox input").keypress(function(e) {
        if(jQuery(this).is(":checked")) {
          jQuery(this).prop( "checked", false);
          e.preventDefault();
        } else {
          jQuery(this).prop( "checked", true );
          e.preventDefault();
        }
      });

      jQuery(".node-form .form-type-checkbox input").keypress(function(e) {
        if(jQuery(this).is(":checked")) {
          jQuery(this).prop( "checked", false);
          e.preventDefault();
        } else {
          jQuery(this).prop( "checked", true );
          e.preventDefault();
        }
      });
    }
  };

  //Disable focus problems on leaflet SDA-852/2.1.2
  Drupal.behaviors.addLeafletAccesibility= {
    attach: function (context, settings) {
      jQuery("#leaflet-map").each(function(e) {
        jQuery("div").children().removeAttr("tabindex");
      });

      jQuery("body").keydown(function(e) {
        jQuery(".leaflet-control-search input").attr('disabled', true);
        jQuery("input.leaflet-control-layers-selector").attr('disabled', true);
      });

      jQuery("body").keydown(function(e) {
        jQuery(".leaflet-control-search input").attr('disabled', false);
        jQuery("input.leaflet-control-layers-selector").attr('disabled', false);
      });
    }
  };

  //Add name to search button in SDA-852/4.1.1
  Drupal.behaviors.addNameButton= {
    attach: function (context, settings) {
      jQuery(".views-exposed-form .views-submit-button .form-submit").each(function(e) {
        jQuery(this).attr("name" , "search_submit");
      });
      jQuery(".dge_calendar_filter_form .range-form-filter-button .form-submit").each(function(e) {
        jQuery(this).attr("name" , "search_date_submit");
      });
    }
  };

  //Make Share button accesible
  Drupal.behaviors.addShareAccesible= {
    attach: function (context, settings) {
      jQuery("div.dge-detail__share").attr("tabindex", 0);
      jQuery("div.dge-detail__share ul.links").attr("role", "menu");
      jQuery("div.dge-detail__share").attr({"name": Drupal.t("Share content"), role: Drupal.t("button")});
      jQuery(".dge-detail__share-title").attr({"name": Drupal.t("Share content"), role: Drupal.t("button")});
      jQuery("div.dge-detail__share2").attr({"name": Drupal.t("Share content"), role: Drupal.t("button")});
      jQuery("div.dge-detail__share2 ul.links").attr("role", "menu");
      jQuery(".dge-detail__share2-title").attr({"name": Drupal.t("Share content"), role: Drupal.t("button")});
      jQuery("div.dge-detail__share").keypress(function(e) {
        if(jQuery(this).hasClass("is-visible")) {
          jQuery(this).removeClass("is-visible");
        }
        else {
          jQuery(this).addClass("is-visible");
        }
      });
      jQuery(".dge-detail__share2").keypress(function(e) {
        if(jQuery(this).hasClass("is-visible")) {
          jQuery(this).removeClass("is-visible");
        }
        else {
          jQuery(this).addClass("is-visible");
        }
      });
    }
  };

  //Make Tabs accesibles
  Drupal.behaviors.addTabsAccesibles= {
    attach: function (context, settings) {
      jQuery("dge-actual-aporta-tabs ul li a").attr('tabindex', 0);
      jQuery(".tablist li").keypress(function(e) {
        jQuery(".tablist li").removeClass("ui-tabs-active ui-state-active");
        jQuery(this).addClass("ui-tabs-active ui-state-active");
      });
    }
  };

  //Make calendar arrows accesibles
  Drupal.behaviors.addArrowAccesible= {
    attach: function (context, settings) {
      addCalendarAccesible();
      jQuery(".ui-datepicker-next").click(function () {
        addCalendarAccesible();
      });
    }
  };


  function addCalendarAccesible() {
    var lang = $('html')[0].lang;
    var next;
    var prev;
    switch(lang) {
      case "es":
        prev = "Anterior";
        next = "Siguiente";
        break;
      case "en":
        prev = "Previous";
        next = "Next";
        break;
      case "ca":
        prev = "Anterior";
        next = "Següent";
        break;
      case "gl":
        prev = "Anterior";
        next = "Seguinte";
        break;
      case "eu":
        prev = "Aurrekoa";
        next = "Hurrengoa";
        break;
    }
    jQuery(".ui-datepicker-prev span").attr({"aria-label": prev, alt: prev});
    jQuery(".ui-datepicker-next span").attr({"aria-label": next, alt: next});
    jQuery(".ui-datepicker-prev").attr({"aria-label": prev, alt: prev, 'tabindex': 0});
    jQuery(".ui-datepicker-next").attr({"aria-label": next, alt: next, 'tabindex': 0});
    jQuery(".ui-datepicker-prev").attr({role: Drupal.t("button")});
    jQuery(".ui-datepicker-next").attr({role: Drupal.t("button")});
    jQuery(".ui-datepicker-prev").keypress(function(e) {
      jQuery(this).click();
      addCalendarAccesible();
    });
    jQuery(".ui-datepicker-next").keypress(function(e) {
      jQuery(this).click();
      addCalendarAccesible();
    });
  }

  //Assing Initiatives form names to inputs
  Drupal.behaviors.addInitiativeFormNames= {
    attach: function (context, settings) {
      jQuery("#edit-field-initiative-strategy-und-0-url").attr({"title": jQuery("label[for='edit-field-initiative-strategy-und-0']").text()});
      jQuery(".form-item-field-initiative-strategy-und-0 label.element-invisible").text(jQuery("label[for='edit-field-initiative-strategy-und-0']").text());

      jQuery("#edit-field-initiative-download-und-0-url").attr({"title": jQuery("label[for='edit-field-initiative-download-und-0']").text()});
      jQuery(".form-item-field-initiative-download-und-0 label.element-invisible").text(jQuery("label[for='edit-field-initiative-download-und-0']").text());

      jQuery("#edit-field-initiative-link-und-0-url").attr({"title": jQuery("label[for='edit-field-initiative-link-und-0']").text()});
      jQuery(".form-item-field-initiative-link-und-0 label.element-invisible").text(jQuery("label[for='edit-field-initiative-link-und-0']").text());

      jQuery("#edit-field-url-del-cat-logo-und-0-url").attr({"title": jQuery("label[for='edit-field-url-del-cat-logo-und-0']").text()});
      jQuery(".form-item-field-url-del-cat-logo-und-0 label.element-invisible").text(jQuery("label[for='edit-field-url-del-cat-logo-und-0']").text());

      jQuery("#edit-field-initiative-webservice-und-0-url").attr({"title": jQuery("label[for='edit-field-initiative-webservice-und-0']").text()});
      jQuery(".form-item-field-initiative-webservice-und-0 label.element-invisible").text(jQuery("label[for='edit-field-initiative-webservice-und-0']").text());

      jQuery("#edit-field-initiative-api-ckan-und-0-url").attr({"title": jQuery("label[for='edit-field-initiative-api-ckan-und-0']").text()});
      jQuery(".form-item-field-initiative-api-ckan-und-0 label.element-invisible").text(jQuery("label[for='edit-field-initiative-api-ckan-und-0']").text());

      jQuery("#edit-field-initiative-restful-api-und-0-url").attr({"title": jQuery("label[for='edit-field-initiative-restful-api-und-0']").text()});
      jQuery(".form-item-field-initiative-restful-api-und-0 label.element-invisible").text(jQuery("label[for='edit-field-initiative-restful-api-und-0']").text());

      jQuery("#edit-field-initiative-sparql-und-0-url").attr({"title": jQuery("label[for='edit-field-initiative-sparql-und-0']").text()});
      jQuery(".form-item-field-initiative-sparql-und-0 label.element-invisible").text(jQuery("label[for='edit-field-initiative-sparql-und-0']").text());

      jQuery("#edit-field-initiative-license-und-0-url").attr({"title": jQuery("label[for='edit-field-initiative-license-und-0']").text()});
      jQuery(".form-item-field-initiative-license-und-0 label.element-invisible").text(jQuery("label[for='edit-field-initiative-license-und-0']").text());

      jQuery("#edit-field-initiative-channel-und-0-url").attr({"title": jQuery("label[for='edit-field-initiative-channel-und-0']").text()});
      jQuery(".form-item-field-initiative-channel-und-0 label.element-invisible").text(jQuery("label[for='edit-field-initiative-channel-und-0']").text());

      jQuery("#edit-field-initiative-catalog-und-0-url").attr({"title": jQuery("label[for='edit-field-initiative-catalog-und-0']").text()});
      jQuery(".form-item-field-initiative-catalog-und-0 label.element-invisible").text(jQuery("label[for='edit-field-initiative-catalog-und-0']").text());

      jQuery("#edit-field-initiative-resources-und-0-url").attr({"title": jQuery("label[for='edit-field-initiative-resources-und-0']").text()});
      jQuery(".form-item-field-initiative-resources-und-0 label.element-invisible").text(jQuery("label[for='edit-field-initiative-resources-und-0']").text());
    }
  };

  //Add description to Geofield
  Drupal.behaviors.addGeofieldDescription= {
    attach: function (context, settings) {
      jQuery("#edit-field-geoposition .fieldset-description").appendTo(".form-item-field-geoposition-und-0-geom-lon");
      jQuery("#edit-field-geoposition .fieldset-description").addClass("description");
    }
  };

  //SDA-852 Add lang tag to dropdown menu
  Drupal.behaviors.addLangTag= {
    attach: function (context, settings) {
      jQuery("#lang-dropdown-select-language option").each(function() {
        jQuery(this).attr("lang", jQuery(this).val());
      });
    }
  };

})(jQuery);
