<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_desafio_aporta (datos.gob.es)".
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

/**
 * @file
 * dgef_desafio_aporta.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dgef_desafio_aporta_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_aporta_awards';
  $strongarm->value = '0';
  $export['comment_anonymous_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_carousel';
  $strongarm->value = '0';
  $export['comment_anonymous_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_challenge_aporta';
  $strongarm->value = '0';
  $export['comment_anonymous_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_current_aporta';
  $strongarm->value = '0';
  $export['comment_anonymous_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_speakers_aporta';
  $strongarm->value = '0';
  $export['comment_anonymous_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_aporta_awards';
  $strongarm->value = '2';
  $export['comment_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_carousel';
  $strongarm->value = '2';
  $export['comment_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_challenge_aporta';
  $strongarm->value = '2';
  $export['comment_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_current_aporta';
  $strongarm->value = '2';
  $export['comment_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_aporta_awards';
  $strongarm->value = 1;
  $export['comment_default_mode_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_carousel';
  $strongarm->value = 1;
  $export['comment_default_mode_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_challenge_aporta';
  $strongarm->value = 1;
  $export['comment_default_mode_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_current_aporta';
  $strongarm->value = 1;
  $export['comment_default_mode_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_speakers_aporta';
  $strongarm->value = 1;
  $export['comment_default_mode_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_aporta_awards';
  $strongarm->value = '50';
  $export['comment_default_per_page_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_carousel';
  $strongarm->value = '50';
  $export['comment_default_per_page_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_challenge_aporta';
  $strongarm->value = '50';
  $export['comment_default_per_page_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_current_aporta';
  $strongarm->value = '50';
  $export['comment_default_per_page_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_speakers_aporta';
  $strongarm->value = '50';
  $export['comment_default_per_page_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_aporta_awards';
  $strongarm->value = 1;
  $export['comment_form_location_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_carousel';
  $strongarm->value = 1;
  $export['comment_form_location_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_challenge_aporta';
  $strongarm->value = 1;
  $export['comment_form_location_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_current_aporta';
  $strongarm->value = 1;
  $export['comment_form_location_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_speakers_aporta';
  $strongarm->value = 1;
  $export['comment_form_location_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_aporta_awards';
  $strongarm->value = '1';
  $export['comment_preview_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_carousel';
  $strongarm->value = '1';
  $export['comment_preview_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_challenge_aporta';
  $strongarm->value = '1';
  $export['comment_preview_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_current_aporta';
  $strongarm->value = '1';
  $export['comment_preview_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_speakers_aporta';
  $strongarm->value = '1';
  $export['comment_preview_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_speakers_aporta';
  $strongarm->value = '2';
  $export['comment_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_aporta_awards';
  $strongarm->value = 1;
  $export['comment_subject_field_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_carousel';
  $strongarm->value = 1;
  $export['comment_subject_field_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_challenge_aporta';
  $strongarm->value = 1;
  $export['comment_subject_field_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_current_aporta';
  $strongarm->value = 1;
  $export['comment_subject_field_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_speakers_aporta';
  $strongarm->value = 1;
  $export['comment_subject_field_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_aporta_date_new';
  $strongarm->value = 'd \\d\\e F \\d\\e Y';
  $export['date_format_aporta_date_new'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__aporta_awards';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'carousel_item' => array(
        'custom_settings' => TRUE,
      ),
      'carousel_view' => array(
        'custom_settings' => TRUE,
      ),
      'actual_meeting' => array(
        'custom_settings' => TRUE,
      ),
      'speakers' => array(
        'custom_settings' => TRUE,
      ),
      'agenda' => array(
        'custom_settings' => TRUE,
      ),
      'referenced_content' => array(
        'custom_settings' => TRUE,
      ),
      'challenge_aporta' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'actual_challenge' => array(
        'custom_settings' => FALSE,
      ),
      'actual_winners' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '2',
        ),
        'title' => array(
          'weight' => '28',
        ),
        'path' => array(
          'weight' => '0',
        ),
        'xmlsitemap' => array(
          'weight' => '1',
        ),
      ),
      'display' => array(
        'created' => array(
          'default' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'actual_winners' => array(
            'weight' => '20',
            'visible' => FALSE,
          ),
        ),
        'author' => array(
          'default' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
          'actual_winners' => array(
            'weight' => '21',
            'visible' => FALSE,
          ),
        ),
        'title' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'actual_winners' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'language_markup_enabled' => array(
          'default' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'actual_winners' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__carousel';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'carousel_item' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'carousel_view' => array(
        'custom_settings' => TRUE,
      ),
      'actual_meeting' => array(
        'custom_settings' => FALSE,
      ),
      'agenda' => array(
        'custom_settings' => FALSE,
      ),
      'speakers' => array(
        'custom_settings' => FALSE,
      ),
      'referenced_content' => array(
        'custom_settings' => TRUE,
      ),
      'challenge_aporta' => array(
        'custom_settings' => FALSE,
      ),
      'actual_challenge' => array(
        'custom_settings' => FALSE,
      ),
      'actual_winners' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '5',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'xmlsitemap' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(
        'created' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'carousel_view' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'author' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'carousel_view' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'title' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'carousel_view' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'language_markup_enabled' => array(
          'default' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'carousel_view' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__challenge_aporta';
  $strongarm->value = array(
    'view_modes' => array(
      'agenda' => array(
        'custom_settings' => FALSE,
      ),
      'speakers' => array(
        'custom_settings' => FALSE,
      ),
      'referenced_content' => array(
        'custom_settings' => TRUE,
      ),
      'challenge_aporta' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'carousel_item' => array(
        'custom_settings' => TRUE,
      ),
      'carousel_view' => array(
        'custom_settings' => TRUE,
      ),
      'actual_meeting' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'actual_challenge' => array(
        'custom_settings' => TRUE,
      ),
      'actual_winners' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '2',
        ),
        'title' => array(
          'weight' => '8',
        ),
        'path' => array(
          'weight' => '1',
        ),
        'xmlsitemap' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'created' => array(
          'default' => array(
            'weight' => '24',
            'visible' => FALSE,
          ),
          'desaf_o_actual' => array(
            'weight' => '24',
            'visible' => FALSE,
          ),
          'actual_challenge' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'author' => array(
          'default' => array(
            'weight' => '25',
            'visible' => FALSE,
          ),
          'desaf_o_actual' => array(
            'weight' => '25',
            'visible' => FALSE,
          ),
          'actual_challenge' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'title' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'desaf_o_actual' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'actual_challenge' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'language_markup_enabled' => array(
          'default' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'desaf_o_actual' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'actual_challenge' => array(
            'weight' => '27',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__current_aporta';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'carousel_item' => array(
        'custom_settings' => TRUE,
      ),
      'carousel_view' => array(
        'custom_settings' => TRUE,
      ),
      'actual_meeting' => array(
        'custom_settings' => TRUE,
      ),
      'agenda' => array(
        'custom_settings' => TRUE,
      ),
      'speakers' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'referenced_content' => array(
        'custom_settings' => TRUE,
      ),
      'challenge_aporta' => array(
        'custom_settings' => FALSE,
      ),
      'actual_challenge' => array(
        'custom_settings' => FALSE,
      ),
      'actual_winners' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '2',
        ),
        'title' => array(
          'weight' => '59',
        ),
        'path' => array(
          'weight' => '0',
        ),
        'xmlsitemap' => array(
          'weight' => '1',
        ),
      ),
      'display' => array(
        'created' => array(
          'default' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'agenda' => array(
            'weight' => '-5',
            'visible' => TRUE,
          ),
          'actual_meeting' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'author' => array(
          'default' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'agenda' => array(
            'weight' => '-3',
            'visible' => TRUE,
          ),
          'actual_meeting' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'title' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'agenda' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
          'actual_meeting' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'language_markup_enabled' => array(
          'default' => array(
            'weight' => '16',
            'visible' => TRUE,
          ),
          'agenda' => array(
            'weight' => '100',
            'visible' => TRUE,
          ),
          'actual_meeting' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__speakers_aporta';
  $strongarm->value = array(
    'view_modes' => array(
      'agenda' => array(
        'custom_settings' => TRUE,
      ),
      'speakers' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'carousel_item' => array(
        'custom_settings' => TRUE,
      ),
      'carousel_view' => array(
        'custom_settings' => TRUE,
      ),
      'actual_meeting' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'referenced_content' => array(
        'custom_settings' => TRUE,
      ),
      'challenge_aporta' => array(
        'custom_settings' => TRUE,
      ),
      'actual_challenge' => array(
        'custom_settings' => FALSE,
      ),
      'actual_winners' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '40',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'xmlsitemap' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'created' => array(
          'agenda' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'speakers' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'challenge_aporta' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
        'author' => array(
          'agenda' => array(
            'weight' => '-3',
            'visible' => FALSE,
          ),
          'speakers' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'challenge_aporta' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
        ),
        'title' => array(
          'agenda' => array(
            'weight' => '-4',
            'visible' => TRUE,
          ),
          'speakers' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'challenge_aporta' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'language_markup_enabled' => array(
          'agenda' => array(
            'weight' => '100',
            'visible' => FALSE,
          ),
          'speakers' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
          'challenge_aporta' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_aporta_awards';
  $strongarm->value = '0';
  $export['language_content_type_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_carousel';
  $strongarm->value = '0';
  $export['language_content_type_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_challenge_aporta';
  $strongarm->value = '0';
  $export['language_content_type_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_current_aporta';
  $strongarm->value = '0';
  $export['language_content_type_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_speakers_aporta';
  $strongarm->value = '0';
  $export['language_content_type_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_aporta_awards';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_carousel';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_challenge_aporta';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_current_aporta';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_speakers_aporta';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_aporta_awards';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_carousel';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_challenge_aporta';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_current_aporta';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_speakers_aporta';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_aporta_awards';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_carousel';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_challenge_aporta';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_current_aporta';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_speakers_aporta';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_aporta_awards';
  $strongarm->value = '1';
  $export['node_preview_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_carousel';
  $strongarm->value = '1';
  $export['node_preview_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_challenge_aporta';
  $strongarm->value = '1';
  $export['node_preview_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_current_aporta';
  $strongarm->value = '1';
  $export['node_preview_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_speakers_aporta';
  $strongarm->value = '1';
  $export['node_preview_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_aporta_awards';
  $strongarm->value = 0;
  $export['node_submitted_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_carousel';
  $strongarm->value = 0;
  $export['node_submitted_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_challenge_aporta';
  $strongarm->value = 0;
  $export['node_submitted_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_current_aporta';
  $strongarm->value = 0;
  $export['node_submitted_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_speakers_aporta';
  $strongarm->value = 0;
  $export['node_submitted_speakers_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_aporta_awards_pattern';
  $strongarm->value = 'premios-aporta/[node:title]';
  $export['pathauto_node_aporta_awards_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_carousel_pattern';
  $strongarm->value = '';
  $export['pathauto_node_carousel_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_challenge_aporta_pattern';
  $strongarm->value = 'desafios-aporta/[node:title]';
  $export['pathauto_node_challenge_aporta_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_current_aporta_pattern';
  $strongarm->value = 'encuentros-aporta/[node:title]';
  $export['pathauto_node_current_aporta_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_speakers_aporta_pattern';
  $strongarm->value = '';
  $export['pathauto_node_speakers_aporta_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_agenda_titles_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_agenda_titles_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_aporta_situations_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_aporta_situations_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_aporta_awards';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_aporta_awards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_carousel';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_carousel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_challenge_aporta';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_challenge_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_current_aporta';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_current_aporta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_speakers_aporta';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_speakers_aporta'] = $strongarm;

  return $export;
}
