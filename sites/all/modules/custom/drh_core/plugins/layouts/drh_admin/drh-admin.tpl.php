<?php
// $Id$
?>
<div class="panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-panel <?php print ns('grid-16', $content['right'], 4); ?>">
    <div class="inside"><?php print $content['left']; ?></div>
  </div>
  <?php if ($content['right']): ?>
  <div class="panel-panel grid-4">
    <div class="inside"><?php print $content['right']; ?></div>
  </div>
  <?php endif; ?>
</div>
