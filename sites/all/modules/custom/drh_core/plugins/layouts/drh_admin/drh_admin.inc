<?php
// $Id$

/**
 * Implementation of hook_panels_layouts().
 */
function drh_core_drh_admin_panels_layouts() {
  $items['drh_admin'] = array(
    'title' => t('DRH: Admin page'),
    'icon' => 'drh_admin.png',
    'theme' => 'drh_admin',
    'panels' => array(
      'left' => t('Left'),
      'right' => t('Right'),
    ),
  );

  return $items;
}
