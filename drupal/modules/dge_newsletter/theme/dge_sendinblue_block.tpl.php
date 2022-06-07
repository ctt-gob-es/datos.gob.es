<?php

/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_newsletter (datos.gob.es)".
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

/**
 * Block for SendInBlue on footer page
 */
?>

<div id="boletin">
  <h3><?php print t('Newsletter') ?></h3>
  <p><?php print t('Subscribe to our newsletter to receive the latest news from datos.gob') ?></p>

  <form action="/es/formulario-de-alta" method="get">
       <button title="Suscripción por correo electrónico a las últimas noticias de datos.gob.es.">Suscribir</button>
  </form>

  <p id="baja">
    <?php print t('You can cancel your subscription by') ?>
    <a href="<?php print url('/formulario-de-baja') ?>" title="<?php print t('unsubscribe from the data.gob.es bulletin') ?>"> <?php print t('clicking here') ?></a>
  </p>
</div>
