#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    message = "";

    width = 400;
    height= 400;

    font.load("verdana.ttf",20);

    TCPServer.setup(11999);
    TCPServer.setMessageDelimiter("\n");

    image.allocate(width, height);
    colorMap = new unsigned char[width*height*3];
    for(int i=0;i<height;i++) {
        for(int j=0;j<width;j++) {
            colorMap[i*width*3+j*3+0] = j/(float)width*255;
            colorMap[i*width*3+j*3+1] = (height-i)/(float)height*255;
            colorMap[i*width*3+j*3+2] = 100;
        }
    }
    image.setFromPixels(colorMap, width, height);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    image.draw(0, 0, ofGetWidth(),ofGetHeight());
    if (message.length() > 0) {
        font.drawString("Sending: " + message, 10, 30);
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
    int pos_x = x / (float)ofGetWidth() * width;
    int pos_y = y / (float)ofGetHeight() * height;

    message = ofToString((int)colorMap[pos_y * width * 3 + pos_x * 3 + 0]) + " " +
                     ofToString((int)colorMap[pos_y * width * 3 + pos_x * 3 + 1]) + " " +
                     ofToString((int)colorMap[pos_y * width * 3 + pos_x * 3 + 2]);
    if (TCPServer.isConnected()) {
        TCPServer.sendToAll(message);
    }
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
