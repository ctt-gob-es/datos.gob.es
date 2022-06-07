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

?><div class="dge-datacatalog dge-nti-categories">
  <ul class="dataset-categories dataset-categories-full">
    <?php foreach ($categories as $category): ?>
      <li><a class="label <?php print $category['key'];?>" href="<?php print $category['link'];?>"><p><?php print $category['label'];?></p><span>(<?php print $category['total'];?>)</span></a></li>
    <?php endforeach; ?>
  </ul>
</div>
