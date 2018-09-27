#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(40,40,40);
    
    float centerX = ofGetWindowWidth()/2.0;
    float centerY = ofGetWindowHeight()/2.0;
    
    normal.setup("verdana.ttf",200);
    normal.setPosition(centerX-100, centerY + 100);
    normal.setMessage("O");
    normal.setColor(ofColor(255,255,0));
    
    VTF.setup("verdana.ttf",200);
    VTF.setPosition(centerX-300, centerY + 100);
    VTF.setMessage("H");
    VTF.setColor(ofColor(255,0,0));
    VTF.setMaxAmplitude(200.0);
    VTF.setStep(0.1);

    CTF.setup("verdana.ttf", 200);
    CTF.setPosition(centerX + 100, centerY + 100);
    CTF.setMessage("T");
    CTF.setColor(ofColor(0,255,255));
    CTF.setStep(0.03);
    CTF.setMinAlpha(40.0);
    CTF.setMaxAlpha(100.0);

}


//--------------------------------------------------------------
void ofApp::update(){
    VTF.update();
    CTF.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    normal.draw();
    VTF.draw();
    CTF.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
