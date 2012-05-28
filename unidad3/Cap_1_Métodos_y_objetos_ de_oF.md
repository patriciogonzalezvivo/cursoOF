# Abriendo la caja de herramientas de oF
##### por [Patricio Gonzalez Vivo](http://www.patriciogonzalezvivo.com)

OpenFrameworks cuenta con algunas herramientas que nos van ayudar enormemente a la hora de hacer aplicaciones. Las mismas simplifican funciones matemáticas, que si sabemos utilizarlas, podremos resolver cuestiones complejas de forma elegante y eficiente.

## Objetos

### oPoint
En el [último capítulo de la unidad anterior](https://github.com/patriciogonzalezvivo/cursoOF/blob/master/unidad2/Cap_4_Primeros_pasos.md) estuvimos moviendo un círculo suavemente hacia la posición del mouse utilizando:

~~~~{.cpp}
	x += ( mouseX - x )*0.1;
	y += ( mouseY - y )*0.1;
~~~~

Si tuviéramos varios círculos que mover tendríamos rápidamente cientos de pares de variables haciendo cálculos vectoriales similares a este.

Es por eso que una buena idea de la comunidad oF fue armar un objeto que maneje posiciones y se encargue de lidiar con los valores en `x`, `y` y `z`. Es por eso que cada uno de estos objetos contienen tres `float` para cada uno de ellos, junto algunas funciones útiles. Este tipo de objetos se llama `ofPoint` y se van a comportar bastante similar a cualquier otra variable.

Se declaran de la siguiente manera:

~~~~{.cpp}
	ofPoint pos;
~~~~

Una vez creados es posible acceder a los valores de `x`, `y`y `z` que contiene de una manera similar a como si fueran archivos dentro de un directorio. Sin embargo, en vez de utilizar `\` accederemos a ellos usando un punto `.` . Por ejemplo:

~~~~{.cpp}
	pos.x = 500;
	pos.y = 250;
~~~~

Otra manera de pasarle estos valores podría ser utilizando un método perteneciente al objeto `ofPoint`: 
 
~~~~{.cpp}
	pos.set(500,250);
~~~~

Si exploramos bien con la función de auto-completar de nuestro IDE, notaremos que existe varios métodos útiles junto con operadores matemáticos y lógicos. Por tanto es posible sumar, multiplicar, dividir o restar dos `ofPoint`, tanto como compararlos de forma sencilla. 

De esta forma podríamos optimizar en una sola línea nuestro función para acercar progresivamente el mouse, de la siguiente manera.

~~~~{.cpp}
	pos += ( ofPoint(mouseX,mouseY) - pos ) * 0.1;
~~~~

Es más! podríamos utilizar una función nativa de `ofPoint` que hace exactamente esto mismo!

~~~~{.cpp}
	pos.interpolate( ofPoint(mouseX,mouseY) , * 0.1);
~~~~
 
Fantástico no? Esto nos va a hacer de mucha ayuda en nuestro siguiente capítulo donde al círculo le otorgaremos velocidad, aceleración. Los cálculos vectoriales necesarios serán hechos de forma sencilla e indolora por el objeto `ofPoint` mientras nosotros podemos concentrarnos en el diseño del comportamiento.

La frutilla del postre consiste en que varias funciones de oF aceptan como parámetro a `ofPoint` para substituir el uso de dos otre variables. Como por ejemplo:

~~~~{.cpp}
	ofCircle(pos, 50);
~~~~


### oFColor
De la misma manera que `ofPoint` se encarga de manejar una posición en el espacio. `ofColor` se encargará de los colores.

Una vez creado el objeto de color podemos utilizar operadores matemáticos, lógicos o bien alguno de sus métodos. Si exploramos los mismos encontraremos que es posible alternar entre sistema RGB a HSB.

Al igual que existen funciones que toman `ofPoint` como parámetros existen varias funciones que toman `ofColor`. Este es el caso por ejemplo de:

~~~~{.cpp}
	ofColor	negro;
	ofColor	azul;

	negro.set(0,0,0);
	azul.set(0,0,255);

	ofBackground(negro);

	ofSetColor(azul);
	ofCircle(pos,50);
~~~~

## [Funciones Matemáticas](http://www.openframeworks.cc/documentation/math/ofMath.html)
Si bien ya hemos utilizado algunas funciones como `ofBackground()`, `ofGetWindowWidth()` en esta sección nos vamos a detener en aquellas que realizan [operaciones matemáticas](http://www.openframeworks.cc/documentation/math/ofMath.html)

### ofRandom()

### ofNoise()

### ofMap()

### ofClamp()

### ofToString()

###Nativos de C++ (STL)
sin, cos, atan, sqrt, abs

