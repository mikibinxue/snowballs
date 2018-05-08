#pragma once

#include "ofMain.h"
#include "Snowflake.h"
#include "Snowflakesmall.h"
#include "Snowball.h"

#include "ofxOpenCv.h"
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
    
    
    //to set up function to call small snow flakes
    void generateSmallSnowFlakes(ofVec2f _position);
    
    vector <Snowflake> snows;
    vector <Snowflakesmall> small_snows;
    vector <Snowball> snowballs;
    ofVec2f g;
    
    ofVideoGrabber         vidGrabber;
    
    ofxCvColorImage            myColorImg;
    
    ofxCvGrayscaleImage     myGrayImage;
    ofxCvGrayscaleImage     myBackground;
    ofxCvGrayscaleImage     myGrayDiff;
    
    ofxCvContourFinder     contourFinder;
    
    
    
    int                 threshold;
    bool                bLearnBackground;
    bool                bShowVideo = true;
    int state = 1;
    
    int num_snowball = 3;
    int num_snowflake = 10;

		
};
