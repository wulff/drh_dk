<?php
// $Id: views_tagger_plugin_style.inc,v 1.1.2.2 2009/11/27 13:15:02 wulff Exp $

/**
 * @file
 * Custom plugin style for views.
 */

class views_tagger_plugin_style extends views_plugin_style_table {
  function options(&$options) {
    parent::options($options);
    $options['vocabularies'] = array();
  }

  function options_form(&$form, &$form_values) {
    parent::options_form($form, $form_values);

    $vocabularies = taxonomy_get_vocabularies();

    $options = array();
    foreach ($vocabularies as $vocabulary) {
      $options[$vocabulary->vid] = $vocabulary->name;
    }

    $form['vocabularies'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Vocabularies'),
      '#description' => t('Select the vocabularies you wish to edit in this view. If you leave all the boxes unchecked, all the vocabularies will be included in the view.'),
      '#default_value' => $this->options['vocabularies'],
      '#options' => $options,
    );
  }

  function render() {
    $sets = $this->render_grouping($this->view->result, $this->options['grouping']);
    $this->sets = $sets;

    static $form_suffix;
    if (isset($form_suffix)) {
      $form_suffix++;
    }
    else {
      $form_suffix = 1;
    }

    return drupal_get_form('views_tagger_form__' . $form_suffix, $this);
  }

  function uses_fields() {
    if (isset($this->view->ignore_fields)) {
      return FALSE;
    }
    return parent::uses_fields();
  }
}
