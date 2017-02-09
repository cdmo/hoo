<?php

/**
 * @file
 * Monthly hours massager, extension of HoursMassager
 */

/**
* MonthlyHoursMassager
*/
class MonthlyHoursMassager extends HoursMassager
{
  public $month_year;

  public function compareTodayToYesterdayAndTomorrow($hours_item)
  {
    parent::compareTodayToYesterdayAndTomorrow($hours_item);

    foreach ($this->hours_array as $key => &$hours_item) {
      $this->removeBleeders($hours_item, $key);
    }
  }

  public function removeBleeders($hours_item, $key)
  {
    // Takes care of hours that bleed over from the previous month when
    // the last day of the previous month has hours that extend into this
    // month.
    if (substr($hours_item->field_data_field_hours_field_hours_value, 0, 7) != $this->month_year) {
      unset($this->hours_array[$key]);
    }
  }
}
