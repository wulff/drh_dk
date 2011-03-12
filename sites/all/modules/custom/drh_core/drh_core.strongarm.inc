<?php
// $Id$

/**
 * @file
 * Strongarmed variables for drh.dk.
 */

/**
 * Implementation of hook_strongarm().
 */
function drh_core_strongarm() {
  // core
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'drh.dk';
  $strongarms['site_name'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_footer';
  $strongarm->value = 'Den Rytmiske Højskole · Jyderupvej 18 · 4560 Vig · 59 360 600 · <a href="/kontakt">den@rytmiske.dk</a>';
  $strongarms['site_footer'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'drh_jensen';
  $strongarms['theme_default'] = $strongarm;

  // admin menu
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_menu_tweak_modules';
  $strongarm->value = TRUE;
  $strongarms['admin_menu_tweak_modules'] = $strongarm;

  // image
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_jpeg_quality';
  $strongarm->value = 80;
  $strongarms['image_jpeg_quality'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imageapi_jpeg_quality';
  $strongarm->value = 80;
  $strongarms['imageapi_jpeg_quality'] = $strongarm;

  // nodeformcols
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_profile_default';
  $strongarm->value = array (
    'title' => array (
      'region' => 'main',
      'weight' => '2',
      'has_required' => true,
      'title' => 'Navn',
    ),
    'body_field' => array (
      'region' => 'main',
      'weight' => '4',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => array (
      'region' => 'right',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'revision_information' => array (
      'region' => 'right',
      'weight' => '4',
      'has_required' => false,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'comment_settings' => array (
      'region' => 'right',
      'weight' => '6',
      'has_required' => false,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'path' => array (
      'region' => 'right',
      'weight' => '2',
      'has_required' => false,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'options' => array (
      'region' => 'right',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'author' => array (
      'region' => 'right',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'buttons' => array (
      'region' => 'footer',
      'weight' => '6',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'group_dates' => array (
      'region' => 'main',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Datoer',
      'collapsed' => 1,
    ),
    'group_notes' => array (
      'region' => 'main',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Noter',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_images' => array (
      'region' => 'main',
      'weight' => '6',
      'has_required' => false,
      'title' => 'Billeder',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_links' => array (
      'region' => 'main',
      'weight' => '7',
      'has_required' => false,
      'title' => 'Links',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'taxonomy' => array (
      'region' => 'right',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Vocabularies',
      'collapsed' => 0,
    ),
    'group_courses' => array (
      'region' => 'main',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Fag',
      'collapsed' => 0,
      'hidden' => 0,
    ),
    'field_teaser' => array (
      'region' => 'main',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Teaser',
      'hidden' => 0,
    ),
  );
  $strongarms['nodeformscols_field_placements_profile_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_event_default';
  $strongarm->value = array (
    'title' => array (
      'region' => 'main',
      'weight' => '3',
      'has_required' => true,
      'title' => 'Title',
    ),
    'body_field' => array (
      'region' => 'main',
      'weight' => '5',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => array (
      'region' => 'right',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'revision_information' => array (
      'region' => 'right',
      'weight' => '4',
      'has_required' => false,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'comment_settings' => array (
      'region' => 'right',
      'weight' => '6',
      'has_required' => false,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'path' => array (
      'region' => 'right',
      'weight' => '2',
      'has_required' => false,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'options' => array (
      'region' => 'right',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'author' => array (
      'region' => 'right',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'buttons' => array (
      'region' => 'footer',
      'weight' => '7',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'group_dates' => array (
      'region' => 'main',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Datoer',
      'collapsed' => 1,
    ),
    'group_notes' => array (
      'region' => 'main',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Noter',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_images' => array (
      'region' => 'main',
      'weight' => '6',
      'has_required' => false,
      'title' => 'Billeder',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_links' => array (
      'region' => 'main',
      'weight' => '7',
      'has_required' => false,
      'title' => 'Links',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_map' => array (
      'region' => 'main',
      'weight' => '8',
      'has_required' => false,
      'title' => 'Kort',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'field_date' => array (
      'region' => 'main',
      'weight' => '2',
      'has_required' => true,
      'title' => 'Dato',
    ),
    'field_teaser' => array (
      'region' => 'main',
      'weight' => '4',
      'has_required' => false,
      'title' => 'Teaser',
      'hidden' => 0,
    ),
    'taxonomy' => array (
      'region' => 'right',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Vocabularies',
      'collapsed' => 0,
    ),
  );
  $strongarms['nodeformscols_field_placements_event_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_image_default';
  $strongarm->value = array (
    'title' => 
    array (
      'region' => 'main',
      'weight' => '3',
      'has_required' => true,
      'title' => 'Titel',
    ),
    'body_field' => 
    array (
      'region' => 'main',
      'weight' => '4',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => 
    array (
      'region' => 'right',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'revision_information' => 
    array (
      'region' => 'right',
      'weight' => '4',
      'has_required' => false,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'comment_settings' => 
    array (
      'region' => 'right',
      'weight' => '6',
      'has_required' => false,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'path' => 
    array (
      'region' => 'right',
      'weight' => '2',
      'has_required' => false,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'options' => 
    array (
      'region' => 'right',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Publishing options',
      'collapsed' => 0,
      'hidden' => 0,
    ),
    'author' => 
    array (
      'region' => 'right',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'buttons' => 
    array (
      'region' => 'footer',
      'weight' => '6',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'taxonomy' => 
    array (
      'region' => 'right',
      'weight' => '0',
      'has_required' => false,
      'title' => 'Vocabularies',
      'collapsed' => 0,
      'hidden' => 0,
    ),
    'group_dates' => 
    array (
      'region' => 'main',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Datoer',
      'collapsed' => 1,
    ),
    'group_notes' => 
    array (
      'region' => 'main',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Noter',
      'hidden' => 0,
      'collapsed' => 1,
    ),
    'group_image' => 
    array (
      'region' => 'main',
      'weight' => '2',
      'has_required' => false,
      'title' => 'Billede',
      'collapsed' => 0,
      'hidden' => 0,
    ),
  );
  $strongarms['nodeformscols_field_placements_image_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; // Edit this to true to make a default strongarm disabled initially
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_facility_default';
  $strongarm->value = array (
    'title' => 
    array (
      'region' => 'main',
      'weight' => '2',
      'has_required' => true,
      'title' => 'Titel',
    ),
    'body_field' => 
    array (
      'region' => 'main',
      'weight' => '4',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => 
    array (
      'region' => 'right',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'revision_information' => 
    array (
      'region' => 'right',
      'weight' => '4',
      'has_required' => false,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'comment_settings' => 
    array (
      'region' => 'right',
      'weight' => '6',
      'has_required' => false,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'path' => 
    array (
      'region' => 'right',
      'weight' => '2',
      'has_required' => false,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'options' => 
    array (
      'region' => 'right',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'author' => 
    array (
      'region' => 'right',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'buttons' => 
    array (
      'region' => 'footer',
      'weight' => '6',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'group_dates' => 
    array (
      'region' => 'main',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Datoer',
      'collapsed' => 1,
    ),
    'group_notes' => 
    array (
      'region' => 'main',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Noter',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_images' => 
    array (
      'region' => 'main',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Billeder',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_links' => 
    array (
      'region' => 'main',
      'weight' => '6',
      'has_required' => false,
      'title' => 'Links',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'field_teaser' => 
    array (
      'region' => 'main',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Teaser',
      'hidden' => 0,
    ),
    'taxonomy' => 
    array (
      'region' => 'right',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Vocabularies',
      'collapsed' => 0,
    ),
  );
  $strongarms['nodeformscols_field_placements_facility_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; // Edit this to true to make a default strongarm disabled initially
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_course_default';
  $strongarm->value = array (
    'title' => 
    array (
      'region' => 'main',
      'weight' => '2',
      'has_required' => true,
      'title' => 'Navn',
    ),
    'body_field' => 
    array (
      'region' => 'main',
      'weight' => '4',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => 
    array (
      'region' => 'right',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'revision_information' => 
    array (
      'region' => 'right',
      'weight' => '4',
      'has_required' => false,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'comment_settings' => 
    array (
      'region' => 'right',
      'weight' => '6',
      'has_required' => false,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'path' => 
    array (
      'region' => 'right',
      'weight' => '2',
      'has_required' => false,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'options' => 
    array (
      'region' => 'right',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'author' => 
    array (
      'region' => 'right',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'buttons' => 
    array (
      'region' => 'footer',
      'weight' => '6',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'field_teaser' => 
    array (
      'region' => 'main',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Teaser',
      'hidden' => 0,
    ),
    'group_dates' => 
    array (
      'region' => 'main',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Datoer',
      'collapsed' => 1,
    ),
    'group_notes' => 
    array (
      'region' => 'main',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Noter',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_images' => 
    array (
      'region' => 'main',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Billeder',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'taxonomy' => 
    array (
      'region' => 'right',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Vocabularies',
      'collapsed' => 0,
    ),
  );
  $strongarms['nodeformscols_field_placements_course_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; // Edit this to true to make a default strongarm disabled initially
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_teaser_default';
  $strongarm->value = array (
    'title' => 
    array (
      'region' => 'main',
      'weight' => '2',
      'has_required' => true,
      'title' => 'Titel',
    ),
    'body_field' => 
    array (
      'region' => 'main',
      'weight' => '3',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => 
    array (
      'region' => 'right',
      'weight' => '4',
      'has_required' => false,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'revision_information' => 
    array (
      'region' => 'right',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'comment_settings' => 
    array (
      'region' => 'right',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'path' => 
    array (
      'region' => 'right',
      'weight' => '1',
      'has_required' => false,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'options' => 
    array (
      'region' => 'right',
      'weight' => '0',
      'has_required' => false,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'author' => 
    array (
      'region' => 'right',
      'weight' => '2',
      'has_required' => false,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'buttons' => 
    array (
      'region' => 'footer',
      'weight' => '5',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'group_dates' => 
    array (
      'region' => 'main',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Datoer',
      'collapsed' => 1,
    ),
    'group_notes' => 
    array (
      'region' => 'main',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Noter',
      'hidden' => 0,
      'collapsed' => 1,
    ),
    'group_images' => 
    array (
      'region' => 'main',
      'weight' => '4',
      'has_required' => false,
      'title' => 'Billeder',
      'collapsed' => 1,
      'hidden' => 0,
    ),
  );
  $strongarms['nodeformscols_field_placements_teaser_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; // Edit this to true to make a default strongarm disabled initially
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_topic_default';
  $strongarm->value = array (
    'title' => 
    array (
      'region' => 'main',
      'weight' => '2',
      'has_required' => true,
      'title' => 'Navn',
    ),
    'body_field' => 
    array (
      'region' => 'main',
      'weight' => '4',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => 
    array (
      'region' => 'right',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'revision_information' => 
    array (
      'region' => 'right',
      'weight' => '4',
      'has_required' => false,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'comment_settings' => 
    array (
      'region' => 'right',
      'weight' => '6',
      'has_required' => false,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'path' => 
    array (
      'region' => 'right',
      'weight' => '2',
      'has_required' => false,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'options' => 
    array (
      'region' => 'right',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'author' => 
    array (
      'region' => 'right',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'buttons' => 
    array (
      'region' => 'footer',
      'weight' => '5',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'group_dates' => 
    array (
      'region' => 'main',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Datoer',
      'collapsed' => 1,
    ),
    'group_notes' => 
    array (
      'region' => 'main',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Noter',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_images' => 
    array (
      'region' => 'main',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Billeder',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'field_teaser' => 
    array (
      'region' => 'main',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Teaser',
      'hidden' => 0,
    ),
    'taxonomy' => 
    array (
      'region' => 'right',
      'weight' => '0',
      'has_required' => false,
      'title' => 'Vocabularies',
      'collapsed' => 0,
      'hidden' => 0,
    ),
  );
  $strongarms['nodeformscols_field_placements_topic_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; // Edit this to true to make a default strongarm disabled initially
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_news_default';
  $strongarm->value = array (
    'title' => 
    array (
      'region' => 'main',
      'weight' => '2',
      'has_required' => true,
      'title' => 'Titel',
    ),
    'body_field' => 
    array (
      'region' => 'main',
      'weight' => '4',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => 
    array (
      'region' => 'right',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'revision_information' => 
    array (
      'region' => 'right',
      'weight' => '4',
      'has_required' => false,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'comment_settings' => 
    array (
      'region' => 'right',
      'weight' => '6',
      'has_required' => false,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'path' => 
    array (
      'region' => 'right',
      'weight' => '2',
      'has_required' => false,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'options' => 
    array (
      'region' => 'right',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'author' => 
    array (
      'region' => 'right',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'buttons' => 
    array (
      'region' => 'footer',
      'weight' => '5',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'field_teaser' => 
    array (
      'region' => 'main',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Teaser',
      'hidden' => 0,
    ),
    'group_dates' => 
    array (
      'region' => 'main',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Datoer',
      'collapsed' => 1,
    ),
    'group_notes' => 
    array (
      'region' => 'main',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Noter',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_images' => 
    array (
      'region' => 'main',
      'weight' => '8',
      'has_required' => false,
      'title' => 'Billeder',
      'hidden' => 0,
      'collapsed' => 1,
    ),
    'group_links' => 
    array (
      'region' => 'main',
      'weight' => '9',
      'has_required' => false,
      'title' => 'Links',
      'hidden' => 0,
      'collapsed' => 1,
    ),
    'taxonomy' => 
    array (
      'region' => 'right',
      'weight' => '0',
      'has_required' => false,
      'title' => 'Vocabularies',
      'collapsed' => 0,
      'hidden' => 0,
    ),
  );
  $strongarms['nodeformscols_field_placements_news_default'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; // Edit this to true to make a default strongarm disabled initially
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements_page_default';
  $strongarm->value = array (
    'title' => 
    array (
      'region' => 'main',
      'weight' => '2',
      'has_required' => true,
      'title' => 'Title',
    ),
    'body_field' => 
    array (
      'region' => 'main',
      'weight' => '3',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'menu' => 
    array (
      'region' => 'right',
      'weight' => '5',
      'has_required' => false,
      'title' => 'Menu settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'revision_information' => 
    array (
      'region' => 'right',
      'weight' => '4',
      'has_required' => false,
      'title' => 'Revision information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'comment_settings' => 
    array (
      'region' => 'right',
      'weight' => '6',
      'has_required' => false,
      'title' => 'Comment settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'path' => 
    array (
      'region' => 'right',
      'weight' => '2',
      'has_required' => false,
      'title' => 'URL path settings',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'options' => 
    array (
      'region' => 'right',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Publishing options',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'author' => 
    array (
      'region' => 'right',
      'weight' => '3',
      'has_required' => false,
      'title' => 'Authoring information',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'buttons' => 
    array (
      'region' => 'footer',
      'weight' => '6',
      'has_required' => false,
      'title' => NULL,
      'hidden' => 0,
    ),
    'group_dates' => 
    array (
      'region' => 'main',
      'weight' => '0',
      'has_required' => true,
      'title' => 'Datoer',
      'collapsed' => 1,
    ),
    'group_notes' => 
    array (
      'region' => 'main',
      'weight' => '1',
      'has_required' => false,
      'title' => 'Noter',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_images' => 
    array (
      'region' => 'main',
      'weight' => '7',
      'has_required' => false,
      'title' => 'Billeder',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_links' => 
    array (
      'region' => 'main',
      'weight' => '8',
      'has_required' => false,
      'title' => 'Links',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_files' => 
    array (
      'region' => 'main',
      'weight' => '9',
      'has_required' => false,
      'title' => 'Filer',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'group_map' => 
    array (
      'region' => 'main',
      'weight' => '9',
      'has_required' => false,
      'title' => 'Kort',
      'collapsed' => 1,
      'hidden' => 0,
    ),
    'taxonomy' => 
    array (
      'region' => 'right',
      'weight' => '0',
      'has_required' => false,
      'title' => 'Vocabularies',
      'collapsed' => 0,
      'hidden' => 0,
    ),
  );
  $strongarms['nodeformscols_field_placements_page_default'] = $strongarm;

/*
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; // Edit this to true to make a default strongarm disabled initially
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeformscols_field_placements__default';
  $strongarm->value =
  $strongarms['nodeformscols_field_placements__default'] = $strongarm;
*/

  return $strongarms;
}
