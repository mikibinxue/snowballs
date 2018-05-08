//
//  Snowflakesmall.cpp
//  OOP-tester
//
//  Created by Miki Bin on 2/19/18.
//

#include "Snowflakesmall.h"

Snowflakesmall::Snowflakesmall(){
    
}

void Snowflakesmall:: setup(){

    position.set(0,0);
    
    velocity.set(0,0);

    color.set(255); // one way of defining digital color is by addressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
    
    myfont.loadFont("Champions-Bold.ttf", 12);
    
    repulsionCenter.set(0,0);
    
    
    int temp = int(ofRandom(0,5));
    switch(temp){
        case 0:
            word = "s";
            break;
            
        case 1:
            word = "n";
            break;
        
        case 2:
            word = "o";
            break;
            
        case 3:
            word = "w";
            break;
            
//        case 4:
//
//            break;
        
    }
    
    
}

void Snowflakesmall::applyForce(ofVec2f _force){
    ofVec2f acc = _force/1;
    acceleration += acc;

}

void Snowflakesmall::update(){
    velocity += acceleration;
    position += velocity;
        acceleration *= 0;
    
}

void Snowflakesmall::display(){
    ofSetColor(color);
    //ofDrawCircle(position.x, position.y, dim);
    myfont.drawString(word, position.x, position.y);
//    ofDrawBitmapString("snow", position.x, position.y);
}

void Snowflakesmall::checkEdges(){
    if(position.y> ofGetHeight()){
        position.set(ofRandom(ofGetWidth()),ofRandom(ofGetHeight())-600);
        color.set(255);
        velocity.set(0,0);
        
    }
}


bool Snowflakesmall::checkDistance(ofVec2f _centroid){
    
    
    ofVec2f centroid;
    centroid = _centroid;
    
    float distance = position.distance(centroid);
    
    if(distance < 50){
        return true;
    };
    return false;
    
}

void Snowflakesmall::calculateRepulsion(){
    ofVec2f v = position -repulsionCenter;
    float d = v.length();
    float f = 1000/d/d;
    v = v.getNormalized()*f;
    applyForce(v);
    
}


