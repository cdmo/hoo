<?php
/**
 * @file
 * hoo.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hoo_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'clone node'.
  $permissions['clone node'] = array(
    'name' => 'clone node',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'hours author' => 'hours author',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'clone own nodes'.
  $permissions['clone own nodes'] = array(
    'name' => 'clone own nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'create hours content'.
  $permissions['create hours content'] = array(
    'name' => 'create hours content',
    'roles' => array(
      'administrator' => 'administrator',
      'hours author' => 'hours author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create semester_hours content'.
  $permissions['create semester_hours content'] = array(
    'name' => 'create semester_hours content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any hours content'.
  $permissions['delete any hours content'] = array(
    'name' => 'delete any hours content',
    'roles' => array(
      'administrator' => 'administrator',
      'hours author' => 'hours author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any semester_hours content'.
  $permissions['delete any semester_hours content'] = array(
    'name' => 'delete any semester_hours content',
    'roles' => array(
      'administrator' => 'administrator',
      'hours author' => 'hours author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own hours content'.
  $permissions['delete own hours content'] = array(
    'name' => 'delete own hours content',
    'roles' => array(
      'administrator' => 'administrator',
      'hours author' => 'hours author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own semester_hours content'.
  $permissions['delete own semester_hours content'] = array(
    'name' => 'delete own semester_hours content',
    'roles' => array(
      'administrator' => 'administrator',
      'hours author' => 'hours author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any hours content'.
  $permissions['edit any hours content'] = array(
    'name' => 'edit any hours content',
    'roles' => array(
      'administrator' => 'administrator',
      'hours author' => 'hours author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any semester_hours content'.
  $permissions['edit any semester_hours content'] = array(
    'name' => 'edit any semester_hours content',
    'roles' => array(
      'administrator' => 'administrator',
      'hours author' => 'hours author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own hours content'.
  $permissions['edit own hours content'] = array(
    'name' => 'edit own hours content',
    'roles' => array(
      'administrator' => 'administrator',
      'hours author' => 'hours author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own semester_hours content'.
  $permissions['edit own semester_hours content'] = array(
    'name' => 'edit own semester_hours content',
    'roles' => array(
      'administrator' => 'administrator',
      'hours author' => 'hours author',
    ),
    'module' => 'node',
  );

  return $permissions;
}
