<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_ckan_blocks (datos.gob.es)".
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

?><div class="dge-iniciativas-datos__content">
<ul>
	<li><?php echo '<p class="data-initiatives"><strong>' . $total; ?> <?php echo t('open</strong></p><span class="data-initiatives"><strong>data initiatives</strong></span>'); ?></strong>
		<ul>
         <?php foreach ($initiatives as $initiative): ?>
            <li><strong class="list_number"><?php echo $initiative['total']; ?></strong> <em><?php echo t('from'); ?> <?php echo $initiative['title']; ?></em></li>
         <?php endforeach; ?>
		</ul>
	</li>
</ul>
<p class="dge-ckan-blocks-initiatives-link"><a href="<?php echo url($map_link); ?>" class="dge-ckan-blocks-link"><?php echo t('open map'); ?></a></p>
</div>
