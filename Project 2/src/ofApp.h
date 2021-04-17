#pragma once

#include "ofMain.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
        bool checkCollision();
        void replaceDiamond();
        void checkWin();
        void gameSetup();
        void playInstructions();
        void startGame();
        void winAnimation();
        void endGame();
        void updateButton();
        bool overRect(int x, int y, int width, int height);
        void drawButton();
    
        ofImage mario_00;
        ofImage mario_01;
        ofImage mario_02;
        ofImage mario_03;
    
        ofImage mario_04;
        ofImage mario_05;
        ofImage mario_06;
        ofImage mario_07;
        
        ofImage mario_08;
        ofImage mario_09;
        ofImage mario_10;
        ofImage mario_11;
        
        ofImage mario_12;
        ofImage mario_13;
        ofImage mario_14;
        ofImage mario_15;
    
        ofImage diamond;
        ofImage background;
        ofImage house;
    
        int step = 0;
        int score = 0;
        int posX, posY;
        int diamondX, diamondY;
        int speed = 6;
        int currentWidth, currentHeight;
        int screenNum = -1;
        bool rectOver = false;
        int rectSize = 100;
        int rectX = ofGetWidth()/2 - rectSize/2;
        int rectY = ofGetHeight()/2;
        int finalScore = 2;

        
        vector<ofImage> down;
        vector<ofImage> up;
        vector<ofImage> left;
        vector<ofImage> right;
    
        string scoring;
    
        bool isDown = false;
        bool isUp = false;
        bool isLeft = false;
        bool isRight = false;

};
