# Instalación desde GitHub.com
##### por [Patricio Gonzalez Vivo](www.patriciogonzalezvivo.com)

## 1. Pre-requicitos

Como vimos en el capítulo anterior, openFrameworks consiste tan sólo de un conjunto de librerías que facilita la utilización de varias librerías openSource. Por lo que tan sólo representa hojas de código que se relacionan con más hojas de código. Con esto quiero señalar que no existe un ejecutable como Processing o Flash el cual correr y pueda decir "Ahora estoy corriendo openFrameworks".

Para programar vamos a utilizar dos herramientas de desarrollo profesional hechas y derechas. La más importante es el IDE, una suerte de editor de texto que posee ciertas funciones que optimizan y facilitan nuestro trabajo. Allí crearemos proyectos que ordenen nuestras hojas de código y carga las librerías de openFrameworks con sus dependencias a las otras librerías openSource de las cuales se "alimenta".

La segunda herramienta es un cliente GIT, el cual nos permitirá bajar las librerías de openFrameworks y compartir código con otros programadores de la comunidad oF. El sistema de repositorio de código GIT fue desarrollado por el mismo Linus Torvals ( padre del proyecto Linux ) por lo que podemos deducir el nivel de confiabilidad, seriedad y espíritu libre de las herramientas que estamos utilizando.

Veamos los pasos para instalar ambas cosas en cada sistema operativo. 

### Linux

Si bien es posible instalar el codeBlocks desde Symbian, recomendamos que primero se instale el cliente GIT para bajar las librerías oF (descriptas en el segundo paso ) y luego recién ahí correr los scripts que instalan las dependencias, codecs y al mismo codeBlocks. 

``` sudo apt-get install git-core ```

El siguiente paso es abrir una Terminal ( en las nuevas distribuciones de ubuntu basta presionar la tecla que posee el logo de windows, por más extraño que esto suene, y tipear "terminal" )

### OSX

- Antes de realizar cualquier paso es preciso bajar e instalar [Xcode](http://developer.apple.com/devcenter/mac/index.action)

- Luego para poder descargar programas openSource (como el cliente GIT) es necesario bajar e instalar [MacPorts](http://www.macports.org/). El cual nos permite conectarnos con repositorios de código GNU de programas bien conocidos, descargarlos e instalarlos en nuestra computadora. De esta forma podemos disfrutar de las bondades del código abierto en un sistema que no lo es tanto.

- Una vez instalado el xCode y MacPorts. El siguiente paso consiste en actualizar los repositorios de código e instalar el cliente GIT. Para eso abrimos una Terminal ( `cmd + space + "terminal"` ) y tipeamos:

```
	sudo port selfupdate 
	sudo port install git-core
```

### Windows

- Empezamos bajando e instalando [Code::Blocks](http://www.codeblocks.org/downloads/26). Es muy importante elegir la opción que viene CON el compilador mingw 

![codeBlocks](http://www.patriciogonzalezvivo.com/images/tutoriales/codeblocks.png)

- CodeBlocks va a necesitar ciertas [librerías extra](http://www.openframeworks.cc/content/files/codeblocks_additions.zip). Luego de bajarlas hay que arrojar el contenido de:

 - `add_to_codeblocks_mingw_include` dentro de `C:\Program Files\CodeBlocks\MinGW\include` (o donde sea que este `app\mingw\include`)

 - `add_to_codeblocks_mingw_lib` dentro `C:\Program Files\CodeBlocks\MinGW\lib` (o donde este el directorio `app\mingw\lib` )

- El siguiente paso consiste en bajar e instalar un cliente [GIT para windows](http://code.google.com/p/msysgit/)

- Una vez que esta todo instalado vamos a abrir la terminal `Git Bash` y allí continuar ingresando los comandos descriptos en el paso siguiente

![git-bash-win](http://patriciogonzalezvivo.com/images/tutoriales/gitBash.jpg)


## 2. Bajara la última versión de desarrollo de openFrameworks 

El siguiente paso son una serie de comandos para consola bajar (o clonar) las librerías de openFrameworks que se encuentran en el repositorio GitHub dentro de un directorio en el escritorio. Es posible que aquí la ruta al mismo sea distinto.


``` 
	cd Desktop 
	git clone git://github.com/openframeworks/openFrameworks.git 
	cd openFrameworks
```

Felicitaciones tienes todos lo que necesitas para empezar a utilizar openFrameworks!!


Nota: hasta que no se haga el release de la 0071 debemos cambiar al branch ```develop``` que tiene las últimas mejoras. Puntual mente viene con varios nuevos ejemplos y un maravilloso generador de proyectos.

Para ello basta con escribir: 

``` 
	git checkout develop
```

De esta forma el cliente GIT cambia del branch `master` al `develop` el cual es muy inestable y debería ser utilizado sólo por desarrolladores con algo de experiencia.


## 3. Instalar dependencias ( sólo en Linux )

Sólo en linux es necesario correr algunas dependencias al principio y por única vez. Estas agregan librerías necesarias a la vez que instalan automáticamente el CodeBlocks para Linux.

```
	cd openFrameworks/scripts/linux/ubuntu
	sudo ./install_dependencies.sh
	sudo ./install_codeblocks.sh
	sudo ./install_codecs.sh 
	sudo apt-get install python-lxml
```


## 4. Crear los proyectos 

Para aquellos que se hallan animado a utilizar el branch `develop` tengo una buena noticia. El compilar y crear nuevos proyectos es súper sencillo. Basta con:

- Abrir el projectGenerator en ```openFrameworks/app/devApp/ProjectGenerator``` (en codeBlocks es necesario siempre abrir el que dice "CodeBlocks Workspace" en vez del que dice "CodeBlocks Project").

- Compilarlo haciendo click en "Build & Run"

- Una vez abierto veremos en la cajita negra del medio muchas opciones. Seleccionen aquella que coincide con sus sistema operativo e IDE y luego hagan click en "<- Generate"

- Una vez que hayan compilados los ejemplos quizá quieran ir a abrirlos y probarlos. Cuando ese momento mágico terminen quizá quieran crear el propio. Para eso vuelvan a este punto y hagan click en "Create" en el cuadro de la derecha. 


# Elige tu propia Aventura 

- En el caso de querer más en profundidad como es la estructura de openFrameworks ir al [Unidad 1: Cap. 3](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad1/Cap_3_estructura_oF.md)

- En el caso de querer saber como crear un proyecto en openFrameworks desde cero para compartir con gitHub ir al [Unidad 1: Cap. 4](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad1/Cap_4_intro_a_git.md)

- En el caso de querer pasar directamente a la acción y empezar a programar ir a la [Unidad 2: Cap. 4](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad2/Cap_4_Primeros_pasos.md)
