#include "ailadiScene.h"
//#include "data.h"

//--------------------------------------------------------------
void ailadiScene::setup(){

    studentName = "Ailadi";
    //charging the image:
    wheel.load("ailadi/wheel.png");
    
    for (int x=0; x<wheel.getWidth(); x++){
        for (int y=0; y<wheel.getHeight(); y++){
            if(wheel.getColor(x,y).a > 127){
                
                pixel temp;
                temp.pos = ofPoint (x,y);
                temp.orig = ofPoint (x-wheel.getWidth()/2,y-wheel.getHeight()/2);
                temp.color = wheel.getColor(x,y);
                temp.magnetism = ofRandom(0.5,0.99);
                pixels.push_back(temp);
            }
        }
    }

    // taking the midi
    //ofSetVerticalSync(true);
    //ofBackground(255);

//    midiIn.listPorts(); // via instance
//    midiIn.openPort(0);
//    midiIn.ignoreTypes(false, false, false);
//    midiIn.addListener(this);
//    midiIn.setVerbose(true);
//
    value = 0;
    ofSetCircleResolution(80);
    
//    midiControl.resize(71);

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
}

//--------------------------------------------------------------
void ailadiScene::update(){
    
    //check for midi
//    for(int i = 0; i < 71; i++){
//        if(midiMessage.control == i){
//            midiControl[i] = midiMessage.value;
//        }
//    }
    
}


//--------------------------------------------------------------
void ailadiScene::draw(){

   // ofBackground(255);
    // you don't have to touch this either:) ----- copy data into array
    ofPoint data3d[24];
    int frameNumber =(int)(ofGetFrameNum()*0.4) % 30;
    for (int i = 0; i < 24; i++){
        data3d[i] = frames[ frameNumber][i];
    } // end do not touch
    
    float time = ofGetElapsedTimef();
   // cam.begin();
   // cam.enableOrtho();
    ofSetColor(255);

    ofMesh mesh;
//    OF_PRIMITIVE_TRIANGLE_STRIP,
//    OF_PRIMITIVE_TRIANGLE_FAN,
//    OF_PRIMITIVE_LINE_LOOP,
      mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    
    float num = 1.0;
    
    for (int i=0; i<25; i++) {
        mesh.addVertex( data3d[12]*num);
        mesh.addVertex( data3d[13]*num);
        mesh.addVertex( data3d[14]*num);
        mesh.addVertex( data3d[15]*num);
        mesh.addVertex( data3d[21]*num);
        mesh.addVertex( data3d[22]*num);
        mesh.addVertex( data3d[23]*num);
        mesh.addVertex( data3d[19]*num);
        mesh.addVertex( data3d[18]*num);
        mesh.addVertex( data3d[17]*num);
        mesh.addVertex( data3d[7]*num);
        mesh.addVertex( data3d[6]*num);
        mesh.addVertex( data3d[5]*num);
        mesh.addVertex( data3d[4]*num);
        mesh.addVertex( data3d[3]*num);
        
        
        
//        white, gray, black, red, green, blue, cyan, magenta,
//        yellow,aliceBlue,antiqueWhite,aqua,aquamarine,azure,beige,bisque,blanchedAlmond,
//        blueViolet,brown,burlyWood,cadetBlue,chartreuse,chocolate,coral,cornflowerBlue,cornsilk,
//        crimson,darkBlue,darkCyan,darkGoldenRod,darkGray,darkGrey,darkGreen,darkKhaki,
//        darkMagenta,darkOliveGreen,darkorange,darkOrchid,darkRed,darkSalmon,darkSeaGreen,
//        darkSlateBlue,darkSlateGray,darkSlateGrey,darkTurquoise,darkViolet,deepPink,
//        deepSkyBlue,dimGray,dimGrey,dodgerBlue,fireBrick,floralWhite,forestGreen,fuchsia,
//        gainsboro,ghostWhite,gold,goldenRod,grey,greenYellow,honeyDew,hotPink,indianRed,indigo,
//        ivory,khaki,lavender,lavenderBlush,lawnGreen,lemonChiffon,lightBlue,lightCoral,
//        lightCyan,lightGoldenRodYellow,lightGray,lightGrey,lightGreen,lightPink,lightSalmon,
//        lightSeaGreen,lightSkyBlue,lightSlateGray,lightSlateGrey,lightSteelBlue,lightYellow,
//        lime,limeGreen,linen,maroon,mediumAquaMarine,mediumBlue,mediumOrchid,mediumPurple,
//        mediumSeaGreen,mediumSlateBlue,mediumSpringGreen,mediumTurquoise,mediumVioletRed,
//        midnightBlue,mintCream,mistyRose,moccasin,navajoWhite,navy,oldLace,olive,oliveDrab,
//        orange,orangeRed,orchid,paleGoldenRod,paleGreen,paleTurquoise,paleVioletRed,papayaWhip,
//        peachPuff,peru,pink,plum,powderBlue,purple,rosyBrown,royalBlue,saddleBrown,salmon,
//        sandyBrown,seaGreen,seaShell,sienna,silver,skyBlue,slateBlue,slateGray,slateGrey,snow,
//        springGreen,steelBlue,blueSteel,tan,teal,thistle,tomato,turquoise,violet,wheat,whiteSmoke,
//        yellowGreen

        mesh.addColor(ofColor::cornflowerBlue);
        mesh.addColor(ofColor::orangeRed);
        mesh.addColor(ofColor::salmon);
        mesh.addColor(ofColor::whiteSmoke);
        mesh.addColor(ofColor::pink);
        mesh.addColor(ofColor::coral);
        mesh.addColor(ofColor::hotPink);
        mesh.addColor(ofColor::lightPink);
        mesh.addColor(ofColor::fuchsia);
        mesh.addColor(ofColor::deepPink);
        mesh.addColor(ofColor::pink);
        mesh.addColor(ofColor::paleVioletRed);
        mesh.addColor(ofColor::pink);
        mesh.addColor(ofColor::papayaWhip);
        mesh.addColor(ofColor::pink);

    
        //ofDrawLine(data3d[i], data3d[0]);
//        ofSetColor(255,118,234);
//        float r = ofMap(sin(time/2), -1, 1, 4, 14);
//        ofDrawSphere(data3d[i]*num, r);
        
    }
//        float x = data3d[i].x;
//        float y = data3d[i].y;
//        float z = data3d[i].z;
//        z += ofSignedNoise(x*0.01, y*0.01, time) * ofMap(sin(time), -1, 1, 0, 400);
//
//        ofDrawSphere(ofPoint(x,y,z), 5);
        //ofDrawBitmapString(ofToString(i), data3d[i]);
  

    
    //end
    ofSetColor(59, 4, 69);
    //ofDrawSphere(data3d[10]*num, midiControl[0]);
    //ofCircle(data3d[18], 10);

    
    
    //calculate rotating images points
    for (int i=0; i< pixels.size(); i++){
        
            float t = ofGetElapsedTimef();
            float magnetism = pixels[i].magnetism;
            
            ofPoint original = pixels[i].orig;
            float distance = ofDist(0, 0, original.x, original.y);
            float angle = atan2(original.y, original.x);
            angle = angle + t;
            
            ofPoint newOrig;
            newOrig.x = 0 + distance*cos(angle);
            newOrig.y = 0 + distance*sin(angle);
            
            float currPosX = pixels[i].pos.x;
            float newPosX = data3d[10].x*num + newOrig.x;
            pixels[i].pos.x = currPosX * magnetism + newPosX * (1-magnetism);
        
            float currPosY = pixels[i].pos.y;
            float newPosY = data3d[10].y*num + newOrig.y;
            pixels[i].pos.y = currPosY * magnetism + newPosY * (1-magnetism);
        
        
    }
    
    //draw turning wheel
    for (int i=0; i<pixels.size(); i++){
        ofSetColor(pixels[i].color);
        ofDrawCircle(pixels[i].pos.x, pixels[i].pos.y, 1);
    }
    
    mesh.draw();
    //cam.end();
    
}
void ailadiScene::exit() {
    
    // clean up
    //midiIn.closePort();
    //midiIn.removeListener(this);
}

////--------------------------------------------------------------
//void ailadiScene::newMidiMessage(ofxMidiMessage& msg) {
//
//    // make a copy of the latest message
//    midiMessage = msg;
//}
//--------------------------------------------------------------
void ailadiScene::keyPressed(int key){

}

//--------------------------------------------------------------
void ailadiScene::keyReleased(int key){

}

//--------------------------------------------------------------
void ailadiScene::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ailadiScene::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ailadiScene::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ailadiScene::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ailadiScene::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ailadiScene::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ailadiScene::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ailadiScene::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ailadiScene::dragEvent(ofDragInfo dragInfo){

}
