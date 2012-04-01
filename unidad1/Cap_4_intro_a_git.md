# Bases sobre repositorios Git
##### por Christoph Buchner (en proceso de traducción por [Patricio Gonzalez Vivo](http://www.patriciogonzalezvivo.com))

Este tutorial contiene una breve introducción al sistema de control de versiones de repositorios git. Es una buena ida para comenzar a desarrollar código utilizándolo en tus propios proyectos o para interactuar con la comunidad openFrameworks y [github](www.github.com).

Veremos cómo crear un repositorio git, iniciar un proyecto y rastrear los cambios. Además de aprender cómo llevar a cabo las tareas más frecuentes en git.

## ¿Porqué es importante?

El control de versiones es una herramienta que te permite mantener fácilmente la historia, los cambios, y las diferentes variantes de código que escriben.
Es una mejora incalculable el no tener que guardar copias de seguridad de forma manual a través de comprimir la carpeta de su programa o un mecanismo similar.

Además, te permite cooperar con los demás en el código de una manera significativamente más eficaz, por lo que no hay realmente ninguna razón para no hacerlo, sin duda va a hacer tu vida mucho más fácil.

## Información básica sobre Git

[Git](http://en.wikipedia.org/wiki/Git_%28software%29) es el sistema de control de versiones de elección para openFrameworks y github, así que esto es lo que vamos a utilizar.
Es un sistema de revisión llamado [control distribuido](http://en.wikipedia.org/wiki/Distributed_revision_control), lo que básicamente significa que no es necesario tener un servidor central / repositorio ejecutando para su uso.

Si es la primera vez que escuchas sobre git, hay un par de los recursos que debes googlear antes de continuar con este tutorial. Ellos *le enseñará lo básico de cómo usar* git. Después de eso, vamos a tocar algunas de las cosas que surgen cuando estás usando git con OF.

[gitref.org](http://gitref.org/) es una referencia concisa de los elementos esenciales de git. Setarda como 30 minutos en leerla, pero vale la pena.

[La página de ayuda github](http://help.github.com/) posee información sobre el uso básico, los conceptos y términos de git y github. Es bueno tener una primera idea acerca de las cosas que normalmente se puede hacer con git.

También existe un resumen en [titanPad](http://piratepad.net/ofgitcheatsheet) de comandos frecuentes hecho para la comunidad OF.

## Usando Git para proyecto en oF

Si desea utilizar git con sus proyectos, tiene sentido **comenzar tan pronto como sea posible**, idealmente antes de que siquiera empezar a programar.

A continuación se presentan algunas de las cosas digno de mención, aparte del uso de base, que está cubierto por los vínculos de la sección anterior.

	
### Ignorando archivos
Es importante que git **sólo analice los archivos correctos.**
Los que son generados automáticamente, temporales, binarios o específicos de usuario no deberían formar parte del repositorio, ya que están generados por el código fuente para un determinado usuario.

En git, existe la posibilidad de especificar elaborados patrones para ignorar archovos utilizando el archivo `.gitignore` (el `.` es importante).
Un `.gitignore ` pre-hecho esta adjunto en tu proyecto si haz bajado oF desde el respositorio git.

Una colección útil de `.gitignore` con una amplia cantidad de archivos para distintas situaciones puede ser encontrado [aquí](https://github.com/github/gitignore).

Tenga en cuenta que los archivos que ya forman parte del depósito no se tienen en cuenta.
Además, una vez que los archivos se añaden al repositorio, se convierten en parte de la historia y estarán allí para quedarse. De esta manera, es muy fácil de aumentar innecesariamente el tamaño de su repositorio, porque no hay manera fácil de purgar los archivos añadidos por error desde el repositorio (especialmente si usted ha llevado ya a su repositorio en línea).
Por estas razones, es **muy importante** estar atentos al añadir archivos a su repositorio.

### Git GUIs
Si no desea utilizar la línea de comandos, hay un número de clientes git visuales por ahí que puede utilizar.
StackOverflow tiene una buena colección de los candidatos para [Linux](http://stackoverflow.com/q/2141611/599884), [MacOS](http://stackoverflow.com/questions/455698/best-visual-client-for-git-on-mac-os-x) y [Windows](http://stackoverflow.com/questions/157476/what-guis-exist-for-git-on-windows).

### Repositorios remotos: origin y upstream
[Remotes](http://gitref.org/remotes/) son los identificadores de los repositorios remotos con los que probablemente quieras interactuar.
Hacen que sea fácil acceder a los repositorios sin tener que escribir las direcciones URL en todo momento.
Es costumbre nombrar a la copia de tu propio repositorio (por ejemplo, en github) como `origin` . Esto se hace automáticamente cuando escribes `git clone` a un repositorio de GitHub.
Por otro lado, si el repositorio es un fork de otro repositorio, por ejemplo, si usted tiene su propia copia de la OF, ese repositorio normalmente se le llama `usptream`.

### Git para los que vienen de SVN
Si haz usado SVN, y queres pasar a git, las cosas pueden ser confusas. Hay algunos recursos en la web, un tutorial que explica los comandos equivalentes que se puede encontrar [aquí](http://git.or.cz/course/svn.html).
Una cosa a tener en cuenta es que un `commit` es mucho menos grave en git, ya que permanecerá en su repositorio local. En git la clave es  **"commit early, commit often"**.

Otra distinción es que tener tu propio repositorio es mucho más independiente de un repositorio central.

Además, la fusión (merging) y la ramificación (branching) son las cosas que son fundamentales para la forma git trabaja, a fin de utilizarlo libremente.

### Empujando nuevas versiones (Pushingnew branches) a Github
Si usted tiene un trabajo nuevo en una rama separada, y que desea llevar este a su repositorio github, usted dice

```
	git push origin new-work
```
	
### Crear una copia local de un branch en un repositorio remoto 

Si quieres echa un vistazo a la rama de un repositorio, que todavía no existe en el repositorio local, se utiliza

```
	git fetch origin
	git checkout --track origin/interesting-branch
```

El segundo comando crea una sucursal local llamado `interesting-branch` que coincide con el origen de `origin/interesting-branch` le dice a Git que desea ser capaz de subir (push) con facilidad y sacar de la rama (branch) en el control remoto.

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

## More git resources:

If you want to learn some more tricks, want to get more in-depth info, or run into a problem not mentioned in this tutorial, here's a collection of resources you should consult:

[The oF git cheat sheet](http://piratepad.net/ofgitcheatsheet): A small list of **helpful git commands put together by oF developers**.

[Pro Git](http://progit.org/): A book, also freely available on the homepage in html form. Deals with everything from git basics to advanced concepts.

[The git man pages](http://www.kernel.org/pub/software/scm/git/docs/): The manual of git. Also available on your command line, but much more readable on the net. :D Bare-bones explanation of the details of command line git usage.

If you ever have a question about how to do things in git, it is often best to enter your question on [Stack overflow](http://www.stackoverflow.com). Most probably someone there has had your problem before. For example, [How do I make git ignore mode changes?](http://stackoverflow.com/search?q=How+do+I+make+git+ignore+mode+changes)

There is also a great amount of articles, wiki pages, tutorials and blog posts about git, for example [git for the lazy](http://spheredev.org/wiki/Git_for_the_lazy) or [Git Immersion](http://library.edgecase.com/git_immersion/index.html).

