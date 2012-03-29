# ¿Qué es C++?
##### por [Jeff Crouse](http://www.jeffcrouse.info/)

Hemos aprendido en la última sección que openFrameworks no es un lenguaje de programación, sino más bien un framework para la creación de programas C++. ¿Pero lo qué es [C++](http://en.wikipedia.org/wiki/C%2B%2B)?

Esta documentación tiene el objetivo de guiar a través de openFrameworks, por medio del cual nos iremos familiarizando con el lenguaje C++. En si mismo este lenguaje es un tema super extenso e infinitamente profundo, por lo que tan sólo haremos una breve introducción al mismo.

C++ es una extensión del [lenguaje C](http://en.wikipedia.org/wiki/C_(programming_language) ), que fue desarrollado en 1979 en los Laboratorios de la Bell. Ambos idiomas fueron pensados con fines generales de computación para que se puedan ejecutar en prácticamente cualquier plataforma de computación en el mundo. Un ejemplo clásico del mismo es el siguiente:

```c++
	// my first program in C++
 
	#include <iostream>
	using namespace std;
 
	int main(){
  		cout << "Hello World!\n";
  		return 0;
	}
```

Para leer un desglose de estas líneas valla a [este enlace](http://www.cplusplus.com/doc/tutorial/program_structure/)

Después compilado, se creará un programa ejecutable a partir de este código. Se trata de una muy simple línea de comandos de programa que simplemente imprime "Hola Mundo!" a la consola, pero un programa, al fin. 

Para ello:

- abra un editor de texto como el TextEdit, nano, vi, emacs, TextWrangler y copie las lineas de código anteriores.

![editor](http://www.openframeworks.cc/tutorials/introduction/images/PlainText.png)

- Guárdelo en su escritorio.

- Abra una terminal y allí escriba

```
	cd Desktop
	g++ -o hello hello.cpp
	./hello
```

Devería ver algo similar a los siguiente:

![terminal](http://www.openframeworks.cc/tutorials/introduction/images/HelloWorld.png)

Felicidades, acaba de crear (y correr) su primer programa en C++! 
Debería estar viendo algo similar a esto:

![app](http://www.openframeworks.cc/tutorials/introduction/images/hello.png)

Quizá no luzca como los otros programas que utilizan llamativos iconos personalizados, pero es un programa! De hecho, si indagamos lo suficientemente profundo, todos los programas de tu computadora se reduce a un archivo tal como el programa de ```hello``` que acaba de crear. El resto es tan sólo chapa y pintura.

## ¿Qué es un compilador? y ¿qué es un IDE?
Si alguna vez usaste Flash o Processing, que tienen un estilo familliar al código de recién, entonces haz compilado cada vez que apretabas el botón de "play". Esto se conoce como compilación o elaboración, y es lo que acabamos de hacer en la sección anterior. Si usted es familliar con la edición de vídeo, la compilación es algo similar a la render. La idea es que se debe traducir el código que es "legible" en el formato que el ordenador puede ejecutar. C, C++, Java, Objective-C, Fortran, Lisp, Pascal ... estos son todos los [lenguajes compilados](http://en.wikipedia.org/wiki/Compiled_language). Por más crípticas que puedan parecer, todos estos lenguajes se supone que es "legible". Ellos fueron creados específicamente para ser escrito, leído, y entendido por los seres humanos. Pero no importa el idioma que empezar, al final, tiene que ser traducido en algo que tu computadora pueda entender. Es decir, [código de máquina](http://en.wikipedia.org/wiki/Machine_code).

Algunos idiomas, como el PHP y Python son conocidos como "lenguajes de script." Que todavía requieren la compilación, pero ocurre justo antes de que se ejecuta el programa.
El programa que hace el trabajo de tomar el código y su traducción al código de máquina que se llama el compilador. [GCC](http://gcc.gnu.org/) es uno de los compiladores más populares. Se puede compilar un montón de idiomas diferentes. GCC es muy bueno para la compilación, pero saber exactamente cómo decirle lo que quieres hacer a veces puede ser complejo y frustrante. Recién compilamos un programa muy sencillo y corto tan sólo con el comando ```g + +-o hola hello.cpp```, pero una vez que empiecemos a hacer cosas más complicadas puede ser imposible decirle al compilador que compilar primero y qué después. Decirle a gcc que compile incluso un proyecto vacío de openFrameworks puede tomar cientos de líneas y docenas de herramientas.

Así que en vez de hacerlo a mano, la mayoría de los desarrolladores utilizan IDEs (Entornos de Desarrollo Integrados) para organizar y crear proyectos. La mayoría de entornos de desarrollo incluirá un editor de texto, un organizador de archivos, un compilador y un montón de interfaces gráficas de usuario para personalizar todas las opciones y los detalles del proceso de compilación. Algunos [entornos de desarrollo populares](http://en.wikipedia.org/wiki/Comparison_of_integrated_development_environments) son: XCode, Visual Studio, CodeBlocks, Eclipse, NetBeans. Hay entornos de desarrollo para cada sistema operativo y el idioma. Algunos IDE son para un idioma específico y algunos tienen soporte para varios. 

Quizá estes familiarizado con entornos como Flash, Processing, VVVV, y MaxMSP, estos vienen con un montón de funcionalidades integradas que están generalmente optimizadas para un propósito en particular. Los IDE al contrario son como pizarras en blanco que vienen sin ninguna funcionalidad específica. 

openFrameworks definitivamente viene con un montón de funcionalidades. La diferencia con openFrameworks es que no viene con su propio IDE. Técnicamente, se puede usar cualquier IDE que desea capaz de crear un proyecto C++. Una de las grandes cosas acerca de openFrameworks es que proporciona puntos de partida para varios entornos de desarrollo en las 3 plataformas principales. Ellos han hecho el trabajo duro de crear plantillas de proyecto para tres entornos de desarrollo diferentes en las 3 plataformas principales para todo lo que tienes que hacer es descargar y empezar a programar.

Para empezar a trabajar con openFrameworks, tendrá que descargar e instalar un IDE de su sistema operativo. Se puede seguir las guías de instalación de acuerdo a la plataforma:

### Windows

[Code :: Blocks guía de configuración](http://www.openframeworks.cc/setup/codeblocks/)

[vs 2010 Guía de instalación](http://www.openframeworks.cc/setup/vs-2010/)


### Mac

[XCode Guía de instalación](http://www.openframeworks.cc/setup/xcode/)


### Linux

[codeblocks y makefiles](http://www.openframeworks.cc/setup/linux-codeblocks/)




En el próximo capítulo se detallará como instalar openFrameworks usando el repositorio git tanto en Linux como en Mac. Lo cual le permitirá utilizar la última versión de desarrollo y se parte de la vibrante comunidad de desarrolladores de oF y sus aportes.

