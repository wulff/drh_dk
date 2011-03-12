<?php
// $Id: views_handler_field_primary_term_tid.inc,v 1.1.2.1 2010/10/13 18:20:52 brianV Exp $

/**
 * @file
 * Provide a views handlers for primary_term data fields.
 */

class views_handler_field_primary_term_tid extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_taxonomy'] = array('default' => TRUE);
    return $options;
  }

  /**
   * Provide "link to term" option.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_to_taxonomy'] = array(
      '#title' => t('Link this field to its term page'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_taxonomy']),
    );
  }

  function render($values) {
    $tid = $values->{$this->field_alias};
    $term = taxonomy_get_term($tid);

    if (!$term) {
      return;
    }

    if ($this->options['link_to_taxonomy']) {
      return l($term->name, taxonomy_term_path($term));
    }
    else {
      return check_plain($term->name);
    }
  }
}