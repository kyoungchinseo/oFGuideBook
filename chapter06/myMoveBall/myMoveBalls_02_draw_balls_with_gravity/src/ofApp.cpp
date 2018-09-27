#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i=0;i<20;i++) {
        MovingBall *ball;
        ball = new MovingBall();
        ball->setup(ofVec2f(ofRandom(ofGetWidth()*0.25,ofGetWidth()*0.75),
                            ofRandom(ofGetHeight()*0.25,ofGetHeight()*0.75)),
                    ofVec2f(ofRandom(-5.5f, 5.5f),ofRandom(-5.5f, 5.5f)),
                    ofVec2f(0.0,0.0),
                    ofColor(ofRandom(0.0,255.0),ofRandom(0.0,255.0),ofRandom(0.0,255.0)),
                    ofRandom(30,50));
        balls.push_back(ball);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(auto b : balls) {
        b->checkBoundary();
        b->applyForce(ofVec2f(0.0,0.3));
        b->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(auto b : balls) {
        b->draw();
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
