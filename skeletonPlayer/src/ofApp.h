#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "sukanyaScene.h"
#include "sarahScene.h"
#include "sydScene.h"

#include "fame1Scene.h"
#include "fame2Scene.h"
#include "fame3Scene.h"
#include "agnesScene.h"
#include "rileyApp.h"
#include "gonzaScene.h"
#include "kellyScene.h"
#include "rachelScene.h"
#include "yeliScene.h"

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
		

        ofPoint frames[30][24];         // 30 frames, 24 points per frame
        ofPoint frames2d[30][24];         // 30 frames, 24 points per frame
    
    
        vector < baseScene * > scenes;
    
    float angle =0;
        ofEasyCam cam;
    
    int currentScene;
    
    ofTrueTypeFont font;
    
    
    
};
