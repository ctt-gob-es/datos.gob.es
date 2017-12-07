<?php

/**
 * Copyright (C) 2017 Entidad Pública Empresarial Red.es
 * 
 * This file is part of "dgef_comment (datos.gob.es)".
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

/**
 * @file
 * dgef_comment.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dgef_comment_default_rules_configuration() {
  $items = array();
  $items['rules_after_create_comment_send_'] = entity_import('rules_config', '{ "rules_after_create_comment_send_" : {
      "LABEL" : "After create comment send mail author",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_i18n", "comment" ],
      "ON" : { "comment_insert" : [] },
      "DO" : [
        { "mail" : {
            "to" : "[comment:node:author:mail]",
            "subject" : "Nuevo comentario pendiente de aprobaci\\u00f3n en [site:name]",
            "message" : "Nuevo comentario pendiente de aprobaci\\u00f3n en \\r\\n[comment:node:title]\\r\\n\\r\\nAdministraci\\u00f3n de comentarios:\\r\\n[site:url]\\/admin\\/dashboard\\/comment\\/approval\\r\\n\\r\\nAutor: [comment:name]\\r\\nMensaje:\\r\\n[comment:body]",
            "language" : [ "" ]
          }
        },
        { "mail" : {
            "to" : "contacto@datos.gob.es",
            "subject" : "Nuevo comentario pendiente de aprobaci\\u00f3n en [site:name]",
            "message" : "Nuevo comentario pendiente de aprobaci\\u00f3n en \\r\\n[comment:node:title]\\r\\n\\r\\nAdministraci\\u00f3n de comentarios:\\r\\n[site:url]\\/admin\\/dashboard\\/comment\\/approval\\r\\n\\r\\nAutor: [comment:name]\\r\\nMensaje:\\r\\n[comment:body]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_dge_comment_approve_message'] = entity_import('rules_config', '{ "rules_dge_comment_approve_message" : {
      "LABEL" : "After approving comment send mail author",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_i18n", "comment" ],
      "ON" : { "comment_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "comment:status" ], "value" : "1" } },
        { "data_is" : { "data" : [ "comment-unchanged:status" ], "value" : "0" } },
        { "NOT user_has_role" : {
            "account" : [ "comment:author" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[comment:mail]",
            "subject" : "Se ha aprobado tu comentario del contenido \\u0022[comment:node:title]\\u0022 en datos.gob.es",
            "message" : "Estimado,\\r\\nse ha aprobado tu comentario del contenido \\u0022[comment:node:title]\\u0022. Puedes acceder al comentario mediante la URL [comment:node:url].\\r\\n\\r\\nSaludos cordiales,\\r\\n\\r\\ndatos.gob.es\\r\\nMinisterio de Energ\\u00eda, Turismo y Agenda Digital \\r\\nMinisterio de Hacienda y Funci\\u00f3n P\\u00fablica",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_dge_comment_organization_response'] = entity_import('rules_config', '{ "rules_dge_comment_organization_response" : {
      "LABEL" : "After organization response send mail author",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_i18n", "comment" ],
      "ON" : { "comment_insert" : [] },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "comment:parent" ] } },
        { "user_has_role" : {
            "account" : [ "comment:author" ],
            "roles" : { "value" : { "6" : "6" } }
          }
        },
        { "data_is" : {
            "data" : [ "comment:author:profile-agency-data:field-root-agency:tid" ],
            "value" : [ "comment:node:author:profile-agency-data:field-root-agency:tid" ]
          }
        },
        { "NOT data_is" : {
            "data" : [ "comment:author:uid" ],
            "value" : [ "comment:parent:author:uid" ]
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[comment:parent:mail]",
            "subject" : "Un organismo ha respondido a tu comentario del contenido \\u0022[comment:node:title]\\u0022 en datos.gob.es",
            "message" : "Estimado,\\r\\ntu comentario sobre \\u0022[comment:node:title]\\u0022 ha recibido una respuesta del organismo responsable. Puedes verla en la URL [comment:node:url].\\r\\n\\r\\nSaludos cordiales,\\r\\n\\r\\ndatos.gob.es\\r\\nMinisterio de Energ\\u00eda, Turismo y Agenda Digital \\r\\nMinisterio de Hacienda y Funci\\u00f3n P\\u00fablica",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
