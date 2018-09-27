//
//  MovingBall.cpp
//  myMoveBalls
//
//  Created by Kyoungchin Seo on 2017. 8. 28..
//
//

#include "MovingBall.h"


MovingBall::MovingBall() {
    
}

MovingBall::~MovingBall() {
    
}

void MovingBall::setup(ofVec2f l, ofVec2f v, ofVec2f a, ofColor c, float r)
{
    location = l;
    velocity = v;
    acceleration = a;
    color = c;
    radius = r;
}

void MovingBall::update() {
    velocity += acceleration;
    location += velocity;
}

void MovingBall::draw() {
    ofSetColor(color);
    ofDrawCircle(location, radius);
}

void MovingBall::drawTrail() {
    ofNoFill();
    ofSetColor(color);
    ofDrawCircle(location, radius);
}

void MovingBall::checkBoundary() {
    if ((location.x - radius < 0) || (location.x + radius > ofGetWidth())) {
        velocity.x *= -1.0;
    }
    if ((location.y - radius < 0) || (location.y + radius > ofGetHeight())){
        velocity.y *= -1.0;
    }
}

void MovingBall::applyForce(ofVec2f force) {
    acceleration = force;
    //update();
}

