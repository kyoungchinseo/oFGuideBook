#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(40,40,40);
    
    float centerX = ofGetWindowWidth()/2.0;
    float centerY = ofGetWindowHeight()/2.0;
    
    upperLeft.x = centerX - 240;
    upperLeft.y = centerY - 40;
    upperRight.x = centerX - 40;
    upperRight.y = centerY - 40;
    lowerLeft.x = centerX - 200;
    lowerLeft.y = centerY + 175;
    lowerRight.x = centerX - 55;
    lowerRight.y = centerY + 260;
    
    upperLeftMessage = "A";
    upperRightMessage = "B";
    lowerLeftMessage = "C";
    lowerRightMessage = "D";
    
    upperLeftFont.load("verdana.ttf", 240);
    upperRightFont.load("verdana.ttf", 180);
    lowerLeftFont.load("verdana.ttf", 200);
    lowerRightFont.load("verdana.ttf", 300);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,0,0);
    upperLeftFont.drawString(upperLeftMessage, upperLeft.x, upperLeft.y);
    
    ofSetColor(255,255,0);
    upperRightFont.drawString(upperRightMessage, upperRight.x, upperRight.y);
    
    ofSetColor(0,255,255);
    lowerLeftFont.drawString(lowerLeftMessage, lowerLeft.x, lowerLeft.y);
    
    ofSetColor(255, 0, 255);
    lowerRightFont.drawString(lowerRightMessage, lowerRight.x, lowerRight.y);
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
