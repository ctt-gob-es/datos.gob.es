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

?><style>
.dge_ckan_small_color_block{
    color: <?php echo $color; ?>;

    text-align:center;
    padding:1rem;
    line-height:1.4rem;
    font-weight:bold;

}
.color_blocks_region > div > div:first-child  .dge_ckan_small_color_block{
    margin-bottom:12px;
}
.dge_ckan_small_color_block_label{
font-size: 1.5rem;
display: block;
}
.dge_ckan_small_color_block_img{
    height: 110px;
}
</style>

<div style=" background-color:<?php echo $backgroundColor; ?>;  box-shadow: 0 0 0 1px #FFF,0 0 0 2px <?php echo $backgroundColor; ?>;"  class="dge_ckan_small_color_block">
<img class="dge_ckan_small_color_block_img" src="/sites/all/themes/dge_theme/images/<?php print $image_path?>" alt="">

<span class="dge_ckan_small_color_block_label">  <?php echo number_format($total,2,',','.'); ?> <?php echo $label1; ?></span>
<span class="dge_ckan_small_color_block_label">    <?php echo $label2; ?></span>
</div>
