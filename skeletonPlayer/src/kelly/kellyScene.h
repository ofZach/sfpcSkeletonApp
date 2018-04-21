#pragma once

#include "baseScene.h"

class kellyScene : public baseScene{

	public:
		void setup();
		void update();
		void draw();

    void createSineWave(ofPoint pt1, ofPoint pt2);
    void createOutline(ofPoint pt1, ofPoint pt2);
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

    
//    ofEasyCam cam;
//    
//    ofPoint frames[30][24];
//    ofPoint frames2d[30][24];
		
};
