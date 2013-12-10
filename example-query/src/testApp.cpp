#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofSetFrameRate(30);
    
    string const CONSUMER_KEY = "VyZSL4qYqiiolN9P6uJgg";
    string const CONSUMER_SECRET = "uYwllm7aTxTVzvbG7MEJDcJjrRLPADJzAeY2PIQCY";
    
    twitterClient.authorize(CONSUMER_KEY, CONSUMER_SECRET);
    
    actualTweet = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){

    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // Print tweets:
    
    int maxLineSize = 90;
    
    if(twitterClient.getTotalLoadedTweets() > 0) {
        
        tweet = twitterClient.getTweetByIndex(actualTweet);
        
        ofDrawBitmapString("User:", ofPoint(20,90));
        ofDrawBitmapStringHighlight(tweet.user.screen_name, ofPoint(120,90));
        
        ofDrawBitmapString("Location:", ofPoint(20,120));
        ofDrawBitmapStringHighlight(tweet.user.location, ofPoint(120,120));
        
        ofDrawBitmapString("Descript.:", ofPoint(20,150));
        string desc = tweet.user.description;
        for(int i=0;i<(desc.length()/maxLineSize)+1;i++) {
            ofDrawBitmapStringHighlight(desc.substr(i*maxLineSize,maxLineSize), ofPoint(120,150+(30*i)));
        }
        
        ofDrawBitmapString("Text:", ofPoint(20,240));
        string text = tweet.text;
        for(int i=0;i<(text.length()/maxLineSize)+1;i++) {
            ofDrawBitmapStringHighlight(text.substr(i*maxLineSize,maxLineSize), ofPoint(120,240+(30*i)));
        }
        
    }
    
    // Aditional info:
    
    string info;
    info += "App Authorized: " + ofToString(twitterClient.isAuthorized());
    info += "\nTweets loaded: " + ofToString(twitterClient.getTotalLoadedTweets());
    if(twitterClient.getTotalLoadedTweets() > 0) {
        info += "\nShowing: " + ofToString(actualTweet+1) + " / "+ofToString(twitterClient.getTotalLoadedTweets());
    }
    
    ofSetColor(0);
    ofDrawBitmapString(info, ofPoint(20,20));
    
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
    
    if(key == OF_KEY_UP) {
        if(actualTweet < twitterClient.getTotalLoadedTweets()-1) actualTweet += 1;
    }
    
    if(key == OF_KEY_DOWN) {
        if(actualTweet > 0) actualTweet -= 1;
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
