# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge_archiver (datos.gob.es)".
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

import logging
import os
import time
import smtplib
import json
from datetime import datetime
from email.mime.text import MIMEText
from ckan.lib.mailer import MailerException
import ckan.model as model
import paste.deploy.converters
from ckan.model.group import Group
from ckan.plugins import toolkit
from ckanext.dge_archiver.model import CheckGroupArchiver
from ckanext.report.model import DataCache
from email.MIMEMultipart import MIMEMultipart
from pylons import config

log = logging.getLogger(__name__)


def dge_archiver_group_to_check(groups_to_check):
    log.debug('DENTRO DE dge_archiver_group_to_check')

    groups_to_check_ids = []
    for name in groups_to_check:
        group = Group.search_by_name_or_title(name, is_org=True).first()
        if group:
            groups_to_check_ids.append(group.id)
    log.debug('group_list:')
    log.debug(groups_to_check_ids)

    groups_archiver = CheckGroupArchiver.all()

    groups_archiver_ids = []
    for g in groups_archiver:
        groups_archiver_ids.append(g.group_id)
        g.checkeable = False
        log.debug("Checkeable a FALSE")
    log.debug('all_group_id:')
    log.debug(groups_archiver_ids)

    for org in groups_to_check_ids:
        if org in groups_archiver_ids:
            log.debug("Organization in DB")
        else:
            CheckGroupArchiver.add_org(org)

    for o in groups_archiver:
        if o.group_id in groups_to_check_ids:
            o.checkeable = True
            log.debug("Checkeable a TRUE")

    CheckGroupArchiver.commit()


def dge_archiver_get_checkeable_groups():
    check_groups = CheckGroupArchiver.all()
    result = []

    for check_group in check_groups:
        if check_group.checkeable:
            group = Group.get(check_group.group_id)
            if group is not None:
                result.append(group.name)

    return result


def dge_archiver_check_broken_links(context):
    context.log.debug('DENTRO DE dge_archiver_check_broken_links')
    method_log_prefix = '[%s][[dge_archiver_check_broken_links]' % __name__
    context.log.debug('%s Init method.' % (method_log_prefix))

    organizations = CheckGroupArchiver.all()
    group_ids = [o.group_id for o in organizations if o.checkeable]

    for id in group_ids:
        cmd = '/usr/lib/ckan/default/bin/paster --plugin=ckanext-archiver archiver update ' + id + ' -c /etc/ckan/default/production.ini'
        os.system(cmd)
        time.sleep(1)  # to try to avoid machine getting overloaded


def dge_archiver_report_email_finished(context):
    context.log.debug('DENTRO DE dge_report_email_finished')
    method_log_prefix = '[%s][dge_report_email_finished]' % __name__
    context.log.debug('%s Init method.' % (method_log_prefix))
    # REVISAR SI ES NECESARIO ESTO
    # toolkit.check_access('dge_harvest_source_email_job_finished', context, data_dict)
    # model = context['model']

    #organizations = model.Group.all()
    #solo organismos seleccionados
    organizations = CheckGroupArchiver.all()
    result = []

    for check_group in organizations:
        if check_group.checkeable:
            group = Group.get(check_group.group_id)
            if group is not None:
                result.append(group)

    organizations = result

    for organization in organizations:
        object_id = organization.name
        key = 'broken-links?organization=%s&include_sub_organizations=0' % (object_id)

        value, created = DataCache.get(object_id, key, convert_json=True)
        if value is None or created is None:
            raise NotFound
        # If the report for this org is not from today continues with the next one
        if created.strftime('%d-%m-%Y') != datetime.today().strftime('%d-%m-%Y'):
            continue
        # If the report for this org has no broken packages/resources continues with the next one
        if value['num_broken_packages'] == 0 and value['num_broken_resources'] == 0:
            continue

        message, mail_to, mail_ccs, mail_bccs = dge_archiver_buildmail(organization, model, context)
        context.log.debug('mail_to: %s mail_ccs: %s mail_bccs: %s' % (mail_to, mail_ccs, mail_bccs))
        try:
            _dge_archiver_send_email(message['From'], (mail_to + mail_ccs), message)
            context.log.debug('ENVIO CORRE0')
        except MailerException, e:
            msg = '%r' % e
            log.exception('%s Exception sending email.' % (method_log_prefix))
        finally:
            log.debug('%s End method.' % (method_log_prefix))


def dge_archiver_buildmail(organization, model, context):
    # model = context['model']

    context.log.debug(organization.id)

    members = toolkit.get_action('member_list')(
        data_dict={'id': organization.id, 'table_name': 'user', 'capacity': 'editor', 'state': 'active'})
    if members is None:
        raise NotFound

    # To
    mail_to = []
    for member in members:
        user = model.User.get(member[0])
        if user.state == 'active' and user.email and len(user.email) > 0:
            mail_to.append(user.email)
    # From
    mail_from = config.get('smtp.mail_from', None)
    # CC
    mail_ccs = config.get('smtp.mail_cc', '').split(' ')
    # BCC
    mail_bccs = config.get('smtp.mail_bcc', '').split(' ')
    # Reply-To
    mail_reply_to = config.get('smtp.mail_reply_to', None)
    # Subject
    subject = u'Enlaces rotos entre sus conjuntos de datos (%s)' % (config.get('ckan.site_title', 'datos.gob.es'))
    # Body
    url_report = config.get('ckan.site_url') + "/report/broken-links/" + organization.name;
    url_report = url_report.replace("http://", "https://")
    mail_body = u"""En el informe realizado el %s sobre el estado de las distribuciones de sus conjuntos de datos, se han detectado enlaces rotos publicados en el cat\u00E1logo de datos.gob.es. Por favor, rev\u00EDselos a trav\u00E9s del siguiente enlace %s\n---\nMessage sent by %s (%s)
                """ % (datetime.today().strftime('%d/%m/%Y'), url_report, config.get('ckan.site_title', 'datos.gob.es'),
                       config.get('ckan.site_url'))
    msg = MIMEMultipart()
    if mail_from:
        msg['From'] = mail_from
    if mail_reply_to:
        msg['Reply-To'] = mail_reply_to
    if mail_to and len(mail_to) > 0:
        msg['To'] = ", ".join(mail_to)
    if mail_ccs and len(mail_ccs) > 0:
        msg['Cc'] = ", ".join(mail_ccs)
    if mail_bccs and len(mail_bccs) > 0:
        msg['Bcc'] = ", ".join(mail_bccs)
    msg['Subject'] = subject
    msg.attach(MIMEText(mail_body.encode('utf-8'), 'plain', 'utf-8'))

    return msg, mail_to, mail_ccs, mail_bccs


def _dge_archiver_send_email(from_addr, to_addrs, msg):
    log.info("Sending email from {0} to {1}".format(from_addr, to_addrs))
    # Send the email using Python's smtplib.
    smtp_connection = smtplib.SMTP()
    # smtp_connection.set_debuglevel(1) descomentar para pruebas
    if 'smtp.test_server' in config:
        # If 'smtp.test_server' is configured we assume we're running tests,
        # and don't use the smtp.server, starttls, user, password etc. options.
        smtp_server = config['smtp.test_server']
        smtp_starttls = False
        smtp_user = None
        smtp_password = None
    else:
        smtp_server = config.get('smtp.server', 'localhost')
        smtp_starttls = paste.deploy.converters.asbool(
            config.get('smtp.starttls'))
        smtp_user = config.get('smtp.user')
        smtp_password = config.get('smtp.password')
    smtp_connection.connect(smtp_server)
    try:
        # smtp_connection.set_debuglevel(True)

        # Identify ourselves and prompt the server for supported features.
        smtp_connection.ehlo()

        # If 'smtp.starttls' is on in CKAN config, try to put the SMTP
        # connection into TLS mode.
        if smtp_starttls:
            if smtp_connection.has_extn('STARTTLS'):
                smtp_connection.starttls()
                # Re-identify ourselves over TLS connection.
                smtp_connection.ehlo()
            else:
                raise MailerException("SMTP server does not support STARTTLS")

        # If 'smtp.user' is in CKAN config, try to login to SMTP server.
        if smtp_user:
            assert smtp_password, ("If smtp.user is configured then "
                                   "smtp.password must be configured as well.")
            smtp_connection.login(smtp_user, smtp_password)

        smtp_connection.sendmail(from_addr, to_addrs, msg.as_string())
        log.info("Sent email from {0} to {1}".format(from_addr, to_addrs))

    except smtplib.SMTPException, e:
        msg = '%r' % e
        log.exception(msg)
        raise MailerException(msg)
    finally:
        smtp_connection.quit()


############### AUTHORIZATION ###################

@toolkit.auth_allow_anonymous_access
def dge_archiver_auth(context, data_dict):
    '''
    All users can access DCAT endpoints by default
    '''
    return {'success': True}
