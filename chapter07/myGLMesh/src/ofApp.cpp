#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gridX = 50;
    gridY = 50;
    
    for(int i=0;i<gridY;i++) {
        for(int j=0;j<gridX;j++) {
            mesh.addVertex(ofVec3f((gridX/2-j)*40.0f,(gridY/2-i)*30.0f,0.0f));
            mesh.addColor(ofColor(255*ofMap(j, 0, gridX, 0.0, 1.0),255*ofMap(i, 0, gridY, 0.0, 1.0),0));
        }
    }
    
    for(int i=0;i<gridY-1;i++) {
        for(int j=0;j<gridX-1;j++) {
            mesh.addIndex(i*gridX+j);
            mesh.addIndex(i*gridX+j+1);
            mesh.addIndex((i+1)*gridX+j);
            
            mesh.addIndex(i*gridX+j+1);
            mesh.addIndex((i+1)*gridX+j+1);
            mesh.addIndex((i+1)*gridX+j);
        }
    }
    
    light.setPointLight();
    light.setPosition(150,150,100);
    
    ofEnableDepthTest();
    ofEnableSmoothing();
    
    angle = 0.0;
    model.loadModel("sample.obj");
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<gridY;i++) {
        for(int j=0;j<gridX;j++) {
            mesh.setVertex(i*gridX+j, ofVec3f((gridX/2-j)*40.0f,(gridY/2-i)*30.0f,
                                              20*cos(j+ofGetElapsedTimef()*2.0) ));
        }
    }
    
    angle += 1.0;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(50, 50, 50, 0);
    ofSetColor(255, 255, 255, 255);
    
    ofEnableLighting();
    light.enable();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofRotate(60.0f, 1.0f, 0.0f, 0.0f);
    
    mesh.drawFaces();
    mesh.drawWireframe();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, (float)ofGetHeight()/3 , 100.0f);
    ofRotate(angle, 0.0f, 1.0f, 0.0f);
    ofScale(0.5,0.5,0.5);
    model.drawFaces();
    //model.drawWireframe();
    ofPopMatrix();
    
    
    light.disable();
    
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
