# Copyright (C) 2022 Entidad Pública Empresarial Red.es
#
# This file is part of "dge_harvest (datos.gob.es)".
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

# -*- coding: utf-8 -*-

'''
Stores constants with
 metadata names
 the error and warning messages used in the harvester
'''
# parts of rfd
CATALOG = u'Cat\u00E1logo'
DATASET = u'Dataset'
DISTRIBUTION = u'Distribuci\u00F3n'

# metadata names
CATALOG_TITLE = u'Nombre (dct:title)'
CATALOG_DESCRIPTION = u'Descripci\u00F3n (dct:description)'
CATALOG_PUBLISHER = u'\u00D3rgano publicador (dct:publisher)'
CATALOG_EXTENT = u'Tama\u00F1o del cat\u00E1logo (dct:extent)'
CATALOG_IDENTIFIER = u'Identificador (dct:identifier)'
CATALOG_ISSUED = u'Fecha de creaci\u00F3n (dct:issued)'
CATALOG_MODIFIED = u'Fecha de actualizaci\u00F3n (dct:modified)'
CATALOG_LANGUAGE = u'Idioma (dc:language o dct:language)'
CATALOG_LANGUAGES = u'Idioma(s) (dc:language o dct:language)'
CATALOG_SPATIAL = u'Cobertura geogr\u00E1fica (dct:spatial)'
CATALOG_THEME_TAXONOMY = u'Tem\u00E1ticas (dcat:themeTaxonomy)'
CATALOG_HOMEPAGE = u'P\u00E1gina web (foaf:homepage)'
CATALOG_LICENSE = u'T\u00E9rminos de uso (dct:license)'
CATALOG_DATASET = u'Dataset (dcat:dataset)'
CATALOG_DATASETS = u'Datasets (dcat:dataset)'

DATASET_TITLE = u'Nombre (dct:title)'
DATASET_CKAN_TITLE = u'Nombre en CKAN (dct:title)'
DATASET_DESCRIPTION = u'Descripci\u00F3n (dct:description)'
DATASET_THEME = u'Tem\u00E1tica (dcat:theme)'
DATASET_THEME = u'Tem\u00E1ticas (dcat:theme)'
DATASET_KEYWORD = u'Etiqueta (dcat:keyword)'
DATASET_KEYWORDS = u'Etiqueta(s) (dcat:keyword)'
DATASET_IDENTIFIER = u'Identificador (dct:identifier)'
DATASET_ISSUED = u'Fecha de creaci\u00F3n (dct:issued)'
DATASET_MODIFIED = u'Fecha de \u00FAltima actualizaci\u00F3n (dct:modified)'
DATASET_ACCRUAL_PERIODICITY = u'Frecuencia de actualizaci\u00F3n (dct:accrualPeriodicity)'
DATASET_LANGUAGE = u'Idioma(s) (dc:language o dct:language)'
DATASET_PUBLISHER = u'Organismo publicador (dct:publisher)'
DATASET_LICENSE = u'Condiciones de uso (dct:license)'
DATASET_SPATIAL = u'Cobertura geogr\u00E1fica (dct:spatial)'
DATASET_TEMPORAL = u'Cobertura temporal (dct:temporal)'
DATASET_VALID = u'Vigencia del recurso (dct:valid)'
DATASET_REFERENCES = u'Recurso(s) relacionado(s) (dct:references)'
DATASET_CONFORMS_TO = u'Normativa (dct:conformsTo)'
DATASET_DISTRIBUTION = u'Distribuci\u00F3n (dcat:distribution)'
DATASET_DISTRIBUTIONS = u'Distribuci\u00F3n(es) (dcat:distribution)'

DISTRIBUTION_IDENTIFIER = u'Identificador de la distribuci\u00F3n (dct:identifier)'
DISTRIBUTION_TITLE = u'Nombre de la distribuci\u00F3n (dct:title)'
DISTRIBUTION_ACCESS_URL = u'URL de acceso de la distribuci\u00F3n (dcat:accessURL)'
DISTRIBUTION_MEDIA_TYPE = u'Formato de la distribuci\u00F3n (dcat:mediaType)'
DISTRIBUTION_BYTE_SIZE = u'Tama\u00F1o de la distribuci\u00F3n (dcat:byteSize)'
DISTRIBUTION_RELATION = u'Informaci\u00F3n adicional de la distribuci\u00F3n (dct:relation)'
DISTRIBUTION_PREFIX_MESSAGE = u'Error en la distribuci\u00F3n: %s'
DISTRIBUTION_NO_IDENTIFIER = u'(Sin identificador)'

# ERROR/WARNING CATALOG MESSAGES
CATALOG_ACCESS_ERROR_URL = u'[Error al acceder al cat\u00E1logo en la URL: %s] %s. El feed no ha sido procesado.'
CATALOG_ACCESS_ERROR = u'[Error al acceder al cat\u00E1logo. %s] El feed no ha sido procesado.'
CATALOG_DOWNLOAD_ERROR_URL = u'[Error al descargar al cat\u00E1logo en la URL: %s] %s. El feed no ha sido procesado.'
CATALOG_DOWNLOAD_ERROR = u'[Error al descargar al cat\u00E1logo] %s. El feed no ha sido procesado.'
CATALOG_PARSER_ERROR_URL = u'[Error al parsear el cat\u00E1logo en la URL: %s] %s. El feed no ha sido procesado.'
CATALOG_PARSER_ERROR = u'[Error al parsear el cat\u00E1logo dcat] %s. El feed no ha sido procesado.'
CATALOG_VALIDATION_ERRORS_URL = u'[Errores al tratar el cat\u00E1logo en la URL: %s] %s. El feed no ha sido procesado.'
CATALOG_VALIDATION_ERROR_URL = u'[Error al tratar el cat\u00E1logo en la URL: %s] %s. El feed no ha sido procesado.'
CATALOG_VALIDATION_ERRORS = u'[Errores al tratar el cat\u00E1logo] %s. El feed no ha sido procesado.'
CATALOG_VALIDATION_ERROR = u'[Error al tratar el cat\u00E1logo. %s] El feed no ha sido procesado.'
CATALOG_VALIDATION_WARNINGS_URL = u'[Warning al tratar el cat\u00E1logo en la URL: %s] %s.'
CATALOG_VALIDATION_WARNING_URL = u'[Warning al tratar el cat\u00E1logo en la URL: %s] %s.'
CATALOG_VALIDATION_WARNINGS = u'[Warnings al tratar el cat\u00E1logo] %s.'
CATALOG_VALIDATION_WARNING = u'[Warning al tratar el cat\u00E1logo] %s.'
CATALOG_WRONG_DEFINITION = u'No se ha encontrado la URI del cat\u00E1logo o la etiqueta del cat\u00E1logo no ha sido declarada (rdf:about)'
CATALOG_LANGUAGE_NOT_FOUND = u'No se ha encontrado el campo: %s del cat\u00E1logo. (Idiomas soportados: %s)'
CATALOG_NO_LANGUAGES = u'No est\u00E1 definido el idioma del cat\u00E1logo'

# ERROR/WARNING DATASET MESSAGES
DATASET_IMPORT_ERROR = u'[Error al importar el dataset en base de datos] %s.'
DATASET_VALIDATION_ERROR = u'[Error al tratar el dataset] %s.'
DATASET_VALIDATION_WARNING = u'[Warning al tratar el dataset] %s.'
DATASET_VALIDATION_ERROR_IDENTIFIER = u'[Error al tratar el dataset] %s.'
DATASET_VALIDATION_WARNING_IDENTIFIER = u'[Warning al tratar el dataset] %s.'
DATASET_WRONG_DEFINITION = u'No se ha encontrado la URI del dataset o la etiqueta del dataset no ha sido declarada (rdf:about)'
DATASET_SAME_ABOUT_DISTRIBUTION = u'Existe al menos una distribuci\u00F3n con la misma URI (rdf:about) que el dataset: %s'
DATASET_SAME_ABOUT_DATASET = u'Existen al menos dos datasets con la misma URI (rdf:about): %s'
DISTRIBUTION_SAME_ABOUT_DISTRIBUTION = u'Existen al menos dos distribuciones con la misma URI (rdf:about): %s'
CATALOG_SAME_ABOUT_DATASET = u'Existe al menos un dataset con la misma URI (rdf:about) que el cat\u00E1logo: %s'
CATALOG_SAME_ABOUT_DISTRIBUTION = u'Existe al menos una distribuci\u00F3n con la misma URI (rdf:about) que el cat\u00E1logo: %s'
DATASET_INTEGRITY_ERROR = u'Es posible que exista otro dataset en el cat\u00E1logo cuyo t\u00EDtulo en es coincida con el de otro dataset en los primeros 300 caracteres'

DISTRIBUTION_VALIDATION_ERROR = u'[Error al tratar el dataset][Error al tratar la distribución]'
DISTRIBUTION_VALIDATION_ERROR_ID = u'[Error al tratar el dataset][Error al tratar la distribución:%s]'

# ERROR/WARNING COMMON MESSAGES
UNEXPECTED_LANGUAGES = u'%s mal definido o no soportado por el portal: %s. (Idiomas soportados: %s)'
DEFAULT_LANGUAGE_NOT_FOUND = u'No se ha encontrado el %s obligatorio %s'
NO_LANGUAGES = u'No se define ning\u00FAn %s. (Idiomas soportados: %s)'
EXPECTED_IN_ALL_CATALOG_LANGUAGE = u'El campo %s no est\u00E1 en todos los idiomas del cat\u00E1logo'
EXPECTED_IN_DEFAULT_CATALOG_LANGUAGE = u'El campo %s no est\u00E1 en al menos el idioma requerido del cat\u00E1logo (%s)'
UNEXPECTED_MULTIPLES_VALUES_SAME_LANGUAGE = u'El campo %s aparece varias veces definido con el idioma %s'
UNEXPECTED_MULTIPLES_VALUES_WITHOUT_LANGUAGE = u'El campo %s aparece varias veces definido sin idioma'
VALUE_IN_UNEXPECTED_LANGUAGE = u'El campo %s est\u00E1 en los idiomas (%s) que no son idiomas del cat\u00E1logo'
VALUE_IN_UNEXPECTED_PORTAL_LANGUAGE = u'El campo %s est\u00E1 en los idiomas (%s) que no son idiomas soportados por el portal'
EMPTY_VALUE_IN_LANGUAGE = u'El campo %s no tiene valor en los idiomas (%s)'
EMPTY_VALUE_NO_LANGUAGE = u'El campo %s sin idioma definido no tiene valor'
VALUE_NOT_FOUND_IN_EXPECTED_LANGUAGE = u'El campo %s no est\u00E1 en los idiomas del cat\u00E1logo: %s'
UNEXPECTED_EMPTY_VALUE = u'El campo %s aparece sin valor'
OPTIONAL_EMPTY_VALUE = u'El campo no obligatorio %s se ignora porque tiene un valor vac\u00EDo'
UNEXPECTED_VALUE = u'El campo %s no tiene un valor v\u00E1lido (%s)'
REQUIRED_FIELD_NOT_FOUND = u'No se ha encontrado el campo %s'
REQUIRED_MULTIPLE_FIELD_NOT_FOUND = u'No se ha encontrado ning\u00FAn campo %s'
WRONG_URI = u'El campo %s no contiene una URI v\u00E1lida (%s)'
WRONG_URL = u'El campo %s no contiene una URL v\u00E1lida (%s)'
UNEXPECTED_SPATIAL_COVERAGE_VALUES = u'El campo %s no contiene ninguna Autonom\u00EDa ni Provincia v\u00E1lida'
REQUIRED_VALUE_NOT_FOUND = u'El campo %s no contiene el valor esperado (%s)'
REQUIRED_VALUE_NOT_FOUND_CASE_SENSITIVE = u'El campo %s tienen un valor (%s) que no contiene exactamente el valor esperado (%s)'
UNEXPECTED_THEME_TAXONOMY_NOT_IN_CALOG = u'El campo %s tiene un valor %s que no se corresponde a ninguna tem\u00E1tica del cat\u00E1logo'
UNEXPECTED_THEME_VALUE = u'El campo %s no tiene ning\u00FAn valor que corresponda a la tem\u00E1tica obligatoria del cat\u00E1logo (%s)'
VALUE_NO_CASE_SENSITIVE = u'El campo %s tiene valores que no coinciden exactamente con las uris especificadas en la norma: (%s)'
FORMAT_NO_CASE_SENSITIVE = u'El campo %s tiene un valor que no coincide exactamente con los aceptados: (%s)'
REQUIRED_LITERAL_OBJECTS = u'El campo %s no es un literal. El posible que el campo no tenga valor o tenga un atributo lang incorrecto'
#UNEXPECTED_KEYWORD_FORMAT = u'El campo %s tiene un valor %s que no est\u00E1 compuesto por caracters alfanum\u00E9ricos o s\u00EDmbolos: -_.'
UNEXPECTED_KEYWORD_FORMAT = u'El campo %s tiene un valor %s. Debe estar compuesto por caracteres alfanuméricos o alguno de los símbolos siguientes para ser válido: - _ Ç ç L·L l·l '' & .'
RECEIVED_VALUE = u'El campo %s tiene valor no esperado: %s'
UNEXPECTED_VALUE = u'El campo %s tiene un valor no v\u00E1lido (%s)'
UNEXPECTED_ERROR = u'%s: %s'
UNEXPECTED_FIELD_ERROR = u'El campo %s tiene un error %s: %s'
UNEXPECTED_PUBLISHER = u'El campo %s tiene un valor %s que no corresponde a ninguna organizaci\u00F3n del sistema'
UNEXPECTED_PUBLISHER_CATALOG_OWNER_SOURCE = u'La organizaci\u00F3n publicadora del cat\u00E1logo no se corresponde con la organizaci\u00F3n asociada al harvest source'

# ERROR MESSAGE THAT NO CONTAIN FIELD_NAME
FIELD_PLUS_MESSAGE = u'El campo %s %s'
UNEXPECTED_COMPLETE_DEFINITION = u'no est\u00E1 bien definido. %s: %s'
UNEXPECTED_DEFINITION = u'no est\u00E1 bien definido'
UNEXPECTED_MULTIPLE_OBJECTS = u'aparece definido varias veces'
UNEXPECTED_MULTIPLE_SUBOBJECTS = u'tiene varios nodos %s'
UNEXPECTED_MULTIPLE_SUB_SUBOBJECTS = u'tiene varios subnodos %s bajo el nodo %s'
UNEXPECTED_DATE_DATATYPE = u'tiene un tipo de dato incorrecto %s para la fecha %s. Los tipos permitidos son: %s '
UNEXPECTED_DATE_FORMAT = u'no tiene formato ISO-8601 %s'
UNEXPECTED_DATE_VALUE = u'no tiene un valor v\u00E1lido %s. %s'
UNEXPECTED_INTEGER_VALUE = u'no contiene un valor convertible a n\u00FAmero entero (%s)'
UNEXPECTED_INCOMPLETE_VALUE = u'aparece sin valor'


CATALOG_ERROR_SUMMARY = u'Resumen: %s warning(s) y %s error(es) se ha(n) generado en la validaci\u00F3n del cat\u00E1logo. Ning\u00FAn dataset ha sido procesado'
SUMMARY = u'''Resumen: CAT\u00C1LOGO: %s warning(s) se ha(n) generado en la validaci\u00F3n del cat\u00E1logo.
                       DATASETS: Se han proceso %s datasets, de los cuales %s han producido error y no se han podido federar.
                       Se han generado %s error(es) y %s warning(s) diferentes en la validación de todos los datasets procesados.'''
LOG_CATALOG_ERROR_SUMMARY = u'''ERROR/WARNING SUMMARY IN GATHER STAGE:
                    \n\tcatalog warnings=%s,
                    \n\tcatalog errors=%s'''
LOG_SUMMARY = u'''ERROR/WARNING SUMMARY IN GATHER STAGE:
                    \n\tcatalog warnings=%s,
                    \n\ttotal dataset=%s,
                    \n\tdataset with errors=%s,
                    \n\ttotal dataset errors=%s,
                    \n\ttotal dataset warnings=%s'''


THEME_PREFIX = u'http://datos.gob.es/kos/sector-publico/sector'
THEME_PREFIX_SLASH = u'http://datos.gob.es/kos/sector-publico/sector/'
SPATIAL_PREFIX = u'http://datos.gob.es/recurso/sector-publico/territorio/'
SPATIAL_PROVINCE_PREFIX = u'http://datos.gob.es/recurso/sector-publico/territorio/Provincia/'
SPATIAL_CCAA_PREFIX = u'http://datos.gob.es/recurso/sector-publico/territorio/Autonomia/'
PUBLISHER_PREFIX = u'http://datos.gob.es/recurso/sector-publico/org/Organismo/'
DEFAULT_TIMEZONE = 'Europe/Madrid'
LANGUAGE_PREFIX_EDP = u'http://publications.europa.eu/resource/authority/language/'
FORMAT_PREFIX_EDP = u'http://publications.europa.eu/resource/authority/file-type/'
FORMAT_PREFIX_EDP_IANA = u'https://www.iana.org/assignments/media-types/'

# Keys of catalog dictionary
CAT_ERRORS = u'cat_errors'
CAT_WARNINGS = u'cat_warnings'
CAT_LANGUAGE = u'cat_language'
CAT_TITLE_TRANSLATE = u'cat_title_translated'
CAT_DESCRIPTION = u'cat_description'
CAT_PUBLISHER = u'cat_publisher'
CAT_PUBLISHER_NAME = u'cat_publisher_display_name'
CAT_PUBLISHER_ID_MINHAP = u'cat_publisher_id_minhap'
CAT_SIZE = u'cat_size'
CAT_IDENTIFIER = u'cat_identifier'
CAT_ISSUED_DATE = u'cat_issued_date'
CAT_MODIFIED_DATE = u'cat_modified_date'
CAT_SPATIAL = u'cat_spatial'
CAT_THEME_TAXONOMY = u'cat_theme_taxonomy'
CAT_HOMEPAGE = u'cat_homepage'
CAT_LICENSE = u'cat_license_id'
CAT_URI = u'cat_uri'

# Keys of catalog and dataset dictionary
DS_ERRORS = u'errors'
DS_WARNINGS = u'warnings'
DS_EXTRAS = u'extras'
DS_TAGS = u'tags'
DS_MULTILINGUAL_TAGS = u'multilingual_tags'
DS_RESOURCES = u'resources'
DS_TYPE = u'type'
DS_ID = u'id'
DS_DEFAULT_CATALOG_LANGUAGE = u'default_catalog_language'
DS_URI = u'uri'
DS_NAME = u'name'
DS_TITLE = u'title'
DS_OWNER_ORG = u'owner_org'
DS_LANGUAGE = u'language'
DS_TITLE_TRANSLATED = u'title_translated'
DS_DESCRIPTION = u'description'
DS_THEME = u'theme'
DS_IDENTIFIER = u'identifier'
DS_ISSUED_DATE = u'issued_date'
DS_MODIFIED_DATE = u'modified_date'
DS_FREQUENCY = u'frequency'
DS_PUBLISHER = u'publisher'
DS_PUBLISHER_NAME = u'publisher_display_name'
DS_PUBLISHER_ID_MINHAP = u'publisher_id_minhap'
DS_LICENSE = u'license_id'
DS_SPATIAL = u'spatial'
DS_TEMPORAL_COVERAGE = u'coverage_new'
DS_VALID = u'valid'
DS_REFERENCE = u'reference'
DS_NORMATIVE = u'conforms_to'
DS_RESOURCE_IDENTIFIER = u'resource_identifier'
DS_RESOURCE_NAME_TRANSLATED = u'name_translated'
DS_RESOURCE_ACCESS_URL = u'url'
DS_RESOURCE_MIMETYPE = u'mimetype'
DS_RESOURCE_FORMAT = u'format'
DS_RESOURCE_BYTE_SIZE = u'byte_size'
DS_RESOURCE_RELATION = u'resource_relation'
DS_HASH = u'hash'
DS_GUID = u'guid'

# Keys of harvest source config properties
HS_PROP_USER = u'user'
HS_PROP_READ_ONLY = u'read_only'
HS_PROP_DEFULT_CATALOG_LANGUAGE = u'default_catalog_language'
HS_PROP_RDF_FORMAT = u'rdf_format'
# Keys of ckan config properties
CKAN_PROP_LOCALES_OFFERED = u'ckan.locales_offered'
CKAN_PROP_LOCALE_DEFAULT = u'ckan.locale_default'
CKAN_PROP_LOCALE_ORDER = u'ckan.locale_order'
CKAN_PROP_HTTP_PROXY = u'ckanext.dge_harvest.http_proxy'
CKAN_PROP_HTTPS_PROXY = u'ckanext.dge_harvest.https_proxy'

ORG_PROP_ID_UD_ORGANICA = 'C_ID_UD_ORGANICA'
ORG_PROP_ID_UD_PRINCIPAL = 'C_ID_DEP_UD_PRINCIPAL'
ORG_PROP_NOMBRE_UD_RAIZ = 'C_DNM_DEP_UD_PRINCIPAL'

CAT_AVAILABLE_DATA = u'available_data'
CAT_AVAILABLE_THEMES = u'available_themes'
CAT_AVAILABLE_SPATIAL_COVERAGES = u'available_spatial_coverages'
CAT_AVAILABLE_RESOURCE_FORMATS = u'available_resource_formats'
CAT_AVAILABLE_PUBLISHERS = u'available_publishers'

EXPORT_AVAILABLE_RESOURCE_FORMATS = u'export_available_resource_formats'
EXPORT_AVAILABLE_PUBLISHERS = u'export_available_publishers'
EXPORT_AVAILABLE_THEMES = u'export_available_themes'
