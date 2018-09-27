//
//  FontText.h
//  myFirstClass
//
//  Created by Kyoungchin Seo on 2017. 6. 1..
//
//

#ifndef FontText_h
#define FontText_h

#include "ofMain.h"

class FontText {
public:
    FontText();
    ~FontText();
    
    void setup(string fontFile, int fontSize);
    void setPosition(int x, int y);
    void setColor(ofColor fontColor);
    void setMessage(string textMessage);
    void draw();
    
public:
    ofPoint position;
    ofColor color;
    string  message;
    ofTrueTypeFont font;
};


#endif /* FontText_h */
