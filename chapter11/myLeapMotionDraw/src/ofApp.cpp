#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);

    leap.open();

    // keep app receiving data from leap motion even when it's in the background
    leap.setReceiveBackgroundFrames(true);

    cam.setOrientation(ofPoint(-20, 0, 0));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    leap.setupGestures();
    points.clear();
    lineColor = ofColor(255,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){

    hands = leap.getSimpleHands();

    if( leap.isFrameNew() && hands.size() ){
        
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
        
        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
        
        for(int i = 0; i < hands.size(); i++){
            if (hands[i].isLeft == false) {
                ofPoint tip_THUMB = hands[i].fingers[ fingerTypes[0] ].tip;
                ofPoint tip_INDEX = hands[i].fingers[ fingerTypes[1] ].tip;
                
                float dist = ofDist(tip_THUMB.x, tip_THUMB.y, tip_THUMB.z, tip_INDEX.x, tip_INDEX.y, tip_INDEX.z);
                cout << "distance " << dist << endl;
                if (dist < 100) {
                    cout << "add: " << tip_INDEX << endl;
                    points.push_back(tip_INDEX);
                } else {
                    points.clear();
                }
                
            } else {
                ofPoint tip = hands[i].handPos;
                lineColor.r = ofMap(tip.y, -1.0*ofGetHeight(), ofGetHeight(), 0, 255);
            }
            
        }
    }

    leap.markFrameAsOld();
    
    leap.updateGestures();
    if ((leap.iGestures >= 3) && (leap.iGestures <=6)) {
        lineColor.r = ofRandom(100,255);
        lineColor.g = ofRandom(100,255);
        lineColor.b = ofRandom(100,255);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255,255,255);

    cam.begin();

    ofPushMatrix();
    ofRotate(90, 0, 0, 1);
    ofSetColor(20);
    ofDrawGridPlane(800, 20, false);
    ofPopMatrix();

    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};

    for(int i = 0; i < hands.size(); i++){
        bool isLeft        = hands[i].isLeft;
        ofPoint handPos    = hands[i].handPos;
        ofPoint handNormal = hands[i].handNormal;
        
        ofSetColor(0, 0, 255);
        ofDrawSphere(handPos.x, handPos.y, handPos.z, 20);
        ofSetColor(255, 255, 0);
        ofDrawArrow(handPos, handPos + 100*handNormal);
        
        for (int f=0; f<5; f++) {
            ofPoint mcp = hands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
            ofPoint pip = hands[i].fingers[ fingerTypes[f] ].pip;  // proximal
            ofPoint dip = hands[i].fingers[ fingerTypes[f] ].dip;  // distal
            ofPoint tip = hands[i].fingers[ fingerTypes[f] ].tip;  // fingertip
            
            ofSetColor(0, 255, 0);
            ofDrawSphere(mcp.x, mcp.y, mcp.z, 12);
            ofDrawSphere(pip.x, pip.y, pip.z, 12);
            ofDrawSphere(dip.x, dip.y, dip.z, 12);
            ofDrawSphere(tip.x, tip.y, tip.z, 12);
            
            ofSetColor(255, 0, 0);
            ofSetLineWidth(20);
            ofDrawLine(mcp.x, mcp.y, mcp.z, pip.x, pip.y, pip.z);
            ofDrawLine(pip.x, pip.y, pip.z, dip.x, dip.y, dip.z);
            ofDrawLine(dip.x, dip.y, dip.z, tip.x, tip.y, tip.z);
        }
    }

    ofSetColor(lineColor);
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    for(unsigned int i = 1; i < points.size(); i++){
        //find this point and the next point
        ofVec3f thisPoint = points[i-1];
        ofVec3f nextPoint = points[i];

        //get the direction from one to the next.
        //the ribbon should fan out from this direction
        ofVec3f direction = (nextPoint - thisPoint);

        //get the distance from one point to the next
        float distance = direction.length();

        //get the normalized direction. normalized vectors always have a length of one
        //and are really useful for representing directions as opposed to something with length
        ofVec3f unitDirection = direction.getNormalized();

        //find both directions to the left and to the right
        ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
        ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));

        //use the map function to determine the distance.
        //the longer the distance, the narrower the line.
        //this makes it look a bit like brush strokes
        float thickness = ofMap(distance, 0, 60, 20, 2, true);

        //calculate the points to the left and to the right
        //by extending the current point in the direction of left/right by the length
        ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
        ofVec3f rightPoint = thisPoint+toTheRight*thickness;

        //add these points to the triangle strip
        mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
        mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
    }
    //end the shape
    mesh.draw();

    cam.end();
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
