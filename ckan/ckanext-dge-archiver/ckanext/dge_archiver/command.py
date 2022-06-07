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

import sys

from pylons import config

import ckan.plugins as p
from subprocess import call

from ckanext.dge_archiver.logic import dge_archiver_report_email_finished, dge_archiver_check_broken_links 

class DgeArchiverCommand(p.toolkit.CkanCommand):
    """
    Control reports, their generation and caching.

    Reports can be cached if they implement IReportCache. Suitable for ones
    that take a while to run.

    The available commands are:

        initdb   - Initialize the database tables for this extension

        list     - Lists the reports

        generate - Generate and cache reports - all of them unless you specify
                   a comma separated list of them.

        generate-for-options - Generate and cache a report for one combination
                   of option values. You can leave it with the defaults or
                   specify options as more parameters: key1=value key2=value

    e.g.

      List all reports:
      $ paster report list

      Generate two reports:
      $ paster report generate openness-scores,broken-links

      Generate report for one specified option value(s):
      $ paster report generate-for-options publisher-activity organization=cabinet-office

      Generate all reports:
      $ paster report generate

    """

    summary = __doc__.split('\n')[0]
    usage = __doc__
    max_args = None
    min_args = 1

    def __init__(self, name):
        super(DgeArchiverCommand, self).__init__(name)

    def command(self):
        import logging

        self._load_config()
        self.log = logging.getLogger("ckan.lib.cli")
        self.log.setLevel('DEBUG')

        cmd = self.args[0]
        import datetime
        
        
        self.log.debug(datetime.datetime.now())
        self.log.debug('ANTES DE COMPROBAR COMANDO')
        if cmd == 'initdb':
            from ckanext.dge_archiver import model as dge_archiver_model
            dge_archiver_model.init_tables()
            self.log.info('DGE Archiver tables are setup')
        elif cmd == 'dropdb':
            from ckanext.dge_archiver import model as dge_archiver_model
            dge_archiver_model.drop_tables()
            self.log.info('DGE Archiver tables dropped')
        elif cmd == 'generate-and-notify':
            self.log.debug('DENTRO DEL COMANDO')
            paster_command = config.get('ckanext-dge-archiver.paster_command')
            paster_command = paster_command.format(config.get('ckanext-dge-archiver.config_file'))
            self.log.info(paster_command)
            call(paster_command, shell=True)
            self.log.debug('SE HA TERMINADO DE EJECUTAR EL REPORTE')
            self.log.debug('SE LLAMA A LA FUNCION DEL MAIL')
            dge_archiver_report_email_finished(self)
        elif cmd == 'check-archiver':
            self.log.debug('SE VAN A COMPROBAR LOS ENLACES ROTOS DE LOS ORGANISMOS ELEGIDOS')
            dge_archiver_check_broken_links(self)
            self.log.debug('YA SE HAN ENCOLADO LOS ENLACES')
        else:
            self.parser.error('Command not recognized: %r' % cmd)

    def _initdb(self):
        from ckanext.report import model as report_model
        report_model.init_tables()
        self.log.info('Report table is setup')
        
        from ckanext.dge_archiver import model as dge_archiver_model
        dge_archiver_model.init_tables()
        self.log.info('DGEArchiver tables are setup')

    def _list(self):
        from ckanext.report.report_registry import ReportRegistry
        registry = ReportRegistry.instance()
        for plugin, report_name, report_title in registry.get_names():
            report = registry.get_report(report_name)
            date = report.get_cached_date()
            print '%s: %s %s' % (plugin, report_name,
                  date.strftime('%d/%m/%Y %H:%M') if date else '(not cached)')

    def _generate(self, report_list=None):
        import time
        from ckanext.report.report_registry import ReportRegistry
        timings = {}

        registry = ReportRegistry.instance()
        if report_list:
            for report_name in report_list:
                s = time.time()
                registry.get_report(report_name).refresh_cache_for_all_options()
                timings[report_name] = time.time() - s
        else:
            s = time.time()
            registry.refresh_cache_for_all_reports()
            timings["All Reports"] = time.time() - s

        self.log.info("Report generation complete %s", timings)

    def _generate_for_options(self, report_name, options):
        from ckanext.report.report_registry import ReportRegistry
        registry = ReportRegistry.instance()
        report = registry.get_report(report_name)
        all_options = report.add_defaults_to_options(options,
                                                     report.option_defaults)
        report.refresh_cache(all_options)
