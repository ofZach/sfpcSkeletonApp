#include "fame1Scene.h"
//#include "data.h"

//--------------------------------------------------------------
void fame1Scene::setup(){
    
    studentName = "Nitcha Tothong (Fame)";
    
    // the data is stored in a big flat array, let's copy it into something more managable
    
//    for (int i = 0; i < 30; i++){
//        for (int j = 0; j < 24; j++){
//            float x = data3d[ i * 24 * 3  + j * 3 + 0 ];
//            float y = data3d[ i * 24 * 3  + j * 3 + 1 ];
//            float z = data3d[ i * 24 * 3  + j * 3 + 2 ];
//            frames[i][j].set(x,y,z);
//        }
//    }
    
    
     for (int j = 0; j < 24; j++){
         offsets.push_back(ofVec3f(ofRandom(0, 10000), ofRandom(0, 10000), ofRandom(0, 10000)));
     }
}

//--------------------------------------------------------------
void fame1Scene::update(){
    
}

//--------------------------------------------------------------
void fame1Scene::draw(){
    
    
    
   // ofBackground(0);
    
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
    ofSetLineWidth(3);
    
    ofMesh mesh; //Great for triangle,
    mesh.setMode(OF_PRIMITIVE_LINES);
    for (int i = 0; i < 24; i++){
        
       
        //mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
        //mesh.enableIndices();

        ofVec3f timeOffsets = offsets[i];
        
        float x = data3d[i].x;
        float y = data3d[i].y;
        float z = data3d[i].z;
        
        z += ofSignedNoise( x * 0.5, y, time) * ofMap(sin(time + timeOffsets.x), -1, 1, 0, 200);
        
        ofVec3f pos(x, y, z);
//        mesh.addVertex(ofPoint(data3d[i].x, data3d[i].y, data3d[i].z));
        mesh.addVertex(ofPoint(data3d[i].x, data3d[i].y, 0));
       // mesh.addColor(ofColor::black);
        
        mesh.addVertex(pos);
        mesh.addColor(ofColor::pink);
        mesh.addColor(ofColor::white);

       
        
        
    }
     mesh.draw();
    
    
    //cam.end();

   
}

//--------------------------------------------------------------
void fame1Scene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void fame1Scene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void fame1Scene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void fame1Scene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void fame1Scene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void fame1Scene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void fame1Scene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void fame1Scene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void fame1Scene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void fame1Scene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void fame1Scene::dragEvent(ofDragInfo dragInfo){
    
}
