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

/*
function cogeVisitas(id){
		/**VISITAS YOUTUBE
		var urlJSON="https://www.googleapis.com/youtube/v3/videos?part=statistics&id=hKDkuGafGas&key=AIzaSyDFheRQSOY9DxFHyKmS-bxIdqX74gp6Ch8";
		$.getJSON(urlJSON, function(data) {
		alert(data.items[0].statistics.viewCount);
		});
}*/
(function($){

  var leafletFullScreen = false;
  var isFullScreen = false;

  $(document).ready(function(){
    $('.field-widget-text-textarea').children('div#comment-body-add-more-wrapper').children('div.text-format-wrapper').children(".description").appendTo('.form-item-comment-body-und-0-value');
    /**IMAGEN PREMIO REDES */
    var image = new Image();
    var src = '/sites/all/themes/dge_theme/images/svg/twitter.svg'; //Esta es la variable que contiene la url de una imagen ejemplo, luego puedes poner la que quieras
    image.src = src;
    $('.TwitterPremio').text("");
    $('.TwitterPremio').append(image);
    var image2 = new Image();
    var src2 = '/sites/all/themes/dge_theme/images/svg/linkedin.svg'; //Esta es la variable que contiene la url de una imagen ejemplo, luego puedes poner la que quieras
    image2.src = src2;
    $('.LinkedinPremio').text("");
    $('.LinkedinPremio').append(image2);
    var image3 = new Image();
    var src3 = '/sites/all/themes/dge_theme/images/svg/youtube.svg'; //Esta es la variable que contiene la url de una imagen ejemplo, luego puedes poner la que quieras
    image3.src = src3;
    $('.YoutubePremio').text("");
    $('.YoutubePremio').append(image3);

		/**BOLETIN GDPR*/

	  var $newsletterForm = $('form#simplenews-block-form-21');
			var $input = $newsletterForm.find('input#edit-mail');
			var $input2 = $newsletterForm.find('input#edit-mail--2');
      var $terms_field =  $newsletterForm.find('.form-type-checkbox');

      $terms_field.hide();

      function show_legal(){
        // $legal_block.show();
          $terms_field.slideDown(700);
      }

    $input.on('focus', function() {
			if($("#edit-action2-subscribe").prop("checked")){
				show_legal();
			}
			if($("#edit-action2-unsubscribe").prop("checked")){
				$terms_field.slideUp(700);
			}
		});
		$input2.on('focus', function() {
      if($("#edit-action2-subscribe").prop("checked")){
				show_legal();
			}
		});
		$('input#edit-submit--4').click(function(){
			if($("#edit-action2-unsubscribe").prop("checked")){
				$terms_field.remove();
			}
		});

		/*::::::::: LATERAL MENU CAROUSEL :::::::::*/
		var numero=0;
		var url = window.location.href;
		var urlHashControl = url.split("#");
		var controlNumber = url.split("-");
		$("div.col-width-30").append("<ul class='listadoMenu'></ul>");
		$( "div.titleMenu" ).each( function(){
			$("ul.listadoMenu").append("<li id='islide-" + numero + "'><a class='elementoTitleMenu' href ='#slide-" + numero++ + "'><span>" + ($(this).text()) + "</span></a></li>");
		  $( "div.titleMenu" ).remove();
		});

    if(controlNumber[1]>=0 && controlNumber[1]<5){
			$( "li#i" + urlHashControl[1] ).attr("class","selectedMenu");
		}else{
			$( "li#islide-0" ).attr("class","selectedMenu");
		}
		$(window).bind('hashchange',function(){
			var newHash = window.location.hash.slice(1);
			var newControlNumber = newHash.split("-");
			if(newControlNumber[1]>=0 && newControlNumber[1]<5){
				$( "li.selectedMenu").removeAttr("class");
				$( "li#i" + newHash ).attr("class","selectedMenu");
			}
		});



	$('.node-carousel .content .carousel-left-content, .node-carousel .content .carousel-right-content .listadoMenu').equalHeights();



		/*::::::::: Add DGE class to WEBFORMS :::::::: */
		if($('.webform-client-form').length){
			$('.webform-client-form').addClass('dge-form');
		}
		if($('#formulario-generador-form').length){
			$('#formulario-generador-form').addClass('dge-form dge-form--widget');
		}
		$('.node-form').addClass('dge-form');
		$('#faq-order-settings-form').addClass('dge-form dge-form--faq');
		$('#comment-form').addClass('dge-form');

		/*::::::::: FILTERS responsive :::::::: */
		if($('.pane-facetapi').length){
			$('.pane-views-panes').before('<a class="show-filters btn" href="#" id="filterButtom">Filtrar resultados</a>');
		}

		$('.dge-filters .inside').before('<a class="closeModalSM closeFilters"><i class="icon-remove-sign"></i><span class="element-invisible">close</span></a>');
		$('#filterButtom').click(function(){
			$('body').addClass('filters-modal');
		});
		$('.closeFilters').click(function(){
			$('body').removeClass('filters-modal');
		});

		/*::::::::: LOGIN responsive :::::::: */
		$('.block-user form').before('<a class="closeModalMD closeLogin"><i class="icon-remove-sign"></i><span class="element-invisible">close</span></a>');

		$('.dge-mobileuser').click(function(){
			$('body').addClass('login-modal');
		});
		$('.closeLogin').click(function(){
			$('body').removeClass('login-modal');
		});

		/*::::::::: SEARCH responsive :::::::: */
		$('.block-search form').before('<a class="closeModalMD closeSearch"><i class="icon-remove-sign"></i><span class="element-invisible">close</span></a>');

		$('.dge-mobilesearch').click(function(){
			$('body').addClass('search-modal');
		});
		$('.closeSearch').click(function(){
			$('body').removeClass('search-modal');
		});

		/*::::::::: HEADER Social Networks hover :::::::: */
		$('.region-header .dge-social-links .content a').bind('mouseenter focusin', function(){
			var src = $(this).find('img').attr('src');
			if(src.indexOf('-alt.svg') == -1){
				src = $(this).find('img').attr('src').match(/[^\.]+/) + '-alt.svg';
				$(this).find('img').attr("src", src);
			}
		}).bind('mouseleave focusout', function(){
			var src = $(this).find('img').attr("src").replace("-alt.svg", ".svg");
            $(this).find('img').attr("src", src);
		});



		/*::::::::: SHARE Social Networks  :::::::: */
		$('.dge-detail__share strong').click(function(){
			$('.dge-detail__share').toggleClass('is-visible');
			return false;
		});
		/*::::::::: SHARE Social Networks  :::::::: */
		$('.dge-detail__share2 strong').click(function(){
			$(this.parentNode).toggleClass('is-visible');
			return false;
		});
		$('.service-links-twitter').attr('target','_blank');
		$('.service-links-linkedin').attr('target','_blank');
		$('.service-links-facebook').attr('target','_blank');
		$('.service-links-google-plus').attr('target','_blank');
		/*::::::::: MENU MAIN lateral :::::::: */
		$('.dge-mobilemenu').sidr({
			name: 'dge-main-menu--rwd',
			source: '.dge-submenu',
			side: 'right'
		});
		$('#dge-main-menu--rwd').insertAfter('.dge-mobilenav');

		/* ::::::: CLOSE MENU AND MODAL to CLICK out ::::::: */
		if (!window.matchMedia("(min-width: 60em)").matches) {
			$('html').tap(function(){
				$.sidr('close', 'dge-main-menu--rwd');
				$('.dge-detail__share').removeClass('is-visible');
			});
			// prevent click close propagation
			$('#dge-main-menu--rwd, .dge-detail__share .links').tap(function(e){
				e.stopPropagation();
			});
		};

				/* ::::::: CLOSE MENU AND MODAL to CLICK out ::::::: */
				if (!window.matchMedia("(min-width: 60em)").matches) {
					$('html').tap(function(){
						$.sidr('close', 'dge-main-menu--rwd');
						$('.dge-detail__share2').removeClass('is-visible');
					});
					// prevent click close propagation
					$('#dge-main-menu--rwd, .dge-detail__share2 .links').tap(function(e){
						e.stopPropagation();
					});
				};

		/* ::::::: CLOSE MENU AND MODAL on RESIZE ::::::: */
		var width = $(window).width();
		$(window).resize(function() {
            if (document.fullScreen || document.mozFullScreen || document.webkitIsFullScreen) {
                isFullScreen = true;
            } else {
                isFullScreen = false;
            }
            if($("#leaflet-map").length != 0 && ! $.isEmptyObject(Drupal.behaviors.dge_leaflet)) {
                if (Drupal.behaviors.dge_leaflet.getMap().isFullscreen() ||
                        document.fullscreenElement ||
                        document.mozFullScreenElement ||
                        document.webkitFullscreenElement ||
                        document.msFullscreenElement) {
                    leafletFullScreen = true;
                } else {
                    if (!leafletFullScreen || !isFullScreen) {
                        location.reload();
                    } else {
                        leafletFullScreen = false;
                    }
                }
            } else if($(this).width() != width && !isFullScreen) {
                location.reload();
            }
        });

		$('.dge-main-menu a').filter(function() {
			return $(this).attr('href').match(/user$/);
		}).attr("href", "#useroptions");
			$('.dge-submenu .content ul:first > li > a').filter(function() {
			return $(this).attr('href').match(/user$/);
		}).attr("href", "#useroptions");

		/*::::::::: Hide Login option :::::::: */
		$('.logged-in .dge-main-menu .content li').filter(function() {
			return $(this).find('a[href="#login"]').size() > 0;
		}).remove();

		/*::::::::: MENU MAIN desplegable :::::::: */
		var oldSection = $(this).find('.active-trail a').attr('href');
		$('.dge-main-menu a[href^="#"]').click(function(){
			var dgeSection = $(this).attr('href');

			if(oldSection == dgeSection){
				$('.dge-main-menu a').parent('li').removeClass('is-visible');
				$('.block-search').removeClass('is-visible'); //Search menu invisible
				$('.dge-user-menu, .block-user').removeClass('is-visible'); //User menu invisible
				$('.dge-submenu li').removeClass('is-visible').parent('.menu').removeClass('is-visible');
				oldSection = '';
				return false;
			}else{
				$('.dge-main-menu a').parent('li').removeClass('is-visible');
				$(this).parent('li').toggleClass('is-visible');

				if(dgeSection == '#search'){
					$('.dge-submenu').removeClass('is-visible'); //Submenu invisible
					$('.dge-user-menu, .block-user').removeClass('is-visible'); //User menu invisible
					$('.block-search').addClass('is-visible').find('.form-text').focus(); //Search form visible and focus
				} else if(dgeSection == '#login'){
					$('.dge-submenu').removeClass('is-visible'); //Submenu invisible
					$('.block-search').removeClass('is-visible'); //Search menu invisible
					$('.dge-user-menu, .block-user').addClass('is-visible').find('.form-item-name .form-text').focus(); //User form o menu visible and focus
				} else {
					$('.block-search').removeClass('is-visible'); //Search menu invisible
					$('.dge-user-menu, .block-user').removeClass('is-visible'); //User menu invisible
					$('.dge-submenu li').removeClass('is-visible').parent('.menu').removeClass('is-visible');
					$('.dge-submenu').addClass('is-visible'); //Submenu visible
					$('.dge-submenu a[href="' + dgeSection + '"]').parent('li').addClass('is-visible').parent('.menu').addClass('is-visible').find('li:first-child a').focus();
				}
			}

			oldSection = dgeSection;
			return false;
		});
		$('.dge-submenu li.active-trail').addClass('is-visible').parents('.dge-submenu').addClass('is-visible');
		$('.block-user .form-item-pass .form-text').on('blur', function(){
			$('.block-user .form-submit').focus();
		});

		/*:::: MENU Tootltips ::::*/
		$('.dge-main-menu .block__content a[href="#search"]').wrapInner('<span class="dge-main-menu__tooltip"></span>');
		$('.dge-main-menu .block__content a[href="#login"]').wrapInner('<span class="dge-main-menu__tooltip"></span>');

		/*::::::::: FILTERS active :::::::: */
		$('.pane-facetapi .facetapi-active').parent('li').addClass('is-active');

		/*::::::::: MENU SCROLL stiky ::::::::*/
		var stikyNav = $('.site-navigation');
		var stikyHeight = $('.site-navigation').offset();
		$(window).scroll(function (){
			if ($(this).scrollTop() > (stikyHeight.top)){
				stikyNav.addClass("stiky");
			} else {
				stikyNav.removeClass("stiky");
			}
		});


		/*::::::::: SLIDER Twitter HOME ::::::::*/
		if (window.matchMedia("(min-width: 80em)").matches) {
			$('.dge-twitter__lst').bxSlider({
				auto: true,
				autoHover: true,
				minSlides: 4,
				maxSlides: 4,
				moveSlides: 1,
				pager: false,
				slideWidth: 310,
				slideMargin: 70,
				speed: 3000
			});
		} else if (window.matchMedia("(min-width: 80em)").matches) {
			$('.dge-twitter__lst').bxSlider({
				auto: true,
				autoHover: true,
				minSlides: 4,
				maxSlides: 4,
				moveSlides: 1,
				pager: false,
				slideWidth: 310,
				slideMargin: 15,
				speed: 3000
			});
		} else if (window.matchMedia("(min-width: 60em)").matches) {
			$('.dge-twitter__lst').bxSlider({
				auto: true,
				autoHover: true,
				minSlides: 3,
				maxSlides: 3,
				moveSlides: 1,
				pager: false,
				slideWidth: 310,
				slideMargin: 70,
				speed: 3000
			});
		} else if (window.matchMedia("(min-width: 30em)").matches) {
			$('.dge-twitter__lst').bxSlider({
				auto: true,
				autoHover: true,
				minSlides: 2,
				maxSlides: 2,
				moveSlides: 1,
				pager: false,
				slideWidth: 310,
				slideMargin: 70,
				speed: 3000
			});
		} else{
			$('.dge-twitter__lst').bxSlider({
				auto: true,
				autoHover: true,
				minSlides: 1,
				maxSlides: 1,
				moveSlides: 1,
				pager: false,
				slideWidth: 320,
				slideMargin: 0,
				speed: 3000
			});
		}
		/*::::::::: SLIDER News (blog) HOME ::::::::*/
		if (window.matchMedia("(min-width: 48em)").matches) {
			$('.dge-news__content ul').bxSlider({
				minSlides: 3,
				maxSlides: 3,
				moveSlides: 1,
				pager: false,
				slideWidth: 535,
				slideMargin: 5//,
			});
		} else if (window.matchMedia("(min-width: 37.500em)").matches) {
			$('.dge-news__content ul').bxSlider({
				minSlides: 2,
				maxSlides: 2,
				moveSlides: 1,
				pager: false,
				slideWidth: 300,
				slideMargin: 5//,
			});
		} else {
			$('.dge-news__content ul').bxSlider({
				minSlides: 1,
				maxSlides: 1,
				moveSlides: 1,
				pager: false,
				slideWidth: 320,
				slideMargin: 0//,
			});
		}
	if (window.matchMedia("(min-width: 48em)").matches) {
			$('.dge-smallcarousel__content ul').bxSlider({
				minSlides: 3,
				maxSlides: 3,
				moveSlides: 1,
				pager: false,
				slideWidth: 535,
				slideMargin: 5//,
			});
		} else if (window.matchMedia("(min-width: 37.500em)").matches) {
			$('.dge-smallcarousel__content ul').bxSlider({
				minSlides: 2,
				maxSlides: 2,
				moveSlides: 1,
				pager: false,
				slideWidth: 300,
				slideMargin: 5//,
			});
		} else {
			$('.dge-smallcarousel__content ul').bxSlider({
				minSlides: 1,
				maxSlides: 1,
				moveSlides: 1,
				pager: false,
				slideWidth: 320,
				slideMargin: 0//,
			});
		}
		/*::::::::: SLIDER Apps HOME ::::::::*/
		if (window.matchMedia("(min-width: 48em)").matches) {
			$('.dge-app__content ul').bxSlider({
				minSlides: 3,
				maxSlides: 3,
				moveSlides: 1,
				pager: false,
				slideWidth: 535,
				slideMargin: 5//,
			});
		} else if (window.matchMedia("(min-width: 37.500em)").matches) {
			$('.dge-app__content ul').bxSlider({
				minSlides: 2,
				maxSlides: 2,
				moveSlides: 1,
				pager: false,
				slideWidth: 300,
				slideMargin: 5//,
			});
		} else {
			$('.dge-app__content ul').bxSlider({
				minSlides: 1,
				maxSlides: 1,
				moveSlides: 1,
				pager: false,
				slideWidth: 320,
				slideMargin: 0//,
			});
		}

		/*::::::::: SLIDER Apps DETAIL ::::::::*/
		if (window.matchMedia("(min-width: 30em)").matches) {
			$('.dge-detail__gallery ul').bxSlider({
				infiniteLoop: false,
				minSlides: 5,
				maxSlides: 5,
				moveSlides: 1,
				pager: false,
				slideWidth: 300,
				slideMargin: 20//,
			});
		} else {
			$('.dge-detail__gallery ul').bxSlider({
				infiniteLoop: false,
				minSlides: 1,
				maxSlides: 1,
				moveSlides: 1,
				pager: false,
				slideWidth: 535,
				slideMargin: 5//,
			});
		}
		$('.dge-detail__gallery ul > li > a').addClass('dge-colorbox').attr('rel','dge-app-gallery');
		$('a.dge-colorbox').colorbox({current:'',rel:'dge-app-gallery',maxHeight:'100%',maxWidth:'100%'});

		/* :::::::: TABS Iniciativa Aporta - Basic page :::::::: */
		if (window.matchMedia("(min-width: 48em)").matches) {
			$(".dge-aporta-tabs").tabs({
				collapsible: true,
				hide: {effect:"slideUp", duration:500},
				show: {effect:"slideDown", duration:400}
			});
		};
		if (window.matchMedia("(min-width: 48em)").matches) {
			$(".dge-actual-aporta-tabs").tabs({
				collapsible: true,
				hide: {effect:"slideUp", duration:500},
				show: {effect:"slideDown", duration:400}
			});
		};

		/* :::::::: TABS Iniciativa Aporta - Dropdown :::::::: */
		$('.field-name-field-aporta-workgroup-title').addClass('dropdown').find('.field-item').prepend('<span class="drop dropd element-invisible">Desplegar información</span>').wrapInner('<a href="#closed"></a>');
		$('.field-name-field-aporta-workgroup-title').bind('click', function() {
			$(this).toggleClass('dropdown').next().slideToggle().next().slideToggle();
			var $a = $(this).find('.drop').css('border','2px solid red').hasClass('dropd');
			if($a) {
				$(this).find('.drop').after('<span class="drop element-invisible">Ocultar información</span>').remove();
			} else {
				$(this).find('.drop').after('<span class="drop dropd element-invisible">Desplegar información</span>').remove();
			}
		});

		/*:::::::: CATEGORY LIST ::::::*/
		if($('.dge-category-list').height() > 100){
			$('.dge-category-list').addClass('dge-categories-full');
		} else {
			$('.dge-category-list').addClass('dge-categories-mini');
		};
		/**LOAD*/
		if($('#edit-profile-agency-data-field-other-agency-und').attr('checked') != 'checked') {
			$('#edit-profile-agency-data-field-root-agency-und').removeAttr('style','display: none;');
			$('#edit-profile-agency-data-field-root-agency-und').attr('class','form-select chosen-processed selectAbsolute');
			$('#edit-profile-agency-data-field-root-agency-und').find('option:first').attr('value', '').parent('select');
			$('#edit-profile-agency-data-field-root-agency-und').attr('required','');
		}
		$("#edit-profile-agency-data-field-other-agency-und").click(function() {
			if ($(this).attr('checked') == 'checked') {
				$('#edit-profile-agency-data-field-other-agency-name-und-0-value').attr('required','required');
				$('#edit-profile-agency-data-field-root-agency-und').removeAttr('required','');
				$('#edit-profile-agency-data-field-root-agency-und').attr('class','form-select chosen-processed');
				$('#edit-profile-agency-data-field-root-agency-und').attr('style','display: none;');
				$('#edit-profile-agency-data-field-root-agency-und').find('option:first').attr('value', '_none').parent('select');
			}else{
				$('#edit-profile-agency-data-field-root-agency-und').removeAttr('style','display: none;');
				$('#edit-profile-agency-data-field-other-agency-name-und-0-value').removeAttr('required','required');
				$('#edit-profile-agency-data-field-root-agency-und').attr('required','');
				$('#edit-profile-agency-data-field-root-agency-und').attr('class','form-select chosen-processed selectAbsolute');
				$('#edit-profile-agency-data-field-root-agency-und').find('option:first').attr('value', '').parent('select');
			}
		});
		var tamanoCarousel = $('.carousel-right-content .listadoMenu').children("li").size();
		switch(tamanoCarousel){
			case 2:
			   $(".carousel-right-content .listadoMenu li span").addClass("letraCarousel2");
			   break;
			case 3:
			   $(".carousel-right-content .listadoMenu li span").addClass("letraCarousel3");
			   break;
			case 4:
			   $(".carousel-right-content .listadoMenu li span").addClass("letraCarousel4");
			   break;
			case 5:
			   $(".carousel-right-content .listadoMenu li span").addClass("letraCarousel5");
			   break;
		}
		/* Sector */
		if ($(window).width() > 1024) {
			$(document).ready(function () {
				$('.dge-sector--link').hover(function () {
					$(this).find('.dge-sector--description_content p').stop().animate({
						height: "toggle",
						opacity: "toggle",
						maxHeight: "140px"
					}, 300);
				});

			});

		}


    //SDA-932 SEO, change link headers
  $("head link[hreflang|='x-default']").attr("hreflang", "es");

	$("head link[rel|='canonical']").attr("href", window.location.href);

    /*ISSUE 1004*/
  $('#initiative-node-form fieldset legend').addClass('legend__form');
  /*$('#initiative-node-form fieldset .group-initiative-identification div.fieldset-wrapper').after('<div class="vertical--mark__form"></div>');*/
	$('#initiative-node-form .group-initiative-identification div.fieldset-wrapper').after('<div class="vertical--mark__form"></div>');
	$('#initiative-node-form .field-name-field-geoposition div.fieldset-wrapper').after('<div class="vertical--mark__form"></div>');
	$('#initiative-node-form .group-initiative-catalog div.fieldset-wrapper').after('<div class="vertical--mark__form"></div>');
	$('#initiative-node-form .group-initiative-promotion div.fieldset-wrapper').after('<div class="vertical--mark__form"></div>');
	$('#initiative-node-form .group-sender-data div.fieldset-wrapper').after('<div class="vertical--mark__form"></div>');

    $('.pane-initiative-search-panel-pane-2 .view-display-id-panel_pane_2 .item-list').attr('id', 'list-initiatives-container');
    if($('.pane-initiative-search-panel-pane-2 .view-display-id-panel_pane_2').length) {
      $('.pane-block-10').remove();
    }
    $('#initiative-node-form fieldset.group-initiative-promotion').append($('#initiative-node-form div#edit-field-initiative-collaborate'));


	});
})(jQuery);
