//
//  CTFontText.cpp
//  myFirstClass
//
//  Created by Kyoungchin Seo on 2017. 6. 5..
//
//

#include <stdio.h>
#include "CTFontText.h"

CTFontText::CTFontText() {
    
}

CTFontText::~CTFontText() {
    
}

void CTFontText::setMinAlpha(float value) {
    minAlpha = value;
}

void CTFontText::setMaxAlpha(float value) {
    maxAlpha = value;
}

void CTFontText::setStep(float value) {
    step = value;
}

void CTFontText::update() {
    angle += step;
    alpha = (maxAlpha - minAlpha) * (cos(angle) + 1.0)/2.0 + minAlpha;
}

void CTFontText::draw() {
    ofSetColor(color, alpha);
    font.drawString(message, position.x, position.y);
}
