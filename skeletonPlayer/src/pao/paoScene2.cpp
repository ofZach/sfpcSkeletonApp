#include "paoScene2.h"
//#include "data.h"

//--------------------------------------------------------------
void paoScene2::setup(){
    
    studentName = "Paola González";
    
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
void paoScene2::update(){

}

//--------------------------------------------------------------
void paoScene2::draw(){

    //ofBackground(0);

    
    ofSetCircleResolution(100);
    // you don't have to touch this either:)
    //----------------------------- copy data into array
    ofPoint data3d[24];
    ofPoint data2d[24];
    
    int frameNumber =(int)(ofGetFrameNum()*(0.4)) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[ frameNumber][i];
        data2d[i] = frames2d[frameNumber][i];
    }
    
    
    //----------------------------- 3d
    
    ofFill();
//    cam.begin();
//    cam.enableOrtho();
    ofSetColor(255);

   
    ofPushMatrix();
    
    ofDrawSphere(data3d[10].x, data3d[10].y + 50, data3d[10].z, 90);
    
    ofDrawLine(data3d[12], data3d[13]);
    ofDrawLine(data3d[13], data3d[15]);
    
    ofDrawLine(data3d[4], data3d[5]);
    ofDrawLine(data3d[5], data3d[7]);
    
    ofDrawLine(data3d[12], data3d[0]);
    ofDrawLine(data3d[4], data3d[0]);
    
    ofDrawLine(data3d[0], data3d[17]);
    ofDrawLine(data3d[17], data3d[19]);
    
    ofDrawLine(data3d[0], data3d[21]);
    ofDrawLine(data3d[21], data3d[23]);

    ofPopMatrix();

    
   // cam.end();
    
  
    
}

//--------------------------------------------------------------
void paoScene2::keyPressed(int key){

}

//--------------------------------------------------------------
void paoScene2::keyReleased(int key){

}

//--------------------------------------------------------------
void paoScene2::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void paoScene2::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void paoScene2::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void paoScene2::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void paoScene2::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void paoScene2::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void paoScene2::windowResized(int w, int h){

}

//--------------------------------------------------------------
void paoScene2::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void paoScene2::dragEvent(ofDragInfo dragInfo){

}
