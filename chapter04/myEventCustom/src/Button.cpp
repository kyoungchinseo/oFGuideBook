//
//  Button.cpp
//  myEventCustom
//
//  Created by Kyoungchin Seo on 2017. 8. 11..
//
//

#include "Button.h"

Button::Button() {
    
}

Button::~Button() {
    ofRemoveListener(ofEvents().mousePressed, this, &Button::mousePressedHandler);
    ofRemoveListener(ofEvents().mouseReleased, this, &Button::mouseReleasedHandler);
    
    ofRemoveListener(ofEvents().mouseDragged, this, &Button::mouseDraggedHandler);
}

void Button::setup(int x, int y, int w, int h, ofColor c) {
    rect.set(x,y,w,h);
    color = c;
    
    ofAddListener(ofEvents().mousePressed, this, &Button::mousePressedHandler);
    ofAddListener(ofEvents().mouseReleased, this, &Button::mouseReleasedHandler);
    
    ofAddListener(ofEvents().mouseDragged, this, &Button::mouseDraggedHandler);
}

void Button::draw() {
    ofSetColor(color);
    ofDrawRectangle(rect);
}

bool Button::isInside(int x, int y) {
    if ((x > rect.x) && ( x < rect.x + rect.getWidth())) {
        if ((y > rect.y) && ( y < rect.y + rect.getHeight())) {
            return true;
        }
    }
    return false;
}

void Button::mousePressedHandler(ofMouseEventArgs & mouse) {
    if (isInside(mouse.x, mouse.y) == true) {
        color = ofColor(80,80,80);
    }
}

void Button::mouseReleasedHandler(ofMouseEventArgs & mouse) {
    if (isInside(mouse.x, mouse.y) == true) {
        color = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
    }
    
}

void Button::mouseDraggedHandler(ofMouseEventArgs & mouse) {
    if (isInside(mouse.x, mouse.y) == true) {
        ofColor picked = pickColor(mouse.x,mouse.y);
        ofNotifyEvent(selectedColor, picked, this);
    }
}

ofColor Button::pickColor(int x, int y) {
    float r = (x - rect.x)/rect.width * 255.0;
    float g = (y - rect.y)/rect.height * 255.0;
    return ofColor(r,g,0);
}
