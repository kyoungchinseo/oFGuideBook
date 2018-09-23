#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    int planeWidth = ofGetWidth();
    int planeHeight = ofGetHeight();
    int planeGridSize = 20;
    int planeColumns = planeWidth / planeGridSize;
    int planeRows = planeHeight / planeGridSize;
    
    
    colorShader.load("color.vert","color.frag");
    colorPlane.set(planeWidth,planeHeight,planeColumns,planeRows,OF_PRIMITIVE_TRIANGLES);
    
    textureShader.load("texture.vert","texture.frag");
    textureImage.load("bg-rainbow.jpg");
    texturePlane.set(planeWidth,planeHeight,planeColumns,planeRows,OF_PRIMITIVE_TRIANGLES);
    texturePlane.mapTexCoords(0, 0, textureImage.getWidth(), textureImage.getHeight());

    rippleShader.load("ripple.vert","ripple.frag");
    rippleImage.load("bg-ripple.jpg");
    ripplePlane.set(planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES);
    ripplePlane.mapTexCoords(0, 0, rippleImage.getWidth(), rippleImage.getHeight());

    camDispShader.load("camDisp.vert","camDisp.frag");
    camera.setDeviceID(0);
    camera.setDesiredFrameRate(30);
    camera.initGrabber(640, 480);
    camDispImage.allocate(640, 480, OF_IMAGE_COLOR);
    camDispPlane.set(planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES);
    camDispPlane.mapTexCoords(0, 0, 640, 480);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    if (camera.isFrameNew()) {
        ofPixels & pixels = camera.getPixels();
        camDispImage.setFromPixels(pixels);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0,0,0);
    
    colorShader.begin();
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2,0);
        colorPlane.drawFaces();
    ofPopMatrix();
    colorShader.end();

    textureShader.begin();
    textureShader.setUniformTexture("texture", textureImage,0);
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2,0);
        ofScale(0.8,0.8,0.8);
        texturePlane.drawFaces();
    ofPopMatrix();
    textureShader.end();

    rippleShader.begin();
    rippleShader.setUniform1f("time", ofGetElapsedTimef());
    rippleShader.setUniformTexture("texure", rippleImage, 0);
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2,1);
        ofScale(0.6,0.6,0.6);
        ripplePlane.drawFaces();
    ofPopMatrix();
    rippleShader.end();

    camDispShader.begin();
    camDispShader.setUniform1f("time",ofGetElapsedTimef());
    camDispShader.setUniformTexture("video", camDispImage, 0);
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2,1);
        ofScale(0.4,0.4,0.4);
        camDispPlane.drawFaces();
    ofPopMatrix();
    camDispShader.end();

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
