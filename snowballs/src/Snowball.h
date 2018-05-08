//
//  Snowball.h
//  OOP-tester
//
//  Created by Miki Bin on 2/22/18.
//

#ifndef Snowball_h
#define Snowball_h


#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework



class Snowball{
public:
    
    void setup();
    void update();
    void display();
    bool if_burst();

    //variables
    ofVec2f position;

    
    int dim;
    ofColor color;
    
    Snowball();

private:
};

#endif /* Snowball_h */
