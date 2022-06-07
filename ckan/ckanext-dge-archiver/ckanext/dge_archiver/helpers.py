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

#!/usr/bin/env python
# -*- coding: utf-8 -*-
from ckan.lib.helpers import get_available_locales
import ckanext.dge.helpers as dh
import ckanext.dge_scheming.helpers as dsh
import ckanext.scheming.helpers as sh
import paste.deploy.converters as converters
from pylons.i18n import gettext
from pylons import config
import pytz
import datetime
import calendar
from dateutil.relativedelta import relativedelta
from time import strptime
import ckan.lib.helpers as h
import ckan.plugins.toolkit as toolkit
import urllib, json
from ckan import logic
from ckan.common import (
    _, ungettext, g, c, request, session, json, OrderedDict
)
from operator import itemgetter
import ckan.model as model
import logging

from rdflib.plugins.parsers.pyRdfa import options

log = logging.getLogger(__name__)

def organization_name():
        orgs = dh.dge_url_for_user_organization()
        return orgs
