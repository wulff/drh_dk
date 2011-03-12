Imagefield import
================================================================================

Summary
--------------------------------------------------------------------------------

Imagefield import allows users with the proper permissions to import a bunch of
images from a directory on the server into nodes with imagefields.


Requirements
--------------------------------------------------------------------------------

The Imagefield import module requires the CCK and Imagefield modules.


Installation
--------------------------------------------------------------------------------

1. Copy the imagefield_import folder to sites/all/modules or to a site-specific
   modules folder.
2. Go to Administer > Site building > Modules and enable the Imagefield import
   module.


Configuration
--------------------------------------------------------------------------------

1. Go to Administer > Site configuration > Imagefield import and configure the
   upload folder and target imagefield.
2. Go to Administer > Content management > Import images to import images from
   the upload folder.

Thumbnails

These options let you display thumbnails next to the filenames on the import
form. Be aware that the thumbnails are just the original images scaled by the
browser, so this option might not be a good choice if the images you are
importing are very high resolution.

File handling

Ignore files: Enter a regular expression to ignore specific files during import.
Example: Enter "/bmp$/" (without the quotes) to ignore all .bmp files. Ignored
files will not show up on the import form.

Delete files after import: By default, the files are deleted when they have been
imported. Disable this option if you want to keep the files around.

Publishing options

Set node status during import: Enable this option if you want to set the
published/unpublished status of each imported node directly from the import
form.

Set default status to unpublished: By default the status of all imported nodes
is set to published. Use this to set the default status for some nodes to
unpublished. All filenames matching this regular expression will have their
default status set to unpublished. Remember to include the leading and trailing
slashes of the regular expression. Example: Enter "/^_/" (without the quotes) in
the field to set the status of all files starting with _ to unpublished (e.g.
_foo.jpg).

Advanced settings

Title and body fields: You can choose to have the title and body fields prepopu-
lated with the filename, or data pulled from EXIF or IPTC. The EXIF and IPTC
options are only displayed if they are supported by your PHP installation.

If you choose to have the data prepopulated from EXIF or IPTC, you can select
which metadata tags should be used to prepopulate the title and body fields on
the import form.

Display selection form: Disable this option to bypass the standard selection
form. This is useful if you are importing thousands of images and don't need to
set titles and bodies individually. You will still have the option to assign
taxonomy terms, etc.


Notes
--------------------------------------------------------------------------------

If you have defined a maximum resolution for images in your image field, you
should be aware that the original file in the upload directory is resized
before the image is moved to its new location.


Support
--------------------------------------------------------------------------------

Please post bug reports and feature requests in the issue queue:

   http://drupal.org/project/imagefield_import


Credits
--------------------------------------------------------------------------------

Original author: vordude (http://drupal.org/user/150473)

Maintainer: Morten Wulff <wulff@ratatosk.net> (http://drupal.org/user/7118)


$Id: README.txt,v 1.1.2.8 2010/02/10 11:33:11 wulff Exp $
