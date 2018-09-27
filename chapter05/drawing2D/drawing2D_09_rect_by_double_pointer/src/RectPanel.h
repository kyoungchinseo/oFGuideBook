//
//  RectPanel.h
//  drawing2D
//
//  Created by Kyoungchin Seo on 2016. 12. 20..
//
//

#ifndef RectPanel_h
#define RectPanel_h

#include "ofMain.h"

class RectPanel {
public:
    RectPanel();
    ~RectPanel();
    
    void setRectPanel(float x, float y, float w, float h, int r, int g, int b, int a);
    void draw();
public:
    float posX;
    float posY;
    float width;
    float height;
    
    int red;
    int green;
    int blue;
    int alpha;
};

#endif /* RectPanel_h */
