<?php
// $Id$
?>
<?php if ($panel_admin): ?>
<div class="container-16 clear-block">
<?php endif; ?>
<div class="panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="clear-block">
    <div class="panel-panel <?php print ns('grid-16', $content['top_left'], 3, $content['top_right'], 4) . ' ' . ns('push-3', !$content['top_left'], 3); ?>">
      <div class="inside"><?php print $content['top_main']; ?></div>
    </div>
    <?php if ($content['top_left']): ?>
    <div class="panel-panel grid-3 <?php print ns('pull-13', $content['top_right'], 4); ?>">
      <div class="inside"><?php print $content['top_left']; ?></div>
    </div>
    <?php endif; ?>
    <?php if ($content['top_right']): ?>
    <div class="panel-panel grid-4">
      <div class="inside"><?php print $content['top_right']; ?></div>
    </div>
    <?php endif; ?>
  </div>

  <?php // TODO: make the bottom part flexible as well... ?>
  <?php if (!$panel_admin && ($content['bottom_left'] || $content['bottom_main'] || $content['bottom_right'])): ?>
  <hr class="panel-separator" />
  <?php endif; ?>
  <div class="clear-block">
    <div class="panel-panel grid-3">
      <div class="inside"><?php print $content['bottom_left']; ?></div>
    </div>
    <div class="panel-panel grid-7">
      <div class="inside"><?php print $content['bottom_main']; ?></div>
    </div>
    <div class="panel-panel grid-6">
      <div class="inside"><?php print $content['bottom_right']; ?></div>
    </div>
  </div>
</div>
<?php if ($panel_admin): ?>
</div>
<?php endif; ?>
