<?php
// $Id: primary_term_from_node.inc,v 1.1.2.1 2010/10/13 17:39:56 brianV Exp $

/**
 * @file
 * Plugin to provide an relationship handler for the primary term from node.
 * Based on CTools' term_from_node relationship
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Primary term from node'),
  'keyword' => 'primary_term',
  'description' => t('Adds the primary term from a node context'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'context' => 'primary_term_from_node_context',
);

/**
 * Return a new context based on an existing context.
 */
function primary_term_from_node_context($context, $conf) {
  // If unset it wants a generic, unfilled context, which is just NULL.
  if (empty($context->data)) {
    return ctools_context_create_empty('term', NULL);
  }

  if (isset($context->data->primary_term)) {
    return ctools_context_create('term', $context->data->primary_term);
  }
  else {
    return ctools_context_create_empty('term', NULL);
  }
}
