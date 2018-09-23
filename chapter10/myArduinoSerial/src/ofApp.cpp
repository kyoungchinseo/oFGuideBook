#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    font.load("verdana.ttf", 64);

    serial.listDevices();
    vector<ofSerialDeviceInfo> deviceList = serial.getDeviceList();

    for(auto list: deviceList) {
        cout << list.getDevicePath() << endl;
    }

    serial.setup("/dev/cu.usbmodem1421", 9600);
    recvData.clear();
}


//--------------------------------------------------------------
void ofApp::update(){
    char ch;
    if(serial.available()) {
        while((ch= serial.readByte())>0) {
            if(ch== ' ') {
                rotation = ofToFloat(recvData);
                cout<< "Received: "<< rotation<< endl;
                recvData.clear();
            } else{
                recvData+= ch;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(20,20,20);
    ofSetColor(220);
    string msg;
    msg+= "Rotating "+ ofToString(rotation);
    font.drawString(msg,50,100);
    ofSetColor(200,200,200,70);
    ofTranslate(ofGetWindowWidth()/2.0f,ofGetWindowHeight()/2.0f);
    ofRotate(rotation);
    ofTranslate(-200,-100);
    ofDrawRectangle(0,0,400,200);
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
