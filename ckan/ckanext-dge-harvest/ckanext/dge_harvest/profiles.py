# Copyright (C) 2017 Entidad Pública Empresarial Red.es
# 
# This file is part of "ckanext-dge-harvest (datos.gob.es)".
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
# 
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import json
import isodate
import rdflib
import logging
import iso8601
import pytz
import re
import ckan.lib.helpers as h
import ckanext.scheming.helpers as sh
import ckanext.dge_scheming.helpers as dsh
import ckanext.dge_harvest.constants as dhc
import ckanext.dge_harvest.helpers as dhh

from pylons import config
from rdflib import URIRef, BNode, Literal
from rdflib.namespace import Namespace, RDF, XSD, SKOS, RDFS, DC
from geomet import wkt, InvalidGeoJSONException
from ckan.plugins import toolkit
from ckanext.dcat.utils import resource_uri, publisher_uri_from_dataset_dict,\
    catalog_uri
from ckanext.dcat.processors import RDFParserException
from ckanext.dcat.profiles import RDFProfile, DCT, DCAT, ADMS, VCARD, FOAF, SCHEMA, LOCN, GSP, OWL, SPDX, GEOJSON_IMT  
from isodate import isoduration, ISO8601Error, Duration
from datetime import timedelta, datetime, tzinfo
from dateutil.parser import parse as parse_date
from iso8601 import ParseError
from pytz import timezone
from _weakref import ReferenceType
from _elementtree import ParseError
from ckan.lib.helpers import dataset_display_name


log = logging.getLogger(__name__)

import sys
import __builtin__

ENCODING = sys.getdefaultencoding()
TIME = Namespace('http://www.w3.org/2006/time#')
XSD = Namespace('http://www.w3.org/2001/XMLSchema#')

namespaces = {
    'dct': DCT,
    'dcat': DCAT,
    'adms': ADMS,
    'vcard': VCARD,
    'foaf': FOAF,
    'schema': SCHEMA,
    'time': TIME,
    'skos': SKOS,
    'locn': LOCN,
    'gsp': GSP,
    'owl': OWL,
    'xsd': XSD
}


class DgeProfile(RDFProfile):
    '''
    An RDF profile based on the DCAT-AP for data portals in Europe

    More information and specification:

    https://joinup.ec.europa.eu/asset/dcat_application_profile

    '''
    catalog_errors = []
    dataset_errors = []
    catalog_warnings = []
    dataset_warnings = []

    def _get_ckan_locales_offered(self):
        ''' Returns locales offered '''
        return config.get(dhc.CKAN_PROP_LOCALES_OFFERED, None)
    
    def _get_ckan_default_locale(self):
        ''' Returns default locale '''
        return config.get(dhc.CKAN_PROP_LOCALE_DEFAULT, 'es')

    def _is_uri(self, uri):
        ''' Returns True is the given uri is a valid uri. '''
        return dhh.dge_harvest_is_uri(uri)

    def _add_translated_triple_field_from_dict(self, _dict, subject, predicate, key, fallbacks=None):
        '''
        Adds a new triple to the graph for each language with the provided parameters
    
        The subject and predicate of the triple are passed as the relevant
        RDFLib objects (URIRef or BNode). The object is always a literal value,
        which is extracted from the dict using the provided key (see
        `_get_dict_value`). If the value for the key is not found, then
        additional fallback keys are checked.
        '''
        value = self._get_dict_value(_dict, key)
        if not value and fallbacks:
            for fallback in fallbacks:
                value = self._get_dict_value(_dict, fallback)
                if value:
                    break

        # List of values
        if isinstance(value, dict):
            items = value
            for k, v in items.items():
                if k and v:
                    self.g.add((subject, predicate, Literal(v, lang=k)))


    def _add_date_triple(self, subject, predicate, value):
        '''
        Adds a new triple with a date object

        Dates are parsed using iso8601, and if the date obtained is correct,
        added to the graph as an XSD.dateTime value.
        All dates are in timezone 'Europe/Madrid'

        If there are parsing errors, the literal string value is added.
        '''
        if not value:
            return
        try:
            default_timezone = timezone(dhc.DEFAULT_TIMEZONE)
            naive = iso8601.parse_date(value, None)
            #FIXME - is_dst a False para evitar AmbiguousTimeError en fechas en que
            # se cambia la hora. 
            try:
                local_dt = default_timezone.localize(naive, is_dst=None)
            except pytz.exceptions.AmbiguousTimeError:
                log.info("AmbiguousTimeError - %s", value)
                local_dt = default_timezone.localize(naive, is_dst=False)
            #remove microseconds
            final_local_dt = local_dt.replace(microsecond=0)
            self.g.add((subject, predicate, Literal(final_local_dt.isoformat(),
                                                    datatype=XSD.dateTime)))
        except ParseError:
            self.g.add((subject, predicate, Literal(value)))

    def _add_skos_concept(self, concept=None, value=None, labels=None, descriptions=None, mapping=None, notation=None):
        if concept and value and isinstance(concept, URIRef) :
            self.g.add((concept, RDF.type, SKOS.Concept))
            if labels:
                if isinstance(labels, dict):
                    for key, value in labels.items():
                        if value and value != '':
                            self.g.add((concept, SKOS.prefLabel, Literal(value, lang=key)))
                else:
                    if labels and labels != '':
                        self.g.add((concept, SKOS.prefLabel, Literal(labels)))
            if descriptions:
                if isinstance(descriptions, dict):
                    for key, value in descriptions.items():
                        if value and value != '':
                            self.g.add((concept, SKOS.definition, Literal(value, lang=key)))
                else:
                    if descriptions and descriptions != '':
                        self.g.add((concept, SKOS.definition, Literal(descriptions)))
            if mapping:
                self.g.add((concept, SKOS.broadMatch, URIRef(mapping)))
            if notation:
                self.g.add((concept, SKOS.notation, Literal(notation)))

    def _add_resource_list_triple(self, subject, predicate, value, labels=None, descriptions=None, mapping=None, notation=None):
            '''
            Adds as many triples to the graph as values

            Values are literal strings, if `value` is a list, one for each
            item. If `value` is a string there is an attempt to split it using
            commas, to support legacy fields.
            '''
            items = []
            # List of values
            if isinstance(value, list):
                items = value
            elif isinstance(value, basestring):
                try:
                    # JSON list
                    items = json.loads(value)
                except ValueError:
                    if ',' in value:
                        # Comma-separated list
                        items = value.split(',')
                    else:
                        # Normal text value
                        items = [value]
            for item in items:
                concept = URIRef(item)
                self.g.add((subject, predicate, concept))
                if labels or descriptions or mapping or notation:
                    self._add_skos_concept(concept, value, labels, descriptions, mapping, notation)
                    
                

    def _get_value_from_dict(self, _dict, key, fallbacks=None):
        '''
        Returns the value for the given key on a CKAN dict

        The subject and predicate of the triple are passed as the relevant
        RDFLib objects (URIRef or BNode). The object is always a literal value,
        which is extracted from the dict using the provided key (see
        `_get_dict_value`). If the value for the key is not found, then
        additional fallback keys are checked.
        '''
        value = self._get_dict_value(_dict, key)
        if not value and fallbacks:
            for fallback in fallbacks:
                value = self._get_dict_value(_dict, fallback)
                if value:
                    break
        return value

    def _add_warningmsg(self, warningmsg=None, isCatalog=False, prefix=None):
        '''
        If warningmsg... add the given warning message to catalog_warning list 
        if isCatalog is True, or to dataset_wargning list in other case
        '''
        method_log_prefix = '[%s][_add_warningmsg]' % type(self).__name__
        if warningmsg is not None and warningmsg:
            if prefix and len(prefix) > 0:
                warningmsg = "[%s]%s" % (prefix, warningmsg)
            if isCatalog and warningmsg not in self.catalog_warnings:
                self.catalog_warnings.append(warningmsg)
                log.info("%s Adding catalog_warning... %r" % (method_log_prefix, warningmsg))
            elif not isCatalog and warningmsg not in self.dataset_warnings:
                self.dataset_warnings.append(warningmsg)
                log.info("%s Adding dataset_warning... %r" % (method_log_prefix, warningmsg))

    def _add_errormsg(self, errormsg=None, isCatalog=False, prefix=None):
        '''
        If errosmsg... add the given error message to catalog_errors list 
        if isCatalog is True, or to dataset_errors in other case
        '''
        method_log_prefix = '[%s][_add_errormsg]' % type(self).__name__
        if errormsg is not None and errormsg:
            if prefix and len(prefix) > 0:
                errormsg = "[%s]%s" % (prefix, errormsg)
            if isCatalog and errormsg not in self.catalog_errors:
                self.catalog_errors.append(errormsg)
                log.info("%s Adding catalog_error... %r" % (method_log_prefix, errormsg))
            elif not isCatalog and errormsg not in self.dataset_errors:
                self.dataset_errors.append(errormsg)
                log.info("%s Adding dataset_error... %r" % (method_log_prefix, errormsg))

    def _check_empty_field(self, value, field_name, isCatalog=False, required=False, multiple=False, prefix_msg= None):
        '''
        Returns True if value is None or empty, False in other case.
        Moreover, add an error or warning message when value is None or empty 
        '''
        empty = False 
        value = self._strip_value(value)
        if required:
            if value is None:
                empty = True
                if multiple:
                    self._add_errormsg(dhc.REQUIRED_MULTIPLE_FIELD_NOT_FOUND % (field_name), isCatalog, prefix_msg)
                else:
                    self._add_errormsg(dhc.REQUIRED_FIELD_NOT_FOUND % (field_name), isCatalog, prefix_msg)
            elif not value:
                empty = True
                self._add_errormsg(dhc.UNEXPECTED_EMPTY_VALUE % (field_name), isCatalog, prefix_msg)
        else:
            if value is None:
                empty = True
            if value is not None and not value:
                empty = True
                self._add_warningmsg(dhc.OPTIONAL_EMPTY_VALUE % (field_name), isCatalog, prefix_msg)
        return empty

    def _are_literal_objects(self, subject, predicate):
        '''
        Given a subject and a predicate, returns True
        if datatype of all found objects is an instance of Literal

        Both subject and predicate must be rdflib URIRef or BNode objects
        '''
        for o in self.g.objects(subject, predicate):
            if o and not isinstance(o, Literal):
                return False
        return True

    def _validate_iso8601_date(self, datevalue, datetype):
        '''
        Returns the date with 'YYY-MM-DDTHH:mm:ssTZD' ISO 8601 format

        Note that partial dates will be expanded to the first month / day
        value, eg '1904' -> '1904-01-01'.

        Returns a string with the date value Europe/Madrid timezone,
        or None if datevalue is None. If datetype is None, XSD.dateTime is considered
        Raise RDFParserException if the datevalue format is not as expected 
        '''
        method_log_prefix = '[%s][_validate_iso8601_date]' % type(self).__name__
        log.debug("%s Init method. Inputs: datevalue=%s, datetype=%s" % (method_log_prefix, datevalue, (datetype if datetype else 'None')))
        result = None
        errormsg = None
        if (datevalue):
            try:
                if (not datetype):
                    datetype = XSD.dateTime
                if (datetype not in [XSD.date, XSD.dateTime]):
                    errormsg = dhc.UNEXPECTED_DATE_DATATYPE % (datetype, datevalue)
                else:
                    default_timezone = timezone(dhc.DEFAULT_TIMEZONE)
                    datetimevalue = iso8601.parse_date(datevalue, default_timezone)
                    if datetype == XSD.date:
                        isoformatvalue = datetimevalue.isoformat()
                        result = datetimevalue.strftime("%Y-%m-%d")
                    elif datetype == XSD.dateTime:
                        utc1 = datetimevalue.astimezone(default_timezone)
                        isoformatvalue = utc1.isoformat()
                        result = utc1.strftime("%Y-%m-%dT%H:%M:%S")
            except ParseError as e:
                errormsg = dhc.UNEXPECTED_DATE_FORMAT % (datevalue)
                raise RDFParserException(errormsg)
            except ValueError as e:
                errormsg = dhc.UNEXPECTED_DATE_VALUE % (datevalue, e.message)
                raise RDFParserException(errormsg)
            if errormsg is not None:
                raise RDFParserException(errormsg)
        log.debug("%s End method. Returns %r" % (method_log_prefix, result))
        return result

    def _time_interval_coverage(self, interval):
        '''
        Returns the start and end date for a time interval object

        Both subject and predicate must be rdflib URIRef or BNode objects

        It checks for time intervals defined with both schema.org startDate &
        endDate and W3C Time hasBeginning & hasEnd or period of time defined
        with http://purl.org/dc/terms/PeriodOfTime.

        Note that partial dates will be expanded to the first month / day
        value, eg '1904' -> '1904-01-01'.

        Returns a tuple with the start and end date values, both of which
        can be None if not found. Raise RDFParserException if the definition 
        format is not as expected 
        '''
        method_log_prefix = '[%s][_time_interval_coverage]' % type(self).__name__
        log.debug("%s Init method. Input: interval=%r" % (method_log_prefix, interval))
        start_date = end_date = None
        start_date_type = end_date_type = None
        final_start_date = final_end_date = None
        valid_data_types = [XSD.date, XSD.dateTime]
        errormsgs = []
        
        try:
            if interval:
                isInterval = (interval, RDF.type, TIME.Interval) in self.g
                isPeriodOfTime = (interval, RDF.type, DCT.PeriodOfTime) in self.g
    
                '''Fist try the schema.org way
                <dct:temporal>
                    <dct:PeriodOfTime>
                        <shema:startDate rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">@@FechaHoraInicio@@</schema:startDate>
                        <shema:endDate rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">@@FechaHoraFin@@</schema:endDate>
                    </dct:PeriodOfTime>
                </dct:temporal>
                '''
                if (isPeriodOfTime):
                    try:
                        start_date, start_date_type = self._object_value_datatype(interval, SCHEMA.startDate)
                    except RDFParserException as e:
                        errormsgs.append(dhc.UNEXPECTED_MULTIPLE_SUBOBJECTS % (SCHEMA.startDate))
                    try:
                        end_date, end_date_type = self._object_value_datatype(interval, SCHEMA.endDate)
                    except RDFParserException as e:
                        errormsgs.append(dhc.UNEXPECTED_MULTIPLE_SUBOBJECTS % (SCHEMA.endDate))

                ''' If no luck, try the w3 time way
                <dct:temporal>
                    <time:Interval>
                        <rdf:type rdf:resource="http://purl.org/dc/terms/PeriodOfTime" />
                        <time:hasBeginning>
                            <time:Instant>
                                <time:inXSDDateTime rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">@@FechaHoraInicio@@</time:inXSDDateTime>
                            </time:Instant>
                        </time:hasBeginning>
                        <time:hasEnd>
                            <time:Instant>
                                <time:inXSDDateTime rdf:datatype="http://www.w3.org/2001/XMLSchema#dateTime">@@FechaHoraFin@@</time:inXSDDateTime>
                            </time:Instant>
                        </time:hasEnd>
                    </time:Interval>
                </dct:temporal>
                '''
                if isPeriodOfTime and isInterval:
                    start_nodes = [t for t in self.g.objects(interval, TIME.hasBeginning)]
                    end_nodes = [t for t in self.g.objects(interval, TIME.hasEnd)]
                    if start_nodes and len(start_nodes) > 1:
                        errormsgs.append(dhc.UNEXPECTED_MULTIPLE_SUBOBJECTS % (TIME.hasBeginning))
                    elif start_nodes and len(start_nodes) == 1 and (start_nodes[0], RDF.type, TIME.Instant) in self.g:
                        try:
                            start_date, start_date_type = self._object_value_datatype(start_nodes[0], TIME.inXSDDateTime)
                        except:
                            errormsgs.append(dhc.UNEXPECTED_MULTIPLE_SUBOBJECTS % ((TIME.hasBeginning + "-" + TIME.inXSDDateTime)))
                    if end_nodes and len(end_nodes) > 1:
                        errormsgs.append(dhc.UNEXPECTED_MULTIPLE_SUBOBJECTS % (TIME.hasEnd))
                    elif end_nodes and (end_nodes[0], RDF.type, TIME.Instant) in self.g:
                        try:
                            end_date, end_date_type = self._object_value_datatype(end_nodes[0], TIME.inXSDDateTime)
                        except:
                            errormsgs.append(dhc.UNEXPECTED_MULTIPLE_SUBOBJECTS % ((TIME.hasEnd + "-" + TIME.inXSDDateTime)))
    
                ''' If no luck...
                <dct:temporal>
                    <dct:PeriodOfTime>
                       <rdf:value rdf:datatype="http://www.w3.org/2001/XMLSchema#string">2007-01-01T00:00:00.000+01:00/2012-12-31T00:00:00.000+01:00</rdf:value>
                    </dct:PeriodOfTime>
                </dct:temporal>
                '''
                if isPeriodOfTime:
                    try:
                        period_value, period_type = self._object_value_datatype(interval, RDF.value)
                        if (period_value and period_type == XSD.string):
                            nodes = period_value.split('/')
                            if (nodes and len(nodes) >= 1 and len(nodes) <= 2):
                                if (len(nodes) >= 1):
                                    start_date = nodes[0]
                                if (len(nodes) == 2):
                                    end_date = nodes[1]
                    except:
                        errormsgs.append(dhc.UNEXPECTED_MULTIPLE_SUBOBJECTS % (RDF.value))

                if len(errormsgs) == 0:
                    if start_date or end_date:
                        if start_date and start_date_type and start_date_type not in valid_data_types:
                            errormsgs.append(dhc.UNEXPECTED_DATE_DATATYPE % (start_date_type, start_date, valid_data_types))
                        else:
                            try:
                                start_date = self._validate_iso8601_date(start_date, start_date_type)
                            except RDFParserException as e:
                                errormsgs.append(e.message)
                        if end_date and end_date_type and end_date_type not in valid_data_types:
                            errormsgs.append(dhc.UNEXPECTED_DATE_DATATYPE % (end_date_type, end_date))
                        else: 
                            try:
                                end_date = self._validate_iso8601_date(end_date, end_date_type)
                            except RDFParserException as e:
                                errormsgs.append(e.message)
                    else:
                        errormsgs.append(dhc.UNEXPECTED_DEFINITION)
        except:
            errormsgs.append(dhc.UNEXPECTED_DEFINITION)
        if len(errormsgs) > 0:
            raise RDFParserException(", ".join(errormsgs))
        log.debug("%s End method. Returns start_date=%r, end_date=%r" % (method_log_prefix, start_date, end_date))
        return start_date, end_date

    def _object_value(self, subject, predicate):
        '''
        Given a subject and a predicate, returns the value of the object

        Both subject and predicate must be rdflib URIRef or BNode objects

        If found, the unicode representation is returned, else None
        ''' 
        result = None
        for o in self.g.objects(subject, predicate):
            if o:
                if result is None:
                    result = unicode(o)
                else:
                    errormsg = dhc.UNEXPECTED_MULTIPLE_OBJECTS
                    raise RDFParserException(errormsg)
        return result

    def _object_value_int(self, subject, predicate):
        '''
        Given a subject and a predicate, returns the value of the object as an
        integer. Decimal values are not rounded.

        Both subject and predicate must be rdflib URIRef or BNode objects

        If the value can not be parsed as integer, returns None
        '''
        object_value = self._strip_value(self._object_value(subject, predicate))
        if object_value:
            try:
                return int(float(object_value))
            except ValueError as e:
                raise RDFParserException(dhc.UNEXPECTED_INTEGER_VALUE % (object_value))
        return None

    def _object_datatype(self, subject, predicate):
        '''
        Given a subject and a predicate, returns the datatype of the object

        Both subject and predicate must be rdflib URIRef or BNode objects

        If found, the datatype is returned, else None
        '''
        result = None
        for o in self.g.objects(subject, predicate):
            if o and result is None:
                if isinstance(o, Literal):
                    result = (Literal(o)).datatype
            else:
                raise RDFParserException(dhc.UNEXPECTED_MULTIPLE_OBJECTS)
        return result

    def _object_value_datatype(self, subject, predicate):
        '''
        Given a subject and a predicate, returns the value and the datatype 
        of the object

        Both subject and predicate must be rdflib URIRef or BNode objects

        If found, the unicode representation and datatype is returned, else None
        '''
        r1 = r2 = None
        for o in self.g.objects(subject, predicate):
            if o is not None:
                if r1 is None:
                    if (isinstance(o, Literal)):
                        r1 = unicode(o)
                        r2 = (Literal(o)).datatype
                    else:
                        r1 = unicode(o)
                        r2 = None
                else:
                    raise RDFParserException(dhc.UNEXPECTED_MULTIPLE_OBJECTS)
        return r1, r2

    def _object_value_list(self, subject, predicate):
        '''
        Given a subject and a predicate, returns a list with all the values of
        the objects

        Both subject and predicate must be rdflib URIRef or BNode  objects

        If no values found, returns an empty string
        '''
        return [unicode(o) for o in self.g.objects(subject, predicate)]

    def _object_value_datatype_list(self, subject, predicate):
        '''
        Given a subject and a predicate, returns a list with all the values of
        the objects

        Both subject and predicate must be rdflib URIRef or BNode  objects

        If no values found, returns an empty string
        '''
        values = []
        datatypes = []
        return [unicode(o) for o in self.g.objects(subject, predicate)]
        for o in self.g.objects(subject, predicate):
            if (isinstance(o, Literal)):
                values.append(unicode(o))
                datatypes.append((Literal(o)).datatype)
            else:
                values.append(unicode(o))
                datatypes.append(None)
        return values, datatypes

    def _get_frequency(self, subject, predicate):
        '''
        Returns the type and value for a accrual periodicity object
        Returns the type and value, both of which
        can be None if not found
        '''
        method_log_prefix = '[%s][_get_frequency]' % type(self).__name__
        log.debug("%s Init method. Inputs: subject=%r, predicate=%r" % (method_log_prefix, subject, predicate))
        types = [TIME.seconds, TIME.minutes, TIME.hours, TIME.days, TIME.weeks, TIME.months, TIME.years]
        ftype = None
        fvalue = None
        isDuration = False
        frequency = None
        accrualPeriodicity = False
        if (subject, predicate, None) not in self.g:
            return None, None
        for period in self.g.objects(subject, predicate):
            isDuration = False
            frequency = None
            if period:
                if accrualPeriodicity == True:
                    # Raise an exception if multiple accrualPeriodicity objects
                    raise RDFParserException(dhc.UNEXPECTED_MULTIPLE_OBJECTS)
                accrualPeriodicity = True
                if isinstance(period, Literal):
                    # <dct:accrualPeriodicity>PnYnMnDTnHnMnS</dct:accrualPeriodicity>
                    frequency = period
                    isDuration = True
                elif isinstance(period, BNode):
                    if (period, RDF.type, DCT.Frequency) in self.g:
                        num_rdf_value_nodes = 0
                        for period_value in self.g.objects(period, RDF.value):
                            num_rdf_value_nodes = num_rdf_value_nodes + 1
                            if num_rdf_value_nodes > 1:
                                raise RDFParserException(dhc.UNEXPECTED_MULTIPLE_SUBOBJECTS % ('rdf:value'))
                            if period_value and isinstance (period_value, BNode):
                                if (period_value, RDF.type, TIME.DurationDescription) in self.g:
                                    num_duration_description_value = 0
                                    for p, o in self.g.predicate_objects(period_value):
                                        if isinstance(p, URIRef) and p in types:
                                            num_duration_description_value = num_duration_description_value + 1
                                            if num_duration_description_value > 1:
                                                raise RDFParserException(dhc.UNEXPECTED_MULTIPLE_SUB_SUBOBJECTS % ('time', 'time:DurationDescription'))
                                            ftype = unicode(p).split('#')[1]
                                            if isinstance(o, Literal):
                                                fvalue = unicode(o)
                            elif period_value and isinstance (period_value, Literal):
                                if ((Literal(period_value)).datatype) == XSD.duration:
                                    frequency = unicode(period_value)
                                    isDuration = True
        if accrualPeriodicity == True:
            if (frequency and isDuration == True):
                    try:
                        duration = isoduration.parse_duration(frequency)
                        if isinstance(duration, Duration) or \
                           isinstance(duration, timedelta):
                            years = months = weeks = days = hours = minutes = seconds = 0
                            aux_value = 0

                            #years
                            if hasattr(duration, 'years'):
                                years = duration.years if duration.years else 0
                                aux_value = years
                                if duration.years:
                                    if (duration.years > 0 or 
                                       (duration.years == 0 and not ftype)):
                                        ftype = TIME.years.split('#')[1]
                                        fvalue = aux_value

                            #months
                            if hasattr(duration, 'months'):
                                months = duration.months if duration.months else 0
                                aux_value = years * 12 + months 
                                if (duration.months > 0 or 
                                    (duration.months == 0 and not ftype)):
                                    ftype = TIME.months.split('#')[1]
                                    fvalue = aux_value

                            #weeks
                            if hasattr(duration, 'weeks'):
                                weeks = duration.weeks if duration.weeks else 0
                                aux_value = years * 12 * 52 + \
                                        months * 4 + \
                                        weeks 
                                if (duration.weeks > 0 or 
                                    (duration.weeks == 0 and not ftype)):
                                    ftype = TIME.weeks.split('#')[1]
                                    fvalue = aux_value

                            #days
                            if hasattr(duration, 'days'):
                                days = duration.days if duration.days else 0
                                aux_value = years * 12 * 365 + \
                                        months * 30 + \
                                        weeks * 7 + \
                                        days
                                if (duration.days > 0 or 
                                    (duration.days == 0 and not ftype)):
                                    ftype = TIME.days.split('#')[1]
                                    fvalue = aux_value

                            #hours
                            if hasattr(duration, 'hours'):
                                hours = duration.hours if duration.hours else 0
                                aux_value = fvalue * 24 + hours
                                if (duration.hours > 0 or 
                                    (duration.hours == 0 and not ftype)):
                                    ftype = TIME.hours.split('#')[1]
                                    fvalue = aux_value

                            #minutes
                            if hasattr(duration, 'minutes'):
                                minutes = duration.minutes if duration.minutes else 0
                                aux_value = fvalue * 60 + minutes
                                if (duration.minutes > 0 or 
                                    (duration.minutes == 0 and not ftype)):
                                   ftype = TIME.minutes.split('#')[1]
                                   fvalue = aux_value

                            #seconds
                            if hasattr(duration, 'seconds'):
                                seconds = duration.seconds if duration.seconds else 0
                                aux_value = fvalue * 60 + seconds
                                if (duration.seconds > 0 or 
                                    (duration.seconds == 0 and not ftype)):
                                    ftype = TIME.seconds.split('#')[1]
                                    fvalue = aux_value
                    except TypeError as e:
                        errormsg = dhc.UNEXPECTED_COMPLETE_DEFINITION % ('TypeError', e)
                        raise RDFParserException(errormsg)
                    except ISO8601Error as e:
                        errormsg = dhc.UNEXPECTED_COMPLETE_DEFINITION % ('ISO8601Error', e)
                        raise RDFParserException(errormsg)
                    except: 
                        errormsg = dhc.UNEXPECTED_DEFINITION
                        raise RDFParserException(errormsg)
            if ftype and fvalue is not None:
                try:
                    fvalue = int(float(fvalue))
                except ValueError as e:
                    errormsg = dhc.UNEXPECTED_INTEGER_VALUE % (e)
                    raise RDFParserException(e.message)
            else:
                errormsg = dhc.UNEXPECTED_INCOMPLETE_VALUE
                raise RDFParserException(errormsg)
            log.debug("%s End  method. Returns type=%r, value=%r" % (method_log_prefix, ftype, fvalue))
            return ftype, fvalue 

    def _get_languages(self, data_ref):
        ''' 
            Returns valid and wrong languages found in the data_ref
            
            Give a data_ref, searches predicates DC.language and DCT.language. 
            Create a list of valid values (values that matches with a language 
            in ckan.locales_offered configuration property) and other list of 
            wrong values (not in ckan.locales_offered)
            
            Returns two lists:
             - list of valid languages or [].
             - list of wrong languages or [] 
        '''
        method_log_prefix = '[%s][_get_languages]' % type(self).__name__
        log.debug("%s Init method. Input: data_ref=%r" % (method_log_prefix, data_ref))
        languages = []
        wrong_languages = []
        if data_ref:
            dc_languages = self._object_value_list(data_ref, DC.language)
            dct_languages = self._object_value_list(data_ref, DCT.language)
            languages = []
            locales_offered = self._get_ckan_locales_offered()
            if dc_languages is not None and len(dc_languages) > 0:
                for language in dc_languages:
                    language = self._strip_value(language)
                    if language not in locales_offered:
                        wrong_languages.append(language) 
                    elif language not in languages:
                        languages.append(language)

            if dct_languages is not None and len(dct_languages) > 0:
                for language in dct_languages:
                    language = self._strip_value(language)
                    if language not in locales_offered:
                        wrong_languages.append(language)
                    elif language not in languages:
                        languages.append(language)
        log.debug("%s End method. Returns languages=%r, wrong_languages=%r" % (method_log_prefix, languages, wrong_languages))
        return languages, wrong_languages

    def _strip_value(self, value):
        '''
        Returns a string without blanks at the beginning and the end of the string
        
        Give a value, delete [ \t\n\r] char from the beginning and the end
        
        Result a string without blanks or None if value is empty 
        '''
        result = None
        if value:
            value = value.strip(' \t\n\r')
            if len(value) > 0:
                result = value
        return result 

    def _get_field_translates(self, catalog_languages, subject, predicate, required, field_name, isCatalog, prefix_msg=None):
        '''
        Returns a dictionary with translates of the objects found 
        from given the subject and predicate
        
        Given a subject, predicate and catalog_languages, 
        search their objects in the graph and 
        get the translates of this objects in the catalog_languages
        
        Returns a dictionary with translates;
        None if required is false and no object is found; 
        RDFParserException if required is true and all translates 
        do not found
        '''
        method_log_prefix = '[%s][_get_field_translates]' % type(self).__name__
        log.debug("%s Init method. Inputs: catalog_languages=%r, subject=%r, predicate=%r, required=%r, field_name=%r, isCatalog=%r, prefix_msg=%r" % (method_log_prefix, catalog_languages, subject, predicate, required, field_name, isCatalog, prefix_msg if prefix_msg else ''))
        if (field_name is None):
            field_name = predicate
        result = None
        wrong_definition = False
        field_in_default_language = False
        default_language = self._get_ckan_default_locale()
        if catalog_languages is None or len(catalog_languages) == 0:
            self._add_warningmsg(dhc.CATALOG_NO_LANGUAGES, prefix_msg)
        elif subject is not None and predicate is not None:
            objects = self.g.objects(subject, predicate)
            if objects is None:
                if required:
                    self._add_errormsg(dhc.REQUIRED_FIELD_NOT_FOUND % (field_name), isCatalog, prefix_msg)
            else:
                translates = {}  # objects with language
                no_translate = None  # object without language
                no_translate_number = 0
                languages = []  # languages found
                unexpected_languages = []
                multiples_same_language = []
                multiples_no_language = False
                empty_value_for_languages = []
                empty_value_no_languages = False
                total = 0
                num_objects = 0
                for object in objects:
                    num_objects = num_objects + 1
                    if object and isinstance(object, Literal):
                        value = self._strip_value(unicode(object))
                        if not self._check_empty_field(value, field_name, isCatalog, True, False):
                            if hasattr(object, 'language') and object.language:
                                if object.language in catalog_languages:
                                    if object.language not in translates:
                                        translates[object.language] = value
                                        total = total + 1
                                        if object.language == default_language:
                                            field_in_default_language = True
                                        languages.append(object.language)
                                    else:
                                        if (object.language not in multiples_same_language):
                                            multiples_same_language.append(object.language)
                                else:
                                    if (object.language not in unexpected_languages):
                                        unexpected_languages.append(object.language)
                            else:
                                no_translate_number = no_translate_number + 1
                                if no_translate is None:
                                    no_translate = value
                                    total = total + 1
                                else:
                                    multiples_no_language = True
                        else:
                            if hasattr(object, 'language') and object.language:
                                if (object.language not in empty_value_for_languages):
                                    empty_value_for_languages.append(object.language)
                            else:
                                empty_value_no_languages = True
                    else:
                        self._add_errormsg(dhc.REQUIRED_LITERAL_OBJECTS % (field_name), isCatalog, prefix_msg)
                        wrong_definition = True;
                        break;
                if num_objects == 0 and required:
                    self._add_errormsg(dhc.REQUIRED_FIELD_NOT_FOUND % (field_name), isCatalog, prefix_msg)
                    return None
                if wrong_definition:
                    return None;
                warn_msgs = []
                error_msgs = []
                # Warnings for empty values
                if len(empty_value_for_languages) > 0:
                    warn_msgs.append(dhc.EMPTY_VALUE_IN_LANGUAGE % (field_name, ", ".join(empty_value_for_languages)))
                if empty_value_no_languages:
                    warn_msgs.append(dhc.EMPTY_VALUE_NO_LANGUAGE % (field_name))
                # Errors multiples values in the same language or no language
                if multiples_no_language:
                    error_msgs.append(dhc.UNEXPECTED_MULTIPLES_VALUES_WITHOUT_LANGUAGE % (field_name))
                if len(multiples_same_language) > 0:
                    error_msgs.append(dhc.UNEXPECTED_MULTIPLES_VALUES_SAME_LANGUAGE % (field_name, ",".join(multiples_same_language)))
                # Warnings for values in unexpected language
                if len(unexpected_languages) > 0:
                    warn_msgs.append(dhc.VALUE_IN_UNEXPECTED_LANGUAGE % (field_name, ",".join(unexpected_languages)))
                if total == 0:
                    # no allowed objects
                    if required and isCatalog:
                        error_msgs.append(dhc.EXPECTED_IN_ALL_CATALOG_LANGUAGE % (field_name))
                    elif required and not isCatalog:
                        error_msgs.append(dhc.EXPECTED_IN_DEFAULT_CATALOG_LANGUAGE % (field_name, default_language))
                else:
                    if len(catalog_languages) == len(translates):
                        result = translates
                    else:
                        languages_not_found = []
                        if not isCatalog:
                            for lang in catalog_languages:
                                if lang not in languages:
                                    languages_not_found.append(lang)
                            if len(languages_not_found) > 1 or \
                               (len(languages_not_found) == 1 and languages_not_found[0] != default_language):
                                warn_msgs.append(dhc.VALUE_NOT_FOUND_IN_EXPECTED_LANGUAGE % (field_name, ", ".join(languages_not_found)))

                        if len(catalog_languages) == 1:
                            if (no_translate is not None and no_translate_number == 1):
                                if result is None:
                                    result = {}
                                result[catalog_languages[0]] = no_translate
                            else:
                                if isCatalog:
                                    error_msgs.append(dhc.EXPECTED_IN_ALL_CATALOG_LANGUAGE % (field_name))
                                elif not field_in_default_language:
                                    error_msgs.append(dhc.EXPECTED_IN_DEFAULT_CATALOG_LANGUAGE % (field_name, default_language))
                        else:
                            if isCatalog:
                                error_msgs.append(dhc.EXPECTED_IN_ALL_CATALOG_LANGUAGE % (field_name))
                            else:
                                if field_in_default_language:
                                    result = translates
                                else:
                                    error_msgs.append(dhc.EXPECTED_IN_DEFAULT_CATALOG_LANGUAGE % (field_name, default_language))

                if len(warn_msgs) > 0:
                    message = "; ".join(warn_msgs)
                    self._add_warningmsg(message, isCatalog, prefix_msg)
                if len(error_msgs) > 0:
                    message = "; ".join(error_msgs)
                    self._add_errormsg(message, isCatalog, prefix_msg)
        log.debug("%s End method. Returns %r" % (method_log_prefix, result))
        return result

    def _get_dataset_title(self, translated_titles, default_catalog_language):
        '''
        Returns the ckan title
        
        Given the default_catalog_language and all translated titles, 
        get de ckan title based on settings: ckan.locale_default, 
        default_catalog_language and ckan.locale_order
        
        Returns the first translated title found in the following order:
        ckan.locale_default, default_catalog_language and ckan.locale_order
        '''
        method_log_prefix = '[%s][_get_dataset_title]' % type(self).__name__
        log.debug("%s Init method. Inputs: translated_titles=%r, default_catalog_language=%r" % (method_log_prefix, translated_titles, default_catalog_language if default_catalog_language else 'None'))
        result = None
        if translated_titles is not None and len(translated_titles) == 1:
            values = translated_titles.values()
            result = values[0]
        elif translated_titles is not None and len(translated_titles) > 1:
            default_locale = self._get_ckan_default_locale()
            locale_order = config.get(dhc.CKAN_PROP_LOCALE_ORDER, None).split()
            if default_locale is not None and default_locale in translated_titles:
                result = translated_titles[default_locale]
            elif default_catalog_language is not None and default_catalog_language in translated_titles:
                result = translated_titles[default_catalog_language]
            elif locale_order is not None:
                for locale in locale_order:
                    if locale is not None and locale in translated_titles:
                        result = translated_titles[locale]
                        break;
        log.debug("%s End method. Returns %r" % (method_log_prefix, result))
        return result

    def _check_theme_in_theme_taxonomy(self, theme=None, theme_taxonomy_list=[]):
        '''
        Given a theme and a list of theme taxonomies,
        return True if theme belongs to a taxonomy given
        '''
        if theme is not None and theme_taxonomy_list != []:
            for taxonomy in theme_taxonomy_list:
                if taxonomy:
                    if (theme.lower()).find(taxonomy.lower()) == 0:
                        return True
        return False

    def _get_publisher_id_minhap(self, publisher, fieldname, isCatalog):
        '''
        Returns idminhap of publisher url or add an error if idminhap nos exists
        '''
        idminhap = None
        upper_publisher = publisher.upper()
        if (upper_publisher.find(dhc.PUBLISHER_PREFIX.upper()) == 0 and len(publisher) > len(dhc.PUBLISHER_PREFIX)):
            idminhap = publisher[len(dhc.PUBLISHER_PREFIX):]
        if not idminhap:
            self._add_errormsg(dhc.UNEXPECTED_VALUE % (fieldname, publisher), isCatalog)
        return idminhap

    def parse_dataset(self, dataset_dict, dataset_ref):
        method_log_prefix = '[%s][parse_dataset]' % type(self).__name__
        if not dataset_dict:
                dataset_dict = {}
        self.dataset_errors = []
        self.dataset_warnings = []
        isCatalog = False
        actual_field = None
        
        try:
            log.debug('%s Init method.' % (method_log_prefix))

            locales_offered = self._get_ckan_locales_offered()
            default_locale = self._get_ckan_default_locale()
            catalog_language = None
            default_catalog_language = None
            valid_dict_themes = {}
            valid_dict_spatials = {}
            valid_dict_formats = {}
            publisher_organizations = {}

            if dhc.CAT_LANGUAGE in dataset_dict and dataset_dict[dhc.CAT_LANGUAGE] is not None:
                catalog_language = dataset_dict[dhc.CAT_LANGUAGE]
            if dhc.DS_DEFAULT_CATALOG_LANGUAGE in dataset_dict and dataset_dict[dhc.DS_DEFAULT_CATALOG_LANGUAGE] is not None:
                default_catalog_language = dataset_dict[dhc.DS_DEFAULT_CATALOG_LANGUAGE]

            if (dataset_dict.get(dhc.CAT_AVAILABLE_DATA)):
                valid_dict_themes = dataset_dict.get(dhc.CAT_AVAILABLE_DATA,{}).get(dhc.CAT_AVAILABLE_THEMES,{})
                valid_dict_spatials = dataset_dict.get(dhc.CAT_AVAILABLE_DATA,{}).get(dhc.CAT_AVAILABLE_SPATIAL_COVERAGES,{})
                valid_dict_formats = dataset_dict.get(dhc.CAT_AVAILABLE_DATA,{}).get(dhc.CAT_AVAILABLE_RESOURCE_FORMATS,{})
                publisher_organizations = dataset_dict.get(dhc.CAT_AVAILABLE_DATA,{}).get(dhc.CAT_AVAILABLE_PUBLISHERS,{})
                del dataset_dict[dhc.CAT_AVAILABLE_DATA]

            log.debug('%s Inputs: dataset_dict=%r, dataset_ref=%r' % (method_log_prefix, dataset_dict, dataset_ref))
            dataset_dict[dhc.DS_TAGS] = []
            dataset_dict[dhc.DS_EXTRAS] = []
            dataset_dict[dhc.DS_RESOURCES] = []
            dataset_dict[dhc.DS_TYPE] = 'dataset'
            dataset_dict[dhc.DS_ERRORS] = []
            dataset_dict[dhc.DS_WARNINGS] = []

            do_parsing = True
            #check leng dataset_ref
            if (dataset_ref and len(dataset_ref) > 0):
                # Dataset URI (explicitly show the missing ones)
                dataset_dict[dhc.DS_URI] = (unicode(dataset_ref)
                           if isinstance(dataset_ref, rdflib.term.URIRef)
                           else None)
            else:
                do_parsing = False
                self._add_errormsg(dhc.DATASET_WRONG_DEFINITION, isCatalog)

            # check if distribution with the same dataset rdf:About
            if do_parsing and \
                (dataset_ref, DCAT.distribution, dataset_ref) in self.g:
                do_parsing = False
                self._add_errormsg(dhc.DATASET_SAME_ABOUT_DISTRIBUTION % dataset_ref, isCatalog)

            if  do_parsing:

                # Name (dct:title) - required, multiple -- multilanguage
                log.debug("%s Parsing dataset DCT.title..." % (method_log_prefix))
                actual_field = dhc.DATASET_TITLE
                dataset_dict[dhc.DS_TITLE] = ''
                translates = self._get_field_translates(catalog_language, dataset_ref, DCT.title, True, actual_field, isCatalog)
                if translates:
                    dataset_dict[dhc.DS_TITLE_TRANSLATED] = translates
                    # CKAN title - required, single
                    title = self._get_dataset_title(translates, default_catalog_language)
                    log.debug("%s Title ckan=%r" % (method_log_prefix, title))
                    if title is None or len(title) == 0:
                        log.warning(dhc.UNEXPECTED_EMPTY_VALUE % (dhc.DATASET_CKAN_TITLE))
                        # self._add_warningmsg(dhc.UNEXPECTED_EMPTY_VALUE % (dhc.DATASET_CKAN_TITLE))
                    else:
                        dataset_dict[dhc.DS_TITLE] = title
                log.debug("%s Parsed dataset DCT.title...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_TITLE_TRANSLATED, 'None')))
                log.debug("%s Parsed dataset DCT.title(CKAN)...%r" % (method_log_prefix, dataset_dict.get(dhc.DS_TITLE, 'None')))

                # Description (dct:description) - required, multiple -- multilanguage
                log.debug("%s Parsing dataset DCT.description..." % (method_log_prefix))
                actual_field = dhc.DATASET_DESCRIPTION
                translates = self._get_field_translates(catalog_language, dataset_ref, DCT.description, True, actual_field, isCatalog)
                if translates:
                    dataset_dict[dhc.DS_DESCRIPTION] = translates
                log.debug("%s Parsed dataset DCT.description...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_DESCRIPTION, 'None')))

                # Theme (dcat:theme) - required, multiple
                log.debug("%s Parsing dataset DCAT.theme..." % (method_log_prefix))
                actual_field = dhc.DATASET_THEME
                themes = self._object_value_list(dataset_ref, DCAT.theme)
                finalThemes = []
                warnThemes = []
                if themes:
                    expected_theme = False
                    # Remove duplicates
                    for theme in themes:
                        theme = self._strip_value(theme)
                        if not self._check_empty_field(theme, actual_field, isCatalog, True, False):
                            if dhh.dge_harvest_is_url(theme):
                                lower_theme = theme.lower()  # no case sensitive
                                if self._check_theme_in_theme_taxonomy(lower_theme, dataset_dict[dhc.CAT_THEME_TAXONOMY]):
                                    if lower_theme.find(dhc.THEME_PREFIX_SLASH.lower()) == 0:
                                        expected_theme = True
                                        final_value = valid_dict_themes.get(lower_theme, None)
                                        if final_value:
                                            finalThemes.append(final_value)
                                            if theme != final_value:
                                                warnThemes.append(theme)
                                        else:
                                            self._add_errormsg(dhc.UNEXPECTED_VALUE % (actual_field, theme), isCatalog)
                                else:
                                    self._add_errormsg(dhc.UNEXPECTED_THEME_TAXONOMY_NOT_IN_CALOG % (actual_field, dhc.THEME_PREFIX_SLASH), isCatalog)
                            else:
                                self._add_errormsg(dhc.WRONG_URL % (actual_field, theme), isCatalog)
                    if finalThemes and len(finalThemes) > 0:
                        dataset_dict[dhc.DS_THEME] = finalThemes
                    if warnThemes and len(warnThemes) > 0 :
                        self._add_warningmsg(dhc.VALUE_NO_CASE_SENSITIVE % (actual_field, ", ".join(warnThemes)), isCatalog)
                    if not expected_theme:
                        self._add_errormsg(dhc.UNEXPECTED_THEME_VALUE % (actual_field, dhc.THEME_PREFIX_SLASH), isCatalog)
                else:
                    self._add_errormsg(dhc.REQUIRED_FIELD_NOT_FOUND % (actual_field), isCatalog)
                log.debug("%s Parsed dataset DCAT.theme...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_THEME, 'None')))

                # Tags (dcat:keyword) - optional, multiple
                log.debug("%s Parsing dataset DCAT.keyword..." % (method_log_prefix))
                actual_field = dhc.DATASET_KEYWORDS
                if not self._are_literal_objects(dataset_ref, DCAT.keyword):
                    self._add_errormsg(dhc.REQUIRED_LITERAL_OBJECTS % (actual_field), isCatalog)
                else:
                    keywords = self._object_value_list(dataset_ref, DCAT.keyword)
                    # Split keywords with commas and semicolon
                    for separator_character in [',', ';']:
                        keywords_with_separator_character = [k for k in keywords if separator_character in k]
                        # log.debug("keywords_with_separator_character=%r", keywords_with_separator_character)
                        for keyword in keywords_with_separator_character:
                            keywords.remove(keyword)
                            keywords.extend([k.strip() for k in keyword.split(separator_character)])
                    if (keywords):
                        sorted_keywords = sorted(keywords) 
                        tagname_match = re.compile('[\w \-.]*$', re.UNICODE)
                        for keyword in sorted_keywords:
                            strip_keyword = self._strip_value(keyword)
                            if not self._check_empty_field(strip_keyword, dhc.DATASET_KEYWORD, isCatalog, False, False):
                                if not tagname_match.match(strip_keyword):
                                    self._add_warningmsg(dhc.UNEXPECTED_KEYWORD_FORMAT % (dhc.DATASET_KEYWORD, strip_keyword), isCatalog)
                                else:
                                    dataset_dict[dhc.DS_TAGS].append({'name': strip_keyword})
                log.debug("%s Parsed dataset DCAT.keywords...%r" % (method_log_prefix, dataset_dict.get(dhc.DS_TAGS, 'None')))

                # Identifier (dct:identifier) -  optional, single
                log.debug("%s Parsing dataset DCT.identifier..." % (method_log_prefix))
                actual_field = dhc.DATASET_IDENTIFIER
                dataset_dict[dhc.DS_IDENTIFIER] = ''
                try:
                    dsIdentifier = self._strip_value(self._object_value(dataset_ref, DCT.identifier))
                    if not self._check_empty_field(dsIdentifier, actual_field, isCatalog, False, False):
                        if self._is_uri(dsIdentifier):
                            dataset_dict[dhc.DS_IDENTIFIER] = dsIdentifier
                        else:
                            self._add_errormsg(dhc.WRONG_URI % (actual_field, dsIdentifier), isCatalog)
                except RDFParserException as e:
                    self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed dataset DCT.identifier...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_IDENTIFIER, 'None')))

                # Creation date (dct:issued) - optional, single
                log.debug("%s Parsing dataset DCT.issued..." % (method_log_prefix))
                actual_field = dhc.DATASET_ISSUED
                try:
                    cDate, cType = self._object_value_datatype(dataset_ref, DCT.issued)
                    cDate = self._strip_value(cDate)
                    if not self._check_empty_field(cDate, actual_field, isCatalog, False, False):
                        dataset_dict[dhc.DS_ISSUED_DATE] = self._validate_iso8601_date(cDate, cType)
                except RDFParserException as e:
                    self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed dataset DCT.issued...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_ISSUED_DATE, 'None')))

                # Date of last update (dct:modified) - optional, single
                log.debug("%s Parsing dataset DCT.modified..." % (method_log_prefix))
                actual_field = dhc.DATASET_MODIFIED
                try:
                    uDate, uType = self._object_value_datatype(dataset_ref, DCT.modified)
                    uDate = self._strip_value(uDate)
                    if not self._check_empty_field(uDate, actual_field, isCatalog, False, False):
                        dataset_dict[dhc.DS_MODIFIED_DATE] = self._validate_iso8601_date(uDate, uType)
                except RDFParserException as e:
                    self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed dataset DCT.modified...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_MODIFIED_DATE, 'None')))

                # Update frequency (dct:accrualPeriodicity) - optional, single
                log.debug("%s Parsing dataset DCT.accrualPeriodicity..." % (method_log_prefix))
                actual_field = dhc.DATASET_ACCRUAL_PERIODICITY
                try:
                    f_type, f_value = self._get_frequency(dataset_ref, DCT.accrualPeriodicity)
                    if (f_type and f_value is not None):
                        if (f_value> 0):
                            dataset_dict[dhc.DS_FREQUENCY] = json.dumps({'type': f_type, 'value': f_value})
                        else:
                            self._add_warningmsg(dhc.RECEIVED_VALUE % (actual_field, f_value), isCatalog)
                except RDFParserException as e:
                    self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed dataset DCT.accrualPeriodicity...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_FREQUENCY, 'None')))

                # Languages (dc:language) - Optional, multiple
                log.debug("%s Parsing dataset DC.language and DCT.language..." % (method_log_prefix))
                actual_field = dhc.DATASET_LANGUAGE
                languages, wrong_languages = self._get_languages(dataset_ref)
                langs = False
                wlangs = False
                if wrong_languages and len(wrong_languages) > 0:
                    wlangs = True
                if languages and len(languages) > 0:
                    langs = True
                if langs:
                    dataset_dict[dhc.DS_LANGUAGE] = languages
                    if wlangs:
                        self._add_warningmsg(dhc.UNEXPECTED_LANGUAGES % (actual_field, wrong_languages, locales_offered), isCatalog)
                else:
                    if wlangs:
                        self._add_warningmsg(dhc.UNEXPECTED_LANGUAGES % (actual_field, wrong_languages, locales_offered))
                    else:
                        self._add_warningmsg(dhc.NO_LANGUAGES % (actual_field, locales_offered), isCatalog)
                log.debug("%s Parsed dataset DC.language and DCT.language...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_LANGUAGE, 'None')))

                # Publisher (dct:publisher) - required, single
                log.debug("%s Parsing dataset DCT.publisher..." % (method_log_prefix))
                actual_field = dhc.DATASET_PUBLISHER
                try:
                    publisher = self._strip_value(self._object_value(dataset_ref, DCT.publisher))
                    if not self._check_empty_field(publisher, actual_field, isCatalog, True, False):
                        idminhap= self._get_publisher_id_minhap(publisher, actual_field, isCatalog)
                        if idminhap:
                            dataset_dict[dhc.DS_PUBLISHER_ID_MINHAP] = idminhap
                            publisher_organization = publisher_organizations.get(idminhap, [])
                            if publisher_organization and len(publisher_organization) == 2:
                                dataset_dict[dhc.DS_PUBLISHER] = publisher_organization[0]
                                dataset_dict[dhc.DS_PUBLISHER_NAME] = publisher_organization[1]
                            else:
                                self._add_errormsg(dhc.UNEXPECTED_PUBLISHER % (actual_field, (dhc.PUBLISHER_PREFIX + idminhap)), isCatalog)
                except RDFParserException as e:
                    self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed dataset DCT.publisher...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_PUBLISHER_ID_MINHAP, 'None')))

                # License (dct:license) - required, single
                log.debug("%s Parsing dataset DCT.license..." % (method_log_prefix))
                actual_field = dhc.DATASET_LICENSE
                try:
                    license = self._strip_value(self._object_value(dataset_ref, DCT.license))
                    if not self._check_empty_field(license, actual_field, isCatalog, True, False):
                        if dhh.dge_harvest_is_url(license):
                            dataset_dict[dhc.DS_LICENSE] = license
                        else:
                            self._add_errormsg(dhc.WRONG_URL % (actual_field, license), isCatalog)
                except RDFParserException as e:
                    self._add_errormsg("%s: %s" % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed dataset DCT.license...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_LICENSE, 'None')))

                # Spatial coverage (dct:spatial) - optional, multiple
                log.debug("%s Parsing dataset DCT.spatial..." % (method_log_prefix))
                actual_field = dhc.DATASET_SPATIAL
                spatials = self._object_value_list(dataset_ref, DCT.spatial)
                if (spatials):
                    spatialList = []
                    warnSpatials = []
                    #allowed_values = dhh.dge_harvest_list_spatial_coverage_option_value()
                    num_expected_values = 0
                    for spatial in spatials:
                        spatial = self._strip_value(spatial)
                        if not self._check_empty_field(spatial, actual_field, isCatalog, False, False):
                            lower_spatial = spatial.lower()
                            if (lower_spatial.find(dhc.SPATIAL_PREFIX.lower()) == 0):
                                final_value = valid_dict_spatials.get(lower_spatial, None)
                                if not final_value:
                                    self._add_errormsg(dhc.UNEXPECTED_VALUE % (actual_field, spatial))
                                else:
                                    spatialList.append(final_value)
                                    if spatial != final_value:
                                        warnSpatials.append(spatial)
                                    if (lower_spatial.find(dhc.SPATIAL_PROVINCE_PREFIX.lower()) == 0\
                                        or spatial.find(dhc.SPATIAL_CCAA_PREFIX.lower()) == 0):
                                        num_expected_values = num_expected_values + 1
                    if spatialList and len(spatialList) > 0:
                        dataset_dict[dhc.DS_SPATIAL] = spatialList
                    if warnSpatials and len(warnSpatials) > 0:
                        self._add_warningmsg(dhc.VALUE_NO_CASE_SENSITIVE % (actual_field, ", ".join(warnSpatials)), isCatalog)
#                     if num_expected_values == 0:
#                         self._add_warningmsg((dhc.UNEXPECTED_SPATIAL_COVERAGE_VALUES % (actual_field)), isCatalog)
                log.debug("%s Parsed dataset DCT.spatial...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_SPATIAL, 'None')))

                # Temporal coverage - (dct:temporal) - optional, multiple
                log.debug("%s Parsing dataset DCT.temporal..." % (method_log_prefix))
                actual_field = dhc.DATASET_TEMPORAL
                temporals = self._object_value_list(dataset_ref, DCT.temporal)
                index = 1
                try:
                    for temporal in self.g.objects(dataset_ref, DCT.temporal):
                        start, end = self._time_interval_coverage(temporal)
                        coverage = {}
                        if start or end:
                            if dataset_dict.has_key(dhc.DS_TEMPORAL_COVERAGE) == False:
                                dataset_dict[dhc.DS_TEMPORAL_COVERAGE] = {}
                            if start:
                                coverage['from'] = start
                            if end:
                                coverage['to'] = end
                            dataset_dict[dhc.DS_TEMPORAL_COVERAGE][index] = coverage
                            index = index + 1
                except RDFParserException as e:
                    self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, (e.message if hasattr(e, 'message') else e)), isCatalog)
                log.debug("%s Parsed dataset DCT.temporal...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_TEMPORAL_COVERAGE, 'None')))

                # Validity of resource (dct:valid) - optional, single
                log.debug("%s Parsing dataset DCT.valid..." % (method_log_prefix))
                actual_field = dhc.DATASET_VALID
                try:
                    vDate, vType = self._object_value_datatype(dataset_ref, DCT.valid)
                    vDate = self._strip_value(vDate)
                    if not self._check_empty_field(vDate, actual_field, isCatalog, False, False):
                        dataset_dict[dhc.DS_VALID] = self._validate_iso8601_date(vDate, vType)
                except RDFParserException as e:
                    self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed dataset DCT.valid...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_VALID, 'None')))

                # References (dct:references) - optional, multiple
                log.debug("%s Parsing dataset DCT.references..." % (method_log_prefix))
                actual_field = dhc.DATASET_REFERENCES
                references = self._object_value_list(dataset_ref, DCT.references)
                if (references):
                    referenceList = []
                    for reference in references:
                        reference = self._strip_value(reference)
                        if not self._check_empty_field(reference, actual_field, isCatalog, False, False):
                            if dhh.dge_harvest_is_url(reference):
                                referenceList.append(reference)
                            else:
                                self._add_errormsg(dhc.WRONG_URL % (actual_field, reference), isCatalog)
                    if referenceList and len(referenceList) > 0:       
                        dataset_dict[dhc.DS_REFERENCE] = referenceList
                log.debug("%s Parsed dataset DCT.references...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_REFERENCE, 'None')))

                # Normative (dct:conformsTo) - optional, multiple
                log.debug("%s Parsing dataset DCT.conformsTo..." % (method_log_prefix))
                actual_field = dhc.DATASET_CONFORMS_TO
                conformsTos = self._object_value_list(dataset_ref, DCT.conformsTo)
                if (conformsTos):
                    conformsToList = []
                    for conformsTo in conformsTos:
                        conformsTo = self._strip_value(conformsTo)
                        if not self._check_empty_field(conformsTo, actual_field, isCatalog, False, False):
                            if dhh.dge_harvest_is_url(conformsTo):
                                conformsToList.append(conformsTo)
                            else:
                                self._add_errormsg(dhc.WRONG_URL % (actual_field, conformsTo), isCatalog)
                    if conformsToList and len(conformsToList) > 0:
                        dataset_dict[dhc.DS_NORMATIVE] = conformsToList
                log.debug("%s Parsed dataset DCT.conformsTo...%s" % (method_log_prefix, dataset_dict.get(dhc.DS_NORMATIVE, 'None')))

                # Distributions/Resources (dct:distribution) - required, multiple
                log.debug("%s Parsing dataset DCAT.distribution..." % (method_log_prefix))
                actual_field = dhc.DATASET_DISTRIBUTION
                numDistributions = 0
                for distribution in self._distributions(dataset_ref):
                    resource_dict = {}
                    if distribution:

                        # Identifier (dct:identifier) - optional, single
                        log.debug("%s Parsing distribution DCT.identifier..." % (method_log_prefix))
                        actual_field = dhc.DISTRIBUTION_IDENTIFIER
                        prefix_msg = dhc.DISTRIBUTION_PREFIX_MESSAGE % (dhc.DISTRIBUTION_NO_IDENTIFIER)
                        # The import fails if resource_dict[dhc.DS_RESOURCE_IDENTIFIER] 
                        # is not included, , even if it is empty
                        resource_dict[dhc.DS_RESOURCE_IDENTIFIER] = ''
                        try:
                            dIdentifier = self._strip_value(self._object_value(distribution, DCT.identifier))
                            if not self._check_empty_field(dIdentifier, actual_field, isCatalog, False, False, prefix_msg):
                                prefix_msg = dhc.DISTRIBUTION_PREFIX_MESSAGE % (dIdentifier)
                                if self._is_uri(dIdentifier):
                                    resource_dict[dhc.DS_RESOURCE_IDENTIFIER] = dIdentifier
                                else:
                                    self._add_errormsg(dhc.WRONG_URI % (actual_field, dIdentifier), isCatalog, prefix_msg)
                        except RDFParserException as e:
                            self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog, prefix_msg)
                        log.debug("%s Parsed distribution DCT.identifier...%s" % (method_log_prefix, resource_dict.get(dhc.DS_RESOURCE_IDENTIFIER, 'None')))

                        # name (dct:title) - optional, multiple -- multilanguage
                        log.debug("%s Parsing distribution DCT.title with langs..." % (method_log_prefix))
                        actual_field = dhc.DISTRIBUTION_TITLE
                        translates = self._get_field_translates(catalog_language, distribution, DCT.title, False, actual_field, isCatalog, prefix_msg)
                        if translates is not None:
                             resource_dict[dhc.DS_RESOURCE_NAME_TRANSLATED] = json.dumps(translates)
                        log.debug("%s Parsed distribution DCT.title...%s" % (method_log_prefix, resource_dict.get(dhc.DS_RESOURCE_NAME_TRANSLATED, 'None')))

                        # access url (dcat:accessURL) - required, single
                        log.debug("%s Parsing distribution DCAT.accesURL..." % (method_log_prefix))
                        actual_field = dhc.DISTRIBUTION_ACCESS_URL
                        try:
                            durl = self._strip_value(self._object_value(distribution, DCAT.accessURL))
                            if not self._check_empty_field(durl, actual_field, isCatalog, True, False, prefix_msg):
                                if dhh.dge_harvest_is_url(durl):
                                    resource_dict[dhc.DS_RESOURCE_ACCESS_URL] = durl
                                else:
                                    self._add_errormsg(dhc.WRONG_URL % (actual_field, durl), isCatalog, prefix_msg)
                        except RDFParserException as e:
                            self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog, prefix_msg)
                        log.debug("%s Parsed distribution DCAT.accessURL...%s" % (method_log_prefix, resource_dict.get(dhc.DS_RESOURCE_ACCESS_URL, 'None')))

                        # distribution format (dcat:mediaType) - required, single
                        log.debug("%s Parsing distribution DCAT.mediaType..." % (method_log_prefix))
                        actual_field = dhc.DISTRIBUTION_MEDIA_TYPE
                        normalize_ckan_format = config.get(
                            'ckanext.dcat.normalize_ckan_format', True)
                        imt, label = self._distribution_format(distribution,
                                                                normalize_ckan_format)
                        if imt and len(imt) > 0:
                            lower_imt = imt.lower()
                            final_value = valid_dict_formats.get(lower_imt, None)
                            if final_value:
                                resource_dict[dhc.DS_RESOURCE_MIMETYPE] = final_value
                                resource_dict[dhc.DS_RESOURCE_FORMAT] = final_value
                                if imt != final_value:
                                    self._add_warningmsg(dhc.FORMAT_NO_CASE_SENSITIVE % (actual_field, imt), isCatalog, prefix_msg)
                            else:
                                self._add_errormsg(dhc.UNEXPECTED_VALUE % (actual_field, imt), isCatalog, prefix_msg)
                        else:
                            self._add_errormsg(dhc.REQUIRED_FIELD_NOT_FOUND % (actual_field), isCatalog, prefix_msg)
                        log.debug("%s Parsed distribution DCT.mediaType...%s" % (method_log_prefix, resource_dict.get(dhc.DS_RESOURCE_FORMAT, 'None')))

                        # distribution size (dcat:byteSize) - optional, single
                        log.debug("%s Parsing distribution DCAT.byteSize..." % (method_log_prefix))
                        actual_field = dhc.DISTRIBUTION_BYTE_SIZE
                        try:
                            size = self._object_value_int(distribution, DCAT.byteSize)
                            if size:
                                resource_dict[dhc.DS_RESOURCE_BYTE_SIZE] = size
                        except RDFParserException as e:
                            self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message, prefix_msg))
                        log.debug("%s Parsed distribution DCT.byteSize...%s" % (method_log_prefix, resource_dict.get(dhc.DS_RESOURCE_BYTE_SIZE, 'None')))

                        # relation (dct:relation) - optional, multiple
                        log.debug("%s Parsing distribution DCT.relation..." % (method_log_prefix))
                        actual_field = dhc.DISTRIBUTION_RELATION
                        dRelations = self.g.objects(distribution, DCT.relation)
                        resource_relations = []
                        if (dRelations):
                            for dRelation in dRelations:
                                if (dRelation):
                                    try:
                                        if isinstance(dRelation, Literal):
                                            dRelationValue = self._strip_value(unicode(dRelation))
                                        else:
                                            dRelationValue = self._strip_value(self._object_value(dRelation, FOAF.page))
                                        if not self._check_empty_field(dRelationValue, actual_field, isCatalog, False, False, prefix_msg):
                                            if dhh.dge_harvest_is_url(dRelationValue):
                                                resource_relations.append(dRelationValue)
                                            else:
                                                self._add_errormsg(dhc.WRONG_URL % (actual_field, dRelationValue), isCatalog, prefix_msg)
                                    except RDFParserException as e:
                                        self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog, prefix_msg)
                        if len(resource_relations) > 0:
                             resource_dict[dhc.DS_RESOURCE_RELATION] = resource_relations
                        dataset_dict[dhc.DS_RESOURCES].append(resource_dict)
                        log.debug("%s Parsed distribution DCT.relation...%s" % (method_log_prefix, resource_dict.get(dhc.DS_RESOURCE_RELATION, 'None')))
                        numDistributions = numDistributions + 1
                actual_field = dhc.DATASET_DISTRIBUTIONS
                if numDistributions == 0:
                    self._add_errormsg(dhc.REQUIRED_FIELD_NOT_FOUND % (actual_field), isCatalog)
                log.debug("%s Parsed dataset DCT....%s" % (method_log_prefix, dataset_dict.get(dhc.DS_RESOURCES, 'None')))
                actual_field = None

        except Exception as e :
            if not actual_field:
                self._add_errormsg(dhc.UNEXPECTED_ERROR % (type(e).__name__, e), isCatalog)
            else:
                self._add_errormsg(dhc.UNEXPECTED_FIELD_ERROR % (actual_field, type(e).__name__, e), isCatalog)

        dataset_dict[dhc.DS_ERRORS].extend(self.dataset_errors)
        dataset_dict[dhc.DS_WARNINGS].extend(self.dataset_warnings)
        log.debug('%s End method. Returns dataset_dict=%r' % (method_log_prefix, dataset_dict))
        return dataset_dict

    def parse_catalog(self, catalog_dict, catalog_ref):
        method_log_prefix = '[%s][parse_catalog]' % type(self).__name__
        log.debug('%s Init method. Inputs: catalog_dict=%r, catalog_ref=%r' % (method_log_prefix, catalog_dict, catalog_ref))
        catalog_dict[dhc.CAT_LANGUAGE] = []
        catalog_dict[dhc.CAT_ERRORS] = []
        catalog_dict[dhc.CAT_WARNINGS] = []
        self.catalog_errors = []
        self.catalog_warnings = []

        isCatalog = True
        actual_field = None
        try:
            do_parsing = True

            if (do_parsing  and catalog_ref and len(catalog_ref) > 0):
                 # Catalog URI (explicitly show the missing ones)
                catalog_dict[dhc.CAT_URI] = (unicode(catalog_ref)
                           if isinstance(catalog_ref, rdflib.term.URIRef)
                           else None)
            else:
                do_parsing = False
                self._add_errormsg(dhc.CATALOG_WRONG_DEFINITION, isCatalog)

            # check if dataset or distribution with the same catalog rdf:about
            if do_parsing:
                if (catalog_ref, DCAT.dataset, catalog_ref) in self.g:
                    do_parsing = False
                    self._add_errormsg(dhc.CATALOG_SAME_ABOUT_DATASET % catalog_ref, isCatalog)

                if (catalog_ref, DCAT.distribution, catalog_ref) in self.g:
                    do_parsing = False
                    self._add_errormsg(dhc.CATALOG_SAME_ABOUT_DISTRIBUTION % catalog_ref, isCatalog)

            if  do_parsing:
                locales_offered = self._get_ckan_locales_offered()
                default_locale = self._get_ckan_default_locale()

                #Get dict configuration
                cat_available_data= {}
                #Get valid themes
                cat_available_data[dhc.CAT_AVAILABLE_THEMES] = dhh.dge_harvest_list_theme_option_value()
                #Get valid spatial coverage
                cat_available_data[dhc.CAT_AVAILABLE_SPATIAL_COVERAGES] = dhh.dge_harvest_list_spatial_coverage_option_value()
                #Get valid resource formats
                cat_available_data[dhc.CAT_AVAILABLE_RESOURCE_FORMATS] = dhh._dge_harvest_list_format_option_value()
                #Get available organizations/publishers
                cat_available_data[dhc.CAT_AVAILABLE_PUBLISHERS] = dhh.dge_harvest_organizations_available()
                catalog_dict[dhc.CAT_AVAILABLE_DATA] = cat_available_data

                # dct:title - required, multiple
                log.debug("%s Parsing catalog DC.language and DCT.language..." % (method_log_prefix))
                actual_field = dhc.CATALOG_LANGUAGE
                languages, wrong_languages = self._get_languages(catalog_ref)
                langs = False
                wlangs = False
                if wrong_languages and len(wrong_languages) > 0:
                    wlangs = True
                if languages and len(languages) > 0: 
                    langs = True
                if langs:
                    if default_locale in languages:
                        catalog_dict[dhc.CAT_LANGUAGE] = languages
                    else:
                        self._add_errormsg(dhc.DEFAULT_LANGUAGE_NOT_FOUND % (actual_field, default_locale), isCatalog)
                    if wlangs:
                       self._add_warningmsg(dhc.UNEXPECTED_LANGUAGES % (actual_field, wrong_languages, locales_offered), isCatalog)
                else:
                    if wlangs:
                        self._add_errormsg(dhc.UNEXPECTED_LANGUAGES % (actual_field, wrong_languages, locales_offered), isCatalog)
                    else:
                        self._add_errormsg(dhc.CATALOG_LANGUAGE_NOT_FOUND % (actual_field, locales_offered), isCatalog)
                log.debug("%s Parsed catalog DC.language and DCT.language....%s" % (method_log_prefix, catalog_dict.get(dhc.CAT_LANGUAGE, 'None')))

                # Name (dct:title) - required, multiple -- multilanguage
                if catalog_dict[dhc.CAT_LANGUAGE] is not None and len(catalog_dict[dhc.CAT_LANGUAGE]) > 0:
                    log.debug("%s Parsing catalog DCT.title..." % (method_log_prefix))
                    actual_field = dhc.CATALOG_TITLE
                    translates = self._get_field_translates(catalog_dict[dhc.CAT_LANGUAGE], catalog_ref, DCT.title, True, dhc.CATALOG_TITLE, isCatalog)
                    if translates:
                        catalog_dict[dhc.CAT_TITLE_TRANSLATE] = json.dumps(translates)
                    log.debug("%s Parsed catalog DCT.title_translated....%s" % (method_log_prefix, catalog_dict.get(dhc.CAT_TITLE_TRANSLATE, 'None')))

                # Description (dct:description) - required, multiple -- multilanguage
                if catalog_dict[dhc.CAT_LANGUAGE] is not None and len(catalog_dict[dhc.CAT_LANGUAGE]) > 0:
                    log.debug("%s Parsing catalog DCT.description..." % (method_log_prefix))
                    actual_field = dhc.CATALOG_DESCRIPTION
                    translates = self._get_field_translates(catalog_dict[dhc.CAT_LANGUAGE], catalog_ref, DCT.description, True, dhc.CATALOG_DESCRIPTION, isCatalog)
                    if translates:
                        catalog_dict[dhc.CAT_DESCRIPTION] = json.dumps(translates)
                    log.debug("%s Parsed catalog DCT.description....%s" % (method_log_prefix, catalog_dict.get(dhc.CAT_DESCRIPTION, 'None')))

                # Publisher (dct:publisher) - required, single
                log.debug("%s Parsing catalog DCT.publisher..." % (method_log_prefix))
                actual_field = dhc.CATALOG_PUBLISHER
                try:
                    publisher = self._strip_value(self._object_value(catalog_ref, DCT.publisher))
                    if not self._check_empty_field(publisher, actual_field, isCatalog, True, False):
                        idminhap = self._get_publisher_id_minhap(publisher, actual_field, isCatalog)
                        if idminhap:
                            catalog_dict[dhc.CAT_PUBLISHER_ID_MINHAP] = idminhap
                            publisher_organization = cat_available_data.get(dhc.CAT_AVAILABLE_PUBLISHERS, {}).get(idminhap, [])
                            if publisher_organization and len(publisher_organization) == 2:
                                catalog_dict[dhc.CAT_PUBLISHER] = publisher_organization[0]
                                catalog_dict[dhc.CAT_PUBLISHER_NAME] = publisher_organization[1]
                            else:
                                self._add_errormsg(dhc.UNEXPECTED_PUBLISHER % (actual_field, (dhc.PUBLISHER_PREFIX + idminhap)), isCatalog)                           
                except RDFParserException as e:
                    self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message))
                log.debug("%s Parsed catalog DCT.publisher....%s" % (method_log_prefix, catalog_dict.get(dhc.CAT_PUBLISHER_ID_MINHAP, 'None')))

                # Catalog size (dct:extent) - optional, single
                log.debug("%s Parsing catalog DCT.extent..." % (method_log_prefix))
                actual_field = dhc.CATALOG_EXTENT
                try:
                    exists = False
                    for extent in self.g.objects(catalog_ref, DCT.extent):
                        if not exists:
                            if isinstance(extent, BNode) and \
                             (extent, RDF.type, DCT.SizeOrDuration) in self.g:
                                size = self._object_value_int(extent, RDF.value)
                                if size:
                                    catalog_dict[dhc.CAT_SIZE] = size
                                exists = True
                        else:
                            self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, dhc.UNEXPECTED_MULTIPLE_OBJECTS), isCatalog)
                except RDFParserException as e:
                    self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed catalog DCT.extent....%s" % (method_log_prefix, catalog_dict.get(dhc.CAT_SIZE, 'None')))

                # Identifier (dct:identifier) -  optional, single
                log.debug("%s Parsing catalog DCT.identifier..." % (method_log_prefix))
                actual_field = dhc.CATALOG_IDENTIFIER
                try:
                    cIdentifier = self._strip_value(self._object_value(catalog_ref, DCT.identifier))
                    if not self._check_empty_field(cIdentifier, actual_field, isCatalog, False, False):
                        if self._is_uri(cIdentifier):
                            catalog_dict[dhc.CAT_IDENTIFIER] = cIdentifier
                        else:
                            self._add_errormsg(dhc.WRONG_URI % (actual_field, cIdentifier), isCatalog)
                except RDFParserException as e:
                    self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed catalog DCT.identifier....%s" % (method_log_prefix, catalog_dict.get(dhc.CAT_IDENTIFIER, 'None')))

                # Creation date (dct:issued) - required, single
                log.debug("%s Parsing catalog DCT.issued..." % (method_log_prefix))
                actual_field = dhc.CATALOG_ISSUED
                try:
                    cDate, cType = self._object_value_datatype(catalog_ref, DCT.issued)
                    cDate = self._strip_value(cDate)
                    if not self._check_empty_field(cDate, actual_field, isCatalog, True, False):
                        catalog_dict[dhc.CAT_ISSUED_DATE] = self._validate_iso8601_date(cDate, cType)
                except RDFParserException as e:
                    self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed catalog DCT.issued....%s" % (method_log_prefix, catalog_dict.get(dhc.CAT_ISSUED_DATE, 'None')))

                # Date of last update (dct:modified) - required, single
                log.debug("%s Parsing catalog DCT.modified..." % (method_log_prefix))
                actual_field = dhc.CATALOG_MODIFIED
                try:
                    uDate, uType = self._object_value_datatype(catalog_ref, DCT.modified)
                    uDate = self._strip_value(uDate)
                    if not self._check_empty_field(uDate, actual_field, isCatalog, True, False):
                        catalog_dict[dhc.CAT_MODIFIED_DATE] = self._validate_iso8601_date(uDate, uType)
                except RDFParserException as e:
                    self._add_errormsg("%s, %s" % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed catalog DCT.modified....%s" % (method_log_prefix, catalog_dict.get(dhc.CAT_MODIFIED_DATE, 'None')))

                # Spatial coverage (dct:spatial) - optional, multiple
                log.debug("%s Parsing catalog DCT.spatial..." % (method_log_prefix))
                actual_field = dhc.CATALOG_SPATIAL
                spatials = self._object_value_list(catalog_ref, DCT.spatial)
                if (spatials):
                    spatialList = []
                    warnSpatials = []
                    num_expected_values = 0
                    for spatial in spatials:
                        spatial = self._strip_value(spatial)
                        if not self._check_empty_field(spatial, actual_field, isCatalog, False, False):
                            lower_spatial = spatial.lower()
                            if (lower_spatial.find(dhc.SPATIAL_PREFIX.lower()) == 0):
                                final_value =  cat_available_data.get(dhc.CAT_AVAILABLE_SPATIAL_COVERAGES, {}).get(lower_spatial, None)
                                if not final_value:
                                    self._add_errormsg(dhc.UNEXPECTED_VALUE % (actual_field, spatial), isCatalog)
                                else:
                                    spatialList.append(final_value)
                                    if spatial != final_value:
                                        warnSpatials.append(spatial)
                                    if (lower_spatial.find(dhc.SPATIAL_PROVINCE_PREFIX.lower()) == 0\
                                        or spatial.find(dhc.SPATIAL_CCAA_PREFIX.lower()) == 0):
                                        num_expected_values = num_expected_values + 1
                    if spatialList and len(spatialList) > 0:
                        catalog_dict[dhc.CAT_SPATIAL] = spatialList
                    if warnSpatials and len(warnSpatials) > 0:
                        self._add_warningmsg(dhc.VALUE_NO_CASE_SENSITIVE % (actual_field, ", ".join(warnSpatials)), isCatalog)
#                     if num_expected_values == 0:
#                         self._add_warningmsg((dhc.UNEXPECTED_SPATIAL_COVERAGE_VALUES % (actual_field)), isCatalog)
                log.debug("%s Parsed catalog DCT.spatial....%s" % (method_log_prefix, catalog_dict.get(dhc.CAT_SPATIAL, 'None')))

                # Theme (dcat:themeTaxonomy) - required, multiple
                log.debug("%s Parsing catalog DCAT.themeTaxonomy..." % (method_log_prefix))
                actual_field = dhc.CATALOG_THEME_TAXONOMY
                themes = self._object_value_list(catalog_ref, DCAT.themeTaxonomy)
                finalThemes = []
                if themes:
                    expected_theme = False
                    # Remove duplicates
                    for theme in themes:
                        theme = self._strip_value(theme)
                        if not self._check_empty_field(theme, actual_field, isCatalog, True, False):
                            if dhh.dge_harvest_is_url(theme):
                                lower_theme = theme.lower()
                                if lower_theme == dhc.THEME_PREFIX_SLASH or \
                                   lower_theme == dhc.THEME_PREFIX:
                                    expected_theme = True
                                    if theme != dhc.THEME_PREFIX_SLASH and \
                                       theme != dhc.THEME_PREFIX:
                                        self._add_warningmsg(dhc.REQUIRED_VALUE_NOT_FOUND_CASE_SENSITIVE % (actual_field, theme, dhc.THEME_PREFIX_SLASH), isCatalog)
                                if lower_theme not in finalThemes:
                                    finalThemes.append(lower_theme)
                            else:
                                self._add_errormsg(dhc.WRONG_URL % (actual_field, theme), isCatalog)
                    if not expected_theme:
                        self._add_errormsg(dhc.REQUIRED_VALUE_NOT_FOUND % (actual_field, dhc.THEME_PREFIX), isCatalog)
                    if finalThemes and len(finalThemes) > 0:
                        catalog_dict[dhc.CAT_THEME_TAXONOMY] = finalThemes
                    else:
                        self._add_errormsg(dhc.REQUIRED_FIELD_NOT_FOUND % (actual_field), isCatalog)
                else:
                    self._add_errormsg(dhc.REQUIRED_FIELD_NOT_FOUND % (actual_field), isCatalog)
                log.debug("%s Parsed catalog DCAT.themeTaxonomy....%s" % (method_log_prefix, catalog_dict.get(dhc.CAT_THEME_TAXONOMY, 'None')))

                # web (foaf:homepage) - required, single
                log.debug("%s Parsing catalog FOAF.homepage..." % (method_log_prefix))
                actual_field = dhc.CATALOG_HOMEPAGE
                try:
                    homepage = self._strip_value(self._object_value(catalog_ref, FOAF.homepage))
                    if not self._check_empty_field(homepage, actual_field, isCatalog, True, False):
                        if dhh.dge_harvest_is_url(homepage):
                            catalog_dict[dhc.CAT_HOMEPAGE] = homepage
                        else:
                            self._add_errormsg(dhc.WRONG_URL % (actual_field, homepage), isCatalog)
                except RDFParserException as e:
                     self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed catalog FOAF.homepage....%s" % (method_log_prefix, catalog_dict.get(dhc.CAT_HOMEPAGE, 'None')))

                # License (dct:license) - required, single
                log.debug("%s Parsing catalog DCT.license..." % (method_log_prefix))
                actual_field = dhc.CATALOG_LICENSE
                try:
                    license = self._strip_value(self._object_value(catalog_ref, DCT.license))
                    if not self._check_empty_field(license, actual_field, isCatalog, True, False):
                        if dhh.dge_harvest_is_url(license):
                            catalog_dict[dhc.CAT_LICENSE] = license
                        else:
                            self._add_errormsg(dhc.WRONG_URL % (actual_field, license), isCatalog)
                except RDFParserException as e:
                    self._add_errormsg(dhc.FIELD_PLUS_MESSAGE % (actual_field, e.message), isCatalog)
                log.debug("%s Parsed catalog DC.license....%s" % (method_log_prefix, catalog_dict.get(dhc.CAT_LICENSE, 'None')))

                # dataset (dct:dataset) - required, multiple
                log.debug("%s Parsing catalog DCAT.dataset..." % (method_log_prefix))
                actual_field = dhc.CATALOG_DATASET
                num_datasets = 0
                for o in self.g.objects(catalog_ref, DCAT.dataset):
                    num_datasets = num_datasets + 1
                if num_datasets == 0:
                    self._add_errormsg(dhc.REQUIRED_FIELD_NOT_FOUND % (actual_field), isCatalog)
                log.debug("%s Parsed catalog DCAT.dataset....%s datasets in catalog" % (method_log_prefix, num_datasets))

            actual_field = None

        except Exception as e :
            if not actual_field:
                self._add_errormsg(dhc.UNEXPECTED_ERROR % (type(e).__name__, e), isCatalog)
            else:
                self._add_errormsg(dhc.UNEXPECTED_FIELD_ERROR % (actual_field, type(e).__name__, e), isCatalog)

        catalog_dict[dhc.CAT_ERRORS].extend(self.catalog_errors)
        catalog_dict[dhc.CAT_WARNINGS].extend(self.catalog_warnings)
        log.debug('%s End method. Returns catalog_dict=%r' % (method_log_prefix, catalog_dict))
        return catalog_dict

    def graph_from_dataset(self, dataset_dict, dataset_ref):
        method_log_prefix = '[%s][graph_from_dataset]' % type(self).__name__
        #log.debug('%s Init method. Inputs dataset_dict=%r, dataset_ref=%r' % (method_log_prefix, dataset_dict, dataset_ref))
        #log.debug('%s Init method. Inputs, dataset_ref=%r' % (method_log_prefix, dataset_ref))
        try:
            g = self.g

            for prefix, namespace in namespaces.iteritems():
                g.bind(prefix, namespace)

            g.add((dataset_ref, RDF.type, DCAT.Dataset))

            # Title
            self._add_translated_triple_field_from_dict(dataset_dict, dataset_ref, DCT.title, dhc.DS_TITLE_TRANSLATED, None)

            # Description
            self._add_translated_triple_field_from_dict(dataset_dict, dataset_ref, DCT.description, dhc.DS_DESCRIPTION, None)

            # Theme
            value = self._get_dict_value(dataset_dict, dhc.DS_THEME)
            if value:
                themes = dataset_dict.get(dhc.EXPORT_AVAILABLE_THEMES, {})
                for theme in value:
                    #self._add_resource_list_triple(dataset_ref, DCAT.theme, value)
                    theme_values = themes.get(theme, {})
                    labels = theme_values.get('label')
                    descriptions = theme_values.get('description')
                    dcat_ap = theme_values.get('dcat_ap')
                    notation = theme_values.get('notation')
                    self._add_resource_list_triple(dataset_ref, DCAT.theme, theme, labels, descriptions, dcat_ap, notation)

            # Tags
            for tag in dataset_dict.get('tags', []):
                self.g.add((dataset_ref, DCAT.keyword, Literal(tag['name'])))

            # Identifier
            self._add_triple_from_dict(dataset_dict, dataset_ref, DCT.identifier, dhc.DS_IDENTIFIER, None, False, False)

            # Issued, Modified dates
            self._add_date_triple(dataset_ref, DCT.issued, self._get_value_from_dict(dataset_dict, dhc.DS_ISSUED_DATE, ['metadata_created']))
            self._add_date_triple(dataset_ref, DCT.modified, self._get_value_from_dict(dataset_dict, dhc.DS_MODIFIED_DATE, ['metadata_modified']))
            self._add_date_triple(dataset_ref, DCT.valid, self._get_value_from_dict(dataset_dict, dhc.DS_VALID, None))

            # Accrual periodicity  
            frequency = dataset_dict.get(dhc.DS_FREQUENCY)
            if frequency:
                ftypes = {'seconds': TIME.seconds, 
                     'minutes': TIME.minutes, 
                     'hours': TIME.hours, 
                     'days': TIME.days, 
                     'weeks': TIME.weeks, 
                     'months': TIME.months, 
                     'years': TIME.years}
                ftype = frequency.get('type')
                fvalue = frequency.get('value')
                if ftype and ftype in ftypes.keys() and fvalue:
                    frequency = URIRef("%s/%s" %(dataset_ref, 'Frequency'))
                    duration = URIRef("%s/%s" %(dataset_ref, 'DurationDescription'))
                    g.add((frequency, RDF.type, DCT.Frequency))
                    g.add((duration, RDF.type, TIME.DurationDescription))
                    g.add((dataset_ref, DCT.accrualPeriodicity, frequency))
                    g.add((frequency, RDF.value, duration))
                    g.add((duration, ftypes.get(ftype), Literal(fvalue, datatype=XSD.decimal)))

            # Languages
            self._add_triple_from_dict(dataset_dict, dataset_ref, DCT.language, dhc.DS_LANGUAGE, None, True, False)

            # Publisher
            publishers = dataset_dict.get(dhc.EXPORT_AVAILABLE_PUBLISHERS, {})
            organization_id = dataset_dict.get('publisher')
            if organization_id in publishers:
                publisher = publishers.get(organization_id)
            else:
                publisher = []
                org = h.get_organization(organization_id, False)
                publisher = [org.get('title'), None, None]
                if org and org['extras']:
                    for extra in org.get('extras'):
                        if extra and 'key' in extra and extra['key'] == dhc.ORG_PROP_ID_UD_ORGANICA:
                            notation = extra.get('value')
                            publisher[1] = dhc.PUBLISHER_PREFIX + notation
                            publisher[2] = notation
                publishers[organization_id] = publisher
                dataset_dict[dhc.EXPORT_AVAILABLE_PUBLISHERS] = publishers
            if publisher:
                #g.add((dataset_ref, DCT.publisher, URIRef(publisher[1])))
                self._add_resource_list_triple(dataset_ref, DCT.publisher, publisher[1], publisher[0], None, None, publisher[2])

            # Spatial Coverage
            value = self._get_dict_value(dataset_dict, dhc.DS_SPATIAL)
            if value:
                self._add_resource_list_triple(dataset_ref, DCT.spatial, value)

            # Temporal
            temporal_coverage = self._get_dataset_value(dataset_dict, dhc.DS_TEMPORAL_COVERAGE)
            i = 1
            if temporal_coverage:
                for key, value in temporal_coverage.items():
                    if (value):
                        start = end = None
                        if 'from' in value:
                            start = value.get('from')
                        if 'to' in value:
                            end = value.get('to')
                        if start or end:
                            temporal_extent = URIRef("%s/%s-%s" %(dataset_ref, 'PeriodOfTime',i))
                            g.add((temporal_extent, RDF.type, DCT.PeriodOfTime))
                            if start:
                                self._add_date_triple(temporal_extent, SCHEMA.startDate, start)
                            if end:
                                self._add_date_triple(temporal_extent, SCHEMA.endDate, end)
                            g.add((dataset_ref, DCT.temporal, temporal_extent))
                            i = i+1

            # References 
            value = self._get_dict_value(dataset_dict, dhc.DS_REFERENCE)
            if value:
                self._add_resource_list_triple(dataset_ref, DCT.references, value)

            # Conforms To
            value = self._get_dict_value(dataset_dict, dhc.DS_NORMATIVE)
            if value:
                self._add_resource_list_triple(dataset_ref, DCT.conformsTo, value)

            # Distributions/Resources
            for resource_dict in dataset_dict.get('resources', []):
                uri_resource = '%s/resource/%s' % (dataset_ref, resource_dict['id'])
                distribution = URIRef(uri_resource)
                g.add((dataset_ref, DCAT.distribution, distribution))
                g.add((distribution, RDF.type, DCAT.Distribution))

                # Identifier
                self._add_triple_from_dict(resource_dict, distribution, DCT.identifier, dhc.DS_RESOURCE_IDENTIFIER, None, False, False)

                # Title
                self._add_translated_triple_field_from_dict(resource_dict, distribution, DCT.title, dhc.DS_RESOURCE_NAME_TRANSLATED, None)

                # License (dataset license)
                if dataset_dict.get(dhc.DS_LICENSE):
                    g.add((distribution, DCT.license, URIRef(dataset_dict.get(dhc.DS_LICENSE))))

                # Access URL
                if resource_dict.get(dhc.DS_RESOURCE_ACCESS_URL):
                    g.add((distribution, DCAT.accessURL, Literal(resource_dict.get(dhc.DS_RESOURCE_ACCESS_URL), datatype=XSD.anyURI)))

                # Format
                if resource_dict.get(dhc.DS_RESOURCE_FORMAT, None):
                    imt = URIRef("%s/format" % uri_resource)
                    g.add((imt, RDF.type, DCT.IMT))
                    g.add((distribution, DCT['format'], imt))
                    
                    format = resource_dict.get(dhc.DS_RESOURCE_FORMAT, None)
                    formats = dataset_dict.get(dhc.EXPORT_AVAILABLE_RESOURCE_FORMATS, {})
                    label = None
                    if format and format in formats:
                        label = formats.get(format, None)
                    else:
                        _dataset = sh.scheming_get_schema('dataset', 'dataset')
                        res_format = sh.scheming_field_by_name(_dataset.get('resource_fields'),
                                                               'format')
                        formats[format] = sh.scheming_choices_label(res_format['choices'], format)
                        label = formats.get(format, None)
                        dataset_dict[dhc.EXPORT_AVAILABLE_RESOURCE_FORMATS] = formats
                    if label:
                        g.add((imt, RDFS.label, Literal(label)))
                    g.add((imt, RDF.value, Literal(resource_dict[dhc.DS_RESOURCE_FORMAT])))

                # Size
                if resource_dict.get(dhc.DS_RESOURCE_BYTE_SIZE):
                    try:
                        g.add((distribution, DCAT.byteSize,
                               Literal(float(resource_dict[dhc.DS_RESOURCE_BYTE_SIZE]),
                                       datatype=XSD.decimal)))
                    except (ValueError, TypeError):
                        g.add((distribution, DCAT.byteSize,
                               Literal(resource_dict[dhc.DS_RESOURCE_BYTE_SIZE])))
                # Relation
                value = self._get_dict_value(dataset_dict, dhc.DS_NORMATIVE)
                if value:
                    self._add_resource_list_triple(distribution, DCT.relation, value)

        except Exception, e:
            log.error("%s [dataset_ref: %s]. Unexpected Error %s: %s" % (method_log_prefix, dataset_ref, type(e).__name__, e))
        except:
            log.error("%s [dataset_ref: %s]. Unexpected Generic Error" % (method_log_prefix, dataset_ref))
        #log.debug('%s End method dataset_ref: %s' % (method_log_prefix, dataset_ref))

    def graph_from_catalog(self, catalog_dict, catalog_ref):
        method_log_prefix = '[%s][graph_from_catalog]' % type(self).__name__
        log.debug('%s Init method. Inputs: catalog_dict=%r, catalog_ref=%r' % (method_log_prefix, catalog_dict, catalog_ref))
        try:
            self.organizations = {}

            g = self.g

            for prefix, namespace in namespaces.iteritems():
                g.bind(prefix, namespace)

            g.add((catalog_ref, RDF.type, DCAT.Catalog))

           # Languages
            default_locale = self._get_ckan_default_locale()
            locales_offered = self._get_ckan_locales_offered().split()
            if (locales_offered):
                for locale in locales_offered:
                    g.add((catalog_ref, DCT.language, Literal(locale)))
 
            # Translate fields
            default_title = config.get('ckanext.dge_harvest.catalog.title', None)
            default_description = config.get('ckanext.dge_harvest.catalog.description', None)
            items = [
                ('title', DCT.title, default_title, default_locale),
                ('description', DCT.description, default_description, default_locale)
            ]
            if (locales_offered):
                items = []
                for locale in locales_offered:
                    items.append(('title_' + locale, DCT.title, config.get('ckanext.dge_harvest.catalog.title_' + locale, default_title), locale))
                    items.append(('description_' + locale, DCT.description, config.get('ckanext.dge_harvest.catalog.description_' + locale, default_description), locale))

            for item in items:
                key, predicate, fallback, locale = item
                if catalog_dict:
                    value = catalog_dict.get(key, fallback)
                else:
                    value = fallback
                if value:
                    g.add((catalog_ref, predicate, Literal(value, lang=locale)))

            # Basic fields
            items = [
                ('homepage', FOAF.homepage, config.get('ckanext.dge_harvest.catalog.homepage')),
                ('spatial', DCT.spatial, config.get('ckanext.dge_harvest.catalog.spatial')),
                ('themeTaxonomy', DCAT.themeTaxonomy, config.get('ckanext.dge_harvest.catalog.theme_taxonomy')),
                ('license', DCT.license, config.get('ckanext.dge_harvest.catalog.license')),
                ('publisher', DCT.publisher, config.get('ckanext.dge_harvest.catalog.publisher'))
            ]
            
            for item in items:
                key, predicate, fallback = item
                if catalog_dict:
                    value = catalog_dict.get(key, fallback)
                else:
                    value = fallback
                if value:
                    g.add((catalog_ref, predicate, URIRef(value)))

            #publisher
            
            organizations = dhh.dge_harvest_organizations_available()
            publisher = config.get('ckanext.dge_harvest.catalog.publisher', None)
            if publisher:
                uriref_publisher = URIRef(publisher)
                s_publisher = publisher.upper().split('/')
                if s_publisher and len(s_publisher) > 0:
                    organization_minhap = s_publisher[-1]
                    org = organizations.get(organization_minhap, None)
                    if org:
                        publisher = [org[1], dhc.PUBLISHER_PREFIX+organization_minhap, organization_minhap]
                        self._add_skos_concept(uriref_publisher, publisher[1], publisher[0], None, None, publisher[2])

            # Dates
            modified = self._last_catalog_modification()
            if modified:
                self._add_date_triple(catalog_ref, DCT.modified, modified)

            #Issued
            issued = config.get('ckanext.dge_harvest.catalog.issued', None)
            if issued:
                self._add_date_triple(catalog_ref, DCT.issued, issued)
            catalog_dict[dhc.EXPORT_AVAILABLE_RESOURCE_FORMATS] = dhh._dge_harvest_list_format_option_value()
        except Exception, e:
            log.error("%s Unexpected Error %s: %s"  % (method_log_prefix, type(e).__name__, e))
        except:
            log.error("%s Unexpected Generic Error" % (method_log_prefix))
        log.debug('%s End method' % (method_log_prefix))

class DgeMigrateProfile(DgeProfile):
    '''
    An RDF migrate profile based on the DCAT-AP for data portals in Europe

    More information and specification:

    https://joinup.ec.europa.eu/asset/dcat_application_profile

    '''
    def _is_uri(self, uri):
        return True

    def _get_field_translates(self, catalog_languages, subject, predicate, required, field_name, isCatalog, prefix_msg=None):
        '''
        Returns a dictionary with translates of the objects found 
        from given the subject and predicate
        
        Given a subject, predicate and catalog_languages, 
        search their objects in the graph and 
        get the translates of this objects in the catalog_languages
        
        Returns a dictionary with translates;
        None if required is false and no object is found; 
        RDFParserException if required is true and all translates 
        do not found
        '''
        method_log_prefix = '[%s][_get_field_translates]' % type(self).__name__
        log.debug("%s Init method. Inputs: catalog_languages=%r, subject=%r, predicate=%r, required=%r, field_name=%r, isCatalog%r" % (method_log_prefix, catalog_languages, subject, predicate, required, field_name, isCatalog))
        if (field_name is None):
            field_name = predicate
        result = None
        wrong_definition = False
        field_in_default_language = False
        default_language = self._get_ckan_default_locale()
        if catalog_languages is None or len(catalog_languages) == 0:
            self._add_warningmsg(dhc.CATALOG_NO_LANGUAGES, prefix_msg)
        elif subject is not None and predicate is not None:
            objects = self.g.objects(subject, predicate)
            if objects is None:
                if required:
                    self._add_errormsg(dhc.REQUIRED_FIELD_NOT_FOUND % (field_name), isCatalog, prefix_msg)
            else:
                translates = {}  # objects with language
                unexpected_translates = {}
                no_translate = None  # object without language
                no_translate_number = 0
                languages = []  # languages found
                unexpected_languages = []
                multiples_same_language = []
                multiples_no_language = False
                empty_value_for_languages = []
                empty_value_no_languages = False
                total = 0
                for object in objects:
                    if object and isinstance(object, Literal):
                        value = self._strip_value(unicode(object))
                        if not self._check_empty_field(value, field_name, isCatalog, True, False):
                            if hasattr(object, 'language') and object.language:
                                if object.language in catalog_languages:
                                    if object.language not in translates:
                                        translates[object.language] = value
                                        total = total + 1
                                        if object.language == default_language:
                                            field_in_default_language = True
                                        languages.append(object.language)
                                    else:
                                        if (object.language not in multiples_same_language):
                                            multiples_same_language.append(object.language)
                                else:
                                    if (object.language not in unexpected_languages):
                                        unexpected_languages.append(object.language)
                                        unexpected_translates[object.language] = value
                            else:
                                no_translate_number = no_translate_number + 1
                                if no_translate is None:
                                    no_translate = value
                                    total = total + 1
                                else:
                                    multiples_no_language = True
                        else:
                            if hasattr(object, 'language') and object.language:
                                if (object.language not in empty_value_for_languages):
                                    empty_value_for_languages.append(object.language)
                            else:
                                empty_value_no_languages = True
                    else:
                        self._add_errormsg(dhc.REQUIRED_LITERAL_OBJECTS % (field_name), isCatalog, prefix_msg)
                        wrong_definition = True;
                        break;
                if wrong_definition:
                    return None;
                if not field_in_default_language:
                    value = None
                    if len(translates) > 0:
                        value = translates.get(languages[0])
#                     elif len(unexpected_translates) > 0:
#                         value = unexpected_translates.get(unexpected_languages[0])
                    if value:
                        translates[default_language] = value
                        languages.append(default_language)
                        field_in_default_language = True

                warn_msgs = []
                error_msgs = []
                # Warnings for empty values
                if len(empty_value_for_languages) > 0:
                    warn_msgs.append(dhc.EMPTY_VALUE_IN_LANGUAGE % (field_name, ", ".join(empty_value_for_languages)))
                if empty_value_no_languages:
                    warn_msgs.append(dhc.EMPTY_VALUE_NO_LANGUAGE % (field_name))
                # Errors multiples values in the same language or no language
                if multiples_no_language:
                    error_msgs.append(dhc.UNEXPECTED_MULTIPLES_VALUES_WITHOUT_LANGUAGE % (field_name))
                if len(multiples_same_language) > 0:
                    error_msgs.append(dhc.UNEXPECTED_MULTIPLES_VALUES_SAME_LANGUAGE % (field_name, ",".join(multiples_same_language)))
                # Warnings for values in unexpected language
                if len(unexpected_languages) > 0:
                    warn_msgs.append(dhc.VALUE_IN_UNEXPECTED_LANGUAGE % (field_name, ",".join(unexpected_languages)))

                if total == 0:
                    # no allowed objects
                    if required and isCatalog:
                        error_msgs.append(dhc.EXPECTED_IN_ALL_CATALOG_LANGUAGE % (field_name))
                    elif required and not isCatalog:
                        error_msgs.append(dhc.EXPECTED_IN_DEFAULT_CATALOG_LANGUAGE % (field_name, default_language))
                else:
                    if len(catalog_languages) == len(translates):
                        result = translates
                    else:
                        languages_not_found = []
                        if not isCatalog:
                            for lang in catalog_languages:
                                if lang not in languages:
                                    languages_not_found.append(lang)
                            if len(languages_not_found) > 1 or \
                               (len(languages_not_found) == 1 and languages_not_found[0] != default_language):
                                warn_msgs.append(dhc.VALUE_NOT_FOUND_IN_EXPECTED_LANGUAGE % (field_name, ", ".join(languages_not_found)))

                        if len(catalog_languages) == 1:
                            if (no_translate is not None and no_translate_number == 1):
                                if result is None:
                                    result = {}
                                result[catalog_languages[0]] = no_translate
                            else:
                                if isCatalog:
                                    error_msgs.append(dhc.EXPECTED_IN_ALL_CATALOG_LANGUAGE % (field_name))
                                elif not field_in_default_language:
                                    error_msgs.append(dhc.EXPECTED_IN_DEFAULT_CATALOG_LANGUAGE % (field_name, default_language))
                        else:
                            result
                            if isCatalog:
                                error_msgs.append(dhc.EXPECTED_IN_ALL_CATALOG_LANGUAGE % (field_name))
                            else:
                                if field_in_default_language:
                                    result = translates
                                else:
                                    error_msgs.append(dhc.EXPECTED_IN_DEFAULT_CATALOG_LANGUAGE % (field_name, default_language))

                if len(warn_msgs) > 0:
                    message = "; ".join(warn_msgs)
                    self._add_warningmsg(message, isCatalog, prefix_msg)
                if len(error_msgs) > 0:
                    message = "; ".join(error_msgs)
                    self._add_errormsg(message, isCatalog, prefix_msg)
        log.debug("%s End method. Returns %r" % (method_log_prefix, result))
        return result

class DgeMigrateDrupalProfile(DgeProfile):
    '''
    An RDF migrate profile based on the DCAT-AP for data portals in Europe

    More information and specification:

    https://joinup.ec.europa.eu/asset/dcat_application_profile

    '''
    def parse_dataset(self, dataset_dict, dataset_ref):
        method_log_prefix = '[%s][parse_dataset]' % type(self).__name__
        log.debug('%s Init mehtod. Inputs: dataset_dict=%r, dataset_ref=%r' % (method_log_prefix, dataset_dict, dataset_ref))
        dataset_dict = super(DgeMigrateDrupalProfile, self).parse_dataset(dataset_dict, dataset_ref)
        self.dataset_errors = []
        self.dataset_warnings = []
        isCatalog = False
        actual_field = None

        try:
            if dhc.CAT_LANGUAGE in dataset_dict and dataset_dict[dhc.CAT_LANGUAGE] is not None:
                catalog_language = dataset_dict[dhc.CAT_LANGUAGE]
            if dhc.DS_DEFAULT_CATALOG_LANGUAGE in dataset_dict and dataset_dict[dhc.DS_DEFAULT_CATALOG_LANGUAGE] is not None:
                default_catalog_language = dataset_dict[dhc.DS_DEFAULT_CATALOG_LANGUAGE]

            # rate (dcat:rate) - optional, single
            log.debug("%s Parsing dataset DCT.rate..." % (method_log_prefix))
            actual_field = "rate"
            key_dict = "rate"
            rate = self._strip_value(self._object_value(dataset_ref, DCT.rate))
            if not self._check_empty_field(rate, actual_field, isCatalog, False, False, None):
                dataset_dict[key_dict] = rate
            log.debug("%s Parsed dataset DCT.rate...%s" % (method_log_prefix, dataset_dict[key_dict] if key_dict in dataset_dict and dataset_dict[key_dict] is not None else 'None')) 

            # rateInfo - optional, multiple -- multilanguage
            log.debug("%s Parsing dataset DCT.rateInfo..." % (method_log_prefix))
            actual_field = "rateInfo"
            key_dict = "rate_info"
            translates = self._get_field_translates(catalog_language, dataset_ref, DCT.rateInfo, False, actual_field, isCatalog)
            if translates:
                dataset_dict[key_dict] = translates
            log.debug("%s Parsed dataset DCT.rateInfo...%s" % (method_log_prefix, dataset_dict[key_dict] if key_dict in dataset_dict and dataset_dict[key_dict] is not None else 'None'))

            #remove dhc.DATASET_LICENSE errors
            for error in dataset_dict[dhc.DS_ERRORS][:]:
                log.debug("%s Deleting dataset license_id error" % (method_log_prefix))
                num_errors = 0
                if error and error.find(dhc.DATASET_LICENSE) >= 0:
                    dataset_dict[dhc.DS_ERRORS].remove(error)
                    num_errors = num_errors +1
                if num_errors > 0:
                    dataset_dict[dhc.DS_LICENSE] = ''
                log.debug("%s Delete %s dataset license_id errors" % (method_log_prefix, num_errors))

        except Exception as e :
            if not actual_field:
                self._add_errormsg(dhc.UNEXPECTED_ERROR % (type(e).__name__, e), isCatalog)
            else:
                self._add_errormsg(dhc.UNEXPECTED_FIELD_ERROR % (actual_field, type(e).__name__, e), isCatalog)

        dataset_dict[dhc.DS_WARNINGS].extend(self.dataset_warnings)
        dataset_dict[dhc.DS_ERRORS].extend(self.dataset_errors)
        log.debug('%s: End method. Returns dataset_dict=%r' % (method_log_prefix, dataset_dict))
        return dataset_dict