//
//  FontText.cpp
//  myFirstClass
//
//  Created by Kyoungchin Seo on 2017. 6. 1..
//
//

#include <stdio.h>

#include "FontText.h"


FontText::FontText() {
    
}

FontText::~FontText() {
    
}

void FontText::setup(string fontFile, int fontSize) {
    font.load(fontFile,fontSize);
}

void FontText::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}

void FontText::setColor(ofColor fontColor) {
    color = fontColor;
}

void FontText::setMessage(string textMessage){
    message = textMessage;
}

void FontText::draw() {
    ofSetColor(color);
    font.drawString(message, position.x, position.y);
}
