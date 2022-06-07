# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge_ga_report (datos.gob.es)".
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

try:
    # optional fancy progress bar you can install
    from progressbar import ProgressBar, Percentage, Bar, ETA

    class GaProgressBar(ProgressBar):
        def __init__(self, total):
            if total == 0:
                return
            widgets = ['Test: ', Percentage(), ' ', Bar(),
                       ' ', ETA(), ' ']
            ProgressBar.__init__(self, widgets=widgets,
                                 maxval=total)
            self.start()

except ImportError:
    class GaProgressBar(object):
        def __init__(self, total):
            self.total = total

        def update(self, count):
            if count % 100 == 0:
                print '.. %d/%d done so far' % (count, self.total)