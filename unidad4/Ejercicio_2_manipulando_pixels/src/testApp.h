#pragma once

//  Luego de ver arrays estaticos y su relacion con los punteros a memoria
//  Se platea esta actividad como desafio para comprender el poder y velocidad
//  de utilizar la memoria de esta manera haciendo procesamiento de imagenes 
//  en tiempo real

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
    
    ofVideoGrabber  cam;
    ofImage         img;
    
    int width, height;
};
