#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    button.setup(ofGetWidth()*0.3,ofGetHeight()*0.3, ofGetWidth()*0.4, ofGetHeight()*0.4, ofColor(255,0,0));
    
    color.set(130,130,130);
    ofAddListener(button.selectedColor, this, &ofApp::changeColor);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(color);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    
    button.draw();
}

void ofApp::changeColor(ofColor &c) {
    color = c;
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
