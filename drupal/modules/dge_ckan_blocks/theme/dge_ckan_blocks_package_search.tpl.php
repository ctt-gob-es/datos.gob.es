<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

?>
<?php global $language; ?>
<?php if (empty($packages)): ?>
  <?php print t('No results.'); ?>
<?php else: ?>
  <div class="dge-ckan-blocks-packages">
    <ul>
    <?php foreach ($packages as $package): ?>
      <li class="dge-ckan-blocks-package clearfix">
        <div class="content">
          <div class="dge-ckan-last-datasets-date"><?php print $package['date']->format('d-m-Y') ?></div>
          <div class="dge-ckan-last-datasets-title"><?php if (array_key_exists('language', $package['title']) &&
                        $language->language != $package['title']['language']):
               ?><div lang="es" xml:lang="es"><?php endif;
               ?><a href="<?php print $package['url']?>"><?php print $package['title']['value']?></a><?php
                  if (array_key_exists('language', $package['title']) &&
                        $language->language != $package['title']['language']):
                     ?></div><?php endif; ?></div>
          <div class="dge-ckan-last-datasets-publisher"><span class="dge-ckan-last-datasets-data-title"><?php print t('Published by'); ?>:</span> <?php print $package['organization']?></div>
          <div class="dge-ckan-last-datasets-formats"><span class="dge-ckan-last-datasets-data-title"><?php print t('Format'); ?>:</span> <?php print implode (", ",$package['formats']); ?></div>
        </div>
     </li>
    <?php endforeach; ?>
    </ul>
  </div>
  <div class="read-more">
    <a href="<?php print $ckan_url ?>"><?php print t('View more') ?></a>
  </div>
<?php endif; ?>
