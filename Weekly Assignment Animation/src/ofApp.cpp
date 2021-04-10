#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int margin = 100;
    
    mario_00.load("00.png");
    mario_01.load("01.png");
    mario_02.load("02.png");
    mario_03.load("03.png");
    
    movement.push_back(mario_00);
    movement.push_back(mario_01);
    movement.push_back(mario_02);
    movement.push_back(mario_03);
    
    posX = ofGetWidth()/2;
    posY = mario_00.getHeight()/2;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    movement[step].draw(posX, posY);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 's'){
        posY += speed;
    }
    
    if(ofGetFrameNum() % speed == 0){
          step = (step + 1) % 4;
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
