#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(30);
    
    // You must obtain your own keys at https://dev.twitter.com/
    // You need to provide also a Callback URL http://mydomain.com on the form
    // (its like a boolean saying "yes, my application can use callback-base
    // ofxOAuth will go through the autorization proccess and will create an credentials.xml file
    // On the data folder with your info.
    twitterClient.authorize("VyZSL4qYqiiolN9P6uJgg", "uYwllm7aTxTVzvbG7MEJDcJjrRLPADJzAeY2PIQCY");
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    
    string info;
    info += "Autorizado: " + ofToString(twitterClient.isAuthorized());
    
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
