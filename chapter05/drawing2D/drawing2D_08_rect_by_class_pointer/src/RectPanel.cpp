//
//  RectPanel.cpp
//  drawing2D
//
//  Created by Kyoungchin Seo on 2016. 12. 20..
//
//

#include "RectPanel.h"

RectPanel::RectPanel() {
    
}

RectPanel::~RectPanel() {
    
}

void RectPanel::setRectPanel(float x, float y, float w, float h, int r, int g, int b, int a) {
    posX = x;
    posY = y;
    width = w;
    height = h;
    red = r;
    green = g;
    blue = b;
    alpha = a;
}

void RectPanel::draw() {
    ofSetColor(red,green,blue,alpha);
    ofDrawRectangle(posX,posY,width,height);
}
