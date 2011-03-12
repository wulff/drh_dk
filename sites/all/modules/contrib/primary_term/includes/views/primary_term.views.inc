<?php
// $Id: primary_term.views.inc,v 1.1.2.3 2010/10/13 19:55:36 brianV Exp $

/**
 * @file
 * Views data for primary_term.
 */

function primary_term_views_handlers() {
  return array(
    'info' => array(
        'path' => drupal_get_path('module', 'primary_term') . '/includes/views',
    ),
    'handlers' => array(
      'views_handler_field_primary_term_tid' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */
function primary_term_views_data() {
  $data['primary_term']['table']['group'] = t('Node');
  $data['primary_term']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
    // @@@ Node_revisions?
  );

  $data['primary_term']['tid'] = array(
    'title' => t('Primary Term: Term ID'),
    'help' => t('The Primary Term TID of the node.'),
    'field' => array(
      'handler' => 'views_handler_field_primary_term_tid',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_term_node_tid',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_term_node_tid',
    ),
  );

  return $data;
}
