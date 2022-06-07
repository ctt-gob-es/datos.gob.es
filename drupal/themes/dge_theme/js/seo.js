/**
 	* Copyright (C) 2022 Entidad Pública Empresarial Red.es
 	*
 	* This file is part of "dge_theme (datos.gob.es)".
 	*
 	* This program is free software: you can redistribute it and/or modify
 	* it under the terms of the GNU General Public License as published by
 	* the Free Software Foundation, either version 2 of the License, or
 	* (at your option) any later version.
 	*
 	* This program is distributed in the hope that it will be useful,
 	* but WITHOUT ANY WARRANTY; without even the implied warranty of
 	* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 	* GNU General Public License for more details.
 	*
 	* You should have received a copy of the GNU General Public License
 	* along with this program. If not, see <http://www.gnu.org/licenses/>.
 	*/

(function ($) {
  Drupal.behaviors.schemaWebPage= {
    attach: function (context, settings) {
      var script = document.createElement("script");
      script.type = "application/ld+json";

      // Add script content
      var json =
        {
          "@context": "https://schema.org",
          "@type": "WebPage",
          "url": window.location.href,
          "name": $(document).attr('title'),
          "speakable":
            {
              "@type": "SpeakableSpecification",
              "xpath": [
                "/html/head/title",
                "/html/head/meta[@name='description']/@content"
              ]
            }
        };
      var jsonCode = JSON.stringify(json);
      script.innerText = jsonCode;
      document.head.appendChild(script);
    }
  };

  Drupal.behaviors.schemaGovernmentService= {
    attach: function (context, settings) {
      var lang = document.getElementsByTagName('html')[0].getAttribute('lang');
      if(lang == 'es') {
        var script = document.createElement("script");
        script.type = "application/ld+json";
        // Add script content
        var json =
          {
            "@context": "http://schema.org",
            "@type": "GovernmentService",
            "name": "Iniciativa Aporta",
            "description": "Plataforma de datos abiertos u open data en España para la reutilización de la información pública",
            "serviceOperator": {
              "@type": "GovernmentOrganization",
              "name": "La Secretaría de Estado de Función Pública del Ministerio de Política Territorial y Función Pública, la Secretaría de Estado para el Avance Digital del Ministerio de Economía y Empresa, y Red.es."
            },
            "areaServed": {
              "@type": "AdministrativeArea",
              "name": "Spain"
            },
            "audience": {
              "@type": "Audience",
              "name": "Persona física o jurídica"
            },
            "availableChannel": {
              "@type": "ServiceChannel",
              "name": "Datos.gob.es",
              "image": "https://datos.gob.es/sites/default/files/logo_0.png",
              "ServiceUrl": "https://datos.gob.es/",
              "sameAs": ["https://twitter.com/datosgob",
                "https://www.linkedin.com/company/datos-gob-es", "https://www.youtube.com/user/datosgob", "https://es.slideshare.net/datosgob", "https://www.flickr.com/photos/datosgob/"
              ],
              "availableLanguage": {
                "@type": "Language",
                "name": "Spanish",
                "alternateName": "es"
              }
            }
          };
        var jsonCode = JSON.stringify(json);
        script.innerText = jsonCode;
        document.head.appendChild(script);
      }
    }
  };
  Drupal.behaviors.schemaFaqPage= {
    attach: function (context, settings) {
      var pathname = window.location.pathname; //Your page path
      var page = pathname.slice(4);
      console.lo
      if (page == 'faq-page') {
        var script = document.createElement("script");
        script.type = "application/ld+json";
        // Add script content
        var json =
          {
            "@context": "https://schema.org",
            "@type": "FAQPage",
            "mainEntity": [{
              "@type": "Question",
              "name": "¿Qué es la reutilización de la información del sector público?",
              "acceptedAnswer": {
                "@type": "Answer",
                "text": "Son aquellos datos que cualquiera es libre de utilizar, reutilizar y redistribuir, con el único límite, en su caso, del requisito de atribución de su fuente o reconocimiento de su autoría."
              }
            }, {
              "@type": "Question",
              "name": "¿Para qué reutilizar los datos públicos?",
              "acceptedAnswer": {
                "@type": "Answer",
                "text": "La reutilización de la información del sector público facilita el desarrollo de nuevos productos, servicios y soluciones de alto valor socioeconómico. Igualmente, permite revertir en la sociedad el conocimiento y los beneficios directos derivados de la actividad de las administraciones públicas en condiciones de transparencia. La reutilización ayuda, así, a mejorar la fiabilidad y seguridad de los datos que aquéllas gestionan y contribuye, además, a un diseño más cercano y eficiente de los servicios públicos."
              }
            },
              {
                "@type": "Question",
                "name": "¿Qué es la Iniciativa Aporta?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "La Iniciativa Aporta se presenta como estrategia de datos abiertos en España. Las directrices que rigen las actuaciones a desarrollar se fijan en los siguientes documentos:"
                }
              }, {
                "@type": "Question",
                "name": "¿Por qué un datos.gob.es?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "La plataforma datos.gob.es se constituye como el punto de encuentro entre las administraciones, las empresas y los ciudadanos interesados en la apertura de la información pública y en el desarrollo de servicios avanzados basados en datos. Datos.gob.es permite la interacción del visitante y ofrece visibilidad a las actuaciones que se realizan en el marco de la Iniciativa Aporta, la estrategia de datos abiertos de España. Datos.gob.es que organiza y gestiona el Catálogo de Información Pública del sector público. Asimismo, desde la plataforma proporciona información general, materiales formativos y noticias de actualidad sobre la reutilización de la información del sector público. En línea con los objetivos de la Iniciativa Aporta, este servicio pretende estimular la apertura y reutilización de la información del sector público y hacerlo, además, con la participación creativa de sus usuarios."
                }
              },
              {
                "@type": "Question",
                "name": "¿Qué secciones ofrece datos.gob.es?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "El portal datos.gob.es está diseñado como punto de encuentro entre los diferentes actores –usuarios, infomediarios y organismos públicos- involucrados en la cultura de datos abiertos. Punto de acceso único a los conjuntos de datos de las Administraciones Públicas, el canal también es un catalizador de iniciativas de reutilización de la información o casos de éxito a través de la sección Impacto. Noticias, entrevistas o eventos nacionales e internacionales tienen cabida en la sección Actualidad, concebida para acercar a todos los públicos las últimas noticias en materia de apertura y reutilización de la información pública. Además, desde el apartado Documentación de la sección Interactúa, se puede acceder a materiales formativos, estrategias RISP nacionales, guías y normativas."
                }
              },
              {
                "@type": "Question",
                "name": "¿Cómo suscribirse a los contenidos?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "Cualquier usuario puede suscribirse a las novedades de datos.gob.es a través de los indicadores RSS disponibles en las páginas dinámicas del portal. De esta forma, se facilita de forma automática toda la información relacionada con las últimas actualizaciones del sitio web."
                }
              },
              {
                "@type": "Question",
                "name": "¿Cómo encontrar una información?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "Datos.gob.es permite encontrar la información deseada a través de múltiples vías. Cada una de las secciones del portal incorpora su propio buscador por texto libre, filtros y opciones para ordenar los resultados obtenidos por fecha o título. En todo caso, siempre está disponible en el menú principal una opción para búscar (icono de lupa), esta búsqueda puede realizarla sobre el catálogo de datos o bien, sobre el resto de recursos disponible en el portal."
                }
              },
              {
                "@type": "Question",
                "name": "En el buscador que hay en el menú de la página, ¿cuál es la diferencia entre buscar en Catálogo de datos y Contenido del portal?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "En el menú de la página, el enlace buscar , si selecciona la opción Catálogo de datos le proporciona resultados sobre los conjuntos de datos presentes en el Catálogo de datos. Si por el contrario, selecciona la opción Contenido del portal la búsqueda le ofrecerá resultados sólo sobre el contenido editorial (noticas, eventos, comunidad RISP, aplicaciones, casos de reutilización, etc.). "
                }
              },
              {
                "@type": "Question",
                "name": "¿Qué hacer en caso de incidencias o dudas?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "La sección Interactúa, en el apartado Informa sobre, tiene una opción aspira a recoger la opición de todos los usuarios. Si tienes cualquier incidencia o duda puedes enviarlas a través del formulario de contacto que puedes encontrar en la sección Interactúa o en el pie de la página. Estas aportaciones, abiertas a la participación de todos los usuarios, son fundamentales para mejorar el servicio y ofrecer unos recursos cada vez de mayor calidad y utilidad. En el caso de que pertenezcas a un organismo público puedes hacer uso del servicio de Asesoramiento y soporte que tiene a disposición la Iniciativa Aporta."
                }
              },
              {
                "@type": "Question",
                "name": "¿Quieres recibir mensualmente las últimas novedades del sector de la reutilización de la información del sector público?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "Datos.gob.es te invita a que te suscribas a su servicio de boletín electrónico: eventos, entrevistas, recursos, infografías y monográficos sobre datos abiertos para mantener informados a los usuarios interesados en open data. Además, conocerás de primera mano los últimos conjuntos de datos publicados por las AA.PP., nuevas apps que reutilizan datos abiertos o casos de uso a escala nacional e internacional. Introduce tu dirección de correo electrónico en el formulario situado en el pie de página y ¡únete a una comunidad de 1.700 suscriptores!"
                }
              },
              {
                "@type": "Question",
                "name": "¿Quieres darte de baja del Boletín?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "Si quieres darte de baja del boletín electrónico de novedades de datos.gob.es, introduce tu dirección de correo electrónico en el formulario situado en el pie de página llamado BOLETÍN DE NOTICIAS y selecciona la opción Darse de baja. Podrás volver a darte de alta de nuevo cuando lo desees, utilizando el mismo formulario."
                }
              },
              {
                "@type": "Question",
                "name": "¿Qué recursos ofrece el Catálogo?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "Actualmente, datos.gob.es da acceso a través del Catálogo de Información Pública a múltiples servicios y conjuntos de datos del sector público . Desde ellos se ofrece toda una amplia gama de informaciones (censos, directorios, imágenes…) de áreas de gestión o categorías diferentes."
                }
              },
              {
                "@type": "Question",
                "name": "¿Qué es un conjunto de datos?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "Es, como su nombre indica, una serie de datos vinculados entre sí y agrupados dentro de un mismo sistema de información para su potencial reutilización. Estos datasets (en su denominación anglosajona) se encuentran alojados en los servidores de los diferentes organismos editores a los que da acceso datos.gob.es."
                }
              },
              {
                "@type": "Question",
                "name": "¿Cómo funciona el buscador de conjuntos de datos?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "El buscador de conjuntos de datos permite la posibilidad de combinar búsquedas por texto libre con filtrado por categoría, formato, publicador, nivel de administración o etiquetas. Búsqueda por texto libre: El catálogo recuperará todos los conjuntos de datos que contengan la cadena de caracteres introducida en la caja de texto del buscador en cualquiera de sus metadatos. Si introducimos, dos o más cadenas de caracteres, el buscador devolverá aquellos conjuntos de datos que contengan ambas cadenas (AND) independientemente del orden. Si no se introduce ningún término, el buscador devolverá todos los conjuntos de datos. Si los resultados de la búsqueda son inferiores al 2000 datasets, aparecerá un botón “Descargar” que permite descargar los resultados en CSV. Búsqueda por filtros: Para acotar los resultados de una búsqueda también se pueden utilizar los filtros situados a la izquierda (categoría, formato, publicador, nivel de administración o etiquetas). Junto a cada uno de los elementos de los filtros aparece entre paréntesis el número de datasets que cumplen dicho criterio. Se pueden seleccionar varios términos a la vez de un mismo filtro o de varios. En la medida que se van seleccionando términos, se va acotando la búsqueda (AND) y se van actualizando el número de resultados disponibles por cada uno de los criterios de los filtros. Podemos ir ajustando las búsquedas combinando los filtros con texto libre (AND). Criterios de ordenación:Además, los conjuntos de datos recuperados en una búsqueda se pueden ordenar por los siguientes criterios: Publicado descendente: ordena los conjuntos de datos recuperados en base a la fecha en la que fueron dados de alta en el catálogo de datos.gob.es. Se muestran en las primeras posiciones los conjuntos de datos incorporados más recientemente. Publicado ascendente: ordena los conjuntos de datos en base a la fecha en la que fueron dados de alta en el catálogo de datos.gob.es. Se muestran en las primeras posiciones los conjuntos de datos en han sido incorporados antes. Modificado descendente: ordena los conjuntos de datos en base a la fecha de última modificación o actualización de la ficha de metadatos del conjunto de datos. Se muestran en las primeras posiciones los conjuntos de datos cuyos metadatos se han actualización en una fecha más reciente. Modificado ascendente: ordena los conjuntos de datos en base a la fecha de última modificación o actualización de la ficha de metadatos del conjunto de datos. Se muestran en las primeras posiciones los conjuntos de datos cuyos metadatos se han actualización en una fecha más antigua. Nombre: ordena los conjuntos de datos por orden alfabético en función del título del conjunto de datos."
                }
              },
              {
                "@type": "Question",
                "name": "¿Cómo dar de alta o modificar un conjunto de datos?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "Dar de alta y compartir un conjunto de datos público es una operación sencilla. Requiere, en todo caso, estar autorizado por la entidad pública en cuyo nombre se accede a datos.gob.es y por el propio administrador del portal. Los gestores autorizados deberán iniciar sesión con el nombre de usuario y la contraseña asociados a su cuenta de organismo público. Tras la identificación, podrán ya utilizar la opción Agregar conjuntos de datos que aparecerá en el Catálogo de datos."
                }
              },
              {
                "@type": "Question",
                "name": "¿Cómo crear una cuenta de usuario?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "La creación de una cuenta en datos.gob.es está dirigida a usuario a gestores del sector público autorizados por sus respectivos departamentos, organismos o entidades oficiales para el alta y actualización de los conjuntos de datos presentes en el Catálogo."
                }
              },
              {
                "@type": "Question",
                "name": "¿Qué formatos están admitidos para las distribuciones de los conjuntos de datos?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "La plataforma adminte una serie de formatos junto con su tipo MIME asociado. Podeis consultar esta lista en el siguiente fichero CSV formatos.En caso de tener en su catálogo distribuciones en formatos que no están admitidos actualmente en la plataforma, puede solicitar su inclusión poniendose en contacto con nosotros."
                }
              },
              {
                "@type": "Question",
                "name": "¿A qué nivel de la escala de las 5 estrellas pertenece cada uno de los formatos disponibles en datos.gob.es?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "Clasificar los formatos según la escala de las 5 estrellas sin tener en cuenta qué datos contiene cada conjunto y cómo se representa esa información es arriesgado ya que, dependiendo de cómo se esté usando el conjunto de datos puede cambiar de nivel, especialmente en los niveles más altos. No obstante, únicamente a modo de orientación, teniendo en cuenta que puede depender de los datos contenidos y de cómo esté representada la información, ésta podría ser una clasificación de los formatos que actualmente se presentan en datos.gob.es."
                }
              },
              {
                "@type": "Question",
                "name": "¿Cuáles son las licencias o condiciones de uso más habituales para los conjuntos de datos?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "En España, muchos organismos optan por abrir sus datos indicando unas condiciones de reutilización básicas publicadas en el aviso legal de su web que siguen las condiciones generales indicadas en el Real Decreto 1495/2011: No desnaturalizar el sentido de la información. Citar la fuente de los documentos objeto de la reutilización. Mencionar la fecha de la última actualización de los documentos objeto de la reutilización, siempre cuando estuviera incluida en el documento original. No se podrá indicar, insinuar o sugerir que los órganos administrativos, organismos o entidades del sector público estatal titulares de la información reutilizada participan, patrocinan o apoyan la reutilización que se lleve a cabo con ella. Conservar y no alterar ni suprimir los metadatos sobre la fecha de actualización y las condiciones de reutilización aplicables incluidos, en su caso, en el documento puesto a disposición para su reutilización por la Administración u organismo del sector público."
                }
              },
              {
                "@type": "Question",
                "name": "¿Para qué sirve una aplicación?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "Las aplicaciones reutilizan los datos públicos para permitir su consulta, visualización y comprensión a través de una página web o de un dispositivo móvil. Las aplicaciones, ya sean institucionales o privadas, libres o gratuitas, automatizan y contextualizan la información. De esta forma, transforman los recursos liberados por las administraciones en productos y servicios de alto valor social y/o económico."
                }
              },
              {
                "@type": "Question",
                "name": "¿Qué tipo de aplicaciones existen?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "Hay tantas clases de aplicaciones sobre datos abiertos del sector público como tipos de informaciones y potenciales usuarios puedan describirse. En todo caso, los productos y servicios más populares son los derivados de la reutilización de información del ámbito empresarial-económico; geográfico-cartográfico; jurídico-legal; de transportes; sociodemográfico-estadístico; y meteorológico, entre otros."
                }
              },
              {
                "@type": "Question",
                "name": "¿Cómo compartir nuevas aplicaciones?",
                "acceptedAnswer": {
                  "@type": "Answer",
                  "text": "Para subir y compartir una aplicación en datos.gob.es sólo hay que dirigirse a la sección Interactúa, en el aparatado Informa sobre y seleccionar la opción Aplicaciones. Para dar de alta una aplicación hay que cumplimentar el formulario que una vez enviado será revisado por el equipo de datos.gob.es antes de su publicación en la sección Impacto, apartado Aplicaciones."
                }
              }
            ]
          };

        var jsonCode = JSON.stringify(json);
        script.innerText = jsonCode;
        document.head.appendChild(script);
      }
    }
  };

}(jQuery));
