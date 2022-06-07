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

/**
 * @file recaptcha-widget-noscript.tpl.php
 * Default theme implementation to present the reCAPTCHA noscript code.
 *
 * Available variables:
 * - $sitekey: Google web service site key.
 * - $language: Current site language code.
 * - $url: Google web service API url.
 *
 * @see template_preprocess()
 * @see template_preprocess_recaptcha_widget_noscript()
 */
?>
<noscript>
  <div style="width: 302px; height: 352px;">
    <div style="width: 302px; height: 352px; position: relative;">
      <div style="width: 302px; height: 352px; position: absolute;">
        <iframe src="<?php print $url; ?>" style="width: 302px; height:352px; border-style: none; border: 0;" title="<?php print t('Captcha for validating user authenticity'); ?>"></iframe>
      </div>
      <div style="width: 250px; height: 80px; position: absolute; border-style: none; bottom: 21px; left: 25px; margin: 0px; padding: 0px; right: 25px;">
        <label for="g-recaptcha-response"><?php print t('Response'); ?></label>
        <textarea id="g-recaptcha-response" name="g-recaptcha-response" class="g-recaptcha-response" style="width: 250px; height: 80px; border: 1px solid #c1c1c1; margin: 0px; padding: 0px; resize: none;"></textarea>
      </div>
    </div>
  </div>
</noscript>
