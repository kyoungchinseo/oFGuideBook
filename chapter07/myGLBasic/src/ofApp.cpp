#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    radius = 50;
    rotation = 0;
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    ofEnableDepthTest();
    
    ofSetSmoothLighting(true);
    ofSetSphereResolution(64);
    
    material.setDiffuseColor(ofColor(255,255,255));
    material.setSpecularColor(ofColor(255.0,255.0,255.0));
    material.setShininess( 64 );
    
    light.setDiffuseColor(ofColor(255.0,255.0,255.0));
    light.setSpecularColor(ofColor(255.0,255.0,255.0));
    light.setPointLight();
    
    lightPosition.set(ofVec3f(ofGetWidth()/2,ofGetHeight()/2,400));
    
    camCenter.set(ofGetWidth()/2,ofGetHeight()/2,0.0);
    camPosition = camCenter;
    camPosition.z += 800.0;
    camera.setPosition(camPosition);
    camera.lookAt(camCenter);
    
    textureImage.load("of.png");
    textureMap.loadData(textureImage.getPixels(),GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update(){
    light.setPosition(lightPosition);
    camera.setPosition(camPosition);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    camera.begin();
    
    ofEnableLighting();
    light.enable();
    material.begin();
    
    ofEnableNormalizedTexCoords();
    textureMap.bind();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,0.0,0.0);
    ofRotate(rotation, 0.0, 1.0, 0.0);
    ofTranslate(-ofGetWidth()/2,0.0,0.0);
    for (int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            float x = ofGetWidth() / 5 + ofGetWidth()/5*j;
            float y = ofGetHeight() / 5 + ofGetHeight()/5*i;
            ofDrawSphere(x,y, 0, radius);
        }
    }
    ofPopMatrix();
    
    textureMap.unbind();
    ofDisableNormalizedTexCoords();
    
    material.end();
    light.disable();
    ofDisableLighting();
    
    camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'r') {
        rotation = rotation + 10.0;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    lightPosition.x = x;
    lightPosition.y = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    camPosition.x = x;
    camPosition.y = y;
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
