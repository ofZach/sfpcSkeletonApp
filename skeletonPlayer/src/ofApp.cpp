#include "ofApp.h"
#include "data.h"


//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFullscreen(true);
    ofSetVerticalSync(false);
    ofSetFrameRate(60);
    ofHideCursor();
    
    font.load("Agipo regular.otf", 30, true, true, true);
    
    angle = 0;
    //----------------------------------------------------------------
    // the data is stored in a big flat array, let's copy it into something more managable
    // don't have to touch this :)
    
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 24; j++){
            float x = data3d[ i * 24 * 3  + j * 3 + 0 ];
            float y = data3d[ i * 24 * 3  + j * 3 + 1 ];
            float z = data3d[ i * 24 * 3  + j * 3 + 2 ];
            frames[i][j].set(x,y,z);
        }
    }
    
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 24; j++){
            float x = data2d[ i * 24 * 2  + j * 2 + 0 ];
            float y = data2d[ i * 24 * 2  + j * 2 + 1 ];
            frames2d[i][j].set(x,y);
        }
    }
    //----------------------------------------------------------------
    
    //vector < baseScene * > scenes;
    
    
    scenes.push_back(new ailadiScene());
    scenes.push_back(new paoScene1());
     scenes.push_back(new paoScene2());
    scenes.push_back(new hansScene());
    scenes.push_back(new philScene());
    
    
    
    scenes.push_back(new yeliScene());
    scenes.push_back(new rachelScene());
    scenes.push_back(new kellyScene());
    scenes.push_back(new gonzaScene());
    scenes.push_back(new rileyApp());
    scenes.push_back(new agnesScene());
    scenes.push_back(new fame1Scene());
    scenes.push_back(new fame2Scene());
    scenes.push_back(new fame3Scene());
    scenes.push_back(new sydScene());
    scenes.push_back(new sarahScene());
    scenes.push_back(new sukanyaScene());
    
    for (int i = 0; i < scenes.size(); i++){
        for (int j = 0; j < 30; j++){
            for (int k = 0; k < 24; k++){
                scenes[i]->frames[j][k] = frames[j][k];
                scenes[i]->frames2d[j][k] = frames2d[j][k];
            }
        }
        scenes[i]->setup();
        
        
    }
    
    
    currentScene = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

    ofHideCursor();
    scenes[currentScene]->update();
    
    if (ofGetFrameNum() % (60 * 10) == 0){
        currentScene++;
        currentScene %= scenes.size();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    // from RILEYS
    
    angle += 0.01*0.4;
   cam.setGlobalPosition(sin(angle) * 400.0, (sin(angle - 1) + 0.5) * 250.0, cos(angle) * 400.0 - 200);
        cam.setTarget(ofPoint(0, (sin(angle - 1) - 1) * 60.0, 0));
    ////    cam.enableOrtho();
    //    cam.begin();

    
    
    cam.begin();
    cam.enableOrtho();
    ofTranslate(0,-ofGetHeight()*-0.05, 0);
    ofScale(2.3, 2.3, 2.3);
    
    ofPushStyle();
    scenes[currentScene]->draw();
    ofPopStyle();
    
    cam.end();
    
    
    ofRectangle r = font.getStringBoundingBox(scenes[currentScene]->studentName, 0,0);
    r.scaleFromCenter(1.2);
    ofSetColor(255);
    font.drawString(scenes[currentScene]->studentName,  ofGetWidth()-r.width, ofGetHeight()-r.height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        ofToggleFullscreen();
    }
    
    if (key == OF_KEY_RIGHT){
        currentScene ++;
        currentScene %= scenes.size();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
