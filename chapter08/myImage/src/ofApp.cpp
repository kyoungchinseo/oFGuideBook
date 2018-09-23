#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    centerX = ofGetWidth()/4.0;
    centerY = ofGetHeight()/4.0;
    
    image.load("earth.jpg");
    
    alpha = 128;
    
    distort.allocate(image.getWidth(), image.getHeight(),OF_IMAGE_COLOR_ALPHA);
    
    opencvImage.allocate(image.getWidth(), image.getHeight());
    opencvImage.setFromPixels(image.getPixels());
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    
    for (int i=0; i<image.getHeight(); i++) {
        for (int j=0; j<image.getWidth(); j++) {
            float amp = sin( i * 0.01 );
            int x = j + sin( time * 2.0 ) * amp * 30.0;
            
            x = ofClamp( x, 0, image.getWidth() - 1 );
            
            ofColor color = image.getColor( x, i );
            distort.setColor( j, i, color );
        }
    }
    distort.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    
    ofSetColor(255, 255, 255);
    image.draw(centerX - 160, centerY - 160, 320,320);
    
    ofSetColor(255, 255, 255, alpha);
    image.draw(centerX * 3 - 160, centerY - 160, 320,320);

    ofSetColor(255,255,255,255);
    distort.draw(centerX - 160, centerY*3 - 160, 320,320);

    opencvImage.draw(centerX * 3 - 160, centerY*3 - 160, 320, 320);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == OF_KEY_UP) {
        alpha += 5;
        alpha = ofClamp(alpha, 0, 255);
    }
    if (key == OF_KEY_DOWN) {
        alpha -=5;
        alpha = ofClamp(alpha, 0, 255);
    }
    if (key == 'b') {
        opencvImage.blurGaussian();
    }
    if (key == 'h') {
        opencvImage.mirror(true, false);
    }
    if (key == 'v') {
        opencvImage.mirror(false,true);
    }
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
