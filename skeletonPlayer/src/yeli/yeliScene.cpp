#include "yeliScene.h"
//#include "data.h"

//--------------------------------------------------------------
void yeliScene::setup(){
    ofBackground(0, 0, 51);
    
    studentName = "Omayeli Arenyeka";
    

    //----------------------------------------------------------------
    // the data is stored in a big flat array, let's copy it into something more managable
    // don't have to touch this :)
    
//    for (int i = 0; i < 30; i++){
//        for (int j = 0; j < 24; j++){
//            float x = data3d[ i * 24 * 3  + j * 3 + 0 ];
//            float y = data3d[ i * 24 * 3  + j * 3 + 1 ];
//            float z = data3d[ i * 24 * 3  + j * 3 + 2 ];
//            frames[i][j].set(x,y,z);
//        }
//    }
//
//    for (int i = 0; i < 30; i++){
//        for (int j = 0; j < 24; j++){
//            float x = data2d[ i * 24 * 2  + j * 2 + 0 ];
//            float y = data2d[ i * 24 * 2  + j * 2 + 1 ];
//            frames2d[i][j].set(x,y);
//        }
//    }
}

//--------------------------------------------------------------
void yeliScene::update(){
}

//--------------------------------------------------------------
void yeliScene::draw(){

    
    // you don't have to touch this either:)
    //----------------------------- copy data into array
    ofPoint data3d[24];
    ofPoint data2d[24];

    int frameNumber =(int)(ofGetFrameNum()*0.4) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[ frameNumber][i];
        data2d[i] = frames2d[frameNumber][i];
    }
    
    
    // end do not touch
    
    
//    //----------------------------- 3d
//    cam.begin();
//    cam.enableOrtho();
    ofSetColor(255);

    for (int i = 0; i < 200; i++) {
        float size = 500;
        ofVec3f p = ofVec3f(ofRandom(-size, size), ofRandom(-size, size), ofRandom(-size, size));
        ofDrawCircle(p, ofRandom(1));
    }
    
    float time = ofGetElapsedTimef();
    
    for (int i = 0; i < 23; i++){
        if (i % 2) {
            ofDrawLine(data3d[i], data3d[i+1]*2);
            ofDrawCircle(data3d[i+1]*2, ofRandom(4));
        }
        
        for (int j = 0; j < 6; j++) {
            float x = ofRandom(10);
            float y = ofRandom(10);
            float z = ofRandom(10);
            ofDrawLine(data3d[i], ofVec3f(x, y, z));
        }
    }

    //cam.end();
}

//--------------------------------------------------------------
void yeliScene::keyPressed(int key){
 
}

//--------------------------------------------------------------
void yeliScene::keyReleased(int key){

}

//--------------------------------------------------------------
void yeliScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void yeliScene::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void yeliScene::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void yeliScene::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void yeliScene::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void yeliScene::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void yeliScene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void yeliScene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void yeliScene::dragEvent(ofDragInfo dragInfo){

}
