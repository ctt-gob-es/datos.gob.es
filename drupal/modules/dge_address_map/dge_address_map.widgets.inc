<?php

/**
 * @file
 * Provides field widget hooks for geofield module.
 */

/**
 * Implements hook_field_widget_info().
 */
function dge_address_map_field_widget_info() {
    return array(
        'dge_address_map_geocode' => array(
            'label' => t('Geocode from direction'),
            'field types' => array('geofield'),
        ),
    );
}


/**
 * Implements hook_field_widget_form().
 */



function dge_address_map_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $base) {

    $element = $base;
    $widget = $instance['widget'];
    $element['input_format'] = array(
        '#type' => 'value',
        '#attributes' => array('class' => array('geofield_input_format')),
        '#value' => GEOFIELD_INPUT_AUTO_DISCOVER,
    );
    switch ($widget['type']) {
        case 'dge_address_map_geocode':
            $latlon_value = array(
                'lat' => '',
                'lon' => '',
            );
            if (isset($items[$delta]['lat'])) {
                $latlon_value['lat'] = floatval($items[$delta]['lat']);
            }
            if (isset($items[$delta]['lon'])) {
                $latlon_value['lon'] = floatval($items[$delta]['lon']);
            }
            $element['geom'] = array(
                '#type' => 'dge_address_map_latlon',
                '#title' => check_plain($instance['label']),
                '#description' => $instance['description'],
                '#default_value' => $latlon_value,
                '#required' => $instance['required'],
                '#delta' => $delta,
            );
            $element['input_format']['#value'] = GEOFIELD_INPUT_LAT_LON;
            break;
    }
    return $element;
}

/**
 * Implements field_widget_settings_form().
 */


/**
 * Implements hook_element_info().
 */
function dge_address_map_element_info() {
    return array(
        'dge_address_map_latlon' => array(
            '#input' => TRUE,
            '#process' => array('dge_address_map_latlon_element_process'),
            '#theme' => array('dge_address_map_latlon'),
        ),
    );
}

/**
 * Process function for dge_address_map_latlon.
 */
function dge_address_map_latlon_element_process($element, &$form_values) {
    $element['#tree'] = TRUE;
    $element['#input'] = TRUE;
    $element['lat'] = array(
        '#type' => 'textfield',
        '#required' => (!empty($element['#required'])) ? $element['#required'] : FALSE,
        '#default_value' => (!empty($element['#default_value']['lat'])) ? $element['#default_value']['lat'] : '',
        '#attributes' => array(
            'hidden' => 'hidden',
            'class' => array('geofield-lat'),
        ),
    );
    $element['lon'] = array(
        '#type' => 'textfield',
        '#required' => (!empty($element['#required'])) ? $element['#required'] : FALSE,
        '#default_value' => (!empty($element['#default_value']['lon'])) ? $element['#default_value']['lon'] : '',
        '#attributes' => array(
            'hidden' => 'hidden',
            'class' => array('geofield-lon'),
        ),
    );
    $element['#required'] = FALSE;
    return $element;
}


function dge_address_map_form_alter(&$form, &$form_state, $form_id) {
    if($form_id == 'current_aporta_node_form'){
        $form['#submit'][] = '_dge_address_map_form_submit';
        $form['field_location_gmaps'] = array(
            'type' => 'hidden',
        );
    }
}

function _dge_address_map_form_submit(&$form, &$form_state) {
    if (isset($form_state['values']['field_direction_ign']['und'][0]['value'])){
        $direccion = $form_state['values']['field_direction_ign']['und'][0]['value'];
        $field_maping['value'] = geocode($direccion);
        $latgeo = $field_maping['value'][0];
        $longeo = $field_maping['value'][1];
        $form_state['values']['field_address_current_aporta']['und']['0']['geom']['lon'] = $longeo;
        $form_state['values']['field_address_current_aporta']['und']['0']['geom']['lat'] = $latgeo;
    }

}