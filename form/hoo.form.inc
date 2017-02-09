<?php
/**
 * @file
 * Form alterations for Hours content
 */

/**
 * Implements hook_form_alter().
 */
function hoo_form_hours_node_form_alter(&$form, &$form_state, $form_id) {
  $form['title']['#default_value'] = uniqid();
  $form['title']['#access'] = false;
}
