#pragma once

#include "baseScene.h"



class sukanyaScene : public baseScene{
    
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
    
    void setData(float t);
    void drawJoint(int start, int end, float anim, float intensity);
    void drawMan(float anim, float offset, float intensity);
    
    void debug(int frameNumber);
    
    float getCurve(float time, float offset);
    
    ofEasyCam cam;
    
    //ofPoint frames[30][24];         // 30 frames, 24 points per frame
    
    ofPoint lerpedFrame[24];
    
    int count;
    float stopSize;
    float t;
    
    
    
};
