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

void MovingBall::reset() {
    location = ofVec2f(ofRandom(0,ofGetWidth()),ofRandom(-200.0f, -20.0f));
    velocity = ofVec2f(ofRandom(-3.5f,3.5f),ofRandom(0.0f,3.5f));
    acceleration = ofVec2f(0.0,0.0);
    color = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
    radius = ofRandom(20,50);
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

void MovingBall::checkPass() {
    if ((location.x + radius) > ofGetWidth() ) {
        location.x = -radius;
        reset();
    }
    if ((location.y + radius) > ofGetHeight()) {
        location.y = -radius;
        reset();
    }
}

void MovingBall::applyForce(ofVec2f force) {
    acceleration = force;
    //update();
}

void MovingBall::applyAttraction(ofVec2f force, ofVec2f pos) {
    ofVec2f f = pos - location;
    float distance = f.length();
    if (distance < 10) {
        distance = 10;
    }
    f = f.normalize();
    f = f * force;
    acceleration = f * ofGetWidth()/distance;
    
    //update();
}
