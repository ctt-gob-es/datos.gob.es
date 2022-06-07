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
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php print $fields['field_success_category']->content; ?>
<div class="dge-detail__share"> <strong class="dge-detail__share-title"><?php print t('Share'); ?></strong>
    <?php print $fields['service_links']->content; ?>
</div>
<?php if ($fields['field_success_launch_date']->content) : ?>
    <p class="dge-detail__date">
        <strong><?php print t('Year the company was founded') . ': '; ?></strong>
        <?php print $fields['field_success_launch_date']->content; ?>
    </p>
<?php endif; ?>
<?php if ($fields['field_success_url']->content) : ?>
    <p class="dge-detail__url">
        <strong><?php print t('Company web page') . ': '; ?></strong>
        <?php print $fields['field_success_url']->content; ?>
    </p>
<?php endif; ?>
<?php if ($fields['field_success_app']->content) : ?>
    <p class="dge-detail__url">
        <strong><?php print t('Related application') . ': '; ?></strong>
        <?php print $fields['field_success_app']->content; ?>
    </p>
<?php endif; ?>
<?php if ($fields['field_sender_show_data']->content == 1) : ?>
    <?php if ($fields['field_sender_name']->content) : ?>
        <p class="dge-detail__url">
            <strong><?php print t('Name and surname') . ': '; ?></strong>
            <?php print $fields['field_sender_name']->content; ?>
        </p>
    <?php endif; ?>
    <?php if ($fields['field_sender_email']->content) : ?>
        <p class="dge-detail__url">
            <strong><?php print t('Email') . ': '; ?></strong>
            <?php print $fields['field_sender_email']->content; ?>
        </p>
    <?php endif; ?>
    <?php if ($fields['field_sender_phone']->content) : ?>
        <p class="dge-detail__url">
            <strong><?php print t('Phone') . ': '; ?></strong>
            <?php print $fields['field_sender_phone']->content; ?>
        </p>
    <?php endif; ?>
<?php endif; ?>
<div>
    <?php if ($fields['field_success_image']->content) : ?>
        <div class="dge-detail__img">
            <?php print $fields['field_success_image']->content; ?>
        </div>
    <?php endif; ?>
    <div class="dge-detail__desc clearfix">
        <?php if ($fields['body']->content) : ?>
            <div><?php print $fields['body']->content; ?></div>
        <?php endif; ?>
        <?php if ($fields['field_products_services']->content) : ?>
            <div class="fila-success">
                <p class="purple-bold"><?php print t('Main products and services') . ': '; ?></p><br/>
                <div class="dcha-success"><?php print $fields['field_products_services']->content; ?></div>
            </div>
        <?php endif; ?>
        <?php if ($fields['field_success_key']->content) : ?>
            <div class="fila-success">
                <p class="purple-bold"><?php print t('Key to success') . ': '; ?></p><br/>
                <div class="dcha-success"><?php print $fields['field_success_key']->content; ?></div>
            </div>
        <?php endif; ?>
        <?php if ($fields['field_success_increase']->content) : ?>
            <div class="fila-success">
                <p class="purple-bold"><?php print t('Growth') . ': '; ?></p><br/>
                <div class="dcha-success"><?php print $fields['field_success_increase']->content; ?></div>
            </div>
        <?php endif; ?>
        <?php if ($fields['field_future_plans']->content) : ?>
            <div class="fila-success">
                <p class="purple-bold"><?php print t('Future plans') . ': '; ?></p><br/>
                <div class="dcha-success"><?php print $fields['field_future_plans']->content; ?></div>
            </div>
        <?php endif; ?>
    </div>
</div>
<?php if (
    $fields['field_used_data']->content || $fields['field_success_catalog']->content || $fields['field_company_size']->content || $fields['field_headquarters']->content
    || $fields['field_offices']->content || $fields['field_internationality_grade']->content || $fields['field_clients']->content || $fields['field_marketing_model']->content
    || $fields['field_more_information']->content
) : ?>
    <div class="contenedorcuadrosexito">
        <?php if ($fields['field_used_data']->content || $fields['field_success_catalog']->content) : ?>
            <div class="cuadroscasoexito izda col-md-12">
                <?php if ($fields['field_used_data']->content) : ?>
                    <p class="purple-bold"><?php print t('Data used') . ': '; ?></p><br/>
                    <?php print $fields['field_used_data']->content; ?>
                <?php endif; ?>
                <?php if ($fields['field_success_catalog']->content) : ?>
                    <p class="purple-bold"><?php print t('URL to catalog/s data source') . ': '; ?></p><br/>
                    <?php print $fields['field_success_catalog']->content; ?>
                <?php endif; ?>
            </div>
        <?php endif; ?>
        <?php if ($fields['field_company_size']->content || $fields['field_headquarters']->content || $fields['field_offices']->content || $fields['field_internationality_grade']->content) : ?>
            <div class="cuadroscasoexito dcha col-md-12">
                <?php if ($fields['field_company_size']->content) : ?>
                    <p class="purple-bold"><?php print t('Company size') . ': '; ?></p>
                    <?php print $fields['field_company_size']->content; ?><br/>
                <?php endif; ?>
                <?php if ($fields['field_headquarters']->content) : ?>
                    <p class="purple-bold"><?php print t('Headquarters') . ': '; ?></p><?php print $fields['field_headquarters']->content; ?><br/>
                <?php endif; ?>
                <?php if ($fields['field_offices']->content) : ?>
                    <p class="purple-bold"><?php print t('Offices in') . ': '; ?></p><?php print $fields['field_offices']->content; ?><br/>
                <?php endif; ?>
                <?php if ($fields['field_internationality_grade']->content) : ?>
                    <p class="purple-bold"><?php print t('Level of internalization') . ': '; ?></p> <?php print $fields['field_internationality_grade']->content; ?>
                <?php endif; ?>
            </div>
        <?php endif; ?>
        <?php if ($fields['field_clients']->content) : ?>
            <div class="cuadroscasoexito izda col-md-12">
                <p class="purple-bold"><?php print t('Customers') . ':'; ?></p><br/>
                <?php print $fields['field_clients']->content; ?>
            </div>
        <?php endif; ?>
        <?php if ($fields['field_marketing_model']->content) : ?>
            <div class="cuadroscasoexito dcha col-md-12">
                <p class="purple-bold"><?php print t('Marketing model') . ':'; ?></p><br/>
                <?php print $fields['field_marketing_model']->content; ?>
            </div>
        <?php endif; ?>
        <?php if ($fields['field_more_information']->content) : ?>
            <div class="cuadroscasoexito gen">
                <p class="purple-bold"><?php print t('Further information') . ': '; ?></p><a href="mailto:<?php print $fields['field_more_information']->content; ?>"> <?php print $fields['field_more_information']->content; ?> </a>
            </div>
        <?php endif; ?>
    </div>
<?php endif; ?>

<div class="dge-detail__tags">
    <?php print $fields['field_success_tags']->content; ?>

</div>
<?php print $fields['field_content_related']->content; ?>
<?php print $fields['field_related_content']->content; ?>


