//
//  Ball.h
//  myKinectSkeleton
//
//  Created by Kyoungchin SeO on 2018. 8. 1..
//

#ifndef Ball_h
#define Ball_h

#include "ofMain.h"

class Ball {
public:
    Ball() {}
    ~Ball() {}
    
    void init(ofVec2f l,ofVec2f v,float r, ofColor c) {
        location = l;
        velocity = v;
        radius = r;
        color = c;
    }
    
    void update() {
        location += velocity;
    }
    
    void draw() {
        ofFill();
        ofSetColor(color);
        ofDrawCircle(location, radius);
    }
    
    void checkBoundary() {
        if ((location.x - radius < 0) || (location.x + radius > ofGetWidth())) {
            velocity.x *= -1.0;
        }
        if ((location.y - radius < 0) || (location.y + radius > ofGetHeight())){
            velocity.y *= -1.0;
        }
    }
    
    
public:
    ofVec2f location;
    ofVec2f velocity;
    float   radius;
    ofColor color;
    
};

#endif /* Ball_h */
