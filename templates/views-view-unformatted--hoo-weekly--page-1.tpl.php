<?php
  /**
   * @file
   * format the content table cells, CCL
   */
  // Need to rekey so that modulo calcs can inform the table cell class
  $rows = array_values($rows);
?>

  <tr>

    <?php foreach ($rows as $id => $row): ?>

      <?php
        // Adding a class to highlight today's hours
        $today_class  = $id % 7 == date('w', time()) ? "todays-hours" : "not-today";
        print "<td class=\"{$today_class}\">{$row}</td>";
      ?>

    <?php endforeach; ?>
  </tr>
