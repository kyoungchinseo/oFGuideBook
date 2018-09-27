#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(40,40,40);
    
    float centerX = ofGetWindowWidth()/2.0;
    float centerY = ofGetWindowHeight()/2.0;
    
    upperLeft.setup("verdana.ttf", 240);
    upperRight.setup("verdana.ttf", 180);
    lowerLeft.setup("verdana.ttf", 200);
    lowerRight.setup("verdana.ttf", 300);
    
    upperLeft.setPosition(centerX - 240, centerY - 40);
    upperRight.setPosition(centerX - 40, centerY - 40);
    lowerLeft.setPosition(centerX - 200, centerY + 175);
    lowerRight.setPosition(centerX - 55, centerY + 260);
    
    upperLeft.setMessage("A");
    upperRight.setMessage("B");
    lowerLeft.setMessage("C");
    lowerRight.setMessage("D");
    
    upperLeft.setColor(ofColor(255,0,0));
    upperRight.setColor(ofColor(255,255,0));
    lowerLeft.setColor(ofColor(0,255,255));
    lowerRight.setColor(ofColor(255,0,255));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    upperLeft.draw();
    upperRight.draw();
    lowerLeft.draw();
    lowerRight.draw();
    
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
