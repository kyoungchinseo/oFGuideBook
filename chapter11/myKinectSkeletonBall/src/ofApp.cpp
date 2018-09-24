#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    balls.clear();
    
    ofSetLogLevel(OF_LOG_VERBOSE);

    openNIDevice.setup();
    openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);

    openNIDevice.addUserGenerator();
    openNIDevice.setMaxNumUsers(2);
    openNIDevice.start();

    verdana.load("verdana.ttf", 24);

    ratioW = ofGetWidth()/640.0;
    ratioH = ofGetHeight()/480.0;
    
    
}

void ofApp::exit(){
    openNIDevice.stop();
}

//--------------------------------------------------------------
void ofApp::update(){
    openNIDevice.update();
    
    for(auto ball: balls) {
        ball->update();
        ball->checkBoundary();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);

    openNIDevice.drawImage(0, 0, ofGetWidth(), ofGetHeight());
    openNIDevice.drawSkeletons(0,0,ofGetWidth(),ofGetHeight());

    int numUsers = openNIDevice.getNumTrackedUsers();
    string msg = "";

    if (numUsers > 0) {
        ofxOpenNIUser & user = openNIDevice.getTrackedUser(0);
        
        ofxOpenNIJoint leftHand = user.getJoint(JOINT_LEFT_HAND);
        ofxOpenNIJoint rightHand = user.getJoint(JOINT_RIGHT_HAND);
        ofPoint leftHandPos = leftHand.getProjectivePosition();
        ofPoint rightHandPos = rightHand.getProjectivePosition();
        
        msg += "Left Hand: " + ofToString(leftHandPos.x) +","+ ofToString(leftHandPos.y) + ","+ ofToString(leftHandPos.z) +"\n";
        msg += "Right Hand: " + ofToString(rightHandPos.x) +","+ ofToString(rightHandPos.y) + ","+ ofToString(rightHandPos.z) +"\n";
        
        ofSetColor(200,0,0);
        ofDrawCircle(leftHandPos.x * ratioW, leftHandPos.y * ratioH, 30);
        ofSetColor(0, 0, 200);
        ofDrawCircle(rightHandPos.x * ratioW, rightHandPos.y * ratioH, 30);
        
        if (leftHandPos.x != 0) {
            if (ofDist(leftHandPos.x, leftHandPos.y, rightHandPos.x, rightHandPos.y) < 30 ) {
                Ball* ball = new Ball();
                ball->init(ofVec2f(leftHandPos.x * ratioW,leftHandPos.y * ratioH), ofVec2f(ofRandom(-5.0,5.0), ofRandom(-5.0,5.0)), ofRandom(20,50), ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
                balls.push_back(ball);
            }
        }
    }

    ofSetColor(0, 255, 0);
    msg += "MILLIS: " + ofToString(ofGetElapsedTimeMillis()) + " FPS: " + ofToString(ofGetFrameRate()) + " Device FPS: " + ofToString(openNIDevice.getFrameRate());
    verdana.drawString(msg, 20, 44);
    
    for(auto ball:balls) {
        ball->draw();
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
