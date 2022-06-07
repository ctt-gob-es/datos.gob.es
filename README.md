# [datos.gob.es](https://datos.gob.es/)

Este repositorio contiene el código fuente del proyecto datos.gob.es. Se proporcionan los componentes desarrollados para Drupal y para CKAN. Se puede consultar la arquitectura de alto nivel del proyecto [aquí](https://datos.gob.es/es/tecnologia).

## CKAN

Se han desarrollado las siguientes extensiones de CKAN:

* ckanext-dge: contiene las adaptaciones específicas, tanto funcionales como de estilos.
* ckanext-dge-drupal-users: permite delegar la autenticación de CKAN en Drupal.
* ckanext-dge-scheming: amplía el esquema de metadatos de CKAN a los requisitos de la [Norma Técnica de Interoperabilidad de Reutilización de recursos de la información (NTI-RISP)](https://www.boe.es/diario_boe/txt.php?id=BOE-A-2013-2380).
* ckanext-dge-harvest: implementa el proceso de federación de los catálogos de datos de los organismos publicadores integrados en el sistema.
* ckanext-dge-ga: integración con Google Analytics.
* ckanext-dge-ga-report: generación de información de reportes de Google Analytics.
* ckanext-dge-dashboard: implementa el cuadro de mando del portal.
* ckanext-dge-archiver: personaliza la comprobación de enlaces rotos y permite la selección de las organizaciones.

### Dependencias

Requiere CKAN versión 2.5.2 o superior y las siguientes extensiones:

* [ckanext-dcat](https://github.com/ckan/ckanext-dcat)
* [ckanext-harvest](https://github.com/ckan/ckanext-harvest)
* [ckanext-scheming](https://github.com/ckan/ckanext-scheming)
* [ckanext-fluent](https://github.com/ckan/ckanext-fluent)
* [ckanext-archiver](https://github.com/ckan/ckanext-archiver)
* [ckanext-googleanalytics](https://github.com/ckan/ckanext-googleanalytics)
* [ckanext-report](https://github.com/ckan/ckanext-report)

###  Instalación

El proceso de instalación de las extensiones sigue el mecanismo estándar de CKAN descrito en su [documentación oficial](http://docs.ckan.org/). Para cualquier consulta, puede utilizar el [punto de contacto](https://datos.gob.es/es/contacto) de datos.gob.es.

### Licencia

El código fuente es propiedad de Entidad Pública Empresarial Red.es y está licenciado bajo [GNU Affero General Public License, versión 3 o posterior](http://www.gnu.org/licenses/).

## Drupal

Se incluyen en esta sección los módulos contrib desarrollados para el proyecto, las features que deben ser activadas y el theme a integrar. A destacar el módulo dge_i18n que provee la funcionalidad de multiidioma al portal, permitiendo una navegación simétrica en cada idioma.

### Dependencias

Requiere Drupal versión 7.x.

### Instalación

El proceso de instalación debe seguir el modelo de despliegue de Drupal para modules contrib, activación de features e integración de themes, aplicando las recomendaciones de su [documentación oficial](https://www.drupal.org/docs/7). Para cualquier consulta, puede utilizar el [punto de contacto](https://datos.gob.es/es/contacto) de datos.gob.es.

### Licencia

El código fuente es propiedad de Entidad Pública Empresarial Red.es y está licenciado bajo [GNU General Public License, versión 2 o posterior](http://www.gnu.org/licenses/).
