#include "sukanyaScene.h"
//#include "data.h"

//--------------------------------------------------------------
void sukanyaScene::setup(){
    
    studentName = "Sukanya Aneja";
    
//    for (int i = 0; i < 30; i++){
//        for (int j = 0; j < 24; j++){
//            float x = data3d[ i * 24 * 3  + j * 3 + 0 ];
//            float y = data3d[ i * 24 * 3  + j * 3 + 1 ];
//            float z = data3d[ i * 24 * 3  + j * 3 + 2 ];
//            frames[i][j].set(x,y,z);
//        }
//    }
//
    count = 100;
    stopSize = 0.2;
}

//--------------------------------------------------------------
void sukanyaScene::setData(float t) {
    

    int frameNumber = floor(t);
    frameNumber = ofWrap(frameNumber, 0, 30);
    int nextFrame = frameNumber + 1;
    nextFrame = ofWrap(nextFrame, 0, 30);
    
    float lerpamount = t - floor(t);
    
    for(int i=0; i<24; i++) {
        ofPoint a = frames[frameNumber][i];
        ofPoint b = frames[nextFrame][i];
        float x = ofLerp(a.x, b.x, lerpamount);
        float y = ofLerp(a.y, b.y, lerpamount);
        float z = ofLerp(a.z, b.z, lerpamount);
        lerpedFrame[i] = ofPoint(x, y, z);
    }
}


//--------------------------------------------------------------
void sukanyaScene::drawJoint(int start, int end, float anim, float intensity){

    
    ofPolyline line;
    for(int i=0; i<count; i++) {
        float lerpAmount = float(i)/count;
        int p1 = start;
        int p2 = end;

        float tt = t - lerpAmount * intensity;
        tt = tt - fmod(tt, stopSize);
        ofWrap(tt, 0, 30);
        
        setData(tt);
        float ax = lerpedFrame[p1].x;
        float bx = lerpedFrame[p2].x;
        
        setData(t);
        float ay = lerpedFrame[p1].y;
        float by = lerpedFrame[p2].y;
        
        
        setData(tt);
        float az = lerpedFrame[p1].z;
        float bz = lerpedFrame[p2].z;
        
        float x = ofLerp(ax, bx, lerpAmount);
        float y = ofLerp(ay, by, lerpAmount);
        float z = ofLerp(az, bz, lerpAmount);
        line.addVertex(x,y,z);
    }
    
    
    //    ofMesh m;
    //    m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    //    float thickness = 8;
    //    for (int i = 0; i < line.size(); i++){
    //
    //        int i_m_1 = i-1;
    //        int i_p_1 = i+1;
    //        i_m_1 = ofWrap(i_m_1, 0, line.size());
    //        i_p_1 = ofWrap(i_p_1, 0, line.size());
    //
    //        ofPoint prev = line[i_m_1]; // polyline lets you grab vertex like array
    //        ofPoint next = line[i_p_1];
    //        // get angle bisector vector / normal
    //        ofPoint diff = (next - prev);
    //        diff = diff.getNormalized();
    //        diff.rotate(90, ofPoint(0,0,1));  // rotate 90 on the z axis.
    //
    //        // thickness is the magnitude to travel in directipn of diff
    //        m.addVertex(line[i % line.size()] + diff * thickness*0.5);
    //        m.addVertex(line[i % line.size()] - diff * thickness*0.5);
    //
    //    }
    //
    //    m.draw();
    //    line.close();
    line.draw();
    
}

//--------------------------------------------------------------
void sukanyaScene::debug(int frameNum){
    ofSetColor(255, 0, 0);
    for(int i=0; i<24; i++) {
        ofDrawSphere(frames[frameNum][i],  3);
    }
    ofSetColor(255);
}

//--------------------------------------------------------------
float sukanyaScene::getCurve(float time, float offset) {
    
    float curve = fmin( abs(sin(time)), pow(sin(.5*(time - offset*pi) + .25*pi), 9) );
    
    curve = abs(pow(sin(.5*(time - offset*pi) + .25*pi), 9));
//    curve = ofClamp(curve, 0, 1);
    
    
    return curve;
}

//--------------------------------------------------------------
void sukanyaScene::drawMan(float anim, float offset, float intensity){
    
    float curve = getCurve(anim, offset);
    
    drawJoint(21, 20, anim, intensity * curve);
    drawJoint(21, 23, anim, intensity * curve);
    
    drawJoint(17, 16, anim, intensity * curve);
    drawJoint(17, 19, anim, intensity * curve);
    
    drawJoint(13, 12, anim, intensity * curve);
    drawJoint(13, 15, anim, intensity * curve);
    
    drawJoint(5, 4, anim, intensity * curve);
    drawJoint(5, 7, anim, intensity * curve);
    
    drawJoint(10, 0, anim, intensity * curve);
}

//--------------------------------------------------------------
void sukanyaScene::update(){
    
}

//--------------------------------------------------------------
void sukanyaScene::draw(){
    float scaledFrame = ofGetFrameNum()*stopSize;
    t = ofWrap(scaledFrame, 0, 30);
    int frameNumber = (int)(scaledFrame) % 30;
    
    
    
    float tm = ofGetElapsedTimef();
    float intensity = 30;
    
    
    
    
    //ofBackground(0);
    ofSetColor(255);
    ofSetLineWidth(3);
    //cam.begin();
    //cam.enableOrtho();


    ofLine(0,0,100,100);
    
    
    //drawMan(tm, intensity*fmod(pow(0.5*tm, 2), 40));

    ofPushMatrix();
    ofTranslate(-360, 0, 0);
    drawMan(tm, 0, intensity);
    ofPopMatrix();

    ofPushMatrix();
    ofTranslate(-240, 0, 0);
    drawMan(tm, .1, intensity);
    ofPopMatrix();

    ofPushMatrix();
    ofTranslate(-120, 0, 0);
    drawMan(tm, .2, intensity);
    ofPopMatrix();

    drawMan(tm, .3, intensity);

    ofPushMatrix();
    ofTranslate(120, 0, 0);
    drawMan(tm, .4, intensity);
    ofPopMatrix();

    ofPushMatrix();
    ofTranslate(240, 0, 0);
    drawMan(tm, .5, intensity);
    ofPopMatrix();

    ofPushMatrix();
    ofTranslate(360, 0, 0);
    drawMan(tm, .6, intensity);
    ofPopMatrix();

//    debug(frameNumber);
    //cam.end();
}

//--------------------------------------------------------------
void sukanyaScene::keyPressed(int key){
    
}

//--------------------------------------------------------------
void sukanyaScene::keyReleased(int key){
    
}

//--------------------------------------------------------------
void sukanyaScene::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void sukanyaScene::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void sukanyaScene::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void sukanyaScene::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void sukanyaScene::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void sukanyaScene::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void sukanyaScene::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void sukanyaScene::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void sukanyaScene::dragEvent(ofDragInfo dragInfo){
    
}
