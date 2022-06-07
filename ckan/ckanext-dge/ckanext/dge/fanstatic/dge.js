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

(function($){
	$(document).ready(function(){

		/*::::::::: FOCUS CONDICIONES :::::::: */
		 $('#edit-mail').focus(function() {
			$('#footer-conditions').show();
		 });

		/*::::::::: LOGIN responsive :::::::: */
		//$('.block-user form').before('<a class="closeModalMD closeLogin no-text"><i class="icon-remove-sign"></i><span class="element-invisible">close</span></a>');

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
		$('.social .section-title a').click(function(){
			$('.social').toggleClass('is-visible');
			return false;
		});

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
				$('.social').removeClass('is-visible');
			});
			// prevent click close propagation
			$('#dge-main-menu--rwd, .social ul').tap(function(e){
				e.stopPropagation();
			});
		};

		/* ::::::: CLOSE MENU AND MODAL on RESIZE ::::::: */
		var width = $(window).width();
		$(window).resize(function() {
			if($(this).width() != width){
				width = $(this).width();
				$.sidr('close', 'dge-main-menu--rwd', 'onCloseEnd');
				$('.dge-detail__share').removeClass('is-visible');
				location.reload();
			}
		});

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
		$('.dge-main-menu .block__content a[href="#search"]').attr('data-tooltip', function(){return $(this).text();});
		$('.dge-main-menu .block__content a[href="#login"]').attr('data-tooltip', function(){return $(this).text();});

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

		/*:::::::: CATEGORY LIST ::::::*/
		if($('.dataset-categories').height() > 100){
			$('.dataset-categories').addClass('dataset-categories-full');
		} else {
			$('.dge-category-list').addClass('dataset-categories-mini');
		};
		//dataset list - more than 3 categories
		if (window.matchMedia("(min-width: 60em)").matches) {
			$('.dge-list--dataset .dataset-categories').each(function(){
				if($(this).children().length > 3){
					$(this).addClass('categories-full');
					$(this).after('<a class="categories-open open"><i class="icon-open-sign"></i><span class="element-invisible">Open</span></a>');
				};
			});
			$('.categories-open').click(function(){
				$(this).toggleClass('is-active');
				$(this).prev('.categories-full').toggleClass('selected');
			});
		};

		/*:::::::: CATEGORY LIST ::::::*/
		$('.more-info').mouseleave( function() {
			$(this).find('a').addClass('collapsed');
			$(this).find('div').removeClass('in').css('height',0);
		});


		/*:::::::: NEWSLETTER GDPR ::::::*/
		var $newsletterForm = $('form#simplenews-block-form-21');
		var $input = $newsletterForm.find('input#edit-mail');
		var $input2 = $newsletterForm.find('input#edit-mail--2');
    var $terms_field = $newsletterForm.find('.form-type-checkbox');

	  $terms_field.hide();

    function show_legal() {
			$terms_field.slideDown(700);
    }
    $input.on('focus', function() {
			if ($("#edit-action2-subscribe").prop("checked")) {
				show_legal();
			}
			if ($("#edit-action2-unsubscribe").prop("checked")) {
				$terms_field.slideUp(700);
			}
		});
		$input2.on('focus', function() {
      if ($("#edit-action2-subscribe").prop("checked")) {
				show_legal();
			}
		});
		$('input#edit-submit--4').click(function(){
			if ($("#edit-action2-unsubscribe").prop("checked")) {
				$terms_field.remove();
			}
		});
	});
})(jQuery);
