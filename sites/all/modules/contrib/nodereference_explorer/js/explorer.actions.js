// $Id: explorer.actions.js,v 1.5 2010/05/05 17:05:53 gnindl Exp $

/**
 * @file explorer.actions.js 
 * Actions, e. g. buttons, are assigned to core widget. The most important
 * is the action which open the dialog. Each action has settings which are
 * already there from a former request, e. g. loading of node form.
 */

Drupal.nodereference_explorer.actions = Drupal.nodereference_explorer.actions || {};

/**
 * Attaches actions to the core widget, e. g. buttons
 * @param
 *   DOM context
 */
Drupal.behaviors.NodereferenceExplorerActions = function(context) { 
  // open the dialog
  $('.nodereference-explorer-action-open-dialog:not(.nodereference-explorer-processed)', context)
    .click(Drupal.nodereference_explorer.actions.browse).addClass('nodereference-explorer-processed');
  // create dialog
  $('.nodereference-explorer-action-add-dialog:not(.nodereference-explorer-processed)', context)
    .click(Drupal.nodereference_explorer.actions.create).addClass('nodereference-explorer-processed');
  // removes the value
  $('.nodereference-explorer-action-remove-value:not(.nodereference-explorer-processed)', context)
    .click(Drupal.nodereference_explorer.actions.remove).addClass('nodereference-explorer-processed'); 
  // generic node link in preview
  $('.nodereference-explorer-node-link:not(.nodereference-explorer-processed)', context)
    .bind('click', Drupal.nodereference_explorer.link).addClass('nodereference-explorer-processed'); 
};

/**
 * Wraps the target of a (preview) link into an overlay. It's used for node forms which
 * return an updated value to the referenced node selection.
 */
Drupal.nodereference_explorer.link = function() {
  $id = $(this).parents('.nodereference-explorer-preview').attr('id');
        	        	  
  var settings = Drupal.nodereference_explorer.getSettings($id); // get all NRE settings
  var options = settings['dialog']; // specific dialog options, e. g. height
  
  if (options['api'] == 'modalframe') { // only modalframe supported yet
    var url = $(this).attr('href') || '#';
    if (url.indexOf('?') >= 0) {
      url += '&';
    }
    else {
      url += '?';
    }
    url += 'nodereference_explorer_edit=true';        	
  
    options.onSubmit = Drupal.nodereference_explorer.modalframe.addOnSubmit(settings);
    Drupal.nodereference_explorer.modalframe.open(url, options, '');
  }
  return false;
};

/**
 * Action for opening the dialog
 */
Drupal.nodereference_explorer.actions.browse = function() {
  var action = this;
  $id = $(action).attr('id');
  
  var settings = Drupal.nodereference_explorer.getSettings($id); // get all NRE settings
  var options = settings['dialog']; // specific dialog options, e. g. height
  var value = $('#' + settings['widget']).val();
  
  if (options['api'] == 'modalframe') {
    options.onSubmit = Drupal.nodereference_explorer.modalframe.addOnSubmit(settings);
	Drupal.nodereference_explorer.modalframe.open(settings['browse'], options, value);
  }
  else { //built-in default behaviour
	Drupal.nodereference_explorer.actions.startProgress(action);
    $.getJSON(settings['browse'], function(data, textStatus) {
	  Drupal.nodereference_explorer.addCSS(data.css); // add css files
	  // add js files
	  var inlines = Drupal.nodereference_explorer.addJS(data.js); 
	  Drupal.nodereference_explorer.addInlineJS(inlines);
	  options.buttons = Drupal.nodereference_explorer.dialog.addButtonPane(data.js.setting.actions, settings);
	  Drupal.nodereference_explorer.dialog.open(data.data, options, value); //open the dialog
		
	  // when dialog is opened, remove progress
	  Drupal.nodereference_explorer.actions.endProgress(action);
	}); 
  }
  return false; // This will not submit the form.
};

/**
 * Action for creating a node within a dialog. It returns the new node title and id to the parent form.
 */
Drupal.nodereference_explorer.actions.create = function() {
  $id = $(this).attr('id');
  var settings = Drupal.nodereference_explorer.getSettings($id); // get all NRE settings
  var options = settings['dialog']; // specific dialog options, e. g. height
  // Only supported for modalframe yet 
  // Check if "Create & Reference" functionality is enabled, i. e. URL is set
  if (options['api'] == 'modalframe' && settings['create']) {
	options.onSubmit = Drupal.nodereference_explorer.modalframe.addOnSubmit(settings);
	Drupal.nodereference_explorer.modalframe.open(settings['create'], settings['dialog'], '');
  } 
  return false;
};

/**
 * Action for removing selected values and the preview
 */
Drupal.nodereference_explorer.actions.remove = function() {
  $id = $(this).attr('id');
  var settings = Drupal.nodereference_explorer.getSettings($id); //get the settings
  var widget = '#' + settings['widget']; //get the parent widget where the selected value will be saved to
  var type = settings['field_type'];
  Drupal.nodereference_explorer.actions.removeValue(widget, type);
  return false; // This will not submit the form.
};

/**
 * "Saves" the selected value to the parent widget
 * @param widget
 *   widget where the value is saved to
 * @param type
 *   type of target widget, e. g. nodereference. Determins the output format
 * @param value
 *   Actual value to be stored
 */
Drupal.nodereference_explorer.actions.setValue = function(widget, type, value) {
  eval('nodereference_explorer_plugin_content_' +type+ '_setValue(widget, value);');
};

/**
 * Clears the select item value. Like setValue() this is type specific
 * @param widget
 *   widget where the value is saved to
 * @param type
 *   type of target widget, e. g. nodereference. Determins the output format
 */
Drupal.nodereference_explorer.actions.removeValue = function(widget, type) {
  eval('nodereference_explorer_plugin_content_' +type+ '_removeValue(widget);');
};

/**
 * Add a progress throbber, simulating progress
 * @param
 *   widget element
 */
Drupal.nodereference_explorer.actions.startProgress = function(element) {
  $(element).after('<span class="views-throbbing">&nbsp</span>');
  if ($('input', element)) //if the action element is an input disable it, preventing multiple clicking
	$(element).attr('disabled', 'disabled');
};

/**
 * Stop progress when action done
 * @param
 *   widget element
 */
Drupal.nodereference_explorer.actions.endProgress = function(element) {
  $(element).next().remove();
  if ($('input', element))  //enable button again
    $(element).removeAttr("disabled");
};
