#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    Do.load("do.wav");
    Re.load("re.wav");
    Mi.load("mi.wav");
    Fa.load("fa.wav");
    Sol.load("sol.wav");

    bPressed = false;
    key = 100;
    
    //soundInput.setup(0, 2, 44100, 256, 4);
    soundInput.setup(this,0, 2, 44100, 256, 4);
    //å®soundInput.set
}

//--------------------------------------------------------------
void ofApp::update(){
    if (volume > 0.1) {
        if (!Do.isPlaying() && !Mi.isPlaying() && !Sol.isPlaying()) {
            Do.play();
            Mi.play();
            Sol.play();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(120, 120, 120);
    //ofSoundGetSpectrum(<#int nBands#>) // FFT
    // 0.8.4 >> sound 관련 코드 보고 예제 선택하기

    //sound file 다운로드 받기
    //https://freesound.org/people/Jaz_the_MAN_2/sounds/316899/

    for(int i=0;i<5;i++) {
        ofSetColor(255, 255, 255);
        
        if ((bPressed == true) && (key == i)) {
            ofSetColor(255, 0, 0);
            ofFill();
            ofDrawRectRounded(ofGetWidth()/7*i+ofGetWidth()/7,
                              ofGetHeight()/8,
                              ofGetWidth()/7,
                              ofGetHeight()/2,
                              20);
            
        }
        
        ofNoFill();
        ofSetColor(255, 255, 255);
        ofSetLineWidth(4);
        ofDrawRectRounded(ofGetWidth()/7*i+ofGetWidth()/7,
                          ofGetHeight()/8,
                          ofGetWidth()/7,
                          ofGetHeight()/2,
                          20);
    }
}

// https://openframeworks.cc/documentation/sound/ofSoundStream/
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    float left, right;
    volume = 0.0;
    for (int i = 0; i < bufferSize; i++){
        left     = input[i*2]*0.5;
        right    = input[i*2+1]*0.5;
        
        volume += left * left;
        volume += right * right;
    }
    
    volume = sqrt(volume / (bufferSize * 2));
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
    key = checkPressedKey(x, y);
    bPressed = true;
}

int ofApp::checkPressedKey(int x, int y) {
    
    int key = 1000;
    
    for(int i=0;i<5;i++) {
        int lB = ofGetWidth()/7*i + ofGetWidth()/7;
        int rB = lB + ofGetWidth()/7;
        int tB = ofGetWidth()/8;
        int bB = ofGetWidth()/8 + ofGetHeight()/2;
        if (( x > lB ) && ( x < rB )) {
            if (( y > tB ) && ( y < bB )) {
                key = i;
                return key;
            }
        }
    }
    return  key;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    key = checkPressedKey(x, y);
    switch(key) {
        case 0:
            Do.play();
            break;
        case 1:
            Re.play();
            break;
        case 2:
            Mi.play();
            break;
        case 3:
            Fa.play();
            break;
        case 4:
            Sol.play();
            break;
        default:
            
            break;
    }
    bPressed = false;
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
