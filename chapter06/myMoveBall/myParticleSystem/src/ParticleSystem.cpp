//
//  ParticleSystem.cpp
//  myParticleSystem
//
//  Created by Kyoungchin Seo on 2017. 8. 29..
//
//

#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
    
}

ParticleSystem::~ParticleSystem() {
    
}

void ParticleSystem::setup(int n, ofVec2f o) {
    numOfParticles = n;
    origin = o;
}

void ParticleSystem::update() {
    addParticle();
    for(auto d: particles) {
        d->update();
    }
    
    for(auto it = particles.begin(); it!= particles.end();++it) {
        if ((*it)->isAlive() == false) {
            it = particles.erase(it);
        }
    }
}

void ParticleSystem::draw() {
    for(auto d: particles) {
        d->draw();
    }
}

void ParticleSystem::addParticle() {
    Particle *particle = new Particle();
    particle->setup(origin,
                    ofVec2f(ofRandom(-5.0f, 5.0f),ofRandom(-5.0f,5.0f)),
                    ofVec2f(0.0,0.1),
                    ofColor(0,0,0),
                    10.0,
                    300);
    particles.push_back(particle);
}
