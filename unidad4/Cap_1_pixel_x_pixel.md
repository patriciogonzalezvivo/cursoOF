# Introducción

El tener que procesar imágenes nos introduce de lleno en los conceptos más fríos y rústicos de C++ a la vez que nos enseña todo su potencial y plasticidad. 
Empecemos por preguntarnos qué es una imágen y cómo se guarda en la memoria. Podríamos definir a una imágen digital como: 
 
***Imagen Digital**: conjunto de puntos de color que guardan de forma consecutiva dentro de un array.*

Si bien esto no es un concepto nuevo para todos aquellos que vienen de Processing, si lo es que los pixeles en oF ( en C++ ) son en realidad 3 char consecutivos en las imágenes RGB (4 char en RGBA o uno sólo en las imágenes monocromáticas ).  

![pixels_on_oF](http://patriciogonzalezvivo.com/images/tutoriales/PixelsInOf.png)

Recordemos que los char son 8 bits que posibilitan 255 valores. De ahí el valor del pixel de acuerdo a la cantidad de canales que se utilice. El órden de los canales es en realidad una convención.
Ahora bien para obtener el array de píxeles de una imágen se suele hacer algo así:

~~~~{.cpp}
	ofImage img;
	img.loadImage(“imagen.jpg”);
	unsigned char * imgPixels = img.getPixels();
~~~~

¿Qué *& significa esto? 

#Punteros y referencias

Cuando se declara una variable, el compilador reserva un espacio de memoria para ella y asocia el nombre de ésta a la dirección de memoria desde donde comienzan los datos de esa variable. Las direcciones de memoria se suelen describir como números en hexadecimal.
Un **puntero** es una variable cuyo valor es la dirección de memoria de otra variable. Se dice que un puntero “apunta” a la variable cuyo valor se almacena a partir de la dirección de memoria que contiene el puntero. Por ejemplo, si un apuntador “p” almacena la dirección de una variable x, se dice que “p apunta a x ”. Los punteros permiten código más compacto y eficiente. Utilizándolos en forma ordenada dan gran flexibilidad a la programación. 

Empecemos por comprender qué es la dirección de una variable. La misma la podemos obtener con el operador `&`. Así veremos como luce una dirección en memoria: 

~~~~{.cpp}
	int x = 25;
	cout << "La dirección de x es: " << &x << endl;
~~~~

![arra1](http://patriciogonzalezvivo.com/images/tutoriales/array1.png)

Esto imprime un valor similar a este: `0x4fffd34`. Este valor puede variar durante cada ejecución del programa, debido a que el programa puede reservar distintos espacios de memoria durante cada ejecución.

Para declarar un puntero se especiﬁca el tipo de dato al que apunta, el operador *, y el nombre del puntero.


```<tipo de dato apuntado> *<indentiﬁcador del apuntador>``

Por ejemplo:

~~~~{.cpp}
	int *ptr1; 			// Apuntador o puntero a un dato de tipo entero (int)
	char *cad1, *cad2; 	// Dos punteros a datos de tipo caracter (char)
	float *ptr2;			// Puntero a un dato de tipo punto-flotante (float)
~~~~

Es posible asignar a un puntero direcciones de variables a través del operador de referenciación `& o direcciones almacenadas en otros punteros. 

~~~~{.cpp}
	int i = 8;
	int *p, *q;
	p = &i; 		// Se le asigna a ’p’ la dirección de ’i’
	q = p; 		// Se le asigna a ’q’ la dirección almacenada en ’p’ 
				// (la misma de ’i’)
~~~~

![arra2](http://patriciogonzalezvivo.com/images/tutoriales/array2.png)

La **desreferenciación** es la obtención del valor almacenado en el espacio de memoria donde apunta un puntero. En C y C++ esto se hace a través del operador *, aplicado al puntero que contiene la dirección del valor. 

~~~~{.cpp}
	int x = 17, y;
	int *p;
	p = &x;
	cout << "El valor de x es: " << *p << endl; 	// Imprime 17
	y = *p + 3; 						// A ’y’ se le asigna 20
~~~~

C++ además provee el operador binario `->, utilizado para obtener campos de un registro con un apuntador al mismo de una manera más fácil y legible. 

~~~~{.cpp}
	struct Data{
		char nombre[20];
		int edad;
	};

	Data d;
	Data *pd = &d;
	(*pd).edad = 23; 	// Acceso al campo ’edad’ utilizando el operador ’.’
	pd->edad = 23; 	// Acceso al campo ’edad’ utilizando el operador ’->’
~~~~

Al igual que el resto de las variables, los punteros se enlazan a tipos de datos especíﬁcos, de manera que a un apuntador sólo se le pueden asignar direcciones de variables del tipo especiﬁcado en la declaración del apuntador.

~~~~{.cpp}
	int *p1;
	float *p2;
	int x;
	p1 = &x; 	// Esto es válido
	p2 = &x; 	// Esto no es válido (el compilador genera un error)
~~~~

Ahora bien, una vez presentados los punteros y las referencias es necesario conocer la relación de estos con los arrays.

Nota: Para saber de los peligros de usar pointers y como evitarlos [leer](https://www.itescam.edu.mx/principal/sylabus/fpdb/recursos/r43599.PDF)

# Punteros & Arrays

Los [punteros](http://www.google.com/url?q=http%3A%2F%2Fprofeblog.es%2Fblog%2Falfredo%2F2008%2F05%2F19%2F%25c2%25bfpero-que-demonios-es-eso-de-los-punteros-conceptos-basicos-en-c%2F&sa=D&sntz=1&usg=AFQjCNE9YuxEfFJlMAujqmUk5gkQSbnPDQ) y los [arrays o arreglos](http://www.google.com/url?q=http%3A%2F%2Fprofeblog.es%2Fblog%2Falfredo%2F2008%2F04%2F20%2Fintroduccion-a-los-vectores-y-arrays-en-c%2F&sa=D&sntz=1&usg=AFQjCNHWjPB3h_gJgG1VEIAHb0PLN_COKw) tienen una relación muy estrecha en C y C++, ya que el nombre de un array es en realidad un puntero al primer elemento de ese array. 

~~~~{.cpp}
	int x[5]; 		// es similar a decir int * x;
	cout << “Decir ” << &x[0] << “ es igual a ” << x << endl;  
~~~~

![arra3](http://patriciogonzalezvivo.com/images/tutoriales/array3.png)

La dirección del elemento i-ésimo se puede expresar como `&x[i]` o como `(x+i)`.
En este caso, la expresión (x+i) no es una operación aritmética convencional, sino una operación con punteros (que se denomina aritmética de punteros).
Si `&x[i]` y `(x+i)` representan la dirección del i-ésimo elemento de x, podemos decir que `x[i]` y `*(x+i)` representan el contenido de esa dirección, es decir, el valor del i-ésimo elemento de x. 

De esta manera si quisiéramos movernos hacia adelante en el array bastaría con sumarle uno en cada vuelta.

![arra4](http://patriciogonzalezvivo.com/images/tutoriales/array4.png)

Si observamos bien todo este tiempo al usar arrays escribiendo `x[...]` estábamos especificando cuantos espacios en memoria sumarle al puntero x. Ya sea 0 `(x[0] == *(x+0) )`, 1 `(x[1] == *(x+1))`, 2 `( x[2] == *(x + 2) )` . Por lo que hemos estado usando punteros desde el comienzo.

Para quien le interese, a sabiendas de esta relación entre punteros y arrays es posible crear arrays dinámicos utilizando el comando new para ellos pueden [leer](http://chuwiki.chuidiang.org/index.php?title=Arrays_en_C)


Volviendo a lo nuestro hemos visto que los arrays, por lo tanto, pueden utilizarse con índices o con punteros. Al programar suele resultar mucho más cómodo utilizar la forma x[i] para acceder al elemento i-ésimo de un array. Sin embargo, hay que tener en cuenta que la forma `*(x+i)` es mucho más eficiente que x[i], por lo que suele preferirse cuando la velocidad del ejecución es un factor determinante.
Es por eso que a la hora de manejar enormes cantidades de pixeles en una imagen se suele utilizar aritmética de punteros. Volviendo al tema que nos convoca, cuando decimos: 

~~~~{.cpp}
	ofImage img;
	img.loadImage(“imagen.jpg”);
	unsigned char * imgPixels = img.getPixels();
~~~~

Lo que le estamos pidiendo no son los millones de pixeles que contiene una imagen. Sino tan sólo la dirección al primero de ellos : )

¿Pero que significa `unsigned`? significa que el estilo de la variable en cuestión ( `char`, que almacena tán sólo un byte de información) no poseerá sígno ( osea no contendrá valores negativos ). Por lo que los valores que contengan en vez de ir entre `-128` a `127`, irán de `0` a `255`. 
Ahora todo tiene sentido! no?
Estamos tomando el comienzo de un arrays de char sin sígno. Los cuales representan cada uno de ellos un canal de color siguiendo una estructura previamente pautada.

Pero.... ¿cómo sabemos cuando termina? y ¿cómo sabemos qué formato tiene?
Aquí radica lo tedioso de este procedimiento en oF ( y en C++ en general ) ya que tenemos que ser cuidadosos y obtener toda esa información a priori. De hecho las clases que maneja imágenes en oF suelen pedir primero este tipo de información para saber los parámetros con los que se trabajará ( y así también reservar el espacion en memora). La función común que realiza esta acción es `.allocate( int w, int h, ofImageType type).  

~~~~{.cpp}
	ofImage img;
	img.allocate(width,height, OF_IMAGE_COLOR);
~~~~

La cual como vemos pregunta por un width, un height y un tipo de image ( las opciones de este último son `OF_IMAGE_GRAYSCALE`, `OF_IMAGE_COLOR` o `OF_IMAGE_COLOR_ALPHA` que determina si ordenará los píxeles en un sólo canal, en tres osea RGB o en cuatro RGBA ). 

A sabiendas de esto se puede recorrer una imagen de punta a punta usando al como:

~~~~{.cpp}
	int largo = img.getWith(); 	// Para obtener el largo en caso de no saberlo
	int alto = img.getHeight(); 	// Para saber el alto
	int nCanales = 3; 		//  Porque ordenaremos los pixeles en en RGB
	int totalPixeles = largo * alto * nCanales; // Calculamos la cantidad total 
	unsigned char * pixeles = img.getPixels();
	for (int i = 0; i < totalPixeles; i++){
		pixeles[i] = 255 - pixeles[i]; 	// invertimos el valor de cada uno
	}
~~~~

Para terminar de modificar la imagen necesitamos luego volver a cargarlos con la función `.setFromPixels(PixelType *pixels, int w   int h,  ofImageType type, bool bOrderIsRGB)`. Algo así como:

~~~~{.cpp}
	img.setFromPixels(pixeles, width, height, OF_IMAGE_COLOR);
~~~~

Se lo que están pensando: Acaso no se trataba de un puntero a un array ¿Porqué hay qué tendría que volver a cargar los pixeles? Tienen toda la razón. El tema aquí es que la clase ofImage en realidad lo que contiene es una textura openGL. Acceder a las texturas en memoria no es tan sencillo como algún otro dato en el CPU. Es por esto que hay que volver a parle la dirección del array de pixeles para que las suba openGL a memoria gráfica.
Para comprender esto en mayor profundidad sugiero leer los archivos `ofImage.h` y `ofImage.cpp` 
en el directorio `libs/openFrameworks/graphics`. Donde se puede apreciar como termina cargando todo en un ofTexture mediante la función `.loadData(void * data, int w, int h, int glFormat)

En fin, a lo nuestro. Para poner todo esto en práctica que mejor que algún ejercicio de al estilo Daniel Shiffman. La tarea es itinerar por cada pixel dibujando un circulo de color por cada uno de ellos.  Una fórmula para recorrer un array de pixeles con tres canales es:

~~~~{.cpp}
	ofColor color[width][height]; 	// Usamos un array bidimensional o matriz

	for( int i = 0; i < width; i++ ){
		for( int j = 0; j < height; j++ ){
			int p = j * width + i;

			color[i][j].r = filmPixels[p * 3 + 0];
			color[i][j].g = filmPixels[p * 3 + 1];
			color[i][j].b = filmPixels[p * 3 + 2];
		}
	}
~~~~

El resto queda en manos suyas. 

[Otras fuentes](http://computer.howstuffworks.com/c23.htm)


# Video

La velocidad y poder de trabajar imágenes a este nivel se aprecia cuando lo hacemos con gran cantidad de ellas por segundo. Este es el caso de los videos. Vamos a abrir el ejemplo `movieGrabberExample` del `apps/examples`. 

Notemos que podemos comprender casi todo lo que esta sucediendo alli. ofVideoGrabber funciona bastante como ofImage con la diferencia que en cada paso por el update() hay que buscar un nuevo frame de la camara con la función `.grabFrame()` por otro lado estamos chequeando si el frame es nuevo o no con `.isFrameNew()` para no andar perdiendo tiempo haciendo las cosas más de una vez.

Quizá hay dos cosas que sean novedosas aquí. La primera es:

~~~~{.cpp}
	videoInverted = new unsigned char[camWidth*camHeight*3];
~~~~

Si nos fijamos en el .h estamos declarando un puntero de unsigned char´s llamado videoInverted. Como vimos antes los punteros son potencialmente arrays de un tamaño indeterminado o por lo menos no explicitado. Si nosotros quiciéramos determinar el tamaño de ese array ( lo que se suele denominar construcción de un array dinámico ) podríamos apuntar ese puntero a un lugar en memoria donde creemos la cantidad deseada de espacios. Eso es exactamente lo que hace `new` apunta un pointer a un lugar en memoria donde a creado una instancia de un objeto. En este caso de un conjunto de chars sin signo y con un determinado tamaño ( justo el de pixeles necesarios para una imagen RGB producida por la cámara ).

Otra que podría desconcertarnos de buenas a primeras es el GL_RGB. Esta es una propiedad de las texturas. Puntualmente un tipo openGL. Fijémonos que en este ejemplo no usan imágenes sino que directamente se manejan con texturas. 

Las texturas openGL son la puerta a la autopista del uso de la placa GPU. Allí radica el poder más grande de procesamiento de imágenes y cálculos complejos de vectores que sus computadoras pueden brindarle.  