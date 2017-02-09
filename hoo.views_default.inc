<?php
/**
 * @file
 * hoo.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hoo_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hoo';
  $view->description = 'Monthly and today';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'HOO';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any hours content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Field: Content: Hours */
  $handler->display->display_options['fields']['field_hours']['id'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['table'] = 'field_data_field_hours';
  $handler->display->display_options['fields']['field_hours']['field'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['label'] = '';
  $handler->display->display_options['fields']['field_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['settings'] = array(
    'format_type' => 'just_hour',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_hours']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['delta_offset'] = '0';
  /* Field: Content: Open */
  $handler->display->display_options['fields']['field_open']['id'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['table'] = 'field_data_field_open';
  $handler->display->display_options['fields']['field_open']['field'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['label'] = '';
  $handler->display->display_options['fields']['field_open']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Field: Library */
  $handler->display->display_options['fields']['field_library']['id'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['table'] = 'field_data_field_library';
  $handler->display->display_options['fields']['field_library']['field'] = 'field_library';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: Library (field_library) (reference filter) */
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['id'] = 'field_library_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['table'] = 'field_data_field_library';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['field'] = 'field_library_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['operator_id'] = 'field_library_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['operator'] = 'field_library_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['identifier'] = 'field_library_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['reference_display'] = 'locations_grouped_by_ccl_status:entityreference_1';

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Monthly View';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '0';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'alert' => '#ffffff',
    'page' => '#ffffff',
    'citation' => '#ffffff',
    'book' => '#ffffff',
    'building' => '#ffffff',
    'campus' => '#ffffff',
    'featured_collection' => '#ffffff',
    'department' => '#ffffff',
    'events' => '#ffffff',
    'group' => '#ffffff',
    'homepage_feature' => '#ffffff',
    'hours' => '#ffffff',
    'job' => '#ffffff',
    'library' => '#ffffff',
    'person' => '#ffffff',
    'policy' => '#ffffff',
    'semester_hours' => '#ffffff',
    'space' => '#ffffff',
    'story' => '#ffffff',
    'webform' => '#ffffff',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Hours */
  $handler->display->display_options['fields']['field_hours']['id'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['table'] = 'field_data_field_hours';
  $handler->display->display_options['fields']['field_hours']['field'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['label'] = '';
  $handler->display->display_options['fields']['field_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['settings'] = array(
    'format_type' => 'just_hour',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_hours']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['delta_offset'] = '0';
  /* Field: Content: Open */
  $handler->display->display_options['fields']['field_open']['id'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['table'] = 'field_data_field_open';
  $handler->display->display_options['fields']['field_open']['field'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['label'] = '';
  $handler->display->display_options['fields']['field_open']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_hours.field_hours_value' => 'field_data_field_hours.field_hours_value',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: Library (field_library) (reference filter) */
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['id'] = 'field_library_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['table'] = 'field_data_field_library';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['field'] = 'field_library_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['operator_id'] = 'field_library_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['operator'] = 'field_library_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['identifier'] = 'library';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['reference_display'] = 'locations_grouped_by_ccl_status:entityreference_1';
  $handler->display->display_options['path'] = 'monthly-hours';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'mini';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_hours.field_hours_value' => 'field_data_field_hours.field_hours_value',
  );

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'block_2');
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_hours.field_hours_value' => 'field_data_field_hours.field_hours_value',
  );
  /* Filter criterion: Field: Library (field_library) */
  $handler->display->display_options['filters']['field_library_target_id']['id'] = 'field_library_target_id';
  $handler->display->display_options['filters']['field_library_target_id']['table'] = 'field_data_field_library';
  $handler->display->display_options['filters']['field_library_target_id']['field'] = 'field_library_target_id';
  $handler->display->display_options['filters']['field_library_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_target_id']['expose']['operator_id'] = 'field_library_target_id_op';
  $handler->display->display_options['filters']['field_library_target_id']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['field_library_target_id']['expose']['operator'] = 'field_library_target_id_op';
  $handler->display->display_options['filters']['field_library_target_id']['expose']['identifier'] = 'field_library_target_id';
  $handler->display->display_options['filters']['field_library_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    13 => 0,
  );

  /* Display: Hours Today: Library Specific */
  $handler = $view->new_display('block', 'Hours Today: Library Specific', 'block_4');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: View area */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['label'] = 'Pattee and Paterno ';
  $handler->display->display_options['empty']['view']['empty'] = TRUE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'hoo:block_3';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_library_target_id']['id'] = 'field_library_target_id';
  $handler->display->display_options['relationships']['field_library_target_id']['table'] = 'field_data_field_library';
  $handler->display->display_options['relationships']['field_library_target_id']['field'] = 'field_library_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Library */
  $handler->display->display_options['fields']['field_library']['id'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['table'] = 'field_data_field_library';
  $handler->display->display_options['fields']['field_library']['field'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['label'] = '';
  $handler->display->display_options['fields']['field_library']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_library']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_library']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: cn */
  $handler->display->display_options['fields']['field_cn']['id'] = 'field_cn';
  $handler->display->display_options['fields']['field_cn']['table'] = 'field_data_field_cn';
  $handler->display->display_options['fields']['field_cn']['field'] = 'field_cn';
  $handler->display->display_options['fields']['field_cn']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['field_cn']['label'] = '';
  $handler->display->display_options['fields']['field_cn']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cn']['element_label_colon'] = FALSE;
  /* Field: Content: Open */
  $handler->display->display_options['fields']['field_open']['id'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['table'] = 'field_data_field_open';
  $handler->display->display_options['fields']['field_open']['field'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['label'] = '';
  $handler->display->display_options['fields']['field_open']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_open']['element_label_colon'] = FALSE;
  /* Field: Content: Hours */
  $handler->display->display_options['fields']['field_hours']['id'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['table'] = 'field_data_field_hours';
  $handler->display->display_options['fields']['field_hours']['field'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['label'] = '';
  $handler->display->display_options['fields']['field_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hours']['alter']['text'] = '<div class="hours">
<a href="/hours-and-locations">
<span class="hours__building"><i class="fa fa-clock-o"></i> [field_cn]</span>
 [field_open]
<span class="hours__hours">[field_hours]</span>
</a>
</div>';
  $handler->display->display_options['fields']['field_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['settings'] = array(
    'format_type' => 'just_hour',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_hours']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Library (field_library) */
  $handler->display->display_options['arguments']['field_library_target_id']['id'] = 'field_library_target_id';
  $handler->display->display_options['arguments']['field_library_target_id']['table'] = 'field_data_field_library';
  $handler->display->display_options['arguments']['field_library_target_id']['field'] = 'field_library_target_id';
  $handler->display->display_options['arguments']['field_library_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_library_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_library_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_library_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_library_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: Library (field_library) (reference filter) */
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['id'] = 'field_library_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['table'] = 'field_data_field_library';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['field'] = 'field_library_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['operator_id'] = 'field_library_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['operator'] = 'field_library_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['identifier'] = 'field_library_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['reference_display'] = 'locations_grouped_by_ccl_status:entityreference_1';
  /* Filter criterion: Content: Hours -  start date (field_hours) */
  $handler->display->display_options['filters']['field_hours_value']['id'] = 'field_hours_value';
  $handler->display->display_options['filters']['field_hours_value']['table'] = 'field_data_field_hours';
  $handler->display->display_options['filters']['field_hours_value']['field'] = 'field_hours_value';
  $handler->display->display_options['filters']['field_hours_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_hours_value']['default_date'] = '-1 day 12AM';
  $handler->display->display_options['filters']['field_hours_value']['year_range'] = '-1:+3';
  /* Filter criterion: Content: Hours -  start date (field_hours) */
  $handler->display->display_options['filters']['field_hours_value_1']['id'] = 'field_hours_value_1';
  $handler->display->display_options['filters']['field_hours_value_1']['table'] = 'field_data_field_hours';
  $handler->display->display_options['filters']['field_hours_value_1']['field'] = 'field_hours_value';
  $handler->display->display_options['filters']['field_hours_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_hours_value_1']['default_date'] = '+1 day 12AM';

  /* Display: Hours Today: P&P */
  $handler = $view->new_display('block', 'Hours Today: P&P', 'block_3');
  $handler->display->display_options['display_description'] = 'Global header hours, Pattee and Paterno hours of operation';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_library_target_id']['id'] = 'field_library_target_id';
  $handler->display->display_options['relationships']['field_library_target_id']['table'] = 'field_data_field_library';
  $handler->display->display_options['relationships']['field_library_target_id']['field'] = 'field_library_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Library */
  $handler->display->display_options['fields']['field_library']['id'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['table'] = 'field_data_field_library';
  $handler->display->display_options['fields']['field_library']['field'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['label'] = '';
  $handler->display->display_options['fields']['field_library']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_library']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_library']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: cn */
  $handler->display->display_options['fields']['field_cn']['id'] = 'field_cn';
  $handler->display->display_options['fields']['field_cn']['table'] = 'field_data_field_cn';
  $handler->display->display_options['fields']['field_cn']['field'] = 'field_cn';
  $handler->display->display_options['fields']['field_cn']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['field_cn']['label'] = '';
  $handler->display->display_options['fields']['field_cn']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cn']['element_label_colon'] = FALSE;
  /* Field: Content: Open */
  $handler->display->display_options['fields']['field_open']['id'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['table'] = 'field_data_field_open';
  $handler->display->display_options['fields']['field_open']['field'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['label'] = '';
  $handler->display->display_options['fields']['field_open']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_open']['element_label_colon'] = FALSE;
  /* Field: Content: Hours */
  $handler->display->display_options['fields']['field_hours']['id'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['table'] = 'field_data_field_hours';
  $handler->display->display_options['fields']['field_hours']['field'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['label'] = '';
  $handler->display->display_options['fields']['field_hours']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_hours']['alter']['text'] = '<div class="hours">
<a href="/hours-and-locations">
<span class="hours__building"><i class="fa fa-clock-o"></i> [field_library]</span>
 [field_open]
<span class="hours__hours">[field_hours]</span>
</a>
</div>';
  $handler->display->display_options['fields']['field_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['settings'] = array(
    'format_type' => 'just_hour',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_hours']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Hours -  start date (field_hours) */
  $handler->display->display_options['filters']['field_hours_value']['id'] = 'field_hours_value';
  $handler->display->display_options['filters']['field_hours_value']['table'] = 'field_data_field_hours';
  $handler->display->display_options['filters']['field_hours_value']['field'] = 'field_hours_value';
  $handler->display->display_options['filters']['field_hours_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_hours_value']['default_date'] = '-1 day 12AM';
  $handler->display->display_options['filters']['field_hours_value']['year_range'] = '-1:+3';
  /* Filter criterion: Content: Hours -  start date (field_hours) */
  $handler->display->display_options['filters']['field_hours_value_1']['id'] = 'field_hours_value_1';
  $handler->display->display_options['filters']['field_hours_value_1']['table'] = 'field_data_field_hours';
  $handler->display->display_options['filters']['field_hours_value_1']['field'] = 'field_hours_value';
  $handler->display->display_options['filters']['field_hours_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_hours_value_1']['default_date'] = '+1 day 12AM';
  /* Filter criterion: Field: Library (field_library) */
  $handler->display->display_options['filters']['field_library_target_id']['id'] = 'field_library_target_id';
  $handler->display->display_options['filters']['field_library_target_id']['table'] = 'field_data_field_library';
  $handler->display->display_options['filters']['field_library_target_id']['field'] = 'field_library_target_id';
  $handler->display->display_options['filters']['field_library_target_id']['value'] = array(
    967 => '967',
  );

  /* Display: Month (EDIT MODE) */
  $handler = $view->new_display('page', 'Month (EDIT MODE)', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Monthly View';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '0';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'alert' => '#ffffff',
    'page' => '#ffffff',
    'citation' => '#ffffff',
    'book' => '#ffffff',
    'building' => '#ffffff',
    'campus' => '#ffffff',
    'featured_collection' => '#ffffff',
    'department' => '#ffffff',
    'events' => '#ffffff',
    'group' => '#ffffff',
    'homepage_feature' => '#ffffff',
    'hours' => '#ffffff',
    'job' => '#ffffff',
    'library' => '#ffffff',
    'person' => '#ffffff',
    'policy' => '#ffffff',
    'semester_hours' => '#ffffff',
    'space' => '#ffffff',
    'story' => '#ffffff',
    'webform' => '#ffffff',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Hours */
  $handler->display->display_options['fields']['field_hours']['id'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['table'] = 'field_data_field_hours';
  $handler->display->display_options['fields']['field_hours']['field'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['label'] = '';
  $handler->display->display_options['fields']['field_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['settings'] = array(
    'format_type' => 'just_hour',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_hours']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['delta_offset'] = '0';
  /* Field: Content: Open */
  $handler->display->display_options['fields']['field_open']['id'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['table'] = 'field_data_field_open';
  $handler->display->display_options['fields']['field_open']['field'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['label'] = '';
  $handler->display->display_options['fields']['field_open']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Edit, clone or delete */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Edit, clone or delete';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<a href="/node/[nid]/edit?destination=edit-hours">edit</a> | <a href="/node/[nid]/clone/confirm?destination=edit-hours">clone</a> | <a href="/node/[nid]/delete?destination=edit-hours">delete</a>
';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_hours.field_hours_value' => 'field_data_field_hours.field_hours_value',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: Library (field_library) (reference filter) */
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['id'] = 'field_library_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['table'] = 'field_data_field_library';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['field'] = 'field_library_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['operator_id'] = 'field_library_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['operator'] = 'field_library_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['identifier'] = 'field_library_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    13 => 0,
  );
  $handler->display->display_options['filters']['field_library_target_id_entityreference_filter']['reference_display'] = 'locations_grouped_by_ccl_status:entityreference_1';
  $handler->display->display_options['path'] = 'edit-hours';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['hoo'] = $view;

  $view = new view();
  $view->name = 'hoo_weekly';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'HOO Weekly';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Hours and Locations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_cn',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_cn',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: week of hours (field_week_of_hours) */
  $handler->display->display_options['relationships']['field_week_of_hours_value']['id'] = 'field_week_of_hours_value';
  $handler->display->display_options['relationships']['field_week_of_hours_value']['table'] = 'field_data_field_week_of_hours';
  $handler->display->display_options['relationships']['field_week_of_hours_value']['field'] = 'field_week_of_hours_value';
  $handler->display->display_options['relationships']['field_week_of_hours_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_library_target_id']['id'] = 'field_library_target_id';
  $handler->display->display_options['relationships']['field_library_target_id']['table'] = 'field_data_field_library';
  $handler->display->display_options['relationships']['field_library_target_id']['field'] = 'field_library_target_id';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Physical Address */
  $handler->display->display_options['fields']['field_physical_address']['id'] = 'field_physical_address';
  $handler->display->display_options['fields']['field_physical_address']['table'] = 'field_data_field_physical_address';
  $handler->display->display_options['fields']['field_physical_address']['field'] = 'field_physical_address';
  $handler->display->display_options['fields']['field_physical_address']['relationship'] = 'field_within_this_building_target_id';
  $handler->display->display_options['fields']['field_physical_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_physical_address']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_physical_address']['alter']['path'] = 'https://www.google.com/maps/place/[field_physical_address-thoroughfare]+[field_physical_address-locality]+[field_physical_address-administrative_area]+[field_physical_address-postal_code]';
  $handler->display->display_options['fields']['field_physical_address']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_physical_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_physical_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Within this Building */
  $handler->display->display_options['fields']['field_within_this_building']['id'] = 'field_within_this_building';
  $handler->display->display_options['fields']['field_within_this_building']['table'] = 'field_data_field_within_this_building';
  $handler->display->display_options['fields']['field_within_this_building']['field'] = 'field_within_this_building';
  $handler->display->display_options['fields']['field_within_this_building']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['field_within_this_building']['label'] = '';
  $handler->display->display_options['fields']['field_within_this_building']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_within_this_building']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_within_this_building']['alter']['text'] = '<h3>[field_campus] [field_within_this_building]</h3>
[field_physical_address]
';
  $handler->display->display_options['fields']['field_within_this_building']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_within_this_building']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Brief Space Description */
  $handler->display->display_options['fields']['field_brief_space_description']['id'] = 'field_brief_space_description';
  $handler->display->display_options['fields']['field_brief_space_description']['table'] = 'field_data_field_brief_space_description';
  $handler->display->display_options['fields']['field_brief_space_description']['field'] = 'field_brief_space_description';
  $handler->display->display_options['fields']['field_brief_space_description']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['field_brief_space_description']['label'] = '';
  $handler->display->display_options['fields']['field_brief_space_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_brief_space_description']['element_label_colon'] = FALSE;
  /* Field: Field: Library */
  $handler->display->display_options['fields']['field_library']['id'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['table'] = 'field_data_field_library';
  $handler->display->display_options['fields']['field_library']['field'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['label'] = '';
  $handler->display->display_options['fields']['field_library']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_library']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_library']['alter']['text'] = '<a href="[path]"><strong>[field_library]</strong></a><br>
<span class="containing-space">[field_brief_space_description]</span>
<span class="monthly-hours"><a href="/monthly-hours?library=[nid]"><i class="fa fa-calendar-o"></i> Semester Hours</a></span>
';
  $handler->display->display_options['fields']['field_library']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_library']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: week of hours */
  $handler->display->display_options['fields']['field_week_of_hours']['id'] = 'field_week_of_hours';
  $handler->display->display_options['fields']['field_week_of_hours']['table'] = 'field_data_field_week_of_hours';
  $handler->display->display_options['fields']['field_week_of_hours']['field'] = 'field_week_of_hours';
  $handler->display->display_options['fields']['field_week_of_hours']['label'] = '';
  $handler->display->display_options['fields']['field_week_of_hours']['alter']['text'] = '[field_week_of_hours-value]';
  $handler->display->display_options['fields']['field_week_of_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_week_of_hours']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_week_of_hours']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_week_of_hours']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_week_of_hours']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_week_of_hours']['delta_offset'] = '0';
  /* Field: Content: exceptions */
  $handler->display->display_options['fields']['field_exceptions']['id'] = 'field_exceptions';
  $handler->display->display_options['fields']['field_exceptions']['table'] = 'field_data_field_exceptions';
  $handler->display->display_options['fields']['field_exceptions']['field'] = 'field_exceptions';
  $handler->display->display_options['fields']['field_exceptions']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_exceptions']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_exceptions']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_exceptions']['delta_offset'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'semester_hours' => 'semester_hours',
  );
  /* Filter criterion: Content: week of hours (field_week_of_hours) */
  $handler->display->display_options['filters']['field_week_of_hours_value']['id'] = 'field_week_of_hours_value';
  $handler->display->display_options['filters']['field_week_of_hours_value']['table'] = 'field_data_field_week_of_hours';
  $handler->display->display_options['filters']['field_week_of_hours_value']['field'] = 'field_week_of_hours_value';
  $handler->display->display_options['filters']['field_week_of_hours_value']['operator'] = 'not empty';

  /* Display: UP Hours and Locations */
  $handler = $view->new_display('page', 'UP Hours and Locations', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Hours and Locations';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_within_this_building',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_library',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_library_target_id']['id'] = 'field_library_target_id';
  $handler->display->display_options['relationships']['field_library_target_id']['table'] = 'field_data_field_library';
  $handler->display->display_options['relationships']['field_library_target_id']['field'] = 'field_library_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Brief Space Description */
  $handler->display->display_options['fields']['field_brief_space_description']['id'] = 'field_brief_space_description';
  $handler->display->display_options['fields']['field_brief_space_description']['table'] = 'field_data_field_brief_space_description';
  $handler->display->display_options['fields']['field_brief_space_description']['field'] = 'field_brief_space_description';
  $handler->display->display_options['fields']['field_brief_space_description']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['field_brief_space_description']['label'] = '';
  $handler->display->display_options['fields']['field_brief_space_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_brief_space_description']['element_label_colon'] = FALSE;
  /* Field: Content: Hours */
  $handler->display->display_options['fields']['field_hours']['id'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['table'] = 'field_data_field_hours';
  $handler->display->display_options['fields']['field_hours']['field'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['label'] = '';
  $handler->display->display_options['fields']['field_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['settings'] = array(
    'format_type' => 'just_hour',
    'fromto' => 'both',
    'multiple_number' => '1',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_hours']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['delta_offset'] = '0';
  /* Field: Content: Open */
  $handler->display->display_options['fields']['field_open']['id'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['table'] = 'field_data_field_open';
  $handler->display->display_options['fields']['field_open']['field'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['label'] = '';
  $handler->display->display_options['fields']['field_open']['element_label_colon'] = FALSE;
  /* Field: Content: Within this Building */
  $handler->display->display_options['fields']['field_within_this_building']['id'] = 'field_within_this_building';
  $handler->display->display_options['fields']['field_within_this_building']['table'] = 'field_data_field_within_this_building';
  $handler->display->display_options['fields']['field_within_this_building']['field'] = 'field_within_this_building';
  $handler->display->display_options['fields']['field_within_this_building']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['field_within_this_building']['label'] = '';
  $handler->display->display_options['fields']['field_within_this_building']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_within_this_building']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_within_this_building']['alter']['text'] = '<h3><i class="fa fa-building" aria-hidden="true"></i> [field_within_this_building]</h3>';
  $handler->display->display_options['fields']['field_within_this_building']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_within_this_building']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_within_this_building']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: cn */
  $handler->display->display_options['fields']['field_cn']['id'] = 'field_cn';
  $handler->display->display_options['fields']['field_cn']['table'] = 'field_data_field_cn';
  $handler->display->display_options['fields']['field_cn']['field'] = 'field_cn';
  $handler->display->display_options['fields']['field_cn']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['field_cn']['label'] = '';
  $handler->display->display_options['fields']['field_cn']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cn']['element_label_colon'] = FALSE;
  /* Field: Field: Library */
  $handler->display->display_options['fields']['field_library']['id'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['table'] = 'field_data_field_library';
  $handler->display->display_options['fields']['field_library']['field'] = 'field_library';
  $handler->display->display_options['fields']['field_library']['label'] = '';
  $handler->display->display_options['fields']['field_library']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_library']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_library']['alter']['text'] = '<a href="[path]"><strong>[field_library]</strong></a><br>
<span class="containing-space">[field_brief_space_description]</span>
<span class="monthly-hours"><a href="/monthly-hours?library=[nid]"><br><i class="fa fa-calendar-o"></i> Calendar</a></span>';
  $handler->display->display_options['fields']['field_library']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_library']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_library']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hours' => 'hours',
  );
  /* Filter criterion: Content: Hours -  start date (field_hours) */
  $handler->display->display_options['filters']['field_hours_value']['id'] = 'field_hours_value';
  $handler->display->display_options['filters']['field_hours_value']['table'] = 'field_data_field_hours';
  $handler->display->display_options['filters']['field_hours_value']['field'] = 'field_hours_value';
  $handler->display->display_options['filters']['field_hours_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_hours_value']['default_date'] = 'last Saturday';
  /* Filter criterion: Content: Hours -  start date (field_hours) */
  $handler->display->display_options['filters']['field_hours_value_1']['id'] = 'field_hours_value_1';
  $handler->display->display_options['filters']['field_hours_value_1']['table'] = 'field_data_field_hours';
  $handler->display->display_options['filters']['field_hours_value_1']['field'] = 'field_hours_value';
  $handler->display->display_options['filters']['field_hours_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_hours_value_1']['default_date'] = 'next Sunday';
  /* Filter criterion: Content: CCL (field_ccl) */
  $handler->display->display_options['filters']['field_ccl_value']['id'] = 'field_ccl_value';
  $handler->display->display_options['filters']['field_ccl_value']['table'] = 'field_data_field_ccl';
  $handler->display->display_options['filters']['field_ccl_value']['field'] = 'field_ccl_value';
  $handler->display->display_options['filters']['field_ccl_value']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['filters']['field_ccl_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['path'] = 'hours-and-locations';

  /* Display: CCL Hours and Locations */
  $handler = $view->new_display('page', 'CCL Hours and Locations', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Hours and Locations';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_cn',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_cn',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_library_target_id']['id'] = 'field_library_target_id';
  $handler->display->display_options['relationships']['field_library_target_id']['table'] = 'field_data_field_library';
  $handler->display->display_options['relationships']['field_library_target_id']['field'] = 'field_library_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Brief Space Description */
  $handler->display->display_options['fields']['field_brief_space_description']['id'] = 'field_brief_space_description';
  $handler->display->display_options['fields']['field_brief_space_description']['table'] = 'field_data_field_brief_space_description';
  $handler->display->display_options['fields']['field_brief_space_description']['field'] = 'field_brief_space_description';
  $handler->display->display_options['fields']['field_brief_space_description']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['field_brief_space_description']['label'] = '';
  $handler->display->display_options['fields']['field_brief_space_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_brief_space_description']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: cn */
  $handler->display->display_options['fields']['field_cn']['id'] = 'field_cn';
  $handler->display->display_options['fields']['field_cn']['table'] = 'field_data_field_cn';
  $handler->display->display_options['fields']['field_cn']['field'] = 'field_cn';
  $handler->display->display_options['fields']['field_cn']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['fields']['field_cn']['label'] = '';
  $handler->display->display_options['fields']['field_cn']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cn']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cn']['alter']['text'] = '<a href="[path]"><strong>[field_cn]</strong></a><br>
<span class="monthly-hours"><a href="/monthly-hours?library=[nid]"><i class="fa fa-calendar-o"></i> Calendar</a></span>
';
  $handler->display->display_options['fields']['field_cn']['element_label_colon'] = FALSE;
  /* Field: Content: Hours */
  $handler->display->display_options['fields']['field_hours']['id'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['table'] = 'field_data_field_hours';
  $handler->display->display_options['fields']['field_hours']['field'] = 'field_hours';
  $handler->display->display_options['fields']['field_hours']['label'] = '';
  $handler->display->display_options['fields']['field_hours']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['settings'] = array(
    'format_type' => 'just_hour',
    'fromto' => 'both',
    'multiple_number' => '1',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_hours']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_hours']['delta_offset'] = '0';
  /* Field: Content: Open */
  $handler->display->display_options['fields']['field_open']['id'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['table'] = 'field_data_field_open';
  $handler->display->display_options['fields']['field_open']['field'] = 'field_open';
  $handler->display->display_options['fields']['field_open']['label'] = '';
  $handler->display->display_options['fields']['field_open']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hours' => 'hours',
  );
  /* Filter criterion: Content: Hours -  start date (field_hours) */
  $handler->display->display_options['filters']['field_hours_value']['id'] = 'field_hours_value';
  $handler->display->display_options['filters']['field_hours_value']['table'] = 'field_data_field_hours';
  $handler->display->display_options['filters']['field_hours_value']['field'] = 'field_hours_value';
  $handler->display->display_options['filters']['field_hours_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_hours_value']['default_date'] = 'last Saturday';
  /* Filter criterion: Content: Hours -  start date (field_hours) */
  $handler->display->display_options['filters']['field_hours_value_1']['id'] = 'field_hours_value_1';
  $handler->display->display_options['filters']['field_hours_value_1']['table'] = 'field_data_field_hours';
  $handler->display->display_options['filters']['field_hours_value_1']['field'] = 'field_hours_value';
  $handler->display->display_options['filters']['field_hours_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_hours_value_1']['default_date'] = 'next Sunday';
  /* Filter criterion: Content: CCL (field_ccl) */
  $handler->display->display_options['filters']['field_ccl_value']['id'] = 'field_ccl_value';
  $handler->display->display_options['filters']['field_ccl_value']['table'] = 'field_data_field_ccl';
  $handler->display->display_options['filters']['field_ccl_value']['field'] = 'field_ccl_value';
  $handler->display->display_options['filters']['field_ccl_value']['relationship'] = 'field_library_target_id';
  $handler->display->display_options['filters']['field_ccl_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'ccl-hours-and-locations';
  $export['hoo_weekly'] = $view;

  $view = new view();
  $view->name = 'locations_grouped_by_ccl_status';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Locations grouped by CCL status';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_ccl',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: CCL */
  $handler->display->display_options['fields']['field_ccl']['id'] = 'field_ccl';
  $handler->display->display_options['fields']['field_ccl']['table'] = 'field_data_field_ccl';
  $handler->display->display_options['fields']['field_ccl']['field'] = 'field_ccl';
  $handler->display->display_options['fields']['field_ccl']['label'] = '';
  $handler->display->display_options['fields']['field_ccl']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ccl']['element_label_colon'] = FALSE;
  /* Field: Content: cn */
  $handler->display->display_options['fields']['field_cn']['id'] = 'field_cn';
  $handler->display->display_options['fields']['field_cn']['table'] = 'field_data_field_cn';
  $handler->display->display_options['fields']['field_cn']['field'] = 'field_cn';
  $handler->display->display_options['fields']['field_cn']['label'] = '';
  $handler->display->display_options['fields']['field_cn']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cn']['empty'] = '[title]';
  /* Sort criterion: Content: cn (field_cn) */
  $handler->display->display_options['sorts']['field_cn_value']['id'] = 'field_cn_value';
  $handler->display->display_options['sorts']['field_cn_value']['table'] = 'field_data_field_cn';
  $handler->display->display_options['sorts']['field_cn_value']['field'] = 'field_cn_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'library' => 'library',
  );
  /* Filter criterion: Content: CCL (field_ccl) */
  $handler->display->display_options['filters']['field_ccl_value']['id'] = 'field_ccl_value';
  $handler->display->display_options['filters']['field_ccl_value']['table'] = 'field_data_field_ccl';
  $handler->display->display_options['filters']['field_ccl_value']['field'] = 'field_ccl_value';
  $handler->display->display_options['filters']['field_ccl_value']['operator'] = 'not empty';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'not';
  $handler->display->display_options['filters']['title']['value'] = 'Welcome Desk';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_ccl' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['locations_grouped_by_ccl_status'] = $view;

  return $export;
}
