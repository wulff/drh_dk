<?php
// $Id$

/* --- PREPROCESSORS -------------------------------------------------------- */

/**
 * Render an image link for use in event popups
 */
function drh_jensen_preprocess_node(&$vars) {
  if (!empty($vars['field_image_ref'][0]['nid'])) {
    $image = node_load($vars['field_image_ref'][0]['nid']);

    if (!empty($image->field_image[0]['filepath'])) {
      $vars['field_image_ref_rendered'] = theme('imagecache', 'calendar_popup', $image->field_image[0]['filepath'], $image->title, $image->title);
    }
  }
}

/**
 * Switch out the page template if we're displaying a panel.
 */
function drh_jensen_preprocess_page(&$vars) {
  if (panels_get_current_page_display()) {
    $vars['template_files'][] = 'page-panel';
  }
  if (drupal_is_front_page()) {
    $vars['is_front'] = TRUE;
  }
}

/**
 * Set a varaible if we're on a panels admin page. This gives us a chance to
 * make the admin interface a little nicer to look at.
 */
function drh_jensen_preprocess_drh_page(&$vars) {
  if ('admin' == arg(0) && 'pages' == arg(2)) {
    $vars['panel_admin'] = TRUE;
  }
}

/**
 * Set a varaible if we're on a panels admin page. This gives us a chance to
 * make the admin interface a little nicer to look at.
 */
function drh_jensen_preprocess_drh_frontpage(&$vars) {
  if ('admin' == arg(0) && 'pages' == arg(2)) {
    $vars['panel_admin'] = TRUE;
  }
}

/* --- CORE OVERRIDES ------------------------------------------------------- */

function drh_jensen_fieldset($element) {
  if (!empty($element['#collapsible'])) {
    drupal_add_js('misc/collapse.js');

    if (!isset($element['#attributes']['class'])) {
      $element['#attributes']['class'] = '';
    }

    $element['#attributes']['class'] .= ' collapsible';
    if (!empty($element['#collapsed'])) {
      $element['#attributes']['class'] .= ' collapsed';
    }
  }

  return '<fieldset'. drupal_attributes($element['#attributes']) .'>'. ($element['#title'] ? '<legend><span>'. $element['#title'] .'</span></legend>' : '') . (isset($element['#description']) && $element['#description'] ? '<div class="description">'. $element['#description'] .'</div>' : '') . (!empty($element['#children']) ? $element['#children'] : '') . (isset($element['#value']) ? $element['#value'] : '') ."</fieldset>\n";
}

/* --- CONTRIB OVERRIDES ---------------------------------------------------- */

/**
 * Theme from/to date combination on form.
 */
function drh_jensen_date_combo($element) {
  $fields = content_fields();
  $field = $fields[$element['#field_name']];
  if (!$field['todate']) {
    return $element['#children'];
  }

  // Group from/to items together in fieldset.
  $fieldset = array(
    '#title' => check_plain($field['widget']['label']) .' '. ($element['#delta'] > 0 ? intval($element['#delta'] + 1) : ''),
    '#value' => $element['#children'],
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#description' => $element['#fieldset_description'],
    '#attributes' => array('class' => 'group-from-to'),
  );
  return theme('fieldset', $fieldset);
}

/**
 * Theme formatter medium.
 */
function drh_jensen_embed_gmap_formatter_medium($element) {
  $element['#item'] = embed_gmap_process_value($element['#item']);

  if (empty($element['#item']['value'])) {
    return '';
  }

  $width = 425;
  $height = 240;

  return '<iframe width="'. $width .'" height="'. $height .'" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="'. $element['#item']['value'] .'"></iframe><p class="embed-gmap-link"><a href="'. str_replace('&amp;output=embed', '', $element['#item']['value']) .'" target="_BLANK">'. t('Show large map') .'</a></p>';
}

/**
 * Theme formatter large.
 */
function drh_jensen_embed_gmap_formatter_large($element) {
  $element['#item'] = embed_gmap_process_value($element['#item']);

  if (empty($element['#item']['value'])) {
    return '';
  }

  $width = 760;
  $height = 432;

  return '<iframe width="'. $width .'" height="'. $height .'" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="'. $element['#item']['value'] .'"></iframe><p class="embed-gmap-link"><a href="'. str_replace('&amp;output=embed', '', $element['#item']['value']) .'" target="_BLANK">'. t('Show large map') .'</a></p>';
}

/**
 * Render an icon to display in the Administration Menu.
 */
function drh_jensen_admin_menu_icon() {
  return t('Drupal');
}

/**
 * Jcalendar popup view.
 */
function drh_jensen_jcalendar_view($node) {
  $output = node_view($node, TRUE);
  $output .= '<div id="nodelink">'. l(t('Read more', array(), $node->language), calendar_get_node_link($node)) .'</div>';
  return $output;
}
