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
 * Default theme implementation to display a single Drupal page while offline.
 *
 * All the available variables are mirrored in html.tpl.php and page.tpl.php.
 * Some may be blank but they are provided for consistency.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 *
 * @ingroup themeable
 */
?>
<!DOCTYPE html>
<html lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>">

<div class="site-page site-page--maintenance">
	<div class="site-header">
		<div class="site-wrapper">
			<h1 class="site-header__logo">
				<?php if (!empty($logo)): ?>
				<a href="<?php print $base_path ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo__link">
					<img src="<?php print $logo; ?>" alt="<?php print $site_name; ?>. <?php print $site_slogan; ?>" />
				</a>
				<?php endif; ?>
			</h1>
		</div>
	</div> <!-- /header -->

	<div class="site-content clearfix">
		<div class="site-wrapper">
			<div class="site-main column" role="main">
				<?php if (!empty($title)): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
				<?php if (!empty($messages)): print $messages; endif; ?>
				<div id="content-content" class="clearfix">
					<?php print $content; ?>
				</div>
			</div>
		</div>
	</div> <!-- /container -->

	<div class="site-footer">
		<div class="site-wrapper">
			<?php if (!empty($footer)): print $footer; endif; ?>
		</div>
	</div> <!-- /footer -->

</div> <!-- /site-page -->
</body>
</html>
