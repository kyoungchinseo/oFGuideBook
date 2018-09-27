//
//  Particle.cpp
//  myParticleSystem
//
//  Created by Kyoungchin Seo on 2017. 8. 29..
//
//

#include "Particle.h"

Particle::Particle() {
    
}

Particle::~Particle() {
    
}

void Particle::setup(ofVec2f l, ofVec2f v, ofVec2f a, ofColor c, float r, float lf) {
    location = l;
    velocity = v;
    acceleration = a;
    color = c;
    radius = r;
    lifeSpan = lf;
    lifeLeft = lf;
    bAlive = true;
}

void Particle::update() {
    velocity += acceleration;
    location += velocity;
    lifeLeft -= 2;
    if (lifeLeft > 0) {
        bAlive = true;
    } else {
        bAlive = false;
    }
}

void Particle::draw() {
    if (bAlive == true) {
        ofSetColor(color,100*lifeLeft/lifeSpan);
    } else {
        ofSetColor(color,0);
    }
    ofDrawCircle(location, radius);
}

bool Particle::isAlive() {
    if (bAlive) {
        return true;
    } else {
        return false;
    }
}
