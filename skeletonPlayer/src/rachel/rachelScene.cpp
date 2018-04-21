#include "rachelScene.h"
//#include "data.h"

//--------------------------------------------------------------
void rachelScene::setup(){

    studentName = "Rachel Simanjuntak";
    
    //start = cam.getOrientationQuat();
    
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
    //----------------------------------------------------------------

}

//--------------------------------------------------------------
void rachelScene::update(){

}

//--------------------------------------------------------------
void rachelScene::draw(){

    //ofBackground(0);

    
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

    ofSetLineWidth(3);
    
    float time = ofGetElapsedTimef();

    for (int i = 0; i < 24; i++){

        
        
        
        ofPoint dir = data3d[i] - data3d[(int)(ofGetFrameNum()*0.1) % 24];
        ofDrawLine(data3d[i], data3d[i] + 20000 * dir.normalize());
        
//        ofDrawSphere(data3d[i], mouseX/20.0);
        
//        float x = data3d[i].x;
//        float y = data3d[i].y;
//        float z = data3d[i].z;
//        z += ofSignedNoise(x*0.01, y*0.01, time) * ofMap(sin(time), -1, 1, 0, 400);
//
//        ofDrawSphere(ofPoint(x,y,z), 5);
        
        //ofDrawBitmapString(ofToString(i), data3d[i]);
    }

    //ofCircle(data3d[18], 10);


    //cam.end();
    
    
//    ofQuaternion curr = cam.getOrientationQuat();
//    cam.setOrientation(ofQuaternion::slerp(0, curr, start));
//
    for (int i = 0; i < 24; i++){
        //ofCircle(data2d[i], 4);
    }
}

//--------------------------------------------------------------
void rachelScene::keyPressed(int key){

}

//--------------------------------------------------------------
void rachelScene::keyReleased(int key){

}

//--------------------------------------------------------------
void rachelScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void rachelScene::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void rachelScene::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void rachelScene::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void rachelScene::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void rachelScene::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void rachelScene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void rachelScene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void rachelScene::dragEvent(ofDragInfo dragInfo){

}
