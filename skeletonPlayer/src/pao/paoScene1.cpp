#include "paoScene1.h"
//#include "data.h"

//--------------------------------------------------------------
void paoScene1::setup(){
    
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
    
    line.resize(24);

}

//--------------------------------------------------------------
void paoScene1::update(){

}

//--------------------------------------------------------------
void paoScene1::draw(){

   // ofBackground(0);

    
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
   // cam.begin();
   // cam.enableOrtho();
    ofSetColor(255);

   
    ofPushMatrix();
    for (int i = 0; i < 24; i++){
        
        if(i == 11 || i == 8 || i == 3 || i == 0){
            
        } else {
        ofSetColor(255);
        ofDrawSphere(data3d[i].x, data3d[i].y, data3d[i].z, 1);
        
        ofPoint pt;
        pt.x = data3d[i].x;
        pt.y = data3d[i].y;
        pt.z = data3d[i].z;
        
        if (line[i].size() > 45) {
            for (int s = 0; s < 45; s++){
                line[i].getVertices()[s].z -= 1.25f;
            }
            line[i].getVertices().erase(line[i].getVertices().begin());
        }
        
        line[i].addVertex(pt);
        line[i].draw();
        }
    }

    ofPopMatrix();
   // cam.end();

}

//--------------------------------------------------------------
void paoScene1::keyPressed(int key){

}

//--------------------------------------------------------------
void paoScene1::keyReleased(int key){

}

//--------------------------------------------------------------
void paoScene1::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void paoScene1::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void paoScene1::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void paoScene1::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void paoScene1::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void paoScene1::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void paoScene1::windowResized(int w, int h){

}

//--------------------------------------------------------------
void paoScene1::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void paoScene1::dragEvent(ofDragInfo dragInfo){

}
