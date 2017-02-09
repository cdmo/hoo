<?php

/**
 * @file
 * Class definition for language modifications and the like for hours content
 */

/**
 * WeeklyHoursMassager
 */
class WeeklyHoursMassager extends HoursMassager {
  public $ccl_display_name = "page_1";
  public $libraries_with_hours = array();
  public $locations_without_hours = array();
  public $last_saturday;
  public $next_sunday;

  public function __construct($hours_array, $display) {
    $this->hours_array = $hours_array;
    
    $this->last_saturday = new DateTime();
    $this->last_saturday->modify("last Saturday");
    $this->last_saturday->setTime(0, 0, 0);

    $this->next_sunday = new DateTime();
    $this->next_sunday->modify("next Sunday");
    $this->next_sunday->setTime(0, 0, 0);

    $this->is_ccl = $display == $this->ccl_display_name ? 1 : 0;

	// Complex sorting
	$sort_algorithm = $this->is_ccl == 1 ? 'commonwealthSort' : 'patteeAndPaternoFirst';
	uasort($this->hours_array, array($this, $sort_algorithm));
    
    // Rekey
    $this->hours_array = array_values($this->hours_array);
  }

  public function iterateOverHoursOfOperation()
  {
    parent::iterateOverHoursOfOperation();

    foreach ($this->hours_array as $key => $hours_item) {
      // Removing the dates that were in the set of results for comparison sake
      // only.
      $this->findAndRemoveDay($key, $hours_item);

    }

    // Make a list of locations that aren't displaying hours of operation
    $this->findLibrariesWithHours();
    $this->findLibrariesWithoutHours();
  }

  public function findAndRemoveDay($key, $hours_item)
  {
    if (isset($hours_item->field_data_field_hours_field_hours_value)) {
      $hoo_timestamp = $hours_item->field_data_field_hours_field_hours_value;
      $hoo_dateobject = new DateTime($hoo_timestamp);

      // If the first hoo item is a Saturday, kill it.
      if ($hoo_dateobject->format('m-d-y') == $this->next_sunday->format('m-d-y') ||
          $hoo_dateobject->format('m-d-y') == $this->last_saturday->format('m-d-y')) {
        unset($this->hours_array[$key]);
      }
    }
  }

  public function findLibrariesWithHours()
  {
    foreach ($this->hours_array as $key => &$hours_item) {
      $library_node_id = $hours_item->node_field_data_field_library_nid;
      $this->libraries_with_hours[] = $library_node_id;
    }

    $this->libraries_with_hours = array_unique($this->libraries_with_hours);
  }

  public function findLibrariesWithoutHours()
  {
    // Node IDs to ignore, because LDAP data is an unreliable source to know
    // all of the libraries. These libraries don't have hours, obviously, but
    // are added to this libraries_with_hours array because we use that in the
    // query below to discover library nodes not represented here.
    $this->libraries_with_hours[] = 24040; // Pattee Paterno Welcome Desk node ID
    $this->libraries_with_hours[] = 4912; // World Campus node ID
    $this->libraries_with_hours[] = 4909; // CCL node ID


    $query = new EntityFieldQuery;

    $result = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'library')
      ->fieldCondition('field_ccl', 'value', $this->is_ccl, '=') // Only UP, CCL =1
      ->propertyCondition('nid', $this->libraries_with_hours, "NOT IN")
      ->propertyCondition('status', 1, '=');

    $result = $query->execute();

    if (!empty($result['node']))
    {
      // You could use node_load_multiple() instead of entity_load() for nodes
      $missing_location_nodes = entity_load('node', array_keys($result['node']));
    }
    $this->locations_without_hours = $missing_location_nodes;
  }

  /**
   * Arranges the output of get_libraries_and_phone_numbers() into a table.
   * @param  array $nodes Libraries that don't have hours listed
   * @return string $output HTML formatted table of phone numbers
   */
  public function printLibrariesAndPhoneNumbers()
  {
    if (isset($this->locations_without_hours)) {
      $output = "<h2>Call for Hours</h2>
                <p>If the library you are looking for is not listed above, please
                call the number listed below for hours</p>
                <table>
                  <tr><th>Library</th><th>Phone Number</th></tr>";

      foreach ($this->locations_without_hours as $key => $location)
      {
        $lang = $location->language;
        if (!empty($location->field_general_phone) &&
            !empty($location->field_cn[$lang][0]['value']))
        {
          $output .= "<tr>
                        <td>
                          <a href=\"/node/{$location->nid}\">{$location->field_cn[$lang][0]['value']}</a> <br>
                        </td>
                        <td>{$location->field_general_phone[$lang][0]['value']}</td>
                      </tr>";
        }
      }
      $output .= "</table>";

      return $output;
    } else {
      return;
    }
  }

	/**
	 * Second level sorting for buildings and libraries.
	 */
	private static function patteeAndPaternoFirst($current, $next) {
		$a = array(
			'building' => $current->field_field_within_this_building[0]['rendered']['#markup'],
			'library' => $current->field_field_library[0]['rendered']['#markup'],
      'starttime' => new DateTime($current->field_data_field_hours_field_hours_value)
		);

		$b = array(
			'building' => $next->field_field_within_this_building[0]['rendered']['#markup'],
			'library' => $next->field_field_library[0]['rendered']['#markup'],
      'starttime' => new DateTime($next->field_data_field_hours_field_hours_value)
		);

		if ($a['building'] == "Pattee and Paterno" && $b['building'] == "Pattee and Paterno") {
			if ($a['library'] != $b['library']) {
				if ($a['library'] == "Pattee and Paterno" && $b['library'] != "Pattee and Paterno") {
          return -1;
        } else if ($a['library'] != "Pattee and Paterno" && $b['library'] == "Pattee and Paterno") {
          return 1;
        } else {
          return strnatcmp($a['library'], $b['library']);
        }

			} else {
	      return ($a['starttime'] < $b['starttime']) ? -1 : (($a['starttime'] > $b['starttime']) ? 1 : 0);
			}
		} else if ($a['building'] != "Pattee and Paterno" && $b['building'] == "Pattee and Paterno") {
			return 1;
		} else if ($a['building'] == "Pattee and Paterno" && $b['building'] != "Pattee and Paterno") {
			return -1;
		} else if ($a['building'] != "Pattee and Paterno" && $b['building'] != "Pattee and Paterno") {
			if ($a['library'] != $b['library']) {
				return strnatcmp($a['library'], $b['library']);
			} else {
        return ($a['starttime'] < $b['starttime']) ? -1 : (($a['starttime'] > $b['starttime']) ? 1 : 0);
			}
		}
	}

	/**
	 * Commonwealth campuses *should* be sorted alphabetically
	 */
	private static function commonwealthSort($current, $next) {
    // kpr($current);
    // exit;
		$a = array(
			'cn' => $current->field_field_cn[0]['rendered']['#markup'],
			'starttime' => new DateTime($current->field_data_field_hours_field_hours_value)
		);

		$b = array(
			'cn' => $next->field_field_cn[0]['rendered']['#markup'],
			'starttime' => new DateTime($next->field_data_field_hours_field_hours_value)
		);

		if ($a['cn'] != $b['cn']) {
			return strnatcmp($a['cn'], $b['cn']);
		} else {
			return ($a['starttime'] < $b['starttime']) ? -1 : (($a['starttime'] > $b['starttime']) ? 1 : 0);
		}
	}

}
