<?php
// $Id: oembed-photo.tpl.php,v 1.1 2010/02/21 12:12:35 voxpelli Exp $
/**
 * @file
 * Default template file for oembed data of the photo type
 */
?>
<div class="oembed">
  <?php if (!empty($title)): ?>
    <?php print l($title, $original_url, array('absolute' => TRUE, 'attributes' => array('class' => 'oembed-title'))); ?>
  <?php endif; ?>
  <?php print l(theme('image', $embed->url, '', '', NULL, FALSE), $original_url, array('html' => TRUE, 'absolute' => TRUE, 'attributes' => array('class' => 'oembed-photo oembed-content'))); ?>
</div>
