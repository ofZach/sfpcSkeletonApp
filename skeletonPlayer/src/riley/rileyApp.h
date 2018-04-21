#pragma once

#include "baseScene.h"
#include "ofxGif.h"

struct Butterfly {
    float radius;
    ofPoint velocity;
    ofPoint position;
    int age;
};

class rileyApp : public baseScene{

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
		
        ofxGIF::fiGifLoader gifloader;
        int gifFrames;
        float gifWidth;
        float gifHeight;
        ofPoint gifOffset;
    
       // ofEasyCam cam;
    
    ofPoint data3d[24];
    
        //ofPoint frames[30][24];         // 30 frames, 24 points per frame
        //ofPoint frames2d[30][24];         // 30 frames, 24 points per frame
    
        deque <Butterfly> butterflies;
};
