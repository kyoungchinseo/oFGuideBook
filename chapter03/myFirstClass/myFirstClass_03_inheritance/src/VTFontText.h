//
//  VTFontText.h
//  myFirstClass
//
//  Created by Kyoungchin Seo on 2017. 6. 5..
//
//

#ifndef VTFontText_h
#define VTFontText_h

#include "ofMain.h"
#include "FontText.h"

class VTFontText: public FontText {
public:
    VTFontText();
    ~VTFontText();
    
    void setMaxAmplitude(float value);
    void setStep(float value);
    void update();
    void draw();
    
public:
    float maxAmplitude;
    float step;
    float angle;
    float vertTrans;
};

#endif /* VTFontText_h */
