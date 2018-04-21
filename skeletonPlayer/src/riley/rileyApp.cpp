#include "rileyApp.h"
//#include "data.h"
#include "ofMain.h"

int MAX_AGE = 300;


//--------------------------------------------------------------
void rileyApp::setup(){
    
    studentName = "Riley Shaw";
    
    //----------------------------------------------------------------
    // the data is stored in a big flat array, let's copy it into something more managable
    // don't have to touch this :)
    ofSetColor(255, 255, 255, 0);
//    gifloader.load("riley/butterfly.gif");
//    gifFrames = gifloader.pages.size();
//    gifWidth = gifloader.pages[0].getWidth() / 10;
//    gifHeight = gifloader.pages[0].getHeight() / 10;
//    gifOffset = ofPoint(-gifWidth / 2, -gifHeight / 2);
//    for (int i = 0; i < gifFrames; ++i) {
//        gifloader.pages[i].resize(gifWidth, gifHeight);
//    }
    
//    for (int i = 0; i < 30; i++){
//        for (int j = 0; j < 24; j++){
//            float x = initialData3d[ i * 24 * 3  + j * 3 + 0 ];
//            float y = initialData3d[ i * 24 * 3  + j * 3 + 1 ];
//            float z = initialData3d[ i * 24 * 3  + j * 3 + 2 ];
//            frames[i][j].set(x,y,z);
//        }
//    }
    
    ofBackground(0);
    //----------------------------------------------------------------

}

//--------------------------------------------------------------
void rileyApp::update(){
    // you don't have to touch this either:)
    //----------------------------- copy data into array
    
    int frameNumber = (int)(ofGetFrameNum()*0.4) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[frameNumber][i];
    }
    
    
    // end do not touch
    for (int i = 0; i < 24; ++i) {
        bool leftFoot = (frameNumber > 13 && frameNumber < 19) && (i == 18 || i == 19);
        bool rightFoot = frameNumber > 24 && (i == 22 || i == 23);
        if ((leftFoot || rightFoot) && ofRandom(1) > 0.85) {
            struct Butterfly butterfly;
            butterfly.radius = ofRandom(3, 5);
            butterfly.position = ofPoint(data3d[i].x, data3d[i].y, data3d[i].z);
            butterfly.velocity = ofPoint(ofRandom(-1, 1), ofRandom(5), ofRandom(-3, -1)).normalize() * 2;
            butterfly.age = 0;
            butterflies.push_back(butterfly);
        }
    }

    int numDead = 0;
    for (int i = 0; i < butterflies.size(); ++i) {
        struct Butterfly* butterfly = &butterflies[i];
        int age = butterfly->age;
        if (age > MAX_AGE) {
            ++numDead;
        } else if (age) {
            butterfly->position.y += butterfly->velocity.y + ofRandom(-0.5, 0.5);
            butterfly->position.x += butterfly->velocity.x + ofRandom(-0.5, 0.5);
            butterfly->position.z += butterfly->velocity.z - 2 + ofRandom(-0.5, 0.5);
        }
        ++butterfly->age;
    }
    
    // Probably a way to delete all at once.
    for (int i = 0; i < numDead; ++i) { butterflies.pop_front(); }
}

ofColor bgColor = ofColor(74, 90, 74);
float y = 0;
//--------------------------------------------------------------
void rileyApp::draw(){
//    int frameNumber = (int)(ofGetFrameNum()*0.4) % 30;
//    if (frameNumber == 15 || frameNumber == 26) {
//        y += 2;
//    } else if (frameNumber == 16 || frameNumber == 27) {
//        y -= 0.7;
//    } else {
//        y -= 0.1;
//    }
    
    //----------------------------- 3d
    float angle = fmod(ofGetElapsedTimef() / 2.0, 2 * PI);
//    cam.setGlobalPosition(sin(angle) * 400.0, (sin(angle - 1) + 0.5) * 250.0, cos(angle) * 400.0 - 200);
//    cam.setTarget(ofPoint(0, (sin(angle - 1) - 1) * 60.0, 0));
////    cam.enableOrtho();
//    cam.begin();
    ofSetDepthTest(true);
    ofSetColor(255);
    
    // Torso.
    ofDrawLine(data3d[0], data3d[1]);
    ofDrawLine(data3d[1], data3d[2]);
    ofDrawLine(data3d[2], data3d[3]);
    
    // Right arm.
    ofDrawLine(data3d[3], data3d[4]);
    ofDrawLine(data3d[4], data3d[5]);
    ofDrawLine(data3d[5], data3d[6]);
    ofDrawLine(data3d[6], data3d[7]);
    
    // Left arm.
    ofDrawLine(data3d[3], data3d[12]);
    ofDrawLine(data3d[12], data3d[13]);
    ofDrawLine(data3d[13], data3d[14]);
    ofDrawLine(data3d[14], data3d[15]);
    
    // Head.
    ofDrawLine(data3d[3], data3d[9]);
    ofDrawLine(data3d[9], data3d[10]);
//    ofDrawSphere(data3d[10], 40);
    
    // Right leg.
    ofDrawLine(data3d[0], data3d[16]);
    ofDrawLine(data3d[16], data3d[17]);
    ofDrawLine(data3d[17], data3d[18]);
    ofDrawLine(data3d[18], data3d[19]);
    
    // Left leg.
    ofDrawLine(data3d[0], data3d[20]);
    ofDrawLine(data3d[20], data3d[21]);
    ofDrawLine(data3d[21], data3d[22]);
    ofDrawLine(data3d[22], data3d[23]);
    
    // Fills.
    ofMesh body;
    body.setMode(OF_PRIMITIVE_TRIANGLES);
    
    // Thigh.
    body.addVertex(data3d[16]);
    body.addVertex(data3d[20]);
    body.addVertex(data3d[21]);
    body.draw();
    
    // Thigh.
    body.addVertex(data3d[20]);
    body.addVertex(data3d[16]);
    body.addVertex(data3d[17]);
    body.draw();

    // Torso.
    body.addVertex(data3d[12]);
    body.addVertex(data3d[4]);
    body.addVertex(data3d[20]);
    body.draw();
    
    // Torso.
    body.addVertex(data3d[20]);
    body.addVertex(data3d[16]);
    body.addVertex(data3d[4]);
    body.draw();
    
    // Neck.
    body.addVertex(data3d[12]);
    body.addVertex(data3d[3]);
    body.addVertex(data3d[4]);
    body.draw();
    
    // Bicep.
    body.addVertex(data3d[13]);
    body.addVertex(data3d[3]);
    body.addVertex(data3d[12]);
    body.draw();
    
    // Bicep.
    body.addVertex(data3d[3]);
    body.addVertex(data3d[4]);
    body.addVertex(data3d[5]);
    body.draw();
    
//    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for (int i = 0; i < butterflies.size(); ++i) {
//        // Butterflies fade in *and* out, with max opacity at MAX_AGE / 2"
//        float opacity = 1.0 - (float)abs(2 * butterflies[i].age - MAX_AGE) / MAX_AGE;
        
        // Butterflies just fade out:
        float opacity = 1.0 - (float)butterflies[i].age / MAX_AGE;
        
        // Fade faster...
        opacity *= opacity;
        
        ofSetColor(bgColor, opacity * 255);
        ofPushMatrix();
        ofTranslate(butterflies[i].position);
        ofDrawSphere(0, 0, 0, butterflies[i].radius);
//        ofMatrix4x4 mat;
//        mat.makeLookAtMatrix(butterflies[i].position, cam.getPosition(), ofPoint(0, 1, 0));
//        ofMultMatrix(mat);
        
//        gifloader.pages[(butterflies[i].age / 4) % gifFrames].draw(0, 0, gifWidth, gifHeight);
        ofPopMatrix();
    }

//    ofSetRectMode(OF_RECTMODE_CORNER);
   // cam.end();
}

//--------------------------------------------------------------
void rileyApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void rileyApp::keyReleased(int key){
//    if (key == ' ') cout << bgColor << endl;
}

//--------------------------------------------------------------
void rileyApp::mouseMoved(int x, int y ){
//    bgColor.setHue(x * 255 / ofGetScreenWidth());
}

//--------------------------------------------------------------
void rileyApp::mouseDragged(int x, int y, int button){
//    bgColor.setSaturation(x * 255 / ofGetScreenWidth());
//    bgColor.setBrightness(y * 255 / ofGetScreenHeight());
}

//--------------------------------------------------------------
void rileyApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void rileyApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void rileyApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void rileyApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void rileyApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void rileyApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void rileyApp::dragEvent(ofDragInfo dragInfo){

}
