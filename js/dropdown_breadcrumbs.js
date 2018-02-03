/**
 * @file
 * A JavaScript file for toggling the display of the drop-downs.
 */

jQuery(document).ready(function($){

  // Hide all the dropdown breadcrumb menus on the page.
  $('li.crumb ul').hide();
  $('h1.page-title ul').hide();

  // When the link is clicked...
  $('a.arrow-down').click(function() {

    // If this menu was previously opened, close it.
    if ($(this).siblings('ul').hasClass('ddb-reveal')) {
      $(this).siblings('ul').removeClass('ddb-reveal').hide();
    }
    else {
      // Hide any other previously opened menu.
      $('ul.ddb-reveal').removeClass('ddb-reveal').hide();
      // Show this menu.
      $(this).siblings('ul').addClass('ddb-reveal').show();
    }

    // If this item was previously highlighted, undo that.
    if ($(this).hasClass('ddb-active')) {
      $(this).removeClass('ddb-active');
    }
    else {
      // Un highlight all other buttons.
      $('a.ddb-active').removeClass('ddb-active');
      // Highlight this button.
      $(this).addClass('ddb-active');
    }

    // Prevent default.
    return false;

  });

});
