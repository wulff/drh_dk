<?php
// $Id: oembedcore_theme.inc,v 1.1 2010/02/21 12:12:35 voxpelli Exp $

/**
 * @file
 * Theme related functions for oEmbed Core
 */

function template_preprocess_oembed(&$vars) {
  $embed = $vars['embed'];

  $vars['original_url'] = check_url($embed->original_url);
  $vars['title']        = check_plain($embed->title);

  $vars['template_files'][] = 'oembed';

  $valid_types = array('link', 'photo', 'video', 'rich');
  if (in_array($embed->type, $valid_types)) {
    $vars['template_files'][] = 'oembed-' . $embed->type;
  }
}