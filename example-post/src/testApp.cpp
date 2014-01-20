#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofSetFrameRate(30);
    
    string const CONSUMER_KEY = "";
    string const CONSUMER_SECRET = "";
    string const ACCESS_TOKEN = "";
    string const ACCESS_SECRET = "";
    
    twitterClient.authorize(CONSUMER_KEY, CONSUMER_SECRET,ACCESS_TOKEN,ACCESS_SECRET);

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
    ofDrawBitmapString(info, ofPoint(20,20));
    
    twitterClient.printDebugInfo();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    if(key == 'q') {
        twitterClient.postStatus("test");
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
