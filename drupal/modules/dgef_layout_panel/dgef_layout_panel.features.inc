<?php
/**
 * @file
 * dgef_layout_panel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgef_layout_panel_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
}
