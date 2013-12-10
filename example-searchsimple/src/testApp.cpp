#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofSetFrameRate(30);
    
    // You must create your app and obtain your own keys at https://dev.twitter.com/apps
    // Don«t forget to provide also a Callback URL http://mydomain.com on the form
    // (can be anything, its like a boolean saying "yes, my application can use callback-base)
    // ofxOAuth will go through the autorization proccess and will create an credentials.xml file on the data folder with your info
    
    string const CONSUMER_KEY = "VyZSL4qYqiiolN9P6uJgg";
    string const CONSUMER_SECRET = "uYwllm7aTxTVzvbG7MEJDcJjrRLPADJzAeY2PIQCY";
    
    twitterClient.authorize(CONSUMER_KEY, CONSUMER_SECRET);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    
    string info;
    info += "App Authorized: " + ofToString(twitterClient.isAuthorized());
    info += "\nTweets loaded: " + ofToString(twitterClient.getTotalLoadedTweets());
    
    ofSetColor(0);
    ofDrawBitmapString(info, ofPoint(20,20));
    
    if(twitterClient.getTotalLoadedTweets() > 0) {
        ofDrawBitmapStringHighlight(info, ofPoint(20,20));
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    if(key == 'q') {
        twitterClient.startQuery("cat");
    }
    
    if(key == 'l') {
        twitterClient.loadCacheFile();
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
