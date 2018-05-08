#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //for opencv
    vidGrabber.setup(480,360);
    
    
    myColorImg.allocate(vidGrabber.getWidth(),vidGrabber.getHeight());
    myGrayImage.allocate(vidGrabber.getWidth(),vidGrabber.getHeight());
    myBackground.allocate(vidGrabber.getWidth(),vidGrabber.getHeight());
    myGrayDiff.allocate(vidGrabber.getWidth(),vidGrabber.getHeight());
    
    bLearnBackground = true;
    threshold = 1;
    ofSetBackgroundAuto(false);
    
    //for snowflakes
    for(int i=0; i<num_snowflake; i++){
        Snowflake temp;
        snows.push_back(temp);
        snows[i].setup();
    }
    
    //for snowballs
    for(int i=0; i<num_snowball; i++){
        Snowball temp;
        snowballs.push_back(temp);
        snowballs[i].setup();
    }
    
    g.set(0,0.001);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //for opencv
    bool bNewFrame = false;
    
    
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
    
    if (bNewFrame){
        
        
        myColorImg.setFromPixels(vidGrabber.getPixels());
        
        myGrayImage = myColorImg;
        if (bLearnBackground == true){
            myBackground = myGrayImage;        // the = sign copys the pixels from grayImage into grayBg (operator overloading)
            bLearnBackground = false;
        }
        
        // take the abs value of the difference between background and incoming and then threshold:
        //myGrayDiff.absDiff(myBackground, myGrayImage);
        myGrayImage -= myBackground;
        myGrayDiff = myGrayImage;
        myGrayDiff.threshold(threshold, true);
        
        // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
        // also, find holes is set to true so we will get interior contours as well....
        contourFinder.findContours(myGrayDiff, 200, 480*360/2, num_snowball, false);
       
    }
    
    //for the balls
    //update existing balls

    for(int i=0; i<snows.size(); i++){
        snows[i].checkEdges();
        snows[i].applyForce(g);
        snows[i].update();
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw the incoming video image
    
//    for opencv
    ofBackground(205,245,249,10);

    // draw the incoming video image
    ofSetHexColor(0xffffff);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2 - myColorImg.getWidth()/2,ofGetHeight()/2 - myColorImg.getHeight()/2);
    /*
     uncomment this to turn on the video background
     */
//    if(bShowVideo){
//        myGrayDiff.draw(0,0);
//    }
//
    
          for (int i = 0; i < contourFinder.nBlobs; i++){
//            ofSetColor(ofColor::fuchsia);
//            ofFill();
//            //ofDrawEllipse(contourFinder.blobs[i].boundingRect.getCenter(), 20,20);
//            ofDrawEllipse(contourFinder.blobs[i].centroid, 20,20);
              int id = i;
              ofVec2f temp_centroid;
              temp_centroid.set(contourFinder.blobs[i].centroid);
              
              
              snowballs[id].position.set(temp_centroid);
              snowballs[id].display();
              
             
              
                      for(int i=0; i<snows.size(); i++){
                          if(snows[i].checkDistance(temp_centroid)){
                              snows[i].color.set(205,245,249);
                              snowballs[id].update();
                              if(snowballs[id].if_burst()){
                                  generateSmallSnowFlakes(snowballs[id].position);
                                  snowballs[id].dim = 0;
                                  
                              }

                          };
                          snows[i].update();
                          snows[i].display();
                      }
              
              //for smallsnowballs
              for(int i=0; i<small_snows.size(); i++){
                  small_snows[i].calculateRepulsion();
                  small_snows[i].update();
                  small_snows[i].display();
              }
        }


    ofPopMatrix();
    



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        bLearnBackground = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------

void ofApp::generateSmallSnowFlakes(ofVec2f _position){
    for(int i=0; i<num_snowflake; i++){
        Snowflakesmall temp;
        small_snows.push_back(temp);
        small_snows[i].setup();
        float temp_x =ofGetMouseX() + ofRandom(-10,10);
        float temp_y =ofGetMouseY() + ofRandom(-10,10);
        
        small_snows[i].position.set(temp_x,temp_y);
        small_snows[i].repulsionCenter.set(ofGetMouseX(),ofGetMouseY());
        
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
