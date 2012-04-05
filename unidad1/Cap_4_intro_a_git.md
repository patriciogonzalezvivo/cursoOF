# epositorio gitHub
##### por [Patricio Gonzalez Vivo](http://www.patriciogonzalezvivo.com)

Este tutorial contiene una breve introducción al sistema de control de versiones de repositorios [GIT](http://en.wikipedia.org/wiki/Git_%28software%29). La cual es una herramienta que te permite mantener fácilmente un backup de tu código, junto con la posibilidad de tener distintas versiones, colaboradores y por sobre todo la posibilidad de poder compartirlo fácilmente.
Es una mejora incalculable para cualquier proyecto.

Además, te permite cooperar con los demás en el código de una manera significativamente más eficaz, por lo que no hay realmente ninguna razón para no hacerlo, sin duda va a hacer tu vida mucho más fácil.


Es una buena idea comenzar a utilizarlo cuanto antes para tus propios proyectos o bien como para colaborar cuanto antes con la comunidad openFrameworks. Como sistema de repositorios remotos utilizaremos [GitHub](www.github.com). Por lo que partiremos por crear una [cuenta gratuita](https://github.com/signup/free).

[GitHub](www.github.com) posee información detallada de los pasos a realizar (es fundamental relacionados con las claves SSH ). Es importante comprender que la gracia del sistema git es que la información no esta centralizada en ninguna parte. Los repositorios gitHub son tan sólo repositorios remotos. Pero pormedio de un cliente local git uno puede gozar de todas las funcionalidades de un sistema de control de versiones, como volver realizar cambios ( **commit** ), subir modificaciones ( **push** ), bajar actualizaciones ( **pull** ), deshacer cambios ( **stash** ), separar una nueva versión ( **branch** ), abrir una nueva rama ( **fork** ), mezclar dos rama ( **merge** ), etc.

Como lo hemos realizado en el capítulo anterior todas estas tareas pueden realizarse desde consola (lo cual es muy sencillo en Linux y Mac). Pero también es posible realizarlos con cualquier cliente git que posea una interface gráfica. Estos te ayudarán a mantener tu repositorio **local** con el **remote** (en este caso en gitHub).
En StackOverflow pueden encontrar los mejores clientes git para cada plataforma [Linux](http://stackoverflow.com/q/2141611/599884), [MacOS](http://stackoverflow.com/questions/455698/best-visual-client-for-git-on-mac-os-x) y [Windows](http://stackoverflow.com/questions/157476/what-guis-exist-for-git-on-windows).

Antes de comenzar, sería conveniente que el lector se empapara aún más de las características básica leyendo el siguiente material:

- [gitref.org](http://gitref.org/) es una referencia concisa de los elementos esenciales de git. Setarda como 30 minutos en leerla, pero vale la pena.

- [La página de ayuda github](http://help.github.com/) posee información sobre el uso básico, los conceptos y términos de git y github. Es bueno tener una primera idea acerca de las cosas que normalmente se puede hacer con git.

- También existe un resumen en [titanPad](http://piratepad.net/ofgitcheatsheet) de comandos frecuentes hecho para la comunidad OF.

Perfecto, una vez claros hasta aquí prosigamos viendo cómo crear un repositorio git, iniciar un proyecto y rastrear los cambios. Además de aprender cómo llevar a cabo las tareas más frecuentes en git.

## Usando Git para proyecto en oF

Comenzaremos por dirigirnos al al `apps/devApps/projectGenerator/` dentro de nuestro directorio de openFrameworks. Una vez allí abriremos el proyecto con nuestro IDE, lo compilaremos y lo correremos.

La primera vez que lo corramos nos preguntará donde se encuentra nuestro directorio de openFrameworks. Nosotros deberemos indicarle el camino hacia el mismo.

Una vez cargado el programa clickearemos donde dice "create project"

![projectGenerator](http://www.patriciogonzalezvivo.com/images/tutoriales/proyectGenerator.png)

Elegimos el directorio donde queremos crearlo y... listo.

![nuevo](http://www.patriciogonzalezvivo.com/images/tutoriales/nuevoProyecto.png)

Si vamos al directorio donde lo creamos veremos que agregó los tres archivos básicos de toda aplicación en OF (`main.cpp`, `testApp.h` y `testApp.cpp`), los directorios `bin` y `bin/data`, junto con un proyecto a medida de nuestro IDE.

Ahora lo que queda es trabajar sobre nuestro proyecto.

Pero antes, crearemos un repositorio remoto en nuestra cuenta [GitHub](www.github.com).

Para eso vamos a nuestra cuenta on-line en [www.github.com](www.github.com) y clickeamos donde dice "New repository".

![nuevoREpo](http://www.patriciogonzalezvivo.com/images/tutoriales/newRepo.png)

Ingresamos los datos del projecto y luego al apretar "Create repository" [GitHub](www.github.com) nos dará una descripción detalada de los pasos a realizar. Los mismos son para ser realizados desde la consola.

Los primeros tienen que ver con el seteo general del cliente git local con los datos de la cuenta en GitHub y sólo deben ser realizados la primera vez. 

![pasos](http://www.patriciogonzalezvivo.com/images/tutoriales/pasosGit.png)

El resto de los mismos tiene que ver con crear un directorio q contenga el proyecto (lo cual no es necesario ya que le ProjectGenerator se ha encargado de ello). Inicializar el git ( `git init` ) lo cual crea el directorio `.git` que contendrá todos los archivos y camibos. Luego crear un archivo README (GitHub abre automáticamente los archivos con ese nombre y muestra el contenido en el navegador, también abre los README.md los cuales tienen un formato llamado markDown del cual es posible aprender más en [aquí](http://github.github.com/github-flavored-markdown/)). Luego agrega ( **add** ) a este archivo al sistema git. Para después realizar lo que se conoce como un **commit**, que vendría a hacer como aceptar que este archivo a cambiado y por lo tanto git debe encargarse de él.

A continuación le dice al cliente git local que exite una repositorio remoto de este proyecto con el cual puede sincronizarse ( `git remote add origin …. `) 

Finalmente realiza un **push** de la información, que en otras palabras significa sube los cambios al repositorio remoto. 

Todo esto parece largo y complicado. Tienen reazón!!

Es por eso que a partir de este punto conviene usar un cliente con una buena GUI. Por lo general una vez creado el proyecto, inicializado y configurado el repositorio remoto es posible dragear la carpeta a nuestro cliente Git preferido y automáticamente el se encargará de todo. Veremos que sólo verá que archivos hace falta subir y actualizar. Para cada vez que halla que subir los cambios pedirá que se le otorge un texto explicativo para el commit. 

Es vital realizar la mayor cantidad de commit q sea posible todo el tiempo que sea posible con el mejor grado de detalle y síntesis que sea posible en su descripción. Esta buena práctica lo transformará en un colaborador valorado en su comunidad. 

	
### Ignorando archivos
Es importante que git **sólo analice los archivos correctos.**
Los que son generados automáticamente, temporales, binarios o específicos de usuario no deberían formar parte del repositorio, ya que están generados por el código fuente para un determinado usuario.

En git, existe la posibilidad de especificar elaborados patrones para ignorar archovos utilizando el archivo `.gitignore` (el `.` es importante).
Un `.gitignore ` pre-hecho esta adjunto en tu proyecto si haz bajado oF desde el respositorio git.

Una colección útil de `.gitignore` con una amplia cantidad de archivos para distintas situaciones puede ser encontrado [aquí](https://github.com/github/gitignore).

Tenga en cuenta que los archivos que ya forman parte del depósito no se tienen en cuenta.
Además, una vez que los archivos se añaden al repositorio, se convierten en parte de la historia y estarán allí para quedarse. De esta manera, es muy fácil de aumentar innecesariamente el tamaño de su repositorio, porque no hay manera fácil de purgar los archivos añadidos por error desde el repositorio (especialmente si usted ha llevado ya a su repositorio en línea).
Por estas razones, es **muy importante** estar atentos al añadir archivos a su repositorio.



### Repositorios remotos: origin y upstream
[Remotes](http://gitref.org/remotes/) son los identificadores de los repositorios remotos con los que probablemente quieras interactuar.
Hacen que sea fácil acceder a los repositorios sin tener que escribir las direcciones URL en todo momento.
Es costumbre nombrar a la copia de tu propio repositorio (por ejemplo, en github) como `origin` (como acabamos de realizar al seguir los pasos detallados en por github). Al mismo tiempo cada vez que uno realiza un `git clone` a un repositorio de GitHub (como hicimos cuando bajamos la versión de openFrameworks desde el repositiorio github) este también queda como origin.
Por otro lado, si el repositorio es un fork de otro repositorio, por ejemplo, o sea en el caso que tengas tu propia copia de otro repositorio (por ejemplo tu propia copia de OF), ese repositorio normalmente se le llama `usptream`.


### Push-eando nuevas versiones a Github
Si tenés un trabajo nuevo en una **branch** separado y deseas subirlo a tu repositorio git. La cadena de comandos sería:

```
	git push origin new-work
```
	
### Crear una copia local de un branch en un repositorio remoto 

Si quieres echa un vistazo al **branch** de un repositorio, que todavía no existe en el repositorio local, se utiliza

```
	git fetch origin
	git checkout --track origin/interesting-branch
```

El segundo comando crea una sucursal local llamada `interesting-branch` que coincide con el origen de `origin/interesting-branch`. Esto le dice a Git que deseas ser capaz de subir ( **push** ) con facilidad y sacar de la misma rama ( **branch** ) en el remoto.

### Borrando ramas (branches) en el repo remoto 
Si usted ha trabajado en alguna rama, por ejemplo, para una solicitud de extracción para obtener algunas correcciones de errores en el OF, y usted no necesita esta rama más, por ejemplo, si el PR se ha fusionado ya, continuación, puede eliminar la rama en el control remoto diciendo

```
	git push origin :old-branch
```

### Flujo de trabajo para contribuir con OF 
[Este](https://github.com/openframeworks/openFrameworks/wiki/openFrameworks-git-workflow) es documento que describe el flujo de trabajo de la de desarrolladores seguir para el desarrollo.
Si desea contribuir con éxito el código de openFrameworks, debe seguir este documento.
También es útil leerlo en el caso que quieras trabajar en un gran proyecto junto con otros.


## Soluciones para los problemas más frecuentes 

Hay ciertas situaciones con las que probablemente se vallan a encontrar cuando trabaja con git.
En lo que sigue, algunas de estas situaciones se identifican y un método de solución es identificado.


### Hacer un pull con cambios uncommitted

Si usted ha hecho cambios sin confirmar, pero no está todavía listo para hacer un commit, y desea actualizar su branch de trabajo por medio de un pull al repositorio remoto, va a ser imposible ya que git se negará a realizarlo.

A way around this is to use `git stash`.
This is a really useful [feature](http://gitready.com/beginner/2009/01/10/stashing-your-changes.html) similar to a clipboard, where you can temporarily store changes while doing something else.
There's [an extensive array of options](http://linux.die.net/man/1/git-stash)
Typically, you'll only need `git stash`, which pushes the current changes onto the stash, and `git stash pop`, which pops the latest stash set back again.
So, in the present case, you would do

	<code a bit>
	git stash
	git pull upstream develop
	git stash pop
	<continue work>

### Git para los que vienen de SVN
Si haz usado SVN, y queres pasar a git, las cosas pueden ser confusas. Hay algunos recursos en la web, un tutorial que explica los comandos equivalentes que se puede encontrar [aquí](http://git.or.cz/course/svn.html).
Una cosa a tener en cuenta es que un `commit` es mucho menos grave en git, ya que permanecerá en su repositorio local. En git la clave es  **"commit early, commit often"**.

Otra distinción es que tener tu propio repositorio es mucho más independiente de un repositorio central.

Además, la fusión (merging) y la ramificación (branching) son las cosas que son fundamentales para la forma git trabaja, a fin de utilizarlo libremente.

## More git resources:

If you want to learn some more tricks, want to get more in-depth info, or run into a problem not mentioned in this tutorial, here's a collection of resources you should consult:

[The oF git cheat sheet](http://piratepad.net/ofgitcheatsheet): A small list of **helpful git commands put together by oF developers**.

[Pro Git](http://progit.org/): A book, also freely available on the homepage in html form. Deals with everything from git basics to advanced concepts.

[The git man pages](http://www.kernel.org/pub/software/scm/git/docs/): The manual of git. Also available on your command line, but much more readable on the net. :D Bare-bones explanation of the details of command line git usage.

If you ever have a question about how to do things in git, it is often best to enter your question on [Stack overflow](http://www.stackoverflow.com). Most probably someone there has had your problem before. For example, [How do I make git ignore mode changes?](http://stackoverflow.com/search?q=How+do+I+make+git+ignore+mode+changes)

There is also a great amount of articles, wiki pages, tutorials and blog posts about git, for example [git for the lazy](http://spheredev.org/wiki/Git_for_the_lazy) or [Git Immersion](http://library.edgecase.com/git_immersion/index.html).

