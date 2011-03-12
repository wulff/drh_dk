<?php
// $Id$

/**
 * Implementation of hook_panels_layouts().
 */
function drh_core_drh_frontpage_panels_layouts() {
  $items['drh_frontpage'] = array(
    'title' => t('DRH: Frontpage'),
    'icon' => 'drh_frontpage.png',
    'theme' => 'drh_frontpage',
    'panels' => array(
      'top_left_1' => t('Top left 1'),
      'top_left_2' => t('Top left 2'),
      'top_right' => t('Top right'),
      'teaser_1' => t('Teaser 1'),
      'teaser_2' => t('Teaser 2'),
      'teaser_3' => t('Teaser 3'),
      'teaser_4' => t('Teaser 4'),
      'bottom' => t('Bottom'),
    ),
  );

  return $items;
}
