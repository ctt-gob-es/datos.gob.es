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

import logging
import os
import shlex
import subprocess
from urlparse import urlparse

import psycopg2

from report import DataSetPurgeReport

logger = logging.getLogger(__name__)
NL = os.linesep


class Purger:
    def __init__(self, config):
        self.config = config
        url = urlparse(config.get('app:main', 'sqlalchemy.url'))
        self.conn_string = ("host={} port=5432 user={} "
                            "password={} dbname={}").format(url.hostname, url.username,
                                                            url.password, url.path[1:])


class DataSetPurger(Purger):
    def __init__(self, config, report):
        Purger.__init__(self, config)
        self.purge_cmd_template = self.config.get('app:main', 'purge_command')
        list_ds_cmd = config.get('app:main', 'ckanext-dge.list_dataset_command')
        try:
            out = subprocess.check_output(list_ds_cmd, shell=True)
            self.data = out.split(NL) if out else None
        except subprocess.CalledProcessError:
            self.data = None
        self.report = report

    def __get_datasets_to_purge(self):
        if self.data:
            return [line.split(' ', 2)[:2] for line in self.data if '(deleted)' in line]
        return []

    def purge(self):
        datasets = self.__get_datasets_to_purge()
        if datasets:
            self.report.dataset_report = DataSetPurgeReport(len(datasets))
            for dataset in datasets:
                self.__purge_dataset(dataset)

    def __purge_dataset(self, dataset):
        dataset_id, dataset_name = dataset
        purge_cmd = self.purge_cmd_template.format(dataset_id)
        purge_ok, msg = self.__run_purge_command(purge_cmd)
        if not purge_ok:
            try:
                connection = psycopg2.__connect(self.conn_string)
                cursor = connection.cursor()
                query = "DELETE FROM public.archival WHERE package_id = '{}';".format(dataset_id)
                cursor.execute(query)

                connection.commit()
                cursor.close()
                connection.close()
                purge_ok, msg = self.__run_purge_command(purge_cmd)
            except psycopg2.Error as err:
                msg = err.pgerror

        if purge_ok:
            self.report.dataset_report.purge_correct(dataset)
        else:
            self.report.dataset_report.purge_failed(dataset, msg)

    @staticmethod
    def __run_purge_command(command):
        args = shlex.split(command)
        try:
            subprocess.check_call(command, shell=True)
            return True, None
        except subprocess.CalledProcessError as err:
            return False, err.output


class DistributionsPurger(Purger):
    def __init__(self, config):
        Purger.__init__(self, config)

    def purge(self):
        pass


class FederationsPurger(Purger):
    def __init__(self, config):
        Purger.__init__(self, config)

    def purge(self):
        pass
