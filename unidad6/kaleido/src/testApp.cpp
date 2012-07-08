#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    width = 640;
    height = 480;
    video.initGrabber(width, height);
    
    shader.load("", "shader.frag");

}

//--------------------------------------------------------------
void testApp::update(){ // CPU
    video.update();
}

//--------------------------------------------------------------
void testApp::draw(){   // GPU
    ofVec2f radio = ofVec2f(0,-height*0.5);
    //  A
    ofVec2f A= ofVec2f(width*0.5, height*0.5);
    ofVec2f p[2];
    //  B
    p[0] = radio + A;
    //  C
    p[1] = radio.getRotated(60) + A;
    
    
    shader.begin();
    shader.setUniformTexture("text", video.getTextureReference(), 0);
    shader.setUniform1f("rotate", ofGetElapsedTimef()*0.1);
    shader.setUniform2f("size", width, height);
    
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(A.x, A.y);
    glVertex3f(A.x, A.y, 0.0);
    for(int i = 0; i < 7; i++){    
        glTexCoord2f(p[i%2].x, p[i%2].y);
        ofVec2f e = radio.getRotated(60*i) + A;
        glVertex3f(e.x,e.y, 0.0);
    } 
    glEnd();
    shader.end();
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