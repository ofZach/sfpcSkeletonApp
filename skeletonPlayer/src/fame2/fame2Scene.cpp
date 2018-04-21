#include "fame2Scene.h"
//#include "data.h"

//--------------------------------------------------------------
void fame2Scene::setup(){
    
    studentName = "Nitcha Tothong (Fame)";
    
    
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
//
//        }
//    }
    
   // offsets.push_back(ofVec3f(ofRandom(0, 1000), ofRandom(0, 1000), ofRandom(0, 1000)));
    for (int j = 0; j < 24; j++){
        offsets.push_back(ofVec3f(ofRandom(0, 1000), ofRandom(0, 1000), ofRandom(0, 1000)));
    }
}

//--------------------------------------------------------------
void fame2Scene::update(){
    
}

//--------------------------------------------------------------
void fame2Scene::draw(){
    
    //ofBackground(0);
    
    // you don't have to touch this either:)
    //----------------------------- copy data into array
    
    ofPoint data3d[24];
    //ofPoint data2d[24];
    
    int frameNumber =(int)(ofGetFrameNum()*0.4) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[ frameNumber][i];
        //data2d[i] = frames2d[frameNumber][i];
    }
    
    
    // end do not touch
    //----------------------------- 3d
    //cam.begin();
    //cam.enableOrtho();
    
    ofSetColor(255);
    float time = ofGetElapsedTimef();
    
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    mesh.enableIndices();
    
    
    ofPoint diff = data3d[4]-data3d[8];
    
    for (int i = 0; i < 24; i++){
        
        
        ofVec3f timeOffsets = offsets[i];
        
        float x = data3d[i].x;
        float y = data3d[i].y;
        float z = data3d[i].z;
        
        if (i == 10){
            x += diff.x;
            y += diff.y;
            z += diff.z;
        }
        
        z += ofSignedNoise( x * 0.5, y, time) * ofMap(sin(time + timeOffsets.x), -1, 1, 0, 22);
        
        ofVec3f pos(x, y, z);
        
        //float head = data3d[10].x;
        
        mesh.addVertex(ofPoint(data3d[i].x, data3d[i].y));
        // mesh.addVertex(ofPoint(head));
        
        mesh.addColor(ofColor::teal);
        mesh.addVertex(pos);
        mesh.addColor(ofColor::thistle);
        //mesh.addColor(ofColor::azure);
        mesh.draw();
        
    }
    
    //cam.end();
    
    
}
//--------------------------------------------------------------
void fame2Scene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void fame2Scene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void fame2Scene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void fame2Scene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void fame2Scene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void fame2Scene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void fame2Scene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void fame2Scene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void fame2Scene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void fame2Scene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void fame2Scene::dragEvent(ofDragInfo dragInfo){
    
}
