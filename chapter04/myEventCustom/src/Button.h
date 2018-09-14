//
//  Button.h
//  myEventCustom
//
//  Created by Kyoungchin Seo on 2017. 8. 11..
//
//

#ifndef Button_h
#define Button_h

#include "ofMain.h"
#include "ofEvents.h"

class Button {
public:
    Button();
    ~Button();
    
    void setup(int x, int y, int w, int h, ofColor c);
    void draw();
    
    void mousePressedHandler(ofMouseEventArgs & mouse);
    void mouseReleasedHandler(ofMouseEventArgs & mouse);
    bool isInside(int x, int y);
    
    void mouseDraggedHandler(ofMouseEventArgs & mouse);
    ofColor pickColor(int x, int y);
    
public:
    ofRectangle rect;
    ofColor color;
    
    ofEvent<ofColor> selectedColor;
};

#endif /* Button_h */
