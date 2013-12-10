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

#pragma once

#include "ofMain.h"
#include "ofxOAuth.h"
#include "ofxJSONElement.h"

#include "TwitterDelegate.h"
#include "Tweet.h"

class ofxTwitter {

    public:
    
        ofxTwitter();
        ~ofxTwitter();
    
        void setup(const string& consumerKey, const string& consumerSecret);
        bool isAuthorized();
    
        bool loadCacheIsActive();
        bool saveCacheIsActive();
        //void setCacheActive(bool loadChache, bool saveChache);
        void loadCacheFile();
    
        void startQuery(string keywords, int count = 10);
        //void startTwitterQuery(string keywords, int repliesPerPage=10, int pageIndex=1, int queryIdentifier=0);
        void newResponse(ofEventArgs& args);
        void parseResponse(ofxJSONElement result);
    
        void setSearchDelegate(TwitterDelegate *_delegate) { delegate = _delegate; }

    private:
	
        ofxOAuth oauth;
    
        string dataRequested;
    
        bool bloadCacheActive;
        bool bsaveCacheActive;
    
        int tweetQueryIdentifier;
        TwitterDelegate *delegate;
        vector<Tweet> data;
	
};