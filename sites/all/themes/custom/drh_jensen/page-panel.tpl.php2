<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>

<body class="<?php print $body_classes; ?>">
  <div id="navigation">
    <div class="container-16 clear-block">
      <div id="primary_navigation" class="grid-16">
        <?php print $main_menu_links; ?>
      </div>
    </div>
  </div>

  <div id="header" class="container-16 clear-block">
    <div class="grid-12">
      <?php if ($linked_site_name): ?>
        <h1 id="site-name"><?php print $linked_site_name; ?></h1>
      <?php endif; ?>
      <?php if ($is_front): ?>
        <h1 class="title" id="page-title"><?php print $site_slogan; ?></h1>
      <?php else: ?>
      <?php if ($title): ?>
        <h1 class="title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php endif; ?>
    </div>
    <div class="grid-4">
      <?php if ($search_box): ?>
        <div id="search-box"><?php print $search_box; ?></div>
      <?php endif; ?>
    </div>
  </div>

  <hr />

  <div id="tools" class="container-16 clear-block">
    <div class="grid-16">
      <?php if ($tabs): ?>
        <div class="tabs"><?php print $tabs; ?></div>
      <?php endif; ?>
      <?php print $messages; ?>
      <?php print $help; ?>
      <?php print $feed_icons; ?>
    </div>
  </div>

  <div id="content" class="container-16 clear-block">
    <?php print $content; ?>
  </div>

  <div id="footer">
    <div class="container-16 clear-block">
      <div id="footer-message" class="grid-16">
        <?php if ($footer_message): ?>
          <?php print $footer_message; ?>
        <?php endif; ?>
      </div>
    </div>
  </div>

  <?php print $closure; ?>
</body>
</html>
