#include "philScene.h"
//#include "data.h"

//--------------------------------------------------------------
void philScene::setup(){


    studentName = "Phil Schleihauf";
    
    
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
void philScene::update(){

}

//--------------------------------------------------------------
void philScene::draw(){
   // ofBackground(0);
   // cam.begin();
    //    cam.enableOrtho();
    ofScale(0.3, 0.3, 0.3);
    ofSetColor(255);
    ofSetLineWidth(3);

    ofPoint data3d[24];
    ofPoint last3d[24];
    float z;
    float prevZ;

    for (int n = 0; n < N; n++) {
        z = -n * 100;
        int frameNumber = (int)((ofGetFrameNum() - n * 5)) % 30;
        int prevFrame = (int)((ofGetFrameNum() - (n - 1) * 5)) % 30;
        for (int i = 0; i < 24; i++){
            data3d[i] = frames[frameNumber][i];
            last3d[i] = frames[prevFrame][i];
        }
        

        ofDrawLine(data3d[0] + ofPoint(0, 0, z), data3d[1] + ofPoint(0, 0, z));
        ofDrawLine(data3d[0] + ofPoint(0, 0, z), data3d[16] + ofPoint(0, 0, z));
        ofDrawLine(data3d[0] + ofPoint(0, 0, z), data3d[20] + ofPoint(0, 0, z));

        
//        for (int i = 16; i < 24; i++) {
//            ofDrawSphere(data3d[i] + ofPoint(0, 0, z), 4);
//        }
        ofDrawLine(data3d[20] + ofPoint(0, 0, z), data3d[21] + ofPoint(-60, 40, z));
//        ofDrawSphere(data3d[21] + ofPoint(-60, 40, z), 4);
        ofDrawLine(data3d[21] + ofPoint(-60, 40, z), data3d[22] + ofPoint(-60, 40, z));
//        ofDrawSphere(data3d[22] + ofPoint(-60, 40, z), 4);
        ofDrawLine(data3d[22] + ofPoint(-60, 40, z), data3d[23] + ofPoint(-60, 40, z));
//        ofDrawSphere(data3d[23] + ofPoint(-60, 40, z), 4);

        ofDrawLine(data3d[16] + ofPoint(0, 0, z), data3d[17] + ofPoint(60, 40, z));
        ofDrawLine(data3d[17] + ofPoint(60, 40, z), data3d[18] + ofPoint(60, 40, z));
        ofDrawLine(data3d[18] + ofPoint(60, 40, z), data3d[19] + ofPoint(60, 40, z));

        if (n == 0) {
            ofDrawSphere(data3d[10] + ofPoint(0, 0, z), 20);
            // draw the upper body
//            for (int i = 0; i < 16; i++) {
//                ofDrawSphere(data3d[i], 4);
//            }
            ofDrawLine(data3d[1] + ofPoint(0, 0, z), data3d[2] + ofPoint(0, 0, z));
            ofDrawLine(data3d[2] + ofPoint(0, 0, z), data3d[3] + ofPoint(0, 0, z));
            ofDrawLine(data3d[3] + ofPoint(0, 0, z), data3d[4] + ofPoint(0, 0, z));
            ofDrawLine(data3d[4] + ofPoint(0, 0, z), data3d[5] + ofPoint(0, 0, z));
            ofDrawLine(data3d[5] + ofPoint(0, 0, z), data3d[6] + ofPoint(0, 0, z));
            ofDrawLine(data3d[6] + ofPoint(0, 0, z), data3d[7] + ofPoint(0, 0, z));

            ofDrawLine(data3d[3] + ofPoint(0, 0, z), data3d[9] + ofPoint(0, 0, z));
            ofDrawLine(data3d[9] + ofPoint(0, 0, z), data3d[10] + ofPoint(0, 0, z));

            ofDrawLine(data3d[3] + ofPoint(0, 0, z), data3d[12] + ofPoint(0, 0, z));
            ofDrawLine(data3d[12] + ofPoint(0, 0, z), data3d[13] + ofPoint(0, 0, z));
            ofDrawLine(data3d[13] + ofPoint(0, 0, z), data3d[14] + ofPoint(0, 0, z));
            ofDrawLine(data3d[14] + ofPoint(0, 0, z), data3d[15] + ofPoint(0, 0, z));
        } else {
            // draw the lower part and connect to the prev
            prevZ = -(n - 1) * 100;
//            for (int i = 0; i < 2; i++) {
//                ofDrawSphere(data3d[i] + ofPoint(0, 0, z), 4);
//            }
            ofDrawLine(data3d[0] + ofPoint(0, 0, z), last3d[0] + ofPoint(0, 0, prevZ));
            ofDrawLine(data3d[1] + ofPoint(0, 0, z), last3d[1] + ofPoint(0, 0, prevZ));
            ofDrawLine(data3d[16] + ofPoint(0, 0, z), last3d[16] + ofPoint(0, 0, prevZ));
            ofDrawLine(data3d[20] + ofPoint(0, 0, z), last3d[20] + ofPoint(0, 0, prevZ));
        }
    }

    //cam.end();
}

//--------------------------------------------------------------
void philScene::keyPressed(int key){

}

//--------------------------------------------------------------
void philScene::keyReleased(int key){

}

//--------------------------------------------------------------
void philScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void philScene::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void philScene::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void philScene::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void philScene::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void philScene::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void philScene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void philScene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void philScene::dragEvent(ofDragInfo dragInfo){

}
