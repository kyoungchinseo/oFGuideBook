//
//  VTFontText.cpp
//  myFirstClass
//
//  Created by Kyoungchin Seo on 2017. 6. 5..
//
//

#include <stdio.h>

#include "VTFontText.h"

VTFontText::VTFontText() {
    
}

VTFontText::~VTFontText() {
    
}

void VTFontText::setMaxAmplitude(float value) {
    maxAmplitude = value;
}

void VTFontText::setStep(float value) {
    step = value;
}

void VTFontText::update() {
    angle += step;
    vertTrans = maxAmplitude * cos(angle);
}

void VTFontText::draw() {
    ofSetColor(color);
    ofPushMatrix();
    ofTranslate(0, vertTrans);
    font.drawString(message, position.x, position.y);
    ofPopMatrix();
}
