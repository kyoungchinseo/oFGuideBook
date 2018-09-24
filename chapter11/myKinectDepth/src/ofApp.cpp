#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);

    openNIDevice.setup();
    openNIDevice.setLogLevel(OF_LOG_VERBOSE);
    openNIDevice.addDepthGenerator();
    openNIDevice.addImageGenerator();
    openNIDevice.start();
    openNIDevice.setMirror(true);

    verdana.load(ofToDataPath("verdana.ttf"), 24);
    
    ratioW = ofGetWidth() / 640.0;
    ratioH = ofGetHeight() / 480.0;
    
    selectedPoint = ofPoint(ofGetWidth()/2,ofGetHeight()/2);
}

void ofApp::exit() {
    openNIDevice.stop();
}

//--------------------------------------------------------------
void ofApp::update(){
    openNIDevice.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(0, 0, 0);

    //openNIDevice.drawDebug(0, 0, ofGetWidth(), ofGetWidth()/2*0.75);

    ofShortPixels depthMap = openNIDevice.getDepthRawPixels();
    
    int px = selectedPoint.x / ratioW;
    int py = selectedPoint.y / ratioH;

    int depth = depthMap[px + py * 640];
    int value = ofMap(depth, 500, 2000, 0, 255);

    for (int i=0; i<480; i+=10) {
        for (int j=0; j<640; j+=10) {
            if (depthMap[i*640+j] > 2000) {
                //ofNoFill();
                ofSetColor(value, 0, 0);
                ofDrawCircle(j*ratioW+10, i*ratioH+10, 3);
            } else {
                //ofFill();
                ofSetColor(0, 0, 100);
                ofDrawCircle(j*ratioW+10, i*ratioH+10, 7);
            }
        }
    }

    ofSetColor(0, 255, 0);
    string info = " MILLIS: " + ofToString(ofGetElapsedTimeMillis())
                + " FPS: " + ofToString(ofGetFrameRate());
    verdana.drawString(info, 20, ofGetHeight() - 26);
    
    ofSetColor(255, 255, 255);
    ofDrawCircle(selectedPoint, 20);

    ofSetColor(0, 255, 0);
    string msg = "Position (" + ofToString(selectedPoint.x) + "," + ofToString(selectedPoint.y) +") "
               + "Depth: " + ofToString(depth);
    verdana.drawString(msg, 20, 40);
    
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
    selectedPoint.x = x;
    selectedPoint.y = y;
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
