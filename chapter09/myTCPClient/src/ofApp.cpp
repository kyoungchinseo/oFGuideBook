#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("verdana.ttf", 20);

    TCPClient.setup("127.0.0.1", 11999);
    TCPClient.setMessageDelimiter("\n");

    color.set(100, 100, 100);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (TCPClient.isConnected()){
        string recv = TCPClient.receive();
        if (recv.length() > 0) {
            message = recv;
            color = parseMessage(message, " ");
        }
    }
}

ofColor ofApp::parseMessage(string message,string delim)
{
    ofColor color;
    vector<int> value;
    value.clear();
    size_t pos;
    while((pos = message.find(delim)) != string::npos) {
        string token = message.substr(0, pos);
        value.push_back(ofToInt(token));
        message.erase(0, pos + delim.length());
    }
    value.push_back(ofToInt(message));
    
    if (value.size() == 3) {
        color.r = value[0];
        color.g = value[1];
        color.b = value[2];
    }
    
    return color;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(color);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    if (message.length() >0) {
        ofSetColor(255,255,255);
        font.drawString("Receiving: " + message, 10, 30);
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
