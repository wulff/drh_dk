<?php
/**
 * @file nodereference_explorer_plugin_content.inc
 * Nodereference Explorer plugins care about the different handling of CCK field types.
 * They provide a bunch of object methods which hook into the rendering process of
 * the widget.
 *
 * Child classes must inherit the methods provided here.
 */
abstract class nodereference_explorer_plugin_content {

  public $value_callback = NULL; //define callback function for the widget value
 
  /**
   * The parent widget to which actions and preview is assigned, e. g. autocomplete widget.
   * @param $element
   * @param $edit
   * @param $form_state
   * @param $form
   * @return
   *   array form element
   */
  public function widget_process($element, $edit, $form_state, $form) {
    // Clicking the "Add another item" button triggers a POST request with the current widget values.
    // If that is the case we have to reset the widget values for further processing, e. g. preview.
    $field_name = $element['#field_name'];
    $weight = $element['#delta'];
    // The add more button AJAX call might put the post values into the $element array. We look at this
    // data structure first, before we look up the global $_POST array. As values might be overridden
    // in both arrays, the $_POST array can be manipualted by any PHP code whereas the $element array
    // can only be changed by CCK and dependent modules.
    if($element['#post'][$field_name][$weight]) { 
	   $element['#default_value'] = $element['#post'][$field_name][$weight];
    }
    elseif($_POST[$field_name][$weight]) {
	   $element['#default_value'] = $_POST[$field_name][$weight];
    }
    return $element;
  }

  /**
   * Extended rendering function for parent widget.
   * @param $element
   */
  public abstract function theme_nodereference_explorer($element);

  /**
   * Additional widget settings form elements.
   * @param $widget
   */
  public abstract function widget_settings_form($widget);

  /**
   * Additional widget settings validation.
   * @param $widget
   */
  public abstract function widget_settings_validate($widget);

  /**
   * Additional widget settings save fields.
   * @param $widget
   */
  public abstract function widget_settings_save($widget);

}