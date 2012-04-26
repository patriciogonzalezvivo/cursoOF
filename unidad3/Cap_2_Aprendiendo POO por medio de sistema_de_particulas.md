# Aproximación amable a la programación orientada a objetos
##### por [Patricio Gonzalez Vivo](http://www.patriciogonzalezvivo.com)

## Introducción: ¿Qué es la Programación Orientada a Objetos?

La [programación Orientada a Objetos (POO)](http://es.wikipedia.org/wiki/Programaci%C3%B3n_orientada_a_objetos) es una forma especial de programar, más cercana a como expresaríamos las cosas en la vida real que otros tipos de programación.
Con la POO tenemos que aprender a pensar las cosas de una manera distinta, para escribir nuestros programas en términos de objetos, propiedades, métodos y otras cosas que veremos rápidamente para aclarar conceptos y dar una pequeña base que permita soltarnos un poco con este tipo de programación.

#### Cómo se piensa en objetos

Pensar en términos de objetos es muy parecido a cómo lo haríamos en la vida real. Por ejemplo vamos a pensar en un coche para tratar de modelizarlo en un esquema de POO. Diríamos que el coche es el elemento principal que tiene una serie de características, como podrían ser el color, el modelo o la marca. Además tiene una serie de funcionalidades asociadas, como pueden ser ponerse en marcha, parar o aparcar.

Pues en un esquema POO el coche sería el objeto, las propiedades serían las características como el color o el modelo y los métodos serían las funcionalidades asociadas como ponerse en marcha o parar.

Por poner otro ejemplo vamos a ver cómo modelizaríamos en un esquema POO una fracción, es decir, esa estructura matemática que tiene un numerador y un denominador que divide al numerador, por ejemplo 3/2.

La fracción será el objeto y tendrá dos propiedades, el numerador y el denominador. Luego podría tener varios métodos como simplificarse, sumarse con otra fracción o número, restarse con otra fracción, etc.

Estos objetos se podrán utilizar en los programas, por ejemplo en un programa de matemáticas harás uso de objetos fracción y en un programa que gestione un taller de coches utilizarás objetos coche. Los programas Orientados a objetos utilizan muchos objetos para realizar las acciones que se desean realizar y ellos mismos también son objetos. Es decir, el taller de coches será un objeto que utilizará objetos coche, herramienta, mecánico, recambios, etc.

#### Clases en POO

Las clases son declaraciones de objetos, también se podrían definir como abstracciones de objetos. Esto quiere decir que la definición de un objeto es la clase. Cuando programamos un objeto y definimos sus características y funcionalidades en realidad lo que estamos haciendo es programar una clase. En los ejemplos anteriores en realidad hablábamos de las clases coche o fracción porque sólo estuvimos definiendo, aunque por encima, sus formas.

#### Propiedades en clases

Las propiedades o atributos son las características de los objetos. Cuando definimos una propiedad normalmente especificamos su nombre y su tipo. Nos podemos hacer a la idea de que las propiedades son algo así como variables donde almacenamos datos relacionados con los objetos.

#### Métodos en las clases

Son las funcionalidades asociadas a los objetos. Cuando estamos programando las clases las llamamos métodos. Los métodos son como funciones que están asociadas a un objeto.

## 1er paso: Armar una clase

Si se han realizando los desafíos de los pasados tutoriales probablemente hallan terminado con un montón de código repetido. Por suerte la repetición es una de las especialidades de las computadoras. 
Para ello vamos a empezar a jugar con algunos conceptos de la programación orientada a objetos para facilitar las cosas, hacer el código más legible y menos repetitivo.

#### Pasemos al diseño de una Pelota

Imaginemos una pelota. Se trata de un objeto redondo que tienen algunas propiedades como la posición y el color, también realiza acciones (métodos) como por ejemplo moverse. Todos estos elementos abstractos se puede imaginar como:

Pelota:

	- posición (propiedad)

	- color (propiedad)

	- mover (función o método)

Esto es exactamente lo que termina siendo archivo ".h", una lista de cosas que constituyen un objeto. Así que vamos a añadir dos nuevos archivos a nuestro proyecto (esto depende de la IDE que está utilizando), uno que va a ser un archivo ".h" llamado `Pelota.h` (donde vamos a definir los elementos que componen nuestra pelota) y el otro uno ".cpp" llamado `Pelota.cpp` ( donde estarán detallados los procedimientos que se realizan en cada método).

![newFile](http://www.patriciogonzalezvivo.com/images/tutoriales/newFile.png)

Comencemos con Pelota.h

~~~~{.cpp}
	#ifndef PELOTA	// recordemos que esto previene declarar la misma clase
	#define	PELOTA	// dos veces

	#include "ofMain.h"	// Aqui agregamos los métodos y clases de oF

	class Pelota {
	public:			// Todos los métodos aquí son públicos por los que cualquiera puede
			// verlos y acceder a ellos.
	
		Pelota();	// Constructor indispensable en toda clase
	
		void moverHacia(int _x, int _y);
		void dibujar();
	
		ofColor	color;
		int x;
		int y;
	};
	#endif
~~~~

En el Pelota.cpp:

~~~~{.cpp}
	#include "Pelota.h"		// Referencia al header donde los siguientes métodos están 
							//declarados
	Pelota::Pelota(){
		x = ofRandom( ofGetWindowWidth() ); 
		y = ofRandom( ofGetWindowHeight() ); 
		color.set( ofRandom(255), ofRandom(255), ofRandom(255));
	}

	void Pelota::moverHacia(int _x, int _y){
		// vamos a definirlo más adelante
	}

	void Pelota::dibujar(){
		ofSetColor(color);
		ofFill()
		ofCircle(x, y, 30);
	}
~~~~

Felicidades, acaba de crear su propia clase! Hay un par de cosas nuevas que están pasando aquí. Las primeras 2 líneas (`# ifndef ..` evitan que el compilador lea dos veces una misma clase, desatando toda clase de potenciales errores. Esta es una práctica estándar en C++ y es probable que desee dejar las cosas como son. Usted está básicamente diciendo: "Oye compilador, no pasases por aquí dos veces, y para compilar tendrás que usar el archivo de cabecera ofMain.h. ". Incluir `ofMain.h` le dará acceso a todos los métodos y objetos de openFrameworks.

Para crear un objeto a partir de esta clase necesita llamar al constructor de la clase. El constructor de `Pelota()` es la encargada de formatear ese espacio en memoria para que puda guardar la información que contiene. 

IMPORTANTE: Echa un vistazo a la `};` del final de la clase. Esto es super importante! Sin ella, usted recibirá molestos errores que son difíciles de rastrear. Ese punto y coma es el responsable de cerrar todo correctamente.

Ahora tan sólo nos falta agregar este objeto a nuestro `testApp.h` escribiendo `#include "Pelota.h"` al comienzo y luegro inicializando un objeto `Pelota` llamado "p". Esto crea una instancia de nuestro objeto pelota. Podemos crear cuantas instancias queramos. 

~~~~{.cpp}
	#pragma once

	#include "ofMain.h"
	#include "Pelota.h"		// es importante agregar el header donde se declara el objeto

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
		
		Pelota	p;
	};
~~~~

Para probarlo y usarlo basta con escribir en nuestros `testApp.cpp` lo siguiente:

~~~~{.cpp}
	#include "testApp.h"

	void testApp::setup(){
	}

	void testApp::update(){
		p.x += ( mouseX - theBall.x )*0.1;    
		p.y += ( mouseY - theBall.y )*0.1;
	}

	void testApp::draw(){
		ofBackground(0);
		p.dibujar();
	}
~~~~

Así que ahora tenemos un objetivo que de forma automática se crea con algunos valores aleatorios, pero si queremos podemos acceder a la información en su interior mediante el uso de `objeto.propiedad` o `objeto.método()`.
Esto significa que cada vez que queremos un nuevo balón que sólo para crear y dibujar eso! ¿No es impresionante?

Una última cosa para hablar de cómo se puede pasar algunos parámetros a un método de objeto. Si miramos el código dentro del `TestApp::update()` vemos que actualiza `x` y `y` mediante el uso del `.`, o sea entra dentro de estas variables para setear su contenido a la nueva posición. Eso no es malo, pero por lo general se suelen utilizar métodos que ayuden a hacer las cosas más intuitivas y autónomas. Es por eso que vamos a incorporar esas lineas dentro de nuestro objeto. Más precisamente dentro del método `.moverHacia(int _x, int _y);`.

En el `Pelota.cpp` pondremos

~~~~{.cpp}
	void Ball::moverHacia(int _xDestino, int _yDestino){
		x += ( _xDestino - x )*0.1;
		y += ( _yDestino - y )*0.1;
	}
~~~~

Mientras que en nuestro `testApp.cpp` podemos cambiar esas lineas por:

~~~~{.cpp}
	void testApp::update(){
    		theBall.moverHacia(mouseX,mouseY);
	}
~~~~

Genial de esta forma vemos como los objetos terminan siendo unidades lógicas las cuales se diseñan teniendo en cuenta al usuario. Esto hará nuestros código más entendible, claro y por ende más eficiente.


## 2do paso: aplicarle cierta física

Desde la versión 007 oF cuenta con clases para realizar cálculos vectoriales (de dos, tres o cuatro dimensiones) de forma sencilla. Hechándole una mirada al directorio openFrameworks/libs/openframeworks/math podemos encontrar que también existen clases nativas para realizar calculos de matrices y quaterniones.
En este paso vamos a hacer uso de esas clases reemplazando los int x e y por un vector de dos dimensiones con valores de punto flotante ( número con coma ) que guarde la posición de nuestro objeto, para eso nos vamos a valer de la clase ofVec2f() definida en ofVec2f.h
Además agregaremos dos vectores más para calcular la aceleración y la velocidad.
Así mismo crearemos dos variables más. Una contendrá el tamaño del objeto, mientras que la última será una variable de tipo ofColor() para contener el color del mismo. Este tipo de variables nos permite realizar operaciones de color a la vez que converciones. Vale la pena echarle una mirada a libs/openFrameworks/types/ofColor.h para comprender cómo se las declara y cuántas funciones útiles posee.

En la rutina de update haremos que la aceleración actualice la velocidad. La cual dependerá de la resistencia o densidad del espacio, la cual moverá la posición del objeto. 

Para que nuestro objeto se mueva en vez de pasarle una posición le pasaremos un vector de fuerza hacia donde debe moverse.

Una vez hecho todo esto nuestra clase Pelota.h debería lucir algo así:

~~~~{.cpp}
	#ifndef PELOTA
	#define PELOTA
	#include "ofMain.h"

	class Pelota {
	public:
		Pelota();
	
		void agregarFuerza(ofVec2f fuerza);	// aquí le pasamos la fuerza
	
		void update();	
		void draw();
	
		ofColor	color;	
		ofVec2f 	pos, vel, acc;

		int	tamanio;
	};
	#endif
~~~~

Mientras que el Pelota.cpp: 

~~~~{.cpp}
	#include "Pelota.h"

	Pelota::Pelota(){
		tamanio = 30;
		color.set(255,0,0);
	
		pos.set( ofGetWindowWidth()*0.5 , 	// es un buen hábito
				ofGetWindowHeight()*0.5 );	// usar más matemáticas,
										// sobretodo normales para
										// hacer ajustes
		vel.set(0,0);
		acc.set(0,0);
	}

	void Pelota::agregarFuerza(ofVec2f fuerza){
		acc += fuerza;
	}

	void Pelota::update(){
		vel += acc;		// Suma la aceleración a la velocidad
		vel *= 0.03;	// Le agregamos algo de resistencia o densidad
		pos += vel;		// Suma la velocidad a la posición
		acc *= 0;		// Vuelve a cero la aceleración
	}

	void Pelota::draw(){
		ofSetColor(color);
		ofCircle(pos.x, pos.y, tamanio);
	}
~~~~

Mientras que en el testApp.cpp ahora actualizamos la posición de la siguiente manera:

~~~~{.cpp}
	void testApp::update(){
		ofVec2f destino, haciaDestino;

		destino.set(mouseX,mouseY);
		haciaDestino = destino - p.pos;
	
		p.agregarFuerza(haciaDestino);
		p.update();
	}
~~~~

Al compilar podemos ver como la pelota es atraída por el cursor. Sin embargo esto dista mucho a comportarse como una pelota.
## 3er paso: un poco de onda

Como parte de algunas funciones matemáticas incorporadas al framework podemos agregarle valores random para hacer las cosas un poco más interesante. Para esto a la hora de inicializar utilizaremos la clase ofRandom de dos maneras. Un con un sólo parámetro explicitando el máximo y otra por medio de dos especificando el mínimo y máximo de los valores random que devuelva.
Para este ejemplo le agregaremos una función más a nuestra clase Pelota para saber cuando ha salido de la pantalla de tal forma que podamos volverla a crear. También dejaremos que las pelotas caigan por gravedad.

Pelota.h:

~~~~{.cpp}
	#ifndef PELOTA
	#define	PELOTA
	#include "ofMain.h"

	class Pelota {
	public:
		Pelota();
	
		void agregarFuerza(ofVec2f fuerza);
		bool pasoElBorde();	
		void update();
		void draw();
	
		ofColor	color;	
		ofVec2f pos, vel, acc;
	
		int	tamanio;
	};
	#endif
~~~~

Pelota.cpp:

~~~~{.cpp}
	#include "Pelota.h"

	Pelota::Pelota(){
		tamanio = ofRandom(20);
		color.set(ofRandom(255),ofRandom(255),ofRandom(255));
	
		pos.set( ofGetWindowWidth()*0.5 , ofGetWindowHeight()*0.5 );
		vel.set( ofRandom(-1,1),ofRandom(-1,1));
		acc.set( ofRandom(-1,1),ofRandom(-1,1));
	}

	void Pelota::agregarFuerza(ofVec2f fuerza){
		acc += fuerza;
	}

	void Pelota::update(){
		vel += acc;	// Suma la aceleración a la velocidad
		pos += vel;	// Suma la velocidad a la posición
		acc *= 0;	// Vuelve a cero la aceleración
	}

	void Pelota::draw(){
		ofSetColor(color);
		ofCircle(pos.x, pos.y, tamanio);
	}

	bool Pelota::pasoElBorde(){
		bool rta = false;	
		if ( pos.x < 0 || pos.y < 0 || pos.x > ofGetWindowWidth() || pos.y > ofGetWindowHeight())
			rta = true;
	
		return rta;
	}
~~~~

en el update() del testApp.cpp:

~~~~{.cpp}
	void testApp::update(){
		p.agregarFuerza(ofVec2f(0,0.0098));
		p.update();
	
		if (p.pasoElBorde()){
			p = Pelota();			// las pelotas se vuelven a
			p.pos.set(mouseX,mouseY);	// crear donde esta el cursor
		}
	}
~~~~

## 4to paso: multiplicarlo

En cuanto sistema de partículas se refiere, más es mejor. Así que hagamos un array de estos objetos que estamos usando. Los arrays en C++ son estáticos. Eso quiere decir que una vez creados con cierto tamaño no pueden modificarse, por lo menos en principio.
Vamos a utilizar el pre-compilador para crear una variable constante donde guardar el número de objetos en nuestro array. Esto nos ayudará luego a itinerar por cada uno de ellos fácilmente. Pudiendo cambiar la cantidad total de forma sencilla.

En el testApp.h:

~~~~{.cpp}
	#pragma once

	#include "ofMain.h"
	#include "Pelota.h"

	#define TOTAL 100		// Esta bueno explorar hasta que número puede llegar

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
		
			Pelota	p[TOTAL];
	};
~~~~

En el testApp.cpp:

~~~~{.cpp}
	#include "testApp.h"

	void testApp::setup(){
		for(int i = 0; i < TOTAL; i++){
			p[i].pos.set(ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()));
		}
	}

	void testApp::update(){
		for(int i = 0; i < TOTAL; i++){
			p[i].agregarFuerza(ofVec2f(0,0.0098));
			p[i].update();
	
			if (p[i].pasoElBorde()){
				p[i] = Pelota();
				p[i].pos.set(mouseX,mouseY);
			}
		}
	}

	void testApp::draw(){
		ofBackground(0);
	
		for(int i = 0; i < TOTAL; i++){
			p[i].draw();
		}
	}
~~~~

## 5to paso: buscando sutilezas

Otra forma de jugar con valores random es utilizar ofNoise. Este método devuelve valores más orgánicos. Una de las variantes de la misma clases es ofSignedNoise().
En este paso intentaremos darle movimientos y efectos más interesantes a nuestra clase. Para eso le agregaremos un tiempo de vida a nuestra Pelota. Al mismo tiempo que estaremos atentos a la cantidad de itineraciones del loop principial del testApp. Si su procesador es rápido quizá hayan notado que por momentos las partículas se movían sumamente rápido y por otros momentos se enlentecían. Eso era causado porque no habíamos fijado la cantidad de frames por segundos en las que nuestro loop principal trabaja. Lo fijaremos en 60 con el método ofSetFramerate(60); . También habilitaremos el uso de colores con canal alpha mediante ofEnableAlphaBlending() 
A nuestra clase le agregarémos un par de funciones y variables de tal modo que queden así el header Pelota.h:

~~~~{.cpp}
	#ifndef PELOTA
	#define	PELOTA

	#include "ofMain.h"

	class Pelota {
	public:
		Pelota();
	
		void agregarFuerza(ofVec2f fuerza);
		void agregarNoise(float _angulo, float _turbulencia);	//agregará un movimiento aleatorio suave
		
		void agregarAlphaFade(bool _fadeOut);	// hará que se desvanezcan
		void agregarScaleFade(bool _melt);		// hará que se achiquen
	
		bool pasoElBorde();
		bool estaViva();						// esta función chequea si esta viva
		
		void update(float _limiteDeVelocidad);	// el update quitará vida y limitará el movimiento

		void draw();
	
		ofColor	color;
	
		ofVec2f pos, vel, acc;
		float alphaF, escalaF;
		int vida,vidaInicial, tamanio;
	};
	#endif
~~~~


En el source Pelota.cpp:

~~~~{.cpp}
	#include "Pelota.h"

	Pelota::Pelota(){
		tamanio = ofRandom(20);
		color.set(ofRandom(255),ofRandom(255),ofRandom(255));
	
		pos.set( ofGetWindowWidth()*0.5 , ofGetWindowHeight()*0.5 );
		vel.set( ofRandom(-1,1),ofRandom(-1,1));
		acc.set( ofRandom(-1,1),ofRandom(-1,1));
	
		alphaF	= 1;
		escalaF = 1;
	
		vida = vidaInicial = ofRandom(200,1000);
	}

	void Pelota::update(float _limiteDeVelocidad = 0.0){
		vel += acc;	// Suma la aceleración a la velocidad
	
		if (_limiteDeVelocidad != 0)
			vel.limit(_limiteDeVelocidad);			
		pos += vel;	// Suma la velocidad a la posición
		acc *= 0;	// Vuelve a cero la aceleración
	
		vida--;
	}

	void Pelota::agregarFuerza(ofVec2f fuerza){
		acc += fuerza;
	}

	void Pelota::agregarNoise(float _angulo, float _turbulencia){
		float angulo = ofSignedNoise(pos.x * 0.005f, pos.y *0.005f) * angulo;
		ofVec2f noiseVector( cos( angulo ), sin( angulo ) );
		acc += noiseVector * _turbulencia * (1.0 - ofNormalize(vida, 0, vidaInicial));
	}

	void Pelota::agregarAlphaFade(bool _fadeOut = true){
		if (_fadeOut)
			alphaF = 1.0f-ofNormalize(vida, 0,vidaInicial);
		else 
			alphaF = ofNormalize(vida, 0,vidaInicial);
	}

	void Pelota::agregarScaleFade(bool _melt = true){
		if (_melt)
			escalaF = 1.0f-ofNormalize(vida, 0,vidaInicial);
		else 
			escalaF = ofNormalize(vida, 0,vidaInicial);
	}

	void Pelota::draw(){
		ofSetColor(color, color.a * alphaF );
		ofCircle(pos.x, pos.y, tamanio * escalaF );
	}

	bool Pelota::pasoElBorde(){
		bool rta = false;
	
		if ( pos.x < 0 || pos.y < 0 || pos.x > ofGetWindowWidth() || pos.y > ofGetWindowHeight())
			rta = true
	
		return rta;
	}

	bool Pelota::estaViva(){
		bool rta = true;
	
		if (vida <= 0)
			rta = false;
	
		return rta;
	}
~~~~

En el testApp.h hace falta agregar un integer llamado tiempo, mientras que en el testApp.cpp:

~~~~{.cpp}
	void testApp::setup(){
		ofEnableAlphaBlending();
		ofSetFrameRate(60);
	
		for(int i = 0; i < TOTAL; i++)
			p[i].pos.set( ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));
	
		tiempo = 0;
	}


	void testApp::update(){
		for(int i = 0; i < TOTAL; i++){
			p[i].agregarFuerza(ofVec2f(0,0.00098));
			p[i].agregarNoise(2.7, 0.76);
			p[i].agregarAlphaFade(false);
			p[i].agregarScaleFade(false);
			p[i].update(1);
	
	
			if (p[i].pasoElBorde() || !p[i].estaViva() ){
				p[i] = Pelota();
				p[i].color.setHue( (tiempo%3000)*0.1 );
				p[i].pos.set(mouseX,mouseY);
			}
		}
	
		tiempo++;
	}


	void testApp::draw(){
		ofBackground(0);
	
		for(int i = 0; i < TOTAL; i++)
			p[i].draw();
	}
~~~~

## 6to paso: variedad (herencia y polimorfismo)

Unas de las novedades que C++ trajo al mondo de la programación allá a mediados de los ‘80 fue el concepto de programación orientada a objetos. Hasta aquí hemos estado trabajando con el objeto Pelota. Sin embargo, queda muchísimo del potencial de la programación orientada a objetos por descubrir.

Una de sus principales características se denomina herencia. Podemos utilizar la clase Pelota como padre de otras. Estas heredarán todas las variables y funciones públicas que esta tengan.

Por ejemplo:
~~~~{.cpp}

	#ifndef PELOTITA
	#define PELOTITA

	#include "ofMain.h"
	#include “Pelota.h”	// Es importante incorporar el .h a la clase padre

	class Pelotita : public Pelota{
	public:
		Pelotita();
		void draw();
	};

	#endif
~~~~

En este caso la clase Pelotita hereda todas las características de Pelota sin embargo podremos definir un estilo propio de modo de dibujarla a esto se denomina polimorfismo . Una cuestión muy útil de todo esto es que en un array de Pelotas podríamos insertar Pelotitas . De tal forma que en un sólo for podríamos itinerar por Pelotas y Pelotitas actualizándolas o dibujándolas a todas.   


9no paso: cargando Imágenes
El último paso de este recorrido tiene que ver con remplazar nuestro humilde círculo coloreado por algo más interesante. Para eso vamos a bajar una imagen ( http://github.com/patriciogonzalezvivo/OF05/blob/master/bin/data/bola.png ) copiarla al directorio bin/data de nuestro proyecto y levantarla desde nuestra App.
El plan es el siguiente, en vez de generar 100 copias, una por cada pelota, vamos a cargar en memoria una sólo de estas imágenes y en cada objeto le vamos a pedir que la “dibuje” en su respectivo color y tamaño.
Para levantar la imagen tan sólo necesitamos crear una variable ofImage() y cargar el contenido con el método .loadImage(string _archivo)
A cada objeto vamos a pasarle la dirección en memoria de esta imagen, utilizando el comando & a un la función de cada objeto draw(). Esta va estar esperando un puntero. Osea va a estar mirando hacia el contenido de esa dirección la cual nos pasa. Así va a quedar la función draw de la clase Pelota:

~~~~{.cpp}
	void Pelota::draw(ofImage* _imagen){ // espera un puntero de tipo ofImage
		ofSetColor(color, color.a * alphaF );
		_imagen->draw(	pos.x - _imagen->getWidth() * escalaF, 
						pos.y - _imagen->getHeight() * escalaF, 
			   			_imagen->getWidth() * escalaF, 
			   			_imagen->getHeight() * escalaF);
	}
~~~~

Podemos ver que el objeto se comporta como debería, con la única diferencia que en vez de utilizar puntos ( “.” ) estamos usando flechas ( “->” ).  

Desde la testApp.cpp tan sólo debemos:

~~~~{.cpp}
	void testApp::draw(){
		ofBackground(0);
	
		for(int i = 0; i < TOTAL; i++){
			p[i].draw(&bola);	// Le pasa la dirección en memoria
		}
	}
~~~~

Punteros es un tema importante en C++ el cual volveremos a explicar con mayor detalle en siguiente tutorial. Hasta entonces recomendamos echarle una leida a los siguientes links: http://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Punteros
http://es.scribd.com/doc/19125272/POO-Punteros-en-C
http://elvex.ugr.es/decsai/c/apuntes/punteros.pdf

Tarea:

- Transformar esta clase en una sub-clase que herede de Pelota 

- Investigar sobre arrays dinámicos y aplicar el tipo <vector> ( parte la librería estandar de c++ ) a nuestro sistema de partículas.
[http://ronnyml.wordpress.com/2009/07/04/vectores-matrices-y-punteros-en-c/](http://ronnyml.wordpress.com/2009/07/04/vectores-matrices-y-punteros-en-c/)
[http://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Biblioteca_Est%C3%A1ndar_de_Plantillas/Vectores](http://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Biblioteca_Est%C3%A1ndar_de_Plantillas/Vectores)

- Investigar sobre las diferencia entre vecto y list >. 
[http://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Librer%C3%ADa_Est%C3%A1ndar_de_Plantillas/Listas](http://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Librer%C3%ADa_Est%C3%A1ndar_de_Plantillas/Listas)