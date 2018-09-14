#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    
    rotAngle = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    rotAngle = rotAngle + 0.5;
}

//--------------------------------------------------------------
void ofApp::draw(){
    float w = 100;
    float h = 100;
    float cx = ofGetWindowWidth()/2;
    float cy = ofGetWindowHeight()/2;
    
    ofSetColor(255,0,0);
    ofTranslate(cx,cy);
    ofRotate(rotAngle);
    ofDrawRectangle(-w/2,-h/2,w,h);
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
