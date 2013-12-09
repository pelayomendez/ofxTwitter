/*
 *  ofxTwitter.h
 *
 *  Created by Douglas Edric Stanley on 10/12/10
 *  cc-by-sa 2010 www.abstractmachine.net. Some rights reserved.
 *  http://creativecommons.org/licenses/by-sa/3.0/
 *
 *  Adapted from code by Paul Shen
 *  cf. http://in.somniac.me/2010/01/openframeworks-http-requests-xml-parser/
 *
 *  Edited by Andrew Vergara on 05/04/12
 *  Updated addon to fit most recent version of ofxHttpUtils addon. https://github.com/arturoc/ofxHttpUtils
 *
 *  Edited by welovecode 14/06/12
 *  Added cache support for saving/load xml cache file.
 *  Added POST query method.
 *
 *  Edited by Pelayo MŽndez on 09/12/13
 *  Migrate to Twitter API v1.1. https://dev.twitter.com/docs/api/1.1/overview
 *  Using Christopher Baker ofxOAuth adddon https://github.com/bakercp/ofxOAuth
 *  https://github.com/jefftimesten/ofxJSON ofxJSON for parsing data as XMl is not supported anymore
 */

#include "ofxTwitter.h"

//--------------------------------------------------------------
ofxTwitter::ofxTwitter():
bloadCacheActive(false),
bsaveCacheActive(true)
{

}

ofxTwitter::~ofxTwitter(){
}

//--------------------------------------------------------------
void ofxTwitter::setup(const string& consumerKey, const string& consumerSecret) {
    
    if(!bloadCacheActive) {
        oauth.setup("https://api.twitter.com", consumerKey, consumerSecret);
    } else {
        //loadCacheFile();
    }
	
}

void ofxTwitter::loadCacheFile() {
    // TODO.
}

bool ofxTwitter::isAuthorized() {
    return oauth.isAuthorized();
}

bool ofxTwitter::loadCacheIsActive() {
    return bloadCacheActive;
}

bool ofxTwitter::saveCacheIsActive() {
    return bsaveCacheActive;
}

//--------------------------------------------------------------
void ofxTwitter::startQuery(string keywords) {
    
    string query = "/1.1/search/tweets.json?count=1?q=";
    query += keywords;
    
    if(oauth.isAuthorized()) {
        dataRequested = "";
        dataRequested = oauth.get(query);
        ofAddListener(ofEvents().update,this,&ofxTwitter::newResponse);
    }
    
    //tweetQueryIdentifier = 0;

}

//--------------------------------------------------------------
void ofxTwitter::newResponse(ofEventArgs& args) {
    
    if(dataRequested != "") {
    
        ofxJSONElement result;
        bool parsingSuccessful = result.parse(dataRequested);
        if (parsingSuccessful) {
            if(bsaveCacheActive) result.save("cache.json",true);
            cout << "ofxTwitter: Tweets parsed OK." << endl;
            //cout << result.getRawString() << endl;
            parseResponse(result);
        } else {
            cout  << "ofxTwitter: Failed to parse JSON" << endl;
        }
        
        dataRequested = "";
        ofRemoveListener(ofEvents().update,this,&ofxTwitter::newResponse);
    
    }
	
}


void ofxTwitter::parseResponse(ofxJSONElement result) {
    
	data.clear();
   
    if(result.isMember("statuses")) {
        ofxJSONElement trends = result["statuses"];
        for(int i = 0; i < trends.size(); i++) {
            
            Tweet tweet;
            tweet.id = trends[i]["id_str"].asString();
            tweet.title = trends[i]["text"].asString();
            tweet.language = trends[i]["lang"].asString();
            
            //tweet.updated = trends[i]["text"].asString();
            //tweet.published = trends[i]["text"].asString();
            
            ofxJSONElement author = trends[i]["user"];
            
            tweet.author.name = author["screen_name"].asString();
            tweet.author.uri  = "https://twitter.com/"+author["screen_name"].asString();
            tweet.author.imageUri  = author["profile_image_url"].asString();
            tweet.author.profileimageUri  = author["profile_background_image_url"].asString();
            
            data.push_back( tweet );
            
            cout << tweet.print();
        }
    }
    
   
   
	// ok, send back results
	//if (delegate) {
		//delegate->searchResult(data, tweetQueryIdentifier);
	//}

}

