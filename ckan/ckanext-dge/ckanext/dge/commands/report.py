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
import os

NL = os.linesep
NL2 = NL * 2


class DataSetPurgeReport:
    # noinspection PyTypeChecker
    template = ('Datasets en estado deleted {}' + NL2 +
                'Datasets purgado(s) : {} ' + NL + '{}' + NL2 +
                'Datasets no purgado(s) : {} ' + NL + '{}' + NL2 +
                'Lista Errores:' + NL2 + '{}')

    def __init__(self, datasets_count):
        self.datasets_count = datasets_count
        self.purged_datasets = []
        self.not_purged_datasets = []

    def purge_correct(self, dataset):
        self.purged_datasets += [dataset]

    def purge_failed(self, dataset, error):
        dataset_id, dataset_name = dataset
        self.not_purged_datasets += [(dataset_id, dataset_name, error)]

    def get_report(self):
        not_purged, error_list = '', ''
        for dataset_id, dataset_name, error in self.not_purged_datasets:
            not_purged += ('Id: {}, Nombre: {}' + NL).format(dataset_id, dataset_name)
            error_list += error + NL
        purged = NL.join(
            'Id: {}, Nombre: {}'.format(dataset_id, dataset_name)
            for dataset_id, dataset_name in self.purged_datasets)

        return self.template.format(self.datasets_count,
                                    len(self.purged_datasets),
                                    purged, len(self.not_purged_datasets),
                                    not_purged, error_list)


class DistributionsPurgeReport:
    def __init__(self):
        pass

    def get_report(self):
        pass


class FederationsPurgeReport:
    def __init__(self):
        pass

    def get_report(self):
        pass


class Report:

    def __init__(self):
        self.dataset_report = None
        self.distributions_report = None
        self.federations_report = None

    def get_report(self, default_report):
        self.datos_ = 'Ha concluido la operación de purgado. A continuación algunos datos: '
        full_report = self.datos_
        reports = (('DataSets', self.dataset_report), ('Distribuciones', self.distributions_report),
                   ('Federaciones', self.federations_report))
        give_report = False
        for name, report in reports:
            if report is not None:
                give_report = True
                # noinspection PyTypeChecker
                full_report += (NL2 + '{}:' + NL + ' {}').format(name, report.get_report())

        if give_report:
            return full_report
        return default_report
