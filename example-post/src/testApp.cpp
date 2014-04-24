#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofSetFrameRate(30);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    string const CONSUMER_KEY = "";
    string const CONSUMER_SECRET = "";
    
    twitterClient.authorize(CONSUMER_KEY, CONSUMER_SECRET);

    actualTweet = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){

    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofSetColor(0);
    string info;
    info += "ofxTwitter post example:";
    info += "\nPress 'q' post a 'test' status";
    info += "\nPress i' post a 'test' status with an image";
    info += "\nPress h' to obtain info about media_upload service and image size support";
    ofDrawBitmapString(info, ofPoint(20,20));
    
    twitterClient.printDebugInfo();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    if(key == 'q') {
        twitterClient.postStatus("test status");
    }
    
    if(key == 'i') {
        
        twitterClient.postStatus("test image", "buses.png");
        //twitterClient.postStatus("test image", "buses.jpg");
        //twitterClient.postStatus("test image", "buses.gif");
        
    }
    
    if(key == 'h') {
        twitterClient.config.printPhotoSizesInfo();
    }
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
