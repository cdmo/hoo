<?php
/**
 * @file
 * Class definition for language modifications and the like for hours content
 */


/**
* HoursMassager
*/
class DayHoursMassager extends HoursMassager
{
  public function iterateOverHoursOfOperation()
  {
    parent::iterateOverHoursOfOperation();

    // Removing days that aren't today
    $this->findAndRemoveDay();
  }

  public function findAndRemoveDay()
  {
    $now = new DateTime();

    foreach ($this->hours_array as $key => &$day) {
      if ($day->today['start']->format('w') != $now->format('w')) {
        unset($this->hours_array[$key]);
      }
    }
  }
}
