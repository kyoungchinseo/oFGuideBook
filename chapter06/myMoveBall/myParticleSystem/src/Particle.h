//
//  Particle.h
//  myParticleSystem
//
//  Created by Kyoungchin Seo on 2017. 8. 29..
//
//

#ifndef Particle_h
#define Particle_h

#include "ofMain.h"

class Particle {
public:
    Particle();
    ~Particle();
    void setup(ofVec2f l, ofVec2f v, ofVec2f a, ofColor c, float r, float lf);
    void update();
    void draw();
    bool isAlive();
public:
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofColor color;
    float radius;
    float lifeSpan;
    float lifeLeft;
    bool bAlive;
};

#endif /* Particle_h */
