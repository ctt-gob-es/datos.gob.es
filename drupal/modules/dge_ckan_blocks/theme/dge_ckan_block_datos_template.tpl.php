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

?><div class="dge_ckan_block_datos_counter">
   <div class="body-section">
      <div class="counter-section">
         <div class="p p-1">
            <span class="counter counter1"><?php print number_format($counter1,0,',','.'); ?></span>
            <div class="label label1"><?php print t($label1); ?></div>
         </div>
         <div class="p p-2">
            <span class="counter counter2"><?php print number_format($counter2,0,',','.'); ?></span>
            <div class="label label2"><?php print t($label2); ?></div>
         </div>
      </div>
      <div class="img-section">
         <img src="/sites/all/themes/dge_theme/images/logo_datos_distribucion.png" alt="">
      </div>
   </div>
   <div class="footer-section">
      <a class="footer-link" href="<?php print $url ?>"><?php print t($link_label) ?></a>
   </div>
</div>
