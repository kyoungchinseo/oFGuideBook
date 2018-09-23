#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    font.load("verdana.ttf",20);

    UDPClient.Create();
    UDPClient.Bind(11999);
    UDPClient.SetNonBlocking(true);

    ofSetFrameRate(30);
    ofSetBackgroundColor(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::update(){
    char udpMessage[1000];
    UDPClient.Receive(udpMessage,1000);
    string message = udpMessage;

    if (message!="") {
        //cout << message << endl;
        strBalls = ofSplitString(message,"|");
        cout << strBalls.size() << endl;
        for(auto strBall: strBalls) {
            cout << strBall << endl;
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(auto strBall: strBalls) {
        Ball myBall;
        myBall.init(strBall);
        myBall.draw();
    }

    ofSetColor(0, 0, 0);
    font.drawString("Client-side", 10,30);
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
