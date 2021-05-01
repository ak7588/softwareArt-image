#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    loadSounds();
    tempo = 7000;
    autoPlay = true;
    currTime = ofGetSystemTimeMillis();
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0, 0, 0, 10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    if (autoPlay) {
        if (ofGetSystemTimeMillis() > currTime + tempo) {
            int num = ofRandom(totalVoices);
            sounds[num].play();
            currTime = ofGetSystemTimeMillis();
        }
    }
    
    ofColor drawColor;
    int length = 10000;
    int barWidth = 80;
    float bandsToGet = 512;
    float width = float (5 * 128);
    float * val = ofSoundGetSpectrum(bandsToGet);
    for (int  i = 0; i < bandsToGet; i++) {
        ofPushMatrix();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofRotateDeg(360 / bandsToGet * i);
        drawColor.setHsb(255 / bandsToGet * i, 255, 255, 50);
        ofSetColor(drawColor);
        // ofDrawRectangle(100, -barWidth/2, val[i] * length, barWidth / 2);
        ofDrawCircle(100, -barWidth/2, val[i] * length);
        drawColor.setHsb(255 / bandsToGet * i, 0, 255, 50);
        ofSetColor(drawColor);
        ofDrawCircle(100, -barWidth/2, sin (i * 0.1 + currTime));
        ofPopMatrix();
        // ofDrawCircle(ofGetWidth()/2 + 100 * sin (i * 0.1 + currTime), i, 10);
    }
    
    string text = "How far is the Sun?";
    
    ofPushStyle();
    ofSetColor(0);
    time = ofGetElapsedTimef();
    if (time < 10 ) {
        ofDrawBitmapString(text, ofGetWidth()/2 - 100, ofGetHeight() - 200);
    }
    else if (time < 15 ) {
        text = "Scientists say it's 150 million km away.";
        ofDrawBitmapString(text, ofGetWidth()/2 - 120, ofGetHeight() - 200);
    }
    else if (time < 20 ) {
        text = "But what if you shine just as bright?";
        ofDrawBitmapString(text, ofGetWidth()/2 - 120, ofGetHeight() - 200);
    }
    else if (time < 25 ) {
        text = "Then which color is your spark?";
        ofDrawBitmapString(text, ofGetWidth()/2 - 100, ofGetHeight() - 200);
    }
    else if (time < 30 ) {
        text = "Safe travels!";
        ofDrawBitmapString(text, ofGetWidth()/2 - 50, ofGetHeight() - 200);
    }
    else if (time < 40 ) {
        text = "Welcome to Planet Earth!";
        ofSetColor(255);
        ofDrawBitmapString(text, ofGetWidth()/2 - 100, 200);
    }
    ofPopStyle();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1':
            sounds[0].play();
            soundManipulation(0);
            break;
        case '2':
            sounds[1].play();
            soundManipulation(1);
            break;
        case '3':
            sounds[2].play();
            soundManipulation(2);
            break;
        case '4':
            sounds[3].play();
            soundManipulation(3);
            break;
        case '5':
            sounds[4].play();
            soundManipulation(4);
            break;
        case '6':
            sounds[5].play();
            soundManipulation(5);
            break;
        case '7':
            sounds[6].play();
            soundManipulation(6);
            break;
        case 'a':
            autoPlay = !autoPlay;
            break;
        case '-':
            if (tempo > 1000)
                tempo -= 500;
            break;
        case '=':
            tempo += 500;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp:: soundManipulation(int index) {
    float widthStep = ofGetWidth() / 3.0f;
        if (ofGetMouseX() < widthStep){
            sounds[index].play();
            sounds[index].setSpeed( 0.1f + ((float)(ofGetHeight() - ofGetMouseY()) / (float)ofGetHeight())*10);
            sounds[index].setPan(ofMap(ofGetMouseX(), 0, widthStep, -1, 1, true));
        } else if (ofGetMouseX() >= widthStep && ofGetMouseX() < widthStep*2){
            sounds[index].play();
        } else {
            sounds[index].play();
            sounds[index].setSpeed( 0.1f + ((float)(ofGetHeight() - ofGetMouseY()) / (float)ofGetHeight())*3);
            sounds[index].setPan( ofMap(ofGetMouseX(), widthStep*2, widthStep*3, -1, 1, true) );
        }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::loadSounds(){
    totalVoices = 7;
    sounds.clear();
    for (int i = 0; i < totalVoices; i++) {
        ofSoundPlayer sound;
        sound.load(ofToString(i) + ".wav");
        sound.setMultiPlay(true);
        sounds.push_back(sound);
        sounds[i].setVolume(0.5f);
    }
}
