#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

public:
    ofPoint upperLeft;
    ofPoint upperRight;
    ofPoint lowerLeft;
    ofPoint lowerRight;
    
    string upperLeftMessage;
    string upperRightMessage;
    string lowerLeftMessage;
    string lowerRightMessage;
    
    ofTrueTypeFont upperLeftFont;
    ofTrueTypeFont upperRightFont;
    ofTrueTypeFont lowerLeftFont;
    ofTrueTypeFont lowerRightFont;
};
