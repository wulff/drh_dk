<?php
// $Id: nodereference_explorer.menu.inc,v 1.10 2010/12/06 10:38:10 gnindl Exp $
/**
 * @file
 * nodereference_explorer.menu.inc
 * File containing all menu call backs of the module.
 */

/**
 * Common dialog theme layer for browse functionality.
 * @param $dialog_api
 *   string identifying dialog API
 * @param $type_name
 *   string node type
 * @param $field_name
 *   string CCK field name
 * @param $title
 *   string dialog selection title
 */
function nodereference_explorer_browse($dialog_api, $type_name, $field_name, $title = '') {
  switch ($dialog_api) {
    case 'modalframe':
      return nodereference_explorer_browse_modalframe($type_name, $field_name, $title);
    default:
      nodereference_explorer_browse_builtin($type_name, $field_name, $title);
      break;
  }
}

/**
 * Dialog theme layer for built-in dialog API.
 * A dialog template is applied which is filled by field and widget
 * settings of a CCK field. Third party CCK fields can hook in here
 * and override/supply custom settings.
 * Necessary JS and CSS files are included in the JSON repsone as well.
 * @param $type_name
 * @param $field_name
 * @param $title
 * @return
 *  json string output of dialog html, as well as js and css references
 */
function nodereference_explorer_browse_builtin($type_name, $field_name, $title = '') {
  
  // retrieve field by name
  $field = content_fields($field_name, $type_name);
  
  // a CCK field is manadatory, return if nothing present
  if (!$field)
    return '';  
    
  // JSON array to be return message 
  $ret_msg = array('status' => TRUE);

  /* TODO the scripts array contains additional settings and scripts that
   * ideally could inform some process of loading and setting those things.
   * instead, we're calling views_add_js('ajax_view') with the element..
   * $scripts = drupal_add_js(NULL);
   */
  nodereference_explorer_include('nodereference_explorer.util');
  $ret_msg['js'] = nodereference_explorer_util_get_js();
   
  // settings needed by javascript, i. e. explorer.actions.js
  $dialog = nodereference_explorer_util_parse_settings($field, 'dialog');
  $ret_msg['js']['setting']['dialog'] = $dialog;
  
  // button labels for dialog
  $ret_msg['js']['setting']['actions'] = nodereference_explorer_get_overlay_actions();

  // dynamically loaded css files
  $ret_msg['css'] = nodereference_explorer_util_get_css();
  // render dialog
  $output = nodereference_explorer_get_overlay_content($field, $title);
  $ret_msg['data'] = $output;
 
  drupal_json($ret_msg);
}

/**
 * Dialog theme layer for modalframe api.
 * @param $type_name
 * @param $field_name
 */
function nodereference_explorer_browse_modalframe($type_name, $field_name, $title = '') {
	
  //retrieve field by name
  $field = content_fields($field_name, $type_name);
  
  nodereference_explorer_include('nodereference_explorer.util');
  nodereference_explorer_util_explorer_js($field); //common content js
  nodereference_explorer_add_css('explorer.modalframe');
  
  modalframe_child_js(); //window content javascript
  
  $output = nodereference_explorer_get_overlay_content($field);
  
  //add submit buttons of a form outside the dialog, avoiding nested forms when
  //using exposed filters. It would lead to incompatiblity with IE.
  return $output . drupal_get_form('nodereference_explorer_modalframe_form', $title, nodereference_explorer_get_overlay_actions()); //form of internal area
}

/**
 * Content of the modalframe dialog
 * @param $form_state
 * @param $dialog
 * @param $title
 * @return
 *   a form
 */
function nodereference_explorer_modalframe_form($form_state, $title, $actions) {
  $form['selection'] = array(
    '#type' => 'hidden',
    '#default_value' => $title,
  );
  
  foreach ($actions as $key => $action) {
  	$form[$key] = array(
  	  '#type' => 'submit',
  	  '#value' => $action,	
  	);
  }
  return $form;
}

/**
 * Modalframe form submit, i. e. confirmation of the selection
 * @param $form
 * @param $form_state
 */
function nodereference_explorer_modalframe_form_submit($form, $form_state) {
  if ($form_state['clicked_button']['#id'] == 'edit-ok') {
    $form_state['values']['selection'] = urldecode($form_state['values']['selection']);
    modalframe_close_dialog($form_state['values']); //modalframe is closed
  }
  else {
  	modalframe_close_dialog(); //do not store any selection on abort
  }
}

/**
 * Dialog content containing view displays, filters and tabs.
 * @param $field
 *   CCK content field
 * @param $title
 *   selection value
 * @return
 *   Rendered dialog content (HTML)
 */
function nodereference_explorer_get_overlay_content($field, $title = '') {
  //parse dialog settings
  nodereference_explorer_include('nodereference_explorer.util');
  $dialog = nodereference_explorer_util_parse_settings($field, 'dialog');  

  //fill template for dialog content
  nodereference_explorer_include('nodereference_explorer.views.class');
  $handler = new nodereference_explorer_views($field);
  $handler->set_selection($title);
  $filters = array();
  $dialog_displays = count($dialog['displays']) ? array_intersect_key($handler->get_all_displays(), $dialog['displays']) : $handler->get_all_displays();
  foreach ($dialog_displays as $display) {
  	//Render tabs links manually, as their behavior will be defined by jQuery tabs on the client side.
  	//Usage of the l() functions leads to problems as HTTP requests are triggered, e. g.
  	//$tabs[$display->id] = l($display->display_title, $_GET['q'], array('fragment' => $display->id));
    $tabs[$display->id] = "<a href=\"#$display->id\">$display->display_title</a>";
    
    //display filters only separately if they are exposed in a block
    $handler->view->set_display($display->id);
    if ($handler->view->display_handler->get_option('exposed_block'))
      $filters[$display->id] = $handler->get_exposed_form($display->id);
    $displays[$display->id] = $handler->get_display($display->id);
  }
  return theme('nodereference_explorer_dialog', $dialog['title'], $tabs, $filters, $displays);
}

/**
 * Buttons/actions for the dialog
 * @return
 *   array of action labels
 */
function nodereference_explorer_get_overlay_actions() {
 //button labels for dialog
  $actions = array();
  $actions['ok'] = t('OK');
  $actions['cancel'] = t('Cancel');
  return $actions;
}



/**
 * The "Add/Create and reference" page is built here. If there's more than one referenceable content type
 * a limited node type list is shown, like in /node/add/list. If there's only one or the node type is specified
 * explicitly the corresponding node edit form is shown. This implementation is more or less a copy of 
 * noderelationships_noderef_page_create().
 * @param $type_name
 *   string of referred content type
 * @param $field_name
 *   string of CCK field name
 * @param $new_type
 *   string of node type, directly linking to node edit form
 * @return
 *   Either a node type list is return or the request is forwarded directly to the node edit form
 */
function nodereference_explorer_create_node($dialog_api, $type_name, $field_name, $new_type = NULL) {

  // support only with modalframe yet
  if (module_exists('modalframe')) {
    // Enable the Modal Frame API for the child window.
    modalframe_child_js();
  }
    
  // Try to load information about the requested nodereference field.
  $field = (isset($field_name) && isset($type_name) ? content_fields($field_name, $type_name) : NULL);
  if (empty($field)) {
    drupal_not_found();
    return;
  }
 
  // Build the list of content types related to the given parent node type,
  // and nodereference field, that can be created by the current user.
  nodereference_explorer_include('nodereference_explorer.util');
  $creatable_types = array_filter($field['referenceable_types'], 'nodereference_explorer_util_is_not_zero');
  // filter types further by user "create content types" permission
  foreach ($creatable_types as $id => $creatable_type) {
  	if (!node_access('create', $creatable_type)) {
  	  unset($creatable_types[$id]);
  	} 
  }
  
  // Do we know the content type the user wants to create?
  if (empty($new_type)) {
    // Display the list of content types that can be referred from the
    // given field in the current parent content type.
    $node_add_list = array();
    foreach ($creatable_types as $new_type) {
      $translated_menuitem = menu_get_item('node/add/'. str_replace('_', '-', $new_type));
      if (!empty($translated_menuitem)) {
        $translated_menuitem['href'] = NODE_REFERENCE_EXPLORER_MENU_CALLBACK_CREATE . '/'. $dialog_api . '/' . $type_name .'/'. $field_name .'/'. $new_type;
        $translated_menuitem['localized_options']['attributes'] = array('class' => 'modalframe-exclude');
        $query = drupal_query_string_encode($_GET, array_merge(array('q', 'destination', 'pass', 'translation', 'language'), array_keys($_COOKIE)));
        if (!empty($query)) {
          $translated_menuitem['localized_options']['query'] = $query;
        }
      $node_add_list[] = $translated_menuitem;
      }   
    }
    // Only display the content type selection screen if more than one
    // type is available.
    if (count($node_add_list) > 1) {
      return theme('node_add_list', $node_add_list);
    }
  }

  // And now? Do we know the content type the user wants to create?
  if (!empty($new_type)) {
    // Let's try to redirect to a regular node/add form for the specified type.
    if (isset($creatable_types[$new_type])) {
      $_GET['nodereference_explorer_node_type'] = $type_name;
      $_GET['nodereference_explorer_field_name'] = $field_name;
      $query = drupal_query_string_encode($_GET, array('q'));
      unset($_REQUEST['destination'], $_REQUEST['edit']['destination']);
      drupal_goto('node/add/'. str_replace('_', '-', $new_type), $query);
    }
  }
}

/**
 * Menu call back for showing a view item
 * @param $type_name content type
 * @param $field_name label of the CCK field
 * @param $index ascending number of widget (needed for multiple value per widget)
 * @return rendered view item
 */
function nodereference_explorer_preview($type_name, $field_name) {
  if (!empty($_GET['val'])) {
    nodereference_explorer_include('nodereference_explorer.util');
    $value = nodereference_explorer_util_parse_widget_value($_GET['val']);
  }
  //retrieve the field by name and content type
  $field = content_fields($field_name, $type_name);

  //get the selected rendered view item
  nodereference_explorer_include('nodereference_explorer.views.class');
  $handler = new nodereference_explorer_views($field);
  $output = $handler->get_item($value['nid']);
  drupal_json(array('status' => TRUE, 'data' => $output));
}

/**
 * List of available displays for a preview. This is
 * automatically updated in the settings form.
 * @return
 *   JSON string
 */
function nodereference_explorer_preview_displays() {
  if (!empty($_GET['view'])) {
    $view_name = $_GET['view'];
    if ($view_name == '--')
      $view_name = NODE_REFERENCE_EXPLORER_DEFAULT_VIEW_NAME;
    $view = views_get_view($view_name);
    $preview_options = array();
    $preview_options['--'] = ''; //prepend no preview
    $displays = $view->display;
    foreach ($displays as $id => $display) //build optoins array
      $preview_options[$id] = $display->display_title;
    drupal_json(array('status' => TRUE, 'data' => $preview_options));
  }
}
