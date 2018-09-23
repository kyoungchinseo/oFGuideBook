#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    width = 640;
    height= 480;
    
    video.load("sample.mov");
    video.play();
    
    camera.setDeviceID(0);
    camera.setDesiredFrameRate(30);
    camera.initGrabber(width, height);
    
    videoCapture.allocate(width, height);
    cameraCapture.allocate(width, height);
    
    cameraGray.allocate(width, height);
    cameraGrayPrev.allocate(width, height);
    cameraGrayDiff.allocate(width, height);
    
    videoGray.allocate(width, height);
    videoGrayPrev.allocate(width, height);
    videoGrayDiff.allocate(width, height);
    
    
    ratioW = ofGetWindowWidth() / (float)width;
    ratioH = ofGetWindowHeight() / (float)height;
    
    weightOne = 40;
    weightTwo = 4;
    
    ofSetCircleResolution(64);
    
    // file download:
    // https://github.com/opencv/opencv/tree/master/data/haarcascades
    
    faceFinder.setup("haarcascade_frontalface_default.xml");
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    camera.update();
    
    if (video.isFrameNew()) {
        videoCapture.setFromPixels(video.getPixels());
        videoGray = videoCapture;
        videoGrayDiff.absDiff(videoGray, videoGrayPrev);
        videoGrayDiff.threshold(weightOne);
        contourVideo.findContours(videoGrayDiff, 10, 400, 300, true);
        
        videoGrayDiff.blurHeavily();
        videoGrayPrev = videoGray;
    }
    
    if (camera.isFrameNew()) {
        cameraCapture.setFromPixels(camera.getPixels());
        cameraGray = cameraCapture;
        cameraGrayDiff.absDiff(cameraGray, cameraGrayPrev);
        cameraGrayDiff.threshold(80);
        contourCamera.findContours(cameraGrayDiff, 10, 400, 300, true);
        faceFinder.findHaarObjects(cameraGray);
        cameraGrayPrev = cameraGray;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    int w = 320;
    int h = 240;
    
//    ofSetColor(255, 255, 255);
//    //video.draw(0, 0, ofGetWidth(), ofGetHeight());
//    videoCapture.draw(0, 0, ofGetWidth(), ofGetHeight());
//
//    ofSetColor(255, 255, 255);
//    //camera.draw(ofGetWidth() -w, ofGetHeight()-h, w, h);
//    cameraCapture.draw(ofGetWidth()- w, ofGetHeight()-h, w, h);
    
    ofSetColor(255, 255, 255);
    //video.draw(0, 0, ofGetWidth(), ofGetHeight());
    //videoCapture.draw(0, 0, ofGetWidth(), ofGetHeight());
    videoGrayDiff.draw(0, 0, ofGetWidth(), ofGetHeight());
    

    ofSetColor(255,255,255);
    //camera.draw(0, 0, ofGetWidth(), ofGetHeight());
    //cameraCapture.draw(ofGetWidth()-w, ofGetHeight()-h, w, h);
    cameraGrayDiff.draw(ofGetWidth()- w, ofGetHeight()- h, w, h);
    
    
    for(int i=0;i<contourVideo.nBlobs;i++) {
        int j;
        ofSetColor(0,255,255);
        for(j=0;j<contourVideo.blobs[i].nPts-1;j++) {
            ofDrawLine(contourVideo.blobs[i].pts[j].x*ratioW,contourVideo.blobs[i].pts[j].y*ratioH,
                       contourVideo.blobs[i].pts[j+1].x*ratioW,contourVideo.blobs[i].pts[j+1].y*ratioH);
        }
        ofDrawLine(contourVideo.blobs[i].pts[j].x*ratioW,contourVideo.blobs[i].pts[j].y*ratioH,
                   contourVideo.blobs[i].pts[0].x*ratioW,contourVideo.blobs[i].pts[0].y*ratioH);
        
        ofSetColor(255, 0, 255);
        ofNoFill();
        ofDrawCircle(contourVideo.blobs[i].centroid.x * ratioW,
                     contourVideo.blobs[i].centroid.y * ratioH,
                     weightTwo);

    }

    for(int i=0;i<contourCamera.nBlobs;i++) {
        ofSetColor(255, 255, 0);
        ofFill();
        ofDrawCircle(contourCamera.blobs[i].centroid.x * ratioW,
                     contourCamera.blobs[i].centroid.y * ratioH,
                     weightTwo);
    }

    if (faceFinder.blobs.size()>0) {
        weightOne = ofMap(faceFinder.blobs[0].centroid.x, 0, width, 20.0, 120.0);
        weightTwo = ofMap(faceFinder.blobs[0].centroid.x, 0, width, 30.0, 90.0);
    } else {
        weightOne = 40.0;
        weightTwo = 30.0;
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
