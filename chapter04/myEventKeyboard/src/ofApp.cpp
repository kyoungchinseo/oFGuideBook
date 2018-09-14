#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("verdana.ttf",24);
    message = "";
    
    x = ofGetWidth()/2 - 40;
    y = ofGetHeight()/2 - 40;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,0,0);
    font.drawString(message,20,60);
    
    ofSetColor(0,0,255);
    ofDrawRectRounded(x, y, 80, 80, 8);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    message = "key code: " + to_string(key) + " is pressed.";
    cout << message << endl;

    switch(key) {
        case OF_KEY_LEFT:
            x-=5;
            break;
        case OF_KEY_RIGHT:
            x+=5;
            break;
        case OF_KEY_UP:
            y-=5;
            break;
        case OF_KEY_DOWN:
            y+=5;
            break;
            
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    message = "key code: " + to_string(key) + " is released.";
    cout << message << endl;
    
    
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
