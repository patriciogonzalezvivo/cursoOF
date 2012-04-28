# Introducción a sistemas *nix
##### por [Patricio Gonzalez Vivo](http://www.patriciogonzalezvivo.com)

Si bien la relación C - Unix es íntimamente estrecha desde el comienzo de su historia. Es parte del proceso de profesionalizar nuestra labor como desarrolladores utilizar arquitectura robusta, modular, flexible y gratuita para este taller.

A la hora de realizar instalaciones interactivas la estabilidad y desempeño de los sistemas basados en Unix brindan una diferencia sustancial. Ya que por su caracter de servidores utilizan los recursos de forma eficiente brindando una base estable para realizar nuestro trabajo de forma prolija y profesional.

A su vez muchas veces las situaciones de montaje impiden el acceso a la máquina de la manera en la que estamos acostumbrados ( teclado, mouse y monitor todo enfrente nuestro y listo para acceder a ventanas donde editar el código ). Es por eso que en este curso nos parece importante acostumbrarnos a trabajar desde un ejecutador de comandos (shell/bash) desde consola. Ya que en muchas ocaciones esta será nuestra única y mejor manera de trabajar.

Teniendo una base sólida de terminal cualquier trabajo hacia arriba en términos de interfaces visuales multiplicará nuestra velocidad y capacidad de trabajo.

Si bien la estructura Unix es compartida y heredada por Linux y freeBSD. Aquí nos centraremos en Linux el cual representa un caso paradigmático y abierto de esta estructura de trabajo


## [Sistema de Archivos en Linux](http://www.google.com/url?q=http%3A%2F%2Fmat21.etsii.upm.es%2Fayudainf%2Faprendainf%2FLinux%2FLinux.pdf&sa=D&sntz=1&usg=AFQjCNFzufCI8vvbExPW9sPQtTP1TmE-Fw)

Al contrario que en Windows o MS-DOS el sistema de archivos en cualquier sistema Unix no está ligado de una forma directa con la estructura del hardware, esto es, no depende de si un determinado ordenador tiene 1, 2 o 7 discos duros para crear las unidades c:\, d:\ o m:\.  
Todos el sistema de archivos de Unix tiene un origen único la raíz o root representada por /. Bajo este directorio se encuentran todos los ficheros a los que puede acceder el sistema operativo. Estos ficheros se organizan en distintos directorios cuya misión y nombre son estándar para todos los sistema Unix. 

- `/`		Raíz del sistema de archivos. 

- `/dev`	 	Contiene ficheros del sistema representando los dispositivos que estén físicamente instalados en el ordenador. 

- `/etc`		Este directorio esta reservado para los ficheros de configuración del sistema. En este 
directorio no debe aparecer ningún fichero binario (programas). Bajo este deben aparecer otros dos subdirectorios:
 
- `/etc/X11`	Ficheros de configuración de X Window

- `/lib` 		Contiene las librerías necesarias para que se ejecuten los programas que residen en

- `/bin` 		(no las librerías de los programas de los usuarios). 

- `/proc`		Contiene ficheros especiales que o bien reciben o envían información al kernel del 
sistema (Se recomienda no modificar el contenido de este directorio y sus ficheros).

- `/sbin`		Contiene programas que son únicamente accesibles al superusuario o root. 

- `/usr`		Este es uno de los directorios más importantes del sistema puesto que contiene los 
programas de uso común para todos los usuarios. 
Su estructura suele ser similar a la siguiente: 

- `/usr/X11R6`  Contiene los programas para ejecutar X Window. 

- `/usr/bin`   	Programas de uso general, lo que incluye el compilador de C/C++.

- `/usr/doc`   	Documentación general del sistema. 

- `/usr/etc`   	Ficheros de configuración generales.
 
- `/usr/include`  Ficheros de cabecera de C/C++ (.h). 

- `/usr/info`		Ficheros de información de GNU. 

- `/usr/lib`		Librerías generales de los programas. 

- `/usr/man`		Manuales accesibles con el comando man (ver más adelante). 

- `/usr/sbin`  	Programas de administración del sistema. 

- `/usr/src`  	Código fuente de programas. 

Existen además de los anteriores otros directorios que se suelen localizar en el 
directorio `/usr`, como por ejemplo las carpetas de los programas que se instalen en el 
sistema. 

- `/var`  Este directorio contiene información temporal de los programas (lo cual no implica que se 
pueda borrar su contenido, de hecho, ¡no se debe hacer!)

[Más info...](www.ibm.com/developerworks/linux/library/l-lpic1-v3-102-1/)

# [Permisos](http://www.google.com/url?q=http%3A%2F%2Flafec.df.uba.ar%2Ftutorial_18pag.pdf&sa=D&sntz=1&usg=AFQjCNHT04MszGn0h8lT1ORu24UCbcR0WA)

Linux, como cualquier sistema Unix, es multiusuario, por lo que, los permisos de los archivos están orientados a dicho sistema. Los permisos de cualquier archivo tienen tres partes: permisos del propietario, permisos del grupo y permisos del resto. Así, se ve que un archivo pertenece a un determinado propietario y a un determinado grupo y, dependiendo de los permisos que tenga asociado dicho archivo, se podrá tener acceso a él o no.
Los permisos son de lectura (r), escritura (w) y ejecución (x). Estos se definen mediante letras (parecido al comando attrib de DOS). Con el signo "añadimos un permiso y con el signo" se lo quitamos. Además, los permisos pueden ser generales o no, es decir, si se pone sería permiso de ejecución a todos, sin embargo, si se pone sólo el propietario podría ejecutarlo. De este modo, se tiene: para propietario, para grupo y para el resto. Ejemplo: Se tiene una serie de archivos después de listar con `ls -l` el cual muestra el propietario (skina), el grupo (users) y los permisos de izquierda a derecha: propietario, grupo y el resto.

```

	[]$ ls -l
	-rw-r--r-- 1 skina users 17680 	Nov 29 16:52 GNU-GPL.tex
	-rw-r--r-- 1 skina users 2573 	Nov 30 19:52 Makefile
	-rw-r--r-- 1 skina users 1562 	Nov 29 13:47 autorizacion.txt
	-rw-r--r-- 1 skina users 461 	Oct 24 21:43 biblio.tex
	drwxr-xr-x 2 skina users 1024 	Nov 23 01:02 bin/
	-rw-r--r-- 1 skina users 949 	Nov 30 19:26 creditos.tex
	-rw-r--r-- 1 skina users 550 	Nov 30 19:48 curso_linux.tex
	drwxr-xr-x 2 skina users 3072 	Nov 30 22:55 images/
	drwxr-xr-x 3 skina users 1024 	Nov 30 00:09 install/
	-rw-r--r-- 1 skina users 61566 	Oct 26 22:29 lista_paquetes_mdk.tex
	-rw-r--r-- 1 skina users 53227 	Nov 23 01:08 lista_paquetes_rh.tex
	-rw-r--r-- 1 skina users 3864 	Nov 30 19:56 parte1.tex
	[]$

```

Estos permisos llevan "asociado" un número: el cuatro para lectura, el dos para la escritura y el uno para la ejecución. De esta manera, un archivo tiene tres números asignados: propietario, grupo y resto. Por ejemplo, si tenemos un fichero con los permisos `644` correspondería a: el propietario puede leer/escribir, el grupo sólo puede leer y el resto sólo puede leer. Vemos que, para asignar lectura y escritura, basta con sumar lectura(4)+escritura(2).
El comando para modificar los permisos es `chmod` y tiene la siguiente sintaxis: `chmod` permisos archivo(s). Por ejemplo se desea que todos las personas puedan ver escribir sobre el archivo creditos.tex, entonces

```# chmod a+w creditos.tex```

o su equivalente en números

```# chmod 666 creditos.tex```

[Más info...](www.acm.uiuc.edu/webmonkeys/html_workshop/unix.html) 


# [Comandos](http://www.google.com/url?q=http%3A%2F%2Flafec.df.uba.ar%2Ftutorial_18pag.pdf&sa=D&sntz=1&usg=AFQjCNHT04MszGn0h8lT1ORu24UCbcR0WA) 

## Comandos básicos

Los comandos son esencialmente los mismos que cualquier sistema UNIX. En la tablas 1 y 2 se tiene la lista de comandos mas frecuentes. En la tabla 3 se tiene una lista de equivalencias entre comandos Unix/Linux y comandos DOS.
Comando/Sintaxis	Descripción	Ejemplos

- `cat fich1 [...fichN]` 	Concatena y muestra un archivos. Por ej:	`cat /etc/passwd` o `cat dict1 dict2 dict`

- `cd [dir]` 	Cambia de directorio. Por ej:	`cd /tmp`

- `chmod permisos fich`	 Cambia los permisos de un archivo. Por ej: `chmod +x miscript`

- `chown usuario:grupo fich` 	Cambia el dueño un archivo. Por ej: `chown nobody miscript`

- `cp fich1...fichN dir`	Copia archivos. Por ej: `	cp foo foo.backup`

- `diff [-e]arch1 arch2` 	Encuentra diferencia entre archivos. Por ej: `diff foo.c newfoo.c`

- `du [-sabr] fich` 	Reporta el tamaño del directorio. Por ej: `du -s /home/`

- `file arch`	Muestra el tipo de un archivo. Por ej:	`file arc_desconocido`

- `find dir test acción`	Encuentra archivos. Por ej:	`find . -name ‘‘.bak’’ - print`

- `grep [-cilnv] archivos`	Busca patrones en archivos. Por ej: `grep mike /etc/passwd`

- `head -count fich`	Muestra el inicio de un archivo. Por ej: `head prog1.c`

- `mkdir dir`	Crea un directorio. Por ej:	`mkdir temp`

- `mv fich1 ...fichN dir`	Mueve un archivo a un directorio.  Por ej: `mv a.out prog1`

- `mv fich1 fich2`		Renombra un archivo. Por ej: `mv .c prog_dir`

- `less / more fich`	Visualiza página a página un archivo. less acepta comandos vi. Por ej: `more muy_largo.c`

- `ln [-s] fich acceso` 	Crea un acceso directo a un archivo less acepta comandos vi. `ln -s /users/mike/.profile`

- `ls` 	Lista el contenido del directorio. Por ej: 	`ls -l /usr/bin`

- `pwd` 	Muestra la ruta del directorio actual	pwd

- `rm fich`	Borra un fichero. Por ej:	`rm foo.c`

- `rm -r dir`	Borra un todo un directorio. Por ej:	`rm -rf prog_dir`

- `rmdir dir`	Borra un directorio vacío. Por ej:	`rmdir prog_dir`

- `tail -count fich`	Muestra el final de un archivo. Por ej:  `tail prog1.c`

- `vi fich`	Edita un archivo. Por ej:	`vi .profile`

- `at [-lr] hora [fecha]`	Ejecuta un comando mas tarde. Por ej: `at 6pm Friday miscript`

- `cal [[mes] año]`	Muestra un calendario del mes/año. Por ej: `cal 1 2025`

- `date [mmddhhmm] [+form]`	Muestra la hora y la fecha. Por ej: `date`

- `echo string`	Escribe mensaje en la salida. Por ej:	 `echo "Hola mundo"`

- `finger usuario` 	Muestra información general sobre un usuario en la red `finger nn@maquina.aca.com`

- `id Número`	id de un usuario. Por ej: `id usuario`

- `kill [-señal] PID`	Matar un proceso. Por ej: 	`kill 1234`

- `man comando`	Ayuda comando del especificado. Por ej: `man gcc`

- `passwd`	Cambia la contraseña

- `ps [axiu]` 	Muestra información sobre los procesos que se están ejecutando en el sistema. Por ej: `ps -ux` o `ps -ef`

- `who` o `rwho` 	Muestra información de los usuarios conectados al sistema.


## Comandos en Background

Linux, como cualquier sistema Unix, puede ejecutar varias tareas al mismo tiempo. En sistemas monoprocesador, se asigna un determinado tiempo a cada tarea de manera que, al usuario, le parece que se ejecutan al mismo tiempo.
Para ejecutar un programa en background, basta con poner el signo ampersand (`&`) al término de la línea de comandos. Por ejemplo, si se quisiera copiar el directorio `/usr/src/linux` al directorio `/tmp`:

```
	#cp -r /usr/src/linux /tmp &
	#
```

Cuando ha terminado la ejecución del programa, el sistema lo reporta mediante un
mensaje:

```
	#
	[Done] cp -r /usr/src/linux /tmp
	#
```

Si se hubiese ejecutado el programa y no se hubiese puesto el ampersand, se podría
pasarlo a background de la siguiente manera:
1. Se suspende la ejecución del programa, pulsando Ctrl+Z.
2. Se ejecutamos la siguiente orden: bg


## Interprete de comandos: Shell

El interprete de comandos es el programa que recibe lo que se escribe en la terminal y lo convierte en instrucciones para el sistema operativo.
En otras palabras el objetivo de cualquier intérprete de comandos es ejecutar los programas que el usuario teclea en el prompt del mismo. El prompt es una indicación que muestra el intérprete para anunciar que espera una orden del usuario. Cuando el usuario escribe una orden, el intérprete ejecuta dicha orden. En dicha orden, puede haber programas internos o externos: Los programas internos son aquellos que vienen incorporados en el propio intérprete, mientras que los externos son programas separados (ej: aplicaciones de `/bin`, `/usr/bin`,...).
En el mundo Linux/Unix existen tres grandes familias de Shells como se muestra en la tabla a continuación. Estas se diferencian entre sí básicamente en la sintaxis de sus comandos y en la interacción con el usuario.

[Más info sobre shells](www.ibm.com/developerworks/linux/library/l-linux-shells/index.html)


### Sintaxis de los comandos

Los comandos tienen la siguiente sintaxis:

```
	# programa arg1 arg2 ... argn
```

Se observa que, en la "línea de comandos" se introduce el programa seguido de uno o varios argumentos. Así, el intérprete ejecutará el programa con las opciones que se hayan
escrito.
Cuando se quiere que el comando sea de varias líneas, se separa cada línea con el carácter
barra invertida (`/`). Además, cuando se quiere ejecutar varios comandos en la misma línea,
los separa con punto y coma (`;). Por ejemplo:

```
	# make modules ; make modules_install
```

En los comandos, también se puede utilizar los comodines:
El asterisco (`*`) es equivalente a uno o más caracteres en el nombre de un archivo. Ejm: `ls *.c` lista todos los archivos con extensión c.
El signo de interrogación (`?`) es equivalente a un único carácter. Ejm: `ls curso.te?` lista el archivo curso.tex completando el último carácter.
Un conjunto de caracteres entre corchetes es equivalente a cualquier carácter del conjunto. Ejm: `ls curso_linux.t[aeiou]x` lista curso_linux.tex seleccionando la e del conjunto. .


### Variables de entorno

Una variable de entorno es un nombre asociado a una cadena de caracteres. Dependiendo de la variable, su utilidad puede ser distinta. Algunas son útiles para no tener que escribir muchas opciones al ejecutar un programa, otras las utiliza el propio shell (PATH, PS1,...). La tabla muestra la lista de variables más usuales.


`$DISPLAY` 	Donde aparecen la salidas de X-Windows.
`$HOME` 		Directorio personal.
`$HOSTNAME` 	Nombre de la máquina.
`$MAIL` 		Archivo de correo.
`$PATH` 		Lista de directorios donde buscar los programas.
`$PS1` 		Prompt.
`$SHELL` 		Intérprete de comandos por defecto.
`TERM` 		Tipo de terminal.
`USER` 		Nombre del usuario.


### Alias

Un "alias" es un nombre alternativo para un comando. Así, en lugar de escribir el comando propiamente dicho, escribiríamos el alias de dicho comando.
Un alias se puede definir por varios motivos, por ejemplo:
Dar nombres familiares a comandos comunes:  `alias md="mkdir"`
Crearía un alias para el comando largos: `alias tbz2="tar -cv --use-compress-program=bzip2 -f"`
Para no tener que escribir todos los alias siempre que entremos al sistema, escribiríamos dicho alias en el archivo `/.bash_profile`

### Tuberías o pipes: redireccionamiento de E/S

La filosofía de Linux/Unix es en extremo modular. Se prefieren las herramientas pequeñas con tareas puntuales a las meta-herramientas que realizan todo. Para hacer el modelo completo es necesario proveer el medio para ensamblar estas herramientas en estructuras mas complejas. Esto se realiza por medio del redireccionamiento de las entradas y las salidas.

Redirección de Entrada y Salidas fig_redirect width=5cmimages/standard_io.eps

Todos los programas tiene por por defecto una entrada estándar (teclado) y dos salidas: la salida estándar (pantalla) y la salida de error (pantalla). En ellos se puede sustituir la entrada y salidas estándar por otro dispositivo utilizando los caracteres `'y `' es decir, hacer que se lea un archivo que contenga las opciones a ejecutar y un archivo de salida, respectivamente. Por ejemplo:

#### Entrada
Se desea realizar una transferencia de archivos por ftp automática. Para ello se va a utilizar el programa `ncftp con unas determinadas instrucciones preestablecidas.

Se crea un archivo entrada con dichas instrucciones:

```
	open linuxcol.uniandes.edu.co
	cd /pub/linux/utils
	get *
	quit
```

y se ejecuta el programa: `ncftp < entrada` .

#### Salida

Se quiere saber los archivos que empiezan por i o I y almacenarlo en un archivo:

``` ls [iI]* > listado.txt ```

Es importante resaltar que el carácter de redirección de salida “destruirá el archivo al cual apunta, si este existe, para ser reemplazado por uno nuevo con los resultados del proceso. Si se desea anexar la información a uno ya existente debe usarse doble carácter”

[Más info](http://www.gulic.org/cila/files/Libro_CILA.pdf)

## Aplicaciones Útiles ( en construcción )

www.ibm.com/developerworks/training/kp/l-kp-command/index.html
www.commandlinefu.com/commands/browse/
kkovacs.eu/cool-but-obscure-unix-tools/
www.devdaily.com/unix/edu/IntroToUnix/

[GREP](http://www.tech-recipes.com/rx/16732/unixlinux-how-to-use-grep-commands/)

[GIT](www.devdaily.com/git/git-cheat-sheet-git-reference-commands/)
o
progit.org/book/index.html

[SSH](http://blog.urfix.com/25-ssh-commands-tricks)

XSCREEN


# Elige tu propia Aventura 
 
- Estas chocho siguiendo el programa propuesto y te gusta no perderte ni un punto. Entonces el [siguiente capítulo](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad2/Cap_2_Que_es_cpp.md) es para ti. Allí veremos las particularidades de C++;

- Si eres fanático de Processing y estas en el proceso del cambio quizá te interese leer el [Cap. 2 de la Unidad 2](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad2/Cap_3_desde_processing.md)

- Bueno, es suficiente! Quiero pasar a la acción! Ve a la [Unidad 2, Cap. 4](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad2/Cap_4_Primeros_pasos.md) para empezar a programar en oF cuanto antes!