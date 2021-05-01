#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
        void loadSounds();
    
        void soundManipulation(int index);

		
    vector<ofSoundPlayer> sounds;
    ofSoundPlayer s1, s2, s3, s4, s5, s6, s7;
    bool autoPlay;
    float tempo, currTime;
    int totalVoices;
    int time;
		
};
