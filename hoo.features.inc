<?php
/**
 * @file
 * hoo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hoo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hoo_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hoo_node_info() {
  $items = array(
    'hours' => array(
      'name' => t('Hours'),
      'base' => 'node_content',
      'description' => t('Our hours of operation. A single entry of one date OR a repeating entry of many dates. When there\'s a repeating date, Drupal will create a node for each day of hours which allows easy overriding for exceptions.'),
      'has_title' => '1',
      'title_label' => t('Title for administrative purposes only'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
