# Instalación desde GitHub.com
##### por [Patricio Gonzalez Vivo](www.patriciogonzalezvivo.com)

## 1. Instalación del cliente git

### Linux

``` sudo apt-get install git-core ```

### OSX
- Bajar e instalar [Xcode](http://developer.apple.com/devcenter/mac/index.action)

- Bajar e instalar [MacPorts](http://www.macports.org/)

- Desde la terminal actualizar los repositorios e instalar

```
	sudo port selfupdate 
	sudo port install git-core
```


## 2. Bajara la última versión de desarrollo de openFrameworks 

### Linux & OSX

``` 
	cd Desktop 
	git clone git://github.com/openframeworks/openFrameworks.git 
	cd openFrameworks
	git checkout develop
```

Nota: hasta que no se haga el release de la 0071 debemos cambiar al branch ```develop``` que tiene las últimas mejoras.


## 3. Instalar dependencias y crear proyectos

### Linux (Ubuntu)

```
	cd openFrameworks/scripts/linux/ubuntu
	sudo ./install_dependencies.sh
	sudo ./install_codeblocks.sh
	sudo ./install_codecs.sh 
	sudo apt-get install python-lxml
```


### Linux & OSX
- Abrir y compilar el proyectGenerator en ```openFrameworks/app/devApp/ProjectGenerator```
- Compilar todos los ejemplos y crear nuevos


