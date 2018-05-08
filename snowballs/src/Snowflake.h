//
//  Snowflake.h
//  OOP-tester
//
//  Created by Miki Bin on 2/19/18.
//

#ifndef Snowflake_h
#define Snowflake_h

#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework

class Snowflake{
public:
    
    void setup();
    void update();
    void display();
    void applyForce(ofVec2f force);
    bool checkDistance(ofVec2f centroid);
    void checkEdges();
    
    
    //variables
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;

    int dim;
    ofColor color;
    bool if_close;
    
    Snowflake();
    ofTrueTypeFont myfont;
private:
};

#endif /* Snowflake_h */
