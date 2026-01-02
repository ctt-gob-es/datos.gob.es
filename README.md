<p align="center">
  <a href="https://digital.gob.es/ministerio/organigrama_organos/SEDIA.html" target="_blank" rel="noreferrer noopener"><img alt="Secretaría de Estado de Digitalización e Inteligencia Artificial" src="https://raw.githubusercontent.com/datosgobes/DCAT-AP-ES/a3830db83a1ed5de0b347eeaf9d05eede75f620f/docs/img/sedia-red-es.jpg" height="44" /></a>
  &nbsp;&nbsp;&nbsp;
  <a href="https://datos.gob.es/" target="_blank" rel="noreferrer noopener"><img alt="datos.gob.es" src="https://raw.githubusercontent.com/datosgobes/DCAT-AP-ES/a3830db83a1ed5de0b347eeaf9d05eede75f620f/docs/img/dge_logo_2025.svg" height="44" /></a>
  &nbsp;&nbsp;&nbsp;
  <a href="https://datos.gob.es/acerca-de-la-iniciativa-aporta" target="_blank" rel="noreferrer noopener"><img alt="Iniciativa Aporta" src="https://raw.githubusercontent.com/datosgobes/DCAT-AP-ES/a3830db83a1ed5de0b347eeaf9d05eede75f620f/docs/img/iniciativa_aporta.svg" height="44" /></a>
</p>

# Catálogo Nacional - [datos.gob.es](https://datos.gob.es/)

Este repositorio es el **punto de entrada al código fuente personalizado de la nueva versión de la plataforma [datos.gob.es](https://datos.gob.es/)** en un modelo descentralizado: aquí se mantiene la documentación, la gobernanza y los enlaces a los repositorios donde vive el código ([extensiones CKAN](https://docs.ckan.org/en/latest/extensions/) y [módulos/temas Drupal](https://www.drupal.org/docs/extending-drupal)).

## Objetivo del repositorio

- Facilitar una **gobernanza clara** y un modelo de contribución abierto.
- Separar el código por componentes (extensiones CKAN / módulos y temas Drupal), con su propio ciclo de vida.

## Repositorios

Este repositorio **no contiene el código fuente operativo de [CKAN](https://github.com/ckan/ckan)/[Drupal](https://github.com/drupal/drupal)**. El código se publica y evoluciona en los repositorios de extensiones/módulos/temas enlazados desde aquí.

### Extensiones CKAN

> [!TIP]
> Documentación extensiones CKAN: [**Descargar PDF**](docs/202512_datosgobes-ckan-doc_es.pdf)

Cada extensión CKAN se mantiene en un repositorio independiente.

| Extensión | Descripción | Tipo | Distribución | Actualizado |
|---|---|---|---|---|
| [`ckanext-comments`](https://github.com/datosgobes/ckanext-comments) | Hilos de comentarios en entidades CKAN | `comentarios` `ui` | [![Release](https://img.shields.io/github/v/release/datosgobes/ckanext-comments?label=)](https://github.com/datosgobes/ckanext-comments/releases) | [![Last commit](https://img.shields.io/github/last-commit/datosgobes/ckanext-comments?label=)](https://github.com/datosgobes/ckanext-comments) |
| [`ckanext-dge`](https://github.com/datosgobes/ckanext-dge) | Tema/plantillas y utilidades específicas | `tema` `ui` | [![Release](https://img.shields.io/github/v/release/datosgobes/ckanext-dge?label=)](https://github.com/datosgobes/ckanext-dge/releases) | [![Last commit](https://img.shields.io/github/last-commit/datosgobes/ckanext-dge?label=)](https://github.com/datosgobes/ckanext-dge) |
| [`ckanext-dge-brokenlinks`](https://github.com/datosgobes/ckanext-dge-brokenlinks) | Auditoría/gestión de enlaces rotos | `auditoría` | [![Release](https://img.shields.io/github/v/release/datosgobes/ckanext-dge-brokenlinks?label=)](https://github.com/datosgobes/ckanext-dge-brokenlinks/releases) | [![Last commit](https://img.shields.io/github/last-commit/datosgobes/ckanext-dge-brokenlinks?label=)](https://github.com/datosgobes/ckanext-dge-brokenlinks) |
| [`ckanext-dge-dashboard`](https://github.com/datosgobes/ckanext-dge-dashboard) | Dashboard/estadísticas | `drupal` `analytics` | [![Release](https://img.shields.io/github/v/release/datosgobes/ckanext-dge-dashboard?label=)](https://github.com/datosgobes/ckanext-dge-dashboard/releases) | [![Last commit](https://img.shields.io/github/last-commit/datosgobes/ckanext-dge-dashboard?label=)](https://github.com/datosgobes/ckanext-dge-dashboard) |
| [`ckanext-dge-dataservice`](https://github.com/datosgobes/ckanext-dge-dataservice) | Data services | `metadatos` `api` | [![Release](https://img.shields.io/github/v/release/datosgobes/ckanext-dge-dataservice?label=)](https://github.com/datosgobes/ckanext-dge-dataservice/releases) | [![Last commit](https://img.shields.io/github/last-commit/datosgobes/ckanext-dge-dataservice?label=)](https://github.com/datosgobes/ckanext-dge-dataservice) |
| [`ckanext-dge-drupal-users`](https://github.com/datosgobes/ckanext-dge-drupal-users) | Integración usuarios Drupal ↔ CKAN | `drupal` `integración` `usuarios` | [![Release](https://img.shields.io/github/v/release/datosgobes/ckanext-dge-drupal-users?label=)](https://github.com/datosgobes/ckanext-dge-drupal-users/releases) | [![Last commit](https://img.shields.io/github/last-commit/datosgobes/ckanext-dge-drupal-users?label=)](https://github.com/datosgobes/ckanext-dge-drupal-users) |
| [`ckanext-dge-ga`](https://github.com/datosgobes/ckanext-dge-ga) | Integración Google Analytics | `analytics` `integración` | [![Release](https://img.shields.io/github/v/release/datosgobes/ckanext-dge-ga?label=)](https://github.com/datosgobes/ckanext-dge-ga/releases) | [![Last commit](https://img.shields.io/github/last-commit/datosgobes/ckanext-dge-ga?label=)](https://github.com/datosgobes/ckanext-dge-ga) |
| [`ckanext-dge-ga-report`](https://github.com/datosgobes/ckanext-dge-ga-report) | Extracción/reporting GA | `analytics` `dashboard` | [![Release](https://img.shields.io/github/v/release/datosgobes/ckanext-dge-ga-report?label=)](https://github.com/datosgobes/ckanext-dge-ga-report/releases) | [![Last commit](https://img.shields.io/github/last-commit/datosgobes/ckanext-dge-ga-report?label=)](https://github.com/datosgobes/ckanext-dge-ga-report) |
| [`ckanext-dge-harvest`](https://github.com/datosgobes/ckanext-dge-harvest) | Cosechado/validación DCAT-AP-ES | `cosechador` `federador` | [![Release](https://img.shields.io/github/v/release/datosgobes/ckanext-dge-harvest?label=)](https://github.com/datosgobes/ckanext-dge-harvest/releases) | [![Last commit](https://img.shields.io/github/last-commit/datosgobes/ckanext-dge-harvest?label=)](https://github.com/datosgobes/ckanext-dge-harvest) |
| [`ckanext-dge-scheming`](https://github.com/datosgobes/ckanext-dge-scheming) | Scheming (datasets/dataservices) | `esquema` `metadatos` `dcat-ap-es` `nti-risp` | [![Release](https://img.shields.io/github/v/release/datosgobes/ckanext-dge-scheming?label=)](https://github.com/datosgobes/ckanext-dge-scheming/releases) | [![Last commit](https://img.shields.io/github/last-commit/datosgobes/ckanext-dge-scheming?label=)](https://github.com/datosgobes/ckanext-dge-scheming) |

### Módulos y temas de Drupal

Para simplificar el mantenimiento, los desarrollos Drupal se agrupan en dos repositorios, cada uno con su ciclo de vida, releases e issues.

| Extensión | Descripción | Tipo | Distribución | Actualizado |
|---|---|---|---|---|
| [`drupal-modules-datosgob`](https://github.com/datosgobes/drupal-modules-datosgob) | Módulos Drupal: `dge_ckan`, `dge_blocks`, `dge_comments`, ... | `drupal` `modules` `datos.gob.es` | [![Release](https://img.shields.io/github/v/release/datosgobes/drupal-modules-datosgob?label=)](https://github.com/datosgobes/drupal-modules-datosgob/releases) | [![Last commit](https://img.shields.io/github/last-commit/datosgobes/drupal-modules-datosgob?label=)](https://github.com/datosgobes/drupal-modules-datosgob) |
| [`drupal-themes-datosgob`](https://github.com/datosgobes/drupal-themes-datosgob) | Temas Drupal: `dge_admin_theme`, `dge_theme`, ... | `drupal` `themes` `datos.gob.es`  | [![Release](https://img.shields.io/github/v/release/datosgobes/drupal-themes-datosgob?label=)](https://github.com/datosgobes/drupal-themes-datosgob/releases) | [![Last commit](https://img.shields.io/github/last-commit/datosgobes/drupal-themes-datosgob?label=)](https://github.com/datosgobes/drupal-themes-datosgob) 

## Historial de cambios

Para ver el histórico de cambios y versiones de este repositorio, consulta el [CHANGELOG](CHANGELOG).

## Contribución

¡Las contribuciones son bienvenidas! Por favor, consulta nuestra [Guía de Contribución](CONTRIBUTING.md) para obtener detalles sobre cómo reportar bugs, sugerir mejoras y enviar pull requests.

### Reportar vulnerabilidades de seguridad

Si descubres una vulnerabilidad de seguridad, **no** la reportes públicamente a través de issues. En su lugar, consulta nuestra [Política de Seguridad](SECURITY.md) para obtener instrucciones sobre cómo reportarla de forma responsable.
