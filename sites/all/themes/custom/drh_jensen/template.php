<?php

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
 * Set a variable if we're on a panels admin page. This gives us a chance to
 * make the admin interface a little nicer to look at.
 */
function drh_jensen_preprocess_drh_page(&$vars) {
  $vars['panel_admin'] = ('admin' == arg(0) && 'pages' == arg(2));
}

/**
 * Set a variable if we're on a panels admin page. This gives us a chance to
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

/**
 * Generate the HTML output for imagefield + imagecache images so they can be
 * opened in a lightbox by clicking on the image on the node page or in a view.
 *
 * This actually also handles filefields + imagecache images too.
 *
 * @param $view_preset
 *   The imagecache preset to be displayed on the node or in the view.
 * @param $field_name
 *   The field name the action is being performed on.
 * @param $item
 *   An array, keyed by column, of the data stored for this item in this field.
 * @param $node
 *   The node object.
 * @param $rel
 *   The type of lightbox to open: lightbox, lightshow or lightframe.
 * @param $args
 *   Args may override internal processes: caption, rel_grouping.
 * @return
 *   The themed imagefield + imagecache image and link.
 */
function drh_jensen_imagefield_image_imagecache_lightbox2($view_preset, $field_name, $item, $node, $rel = 'lightbox', $args = array()) {
  if (!isset($args['lightbox_preset'])) {
    $args['lightbox_preset'] = 'original';
  }
  // Can't show current node page in a lightframe on the node page.
  // Switch instead to show it in a lightbox.
  $on_image_node = (arg(0) == 'node') && (arg(1) == $node->nid);
  if ($rel == 'lightframe' && $on_image_node) {
    $rel = 'lightbox';
  }
  $orig_rel = $rel;

  // Unserialize into original - if sourced by views.
  $item_data = $item['data'];
  if (is_string($item['data'])) {
    $item_data = unserialize($item['data']);
  }

  // Set up the title.
  $image_title = !empty($item_data['description']) ? $item_data['description'] : '';
  if (empty($image_title) && isset($item_data['title'])) {
    $image_title = $item_data['title'];
  }
  if (empty($image_title) && isset($item_data['alt'])) {
    $image_title = $item_data['alt'];
  }
  if (empty($image_title) || variable_get('lightbox2_imagefield_use_node_title', FALSE)) {
    $node = node_load($node->nid);
    $image_title = $node->title;
  }

  $image_tag_title = '';
  if (!empty($item_data['title'])) {
    $image_tag_title = $item_data['title'];
  }

  // Enforce image alt.
  $image_tag_alt = '';
  if (!empty($item_data['alt'])) {
    $image_tag_alt = $item_data['alt'];
  }
  elseif (!empty($image_title)) {
    $image_tag_alt = $image_title;
  }

  // Set up the caption.
  $node_links = array();
  if (!empty($item['nid'])) {
    $attributes = array();
    $attributes['id'] = 'lightbox2-node-link-text';
    $target = variable_get('lightbox2_node_link_target', FALSE);
    if (!empty($target)) {
      $attributes['target'] = $target;
    }
    $node_link_text = variable_get('lightbox2_node_link_text', 'View Image Details');
    if (!$on_image_node && !empty($node_link_text)) {
      $node_links[] = l($node_link_text, 'node/'. $item['nid'], array('attributes' => $attributes));
    }
    $download_link_text = check_plain(variable_get('lightbox2_download_link_text', 'Download Original'));
    if (!empty($download_link_text) && user_access('download original image')) {
      $node_links[] = l($download_link_text, file_create_url($item['filepath']), array('attributes' => array('target' => '_blank', 'id' => 'lightbox2-download-link-text')));
    }
  }

  $caption = $image_title;
  if (count($node_links)) {
    $caption .= ' '. implode(" - ", $node_links);
  }
  if (isset($args['caption'])) {
    $caption = $args['caption']; // Override caption.
  }

  if ($orig_rel == 'lightframe') {
    $frame_width = variable_get('lightbox2_default_frame_width', 600);
    $frame_height = variable_get('lightbox2_default_frame_height', 400);
    $frame_size = 'width:'. $frame_width .'px; height:'. $frame_height .'px;';
    $rel = preg_replace('/\]$/', "|$frame_size]", $rel);
  }

  // Set up the rel attribute.
  $full_rel = '';
  $imagefield_grouping = variable_get('lightbox2_imagefield_group_node_id', 1);
  if (isset($args['rel_grouping'])) {
    $full_rel = $rel .'['. $args['rel_grouping'] .']['. $caption .']';
  }
  elseif ($imagefield_grouping == 1) {
    $full_rel = $rel .'['. $field_name .']['. $caption .']';
  }
  elseif ($imagefield_grouping == 2 && !empty($item['nid'])) {
    $full_rel = $rel .'['. $item['nid'] .']['. $caption .']';
  }
  elseif ($imagefield_grouping == 3 && !empty($item['nid'])) {
    $full_rel = $rel .'['. $field_name .'_'. $item['nid'] .']['. $caption .']';
  }
  elseif ($imagefield_grouping == 4 ) {
    $full_rel = $rel .'[allnodes]['. $caption .']';
  }
  else {
    $full_rel = $rel .'[]['. $caption .']';
  }
  $class = '';
  if ($view_preset != 'original') {
    $class = 'imagecache imagecache-' . $field_name . ' imagecache-' . $view_preset . ' imagecache-' . $field_name . '-' . $view_preset;
  }
  $link_attributes = array(
    'rel' => $full_rel,
    'class' => 'imagefield imagefield-lightbox2 imagefield-lightbox2-' . $view_preset . ' imagefield-' . $field_name . ' ' . $class,
  );

  $attributes = array();
  if (isset($args['compact']) && $item['#delta']) {
    $image = '';
  }
  elseif ($view_preset == 'original') {
    $image = theme('lightbox2_image', $item['filepath'], $image_tag_alt, $image_tag_title, $attributes);
  }
  elseif ($view_preset == 'link') {
    // Not actually an image, just a text link.
    $image = variable_get('lightbox2_view_image_text', 'View image');
  }
  else {
    $image = theme('imagecache', $view_preset, $item['filepath'], $image_tag_alt, $image_tag_title, $attributes);
  }

  if ($args['lightbox_preset'] == 'node') {
    $output = l($image, 'node/'. $node->nid .'/lightbox2', array('attributes' => $link_attributes, 'html' => TRUE));
  }
  elseif ($args['lightbox_preset'] == 'original') {
    $output = l($image, file_create_url($item['filepath']), array('attributes' => $link_attributes, 'html' => TRUE));
  }
  else {
    $output = l($image, imagecache_create_url($args['lightbox_preset'], $item['filepath']), array('attributes' => $link_attributes, 'html' => TRUE));
  }

  return $output;
}
