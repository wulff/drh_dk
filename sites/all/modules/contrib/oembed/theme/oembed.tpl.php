<?php
// $Id: oembed.tpl.php,v 1.1 2010/02/21 12:12:35 voxpelli Exp $
/**
 * @file
 * Default template file for oembed data
 */
?>
<?php print l($title, $original_url, array('absolute' => TRUE, 'attributes' => array('class' => 'oembed-title oembed-link')));