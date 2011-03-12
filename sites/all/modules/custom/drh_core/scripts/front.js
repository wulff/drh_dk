// $Id$

Drupal.behaviors.drhCoreFront = function (context) {
  $('.front .teaser').hover(
    function () {
      $(this).find('.field-field-image-front-on').fadeOut();
      $(this).find('p').css('z-index', 0);
    },
    function () {
      $(this).find('p').css('z-index', -3);
      $(this).find('.field-field-image-front-on').fadeIn();
    }
  );
}
