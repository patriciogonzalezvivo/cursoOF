# Un "Hola Mundo" visual
##### por Patricio González Vivo

## Introducción 

Este archivo da por sentado que se han leído los anteriores, se ha instalado satisfactoriamente openFrameworks, creado los proyectos. A su vez también se recomienda que antes de arrancar se hallan compilado los proyectos de ejemplo.

## Arranquemos por dibujar algo 

Cómo hemos visto el testApp esta divido en `setup()`, `update()` y `draw()`. Para dibujar algo, debemos agregarlo en el método donde hay acceso a pantalla. Ese mismo es el `draw()`. 
Entonces, empecemos por crear un nuevo proyecto con el ProjectGenerator o bien duplicando un `emptyExample`. Una vez hecho eso abrieromos el `testApp.cpp` que contiene las implementaciones de los métodos definidos en el `testApp.h` y editemos el `void testApp::draw()` :

~~~~{.cpp}
	#include "testApp.h"

	void testApp::setup(){

	}

	void testApp::update(){

	}

	void testApp::draw(){
		ofBackground(0);
		ofSetColor(255,0,0);	// ofSetColor() altera el color de
							// todas las figuras que se dibujen 
							// luego de ser declarada
		ofCircle(100, 100, 30);
	}
~~~~
 
Vallamos paso a paso. 
Comenzamos por limpiar el fondo pintándolo de negro con `ofBackground(0)`. El comando `background()` puede aceptar tanto un entero que va de 0 a 255 respondiendo al nivel de blanco o bien, tres valores que responden al rojo, verde y azul. 
Esta manera de utilizar los tres canales para definir un color es precisamente la que utilizamos en la siguiente linea al definir el color que vamos a utilizar para dibujar el círculo con `ofSetColor(255,0,0)`. Al proporcional el valor más alto al color canal rojo dejando el resto en 0, estamos definiendo el color en rojo puro. 
Paso siguiente dibujamos un círculo `ofCircle(float _x, float _y, float _radio)` en la posición 100 de `x` y 100 de `y` con 30 pixels de radio. 

Una de las propiedades del `ofSetColor()` más importantes es que este cambio persistirá en todos las subsiguientes figuras que se dibujen. Si quisiéramos dibujar un rectángulo la función que necesitaríamos sería `ofRect( float _x, float _y, float _width, float _height)`. El cual será dibujado respetando el color preestablecido.

Otra propiedad que funciona de igual manera consiste el relleno de las figuras. La misma se define utilizando los métodos de `ofFill()` y `ofNoFill()`. Podemos probar esto utilizando uno u otro. De esta forma si quisiéramos hacer una figura con un borde de distinto color que su contenido deberíamos dibujarlo dos veces cambiando de color al mismo tiempo que se activa y desactiva el relleno con estos dos últimos métodos.

De igual manera es posible cambiar el tamaño del grueso de la linea a dibujar utilizando `ofSetLineWidth( float ancho )`.

Prestando especial atención al nivel de detalle de nuestro círculo podemos notar que es bastante "tosco". Esto es mejorable utilizando dos métodos diferentes. El primero consiste en "suavizar" los bordes colocando `ofEnableSmoothing()` (en el método de `setup()` para que sea activado una sola vez al comienzo de nuestra aplicación).
Mientras que el segundo consiste en alterar el grado de definición del círculo con `ofSetCircleResolution( int _resolution )`. El entero que determina la resolución consiste en la cantidad de lados que tendrán los círculos desde ese momento y hasta que se vuelva a definir (tal y como funcionan `ofSetColor()` y `ofFill()`/`ofNoFill()` ).
De esta forma si quisiéramos dibujar triángulos basta con especificar la resolución a `3`.
 
En el caso que tan sólo querramos dibujar una linea en pantalla sólo necesitaremos la función `ofLine( float x1, float y1, float x2 , float y2 )` el cual debemos completar con las dos posiciones en pantalla del comienzo y final de la misma.

Hablando de posiciones vemos que otra característica de openFrameworks a la hora de dibujar en pantalla es su sistema de coordenadas. Jugando con los valores `x` e `y` podemos comprender rápidamente como la esquina superior izquierda es el punto de referencia `0,0` en pantalla.

![coordenadas](http://www.patriciogonzalezvivo.com/images/tutoriales/coordinates.png)

A la hora de colocar un objeto en pantalla podemos también valernos de otros métodos nativos de openFrameworks que pueden ayudarnos. Este es el caso de `ofGetWindowsWidth()` y `ofGetWindowsHeight()` que nos permiten saber el largo y altura de la ventana de nuestra aplicación. O bien con `ofGetScreenWidth()` y `ofGetScreenHeight()`

Poco a poco, empezamos a ver un cierto estilo gramatical en openFrameworks, el cual es bastante congruente y predecible. Siempre que quiera definir algo comenzará con `ofSet...` y todas las veces que quiera saber un valor el método comenzará con `ofGet...`. A sabiendas de estos dos detalles y valiéndonos con el autocompletado de nuestro IDE podremos descubrir rápidamente nuevos métodos y funciones de oF de forma intuitiva. Explore!! Notará que incluso puede preguntar información al sistema sobre el framerate, el mes, fecha y hora, posición de la ventana y muchas cosas más! Puede adivinar como serían los nombres de esas funciones? 

¿Qué sucede si quisiéramos realizar una figura irregular? Bueno, en ese caso podríamos hacerlo diciéndole a oF que vamos a comenzar a dibujar una figura con `ofBeginShape()`, y luego pasarle las posiciones de cada uno de los vértices del mismo con `ofVertex(float x, float y )`, para luego cerrar dicha figura con `ofEndShape( true )`. En el caso de querer dejar abierta la figura deberíamos cambiar el `true` por un `false`.

En fin, hemos empezado por dibujar algo a pantalla y nos hemos extendido viendo un montón de funciones y métodos que nos permiten dibujar una variedad de cosas. Es hora de aplicar todo este conocimiento a un desafío interesante. Aquí va. Tomando como referencia este cuadro de Kandisky dibuje en su monitor algo que se le asemeje lo más posible. Sea creativo, a la vez que eficiente... piense que cosas pueden ser dibujadas en menos código utilizando loops (o bucles ) `for`. 

![kandisky](http://www.patriciogonzalezvivo.com/images/tutoriales/kandinsky.jpg)

## Movámoslo

Todo muy interesante, pero quizá no encuentre sentido a reproducir algo estático. Si ese es su caso pasemos a agregarle algo de interactividad. Para ello podemos dibujar en cada itineración el mismo círculo en la posición donde se encuentra el mouse. Existen dos formas de realizar esto. La primera es siguiendo la lógica que descubrimos en el capítulo anterior y preguntar cual es la posición del mouse mediante `ofGetMouseX()` y `ofGetMouseY()`. La segunda manera de obtener la posición del mouse es mediante dos variables locales del `testApp` que heredan del `ofBaseApp.h` (si puede tomose el tiempo de entrar el directorio `lib/openFrameworks/app/` y explorar ese archivo de tipo header donde están definidas). Verá con facilidad que ambas variables se llaman `mouseX` y `mouseY`.

Ahora podemos comenzar comenzar de nuevo animando nuestro círculo original de la siguiente forma:

~~~~{.cpp}
	void testApp::draw(){
		ofBackground(0);
		ofSetColor(255, 0, 0);
		ofCircle(mouseX, mouseY, 30);
	}
~~~~

Si en vez de dibujar un círculo dibujamos un rectángulo notaremos que el modo de posicionar el rectángulo es distinto para uno y otro. En el primero el dibujo se ancla en el centro del círculo, mientras que en el segundo se dibuja desde la esquina superior izquierda.

~~~~{.cpp}
	void testApp::draw(){
		ofBackground(0);
		ofSetColor(255, 0, 0);
		ofRect(mouseX, mouseY, 30, 30);
	}
~~~~

Esto puede cambiarse con el método `ofSetRectMode( OF_RECTMODE_CENTER )` / `ofSetRectMode( OF_RECTMODE_CORNER )`;

Hasta ahora le hemos pasado siempre valores a nuestras funciones y métodos a la hora de dibujarlos. Pero como usted bien sabe es posible utilizar variables. Las mismas constituyen la raíz misma de la programación. La posibilidad de volver el código dinámico y un poco más abstracto. 
Aquí vamos a dar por sentado que usted ya sabe que es una variable y que tipos de ellas existe. Seguramente usted sepa que es una variable booleana `bool`, un entero `int`, una variable de tipo flotante `float` (o sea que posee valores con coma) y algunas variables más específicas como los caracteres `char` y una cadena de ellos `string`.
Volviendo a lo nuestro podríamos utilizar dos variables para actualizar la posición del círculo "paulatinamente" inaugurando el  método pensado para procesar información denominado `update()` y luego dibujar la figura en el método `draw()`. 

Aquí es de suma importancia comprender que las variables suelen "vivir" dentro del bloque de código en el cual han sido creadas. Por lo que si creamos un entero dentro de una pregunta `if` una vez pasemos el último corchete de la misma, este entero será destruido. Lo mismo pasa con los métodos. Si creáramos una variable en el método `setup()` no podríamos acceder a ella desde el `update()` o `draw()`, sencillamente por que ha sido destruida una vez que salga del método `setup()`. De igual manera si creásemos una variable en el `update()` la misma sería creada y destruida en cada itineración. 
Por esto para tener dos variables que recuerden la posición del círculo es necesario crearlas de una forma global a toda la clase `testApp`. De esta forma sería posible acceder tanto desde el `setup()`, como del `update()` y `draw()`. 
Podríamos decir que se encuentran de esta forma al mismo "nivel".
Para ello es preciso definirlas en el `testApp.h` de esta manera.

En el testApp.h:
~~~~{.cpp}
	#pragma once
	#include "ofMain.h"

	class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int	x,y;
	};
~~~~

Notemos que NO ES POSIBLE otorgarles un valor en el testApp.h. Si quisiéramos darles un valor inicial deberíamos hacerlo desde el `testApp.cpp` de la siguiente manera. 

~~~~{.cpp}
	#include "testApp.h"

	void testApp::setup(){
		x = ofGetWindowWidth()/2; 	// El círculo comienza en el centro
		y = ofGetWindowHeight()/2;	// de la ventana
	}
~~~~

En fin, ahora es tiempo de aprovechar el hecho que llevamos un registro de la posición del mouse para agregarle algún tipo de efecto al movimiento del mouse.
Un ejemplo de eso sería agregarle a la posición donde será dibujado el círculo, tan sólo una porción de la distancia en dirección la cual debería dibujarse.

Esto podríamos hacerlo restando la posición actual a la del mouse y al resultado multiplicarlo en una porción de la siguiente manera.

~~~~{.cpp}
	void testApp::update(){
		x += ( mouseX - x )*0.1;
		y += ( mouseY - y )*0.1;
	}

	void testApp::draw(){
		ofBackground(50);

		ofSetColor(200,200,124);
		ofFill();
		ofCircle( x, y, 30);
	}
~~~~

Dependiendo de la velocidad de su computadora esto puede suceder en un abrir o cerrar de ojos o en un tiempo relativamente suficiente como para brindar una efecto agradable. Cómo es imposible saber a que velocidad opera su ordenador en particular podríamos fijar el framerate en un valor por defecto con `ofSetFrameRate(30)` en el método `setup()`.

En fin, hasta aquí hemos avanzado un poco en nuestro camino hacia la interactividad. Pero quizá antes debamos aprender algunas cuestiones de la casualidad y la generatividad. Para ello y de forma introductoria a nuestra próxima unidad le proponemos al lector que investigue la función `ofRandom( float _min, float _max)`. El mismo le permitirá obtener valores aleatorios. 
El último desafío de este capítulo consiste en volver a nuestro desafío anterior de imitar un cuadro de Kandisky para remplazar las posiciones por valores aleatorios y/o relacionados con el mouse. De tal forma que cada vez que se corra el programa algunas figuras estén en distintas posiciones mientras que otras dependan de la posición del mouse.
Esta puede ser además un buen momento para explorar los otro métodos presentes en su `testApp` que responden a los eventos de teclado y mouse.

~~~~{.cpp}
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
~~~~
