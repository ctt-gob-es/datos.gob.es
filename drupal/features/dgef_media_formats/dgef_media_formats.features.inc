<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_media_formats (datos.gob.es)".
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
 * dgef_media_formats.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function dgef_media_formats_image_default_styles() {
  $styles = array();

  // Exported image style: aporta_image.
  $styles['aporta_image'] = array(
    'label' => 'aporta_image',
    'effects' => array(
      17 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 478,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: aporta_teaser.
  $styles['aporta_teaser'] = array(
    'label' => 'aporta_teaser',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 130,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: app_images.
  $styles['app_images'] = array(
    'label' => 'app_images',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: app_logo.
  $styles['app_logo'] = array(
    'label' => 'app_logo',
    'effects' => array(
      18 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 478,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: app_teaser.
  $styles['app_teaser'] = array(
    'label' => 'app_teaser',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 130,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: blog_carousel.
  $styles['blog_carousel'] = array(
    'label' => 'blog_carousel',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 530,
          'height' => 180,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: blog_image.
  $styles['blog_image'] = array(
    'label' => 'blog_image',
    'effects' => array(
      19 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 478,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: blog_teaser.
  $styles['blog_teaser'] = array(
    'label' => 'blog_teaser',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 130,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: bulletin_image.
  $styles['bulletin_image'] = array(
    'label' => 'bulletin_image',
    'effects' => array(
      20 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 478,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: doc_image.
  $styles['doc_image'] = array(
    'label' => 'doc_image',
    'effects' => array(
      21 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 478,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: doc_teaser.
  $styles['doc_teaser'] = array(
    'label' => 'doc_teaser',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 130,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: event_image.
  $styles['event_image'] = array(
    'label' => 'event_image',
    'effects' => array(
      22 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 478,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: event_teaser.
  $styles['event_teaser'] = array(
    'label' => 'event_teaser',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 130,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: home_carousel.
  $styles['home_carousel'] = array(
    'label' => 'home_carousel',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 530,
          'height' => 180,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: map_marker.
  $styles['map_marker'] = array(
    'label' => 'map_marker',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 36,
          'height' => 42,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: sector_cover.
  $styles['sector_cover'] = array(
    'label' => 'sector_cover',
    'effects' => array(
      29 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1200,
          'height' => 120,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: sector_link.
  $styles['sector_link'] = array(
    'label' => 'sector_link',
    'effects' => array(
      30 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 208,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: success_image.
  $styles['success_image'] = array(
    'label' => 'success_image',
    'effects' => array(
      23 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 478,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: success_teaser.
  $styles['success_teaser'] = array(
    'label' => 'success_teaser',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 130,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: talk_image.
  $styles['talk_image'] = array(
    'label' => 'talk_image',
    'effects' => array(
      15 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 478,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: talk_teaser.
  $styles['talk_teaser'] = array(
    'label' => 'talk_teaser',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 130,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
