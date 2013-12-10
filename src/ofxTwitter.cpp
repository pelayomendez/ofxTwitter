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
 *  Migrated to Twitter API v1.1. https://dev.twitter.com/docs/api/1.1/overview
 *  Using Christopher Baker ofxOAuth adddon https://github.com/bakercp/ofxOAuth
 *  Using  ofxJSON for parsing data as XMl is not supported anymore https://github.com/jefftimesten/ofxJSON
 *
 */

#include "ofxTwitter.h"

//--------------------------------------------------------------
ofxTwitter::ofxTwitter():
bsaveCacheActive(true)
{

}

//--------------------------------------------------------------
ofxTwitter::~ofxTwitter(){
}

//--------------------------------------------------------------
void ofxTwitter::authorize(const string& consumerKey, const string& consumerSecret) {
    
    ofLogNotice("ofxTwitter::authorize") << "Authorizing app...";
    oauth.setup("https://api.twitter.com", consumerKey, consumerSecret);
	
}

//--------------------------------------------------------------
bool ofxTwitter::isAuthorized() {
    
    return oauth.isAuthorized();

}

//--------------------------------------------------------------
void ofxTwitter::startQuery(string keywords, int count) {
    
    if(oauth.isAuthorized()) {
        string query = "/1.1/search/tweets.json?count="+ofToString(count)+"?q=";
        query += keywords;
        dataRequested = "";
        dataRequested = oauth.get(query);
        ofAddListener(ofEvents().update,this,&ofxTwitter::newResponse);
    } else {
        ofLogError("ofxTwitter::startQuery") << "Local cache is active.";
    }
    
    //tweetQueryIdentifier = 0;

}

//--------------------------------------------------------------
void ofxTwitter::loadCacheFile() {
    
    ofLogNotice("ofxTwitter::loadCacheFile") << "Loading local file 'cache.json'";
    ofxJSONElement result;
    bool parsingSuccessful = result.openLocal("cache.json");
    if (parsingSuccessful) {
        parseResponse(result);
    } else {
        ofLogError("ofxTwitter::loadCacheFile") << "Failed to load JSON";
    }
    
}

//--------------------------------------------------------------
void ofxTwitter::setCache(bool newSaveCache) {
    
    bsaveCacheActive = newSaveCache;
    
}

//--------------------------------------------------------------
bool ofxTwitter::saveCacheIsActive() {
    return bsaveCacheActive;
}

//--------------------------------------------------------------
void ofxTwitter::newResponse(ofEventArgs& args) {
    
    if(dataRequested != "") {
    
        ofxJSONElement result;
        bool parsingSuccessful = result.parse(dataRequested);
        if (parsingSuccessful) {
            if(bsaveCacheActive) result.save("cache.json",true);
            ofLogNotice("ofxTwitter::newResponse") << "Tweets JSON parsed.";
            //cout << result.getRawString() << endl;
            parseResponse(result);
        } else {
            ofLogError("ofxTwitter::newResponse") << "Failed to parse JSON" << endl;
        }
        
        dataRequested = "";
        ofRemoveListener(ofEvents().update,this,&ofxTwitter::newResponse);
    
    }
	
}

//--------------------------------------------------------------
void ofxTwitter::parseResponse(ofxJSONElement result) {
    
    if(result.isMember("statuses")) {
        
        data.clear();
        
        ofxJSONElement trends = result["statuses"];
        
        for(int i = 0; i < trends.size(); i++) {
            
            Tweet tweet;
            
            tweet.id_str = trends[i]["id_str"].asString();
            tweet.created_at = trends[i]["created_at"].asString();
            tweet.language = trends[i]["language"].asString();
            tweet.text = trends[i]["text"].asString();
            tweet.geo = trends[i]["geo"].asString();
            tweet.source = trends[i]["source"].asString();
            tweet.retweet_count = trends[i]["retweet_count"].asInt();
            tweet.truncated = trends[i]["truncated"].asBool();
            
            ofxJSONElement author = trends[i]["user"];
            
            tweet.user.id_str = author["id_str"].asString();
            tweet.user.uri = "https://twitter.com/"+author["screen_name"].asString();
            
            tweet.user.name = author["name"].asString();
            tweet.user.screen_name = author["screen_name"].asString();
            tweet.user.description = author["description"].asString();
            tweet.user.location = author["location"].asString();
            tweet.user.lang = author["lang"].asString();
            tweet.user.url = author["url"].asString();
            
            tweet.user.default_profile = author["default_profile"].asBool();
            tweet.user.default_profile_image = author["default_profile_image"].asBool();
            tweet.user.geo_enabled = author["geo_enabled"].asBool();
            
            tweet.user.profile_image_url = author["profile_image_url"].asString();
            tweet.user.profile_banner_url = author["profile_banner_url"].asString();
            tweet.user.profile_background_image_url = author["profile_background_image_url"].asString();
            tweet.user.profile_background_color = author["profile_background_color"].asString();
            
            tweet.user.profile_background_tile  = author["profile_background_tile"].asBool();
            tweet.user.profile_use_background_image  = author["profile_use_background_image"].asBool();
            
            data.push_back( tweet );
            //tweet.print();
            
        }
        
        ofLogNotice("ofxTwitter::parseResponse") << "(" << data.size() << ") Tweets ready";
        
    }
    
   
   
	// ok, send back results
	//if (delegate) {
		//delegate->searchResult(data, tweetQueryIdentifier);
	//}

}

