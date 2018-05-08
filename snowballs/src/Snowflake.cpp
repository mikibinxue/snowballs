//
//  Snowflake.cpp
//  OOP-tester
//
//  Created by Miki Bin on 2/19/18.
//

#include "Snowflake.h"

Snowflake::Snowflake(){
    
}

void Snowflake:: setup(){

    
    position.set(ofRandom(ofGetWidth()),ofRandom(ofGetHeight())-600);
    
    velocity.set(0,0);

    dim = 20;
    
    color.set(255); // one way of defining digital color is by addressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
    
    myfont.loadFont("Champions-Bold.ttf", 32);
}

void Snowflake::applyForce(ofVec2f _force){
    ofVec2f acc = _force/1;
    acceleration += acc;

}

void Snowflake::update(){
    velocity += acceleration;
    position += velocity;
        acceleration *= 0;
    
    
}

void Snowflake::display(){
    ofSetColor(color);
    //ofDrawCircle(position.x, position.y, dim);
    myfont.drawString("snow", position.x, position.y);
//    ofDrawBitmapString("snow", position.x, position.y);
}

void Snowflake::checkEdges(){
    if(position.y> ofGetHeight()){
        position.set(ofRandom(ofGetWidth()),ofRandom(ofGetHeight())-600);
        color.set(255);
        velocity.set(0,0);
        
    }
}


bool Snowflake::checkDistance(ofVec2f _centroid){
    
    
    ofVec2f centroid;
    centroid = _centroid;
    
    float distance = position.distance(centroid);
    
    if(distance < 50){
        return true;
    };
    return false;
    
}


