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

?>
<?php if (empty($tweets)): ?>
	<p class="dge-twitter__msg"><?php print t('Sorry, twitter is currently unavailable.'); ?></p>
<?php else: ?>
	<ul class="dge-twitter__lst bxslider">
    <?php foreach ($tweets as $tweet): ?>
		<li class="dge-twitter__elm">
			<?php if ($settings['dge_twitter_block_avatar'] == 'icon'): ?>
			<i class="fa fa-twitter left"></i>
			<?php elseif ($settings['dge_twitter_block_avatar'] == 'profile'): ?>
			<span class="dge-twitter__sp-avatar"><img src="<?php print $tweet->avatar; ?>" alt=""></span>
			<?php endif; ?>
			<span class="dge-twitter__content">
				<span class="dge-twitter__author">
					<span class="sp-user">
						<a target="_blank" href="http://www.twitter.com/<?php print $settings['dge_twitter_block_screen_name']; ?>" style="text-decoration: none;"><?php print $tweet->name; ?></a>
					</span>
					<span class="sp-created" style="font-size: smaller;">(<?php print $tweet->created; ?>)</span>
				</span>
				<span class="dge-twitter__sp-text"><?php print $tweet->text; ?></span>
			</span>
		</li>
    <?php endforeach; ?>
	</ul>
<?php endif; ?>