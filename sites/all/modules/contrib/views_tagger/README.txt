Views Tagger
================================================================================

Summary
--------------------------------------------------------------------------------

The Views Tagger module adds the taxonomy form elements from the node editing
form to a view. This makes it easy to assign taxonomy terms to many nodes at
once while seeing a preview of the nodes.


Requirements
--------------------------------------------------------------------------------

The View Tagger module requires the Taxonomy (core) and Views modules.


Installation
--------------------------------------------------------------------------------

1. Copy the views_tagger folder to sites/all/modules or to a site-specific
   modules folder.
2. Go to Administer > Site building > Modules and enable the Views Tagger
   module and the Views UI module.

The module provides a default view at /admin/content/node/tagger.


Configuration
--------------------------------------------------------------------------------

1. Go to Administer > Site building > Views and create a new view.
2. Add a couple of fields to the view, e.g. Title and Teaser.
3. Select Basic settings > Style and choose the Tagger style.
4. Create a page display and assign it a URL.
5. Go to the assigned URL and start tagging your content.

Optional: Click the gear icon next to the Tagger style and select the
vocabularies you want to see in the view. If you don't make any changes, all
vocabularies will be included in the view.


Supported modules
--------------------------------------------------------------------------------

Active Tags

The module supports the Active Tags modules, which adds new options to
freetagging taxonomies.

The currently supported version of Active Tags is 6.x-1.7.

To use this module in conjunction with the Active Tags module, you must apply
the patch active_tags.js.patch provided with this module. See the following
page in the handbook for information on how to apply a patch:

  http://drupal.org/node/620014


Support
--------------------------------------------------------------------------------

Please post bug reports and feature requests in the issue queue:

  http://drupal.org/project/views_tagger

ShutterFreak (http://drupal.org/user/103190) has written a nice guide on how to
use the module:

  http://shutterfreak.net/node/68


Credits
--------------------------------------------------------------------------------

Author: Morten Wulff <wulff@ratatosk.net>

Based on the Views Bulk Operations module.


$Id: README.txt,v 1.1.2.5 2010/04/13 08:51:52 wulff Exp $
