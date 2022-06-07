<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_initiative (datos.gob.es)".
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
 * dgef_initiative.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dgef_initiative_default_rules_configuration() {
  $items = array();
  $items['dgef_send_content_after_creat_content_initiative_mail_2_editors'] = entity_import('rules_config', '{ "dgef_send_content_after_creat_content_initiative_mail_2_editors" : {
      "LABEL" : "After create content initiative send mail to editors",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "dge_send_content" ],
      "REQUIRES" : [ "rules", "rules_i18n" ],
      "ON" : { "node_insert--initiative" : { "bundle" : "initiative" } },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "ralconada@localhost.org",
            "subject" : "Creada nueva iniciativa",
            "message" : "Estimado, \\r\\nSe ha creado una nueva iniciativa en la plataforma datos.gob.es, [node:title], para consultar los datos de la misma por favor acceda a: [node:url]\\r\\n\\r\\nSaludos cordiales,\\r\\n\\r\\ndatos.gob.es \\r\\nMinisterio de Energ\\u00eda, Turismo y Agenda Digital \\r\\nMinisterio de Hacienda y Funci\\u00f3n P\\u00fablica",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['dgef_send_content_after_new_initiative_ops_del'] = entity_import('rules_config', '{ "dgef_send_content_after_new_initiative_ops_del" : {
      "LABEL" : "After create content initiative mail to sender and unpublish",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "dge_send_content" ],
      "REQUIRES" : [ "rules", "rules_i18n" ],
      "ON" : { "node_insert--initiative" : { "bundle" : "initiative" } },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:field-sender-email]",
            "subject" : "Gracias por enviar tu iniciativa",
            "message" : "Gracias por colaborar con datos.gob.es.\\r\\n\\r\\nSaludos cordiales,\\r\\n\\r\\ndatos.gob.es \\r\\nMinisterio de Energ\\u00eda, Turismo y Agenda Digital \\r\\nMinisterio de Hacienda y Funci\\u00f3n P\\u00fablica",
            "from" : "[site:mail]",
            "language" : [ "site:current-user:language" ]
          }
        },
        { "node_unpublish" : { "node" : [ "node" ] } }
      ]
    }
  }');
  return $items;
}
