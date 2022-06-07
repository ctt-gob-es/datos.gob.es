# [datos.gob.es](https://datos.gob.es/)

Este repositorio contiene el c�digo fuente del proyecto datos.gob.es. Se proporcionan los componentes desarrollados para Drupal y para CKAN. Se puede consultar la arquitectura de alto nivel del proyecto [aqu�](https://datos.gob.es/es/tecnologia).

## CKAN

Se han desarrollado las siguientes extensiones de CKAN:

* ckanext-dge: contiene las adaptaciones espec�ficas, tanto funcionales como de estilos.
* ckanext-dge-drupal-users: permite delegar la autenticaci�n de CKAN en Drupal.
* ckanext-dge-scheming: ampl�a el esquema de metadatos de CKAN a los requisitos de la [Norma T�cnica de Interoperabilidad de Reutilizaci�n de recursos de la informaci�n (NTI-RISP)](https://www.boe.es/diario_boe/txt.php?id=BOE-A-2013-2380).
* ckanext-dge-harvest: implementa el proceso de federaci�n de los cat�logos de datos de los organismos publicadores integrados en el sistema.
* ckanext-dge-ga: integraci�n con Google Analytics.
* ckanext-dge-ga-report: generaci�n de informaci�n de reportes de Google Analytics.
* ckanext-dge-dashboard: implementa el cuadro de mando del portal.
* ckanext-dge-archiver: personaliza la comprobaci�n de enlaces rotos y permite la selecci�n de las organizaciones.

### Dependencias

Requiere CKAN versi�n 2.5.2 o superior y las siguientes extensiones:

* [ckanext-dcat](https://github.com/ckan/ckanext-dcat)
* [ckanext-harvest](https://github.com/ckan/ckanext-harvest)
* [ckanext-scheming](https://github.com/ckan/ckanext-scheming)
* [ckanext-fluent](https://github.com/ckan/ckanext-fluent)
* [ckanext-archiver](https://github.com/ckan/ckanext-archiver)
* [ckanext-googleanalytics](https://github.com/ckan/ckanext-googleanalytics)
* [ckanext-report](https://github.com/ckan/ckanext-report)

###  Instalaci�n

El proceso de instalaci�n de las extensiones sigue el mecanismo est�ndar de CKAN descrito en su [documentaci�n oficial](http://docs.ckan.org/). Para cualquier consulta, puede utilizar el [punto de contacto](https://datos.gob.es/es/contacto) de datos.gob.es.

### Licencia

El c�digo fuente es propiedad de Entidad P�blica Empresarial Red.es y est� licenciado bajo [GNU Affero General Public License, versi�n 3 o posterior](http://www.gnu.org/licenses/).

## Drupal

Se incluyen en esta secci�n los m�dulos contrib desarrollados para el proyecto, las features que deben ser activadas y el theme a integrar. A destacar el m�dulo dge_i18n que provee la funcionalidad de multiidioma al portal, permitiendo una navegaci�n sim�trica en cada idioma.

### Dependencias

Requiere Drupal versi�n 7.x.

### Instalaci�n

El proceso de instalaci�n debe seguir el modelo de despliegue de Drupal para modules contrib, activaci�n de features e integraci�n de themes, aplicando las recomendaciones de su [documentaci�n oficial](https://www.drupal.org/docs/7). Para cualquier consulta, puede utilizar el [punto de contacto](https://datos.gob.es/es/contacto) de datos.gob.es.

### Licencia

El c�digo fuente es propiedad de Entidad P�blica Empresarial Red.es y est� licenciado bajo [GNU General Public License, versi�n 2 o posterior](http://www.gnu.org/licenses/).
