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
<?php $ops = explode('|||', $output); ?>
<?php if(isset($ops[0]) && isset($ops[1])): ?>
	<?php if ($ops[0] == 1): ?>
		<?php
			$info = field_info_instance('node','field_sender_name','success');
		?>
		<p class="dge-detail__data"><strong><?php print $info['label']; ?>:</strong> <span><?php print $ops[1]; ?></span></p>
	<?php else: ?>
		<!-- User no data. -->
	<?php endif; ?>
<?php else: ?>
	<!-- User no fields content. -->
<?php endif; ?>