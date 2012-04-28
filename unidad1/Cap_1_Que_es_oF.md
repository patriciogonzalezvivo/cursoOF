# ¿Qué es openFrameworks? 
##### por [Jeff Crouse](http://www.jeffcrouse.info/) y traducido por [Patricio Gonzalez Vivo](http://www.patriciogonzalezvivo.com)
 
openFrameworks es un conjunto de herramientas de código abierto en C++ diseñado para ayudar al proceso creativo. Proporciona un marco sencillo e intuitivo para la experimentación. Este kit une varias librerías de uso común bajo una misma coherencia y estilo para su uso general y reutilización. Estas librerías son:

- [OpenGL](http://www.opengl.org/), [Glew](http://glew.sourceforge.net/), [GLUT](http://www.opengl.org/resources/libraries/glut/), [libtess2](https://code.google.com/p/libtess2/) y [cairo](http://cairographics.org/) para los gráficos

- [RTAudio](http://www.music.mcgill.ca/~gary/rtaudio/), [PortAudio](http://www.portaudio.com/) o [FMOD](http://www.fmod.org/) y [Kiss FFT](http://kissfft.sourceforge.net/) para la entrada de audio, salida y análisis

- [FreeType](http://freetype.sourceforge.net/index2.html) para las fuentes

- [FreeImage](http://freeimage.sourceforge.net/) para la imagen de guardar y cargar

- [Quicktime](http://developer.apple.com/quicktime/) y [videoinput](https://github.com/ofTheo/videoInput) para reproducción de vídeo y el acaparamiento

- [Poco](http://pocoproject.org/) para una variedad de utilidades

Más adelante veremos en detalle algunos de estos paquete (como OpenGL). La mayoría de ellos hacen sus cosas en el fondo y es probable que nunca tengas que preocuparte de ellos. Cada una de estas bibliotecas tienen su propia sintaxis, convenciones y peculiaridades, pero la belleza de openFrameworks es que no tenés que preocuparte de ellas. oF es una sola interfaz sencilla, coherente y transparente que hace el trabajo duro para que puedas crear código robusto y profesional de forma fácil y sencilla.

El código está escrito para ser completamente compatible entre plataformas. En este momento tienen soporte cinco sistemas operativos (Windows, OSX, Linux, iOS, Android) y cuatro IDEs (XCode, Code :: Blocks, y Visual Studio y Eclipse). La API está diseñado para ser minima y fácil de entender.

openFrameworks esta en activo desarrollo por [Zach Lieberman](http://thesystemis.com/), [Theodore Watson](http://muonics.net/) y [Arturo Castro](http://arturocastro.net/), junto con su gran [comunidad oF](http://www.openframeworks.cc/community/). openFrameworks está en deuda con dos precursores importantes: el entorno de desarrollo [Processing](http://processing.org/), creado por [Casey Reas](http://reas.com/), [Ben Fry](http://benfry.com/) y la comunidad de procesamiento, y ACU ToolKiet, desarrollado por Ben Fry y [MIT Media Lab’s Aesthetics and Computation Group](http://acg.media.mit.edu/).


# Preguntas Frecuentes

## ¿openFrameworks es un programa?

OF no es en sí un programa o una aplicación, pero se puede utilizar para escribir tus propios programas y aplicaciones.

## ¿Es un lenguaje de programación?

OF no constituye un lenguaje propio de programación, el lenguaje que se utiliza para escribir programas con OF es C++.

## ¿Entonces es una biblioteca?

OF esta en realidad compuesto por varias bibliotecas, osea una librería de librerías que por lo general recibe el nombre de framework.

## ¿Qué es un framework?

Un framework es una especie de infraestructura de diseño pre-fabricado. Esta proporciona toda la funcionalidad de bajo nivel necesaria al mismo tiempo que permite al programador personalizar los detalles de más alto nivel. Una forma que el uso de un marco difiere de utilizar una biblioteca es que el flujo de control se invierte. Una biblioteca puede ser controlada directamente por el código para llevar a cabo un conjunto de tareas generales. Un framework los eventos e interfaces responde a un modelo prediseñado. En el caso de OF este mismo criterio se utiliza para acceder a otras librerías que poseen criterios y diseños diferentes.

## Suena complicado

De hecho, muchos otros ambientes de autoría multimedia funciona de esta manera, incluso si lo hacen menos transparente.

Imaginemos este caso: estás escribiendo y dirigiendo tu propia película y han decidido trabajar con una compañía de producción cinematográfica. La productora se reserva la ubicación, proporciona toda la infraestructura, se encuentra el equipo de cámara, director de iluminación, ingeniero de sonido y personal importante. Esto hace que todos estén en el escenario a tiempo y que hagan su trabajo cuando deben. Su trabajo consiste en definir lo que sucede en el set, una vez que todos estén listos. OpenFrameworks es como una productora de cine para tu programa. Se ocupa de los detalles administrativos y logísticos y te permite concentrarse en su visión creativa.


## ¿Qué se puede hacer con oF?
La siguiente colección de proyectos es un intento de ilustrar la variedad de diferentes tipos de aplicaciones que se han construido con openFrameworks.

### [Puppet Parade](https://vimeo.com/34824490) por Emily Watson y Gobeille Theo

<iframe src="http://player.vimeo.com/video/34824490" width="640" height="360" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>

Puppet Parade es una instalación interactiva por Emily Watson y Theo Gobeille de Design I/O que permite a los niños a usar sus brazos para titiritero más grande que la vida criaturas proyectadas en la pared frente a ellos. Esta instalación interactiva de doble permite a los niños para llevar a cabo junto a los títeres, desdibujando la línea entre el "público" y de los titiriteros y la creación de un diálogo sin fin lúdico entre los niños en el espacio de títeres y los niños de las criaturas.
— creativeapplications.net

[Más información...](http://www.creativeapplications.net/openframeworks/puppet-parade-openframeworks/)

### [UD Interactive Wall](https://vimeo.com/27500054)

<iframe src="http://player.vimeo.com/video/27500054" width="640" height="360" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>

La pared de 36 pies en la Universidad de Dayton centro de admisión involucra a los estudiantes potenciales y revela los videos de la vida estudiantil en la UD. La pared muestra continuamente cambios en los patrones de gráficos generativos, que responden a la presencia de personas delante de la pared.

El campo de los cubos está animado con las ondas de actividad, y la presencia de un espectador hace que se gire y descubrir vídeos Punto de vista de la experiencia de los estudiantes. Los espectadores pueden explorar los vídeos que se mueven alrededor para revelar diferentes fragmentos de vídeo. Cuando los espectadores están juntos, sus siluetas se unen para revelar más de la de vídeo. Cuando no hay nadie presente en el área de la interacción de la instalación muestra animaciones tipográficas superpuestos en los patrones de gráficos animados de forma dinámica.

Para obtener la documentación de vídeo más y detalles del proceso de diseño y desarrollo de [Case Study](http://www.flightphase.com/main_wp/case-studies/ud-interactive-wall).

- Flightphase.com

[Más información](http://www.flightphase.com/main_wp/expanded-media/interactive-wall-at-ud)



### [Scramble Suit](https://vimeo.com/29391633) por Arturo Castro y Kyle McDonald

<iframe src="http://player.vimeo.com/video/29391633" width="640" height="360" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>

Una gran cosa acerca openFrameworks es que lo fácil de incorporar código C + + desde casi cualquier biblioteca. Para ello, Arturo y Kyle utiliza la [biblioteca FaceTracker de Jason Saragih](http://web.mac.com/jsaragih/FaceTracker/FaceTracker.html) para crear una técnica de reemplazo de la cara que Kyle llamado "traje de Scramble", inspirada en la tecnología de ficción a partir de 1977 Philip K. Dick, la novela, "A Scanner Darkly". Es efectivamente un manto que oculta la identidad del usuario por lo que es imposible de describir o recordar ellos.

# Elige tu propia Aventura 

- Ok, te convenciste que openFrameworks es para ti... pero no lo tienes instalado! No desesperes sólo debes ir al [ siguiente capítulo de esta unidad ](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad1/Cap_2_Instalacion.md)

- Si ya programaste y te intriga saber más en profundidad de que se trata openFrameworks. Puede saltar hasta el [Cap. 3 de esta unidad](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad1/Cap_3_estructura_oF.md) y aprender como esta estructurado oF

- Si eres fanático de Processing y estas en el proceso del cambio quizá te interese leer el [Cap. 2 de la Unidad 2](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad2/Cap_3_desde_processing.md)

- En cambio, si te preguntas ¿Qué es C++? sigue por el [capítulo 2 de la siguiente unidad](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad2/Cap_2_Que_es_cpp.md)

- Si ya tenés instalada una versión de openFrameworks y muchas ganas de empezar de cero a repasar lo que ya conoces puedes ir a [Unidad 2, Cap. 4](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad2/Cap_4_Primeros_pasos.md)
