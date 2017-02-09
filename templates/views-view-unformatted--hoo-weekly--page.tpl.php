<?php
  /**
   * @file
   * format the content table cells, UP
   */
  // Need to rekey so that modulo calcs can inform the table cell class
  $rows = array_values($rows);
?>

  <tr>
    <td class="hours-library">
      <?php if (!empty($title)): ?>
      <p><?php print $title; ?></p>
      <?php endif; ?>
    </td>

    <?php foreach ($rows as $id => $row): ?>

      <?php
        // Adding a class to highlight today's hours
        $today_class  = $id % 7 == date('w', time()) ? "todays-hours" : "not-today";
        print "<td class=\"{$today_class}\">{$row}</td>";
      ?>

    <?php endforeach; ?>
  </tr>
