# sfpcSkeletonApp
walking person data vis project

to convert a normal sketch to this system: 

- take ofApp.h and ofApp.cpp and rename to studentName + Scene, ie, yeliScene.
- change all occurances of ofApp to the scene name
- change include ofMain to baseScene
- comment out references to frame and cam in the scene (it exists now in baseScene) 

//        ofEasyCam cam;
//    
//        ofPoint frames[30][24];         // 30 frames, 24 points per frame
//        ofPoint frames2d[30][24];         // 30 frames, 24 points per frame

- comment out include "data.h" in the scene cpp file
- comment out the code that transfers the data into frames and frames2d
- comment out any use of cam in draw and any calls to ofBackground




