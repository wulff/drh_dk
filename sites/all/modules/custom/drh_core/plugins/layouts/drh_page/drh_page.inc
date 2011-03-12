<?php
// $Id$

/**
 * Implementation of hook_panels_layouts().
 */
function drh_core_drh_page_panels_layouts() {
  $items['drh_page'] = array(
    'title' => t('DRH: Default page'),
    'icon' => 'drh_page.png',
    'theme' => 'drh_page',
    'panels' => array(
      'top_left' => t('Top left'),
      'top_main' => t('Top main'),
      'top_right' => t('Top right'),
      'bottom_left' => t('Bottom left'),
      'bottom_main' => t('Bottom main'),
      'bottom_right' => t('Bottom right'),
    ),
  );

  return $items;
}
