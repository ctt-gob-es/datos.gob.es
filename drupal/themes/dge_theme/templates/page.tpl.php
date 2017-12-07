<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dge_theme (datos.gob.es)".
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file
 * Bartik's theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template normally located in the
 * modules/system directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $hide_site_name: TRUE if the site name has been toggled off on the theme
 *   settings page. If hidden, the "element-invisible" class is added to make
 *   the site name visually hidden, but still accessible.
 * - $hide_site_slogan: TRUE if the site slogan has been toggled off on the
 *   theme settings page. If hidden, the "element-invisible" class is added to
 *   make the site slogan visually hidden, but still accessible.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']: Items for the header region.
 * - $page['menu']: Items for the menu region.
 * - $page['featured']: Items for the featured region.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['triptych_first']: Items for the first triptych.
 * - $page['triptych_middle']: Items for the middle triptych.
 * - $page['triptych_last']: Items for the last triptych.
 * - $page['footer_firstcolumn']: Items for the first footer column.
 * - $page['footer_secondcolumn']: Items for the second footer column.
 * - $page['footer_thirdcolumn']: Items for the third footer column.
 * - $page['footer_fourthcolumn']: Items for the fourth footer column.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see bartik_process_page()
 * @see html.tpl.php
 */
?>
<div class="site-page">
	<!-- HEADER -->
	<div class="site-header">
		<div class="site-wrapper">
			<h1 role="banner" class="site-header__banner">
			<?php if (!empty($logo)): ?>
			<?php 
				$home = url('<front>', array('absolute' => TRUE));
				$home = str_replace('/home', '', $home);
			?>
				<a href="<?php print $home; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-header__link">
					<img src="<?php print $logo; ?>" alt="<?php print $site_name; ?>. <?php print $site_slogan; ?>. <?php print t('Go home') ?>" class="site-header__logo" />
				</a>
				<?php endif; ?>
			</h1>
			<?php if ($page['navigation']): ?>
			<nav class="dge-mobilenav">
				<a href="#dge-user-menu--rwd" class="dge-mobileuser"><img src="<?php print base_path().path_to_theme(); ?>/images/ico-menu-user-rwd.png" alt=""><span class="element-invisible"> <?php print t('User'); ?></span></a>
				<a href="#dge-search-menu--rwd" class="dge-mobilesearch"><img src="<?php print base_path().path_to_theme(); ?>/images/ico-menu-search-rwd.png" alt=""><span class="element-invisible"> <?php print t('Search'); ?></span></a>
				<a href="#dge-main-menu--rwd" class="dge-mobilemenu"><img src="<?php print base_path().path_to_theme(); ?>/images/ico-menu-rwd.png" alt=""><span class="element-invisible"> <?php print t('Menu'); ?></span></a>
			</nav>
			<?php endif; ?>
			<?php if ($page['header']): ?>
			<div class="site-header__options">
				<?php print render($page['header']); ?>
			</div>
			<?php endif; ?>
		</div>
	</div>
	<!-- NAVIGATION -->
	<div class="site-navigation">
		<div class="site-wrapper">
			<?php if ($page['navigation']): ?>
			<nav role="navigation" class="main-navigation">
				<?php print render($page['navigation']); ?>
			</nav>
			<?php endif; ?>
			<?php if ($page['sub_navigation']): ?>
			<div class="sub-navigation">
				<?php print render($page['sub_navigation']); ?>
			</div>
			<?php endif; ?>
		</div>
	</div>
	<!-- MESSAGES -->
	<?php if ($messages): ?>
	<div id="messages" class="site-messages clearfix">
		<div class="site-wrapper">
		<?php print $messages; ?>
		</div>
	</div>
	<?php endif; ?>
	<!-- CONTENT -->
	<main id="main" role="main" class="site-main clearfix">
		<div class="site-wrapper">

			<?php if ($breadcrumb): ?>
			<div id="breadcrumb" class="dge-breadcrumb"><?php print $breadcrumb; ?></div>
			<?php endif; ?>

			<div id="content" class="site-content">
				<div class="site-content__wrapper">
					<a id="main-content"></a>
					<?php if ($feed_icons): ?><div class="dge-feeds"><?php print $feed_icons; ?></div><?php endif; ?>
					<?php if ($title): ?>
					<?php print render($title_prefix); ?>
					<h1 class="page-title" id="page-title">
						<?php print $title; ?>
					</h1>
					<?php print render($title_suffix); ?>
					<?php endif; ?>
					
					<?php if ($tabs): ?>
					<div class="tabs">
					  <?php print render($tabs); ?>
					</div>
					<?php endif; ?>
					<?php print render($page['content']); ?>
				</div>
			</div>

			<?php if ($page['sidebar_first']): ?>
			<aside id="sidebar-first" class="site-sidebar" role="complementary">
				<div class="section">
				<?php print render($page['sidebar_first']); ?>
				</div>
			</aside>
			<?php endif; ?>

			<?php if ($page['sidebar_second']): ?>
			<aside id="sidebar-second" class="site-sidebar--alt">
				<div class="section">
				<?php print render($page['sidebar_second']); ?>
				</div>
			</aside>
			<?php endif; ?>
		</div>
	</main>
	<!-- FOOTER -->
	<?php if ($page['footer_pre']): ?>
	<div class="site-pre-footer">
		<div class="section">
			<?php print render($page['footer_pre']); ?>
		</div>
	</div>
	<?php endif; ?>

	<?php if ($page['footer']): ?>
	<div class="site-footer clearfix">
		<div class="section">
			<?php print render($page['footer']); ?>
		</div>
	</div>
	<?php endif; ?>

	<?php if ($page['footer_post']): ?>
	<div class="site-post-footer">
		<div class="section">
			<?php print render($page['footer_post']); ?>
		</div>
	</div>
	<?php endif; ?>
</div>
