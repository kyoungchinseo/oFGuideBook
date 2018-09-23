//
//  Ball.h
//  myUDPClient
//
//  Created by Kyoungchin SeO on 2018. 6. 4..
//

#ifndef Ball_h
#define Ball_h



#include "ofMain.h"

class Ball {
public:
    Ball() {}
    ~Ball() {}
    
    void init(string msg) {
        vector<string> message = ofSplitString(msg," ");
        location.x = ofToFloat(message[0]) - ofGetWidth();
        location.y = ofToFloat(message[1]);
        radius = ofToFloat(message[2]);
        color.r = ofToInt(message[3]);
        color.g = ofToInt(message[4]);
        color.b = ofToInt(message[5]);
    }
    
    void draw() {
        ofFill();
        ofSetColor(color);
        ofDrawCircle(location, radius);
    }
    
public:
    ofVec2f location;
    float   radius;
    ofColor color;
    
};

#endif /* Ball_h */
