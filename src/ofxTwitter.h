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
 *  Edited vby welovecode 14/06/12
 *  Added cache support for saving/load xml cache file.
 *  Added POST query method.
 *  
 */

#pragma once

#include "ofMain.h"

#include "ofxHttpUtils.h"
#include "ofxXmlSettings.h"

#include "TwitterDelegate.h"
#include "Tweet.h"

class ofxTwitter {
public:
	
	void setup(bool _loadCache, bool _saveCache);
	void setSearchDelegate(TwitterDelegate *_delegate) { delegate = _delegate; }
	
	void startQuery(string query);
	void startTwitterQuery(string keywords, int repliesPerPage=10, int pageIndex=1, int queryIdentifier=0);
    void startPostQuery(ofxHttpForm form);
    void startTwitterPostQuery(string keywords, int repliesPerPage=10, int pageIndex=1, int queryIdentifier=0);
	
	vector<Tweet> getLatestResponse();
	void newResponse(ofxHttpResponse &response);
    void parseXMLResponse();
    
    void clear();

	ofxHttpUtils httpUtils;
    
    int tweetQueryIdentifier;
    
    bool loadCache;
    bool saveCache;
    void loadCacheFile();
    
    
    
private:
	
	TwitterDelegate *delegate;
	
	ofxXmlSettings xml;
	vector<Tweet> data;
	
};