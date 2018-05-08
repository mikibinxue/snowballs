//
//  Snowball.cpp
//  OOP-tester
//
//  Created by Miki Bin on 2/22/18.
//

#include "Snowball.h"


Snowball::Snowball(){
    
}

void Snowball:: setup(){
    
    
    position.set(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    
    dim = ofRandom(18,25);
    
    color.set(255); // one way of defining digital color is by addressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
    
}


void Snowball::update(){
    dim +=1;

}

bool Snowball::if_burst(){
    if(dim> 40){
        return true;
    }
    return false;
    
    
}

void Snowball::display(){
    ofSetColor(color);
    ofDrawCircle(position.x, position.y, dim);

}



