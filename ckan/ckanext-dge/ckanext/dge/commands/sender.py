# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge (datos.gob.es)".
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

# coding=utf-8
import smtplib
from datetime import datetime
from email.mime.text import MIMEText


class EmailSender:
    def __init__(self, config):
        smtp_config = config.get('app:main', 'smtp.server')
        self.host, self.port = smtp_config.split(':', 1) if ':' in smtp_config else (smtp_config, 25)
        self.port = int(self.port)
        self.starttls = eval(config.get('app:main', 'smtp.starttls'))
        self.username, self.password = None, None
        if config.has_option('app:main', 'smtp.user') and config.has_option('app:main', 'smtp.password'):
            self.username = config.get('app:main', 'smtp.user')
            self.password = config.get('app:main', 'smtp.password')
        self.from_addr = config.get('app:main', 'smtp.mail_from')
        self.to = config.get('app:main', 'smtp.purge_to')

    def __fill_common_headers(self, msg):
        msg['From'] = self.from_addr
        msg['To'] = self.to

    def __connect(self):
        smtp_server = smtplib.SMTP(self.host, self.port)
        if self.starttls:
            smtp_server.starttls()
        if self.username and self.password:
            smtp_server.login(self.username, self.password)
        return smtp_server

    def send(self, text):
        msg = MIMEText(text, _charset='utf-8')
        self.__fill_common_headers(msg)
        msg['Subject'] = 'Reporte de purgado ({:%d/%b/%Y})'.format(datetime.now())

        smtp_server = self.__connect()
        smtp_server.sendmail(self.from_addr, self.to, msg.as_string())
        smtp_server.quit()
