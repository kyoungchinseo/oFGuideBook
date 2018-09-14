#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("verdana.ttf",24);
    message = "";
    
    bDraw = false;
    posX = 0;
    posY = 0;
    r = 0;
    
    pos.clear();
    radius.clear();
    
    
    ofSetCircleResolution(64);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,0,0);
    font.drawString(message,30,60);
    
    for(int i=0;i<pos.size();i++) {
        ofSetColor(0,0,255);
        ofDrawCircle(pos[i],radius[i]);
    }
    
    if (bDraw) {
        ofSetColor(0,255,0);
        ofDrawCircle(posX,posY,r);
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
    //message = "mouse moved (" + to_string(x) + "," + to_string(y) + ")";
    //cout << message << endl;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    message = "mouse dragged (" + to_string(x) + "," + to_string(y) + "," + to_string(button) + ")";
    cout << message << endl;
    
    r = ofDist(posX, posY, x, y);
    bDraw = true;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    message = "mouse pressed (" + to_string(x) + "," + to_string(y) + "," + to_string(button) + ")";
    cout << message << endl;
    
    posX = x;
    posY = y;
    bDraw = false;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    message = "mouse released (" + to_string(x) + "," + to_string(y) + "," + to_string(button) + ")";
    cout << message << endl;
    pos.push_back(ofPoint(posX,posY));
    radius.push_back(r);
    bDraw = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    message = "mouse entered (" + to_string(x) + "," + to_string(y) + ")";
    cout << message << endl;
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    message = "mouse exited (" + to_string(x) + "," + to_string(y) + ")";
    cout << message << endl;
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
