//
//  MovingBall.h
//  myMoveBalls
//
//  Created by Kyoungchin Seo on 2017. 8. 17..
//
//

#ifndef MovingBall_h
#define MovingBall_h

#include "ofMain.h"

class MovingBall {
public:
    MovingBall();
    ~MovingBall();
    
    void setup(ofVec2f l, ofVec2f v, ofColor c, float r);
    void update();
    void draw();
    void checkBoundary();
    
public:
    ofVec2f location;
    ofVec2f velocity;

    float radius;
    ofColor color;
};


#endif /* MovingBall_h */
