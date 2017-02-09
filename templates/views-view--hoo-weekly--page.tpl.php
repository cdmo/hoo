<?php

/**
 * @file
 * UP
 */

/**
 * A tiny little helper function to further game this template file into adding
 * a class to a day column header so that we can highlight today's hours for
 * patrons
 *
 * @return string      HTML to be printed to the page
 */
$week_of  = date('F jS', strtotime('last Saturday + 24 hour'));
$day_of   = date('F jS', time());
?>
  <?php print '<p class="week-of">For the week of ' . $week_of . '</p>'; ?>
  <?php print '<p class="day-of">For today, ' . $day_of . '</p>'; ?>
  <a class="button tiny nomargin" href="/hours-and-locations">University Park</a>
  <a class="button tiny nomargin inactive" href="/ccl-hours-and-locations">Commonwealth Campuses</a>
<div class="<?php print $classes; ?>">


  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>
  <?php if ($rows): ?>

        <?php print $rows; ?>

  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
