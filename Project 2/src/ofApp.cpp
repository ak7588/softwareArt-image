#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gameSetup();
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (screenNum == -1) {
        playInstructions();
    }
    
    else if (screenNum == 0) {
        startGame();
    }
    
    else if (screenNum == 1) {
        winAnimation();
    }
    
    else if (screenNum == 2) {
        endGame();
    }

}

//--------------------------------------------------------------
void ofApp::playInstructions(){
    background.draw(0, 0);
    ofPushStyle();
    ofSetColor(0);
    ofDrawBitmapString("Welcome to the game!", 130, 200);
    ofDrawBitmapString("Mario needs your help...", 130, 240);
    ofDrawBitmapString("Can you collect " + to_string(finalScore) + " diamonds?", 130, 260);
    ofDrawBitmapString("Press the button to start and use the keyboard keys to play.", 130, 280);
    ofPopStyle();
    drawButton();
    updateButton();
}


//--------------------------------------------------------------
void ofApp::endGame(){
    background.draw(0, 0);
    house.draw(-80, ofGetHeight() - 2*mario_00.getHeight() - 60);
    ofPushStyle();
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("The Game Animation is Over!", ofGetWidth()/2 - 120, ofGetHeight() / 2);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::winAnimation(){
    background.draw(0, 0);
    house.draw(-80, ofGetHeight() - 2*mario_00.getHeight() - 60);
    ofPushStyle();
    ofSetBackgroundColor(255, 255, 255);
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("Mario is happy and is going home!", ofGetWidth()/2 - 150, ofGetHeight() / 2);
    ofPopStyle();
    if (posY < ofGetHeight() - 2*mario_00.getHeight() + 10){
        down[step].draw(posX, posY);
        posY += 1;
        if (ofGetFrameNum() % speed == 0){
              step = (step + 1) % 4;
        }
    }
    else {
        left[step].draw(posX, posY);
        posX -= 1;
        if (ofGetFrameNum() % speed == 0){
              step = (step + 1) % 4;
        }
        if (posX < -10) {
            screenNum = 2;
        }
    }
}

//--------------------------------------------------------------
void ofApp::startGame() {
    
    background.draw(0, 0);
    house.draw(-80, ofGetHeight() - 2*mario_00.getHeight() - 60);
    diamond.draw(diamondX, diamondY);
    ofSetBackgroundColor(255, 255, 255);
    
    if (isDown)
        down[step].draw(posX, posY);
    if (isUp)
        up[step].draw(posX, posY);
    if (isLeft)
        left[step].draw(posX, posY);
    if (isRight)
        right[step].draw(posX, posY);
    if (checkCollision()) {
        score++;
    }
    
    ofPushStyle();
    ofSetColor(0, 0, 0);
    scoring = "Collected: " + to_string(score);
    ofDrawBitmapString(scoring, 10, 20);
    ofPopStyle();
    
    checkWin();
}

//--------------------------------------------------------------
void ofApp::gameSetup(){
    
    diamond.load("diamond.png");
    background.load("nature.jpeg");
    house.load("house.png");
    
    mario_00.load("00.png");
    mario_01.load("01.png");
    mario_02.load("02.png");
    mario_03.load("03.png");
    
    mario_04.load("04.png");
    mario_05.load("05.png");
    mario_06.load("06.png");
    mario_07.load("07.png");
    
    mario_08.load("08.png");
    mario_09.load("09.png");
    mario_10.load("10.png");
    mario_11.load("11.png");
    
    mario_12.load("12.png");
    mario_13.load("13.png");
    mario_14.load("14.png");
    mario_15.load("15.png");
    
    down.push_back(mario_00);
    down.push_back(mario_01);
    down.push_back(mario_02);
    down.push_back(mario_03);
    
    up.push_back(mario_04);
    up.push_back(mario_05);
    up.push_back(mario_06);
    up.push_back(mario_07);
    
    left.push_back(mario_08);
    left.push_back(mario_09);
    left.push_back(mario_10);
    left.push_back(mario_11);
    
    right.push_back(mario_12);
    right.push_back(mario_13);
    right.push_back(mario_14);
    right.push_back(mario_15);
    
    posX = 0;
    posY = ofGetHeight() - 2*mario_00.getHeight() + 10;
    diamondX = 200;
    diamondY = 150;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == OF_KEY_DOWN){
        isDown = true;
        isUp = false;
        isLeft = false;
        isRight = false;
        posY += speed;
    }
    if (key == OF_KEY_UP){
        isDown = false;
        isUp = true;
        isLeft = false;
        isRight = false;
        posY -= speed;
    }
    if (key == OF_KEY_LEFT){
        isDown = false;
        isUp = false;
        isLeft = true;
        isRight = false;
        posX -= speed;
    }
    if (key == OF_KEY_RIGHT){
        isDown = false;
        isUp = false;
        isLeft = false;
        isRight = true;
        posX += speed;
    }
    
    if (ofGetFrameNum() % speed == 0){
          step = (step + 1) % 4;
    }
}

//--------------------------------------------------------------
bool ofApp::checkCollision(){
    bool flag = false;
    bool prev = false;
    if(diamondX > posX && diamondX < posX + mario_00.getWidth()){
        if(diamondY > posY && diamondY < posY + mario_00.getHeight()){
            // the diamond is inside
            diamondX = -100;
            diamondY = -100;
            replaceDiamond();
            flag = true;
        }
    }
    return flag;
}

//--------------------------------------------------------------
void ofApp::checkWin(){
    if (score >= finalScore) {
        screenNum = 1;
    }
}

//--------------------------------------------------------------
void ofApp::replaceDiamond(){
    diamondX = rand() % ofGetWidth();
    diamondY = rand() % int(ofGetHeight() - 2*mario_00.getHeight() + 10);
}

//--------------------------------------------------------------
void ofApp::drawButton(){
    ofPushStyle();
        if (rectOver) {
            ofSetColor(133, 217, 74);
          } else {
            ofSetColor(98, 166, 88);
        }
        ofDrawRectangle(rectX, rectY, rectSize, rectSize/2);
        ofSetColor(0);
        ofDrawBitmapString("PLAY!", rectX + 30, rectY + 30);
    ofPopStyle();
}

//--------------------------------------------------------------
bool ofApp::overRect(int x, int y, int width, int height){
    if (mouseX >= x && mouseX <= x+width &&
      mouseY >= y && mouseY <= y+height) {
        return true;
    } else {
        return false;
    }
}

//--------------------------------------------------------------
void ofApp::updateButton(){
    if (overRect(rectX, rectY, rectSize, rectSize)) {
        rectOver = true;
      } else {
        rectOver = false;
      }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (rectOver) {
        screenNum = 0;
    }
}
