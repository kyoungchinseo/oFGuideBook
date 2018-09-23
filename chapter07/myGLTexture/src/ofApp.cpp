#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(10, 10, 10);
    ofEnableDepthTest();
    
    texWidth = 320;
    texHeight= 320;
    
    angle = 0.0;
    
    pixelMap.allocate(texWidth,texHeight,OF_PIXELS_RGB);
    for(int i=0;i<texHeight;i++) {
        for(int j=0;j<texWidth;j++) {
            float r = 127.0*(1+sin(j*pi/texWidth));
            float g = 127.0*(1+cos(i*pi/texHeight));
            float b = 127.0*(1+sin((i+j)*pi/texHeight));
            pixelMap.setColor(i,j, ofColor(r,g,b));
        }
    }
    textureFromPixelMap.allocate(pixelMap);
    
    
    image.load("of.png");
    textureFromImage.allocate(image.getPixels());
    
    
    video.load("fingers.mov");
    video.play();
    textureFromVideo.allocate(video.getWidth(),video.getHeight(),GL_RGBA);
    
    
    camera.setDeviceID(0); //
    camera.initGrabber(texWidth, texHeight);
    camera.setDesiredFrameRate(60);
    
    indexPatches.clear();
    for(int i=0;i<48;i++) {
        indexPatches.push_back((int)ofRandom(0,4));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    if (video.isFrameNew()) {
        textureFromVideo.loadData(video.getPixels());
    }
    
    camera.update();
    if (camera.isFrameNew()) {
        textureFromCamera.loadData(camera.getPixels());
    }
    
    //angle += 0.5;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,255,255);
  
    //drawCubes();
    drawTexturePatches();
}

void ofApp::drawCubes() {
     ofPushMatrix();
     ofTranslate(ofGetWidth()/4,ofGetHeight()/4,0);
     ofRotate(angle, 1.0, 1.0, 1.0);
     ofEnableNormalizedTexCoords();
     textureFromPixelMap.bind();
     ofDrawBox(0, 0, 0, 200, 200, 200);
     textureFromPixelMap.unbind();
     ofDisableNormalizedTexCoords();
     ofPopMatrix();
     
     ofPushMatrix();
     ofTranslate(ofGetWidth()/4*3,ofGetHeight()/4,0);
     ofRotate(angle, 1.0, 1.0, 1.0);
     ofEnableNormalizedTexCoords();
     textureFromImage.bind();
     ofDrawBox(0, 0, 0, 200, 200, 200);
     textureFromImage.unbind();
     ofDisableNormalizedTexCoords();
     ofPopMatrix();
     
     ofPushMatrix();
     ofTranslate(ofGetWidth()/4,ofGetHeight()/4*3,0);
     ofRotate(angle, 1.0, 1.0, 1.0);
     ofEnableNormalizedTexCoords();
     textureFromVideo.bind();
     ofDrawBox(0, 0, 0, 200, 200, 200);
     textureFromVideo.unbind();
     ofDisableNormalizedTexCoords();
     ofPopMatrix();
     
     ofPushMatrix();
     ofTranslate(ofGetWidth()/4*3,ofGetHeight()/4*3,0);
     ofRotate(angle, 1.0, 1.0, 1.0);
     ofEnableNormalizedTexCoords();
     textureFromCamera.bind();
     ofDrawBox(0, 0, 0, 200, 200, 200);
     textureFromCamera.unbind();
     ofDisableNormalizedTexCoords();
     ofPopMatrix();
}

void ofApp::drawTexturePatches() {
    for(int i=0;i<6;i++) {
        for(int j=0;j<8;j++) {
            ofPushMatrix();
            ofTranslate(j*ofGetWidth()/8 + ofGetWidth()/16, i*ofGetHeight()/6 + ofGetHeight()/12);
            switch(indexPatches[i*8+j]) {
                case 0:
                    ofEnableNormalizedTexCoords();
                    textureFromPixelMap.bind();
                    ofRotate(angle,0.0,0.0,1.0);
                    ofDrawPlane(0, 0, 0, ofGetWidth()/8, ofGetHeight()/6);
                    textureFromPixelMap.unbind();
                    ofDisableNormalizedTexCoords();
                    break;
                case 1:
                    ofEnableNormalizedTexCoords();
                    textureFromImage.bind();
                    ofRotate(angle,0.0,0.0,1.0);
                    ofDrawPlane(0, 0, 0, ofGetWidth()/8, ofGetHeight()/6);
                    textureFromImage.unbind();
                    ofDisableNormalizedTexCoords();
                    break;
                case 2:
                    ofEnableNormalizedTexCoords();
                    textureFromVideo.bind();
                    ofRotate(angle,0.0,0.0,1.0);
                    ofDrawPlane(0, 0, 0, ofGetWidth()/8, ofGetHeight()/6);
                    textureFromVideo.unbind();
                    ofDisableNormalizedTexCoords();
                    break;
                case 3:
                    ofEnableNormalizedTexCoords();
                    textureFromCamera.bind();
                    ofRotate(angle,0.0,0.0,1.0);
                    ofDrawPlane(0, 0, 0, ofGetWidth()/8, ofGetHeight()/6);
                    textureFromCamera.unbind();
                    ofDisableNormalizedTexCoords();
                    break;
            }
            
            ofPopMatrix();
        }
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

