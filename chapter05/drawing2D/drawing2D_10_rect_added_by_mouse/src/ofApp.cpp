#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    rectPanel.clear();
    
    ofSetBackgroundColor(80,80,80);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0;i<rectPanel.size();i++) {
        rectPanel[i].draw();
    }
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
    
    RectPanel panel;
    panel.setRectPanel(x,
                       y,
                       ofRandom(80,120),
                       ofRandom(80,120),
                       ofRandom(0,255),
                       ofRandom(0,255),
                       ofRandom(0,255),
                       ofRandom(10,100)
                       );
    rectPanel.push_back(panel);
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
