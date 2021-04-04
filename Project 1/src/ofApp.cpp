#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.load("uae.png");
    gui.setup();
    gui.add(intSlider.setup("day or night", 150, 150, 800));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    drawHouses();
    drawCity();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::drawCity(){
    if (intSlider < 500)
        ofSetBackgroundColor(79, 210, 210);
    else
        ofSetBackgroundColor(0, 102, 204);
    
    // colors
    ofColor yellow(241,183,38);
    ofColor red(214,58,41);
    
    // draw land
    ofSetColor(70, 70, 70);
    ofFill();
    ofDrawRectangle(0, ofGetHeight()-207, ofGetWidth(), (ofGetHeight()-image.getHeight())/2+100);
    ofSetColor(red);
    ofFill();
    ofDrawBitmapString("Paper Town", ofGetWidth()/2-50, ofGetHeight()-107);
    
    // draw image
    ofSetColor(255, 255, 255);
    ofFill();
    image.draw(ofGetWidth()/2-image.getWidth()/2, ofGetHeight()/2-image.getHeight()/2);
    image.resize(633, 407);
    
    // draw sun
    if (intSlider < 500)
        ofSetColor(yellow);
    else
        ofSetColor(211, 211, 211);
    ofFill();
    ofSetCircleResolution(100);
    ofDrawCircle(intSlider, 100, 50);
    ofSetColor(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::drawHouses(){
    // declare colors
    ofColor yellow(241,183,38);
    ofColor grey(47,49,46);
    ofColor red(214,58,41);
    ofColor green(87,152,113);
    ofColor blue(51,130,138);
    ofColor beige(104,92,84);
    
    // house 1
    ofSetColor(yellow);
    ofFill();
    ofDrawRectangle(30, ofGetHeight()-407, 100, 350);
    ofSetColor(grey);
    ofFill();
    ofDrawTriangle(29, 360, 79, 273, 129, 362);
    ofDrawRectangle(46, 384, 30, 30);
    ofPushStyle();
    ofRotateXDeg(10);
    ofDrawRectangle(130, 384, 30, 30);
    ofRotateXDeg(-10);
    ofPopStyle();
    ofDrawRectangle(86, 427, 30, 30);
    ofDrawRectangle(46, 427, 30, 30);
    ofPushStyle();
    ofRotateXDeg(10);
    ofDrawRectangle(101, 467, 30, 30);
    ofRotateXDeg(-10);
    ofPopStyle();
    ofDrawRectangle(86, 472, 30, 30);
    ofDrawRectangle(47, 514, 30, 30);
    ofDrawRectangle(86, 514, 30, 30);
    
    // house 2
    ofSetColor(blue);
    ofFill();
    ofDrawRectangle(150, ofGetHeight()-407, 70, 300);
    ofSetColor(red);
    ofFill();
    ofDrawTriangle(143, 389, 194, 331, 230, 378);
    ofDrawRectangle(166, 493, 30, 70);
    
    // house 3
    ofSetColor(red);
    ofFill();
    ofDrawRectangle(ofGetWidth() - 210, ofGetHeight()-407, 100, 350);
    ofSetColor(green);
    ofFill();
    ofDrawTriangle(796, 370, 868, 311, 906, 378);
    ofDrawRectangle(828,393,20,50);
    ofDrawRectangle(858,393,30,120);
    ofDrawRectangle(828,453,30,120);
    
    
    // house 4
    ofSetColor(beige);
    ofFill();
    ofDrawRectangle(ofGetWidth() - 90, ofGetHeight()-407, 70, 300);
    ofSetColor(yellow);
    ofFill();
    ofDrawTriangle(925, 404, 961, 268, 1013, 404);
    ofDrawRectangle(955,441,30,120);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        snapped = true;
    }
    if (snapped == true){
        imgScreenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        imgScreenshot.save("screenshot_"+ofToString(count, 3, '0')+".png");
        count++;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    cout << ofGetMouseX() << endl;
    cout << ofGetMouseY() << endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
