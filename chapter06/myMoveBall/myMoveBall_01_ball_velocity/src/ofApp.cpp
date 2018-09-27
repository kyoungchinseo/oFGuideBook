#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    location.set(ofGetWidth()/2,ofGetHeight()/2);
    velocity.set(3.0f,5.0f);
    radius = 30;
}

//--------------------------------------------------------------
void ofApp::update(){
    location += velocity;
    
    if ((location.x - radius < 0) || (location.x + radius > ofGetWidth())) {
        velocity.x *= -1;
    }
    if ((location.y - radius < 0) || (location.y + radius > ofGetHeight())) {
        velocity.y *= -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,0,0);
    ofDrawCircle(location, 30);
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
