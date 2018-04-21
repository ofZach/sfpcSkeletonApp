#pragma once

#include "baseScene.h"
//#include "ofxMidi.h"

class pixel {
    
public:
    
    ofPoint orig;
    ofPoint pos;
    ofColor color;
    float magnetism;
    
};

class ailadiScene : public baseScene {

	public:
		void setup();
		void update();
		void draw();
        void exit();

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
        //void newMidiMessage(ofxMidiMessage& eventArgs);
    
        ofImage wheel;
        vector < pixel > pixels;
		
        stringstream text;
        //ofxMidiIn midiIn;
        //ofxMidiMessage midiMessage;
        float value;
        //vector <float> midiControl;
    
       // ofEasyCam cam;
        //ofPoint frames[30][24];         // 30 frames, 24 points per frame
    
  
};
