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
      <a href="<?php print $base_path; ?>" title="<?php print t('Home'); ?>" rel="home"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" id="logo-image" /></a>
      <?php if ($is_front): ?>
        <h1 class="title" id="page-title"><?php print $site_name; ?></h1>
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

  <div id="page" class="container-16 clear-block">
    <div id="main" class="column <?php print ns('grid-16', $left, 4, $right, 4) . ' ' . ns('push-4', !$left, 4); ?>">
      <?php if ($tabs): ?>
        <div class="tabs"><?php print $tabs; ?></div>
      <?php endif; ?>
      <?php print $messages; ?>
      <?php print $help; ?>

      <div id="main-content" class="region clear-block">
        <?php print $content; ?>
      </div>

      <?php print $feed_icons; ?>
    </div>

  <?php if ($left): ?>
    <div id="sidebar-left" class="column sidebar region grid-4 <?php print ns('pull-12', $right, 4); ?>">
      <?php print $left; ?>
    </div>
  <?php endif; ?>

  <?php if ($right): ?>
    <div id="sidebar-right" class="column sidebar region grid-4">
      <?php print $right; ?>
    </div>
  <?php endif; ?>
  </div>

  <div id="footer">
    <div class="container-16 clear-block">
      <div id="footer-message" class="grid-16">
        <div class="grid-12 alpha">
          <?php if ($footer_message): ?>
            <?php print $footer_message; ?>
          <?php endif; ?>
        </div>
        <div class="grid-4 omega">
          <div class="addthis_toolbox addthis_default_style ">
            <a class="addthis_button_email"></a>
            <a class="addthis_button_facebook"></a>
            <a class="addthis_button_twitter"></a>
            <a class="addthis_button_myspace"></a>
            <a class="addthis_button_compact"></a>
            <a class="addthis_counter addthis_bubble_style"></a>
          </div>
        </div>
      </div>
    </div>
  </div>

  <script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js#pubid=xa-4da33e0038096bc3"></script>
  <?php print $closure; ?>
</body>
</html>
