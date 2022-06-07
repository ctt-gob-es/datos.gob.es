<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_data_requests (datos.gob.es)".
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

?><div class="request_status_graph">
    <?php foreach ($phases as $k => $phase) : ?>

        <?php if ($k != 0) : ?>

            <div class="arrow-body"></div>
            <div class="arrow-head"></div>
        <?php endif; ?>
        <div class="request_status_phase ">

		<?php if (strpos(url($_GET['q'], array('absolute' => true)), $phase->tid) !==false):
					$active = 'active';
					$color = 'blanco';
				else:
					$active = '';
					$color = 'morado';
		?>
		<?php endif; ?>

		  <?php if (strpos(url($_GET['q'], array('absolute' => true)), '/estado/'.$phase->field_nti_reference_key.'-'.$phase->tid) !==false): ?>
			<a class="request_status_phase_label <?php print $active ?>" href="<?php print url($_GET['q'], array('absolute' => true))?>">
		  <?php else: ?>
			<a class="request_status_phase_label <?php print $active ?>" href="<?php print url($_GET['q'], array('absolute' => true)).'/estado/'.$phase->field_nti_reference_key.'-'.$phase->tid ?>">
		  <?php endif; ?>
                <img title="<?php print str_replace("-", " ", $phase->field_nti_reference_key) ?>" alt="<?php print str_replace("-", " ", $phase->field_nti_reference_key) ?>" class="request_status_phase_icon" src="/sites/all/themes/dge_theme/images/disponibilidad/<?php print $phase->field_nti_reference_key ?>_<?php print $color ?>.png">
                <span class="status_label"><?php print $phase->name ?> </span>
            </a>


            <?php if ($phase->child) : ?>
                <?php if (strpos(url($_GET['q'], array('absolute' => true)), $phase->child->tid) !==false):
						$active_child = 'active';
						$color = 'blanco';
					else:
						$active_child = '';
						$color = 'morado';
				?>
				<?php endif; ?>



                <div class="request_status_phase alternative">
                    <div class="arrow-pre-body"></div>
                    <div class="arrow-body-child"></div>
                    <div class="arrow-head-child"></div>

					<?php if (strpos(url($_GET['q'], array('absolute' => true)), '/estado/'.$phase->child->field_nti_reference_key.'-'.$phase->child->tid) !==false): ?>
						<a class="request_status_phase_label <?php print $active ?>" href="<?php print url($_GET['q'], array('absolute' => true))?>">
					<?php else: ?>
						<a class="request_status_phase_label <?php print $active_child ?>" href="<?php print url($_GET['q'], array('absolute' => true)).'/estado/'.$phase->child->field_nti_reference_key.'-'.$phase->child->tid ?>">
					<?php endif; ?>
					    <img alt=<?php print $phase->child->field_nti_reference_key ?> class="request_status_phase_icon" src="/sites/all/themes/dge_theme/images/disponibilidad/<?php print $phase->child->field_nti_reference_key ?>_<?php print $color ?>.png">
                        <span class="status_label"><?php print $phase->child->name ?> </span>
                    </a>
                </div>
            <?php endif; ?>
        </div>
    <?php endforeach; ?>
</div>

<script>
    var nodes = document.querySelectorAll('.request_status_graph .status_label')


    // for (var i = 0; i < nodes.length; ++i) {
    //    console.log(nodes[i])
    // }
    nodes.forEach(function(el) {
        var new_label=getCount(el.innerHTML.trim())
        if(new_label){
            el.innerHTML = new_label
        }else{
            el.innerHTML = el.innerHTML+'  '

        }
    })

    function getCount(status) {
        status = '<span> ' + status + '</span>'
        var count = null
        document.querySelectorAll('#facetapi-facet-search-apirequest-index-block-field-request-tx-status li  ').forEach(function(el) {
            var index = el.innerHTML.indexOf(status);

            if (index >= 0) {
                var status_index = index
                var status_label = el.innerHTML
                count = status_label.substring(status_index, status_label.length)
                var index_2 = count.indexOf(')');
                count = count.substring(0, index_2+1)


            }
        })
        return count
    }
</script>
