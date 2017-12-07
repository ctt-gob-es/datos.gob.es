/*
 * Superfish v1.4.8 - jQuery menu widget
 * Copyright (c) 2008 Joel Birch
 *
 * Dual licensed under the MIT and GPL licenses:
 *  http://www.opensource.org/licenses/mit-license.php
 *  http://www.gnu.org/licenses/gpl.html
 *
 * CHANGELOG: http://users.tpg.com.au/j_birch/plugins/superfish/changelog.txt
 */

(function($){
    $.fn.superfish = function(op){

        var sf = $.fn.superfish,
            c = sf.c,
            $arrow = $(['<span class="',c.arrowClass,'"> &#187;</span>'].join('')),
            over = function(){
                var $this = $(this), menu = getMenu($this);
                clearTimeout(menu.sfTimer);
                $this.showSuperfishUl().siblings().hideSuperfishUl();
            },
            out = function(){
                var $this = $(this), menu = getMenu($this), o = sf.op;
                clearTimeout(menu.sfTimer);
                menu.sfTimer=setTimeout(function(){
                    o.retainPath=($.inArray($this[0],o.$path)>-1);
                    $this.hideSuperfishUl();
                    if (o.$path.length && $this.parents(['li.',o.hoverClass].join('')).length<1){over.call(o.$path);}
                },o.delay);
            },
            getMenu = function($menu){
                var menu = $menu.parents(['ul.',c.menuClass,':first'].join(''))[0];
                sf.op = sf.o[menu.serial];
                return menu;
            },
            addArrow = function($a){ $a.addClass(c.anchorClass).append($arrow.clone()); };

        return this.each(function() {
          var $this = $(this);
            var s = this.serial = sf.o.length;
            var o = $.extend({},sf.defaults,op);
            o.$path = $('li.'+o.pathClass,this).slice(0,o.pathLevels).each(function(){
                $(this).addClass([o.hoverClass,c.bcClass].join(' '))
                    .filter('li:has(ul)').removeClass(o.pathClass);
            });
            sf.o[s] = sf.op = o;
      // CHANGED: by KARL SWEDBERG
            if ( (o.eventType === 'hoverIntent' && !$.fn.hoverIntent) || !(/^(?:hover|hoverIntent|toggle)$/).test(o.eventType) ) {
              o.eventType = 'hover';
            }
            $this.find('li:has(ul)')[o.eventType](over,out).each(function() {
                if (o.autoArrows) {
                  addArrow( $('>a:first-child',this) );
                 // this.addClass("yourClass");
                }
            })
            .not('.'+c.bcClass)
                .hideSuperfishUl();


            $this.find('a').each(function(i){
                var $a = $(this), $li = $a.parents('li');
                $a.focus(function(){over.call($li);}).blur(function(){out.call($li);});
                $a.click(function(event) {
                  event.preventDefault();
                  if ( !$a.hasClass("sf-with-ul") ) {
                    location.href = this.href;
                  }
                });
            });
            o.onInit.call(this);

        }).each(function() {
            var menuClasses = [c.menuClass];
            if (sf.op.dropShadows  && !($.browser.msie && $.browser.version < 7)) {
              menuClasses.push(c.shadowClass);
            }
            $(this).addClass(menuClasses.join(' '));
        });
    };

    var sf = $.fn.superfish;
    sf.o = [];
    sf.op = {};
    sf.IE7fix = function(){
        var o = sf.op;
        if ($.browser.msie && $.browser.version > 6 && o.dropShadows && o.animation.opacity!=undefined) {
            this.toggleClass(sf.c.shadowClass+'-off');
        }
        };
    sf.c = {
        bcClass     : 'sf-breadcrumb',
        menuClass   : 'sf-js-enabled',
        anchorClass : 'sf-with-ul',
        arrowClass  : 'sf-sub-indicator',
        shadowClass : 'sf-shadow'
    };
    sf.defaults = {
        hoverClass  : 'sfHover',
        pathClass   : 'overideThisToUse',
        pathLevels  : 1,
        delay       : 0,
        animation   : {opacity:'show'},
        speed       : 'normal',
        closeAnimation: {opacity: 'hide'},
        closeSpeed: 0,
        autoArrows  : true,
        dropShadows : true,
    // CHANGED: by KARL SWEDBERG
        eventType   : 'toggle', // one of 'toggle', 'hover', or 'hoverIntent'
    // disableHI  : false,    // true disables hoverIntent detection
        onInit      : function(){}, // callback functions
        onBeforeShow: function(){},
        onShow      : function(){},
        onHide      : function(){}
    };
    $.fn.extend({
        hideSuperfishUl : function(){
            var o = sf.op,
                not = (o.retainPath===true) ? o.$path : '';
            o.retainPath = false;
            var $closingLi = $(['li.',o.hoverClass].join(''),this).add(this).not(not);
            var $ul = $closingLi
                    .find('>ul');
            $ul.animate(o.closeAnimation, o.closeSpeed, function() {
              $closingLi.removeClass(o.hoverClass);
        $ul.css('visibility','hidden');
      });
            o.onHide.call($ul);
            return this;
        },
        showSuperfishUl : function(){
            var o = sf.op,
                sh = sf.c.shadowClass+'-off',
                $ul = this.addClass(o.hoverClass)
                    .find('>ul:hidden').css('visibility','visible');
            sf.IE7fix.call($ul);
            o.onBeforeShow.call($ul);
            $ul.show(0,function(){ sf.IE7fix.call($ul); o.onShow.call($ul);});
            return this;
        }
    });

})(jQuery);