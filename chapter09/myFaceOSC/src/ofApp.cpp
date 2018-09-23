#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup(PORT);
}

/*
 Pose
 center position: /pose/position
 scale: /pose/scale
 orientation (which direction you're facing): /pose/orientation
 Gestures
 mouth width: /gesture/mouth/width
 mouth height: /gesture/mouth/height
 left eyebrow height: /gesture/eyebrow/left
 right eyebrow height: /gesture/eyebrow/right
 left eye openness: /gesture/eye/left
 right eye openness: /gesture/eye/right
 jaw openness: /gesture/jaw
 nostril flate: /gesture/nostrils
 Raw
 raw points (66 xy-pairs): /raw
 */

//--------------------------------------------------------------
void ofApp::update(){
    while(receiver.hasWaitingMessages()) {
        ofxOscMessage message;
        receiver.getNextMessage(message);
        
        if (message.getAddress() == "/pose/position") {
            position[0] = message.getArgAsFloat(0) * ofGetWidth() / 640;
            position[1] = message.getArgAsFloat(1) * ofGetHeight() / 480;
        }
        if (message.getAddress() == "/pose/orientation") {
            orientation[0] = message.getArgAsFloat(0);
            orientation[1] = message.getArgAsFloat(1);
            orientation[2] = message.getArgAsFloat(2);
        }
        
        if (message.getAddress() == "/gesture/mouth/height") {
            mouseHeight = message.getArgAsFloat(0);
        }
        
        if (message.getAddress() == "/pose/scale") {
            scale = message.getArgAsFloat(0);
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(80, 80, 80);

    ofSetColor(255, 0, 0);
    ofPushMatrix();
        ofTranslate(position[0],position[1],0.0);
        ofRotateX(orientation[0]*180/3.141592*2.0);
        ofRotateY(orientation[1]*180/3.141592*2.0);
        ofRotateZ(orientation[2]*180/3.141592*2.0);
        ofScale(1.0*(scale/4.0*5.0),1.0*mouseHeight,1.0);
        ofDrawBox(0, 0, 0, 100, 100, 100);
    ofPopMatrix();
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
