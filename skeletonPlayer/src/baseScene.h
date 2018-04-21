
#pragma once


#include "ofMain.h"


class baseScene {
    
    
    
public:
    
    string studentName = "";
    
    virtual void setup(){}
    virtual void update(){}
    virtual void draw(){}
    //virtual void draw2d(){}
    
    ofPoint frames[30][24];         // 30 frames, 24 points per frame
    ofPoint frames2d[30][24];         // 30 frames, 24 points per frame
    
};
