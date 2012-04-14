# openFrameworks para programadores de Processing
##### by [Zach Gage](www.stfj.net) (en proceso de traducción por Natxo Pedreira Gonzalez)

Si vienes de programar en entorno Processing seguramente habrás usado con anterioridad programación de objetos y te serán familiares conceptos como clases, metodos, propiedades,... Lo que quizas no hayas empleado es el polymorfismo (extender una clase) a la hora de crear clases.

What is class extendisng? (base and sub classes)?

Extender una clase es un método que permite agregar funcionalidades a una clase que ya existe. Esto es muy cómodo si por ejemplo tenemos varios objetos que son casi comunes en su base, pero con alguna diferencia entre ellos. Algo que me ha ayudado a comprender esto, es pensar que la clase base es como un padre/o madre y la nueva es un hijo que viene de serie con todas las características del padre pero con la posibilidad de tener alguna propia y así mejorar o cambiar al padre. class Hijo extends Padre 

Por ejemplo, para un videojuego necesitaremos crear una clase que defina al enemigo.

```c+++
	class Enemy{
		int x; //x position
		int y; //y position
		public void init(String pathToEnemyPicture, int startX, int startY){
			//load in the enemy picture from the hard-drive
			//assign starting positions
		}
	
		public void move(){
			//move, maybe shoot at player
		}

		public void draw(){
			//draw my picture to the screen at the proper location
		}
	}
```

Con esto tendriamos creada la estructura básica de nuestro enemigo, la cual tiene 3 metodos:

- `init()` para incializar el objeto

- `move()` actualiza la propiedad x e y

- `draw()` representa nuestro personaje en la pantalla

El siguiente paso sería, por ejemplo, crear enemigos que aparezcan de modo diferente, lo primero que puedes pensar es: fácil, hago varias clases iguales y les cambio lo que necesite, asi puedo tener varios enemigos tomando este básico que ya he creado. Eso seria la manera errónea de hacerlo: terminariamos con multitud de archivos y seria muy engorroso por no decir de locos el mantener el código.

Ahora es donde necesitamos usar el concepto de extender una clase, porque para crear nuestros enemigos, solo necesitamos cambiar uno de los métodos de la clase base (Enemy), el resto de funcionalidades y propiedades son las mismas.

Necesitamos crear una clase para cada tipo de enemigo que extienda la que define el enemigo “base”, en Processing sería algo así.

class DoubleEnemy extends Enemy

Al hacer esto la nueva clase que estamos creando, hereda las propiedades y los métodos de la anterior (Enemy) y hace que esten todos disponibles para usar en la nueva clase.

Como solo necesitamos modificar draw, no es necesario que definamos el resto de los metodos. Al volver a declara el metodo draw dentro de nuestra nueva clase, lo que estamos haciendo, es sobreescribir un metodo que ya existe en la clase Enemy para adaptarlo a la nueva clase.

En Processing serial algo como:

```java
	class DoubleEnemy extends Enemy
	{
		public void draw()
		{
			//draw myself twice
		}
	}
```

Y en c++

```c++

	//on a "DoubleEnemy.h" file
	class DoubleEnemy: public Enemy // class[className]:[privacy]	[extended Class]{}
	{
		public void draw();//the actual code for draw would be on the "DoubleEnemy.cpp" file
	}; // note the ";" at the end of the class statement
```

Esta clase nueva hereda los métodos `init()` y `move()` de la clase Enemy. Si modificamos el método init o move de la clase base (Enemy) esos cambios se aplicarán instantanemente a todas las clases que extiendan a esta.

Processing es en realidad es un framework para Java. Aunque no lo veamos, cada vez que creamos un sketch o una clase dentro de processing realmente lo que estamos haciendo es una clase que se extiende automáticamente sobre la clase base pApplet para poder usar todos los métodos o propiedades de esa clase base en nuestro nuevo código.

De ese modo cuando estamos escribiendo los métodos `setup()` o `draw()` realmente estamos redefiniendo los métodos que se encuentran en la clase base.

OpenFrameworks funciona de una manera similar a Processing. Si abres el archivo `testApp.h` y buscas la línea donde pone `#include “ofMain.h”` veras que debajo tenemos otra linea donde se declara la clase TestApp.

```c++
	
	class TestApp: public ofSimpleApp{

```
Como ya hemos visto con anterioridad esta es la equivalencia a lo que sería en Processing

```java
	class TestApp extends ofSimpleApp{
```

Lo que significa que la clase que estamos creando `TestApp` extiende a `ofSimpleApp` con lo cual esta nueva clase hereda todos los métodos de la clase base `ofSimpleApp`.

Justo después de la línea que define nuestra clase encontramos bajo el término “public:” encontramos un conjunto de métodos que provienen de esa clase base (ofSimpleApp) y que se encuentran como públicos en nuestra clase para poder ser re-escritos. Es el mismo funcionamiento que en Processing.

Todas las aplicaciones que creemos en c++ precisan de un método `main()` que define el punto de inicio del programa, en Java ocurre lo mismo, solo que Processing lo hace por y no necesitamos declarar ese método porque el compilador lo hace automáticamente por nosotros.

Si abres cualquier ejemplo que viene con OF verás que en todos hay un archivo llamado `main.cpp` en las primeras líneas de este archivo puedes ver varios `#include` (este comando funciona de igual modo que en Processing). Vamos a ir analizando cada uno de ellos.

```c++
	#include "ofMain.h"
```

vincula la libreria de OpenFrameworks a la clase (`main.cpp`) y le permite eejcutar dos métodos importantes de cualquier proyecto de OF, que son:

`ofSetupOpenGL()` el cual crea la ventana donde se mostrará nuestra aplicacion
`ofRunApp()`  llama a nuestra aplicacion

Si nos fijamos en el método `ofRunApp()` veremos que pasa un parámetro el cual es una instancia para crear el objeto de nuestra aplicacion “testApp”.
	`ofRunApp(new testApp());`

Para poder crear esta instancia de la clase testApp debemos de incluir en este archivo un `#include` al archivo de cabecera de dicha clase, así que necesitamos poner al principio

```c++
	#include “ofMain.h”
```

En resumen si analizamos este archivo `main.cpp` nos vamos a encontrar lo siguiente:

```c++
	#include “ofMain.h”
	#include “testApp.h”
	#include “ofAppGlutWindow.h”
```

Estamos importando a nuestro archivo `main.cpp` los archivos de cabecera de las clases: `ofMain`, `testApp`, `ofAppGlutWindow` con lo cual podremos crear instancias de cada una de ellas. A continuación encontramos:
```c++

	int main(){
		ofAppGlutWindow window;
		ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);

		ofRunApp( new testApp() );
	}
```

`ofSetupOpenGL()` y `ofRunApp()` son métodos de la clase ofMain
window es una instancia de la clase ofAppGlutWindow

Hasta que no empieces a crear tus propias clases igual te ayuda a comprender mejor el concepto de funcionamiento el pensar en la clase testApp como la ventana principal de Processing.

El proceso de compilado en C++ tiene grandes diferencias con respecto a Java, es importante conocer como ese ese proceso de compilado porque a posteriori nos facilitará la depuración de errores. Saber en que parte del compilado se produce el error nos ayudará enormemente a encontrar el fallo y poder solucionarlo.

En Java cada vez que compilamos todo el código es transformado a byte code, luego al ejecutarlo un interprete de Java lo procesa y posteriormente ejecuta.

En C++ el proceso de compilado difiere un poco de Java y pasaría por las siguientes fases:

- Paso 1: Preprocesado: el compilador lee todo, busca las instrucciones `#import` y por cada uno de ellos toma el archivo que se indica en el `import` y lo agrega al nuestro, creando una especie de superarchivo temporal donde esta todo el código junto. En este preprocesado se emplean todos lo comandos que van precedidos por un #

- Paso 2: el compilador parsea el código para buscar incoherencias o errores en el mismo y lo trocea para proceder al tercer paso y transformarlo a Assembly

- Paso 3: el código Assembly es trasladado a còdigo máquina creando objetos

- Paso 4: se juntan todos los objetos para crear el archivo ejecutable (.exe o .app)

Una ventaja de realizar el procesado en varios pasos es que si estamos realizando una aplicación compleja, no necesitaremos volver a compilar todo el código que hemos creado, sino que simplemente el compilador procesará los archivos que hayan cambiado.

Una clase en C++ esta compuesta de dos archivos, un ejemplo para comprender esto seria el pensar en que una clase es como una receta y que en ella encontramos.

El archivo de cabecera (.h), seria el listado de ingredientes y estaría compuesto por:
Comandos para que en el preproceso se evite la duplicidad en la importacion de los archivos de cabecera
Cualquier `#include para importar una clase
Any class extension statements -- no lo entiendo
Definiciones de varibles locales de esa clase
Prototipo de cada uno de los metodos de la clase
Los ajustes de seguridad para cada una de esos metodos y variables (public,private,priotected,...)

Y el archivo (.cpp) serían las instrucciones de nuestra receta, la cual tendría:
Todos los includes necesarios a los archivos de cabecera de cada clase
El código de cada uno de los métodos

Puedes comprobar esto abriendo cualquiera de los archivos testApp.h y testApp.cpp que se encuentran en cada uno de los ejemplos que vienen con OF

Todo el código que contenido en testApp.h esta agrupado dentro de un método condicional llamado `#ifndef`. Este método esta creado específicamente para que se ejecute en la parte  del compilado que corresponde al preprocesado. Recordemos que en esta fase, el compilador recorre todo el codigo juntando todos los includes en un mismo archivo.

Si has importado el mismo archivo de cabecera (.h) en distintos sitios, puede ser un problema porque habria instrucciones duplicadas. 

``` c++
	#ifndef _TEST_APP  
	#define _TEST_APP 
```

El comando #ifndef le esta diciendo al compilador que compruebe si la variable _TEST_APP esta definida, esta variable será definida la primera vez que se ejecute el código y si posteriormente el compilador se vuelve a encontrar con esta instrucción, al ver que la variable ya ha sido creada ya no agregara el código de ese archivo y así no tendremos duplicados.

Es una buena costumbre aplicar esto a todas las clases que creemos (claro esta usando nombres de variables distintos para cada clase)

Después de esto vienen las llamadas al metod `#include` para importar todas las clases que precisemos en nuestro proyecto.

A continuación encontramos la declaracion de la clase class testApp:public ofSimpleApp{ como verás la estructura es muy similar a su equivalente en Java.
After this comes the #include statement that brings in all of the OpenFrameworks functionality.
Then comes the class testApp : public ofSimpleApp{ line which is very similar to java's class declaration structure. To compare the two:
C++  :	
class [className] : [privacy] [extendedClass]
JAVA/P5:
[privacy] class [className] extends [extendedClass]


A continuación de la declaración de la clase en el archivo de cabecera encontramos el listado de métodos de esa clase, agrupados por bloques en función de su privacidad.
En Java puedes declarar los métodos como públicos o privados en cualquier orden, pero en c++ han de estar agrupados en bloques.

Un detalle importante es que en c++ tienes que definir tus clases en el archivo de cabecera antes de usarlas (como si fueran variables locales). Esto se llama prototipado, y puede parecer un poco engorroso de aplicar, pero es una manera de conseguir que el archivo de cabecera sea como una lista de los metodos y variables que componen tu clase. Lo cual resulta muy util a la hora de reusar esa clase en otro proyecto  o cuando otra persona quiera comprenderla o implementarla.

También recordar que al final de la clase tenemos que cerrarla con un punto y coma }; y no con un corchete como en Java, así como usar `#endif` para cerrar el condicional que iniciamos con `#ifndef` al principio del archivo. Puedes encontratr mas informacion sobre clases en c++ en: http://pages.cs.wisc.edu/~hasti/cs368/CppTutorial/NOTES/CLASSES-INTRO.html

## Que son los punteros?

Los punteros son problablemente uno de los conceptos mas dificiles de asimilar en c++. A continuación se da una explicacion muy basica de lo que son, su relacion en Java y para que son útiles.
Si deseas conocer mas en detalle estos conceptos, puedes leer este completo tutorial:
http://www.cplusplus.com/doc/tutorial/pointers.html

Una de las principales diferencias entre C++ y Java, es que en este ultimo todos los valores exceptuando los formatos basicos (byte, short, int, long, float, double, boolean, and char) son pasados por referencia. Un detalle importante es que Processing copia un String por valor mientras que en c++ se copia por referencia como en todas las clases.

Para comprender la diferencia entre valor y referencia, primero has de comprender como los ordenadores almacenan las variables en la memoria RAM.

Cuando escribimos int num = 5; en Processing, lo que realmente esta haciendo el ordenador es ir a la parte de la memoria que esta destinada a almacenar integrales, busca un hueco vacío con el numero de bytes necesarios para almacenar un integral, almacena el valor 5 en ese hueco y despues manda la direccion de esa caja que contiene el valor y se almacena como valor de variable.

En resumen que al hacer esto: int num = 5;  en Processing ese valor se guarda como la referencia al punto donde se almacena el valor 5 y no el valor en si mismo.

Es más facil de pensar en ese hueco en la memoria como un numero que hace referencia a una caja donde que contiene el valor que se ha almacenado (en este caso 5)

To understand the difference between value and reference you must first understand how the computer stores variables in its RAM.
When you write the Processing line:
int num = 5;
What the computer does is it goes to the place in its memory that is set up to store integers, picks an empty spot with the right number of bytes to store an integer, places the number 5 in that spot, and then sends the address of that spot to your program which stores it in the "num" variable.
It might be easier to think of the spot in memory that num references as a box containing the number 5:
5	
// value stored
2591
// address in memory


and as num as knowing the address this box
num:
2591	
// address in memory

Processing sabe que estas usando un “int” y que ha de devolverte el valor. Cuando hace un print(num) para ver el valor de la variable, lo que vemos en la consola es el valor que se encuentra “en la caja“ donde se ha almacenado la variable.

Si escribimos esto en un sketch de Processing:
void setup()
{
int num = 1;
addOne(num);
print(num);
}

void addOne(int num)
{
  num++;
}

Al ejecutarlo veremos en la consola el valor “1”. Lo que esta ocurriendo, es que al pasar un valor a una funcion, esta hace una copia de esa variable y no modifica el original.

Veamos otro ejemplo donde en vez de pasar un int como valor vamos a pasar una clase la cual si va a contener un int.

Escribamos en Processing
class Test
{
  int num=0;
}

void setup()
{
Test test = new Test();
test.num=1;
addOne(test);
print(test.num);
}

void addOne(Test test)
{
  test.num++;
}

Al ejecutar este nuevo código veremos que en la consola ahora sale “2”, esto se debe a que Processing reconoce que el valor que estamos pasando no es una estructura basica (aunque la clase contenga es int el cual si es un valor de estructura basica) y entonces pasa ese valor como referencia. Esto significa que en vez de pasar una copia del objeto Test completa a la funcion addOne, solo se pasa la direccion de la memoria donde esta almacenada esa clase.

What happened is that because we created a class Test, Processing recognized that it was not a basic data-type (even though the class contained an int which IS a basic data-type), and passed it to the function by reference. Reference means that instead of passing a copy of the entire Test object to the addOne function, it sent only the address in memory of where the class was stored.



Because Processing knows you're using an int and knows to pass it by value, when you ask for what num is with the line print(num), it prints the value of the address that num is referencing.
Try typing this code into processing:
void setup()
{
int num = 1;
addOne(num);
print(num);
}

void addOne(int num)
{
  num++;
}

Unsurprisingly, the program prints "1". We know that this is because when you pass num to a function, the function makes a copy of num and doesn't modify the original. This is called passing by value.

Lets look at another example. Here, instead of passing an integer, we will try passing a class containing an integer. Try typing this code into Processing:

class Test
{
  int num=0;
}

void setup()
{
Test test = new Test();
test.num=1;
addOne(test);
print(test.num);
}

void addOne(Test test)
{
  test.num++;
}


This time it printed "2". What's going on here?
What happened is that because we created a class Test, Processing recognized that it was not a basic data-type (even though the class contained an int which IS a basic data-type), and passed it to the function by reference. Reference means that instead of passing a copy of the entire Test object to the addOne function, it sent only the address in memory of where the class was stored.
Let's look at boxes again.
test:
52498	
// address in memory

52498:
1	
// test.num


Entonces, cuando test es pasado a través del metodo addOne() estamos pasando la direccion de la memoria(52498) donde esta almacenado test, por eso la variable num no se varía ni se copia.

Java hace esto porque si se pasara el objeto entero continuamente, se ralentizaría todo enormemente. Los valores basicos son suficientemente pequeños para ser pasados por su valor pero cualquier otro valor es transferido por referencia.

So when test is passed through addOne(), really just 52498, or whatever the actual memory address of test's data is passed. Because of that, when test's num is incremented, it is actually changed. No copy is ever made.
Java does this because if it were to pass entire objects around constantly everything would slow to a crawl. The basic data-types are small enough to get passed by value, but everything else is passed by reference.
& and *

C++ se diferencia de Java en que hay que declarar el estado en el cual estamos pasando algo, ya sea por valor o por referencia. You can also define when a variable will behave as if it contains actual data and when a variable will only contain a pointer to data. You can even make an int that behaves like the Test class did above. This is all done with the & (referencing) and * (dereferencing) symbols.

El valor & es usado para adquirir la dirección de la memoria donde se almacena una variable, por ejemplo:
b=1;
a=&b;

significa que a es igual o apunta a la dirección de la memoria donde está almacenada b, no su valor, por lo que a++; va a adquirir el siguiente hueco libre en la memoria despues de b. Pero si hacemos *a++; estamos incrementando el valor almacenado en a, y por consiguiente ahora tanto a como b tienen el valor de 2


C++ differs from Java in that you need to explicitly state whether you are passing something by value or by reference. You can also define when a variable will behave as if it contains actual data and when a variable will only contain a pointer to data. You can even make an int that behaves like the Test class did above. This is all done with the & (referencing) and * (dereferencing) symbols.
the & symbol is used to acquire the memory address of a variable or function, so for example:
b=1;
a = &b;

means, a is now equal to (or points to) the memory address of b, (and not the value of b). At this point,
a++;
would make a equal to the next memory address after b.
the * symbol is used to acquire the value stored in an address. So,
*a++;
would increment the value stored in a, and therefore, b would now equal 2.

¿Como declaro una variable que apunte a una direccion?
Usando el simbolo * este tipo de variables es lo que se conoce como puntero, es importante que estas variables sean declaradas con el mismo tipo del valor al que apunta, por ejeplo: integer pointers para iintegers, float pointers para floats, etc.
int x;
int *ptr;

x=5;
ptr = &x;
*ptr=10;
// ahora x = 10;

But how do I declare a variable to point to an address? To do this, you use the * symbol. This variable is called a pointer. Because different types of variables take on specific numbers of bytes, it is important to declare pointers of the same type as what they are pointing to, e.g. integer pointers for integers, float pointers for floats, etc.
example:
int x;
int *ptr;

x=5;
ptr = &x;
*ptr = 10;

//x now equals 10

So Where Do I use This?

En principio usarás punteros para pasar arrays. Un ejemplo de esto, puede verse en el ejemplo movieGrabberExample donde se usa un punterio para acceder a los pixeles del objeto videograbber ( insigned char* videoInverted;)
Funciona porque en c++ cuando nos referimos a un array sin [] estamos haciendo referencia a una dirección en la memoria, el simbolo [] funciona como * que son operadores de dereferencing
At runtime, your processor multiplies the number inside of the []'s (your index) by the number of bytes your data-type takes up in memory to figure out how far it must jump in memory to reach that index of your array.
So to pass an array in C++ you must pass it without the []'s, and the receiving function must be aware it is receiving a pointer:
[functionName] ( [variable type] * [varName]){
}

To learn more about the infinite complexities of pointers, I recommend visiting the site I referenced at the top of this section. (http://www.cplusplus.com/doc/tutorial/pointers.html )



Initially, you will use pointers to pass arrays back and forth through functions. This can be seen in the movieGrabberExample, where a pointer is used to access the pixels from the video grabber.
( unsigned char * 	videoInverted;)
This works because when you refer to an array in C++ without the []'s you are actually referring to an address in memory. The []'s work as a dereferencing operator, or, a "*".
At runtime, your processor multiplies the number inside of the []'s (your index) by the number of bytes your data-type takes up in memory to figure out how far it must jump in memory to reach that index of your array.
So to pass an array in C++ you must pass it without the []'s, and the receiving function must be aware it is receiving a pointer:
[functionName] ( [variable type] * [varName]){}

To learn more about the infinite complexities of pointers, I recommend visiting the site I referenced at the top of this section. (http://www.cplusplus.com/doc/tutorial/pointers.html )
Basic Data-types

Java y C++ comparten los tipos de variables mas sencillos: byte, short, int, long, float, double y char. (Boolean existe tambien en c++ y funciona del mismo modo que en Processing solo que se indica como bool )

Sin embargo C++ tiene más tipos de datos que son unsigned: unsigned byte, unsigned short, unsigned int, unsigned long, unsigned float, unsigned double, unsigned char. Unsigned significa que en vez de tener valores positivos y negativos (ejemplo: char puede tener cualquier valor comprendido entre -128 y 127), estas variables no tiene signo  (ejemplo: unsigned char puede tener cualquier valor comprendido entre 0 y 255)

Java and C++ share most basic data-types:
byte, short, int, long, float, double, and char. (Boolean is also in C++, and works the same way as it does in processing except it is called 'bool').
However, C++ has an extra set of data-types that are unsigned:
unsigned byte, unsigned short, unsigned int, unsigned long, unsigned float, unsigned double, unsigned char.
Unsigned means that instead of running positive and negative, (e.g. char can be set to any value between -128 and 127), these variables have no sign. (e.g. unsigned char can be set to any value 0-255).

The Processing String Exception

One major difference in the basic data-types is that Processing's string type is "String" while C++ uses a lowercase "string". But more importantly, C++'s string type, when set equal to another string type refers to it by reference (does not make a copy).
NOTE: (theo) not sure if this is true. I think C++ is by copy. So this example might be incorrect.
So, in processing:
String a = "yes";
String b = a;
b = "no";
print(a);

will print "yes"

but in C++
string a = "yes";
string b = a;
b = "no";
printf("%s \n", a.c_str(a));   // to see how this prints, see section 6.3.3 How in the world do I print to the console?

will print "no".
PImage, updatePixels() vs. ofTexture, pixels[]

When you draw in openGL (OF draws using the GLUT library, which in turn uses openGL, Processing draws to openGL optionally, if you decide to when declaring your window size), any pixel data that you want to put on the screen must be preloaded into your RAM before you can draw it. Loading pixel (bitmap) data to RAM is called loading your image into a texture.
Processing has a number of ways to solve this texture problem that hide what you are actually doing from you.
The first is the PImage object. A PImage is a texture object that has a built in color array that holds pixel values so that you can access the individual pixels of the image that you have loaded in. Images cannot draw themselves exactly, but they can be drawn by the image() function.
PImage myPImage; //allocate space for variable
myPImage = loadImage("sample.jpg"); //allocate space for pixels in ram, decode the jpg, and load pixels of the decoded sample.jpg into the pixels.
image(myPImage,100,100); //draw the texture to the screen at 100,100

I should note that its possible that the image() function actually loads the pixels into the ram instead of the PImage, but I dont know enough about the tech behind Processing to say for sure if this is the case or not.
If you want to access the individual pixels of the screen itself, however, you use a different function altogether. You first call loadPixels(), make your pixel changes, and then call updatePixels() to make your changes appear.
This is slightly confusing, because what is actually happening here is the same as what happened above with the PImage: Processing is loading your pixels from the screen into a texture, essentially a PImage, and then drawing that texture to the screen after you update it. For some reason, however, they chose not to use the same function for both.
OpenFrameworks handles this a little differently (and a little bit better in my opinion). Instead of having two different methods, the ofImage object loads images from files, and images from the screen. Additionally, ofImage can draw itself and needs no separate function to do this.
The OF code for the example above with myPImage looks like:
ofImage myImage; //allocate space for variable
myImage.loadImage("sample.jpg"); //allocate space in ram, decode jpg, load pixels.
myImage.draw(100,100);

If you wanted to change the pixels on the screen, you would also use an ofImage.
ofImage theScreen; //declare variable
theScreen.grabScreen(0,0,1024,768); //grab at 0,0 a rect of 1024x768. Equivalent to loadPixels();
//edit pixels in theScreen
theScreen.draw(0,0); //equivalent to updatePixels();

But how do I edit the pixels of something that is in the ram you may ask? The short answer is you cannot. Once something is in the RAM (in an ofTexture), you cannot access it anymore.
You can edit the pixels of an ofImage because ofImages contain two data structures. One of these is an array of Unsigned Characters which represent all of the colors of every pixel, and the other is an ofTexture, which is used to upload those pixels into the ram after changes.
You can actually turn off this texture in an ofImage to save RAM if you know you won't ever have to draw what you are loading to the screen. This could be useful if you only need to load an image to access pixel color values in it, or if you are taking a screenshot that you will save to your hard drive but never draw. see: http://www.openframeworks.cc/documentation#ofImage-setUseTexture
How are pixel values stored without a Color object?

Pixel values are stores as a series of Unsigned Characters. An Unsigned Character is a fancy way of saying a byte value between 0 and 255 inclusive. Every object in OF that can return a pixel array ( getPixels() ), will return you an array of unsigned characters. Because it takes three unsigned characters to denote a color (one for each of the red, green, blue, channels), this array's length will be three times the number of pixels inside of it and structured like:
{pixel_1_Red, pixel_1_Green, pixel_1_Blue, pixel_2_Red, pixel_2_Green, pixel_2_Blue....}

To access a color of a specific pixel:
unsigned char *	myPixels; //create a pointer to an unsigned charecter
myPixels = myOFImage.getPixels(); //set that pointer to point to the beginning of the pixel array
int colorIndex = y*(myOFImage.width*3)+x*3; // yPos * width * 3 + xPos * 3 = the red channel position
ofSetColor(myPixels[colorIndex],myPixels[colorIndex+1],myPixels[colorIndex+2]); 
//sets the color of each channel by going to the successive two values in the array after that of the red channel. 

Common Problems With C++ / Misc. Topics

Expecting implicit data conversion?

One big surprise that comes with C++ is that it doesn't do implicit data conversion. A good example of this is trying to print an integer.
int num = 5;
printf(num +"\n");

will yield an error.
This is because printf only prints strings and chars, and num is neither one of these. To convert any non-string or non-char to a string, use the ofToString() function.
Changing window size

Window size is set intuitively in main.cpp. If you open it up, the comments will show you clearly how to change the size or go to fullscreen mode.
Update() and Draw()?

Unlike Processing, OF contains two methods that are run every loop through of your program, Update() and Draw(). It is good practice to do all of your calculations in the Update() function and reserve Draw() for simply showing results on the screen. This prevents any large slowdowns that might occur during a draw function that could be too complicated. Instead of getting halves of images drawn or screen-tearing, you simply get a low framerate.
Additionally, I should mention that if you do any heavy lifting in your project (e.g. loading in images, or loading anything at all from a file really), you should do it in your setup() function if possible. Update() and Draw() run in a loop, and because of that you should only include code in them that has to run every frame. If something only has to run once, it should probably be in Setup().
How in the world do I print to the console?

For printing to the console, you have two options. The first is printf, which is robust but a bit complicated, and is included by default in openframeworks.
The second is iostream, which is simpler, but less robust, and not included by default.
printf

If you want to use printf to print to the console, this is a good tutorial on how it works: http://www.cplusplus.com/reference/clibrary/cstdio/printf.html

iostream

Another option for printing to the console is iostream. This is a very old c++ library that lets you print to the console very easily and will implicitly convert many variable types for you so you don't have to use ofToString().
To use iostream you first need to include it at the top of your .cpp file
#include <iostream>

Note that in some compilers, specifically very old ones, you will need to include <iostream.h> instead of just <iostream>. This is due to updates in the c++ standard language library (std) in recent years. A more detailed explanation can be found at:
http://members.gamedev.net/sicrane/articles/iostream.html
Actually using iostream is extraordinarily easy.
in processing your code might look like this:
int i = 10;
String s = "Hello!";
boolean b = false;

println(i+" "+s+" "+b); // print variables and end the line
print(i+" "+s+" "+b); // print variables without ending the line.

this would print
10 Hello! false
10 Hello! false

in the console.
The equivalent c++ code using iostream is:
int i = 10;
string s = "Hello!";
bool b = false;

cout<<i<<" "<<s<<" "<<b<<endl; // print variables and end the line
cout<<i<<" "<<s<<" "<<b;       // print variables without ending the line.

this would print
10 Hello! 0
10 Hello! 0

in the console. Note that with iostream, unlike in processing, a false boolean is represented by a '0' and not "false", and a true boolean is represented by a '1'.
Also note that in Java, ending or not ending the line after you print is accomplished by which function you pick, print() or println(), whereas in c++ with iostream, it is controlled by whether or not you put the 'endl' keyword at the end of your cout statement.
Smoothing not working on filled shapes?

If you are drawing a filled shape, e.g. with ofBeginShape(), even if you have called ofEnableSmoothing(), you will notice that the edges of the shape have not been smoothed. This is because GLUT, the library that OF uses for openGL management, doesn't have support for true full-screen graphics, and therefor can't run full-screen anti-aliasing, which is what would smooth your shapes.
An easy workaround for this is to simply draw your shapes twice, the first time filled, and the second time not filled, so that OF draws lines, which it software anti-aliases.
ofFill();

ofBeginShape(); //shape
	ofVertex( 1,1 );
	ofVertex( 5,5 );
	ofVertex( 1,10 );
	ofVertex( 1,1 );
ofEndShape();


ofNoFill();

ofBeginShape(); //smoothed edges
	ofVertex( 1,1 );
	ofVertex( 5,5 );
	ofVertex( 1,10 );
	ofVertex( 1,1 );
ofEndShape();

Displaying video problem/feature related to ofSetColor

Although this is a problem/feature affecting any object that uses an ofTexture draw itself to the screen, I first encountered it with the videoGrabber, and I think that may be the case for many people, so I'm listing it as the video problem/feature.
Basically, ofTextures are constructed so that they can be tinted by the ofSetColor() call. This is great as long as you know it's going to happen, but if it catches you by surprise it can be really confusing, especially if your background is black and you have just called
ofSetColor(0,0,0);
which would make whatever ofTexture you're telling to draw not show up at all.
The solution to this is easy, just make sure that right before you tell any ofTextures to draw, you call ofSetColor() and set it to white, or whatever tint you want to use.
Processing background() vs. OF ofBackground()

In Processing, making the background() call automatically tells Processing to set the background to be set every frame to the color you specified in your function call.
Of can make it auto-refresh every frame, there is a separate function to call:
ofSetBackgroundAuto(true);

This function will make the background autorefresh with the last ofBackground() call, without having to re-call it each time inside draw(). If you don't want to redraw, but make a cumulative image, use:
ofSetBackgroundAuto(false);

Because by default OF redraws the screen every frame.
ofFill() / ofNoFill() vs. processing fill() noFill()

In processing, you can toggle fills and strokes: fill(), noFill. stroke(), noStroke.
In Openframeworks, it's one or the other.
C++  :	
JAVA/P5:
ofFill();
fill(); noStroke();
ofNoFill();
noFill(); stroke(1);

additionally, there is no way to change the stroke width built into openFrameworks. A way around this is to change the stroke size with an openGL call, but it doesn't look that great.
glLineWidth(STROKE_SIZE);

Math functions, and where they come from (no more Math.*)

Math functions in OpenFrameworks actually come from three separate files
cmath

Complex math functions (trigonometric, hyperbolic, exponential, logarithmic, power, rounding, absolute value and remainder functions) come from the cmath library (math.h), and are included by default in OF.
A list of these functions is available at: http://www.cplusplus.com/reference/clibrary/cmath/
ofConstants

Other basic math functions are provided by the ofConstants file.
These include:
Constants:
PI;
TWO_PI;
M_TWO_PI;
FOUR_PI;
HALF_PI;
and Functions:
DEG_TO_RAD();
RAD_TO_DEG();
MIN(x,y);
MAX(x,y);
CLAMP(val,min,max);
ABS([math functions you want to get the absolute value of]);
ofMath

additionally ofMath() provides functions for getting random values.
http://www.openframeworks.cc/documentation#ofMath-about
Structs, what are they for, and how can we use them?

Structs are like miniature classes except they don't have methods. Basically they're custom data objects.
They're very convenient because they don't have to be created externally from your class files (although technically neither do classes..)
Primarily they're used for implementing linked lists (similar to ArrayLists in java). Although linked lists are probably my favorite data structure, I'm not going to write a tutorial here because they can be very complicated at first.
A very inclusive tutorial on linked lists can be found here: http://richardbowles.tripod.com/cpp/linklist/linklist.htm
Anyway, the general format of a struct is :
struct [name]
{
	[varType] varName;
	[varType] varName;
	[varType] varName;
	[etc...]
};

Memory Management and You

In Java/p5 the way garbage collection works is that every few cycles the interpreter sweeps the ram looking for any used objects that have no pointers referencing them, and deletes them.
That means if you were to declare
myCustomDataType temp = new myCustomDataType();
temp = null;

temp was set to reference a newly created myCustomDataType. temp was then set equal to null. This did not actually clear the new myCustomDataType from ram, but whenever java's garbage collection runs it would notice that the new myCustomDataType has no references and would delete it.
Unlike java/p5 however, c++ does not have automated garbage collection. This means that if you have declared object and you want to get rid of it, you will have to delete it yourself. Setting a pointer to NULL is not good enough.
calling the comparable code in c++ would result in an empty pointer and some memory that had been allocated in the ram but now is lost forever. This is called a memory leak. Although it might not affect you right off the bat, memory leaks can lead to your program eating up all of its available memory and crashing. These can be very frustrating to debug because they happen over time and don't give you a specific line that's crashing your program.
Fortunately, they're easy to avoid as long as you plan your programs carefully. The proper way to delete an object after you have created it is to use the delete keyword
delete temp;

Basic Logic Problems

Zach Lieberman asked me to include a bit on conditional logic errors so here goes.
A very common conditional logic error is forgetting to restate your entire argument inside an if statement with an && (and) or || (or) operator.
For example:
int x = 5;
if(x < 0 || > 10)
{
    return true;
}
else
{
    return false;
}

will always return true because ( > 10) is always true. The proper way to write this would be:
int x = 5;

if(x < 0 ||x > 10)
{
    return true;
}
else
{
    return false;
}

note how the entire argument is restated. Instead of asking: is x less than 0 or greater than 10
you need to ask: is x less than 0 or is x greater than 10


