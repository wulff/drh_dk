<?php
// $Id: nodereference_explorer.widget.inc,v 1.8 2010/07/19 15:42:14 gnindl Exp $
/**
 * @file
 * nodereferene_explorer.widget.inc
 * Widget hooks are placed here. This is the heart class of the module, as it builds on
 * top of the autocomplete widget. It add two buttons (browse and remove). The browse
 * button pops up an interactive dialog. All selected values are written to the autocomplete
 * widget.
 */

/**
 * Implementation of hook_widget_info().
 *
 * Adds the widget type explorer to the specified field types. The design is generic, i. e.
 * you should be able to plug the explorer on any field type you like. This requires some
 * configuration in form of nodereference explorer plugins (see plugins subfolder for details)
 * @return array
 *   widget types assigned to field types
 */
function nodereference_explorer_widget_info() {
  return array(
    'nodereference_explorer' => array(
      'label' => t('Explorer'),
      'field types' => 
        // Formerly nodereference_explorer_plugins() function was called here, 
        // but it has been deprecated, see function description for details.
        // Therefore we define the plugin field types here explicitly.
        array('link', 'nodereference', 'nodereference_quantifier'),
    ),
  );
}

/**
 * Implementation of hook_widget().
 *
 * This method attaches a single form element to the form. It will be
 * built out and validated in the callback(s) listed in hook_elements.
 * We build it out in the callbacks rather than here in hook_widget so
 * it can be plugged into any module that can provide it with valid
 * $field information.
 *
 * Content module will set the weight, field name and delta values
 * for each form element. This is a change from earlier CCK versions
 * where the widget managed its own multiple values.
 *
 * If there are multiple values for this field, the content module will
 * call this function as many times as needed.
 *
 * @param $form
 *   the entire form array, $form['#node'] holds node information
 * @param $form_state
 *   the form_state, $form_state['values'][$field['field_name']]
 *   holds the field's form values.
 * @param $field
 *   the field array
 * @param $items
 *   array of default values for this field
 * @param $delta
 *   the order of this item in the array of subelements (0, 1, 2, etc)
 *
 * @return
 *   the form item for a single element for this field
 */
function nodereference_explorer_widget(&$form, &$form_state, $field, $items, $delta = 0) {
  switch ($field['widget']['type']) {
    case NODE_REFERENCE_EXPLORER_MODULE_NAME:
      $element = array( //core widget, e. g. autocomplete
        '#type' => NODE_REFERENCE_EXPLORER_MODULE_NAME,
        '#default_value' => isset($items[$delta]) ? $items[$delta] : NULL,
        '#plugin' => nodereference_explorer_plugins_load_plugin($field['type']), //load field type plugin for noderef explorer
      );
      $element['#value_callback'] = isset($element['#plugin']->value_callback) ? $element['#plugin']->value_callback: NULL;  
    break;
  }
  return $element;
}

/**
 * Proceses a single form element here.
 * @param $element
 *   form widget
 * @param $edit
 * @param $form_state
 *   the form_state, $form_state['values'][$field['field_name']] holds the field's form values.
 * @param $form
 *   the entire form array, $form['#node'] holds node information
 * @return $element
 *   widget including javascript
 */
function nodereference_explorer_widget_process($element, $edit, $form_state, $form) {

  $field = content_fields($element['#field_name'], $element['#type_name']); //get CCK field
  if ($field) {
    nodereference_explorer_widget_attach_dialog_css_and_js($field);
  
    // validate and preview function might destroy the plugin object
    if ($element['#plugin'] instanceof __PHP_Incomplete_Class) { //create new plugin object if destroyed
  	  $element['#plugin'] = nodereference_explorer_plugins_load_plugin($field['type']);
  	  $element['#value_callback'] = isset($element['#plugin']->value_callback) ? $element['#plugin']->value_callback: NULL;
    }
  
    //call parent widget process function, provided by plugin (depends on CCK type)
    $element = $element['#plugin']->widget_process($element, $edit, $form_state, $form); 
    
    //add js settings per field only once, preventing multiple settings holds same values
    //this is compatible with the "add more" behavior
    static $added_settings;

    $field_name = $field['field_name'];
    $type_name = $field['type_name'];
    
    if (!isset($added_settings[$field_name])) { //add only if they haven't been previously added
      nodereference_explorer_include('nodereference_explorer.util');
      $field_settings = array(
        'dialog' => nodereference_explorer_util_parse_settings($field, 'dialog'),  // Dialog window settings
        'field_type' => $field['type'],
        'browse' => url(NODE_REFERENCE_EXPLORER_MENU_CALLBACK_BROWSE .'/' . $field['widget']['dialog_api'] .'/'. $type_name .'/'. $field_name),
        'preview' => url(NODE_REFERENCE_EXPLORER_MENU_CALLBACK_PREVIEW .'/'. $type_name .'/'. $field_name),
      );

      // Issue #1845784: Get organic groups context for create URL
      if (module_exists('og') && function_exists('og_get_group_context')) {
        $field_settings['create'] = url(NODE_REFERENCE_EXPLORER_MENU_CALLBACK_CREATE .'/' . $field['widget']['dialog_api'] .'/'. $type_name .'/'. $field_name, array ('query' => 'gids[]=' . og_get_group_context()-> nid ));
      }
      else {
        $field_settings['create'] = url(NODE_REFERENCE_EXPLORER_MENU_CALLBACK_CREATE .'/' . $field['widget']['dialog_api'] .'/'. $type_name .'/'. $field_name);
      }
            
      $setting[NODE_REFERENCE_EXPLORER_MODULE_NAME] = array(
        $field_name => $field_settings,
      );
      drupal_add_js($setting, 'setting'); //add settings
      $added_settings[$field_name] = $field_settings; //cache field specific js settings
    } 
       
    // determine if create button should be shown (widget option), only supported for modalframe yet
    $show_create_button = $field['widget']['dialog_api'] == 'modalframe' && $field['widget']['create_ref'];
    
   
    //add actions, e. g. browse and remove, to the core widget
    $components = nodereference_explorer_widget_attach_actions($element, $show_create_button);

    //add a preview if enabled (by the content type admin/editor)
    if (!empty($field['widget']['content_preview']) && $field['widget']['content_preview'] != '--') {
      $preview_weight = $field['widget']['content_preview_position'] == 'below' ?  10 : -10;
      $preview_id = nodereference_explorer_widget_preview($element, $field, $preview_weight);
      $components[] = $preview_id; //add preview to components
    }

    //add subwidget js settings per instance, but prevent multiple settings holding same values
    static $added_comps;

    if (!is_array($added_comps[$field_name]['components'])) //initiate array first time
      $added_comps[$field_name]['components'] = array();

    //search the static array: checking for the first item should be sufficient
    $key = array_search($components[0], $added_comps[$field_name]['components']);

    if (is_bool($key) && $key == FALSE) { //if componenents have not yet been added
      $widget_id = _nodereference_explorer_widget_generate_id($element);
      $setting[NODE_REFERENCE_EXPLORER_MODULE_NAME] = array(
        $field_name => array(
          'widgets' => array(
            $widget_id => $components,
      	  ),
        ),
      );
      drupal_add_js($setting, 'setting');
      $added_comps[$field_name]['components'] = array_merge($added_comps[$field_name]['components'], $components); //store added component settings
    }

    //add popups & reference for each item
    if (module_exists('popups_reference') && module_exists('popups'))
      _nodereference_explorer_widget_add_popups_references($element, $field);

    return $element;
  }
}

/**
 * Attach CSS and JS to the widget which are specific to the Dialog API.
 * @param $field
 *   CCK content field
 */
function nodereference_explorer_widget_attach_dialog_css_and_js($field) {
  //load JS reponsible for dialog API
  switch ($field['widget']['dialog_api']) {
  	case 'modalframe': //parent window
  	  modalframe_parent_js();
      nodereference_explorer_add_js('explorer.modalframe');
      break;
    case NODE_REFERENCE_EXPLORER_MODULE_NAME:
    default:
      nodereference_explorer_add_js('explorer.dialog');
      nodereference_explorer_include('nodereference_explorer.util');
      nodereference_explorer_util_explorer_js($field);
  }
}

/**
 * Actions are attached to the core widget form element,
 * f. e. open content browser or remove selected value. The
 * necessary JS settings for the actions are added as well.
 * @param $element
 * 	parent widget, e. g. autocomplete
 * @param field
 *  CCK field
 * @return
 *   array of action ids
 */
function nodereference_explorer_widget_attach_actions(&$element, $show_create_button = TRUE) {

  //wrapper for actions bar
  $element['actions']['#prefix'] = '<div class="form-item nodereference-explorer-actions">' . $element['actions']['#prefix'];
  $element['actions']['#suffix'] = '</div>';
  $element['actions']['#weight'] = 5;
  
  //Button ids
  $add_button_id = $element['#id'] . '-button-add';
  $browse_button_id = $element['#id'] . '-button-browse';
  $remove_button_id = $element['#id'] . '-button-remove';
  
  $element['actions']['browse'] = array(
    '#type' => 'button',
    '#button_type' => 'button',
    '#id' => $browse_button_id,
    '#attributes' => array('class' => 'nodereference-explorer-action-open-dialog nodereference-explorer-button'),
    '#value' => t('Browse'),
  );
  
  if ($show_create_button) {
    //create buttons as form elements
    $element['actions']['create'] = array(
      '#type' => 'button',
      '#button_type' => 'button',
      '#id' => $add_button_id,
      '#attributes' => array('class' => 'nodereference-explorer-action-add-dialog nodereference-explorer-button'),
      '#value' => t('Create'),
    );
  }

  $element['actions']['remove'] = array(
    '#type' => 'button',
    '#button_type' => 'button',
    '#id' => $remove_button_id,
    '#value' => t('Remove'),
    '#attributes' => array('class' => 'nodereference-explorer-action-remove-value nodereference-explorer-button'),
  );
  
  nodereference_explorer_add_css('explorer.form'); //theme for core widget (autocomplete)
  views_add_css('views'); //CSS for progress throbbing, exposed filter layout and misc views stuff...

  nodereference_explorer_add_js('explorer.actions'); //base action script for browse and remove
  
  return array($add_button_id, $browse_button_id, $remove_button_id);
}

/**
 * Default preview on selected view items. Actually
 * an item of a referenced view display is shown
 * @param $element
 *   form element
 * @param $field
 *   CCK field
 * @param $preview_weight
 *   number form position
 * @return
 *   id of the preview area
 */
function nodereference_explorer_widget_preview(&$element, $field, $preview_weight) {

  $element['preview'] = array(
    '#type' => 'markup',
    '#weight' => $preview_weight,
  );

  $preview_id = $element['#id'] .'-preview'; // HTML id
  // wrapper
  $prefix = '<div id="'. $preview_id .'" class="nodereference-explorer-preview">';
  $suffix = '</div>';

 // The NRE plugins and their super class are responsible for providing the node id.
 // See class nodereference_explorer_plugin_content function widget_process and subclasses
 if ($element['#default_value']['nid']) { // load preview if node is provided
    nodereference_explorer_include('nodereference_explorer.views.class');
    $handler = new nodereference_explorer_views($field);
    // valdation hook encapsulates nid further
    $nid = is_array($element['#default_value']['nid']) ? $element['#default_value']['nid']['nid'] : $element['#default_value']['nid'];
   
    $output = '';
    if ($nid) {
      $output = $handler->get_item($element['#default_value']['nid']); // generates HTML preview
    }
    // wrap output, sometimes #prefix and #suffix might not render, 
    // that's why we put everthing into #value
    $element['preview']['#value'] = $prefix . $output . $suffix;
  }
  else { //add an empty placeholder for the preview
    $element['preview']['#value'] = $prefix . $suffix;
  }
   
  nodereference_explorer_add_js('explorer.preview'); //preview behavior js
  return $preview_id;
}

/**
 * Computes a widget id for each item.
 * @param $element
 *   from element
 * @return
 *   generic node widget id
 */
function _nodereference_explorer_widget_generate_id($element) {
  $widget_id = $element['#id']; //generic actions, dialog can be used by third party modules, e. g. link
  if (isset($element['nid'])) { //native actions
    $widget_id .= '-nid-nid';
  }
  return $widget_id;
}

/**
 * Adds popups references to the widget if enabled
 * Copied and adapted from popups_reference_alter_item()
 */
function _nodereference_explorer_widget_add_popups_references(&$element, $field) {
  if (variable_get('popups_reference_show_add_link_'. $element['#field_name'], FALSE)) {
    $wrapper_id = 'popups-reference-' . _popups_reference_counter();
    $links = _popups_reference_links($field, 'nodereference_explorer', $wrapper_id, 'nodereference_autocomplete');
    if ($links) {
      // Put the nodereference widget and links in an wrapper.
      // Makes it easy to find for Ahah targeting, and popups_reference behavior selecting.
      $element['#prefix'] .= '<div class="'. $wrapper_id .'">';
      $element['#suffix'] .= '<div>Add New: ' . implode(', ', $links) .'</div></div>';
    }
  }
}