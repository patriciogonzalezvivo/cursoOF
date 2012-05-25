#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){ 
    
    int array[10];

    cout << "Apenas creamos array contiene la siguiente informacion con basura de memoria: " << endl;
    for(int i = 0; i < 10; i++){
        cout << array[i] << endl;
    }
    //  Cambiando el tipo de array, veremos que a la basura la castea de formas distintas.
    //  Probar con: float y char 
    
    cout << endl;
    cout << "Podemos acceder a la direccion en memoria por medio del simbolo &" << endl;
    for(int i = 0; i < 10; i++){
        cout << "Direccion de array indice " << i << " -> " << &array[i] << endl;
    }
    
    cout << endl;
    // Vemos que en el caso de los int y float las direcciones saltan de a 4 bytes 
    // Esto es porque un array coloca sus elementos de forma continua una atr‡s de otra.
    cout << "Cada elemento de array posee " << sizeof( array[0 ]) << " bytes, mientras que el array total pesa " << sizeof(array) << endl;
    
    cout << endl;
    // Si imprimimos el contenido de array sin indice nos devuelve la direccion al primer elemento del array.
    cout << "array solo contiene la direccion " << array << " y accede a sus elemento saltando los espacios correspondientes al tipo" << endl;
    
    cout << endl;
    // De hecho es posible hacer calculos de direccion de espacio en memoria
    cout << "Esto " << array+4 << " deberia coincidir con la direccion del cuarto elemento" << endl;
    cout << "Y esto " << *(array+4) << " con su contenido" << endl;
    
    cout << endl;
    
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}