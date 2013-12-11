#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofSetFrameRate(30);
    
   
    twitterClient.setDiskCache(true);
    twitterClient.setAutoLoadImages(true, false); // Loads images into memory as ofImage;
    
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
    
    // Print tweets:
    
    int maxLineSize = 90;
    
    if(twitterClient.getTotalLoadedTweets() > 0) {
        
        tweet = twitterClient.getTweetByIndex(actualTweet);
        
        ofSetColor(255, 255, 255, 125);
        if(tweet.isBannerImageLoaded()) {
            tweet.user.profile_banner.draw(0, 0, ofGetWidth(), ofGetHeight());
        }
        
        ofSetColor(0);
        
        ofDrawBitmapString("User:", ofPoint(120,150));
        ofDrawBitmapStringHighlight(tweet.user.screen_name, ofPoint(220,150));
        
        ofDrawBitmapString("Location:", ofPoint(120,180));
        ofDrawBitmapStringHighlight(tweet.user.location, ofPoint(220,180));
        
        ofDrawBitmapString("Descript.:", ofPoint(120,210));
        string desc = tweet.user.description;
        for(int i=0;i<(desc.length()/maxLineSize)+1;i++) {
            ofDrawBitmapStringHighlight(desc.substr(i*maxLineSize,maxLineSize), ofPoint(220,210+(30*i)));
        }
        
        ofDrawBitmapString("Text:", ofPoint(120,300));
        string text = tweet.text;
        for(int i=0;i<(text.length()/maxLineSize)+1;i++) {
            ofDrawBitmapStringHighlight(text.substr(i*maxLineSize,maxLineSize), ofPoint(220,300+(30*i)));
        }
        
        ofSetColor(255, 255, 255);
        if(tweet.isProfileImageLoaded()) {
            tweet.user.profile_image.draw(40, 150);
        }
        
        ofSetColor(0);
        string nav = "Now showing tweet: " + ofToString(actualTweet+1) + " of "+ofToString(twitterClient.getTotalLoadedTweets());
        ofDrawBitmapString(nav, ofPoint(220,420));
        
    }
    
    ofSetColor(0);
    string info;
    info += "ofxTwitter query example:";
    info += "\nPress 'q' to get tweets containing 'cat'";
    info += "\nPress 'l' to load previous query from disk if avilable";
    info += "\nPress UP/DOWN to navigate tweets";
    ofDrawBitmapString(info, ofPoint(20,20));
    
    twitterClient.printDebugInfo();
    
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
