#include "kellyScene.h"
//#include "data.h"

//--------------------------------------------------------------
void kellyScene::setup(){
    
    studentName = "Kelly Monson";
    
    // no need to touch
//
//    for (int i = 0; i < 30; i++) {
//        for (int j = 0; j < 24; j++) {
//            float x = data3d[ i * 24 * 3 + j * 3 + 0 ];
//            float y = data3d[ i * 24 * 3 + j * 3 + 1 ];
//            float z = data3d[ i * 24 * 3 + j * 3 + 2 ];
//            frames[i][j].set(x, y, z);
//
//        }
//    }
//
//    for (int i = 0; i < 30; i++) {
//        for (int j = 0; j < 24; j++) {
//            float x = data2d[ i * 24 * 2 + j * 2 + 0 ];
//            float y = data2d[ i * 24 * 2 * j * 2 + 1 ];
//            frames2d[i][j].set(x, y);
//        }
//    }
}

//--------------------------------------------------------------
void kellyScene::update(){

}

//--------------------------------------------------------------
void kellyScene::draw(){
    //ofBackground(255);
    
    // don't need to touch this either
    // copy data into array
    ofPoint data3d[24];
    ofPoint data2d[24];
    
    int frameNumber = (int)(ofGetFrameNum() * 0.4) % 30;
    
    for (int i = 0; i < 24; i++) {
        data3d[i] = frames[frameNumber][i];
        data2d[i] = frames2d[frameNumber][i];
    }
    // end do not touch
    
  //  cam.begin();
  //  cam.enableOrtho();
    
    ofSetLineWidth(1);
    
    // for joints
    float sinOfTime = sin(ofGetElapsedTimef() * 2);
    float sinOfTimeRemapped = ofMap(sinOfTime, -1, 1, 2, 5);
    
    for (int i = 0; i < 24; i ++) {
        // sine wave squiggles
        ofSetColor(100, 0, ofRandom(0, 255), 100);
        createSineWave(data3d[i], data3d[0]);

        ofSetColor(0, 0, 0, 100);
        ofDrawSphere(data3d[i], sinOfTimeRemapped);
    }
    
    // draw the center
    // ofSetColor(155, 155, 255, 200);
 
    ofDrawSphere(data3d[0], 10);
    
    // ofSetLineWidth(5);
    ofSetColor(255,255,255, 255);

    // arms
    createOutline(data3d[15], data3d[14]);
    createOutline(data3d[14], data3d[13]);
    createOutline(data3d[13], data3d[12]);

    createOutline(data3d[4], data3d[5]);
    createOutline(data3d[5], data3d[6]);
    createOutline(data3d[6], data3d[7]);

    createOutline(data3d[12], data3d[3]);
    createOutline(data3d[3], data3d[4]);
    
    // legs
    createOutline(data3d[20], data3d[21]);
    createOutline(data3d[21], data3d[22]);
    createOutline(data3d[22], data3d[23]);
    
    createOutline(data3d[16], data3d[17]);
    createOutline(data3d[17], data3d[18]);
    createOutline(data3d[18], data3d[19]);

    createOutline(data3d[20], data3d[0]);
    createOutline(data3d[16], data3d[0]);
    
    // bod
    createOutline(data3d[0], data3d[1]);
    createOutline(data3d[1], data3d[2]);
    createOutline(data3d[2], data3d[3]);
    
    // head?
    createOutline(data3d[3], data3d[10]);
    createOutline(data3d[10], data3d[9]);
    
    
    //cam.end();
}

//--------------------------------------------------------------
void kellyScene::createSineWave(ofPoint pt1, ofPoint pt2) {

    float time = ofGetElapsedTimef();
    
    ofPoint diff = pt2 - pt1;
    
    diff.rotate(90, ofPoint(0, 0, 1));
    
    
    // radius = sin * 0.5 + height of wave
    float radius = sin(0.1) * ofRandom(0, 1);
    
    ofPolyline line;
    
    for (int i = 0; i < 100; i ++) {
        float percent = i / 100.0;
        
        float angle = percent * TWO_PI * 5;
        
        ofPoint mix = percent * pt1 + (1 - percent) * pt2;
        
        line.addVertex(mix + sin(angle + time * 10) * diff * radius);
    }
    
    line.draw();
}

void kellyScene::createOutline(ofPoint pt1, ofPoint pt2) {
    
    float time = ofGetElapsedTimef();

    ofPoint diff = pt1 - pt2;
    
    diff.rotate(90, ofPoint(0, 0, 1));
    
    float radius = sin(0.1) * 0.5;
    
    ofPolyline line;
    
    for (int i = 0; i < 100; i ++) {
        float percent = i / 100.0;
        
        float angle = percent * TWO_PI * 5;
        
        ofPoint mix = percent * pt1 + (1 - percent) * pt2;
        
        line.addVertex(mix + sin(angle + time*10) * diff * radius);
    }
    
    line.draw();
}

//--------------------------------------------------------------
void kellyScene::keyPressed(int key){

}

//--------------------------------------------------------------
void kellyScene::keyReleased(int key){

}

//--------------------------------------------------------------
void kellyScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void kellyScene::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void kellyScene::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void kellyScene::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void kellyScene::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void kellyScene::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void kellyScene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void kellyScene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void kellyScene::dragEvent(ofDragInfo dragInfo){

}
