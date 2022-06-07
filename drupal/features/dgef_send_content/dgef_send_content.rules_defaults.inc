<?php
/**
* Copyright (C) 2022 Entidad Pública Empresarial Red.es
* 
* This file is part of "dgef_send_content (datos.gob.es)".
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
 * dgef_send_content.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dgef_send_content_default_rules_configuration() {
  $items = array();
  $items['dgef_send_content_after_create_content_request_mail_to_editors'] = entity_import('rules_config', '{ "dgef_send_content_after_create_content_request_mail_to_editors" : {
      "LABEL" : "After create content request send mail to editors",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "dge_send_content" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--request" : { "bundle" : "request" } },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5", "6" : "6" } },
            "subject" : "Creado nueva petici\\u00f3n de datos",
            "message" : "[node:title]\\r\\n[node:edit-url]\\r\\n\\r\\n"
          }
        }
      ]
    }
  }');
  $items['dgef_send_content_after_create_content_request_redirects'] = entity_import('rules_config', '{ "dgef_send_content_after_create_content_request_redirects" : {
      "LABEL" : "After create content request redirects",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_i18n" ],
      "ON" : { "node_insert--request" : { "bundle" : "request" } },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Gracias por realizar su petici\\u00f3n de datos" } },
        { "redirect" : { "url" : "informa-sobre\\/peticion-datos" } }
      ]
    }
  }');
  $items['dgef_send_content_after_create_content_success_mail_to_editors'] = entity_import('rules_config', '{ "dgef_send_content_after_create_content_success_mail_to_editors" : {
      "LABEL" : "After create content success send mail to editors",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "dge_send_content" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--success" : { "bundle" : "success" } },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5", "6" : "6" } },
            "subject" : "Creado nuevo caso de \\u00e9xito",
            "message" : "[node:title]\\r\\n[node:edit-url]\\r\\n\\r\\n"
          }
        }
      ]
    }
  }');
  $items['dgef_send_content_after_create_content_success_redirects'] = entity_import('rules_config', '{ "dgef_send_content_after_create_content_success_redirects" : {
      "LABEL" : "After create content success redirects",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_i18n" ],
      "ON" : { "node_insert--success" : { "bundle" : "success" } },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Gracias por enviar su caso de \\u00e9xito" } },
        { "redirect" : { "url" : "informa-sobre\\/casos-exito" } }
      ]
    }
  }');
  $items['dgef_send_content_after_create_request_mail_to_author'] = entity_import('rules_config', '{ "dgef_send_content_after_create_request_mail_to_author" : {
      "LABEL" : "After create content request send mail to sender user",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "dge_send_content" ],
      "REQUIRES" : [ "rules", "rules_i18n" ],
      "ON" : { "node_insert--request" : { "bundle" : "request" } },
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
            "subject" : "Gracias por enviar tu petici\\u00f3n de datos",
            "message" : "Mensaje de agradecimiento",
            "from" : "[site:mail]",
            "language" : [ "site:current-user:language" ]
          }
        }
      ]
    }
  }');
  $items['dgef_send_content_after_create_success_mail_to_author'] = entity_import('rules_config', '{ "dgef_send_content_after_create_success_mail_to_author" : {
      "LABEL" : "After create content success send mail to sender user",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "dge_send_content" ],
      "REQUIRES" : [ "rules", "rules_i18n" ],
      "ON" : { "node_insert--success" : { "bundle" : "success" } },
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
            "subject" : "Gracias por enviar tu caso de \\u00e9xito",
            "message" : "Mensaje de agradecimiento",
            "from" : "[site:mail]",
            "language" : [ "site:current-user:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_after_create_content_app_redirects'] = entity_import('rules_config', '{ "rules_after_create_content_app_redirects" : {
      "LABEL" : "After create content app redirects",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_i18n" ],
      "ON" : { "node_insert--app" : { "bundle" : "app" } },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "Gracias por enviar su aplicaci\\u00f3n" } },
        { "redirect" : { "url" : "aplicaciones" } }
      ]
    }
  }');
  $items['rules_after_create_content_app_send_mail_to_editors'] = entity_import('rules_config', '{ "rules_after_create_content_app_send_mail_to_editors" : {
      "LABEL" : "After create content app send mail to editors",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "dge_send_content" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--app" : { "bundle" : "app" } },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5" } },
            "subject" : "Creada nueva aplicaci\\u00f3n",
            "message" : "[node:title]\\r\\n[node:edit-url]\\r\\n\\r\\n"
          }
        }
      ]
    }
  }');
  $items['rules_after_create_content_app_send_mail_to_sender_user'] = entity_import('rules_config', '{ "rules_after_create_content_app_send_mail_to_sender_user" : {
      "LABEL" : "After create content app send mail to sender user",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "dge_send_content" ],
      "REQUIRES" : [ "rules", "rules_i18n" ],
      "ON" : { "node_insert--app" : { "bundle" : "app" } },
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
            "subject" : "Gracias por enviar tu aplicaci\\u00f3n",
            "message" : "Mensaje de agradecimiento",
            "from" : "[site:mail]",
            "language" : [ "site:current-user:language" ]
          }
        }
      ]
    }
  }');
  $items['rules_after_reassigning_data_request'] = entity_import('rules_config', '{ "rules_after_reassigning_data_request" : {
      "LABEL" : "After re-assigning data request",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_i18n" ],
      "ON" : { "node_update--request" : { "bundle" : "request" } },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "node:author:uid" ],
            "value" : [ "node-unchanged:author:uid" ]
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author:mail]",
            "subject" : "[datos.gob.es] Se te ha asignado una petici\\u00f3n de datos",
            "message" : "[node:title]\\r\\n[node:edit-url]\\r\\n",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
