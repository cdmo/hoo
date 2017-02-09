<?php
if (!function_exists("_print_days")) {
  function _print_days()
  {
    $days_of_week = array('Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday',
                          'Friday', 'Saturday',);

    $today = date('l', time());
    $days_html = '<colgroup><col class="leadcol"><col class="contentcol"><col class="contentcol"><col class="contentcol"><col class="contentcol"><col class="contentcol"><col class="contentcol"><col class="contentcol"></colgroup>';
    $days_html  .= '<thead>';
    $days_html .=   '<tr>';
    $days_html .=   '<th class="hours-library">Library</th>';
    foreach ($days_of_week as $day_of_week) {
      $today_class = $today == $day_of_week ? 'class="today"' : NULL;
      $days_html .= '<th scope="col" ' . $today_class . '>';
      $days_html .= $day_of_week;
      $days_html .= '</th>';
    }
    $days_html .=   '</tr>';
    $days_html .= '</thead>';
    return $days_html;
  }
}
?>
<div class="view-grouping">
  <div class="view-grouping-header"><?php print $title; ?></div>
  <div class="view-grouping-content">

    <?php
    print "<table><caption class=\"acc-clip\">Library Hours</caption>";
    print _print_days();
    print "<tbody>";
    print $content;
    print "</tbody></table>";
    ?>
  </div>
</div>
