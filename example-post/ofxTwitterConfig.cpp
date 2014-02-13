//
//  ofxTwitterConfiguration.cpp
//  ofxTwitter
//
//  Created by Pelayo on 13/02/14.
//
//

#include "ofxTwitterConfig.h"




//--------------------------------------------------------------
int ofxTwitterConfig::getMaxMediaPerUpload() {
    
    return max_media_per_upload;
    
}

//--------------------------------------------------------------
int ofxTwitterConfig::getPhotoSizeLimit() {
    
    return photo_size_limit;
    
}

//--------------------------------------------------------------
void ofxTwitterConfig::printPhotoSizesInfo() {
    
    ofLogNotice("ofxTwitter::printPhotoSizesInfo") << "Media Upload Limits:";
    ofLogNotice("ofxTwitter::printPhotoSizesInfo") << "max_media_per_upload: " << max_media_per_upload;
    ofLogNotice("ofxTwitter::printPhotoSizesInfo") << "photo_size_limit: " << photo_size_limit;
    ofLogNotice("ofxTwitter::printPhotoSizesInfo") << "Supported Sizes:";
    for(int i = 0; i < photo_sizes.size(); i++) {
        ofLogNotice("ofxTwitter::printPhotoSizesInfo") << photo_sizes[i].name << ": " << photo_sizes[i].w << "x" << photo_sizes[i].h;
        ofLogNotice("ofxTwitter::printPhotoSizesInfo") << "resize type: " << photo_sizes[i].resize;
    }
    
}


