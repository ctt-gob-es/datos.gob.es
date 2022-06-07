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
// kpr($fields);

?>

<style>
    .request_status_graph {
        display: flex;
        align-items: center;
        padding: 0 30px;
        padding-bottom: 80px;
        margin-top: 50px;
        justify-content: center;
    }

    .request_status_phase {
        display: flex;
        align-items: center;
        position: relative;
    }

    .request_status_phase.naranja {
        color: #E05307;
    }

    .request_status_phase.gris {
        color: #757575;
    }

    .request_status_phase.morado {
        color: #6E2585;
    }

    .request_status_phase_item {
        display: flex;
        flex-direction: column;
        align-items: center;
        position: relative;
    }

    .request_status_phase_label {
        white-space: nowrap;
        text-transform: uppercase;
        position: absolute;
        top: -35px;


    }
    .alternative .request_status_phase_label{
        width: 90px;
        white-space: break-spaces;
    }

    .request_status_phase_icon {}

    .request_status_phase_icon img {
        width: 30px;

    }

    .request_status_phase_icon div {
        border: 3px solid #333;
        border-radius: 500px;
        padding: 7px;
        width: 30px;
        height: 30px;
    }

    .request_status_phase.naranja .request_status_phase_icon div {
        border-color: #E05307 !important;
    }

    .request_status_phase.gris .request_status_phase_icon div {
        border-color: #757575 !important;
    }

    .request_status_phase.morado .request_status_phase_icon div {
        border-color: #6E2585 !important;
        border-width: 4px;
    }

    .request_status_connector {
        width: 150px;
        border-top: 3px solid #757575;
    }

    .request_status_connector_child {
        width: 50px;
        border-top: 3px solid #757575;
    }

    .request_status_connector_pre_child {
        height: 59px;
        border-right: 3px solid #757575;
        position: absolute;
        top: -34px;
    }

    .request_status_phase.naranja .request_status_connector {
        border-color: #E05307;
    }

    .request_status_phase.gris .request_status_connector {
        border-color: #757575;
    }

    .request_status_phase.morado .request_status_connector {
        border-color: #757575;
    }

    /* child */
    .request_status_phase.alternative.naranja>.request_status_connector_child,
    .request_status_phase.alternative.naranja .request_status_connector_pre_child {
        border-color: #E05307;
    }

    .request_status_phase.alternative.gris>.request_status_connector_child,
    .request_status_phase.alternative.gris .request_status_connector_pre_child {
        border-color: #757575;

    }

    .request_status_phase.alternative.morado>.request_status_connector_child,
    .request_status_phase.alternative.morado .request_status_connector_pre_child {
        border-color: #E05307;
    }

    .request_status_phase.alternative.naranja .request_status_phase_icon div {
        border-color: #E05307 !important;
    }

    .request_status_phase.alternative.gris .request_status_phase_icon div {
        border-color: #757575 !important;
        border-width: 3px;
    }

    .request_status_phase.alternative.morado .request_status_phase_icon div {
        border-color: #6E2585 !important;
        border-width: 4px;
    }



    .request_status_phase .alternative {
        position: absolute;
        top: 60px;
        left: -50px;
    }
    .request_status_phase:last-child .alternative {
        position: absolute;
        top: 60px;
        left: -50px;
    }
    .request_status_phase .alternative .request_status_phase_item {
        /* display: block; */
    }

    .request_status_phase .alternative .request_status_phase_label {
        text-transform: capitalize;
        top: 12px;
        left: 55px;
        font-size: 13px;

    }

    @media (max-width: 1199.98px) {
        .request_status_connector {
            width: 100px;

        }

        .request_status_connector_child {
            width: 30px;

        }
    }

    @media (max-width: 991.98px) {
        .request_status_phase_label {
            display: none;
        }

        .request_status_connector {
            width: 30px;

        }

        .request_status_connector_child {
            width: 20px;

        }

        .request_status_phase_icon img,
        .request_status_phase_icon div {
            width: 20px;
            height: 20px;
        }

        .request_status_phase .alternative {
            left: -20px !important;
            top: 50px !important;
        }

        .request_status_connector_pre_child {
            height: 50px;

            top: -31px;
        }

    }
</style>
<?php print $fields['service_links-revision_id']->wrapper_prefix; ?>
<?php print $fields['service_links-revision_id']->label_html; ?>
<?php print $fields['service_links-revision_id']->content; ?>
<?php print $fields['service_links-revision_id']->wrapper_suffix; ?>
<?php print $fields['field_request_category-revision_id']->wrapper_prefix; ?>
<?php print $fields['field_request_category-revision_id']->label_html; ?>
<?php print $fields['field_request_category-revision_id']->content; ?>
<?php print $fields['field_request_category-revision_id']->wrapper_suffix; ?>
<!-- $nid = arg(1);
print $nid; -->

<?php // kpr(request_states_graph_phases_detail($fields['field_request_tx_status']->content));
?>
<?php $phases = request_states_graph_phases_detail($fields['field_request_tx_status-revision_id']->content) ?>
<div class="request_status_graph">

    <?php foreach ($phases as $k => $phase) : ?>
        <div class="request_status_phase <?php print $phase->phase ?>">
            <div class="request_status_phase_item">
                <span class="request_status_phase_label"><?php print $phase->name ?> </span>
                <div class="request_status_phase_icon">
                    <div>
                        <img src="/sites/all/themes/dge_theme/images/disponibilidad/<?php print $phase->field_nti_reference_key ?>_<?php print $phase->phase ?>.png">
                    </div>
                </div>
            </div>
            <?php if (!((sizeof($phases) - 1) == $k)) : ?>
                <div class="request_status_connector"></div>
            <?php endif; ?>
            <?php if ($phase->child) : ?>
                <div class="request_status_phase alternative <?php print $phase->child->phase ?>">
                    <div class="request_status_connector_pre_child"></div>

                    <div class="request_status_connector_child"></div>

                    <div class="request_status_phase_item">
                        <div class="request_status_phase_label"><?php print $phase->child->name ?> </div>
                        <div class="request_status_phase_icon">
                            <div>
                                <img src="/sites/all/themes/dge_theme/images/disponibilidad/<?php print $phase->child->field_nti_reference_key ?>_<?php print $phase->child->phase ?>.png">
                            </div>
                        </div>
                    </div>




                </div>
            <?php endif; ?>
        </div>

    <?php endforeach; ?>
</div>

<div class="page_content_card">
    <div class="page_content_card_header">
        <div class="page_content_card_header_right">
            <?php print $fields['created-revision_id']->wrapper_prefix; ?>
            <?php print $fields['created-revision_id']->label_html; ?>
            <?php print $fields['created-revision_id']->content; ?>
            <?php print $fields['created-revision_id']->wrapper_suffix; ?>
            <?php print $fields['field_organismo_pub-revision_id']->wrapper_prefix; ?>
            <?php print $fields['field_organismo_pub-revision_id']->label_html; ?>
            <?php print $fields['field_organismo_pub-revision_id']->content; ?>
            <?php print $fields['field_organismo_pub-revision_id']->wrapper_suffix; ?>
        </div>
        <div style="flex-shrink:0" class="page_content_card_header_left">
            <a href="<?php print url('/unirse-a-peticiones-datos/' . $row->nid,array('absolute'=>true)) ?>" class="primary_button">
                <img style="width:30px;vertical-align:middle;" class="dge-list_counter_solicitantes-icon" src="/sites/all/themes/dge_theme/images/solicitantes_blanco.png" alt="">
                <span>

                    <?php print t('Join the request'); ?>
                </span>
            </a>
        </div>
        <div style="flex-shrink:0" class="page_content_card_header_left container__second__button page_content_card_secundary">
            <a href="<?php print url('/desunirse-a-peticiones-datos/' . $row->nid,array('absolute'=>true)) ?>" class="secundary_button">
                <span class="span-icon-exit-request dge-list_counter_solicitantes-icon-left-request"></span>
                <span>
                    <?php print t('Leave the request'); ?>
                </span>
            </a>
        </div>
    </div>
    <div class="page_content_card_body">
        <div class="purple_column"></div>
        <div class="field_request_body">
            <div class="field_request_body_wrapper">

                <?php echo $fields['body-revision_id']->wrapper_prefix; ?>
                <?php echo $fields['body-revision_id']->label_html; ?>
                <?php echo $fields['body-revision_id']->content; ?>
                <?php echo $fields['body-revision_id']->wrapper_suffix; ?>
                <?php if ($fields['field_request_long_reason-revision_id']->content) : ?>
                    <?php echo $fields['field_request_long_reason-revision_id']->wrapper_prefix; ?>
                    <?php echo $fields['field_request_long_reason-revision_id']->label_html; ?>
                    <?php echo $fields['field_request_long_reason-revision_id']->content; ?>
                    <?php echo $fields['field_request_long_reason-revision_id']->wrapper_suffix; ?>
                <?php endif; ?>
                <?php if ($fields['field_request_long_benefit-revision_id']->content) : ?>
                    <?php print $fields['field_request_long_benefit-revision_id']->wrapper_prefix; ?>
                    <?php print $fields['field_request_long_benefit-revision_id']->label_html; ?>
                    <?php print $fields['field_request_long_benefit-revision_id']->content; ?>
                    <?php print $fields['field_request_long_benefit-revision_id']->wrapper_suffix; ?>
                <?php endif; ?>
            </div>
        </div>
    </div>

</div>
<?php if ($fields['field_request_answer-revision_id']->content) : ?>

    <div style="height:40px"></div>
    <div class="page_content_card dark">
        <div class="page_content_card_body">
            <div class="field_request_body">

                <?php echo $fields['field_request_answer-revision_id']->wrapper_prefix; ?>
                <?php echo $fields['field_request_answer-revision_id']->label_html; ?>
                <?php echo $fields['field_request_answer-revision_id']->content; ?>
                <?php echo $fields['field_request_answer-revision_id']->wrapper_suffix; ?>
            </div>
        </div>
    </div>
<?php endif; ?>

<div style="height:40px"></div>

<div class="view-view-field-divider"></div>
<div style="height:40px"></div>
