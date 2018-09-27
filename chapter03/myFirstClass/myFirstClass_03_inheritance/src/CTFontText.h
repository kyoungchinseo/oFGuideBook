//
//  CTFontText.h
//  myFirstClass
//
//  Created by Kyoungchin Seo on 2017. 6. 5..
//
//

#ifndef CTFontText_h
#define CTFontText_h

#include "ofMain.h"
#include "FontText.h"

class CTFontText : public FontText {
public:
    CTFontText();
    ~CTFontText();
    
    void setMinAlpha(float value);
    void setMaxAlpha(float value);
    void setStep(float value);
    void update();
    void draw();
    
public:
    float minAlpha;
    float maxAlpha;
    float step;
    float angle;
    float alpha;
    
};


#endif /* CTFontText_h */
