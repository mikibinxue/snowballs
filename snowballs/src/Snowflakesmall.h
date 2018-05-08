//
//  Snowflake.h
//  OOP-tester
//
//  Created by Miki Bin on 2/19/18.
//

#ifndef Snowflakesmall_h
#define Snowflakesmall_h

#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework


class Snowflakesmall{
public:
    
    void setup();
    void update();
    void display();
    void applyForce(ofVec2f force);
    bool checkDistance(ofVec2f centroid);
    void checkEdges();
    void calculateRepulsion();
    
    
    //variables
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofVec2f repulsionCenter;
    
    string word;
    int dim;
    ofColor color;
    bool if_close;

    
    Snowflakesmall();
    ofTrueTypeFont myfont;
private:
};

#endif /* Snowflakesmall_h */
