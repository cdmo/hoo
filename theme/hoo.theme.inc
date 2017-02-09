<?php

/**
 * @file
 * Theme-related hooks for modifying display-related items on hours content
 */

/**
 * Implements hook_views_pre_render(&$view).
 *
 * @param &$view Any view being passed to the page
 */
function hoo_views_pre_render(&$view) {
  // HOO monthly view
  if ($view->name == "hoo" && $view->current_display == "page_1" ||
      $view->name == "hoo" && $view->current_display == "page_2") {

    $monthly_hours_shaped = new MonthlyHoursMassager($view->result);
    $monthly_hours_shaped->month_year = $view->args[0];
    $monthly_hours_shaped->iterateOverHoursOfOperation();

    $view->result = $monthly_hours_shaped->hours_array;

    // Building breadcrumbs
    $breadcrumb = array();
    $breadcrumb[] = l('Home', '<front>');
    $breadcrumb[] = l('Hours and Locations', 'hours-and-locations');
    // Setting breadcrumbs
    drupal_set_breadcrumb($breadcrumb);
  }

  // HOO today view
  if ($view->name == "hoo" && $view->current_display == "block_3" ||
      $view->name == "hoo" && $view->current_display == "block_4") {

    $day_hours_shaped = new DayHoursMassager($view->result);
    $day_hours_shaped->iterateOverHoursOfOperation();
    $view->result = $day_hours_shaped->hours_array;
  }

  // HOO weekly view
  if ($view->name == "hoo_weekly") {

    $weekly_hours_shaped = new WeeklyHoursMassager($view->result, $view->current_display);
    $weekly_hours_shaped->iterateOverHoursOfOperation();

    $view->result = $weekly_hours_shaped->hours_array;
    $view->attachment_after = $weekly_hours_shaped->printLibrariesAndPhoneNumbers();
  }
}

/**
 * Implements template_preprocess_page.
 *
 * Add convenience variables and template suggestions.
 */
function hoo_preprocess_page(&$variables, $hook) {
  if (!empty($variables['node']->type) &&
    $variables['node']->type == 'hours') {
    $variables['title'] = false;
  }
}
