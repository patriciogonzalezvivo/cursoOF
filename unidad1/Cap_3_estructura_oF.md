# Estructura oF 
##### por [Patricio Gonzalez Vivo](http://www.patriciogonzalezvivo.com)

OpenFrameworks es en esencia es una colección de librerías integradas bajo un mismo formato de forma que puedan trabajar juntas. Por ejemplo: openGL para gráficos, freeImages para imágenes, fmod para sonidos, etc. Muchas de las funciones y clases en oF acceden a estas funciones y clases de estas librerías sólo para darles un formato similar. De tal forma de brindar un formato consistente para todo el entorno. 

![cuadro](http://www.patriciogonzalezvivo.com/images/tutoriales/structure004.png)

## Directorios

Cuando uno abre la carpeta de openFrameworks se encuentra con los siguientes directorios:

### /addons		
Allí se encuentran los módulos de librerías adicionales. Por convención los addons comienzan con el prefijo `ofx` mientras que las clases nativas con `of`
En cada addon también se repite una estructura
Estando por cada addon los siguientes directorios:
 
- `ofx*/src`	 	las clases oF 
- `ofx*/libs`	 	las clases de la librería original
- `ofx*/examples`	 ejemplos de su utilización


### apps 

Aquí se suelen guardar los proyectos en los cuales trabajas.
Es importante tener en cuenta que esto es una convención. Uno puede crear otro directorio para contener proyectos, siempre y cuando se respete una distancia de tres niveles con la librería `/libs` de openFrameworks. Porqué?  para compilar exitosamente cualquier proyecto se utilizan referencias relativas a la carpeta `openFrameworks/libs` ,usualmente retrocediendo tres niveles desde donde esta alojado el proyecto ( `../../../libs/*` )

Si se esta utilizando la versión de desarrollo del github encontrará que esta carpeta sólo contiene otro directorio donde se halla entre otras cosas el ProjectGenerator utilizado para crear proyectos automáticamente en todas las plataformas e IDEs soportados.

### examples

Allí se encuentra cantidades de ejemplos para aprender a sacarle el jugo a oF. Si no lo vez es posible que no estes usando la versión del github. En ese caso los encoentrarás dentro del directorio `apps`

- `apps/examples`		Ejemplos utilizando funciones y clases nativas a oF (en la nueva versión se encuentra en el raíz ).

- `apps/addonsExamples` 	Ejemplos que utilizan addons (en la nueva versión esta dentronde de `examples/addons` )

### libs

Donde se enceuntran las librerias que utiliza openFrameworks y las clases de ella misma.
		
- `libs/*`			Cada una de estos directorios contiene las librerías openSource de las cuales oF se nutre.
- `libs/openFrameworks` 	Aquí están las funciones y clases nativas de oF. Las cuales vale la pena entrar y ver como están hechas y organizadas.
 
### scripts

Este directorio es útil para instalar oF dentro de entornos linux ya que poseen scripts de instalación de dependencias.


# Estructura de clases en C++ ( .h y .cpp)

Las clases en C++ utilizan dos archivos: un header ( *.h ) y un source ( *.cpp ). Pese a que todo se podría escribir dentro del header, se utiliza esta convención por muchas razones: organización, portabilidad, tiempo de compilado, etc...
 
En un *.h o header encontramos declaradas todas las variables y funciones de la clase, al igual que cualquier definición o parámetro para el pre-compilador. El header es similar al índice de un libro a una lista de ingredientes de una receta de cocina. Es muy útil a la hora de conocer como funciona a grandes razgos una clase y aprender como utilizarla.

```c++
	#ifndef PARTICLE_H	// Comando para el pre-compilador en donde pregunta
	#define PARTICLE_H	// si es que no ha sido definido esta clase lo 
 				// lo haga ahora. Esta función cierra con el 	#endif
  				// final. De otra forma agrega una clase dentro de
  				// otra causando problemas al compilar

	#include "ofMain.h"	// Agrega todas las clases y funciones nativas de oF

	class Particle		// Declaración de clase
	{
    		Particle();		// Constructor (oblicatorio)
    		~Particle();		// Destructor (opcional)

    		// Metodos
    		void update();
    		void draw();
	
    		// Variables
    		float x, y;
    		float vel_x, vel_y;
	};				// Atención! las clases terminan con punto y coma

	#endif			// Atención! cerrar el ifndef con un endif estos 
	// dos detalles te pueden volver loco a la hora de
	// compilar
```

Es importante tener en cuenta y empezar a hacer uso del pre-compilador de C++ ya que es el quien se encarga de unir y formatear el código antes de compilarlo. Además de para agregar funciones de otras clases como ejemplo con el #include “ofMain.h” es muy útil a la hora de prototipar para definir variables constantes universales por ejemplo:


```c++
	#define CAMWIDTH 640 
```

[Más información...](http://profeblog.es/blog/alfredo/2009/01/15/directivas-de-compilacion-el-precompilador-de-c/)

El archivo .cpp contiene el código de la clase en cuestión con sus devidas instrucciones por cada función o método. Siguendo con la metáfora del libro son los capítulos en si mismos.

```c++
	#include "particle.h"		// header al cual corresponde

	Particle::Particle		// el primer Particle responde al nombre
	{					// de la clase y el segundo a la función
 		x = 0;				// en este caso al constructor
 		y = 0;
 		vel_x = 0;
 		vel_y = 0;
	}

	Particle::~Particle
	{
	}

	void Particle::update()
	{
  		x += vel_x;
  		y += vel_y;
	}

	void Particle::draw()
	{
  		ofCircle(x,y,2);
	}
```

[Para más información sobre clases](http://www.modelo.edu.mx/univ/virtech/prograc/cplus5.htm)

# Estructura de un proyecto en oF

Por cada proyecto independientemente de la plataforma e IDE que utilicemos encontramos los siguientes directorios y archivos:

`src/`	Directorio donde se encuentra el código

`src/main.cpp`		los archivos main.cpp son el punto de partida de cualquier 
programa en C++. De hecho no puede haber dos. Si lo abrimos vamos a observar que en el construye una instancia de una applicación con una ventana contruida en GLUT con siertas dimensiones. Para luego correr la clase testApp.

`src/testApp.h`		Aquí se inicializa el header (o los ingredientes ) la clase 
testApp. La cual notamos que hereda de la clase	ofBaseApp ( clase estandar de una app en oF ). Ella contiene por default 4 metodos y 9 eventos ( de teclado, mouse, etc.. )

`src/testApp.cpp`		Aquí es donde pasa la magia del programa

`bin/`	Directorio donde se alojarán los binarios una vez se compile el código
	
`bin/data`	directorio de información donde guardar o leer datos desde la app. De forma pre-establecida todo programa en oF mira hacia este directorio. Esto es modificable mediante el comando `ofSetDataPathRoot();` a la vez que se puede obtener el path absoluto a un archivo en el mediante el comando `ofToDataPath( string nombreDeArchivo ,true);`



# Estructura del testApp

La clase testApp que viene por defecto en cada proyecto hereda de `libs/openFrameworks/app/ofBaseApp.h`. Esta clase posee 4 métodos standar los cuales podemos modificar. La mayoría de la funcionalidad en openFrameworks funciona con este modelo. En todos los ofApp, hay siempre que configurar, actualizar y dibujar.

## setup()

El método de configuración se llama una sola vez al comienzo de la aplicación y se usa para inicializar otros objetos o variables normalmente declarados en `ofApp.h`.

__ofApp.h__

~~~~{.cpp}

	ofVideoPlayer player;
	int counter;

~~~~

__ofApp.cpp__

~~~~{.cpp}

	void ofApp::setup(){
    		player.loadMovie("movie.mov");
    		counter = 0;
	}
~~~~

En C++ es súper importante inicializar las variables ya que por defecto no se inicializan. Por ejemplo, si no hacemos `counter = 0;`, `counter` no puede tener un valor.


###update/draw()

`update() y `draw()` son llamados en un bucle infinito, uno tras del otro, y en ese orden, hasta que termine la aplicación.

Actualización está destinada a ser utilizada para actualizar el estado de nuestra aplicación, realice los cálculos que tenemos que hacer y actualizar otros objetos como reproductores de vídeo, capturadores, o cualquier análisis de la visión por ordenador que podría estar haciendo ...

En `draw()` tenemos acceso a dibujar en pantalla.

__ofApp.h__

~~~~{.cpp}
	float x;
~~~~

__ofApp.cpp__

~~~~{.cpp}
	void ofApp::setup(){
    		x = 0;
	}

	void ofApp::update(){
    		x++;
	}

	void ofApp::draw(){
    		ofCircle(x,120,30);
	}
~~~~

Esto dibuja un círculo en y = 120 moviéndose hacia la derecha desde la esquina superior izquierda de la pantalla.

## Clases

openFrameworks está principalmente organizada en clases. Hay 3 tipos de clases:

### Clases de Herramientas

Estas son las clases que hacen algo. Son clases como `ofVideoGrabber`, `ofVideoPlayer`, `ofSoundPlayer`, `ofImage`, etc... La mayoría de estas clases utilizan el mismo sistema de configuración ( `setup()` ) / actualización ( `update()` ) / dibujar ( `draw()` ). Por supuesto, para algunos de ellos rendereo no tendrá sentido, por ejemplo un ofSoundPlayer no tiene un método de dibujo.

Estas clases también siguen un patrón común del puntero. Esto significa que cuando se copian la copia es en realidad lo que se llama una copia superficial. Una copia superficial es sólo una referencia al objeto, no una copia de su contenido.

Por ejemplo, si copia un reproductor de vídeo y luego modificar la copia de alguna manera que también se va a modificar el original:

__ofApp.h__

~~~~{.cpp}
	ofVideoPlayer player;
~~~~

__ofApp.cpp__

~~~~{.cpp}
	void ofApp::update(){
    		ofVideoPlayer player2 = player;
    		player2.setFrame(100);
	}
~~~~

Esto establecerá el fram a 100, tanto en jugador y jugador 2 ya que en realidad el jugador y el jugador 2 poseen una referencia al mismo objeto

### Clases de Datos

Estas clases contienen datos y puede hacer algunas operaciones con esos datos que contienen. Ejemplos de ello son las clases como `ofPixels` o `ofBuffer`.

Estas clases siguen un patrón de `allocate` / `loadData`. Asignar ( `alocate` ) memoria reserva en el recipiente donde luego volcar utilizando loadData. Los nombres de estas funciones cambian dependiendo de la clase, pero la funcionalidad es la misma. Copia de estas clases hace una copia de profundidad, lo que significa que una copia es un objeto completamente nuevo con el mismo contenido que el original para modificar la copia no va a tocar el original.

__ofApp.h__

~~~~{.cpp}
	ofPixels pixels1, pixels2;
	ofTexture tex1, tex2;
~~~~

__ofApp.cpp__

~~~~{.cpp}
	void ofApp::setup(){
    		pixels1.allocate(640,480,OF_IMAGE_COLOR)
    		pixels1.set(0);
    		pixels2 = pixels1;
    		pixels2.setColor(10,10,ofColor(255,255,255);
    
    		tex1.allocate(640,480,GL_RGB);
    		tex2.allocate(640,480,GL_RGB);
    		tex1.loadData(pixels1);
    		tex2.loadData(pixels2);
	}

	void ofApp::draw(){
    		tex1.draw(0,0);
    		tex2.draw(660,0);
	}
~~~~

Sacará una imagen completamente en negro en la izquierda de la pantalla y una imagen de color negro con un pixel blanco a 10,10 en la derecha. Cuando llamamos `pixels2 = pixels1`, `` pixels2 se asigna con el mismo tamaño y número de canales como `` pixels1 y los datos de `` pixels1 se copia a `` pixels2.

### Contenedores de datos GL

Los contenedores GL son un caso especial de los contenedores de datos. La funcionalidad es bastante similar a otros contenedores de datos y también sigue el patrón de `allocate` / `loadData` . Estas son las clases como `ofTexture()`, `ofFbo()`, `ofVbo()` o `ofVboMesh()`. Todas ellas están en la carpeta GL, aunque no todo en la carpeta GL es un contenedor de datos, como `ofShader()` o `ofLight()`, que son de utilidad clases GL y generalmente se comportan exactamente igual que otras clases de utilidad.

La diferencia principal entre GL contenedores de datos y contenedores otros datos es que GL contenedores de datos siguen un patrón copia superficial. La razón principal de esto es el rendimiento, lo que hace una copia de los recursos de la GPU suele ser lento para que no los copie de forma predeterminada.

Por ejemplo:

__ofApp.h__

~~~~{.cpp}
	ofTexture tex1, tex2;
~~~~

__ofApp.cpp__

~~~~{.cpp}
	void ofApp::setup(){
    		tex1.allocate(640,480,GL_RGB);
    		ofPixels pixels;
    		pixels.allocate(640,480,OF_IMAGE_COLOR);
    		pixels.set(0);
    		tex1.loadData(pixels);
    		tex2 = tex1;
    		pixels.setColor(10,10,ofColor(255,255,255);
    		tex2.loadData(pixels);
	}

	void ofApp::draw(){
    		tex1.draw(0,0);
    		tex2.draw(660,0);
	}
~~~~

Dibujará un rectángulo negro con un píxel blanco en 10,10 en los lados izquierdo y derecho de la pantalla. Esto es porque en este caso estamos copiando el recurso de GL, que en realidad es sólo una referencia a la ID de la textura de la primera textura, no una copia completa, por lo que cuando se modifica también estamos modificando el original.

### Tipo de datos

Estas son las clases que representan tipos de openFrameworks como `ofRectangle()`, `ofVec3f()` o `ofMatrix4x4()`.

## Funciones

Algunas funciones de openFrameworks se realiza a través las funciones de C llanura. Estos son por lo general las funciones de utilidad como `ofToString()`, `ofRandom()`, `ofDrawBitmapString()` y funciones simples de dibujo como `ofCircle`, `ofRect()`.

## Eventos
También encontramos que existen 10 eventos nativos en cada ofApp que casi que se explican sólos

```c++
	windowResized(int w, int h)
	
	keyPressed(int key)
	keyReleased(int x, int y)
	
	mouseMoved(int x, int y)
	mouseDraged(int x, int y, int button)
	mousePressed(int x, int y, int button)
	mouseReleased()
	mouseReleased(int x, int y, int button)
	
	dragEvent(ofDragInfo dragInfo)
	gotMessage(ofMessage msg)
```

# Elige tu propia Aventura 

- Ok, te convenciste que openFrameworks es para ti... pero no lo tienes instalado! No desesperes sólo debes ir al [ siguiente capítulo de esta unidad ](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad1/Cap_2_Instalacion.md)

- Si eres fanático de Processing y estas en el proceso del cambio quizá te interese leer el [Cap. 2 de la Unidad 2](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad2/Cap_3_desde_processing.md)

- En cambio, si te preguntas ¿Qué es C++? y ¿Cuáles son sus particularidades? sigue por el [capítulo 2 de la siguiente unidad](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad2/Cap_2_Que_es_cpp.md)

- Si ya tenés instalada una versión de openFrameworks y muchas ganas de empezar de cero a repasar lo que ya conoces puedes ir a [Unidad 2, Cap. 4](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad2/Cap_4_Primeros_pasos.md)

