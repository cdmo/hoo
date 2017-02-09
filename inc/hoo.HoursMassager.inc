<?php

/**
 * @file
 * Class definition for language modifications and the like for hours content
 */


/**
* HoursMassager
*/
class HoursMassager
{
  public $hours_array;

  public function __construct($hours_array)
  {
    $this->hours_array = $hours_array;
    // Ordering by start date
    usort($this->hours_array, array($this, "sortByStartDateAscending"));
  }

  public function iterateOverHoursOfOperation()
  {
    foreach ($this->hours_array as $key => &$hours_item) {
      $this->setComparisonDetails($hours_item, $key);
      $this->compareTodayToYesterdayAndTomorrow($hours_item);
    }
  }

  public function setComparisonDetails($hours_item, $key)
  {
    // Is this current hours item properly set?
    if (isset($hours_item->field_field_hours[0])) {

      // Set Timezone, do this once
      if (!isset($this->tz)) {
        $this->tz = new DateTimeZone($hours_item->field_field_hours[0]['raw']['timezone']);
      }

      // What are today's hours?
      $hours_item->today = $this->setDayDetails($hours_item);

      // What are tomorrow's hours?
      if (isset($this->hours_array[$key+1]->field_field_hours[0]['raw'])) {
        $hours_item->tomorrow = $this->setDayDetails($this->hours_array[$key+1]);
      }

      // What were yesterday's hours?
      if (isset($this->hours_array[$key-1]->field_field_hours[0]['raw'])) {
        $hours_item->yesterday = $this->setDayDetails($this->hours_array[$key-1]);
      }
    }
  }

  public function compareTodayToYesterdayAndTomorrow($hours_item)
  {
    // If closed, show closed, don't show hours, don't process any further for
    // today's hours
    $hours_item->field_field_open[0]['rendered']['#access'] = false;
    if ($hours_item->today['open'] == 0) {
      $hours_item->field_field_open[0]['rendered']['#access'] = true;
      $hours_item->field_field_hours[0]['rendered']['#access'] = false;
      return;
    }

    // Today opens at a time that isn't midnight but doesn't close.
    if ($hours_item->today['start']->format('H:i') != "00:00" &&
        $hours_item->today['end']->format('H:i') == "00:00" &&
        !empty($hours_item->tomorrow['start']) &&
        isset($hours_item->tomorrow) &&
        $hours_item->tomorrow['start']->format('H:i') == "00:00")
    {
      $open_text = " No closing time";
      $display_time = 'Opens at ' . $hours_item->today['start']->format('g:i a') . $open_text;
      $hours_item->field_field_hours[0]['rendered']['#markup'] = $display_time;
    }

    // Going from 24 hour service to closing sometime this day
    if ($hours_item->today['start']->format('H:i') == "00:00" &&
        isset($hours_item->yesterday) &&
        !empty($hours_item->yesterday['end']) &&
        $hours_item->yesterday['end']->format('H:i') == "00:00" &&
        isset($hours_item->tomorrow) &&
        ( $hours_item->tomorrow['start']->format('H:i') != "00:00" ||
          $hours_item->tomorrow['open'] == 0)
        )
    {
      $display_time = 'Open until ' . $hours_item->today['end']->format('g:i a');
      $open_text = "Open";
      $display_time = $hours_item->today['end']->format('H:i') == "00:00" ? "$open_text until Midnight" : $display_time;
      $hours_item->field_field_hours[0]['rendered']['#markup'] = $display_time;
    }
  }


  public function setDayDetails($hours_item)
  {
    $day = array(
      'start' => $this->convertDatetime($hours_item->field_field_hours[0]['raw']['value'], $this->tz),
      'end' => $this->convertDatetime($hours_item->field_field_hours[0]['raw']['value2'], $this->tz),
      'type' => $hours_item->field_data_field_hours_bundle,
      'open' => $hours_item->field_field_open[0]['raw']['value'],
    );

    return $day;
  }

  /**
   * Callback function for psulib_hours_views_post_execute(), used to sort the
   * View result object by start date
   */
  private static function sortByStartDateAscending($a, $b)
  {
    $a_timestamp = strtotime($a->field_field_hours[0]['raw']['value']);
    $b_timestamp = strtotime($b->field_field_hours[0]['raw']['value']);

    return $a_timestamp < $b_timestamp ? -1 : 1;
  }

  /**
   * Drupal is very inconsistent in the way it produces thes DateTime fields.
   * Sometimes they have DateTime objects (raw->db). Sometimes they don't. This
   * function creates DateTime objects for all.
   *
   * @param  string $dt Formatted Drupal timestamp
   * @param  object $tz TimeZone ojbect
   * @return object $dt_obj DateTime object
   */
  public function convertDatetime($dt, $tz)
  {
    $tz_utc = new DateTimeZone('UTC');
    $dt_obj = new DateTime($dt, $tz_utc);
    return $dt_obj->setTimezone($tz);
  }
}
