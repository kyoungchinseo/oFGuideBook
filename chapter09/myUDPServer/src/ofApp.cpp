#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("verdana.ttf",20);

    UDPServer.Create();
    //UDPServer.Connect("127.0.0.1", 11999);
    UDPServer.Connect("172.30.1.255", 11999);
    UDPServer.SetEnableBroadcast(true);
    UDPServer.SetNonBlocking(true);

    ofSetFrameRate(30);
    ofSetBackgroundColor(255, 255, 255);

    balls.clear();
}

void ofApp::sendBall() {
    string message="";
    for (auto ball: balls) {
        message += ofToString(ball->location.x) + " ";
        message += ofToString(ball->location.y) + " ";
        message += ofToString(ball->radius) + " ";
        message += ofToString((int)ball->color.r) + " ";
        message += ofToString((int)ball->color.g) + " ";
        message += ofToString((int)ball->color.b) + "|";
    }
    message = message.substr(0,message.size()-1);
    UDPServer.Send(message.c_str(),message.length());
}

//--------------------------------------------------------------
void ofApp::update(){
    for(auto ball : balls) {
        ball->update();
        ball->checkBoundary();
    }
    sendBall();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(auto ball: balls) {
        ball->draw();
    }

    ofSetColor(0, 0, 0);
    font.drawString("Server-side", 10,30);
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
    Ball *ball = new Ball();
    ball->init(ofVec2f(x,y), ofVec2f(ofRandom(5.0, 10.0),ofRandom(5.0, 10.0)),
              ofRandom(20,40), ofColor(ofRandom(255),ofRandom(255),100));
    balls.push_back(ball);
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
