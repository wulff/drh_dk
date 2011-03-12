<?php
// $Id: views_tagger.views.inc,v 1.1.2.1 2009/11/27 13:15:02 wulff Exp $

/**
 * @file
 * Views plugin definition.
 */

function views_tagger_views_plugins() {
  return array(
    'style' => array(
      'tagger' => array(
        'title' => t('Tagger'),
        'help' => t('Quickly assign taxonomy terms to nodes in a view.'),
        'handler' => 'views_tagger_plugin_style',
        'parent' => 'table',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'theme' => 'views_view_tagger',
      ),
    ),
  );
}
