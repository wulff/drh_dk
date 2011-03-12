<?php
// $Id$
?>
<?php if ($panel_admin): ?>
<div class="container-16 clear-block">
<?php endif; ?>
<div class="panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="clear-block">
  <?php if ($content['top_left_1'] || $content['top_left_2']): ?>
  <div class="panel-panel <?php print ns('grid-16', $content['top_right'], 8); ?>">
    <div class="inside"><?php print $content['top_left_1']; ?></div>
    <div class="inside"><?php print $content['top_left_2']; ?></div>
  </div>
  <?php endif; ?>
  <?php if ($content['top_right']): ?>
  <div class="panel-panel <?php print ns('grid-16', ($content['top_left_1'] || $content['top_left_2']), 8); ?>">
    <div class="inside"><?php print $content['top_right']; ?></div>
  </div>
  <?php endif; ?>
  </div>

  <div class="clear-block teasers">
  <?php if ($content['teaser_1'] || $content['teaser_2'] || $content['teaser_3'] || $content['teaser_4']): ?>
  <div class="panel-panel grid-4 teaser">
    <div class="inside"><?php print $content['teaser_1']; ?></div>
  </div>
  <div class="panel-panel grid-4 teaser">
    <div class="inside"><?php print $content['teaser_2']; ?></div>
  </div>
  <div class="panel-panel grid-4 teaser">
    <div class="inside"><?php print $content['teaser_3']; ?></div>
  </div>
  <div class="panel-panel grid-4 teaser">
    <div class="inside"><?php print $content['teaser_4']; ?></div>
  </div>
  <?php endif; ?>
  </div>

  <div class="clear-block images">
  <?php if ($content['bottom']): ?>
  <div class="panel-panel grid-16">
    <div class="inside"><?php print $content['bottom']; ?></div>
  </div>
  <?php endif; ?>
  </div>
</div>
<?php if ($panel_admin): ?>
</div>
<?php endif; ?>
