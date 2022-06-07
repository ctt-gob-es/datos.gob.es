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
?>
<div class="dge-iniciativas-datos__content">
<ul>
	<li><strong><?php print $total; ?></strong> <?php print t('initiatives'); ?>...
		<ul>
         <?php foreach ($initiatives as $initiative): ?>
            <li><strong><?php print $initiative['total']; ?></strong> <em><?php print t('from'); ?> <?php print $initiative['title']; ?></em></li>
         <?php endforeach; ?>
		</ul>
	</li>
</ul>
<p class="dge-ckan-blocks-initiatives-link"><a href="<?php print url($map_link); ?>" class="dge-ckan-blocks-link"><?php print t('open map'); ?></a></p>
</div>
