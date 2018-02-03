<?php
/**
 * @file
 * Theme functions for dropdown breadcrumb blocks.
 */

/**
 * Theme function. Returns output for the breadcrumb trail, with dropdowns.
 */
function theme_dropdown_breadcrumbs($variables) {
  $breadcrumbs = $variables['breadcrumb'];

  $output = '';
  if (!empty($breadcrumbs)) {
    $output .= '<nav role="navigation" class="breadcrumb dropdown-breadcrumb">';
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output .= '  <h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= '  <ol>';
    $crumb_count = 0;

    $last = end($breadcrumbs);
    if (!$last['access']) {
      array_pop($breadcrumbs);
    }

    foreach ($breadcrumbs as $crumb) {
      $crumb_count++;
      $crumb['localized_options']['attributes']['class'] = array('crumb');
      $output .= '  <li class="crumb">';

      if (isset($crumb['href']) && $crumb['href'] != current_path()) {
        $output .= l($crumb['title'], $crumb['href'], $crumb['localized_options']);
      }
      else {
        $output .= '<span>' . t($crumb['title']) . '</span>';
      }

      if (isset($crumb['#dropdown_breadcrumb_menu'])) {
        $output .= '<a class="arrow-down" href="#"></a>';
        $output .= backdrop_render($crumb['#dropdown_breadcrumb_menu']);
      }

      if ($crumb_count != count($breadcrumbs)) {
        $output .= '<span class="separator">/</span>';
      }

      $output .= '  </li>';
    }
    $output .= '  </ol>';
    $output .= '</nav>';
  }

  return $output;
}

/**
 * Theme function. Returns output for the page title, with dropdowns.
 */
function theme_dropdown_title($variables) {
  $output  = '<h1 class="page-title"><span>';
  $output .= backdrop_get_title();

  if (isset($variables['menu']['#dropdown_breadcrumb_menu'])) {
    $output .= '<a class="arrow-down" href="#"></a>';
    $output .= backdrop_render($variables['menu']['#dropdown_breadcrumb_menu']);
  }

  $output .= '</span></h1>';

  return $output;
}
