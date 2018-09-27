//
//  MovingBall.h
//  myMoveBalls
//
//  Created by Kyoungchin Seo on 2017. 8. 28..
//
//

#ifndef MovingBall_h
#define MovingBall_h

#include "ofMain.h"

class MovingBall {
public:
    MovingBall();
    ~MovingBall();
    
    void setup(ofVec2f l, ofVec2f v, ofVec2f a, ofColor c, float r);
    void reset();
    void update();
    void draw();
    void drawTrail();
    void checkBoundary();
    void checkPass();
    void applyForce(ofVec2f force);
    void applyAttraction(ofVec2f force, ofVec2f pos);
    
public:
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    
    float radius;
    ofColor color;
};

#endif /* MovingBall_h */
