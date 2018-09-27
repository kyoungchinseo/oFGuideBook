//
//  ParticleSystem.h
//  myParticleSystem
//
//  Created by Kyoungchin Seo on 2017. 8. 29..
//
//

#ifndef ParticleSystem_h
#define ParticleSystem_h

#include "ofMain.h"
#include "Particle.h"

class ParticleSystem {
public:
    ParticleSystem();
    ~ParticleSystem();
    void setup(int n, ofVec2f o);
    void update();
    void draw();
    void addParticle();
    
public:
    int numOfParticles;
    ofVec2f origin;
    vector<Particle*> particles;
};


#endif /* ParticleSystem_h */
