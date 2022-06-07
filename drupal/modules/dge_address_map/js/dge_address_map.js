(function($) {
    var leafletMap;
    Drupal.behaviors.dge_leaflet = {
        attach: function () {
            $(document).bind('leaflet.map', function(e, map, lMap){
                /* Search Layer Needs Google Maps*/
                var geocoder = new google.maps.Geocoder();

                function googleGeocoding(text, callResponse) {
                    geocoder.geocode({address: text,
                        componentRestrictions: {
                            country: 'ES'
                        }
                    }, callResponse);
                }

                function formatJSON(rawjson) {
                    var json = {},
                        key, loc, disp = [];
                    for(var i in rawjson)
                    {
                        key = rawjson[i].formatted_address;
                        loc = L.latLng( rawjson[i].geometry.location.lat(), rawjson[i].geometry.location.lng() );
                        json[ key ]= loc;	//key,value format
                    }
                    return json;
                }
                lMap.zoomControl.setPosition('bottomright');
                lMap.addControl(new L.Control.Fullscreen({position:'bottomright'}));
                lMap.addControl( new L.Control.Search({
                    sourceData: googleGeocoding,
                    formatData: formatJSON,
                    markerLocation: false,
                    autoType: false,
                    autoCollapse: true,
                    textPlaceholder: Drupal.t('Search...'),
                    textErr: Drupal.t('Location not found'),
                    textCancel: Drupal.t('Cancel'),
                    collapsed: false,
                    minLength: 3
                }) );

                //Add custom offset to marker popups
                lMap.on('popupopen', function(e) {
                    if (e.popup.options.offset.x != 0 ||
                        e.popup.options.offset.y != -15){
                        e.popup.options.offset = new L.Point(0, -15);
                        e.popup._updatePosition();
                    }
                });

                /* Layer selector */
                var layerControlElement = document.getElementsByClassName('leaflet-control-layers')[0];
                $('a[data-leaflet-baselayer]').eq(0).addClass('facetapi-active');
                $('a[data-leaflet-baselayer]').click( function (e) {
                    e.stopPropagation();
                    // Get layer number
                    var l = $(this).attr('data-leaflet-baselayer');
                    // Trigger layer visible
                    layerControlElement.getElementsByTagName('input')[l].click();
                    return false;
                });
                lMap.on('baselayerchange', function(e) {
                    // Set left control styles
                    $('a[data-leaflet-baselayer]').each(function(){
                        $(this).removeClass('facetapi-active');
                        // Get layer name and compare with control name
                        if ($(this).text() == e.name) {
                            $(this).addClass('facetapi-active');
                        }
                    });
                    return false;
                });

                leafletMap = lMap;
            });
        },
        getMap: function () {
            return leafletMap;
        }
    }
})(jQuery);
