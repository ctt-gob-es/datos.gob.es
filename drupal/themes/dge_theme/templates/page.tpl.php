<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
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
 	* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 	* GNU General Public License for more details.
 	*
 	* You should have received a copy of the GNU General Public License
 	* along with this program. If not, see <http://www.gnu.org/licenses/>.
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


       <div role="banner" class="site-header__banner">

          <!-- LOGO  MINISTERIO -->
					<a href="https://www.mineco.gob.es/" title="<?php print t('Ministry of Economy and Business'); ?>" class="site-header__link">
						<img src="/sites/default/files/gob_maetd_sedia.svg" alt="<?php print t('Go to Ministry of Economy and Business'); ?>" class="site-header__logo" />
					</a>
			</div>
			<div class="site-header__banner_datos">

				<?php if (!empty($logo)) : ?>
					<?php
					$home = url('<front>', array('absolute' => TRUE));
					$home = str_replace('/home', '', $home);
					?>
          <!-- LOGO -->
					<a href="<?php print $home; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-header__link">
						<img src="<?php print $logo; ?>" alt="<?php print $site_name; ?>. <?php print $site_slogan; ?>. <?php print t('Go home') ?>" class="site-header__logo_datos" />
					</a>
				<?php endif; ?>
			</div>
			<?php if ($page['navigation']) : ?>
				<nav class="dge-mobilenav">
					<a href="#dge-user-menu--rwd" class="dge-mobileuser"><img src="<?php print base_path() . path_to_theme(); ?>/images/ico-menu-user-rwd.png" alt=""><span class="element-invisible"> <?php print t('User'); ?></span></a>
					<a href="#dge-search-menu--rwd" class="dge-mobilesearch"><img src="<?php print base_path() . path_to_theme(); ?>/images/ico-menu-search-rwd.png" alt=""><span class="element-invisible"> <?php print t('Search'); ?></span></a>
					<a href="#dge-main-menu--rwd" class="dge-mobilemenu"><img src="<?php print base_path() . path_to_theme(); ?>/images/ico-menu-rwd.png" alt=""><span class="element-invisible"> <?php print t('Menu'); ?></span></a>
				</nav>
			<?php endif; ?>
			<?php if ($page['header']) : ?>
				<div class="site-header__options">
					<?php print render($page['header']); ?>
				</div>
			<?php endif; ?>
		</div>
	</div>
	<!-- NAVIGATION -->
	<div class="site-navigation">
		<div class="site-wrapper">
			<?php if ($page['navigation']) : ?>
				<nav role="navigation" class="main-navigation">
					<?php print render($page['navigation']); ?>
				</nav>
			<?php endif; ?>
			<?php if ($page['sub_navigation']) : ?>
				<div class="sub-navigation">
					<?php print render($page['sub_navigation']); ?>
				</div>
				<?php
				if (module_exists('menu_breadcrumb')) {
					$pagina = dge_theme_get_parent_candidates();
					if (strpos($pagina, 'Petición de datos') != FALSE) {
						$pagina = str_replace('Petición de datos', 'Disponibilidad de datos', $pagina);
					}
					$parts = explode(' | ', $pagina);
					$seccion_s1 = $parts[0];
					$seccion_s2 = $parts[1];
					$seccion_s3 = '';
					if (isset($parts[2])) {
						$seccion_s3 = $parts[2];
						if ($seccion_s3 == 'Petición de datos') {
							$seccion_s3 = 'disponibilidad de datos';
						}
					}
					if ($parts[0] == 'home' && $_GET['q'] == 'organismo/register') {
						$seccion_s2 = 'Cuenta de usuario';
					}
					$seccion_s4 = '';
					if (isset($parts[3])) {
						$seccion_s4 = $parts[3];
					}
					global $language;
					$lang = $language->language;
					global $user;
					$roles = '';
					foreach ($user->roles as $key => $value) {
						if ($value != 'authenticated user') {
							if (empty($roles)) {
								$roles = $value;
							} else {
								$roles .= '|' . $value;
							}
							if ($value == 'anonymous user') {
								if ($lang === 'en') {
									$roles = 'anonymous';
								} else {
									$roles = 'anonimo';
								}
							}
						}
					}
					global $language;
					$lang = $language->language;
					$evento = 'loadComplete';
					$status = drupal_get_http_header("status");
					if ($status == '404 Not Found') {
						$status = 'pagina no encontrada';
					} else {
						$status = '';
					}
					$publicador = '';
					$categorias = '';
					if (arg(0) == 'node') {
						$node_ev = node_load(arg(1));
						if ($node_ev->type == 'bulletin') {
							$categorias = $node_ev->field_bulletin_tags[und];
						} elseif ($node_ev->type == 'blog') {
							$categorias = $node_ev->field_blog_tags[und];
						} elseif ($node_ev->type == 'event') {
							$categorias = $node_ev->field_event_tags[und];
						}
					}
					$contenido_categoria = '';
					if (!empty($categorias)) {
						foreach ($categorias as $key => $value) {
							if (empty($contenido_categoria)) {
								$contenido_categoria = taxonomy_term_load($value['tid'])->name;
								//
							} else {
								$contenido_categoria .= '|' . taxonomy_term_load($value['tid'])->name;
							}
						}
					}
					if ($lang === 'en' || $lang == 'ca' || $lang == 'gl' || $lang == 'eu') {
						$active_trail = menu_get_active_trail();
						$seccion_s4 = $active_trail[4]['title'];
						$seccion_s3 = $active_trail[3]['title'];
						$seccion_s2 = $active_trail[2]['title'];
						$seccion_s1 = $active_trail[1]['title'];
						$pagina = $seccion_s1 . " | " . $seccion_s2;
						if (count($active_trail) === 1) {
							$seccion_s1 = $active_trail[0]['title'];
							$pagina = $seccion_s1;
						}
					}
				?>

					<script>
						get_section_2 = function() {
							return '<?php echo $seccion_s2 ?>';
						}

						function RemoveAccents(strAccents) {
							var strAccents = strAccents.split('');
							var strAccentsOut = new Array();
							var strAccentsLen = strAccents.length;
							var accents = 'ÀÁÂÃÄÅàáâãäåÒÓÔÕÕÖØòóôõöøÈÉÊËèéêëðÇçÐÌÍÎÏìíîïÙÚÛÜùúûüÑñŠšŸÿýŽž';
							var accentsOut = "AAAAAAaaaaaaOOOOOOOooooooEEEEeeeeeCcDIIIIiiiiUUUUuuuuNnSsYyyZz";
							for (var y = 0; y < strAccentsLen; y++) {
								if (accents.indexOf(strAccents[y]) != -1) {
									strAccentsOut[y] = accentsOut.substr(accents.indexOf(strAccents[y]), 1);
								} else
									strAccentsOut[y] = strAccents[y];
							}
							strAccentsOut = strAccentsOut.join('');
							strAccentsOut = strAccentsOut.toLowerCase();
							return strAccentsOut;
						}
						jQuery(document).ready(function() {
							/**
							 * Function to add a datalayer object to events.
							 */
							dataLayer.push({
								'pagina': RemoveAccents('<?php echo $pagina ?>'),
								'seccion_s1': RemoveAccents('<?php echo $seccion_s1 ?>'),
								'seccion_s2': RemoveAccents('<?php echo $seccion_s2 ?>'),
								'seccion_s3': RemoveAccents('<?php echo $seccion_s3 ?>'),
								'seccion_s4': RemoveAccents('<?php echo $seccion_s4 ?>'),
								'tipo_visitante': RemoveAccents('<?php echo $roles ?>'),
								'idioma': RemoveAccents('<?php echo $lang ?>'),
								'pagina_error': RemoveAccents('<?php echo $status ?>'),
								'publicador': '',
								'contenido_categoria': RemoveAccents('<?php echo $contenido_categoria ?>'),
								'event': 'loadComplete'
							});
						});
					</script>
			<?php
				}
			endif; ?>

		</div>
	</div>
	<!-- MESSAGES -->
	<?php if ($messages) : ?>
		<div id="messages" class="site-messages clearfix">
			<div class="site-wrapper">
				<?php print $messages; ?>
			</div>
		</div>
	<?php endif; ?>
	<!-- CONTENT -->
	<main id="main" role="main" class="site-main clearfix">
		<div class="site-wrapper">

			<?php
			$type_node = '';
			if (arg(0) == 'node') {
				$type_node = $node_ev->type;
			}
			?>
			<?php if ($breadcrumb && $type_node !== 'sectores') : ?>
				<div id="breadcrumb" class="dge-breadcrumb"><?php print $breadcrumb; ?></div>
			<?php endif; ?>

			<!-- <?php $term = taxonomy_term_load($fields['field_request_tx_status']->content)->field_facetapi_icon ?>
      <?php if ($term) : ?>
         <img class="dge-list__icon"  src="<?php print file_create_url($term['und'][0]['uri']) ?>">
         <?php endif; ?> -->


			<div id="content" class="site-content">
				<div class="site-content__wrapper">
					<a id="main-content"></a>
					<?php if ($feed_icons) : ?><div class="dge-feeds"><?php print $feed_icons; ?></div><?php endif; ?>
					<?php if ($title && $type_node !== 'sectores') : ?>
						<?php print render($title_prefix); ?>
						<h1 class="page-title" id="page-title">
							<div>
								<?php print t($title); ?>
							</div>
							<?php if ($type_node === 'request') : ?>
								<?php
								$node = node_load(arg(1));
								$counter = $node->field_number_subscriptors['und'][0]['value'];
								?>
								<div>
								<span class="dge-list_counter_solicitantes">
									<img style="width:30px;" class="dge-list_counter_solicitantes-icon" src="/sites/all/themes/dge_theme/images/Solicitantes.png" alt="">

									<span style="font-size:1.4rem;" class="dge-list_counter_solicitantes-counter"><?php print $counter ? $counter : '0' ?></span>&nbsp;
									<span style="font-size:1.4rem;">
										<?php print t('requesters'); ?></span>
								</span>
								</div>
							<?php endif; ?>

						</h1>
						<?php print render($title_suffix); ?>
					<?php endif; ?>
					<?php if ($tabs) : ?>
						<div class="tabs">
							<?php print render($tabs); ?>
						</div>
					<?php endif; ?>
					<?php print render($page['content']); ?>
				</div>
			</div>

			<?php if ($page['sidebar_first']) : ?>
				<aside id="sidebar-first" class="site-sidebar" role="complementary">
					<div class="section">
						<?php print render($page['sidebar_first']); ?>
					</div>
				</aside>
			<?php endif; ?>

			<?php if ($page['sidebar_second']) : ?>
				<aside id="sidebar-second" class="site-sidebar--alt">
					<div class="section">
						<?php print render($page['sidebar_second']); ?>
					</div>
				</aside>
			<?php endif; ?>
		</div>
	</main>
	<!-- FOOTER -->
	<?php if ($page['footer_pre_iniciativas']) : ?>
		<div class="site-pre-footer-iniciativas">
			<div class="section">
				<?php print render($page['footer_pre_iniciativas']); ?>
			</div>
		</div>
	<?php endif; ?>

	<?php if ($page['footer_pre']) : ?>
		<div class="site-pre-footer">
			<div class="section">
				<?php print render($page['footer_pre']); ?>
			</div>
		</div>
	<?php endif; ?>

	<?php if ($page['footer']) : ?>
		<div class="site-footer clearfix">
			<div class="section">
				<?php print render($page['footer']); ?>
			</div>
		</div>
	<?php endif; ?>

	<?php if ($page['footer_post']) : ?>
		<div class="site-post-footer">
			<div class="section">
				<?php print render($page['footer_post']); ?>
			</div>
		</div>
	<?php endif; ?>
	<?php if ($page['footer_post_companies']) : ?>
		<div class="site-post-footer-companies">
			<div class="section">
				<?php print render($page['footer_post_companies']); ?>
			</div>
		</div>
	<?php endif; ?>

</div>
