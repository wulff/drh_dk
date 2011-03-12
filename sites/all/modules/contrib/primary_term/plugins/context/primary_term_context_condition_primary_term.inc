<?php
// $Id: primary_term_context_condition_primary_term.inc,v 1.1.2.1 2010/10/13 17:56:04 brianV Exp $

class primary_term_context_condition_primary_term extends context_condition_node {
  function condition_values() {
    $values = array();
    if (module_exists('taxonomy')) {
      foreach (taxonomy_get_vocabularies() as $vocab) {
        if (empty($vocab->tags)) {
          foreach (taxonomy_get_tree($vocab->vid) as $term) {
            $values[$term->tid] = $term->name;
          }
        }
      }
    }
    return $values;
  }

  function condition_form($context) {
    $form = parent::condition_form($context);
    $form['#type'] = 'select';
    $form['#options'] = taxonomy_form_all();
    $form['#size'] = 12;
    $form['#multiple'] = TRUE;
    return $form;
  }

  function execute($node, $op) {
    $map = context_condition_map();
    if (!empty($map['primary_term']) && $node->primary_term->tid) {
      foreach ($this->get_contexts($node->primary_term->tid) as $context) {
        $this->condition_met($context, $node->primary_term->tid);
      }
    }
  }
}
?>
