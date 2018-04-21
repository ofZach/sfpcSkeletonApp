#include "sarahScene.h"
//#include "data.h"

//--------------------------------------------------------------
void sarahScene::setup(){
    
    studentName = "Sarah Gray";
    
    
    //----------------------------------------------------------------
    // the data is stored in a big flat array, let's copy it into something more managable
    // don't have to touch this :)
    
//    for (int i = 0; i < 30; i++){
//        for (int j = 0; j < 24; j++){
//            float x = data3d[ i * 24 * 3  + j * 3 + 0 ];
//            float y = data3d[ i * 24 * 3  + j * 3 + 1 ];
//            float z = data3d[ i * 24 * 3  + j * 3 + 2 ];
//            frames[i][j].set(x,y,z);
//            //pastFrames[i][j].set(x,y,z); // set the past frames
//        }
//    }
    
    //----------------------------------------------------------------

}

//--------------------------------------------------------------
void sarahScene::update(){
    
}

//--------------------------------------------------------------
void sarahScene::draw(){
    
    //ofBackground(0);
    
    
    // you don't have to touch this either:)
    //----------------------------- copy data into array
    ofPoint data3d[24];
    ofPoint data2d[24];
    
    int frameNumber =(int)(ofGetFrameNum()*0.4) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[ frameNumber][i];
        data2d[i] = frames2d[frameNumber][i];
        if(i > 0){
            pastFrames[i] = frames[frameNumber][i-1];
        }
        
    }
    
    
    // end do not touch
    
    
    //    //----------------------------- 3d
//    cam.begin();
//    cam.enableOrtho();
    ofSetColor(255);
    
    float time = ofGetElapsedTimef();
    
    
    for (int i = 0; i < 24; i++){
        ofPolyline line;
        ofPath path;
        ofPath path2;
        float x = data3d[i].x;
        float y = data3d[i].y;
        float z = data3d[i].z;
        z += ofSignedNoise(x*0.11, y*0.01, time) * ofMap(sin(time), -1, 1, 0, 400);
        
        // some of the lines, leaving off segments that aren't necessary
        if(i > 1 ){
            ofPoint p = pastFrames[i-1];
            ofPoint p2 = data3d[i];
            line.addVertex(p);
            line.addVertex(p2);
            if(i > 9 && i % 2 == 1){
               ofDrawLine(p,p2);
            }
        }
        // torso
        for(int t=0; t < 7; t++){
            path.lineTo(data3d[torso[t]]);
        }
        path.close();
        path.setFillColor(ofColor(255));
        path.draw();
        
        // leg
        for(int t=0; t < 3; t++){
            path2.lineTo(data3d[leg[t]]);
        }
        path2.close();
        path2.setFillColor(ofColor(255));
        path2.draw();

        // head
        ofDrawSphere(data3d[10], 15);
       //ofDrawBitmapString(ofToString(i), data3d[i]);
    }
    //cam.end();
}

//--------------------------------------------------------------
void sarahScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void sarahScene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void sarahScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void sarahScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void sarahScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void sarahScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void sarahScene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void sarahScene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void sarahScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void sarahScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void sarahScene::dragEvent(ofDragInfo dragInfo){
    
}
