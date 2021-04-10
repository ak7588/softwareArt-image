#pragma once

#include "ofMain.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofImage mario_00;
        ofImage mario_01;
        ofImage mario_02;
        ofImage mario_03;
    
        int direction = 1;
        int step = 0;
        int score = 0;
        int posX, posY;
        int diamondX, diamondY;
        int speed = 2;
        int row = 4;
        int col = 4;
        int currentWidth, currentHeight;
        
        vector<ofImage> movement;

};
