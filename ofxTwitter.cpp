/*
 *  ofxTwitter.cpp
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

#include "ofxTwitter.h"

void ofxTwitter::setup(bool _loadCache, bool _saveCache) {
    
    // cache
    loadCache = _loadCache;
    saveCache  = _saveCache;
	
	// listen to http events / load cache file
    if(!loadCache) {
        ofAddListener(httpUtils.newResponseEvent, this, &ofxTwitter::newResponse);
        httpUtils.start();
    } else {
        loadCacheFile();
    }
    
	// use dummy data in case we've lost web connection
	data.push_back( Tweet("...") );
	
	delegate = NULL;    
	
}
//--------------------------------------------------------------
void ofxTwitter::startTwitterQuery(string keywords, int repliesPerPage, int pageIndex, int queryIdentifier) {
	
	string query = "http://search.twitter.com/search.atom?q=";
	query += keywords;
	query += "&rpp=" + ofToString(repliesPerPage);
//	query += "&page=" + ofToString(pageIndex);
	query += "&result_type=recent";
    
    tweetQueryIdentifier = queryIdentifier;
    
	startQuery(query);
    //xml.loadFile("last_bck.xml");
    //newResponse();
	
}

void ofxTwitter::startQuery(string query) {
	// load data from web
	httpUtils.addUrl(query);    
}

//--------------------------------------------------------------
void ofxTwitter::startTwitterPostQuery(string keywords, int repliesPerPage, int pageIndex, int queryIdentifier) {
	
    string query = "http://search.twitter.com/search.atom?a=";
	query += keywords;
	query += "&rpp=" + ofToString(repliesPerPage);
    //	query += "&page=" + ofToString(pageIndex);
	query += "&result_type=recent";
    
    tweetQueryIdentifier = queryIdentifier;
    
    ofxHttpForm form;
	form.action= query;
	form.method= OFX_HTTP_POST;
    form.addFormField("q", keywords);
    //form.addFormField("rpp", ofToString(repliesPerPage));
    //form.addFormField("page", ofToString(pageIndex));
    //form.addFormField("result_type", "recent");
    
    form.name = form.action;
    
	startPostQuery(form);
  	
}

void ofxTwitter::startPostQuery(ofxHttpForm form) {
    
	// load data from web
	httpUtils.addForm(form);    
    
}


//--------------------------------------------------------------
void ofxTwitter::newResponse(ofxHttpResponse &response) {
    
    cout << "ofxTwitter: HTTP RESPONSE RECIVED." << endl;
    
    xml.loadFromBuffer(response.responseBody); // parse string
    xml.pushTag("feed"); // change relative root to <feed>
    
    // cache
    if(saveCache) {
        xml.saveFile("last.xml");
    }
	
	parseXMLResponse();
	
}

void ofxTwitter::loadCacheFile() {
    
    cout << "ofxTwitter: LOADING CACHE." << endl;
    
    xml.loadFile("last.xml");
    xml.pushTag("feed"); // change relative root to <feed>
    
    parseXMLResponse();

}

void ofxTwitter::parseXMLResponse() {
    
    // get current count of data
	int xmlDataCount = data.size();
	
    int nombreDeTweets = xml.getNumTags("entry");
    
    // iterate through <entry> tags
    for (int i = 0; i < nombreDeTweets; i++) {
		
		xml.pushTag("entry", i);
		
		Tweet tweet;
		tweet.id = xml.getValue("id", "", 0).c_str();
		tweet.title = xml.getValue("title", "", 0).c_str();
		tweet.updated = xml.getValue("updated", "", 0).c_str();
		tweet.published = xml.getValue("published", "", 0).c_str();
		tweet.author.uri  = xml.getValue("author:uri", "", 0).c_str();
		tweet.author.name = xml.getValue("author:name", "", 0).c_str();
		
		tweet.language = xml.getValue("twitter:lang", "", 0).c_str();
		
		for(int j=0; j<xml.getNumTags("link"); j++) {
			
			string type = xml.getAttribute("link", "type", "", j);
			string rel  = xml.getAttribute("link", "rel", "", j);
			string href = xml.getAttribute("link", "href", "", j);
			
			if (rel == "image")
				tweet.author.imageUri = href;
			else if (rel == "alternate")
				tweet.link = href;
		}
		
		data.push_back( tweet );
		
		xml.popTag();
		
    }
    xml.popTag(); // move out of <feed>
	
	// remove previous data
	for (int i=0; i<xmlDataCount; i++) {
		data.erase(data.begin());
	}
	
	// ok, send back results
	if (delegate) {
		delegate->searchResult(data, tweetQueryIdentifier);
	}

}

//--------------------------------------------------------------
vector<Tweet> ofxTwitter::getLatestResponse() {
	return data;
}

//--------------------------------------------------------------
void ofxTwitter::clear() {
	// listen to http events
    ofRemoveListener(httpUtils.newResponseEvent, this, &ofxTwitter::newResponse);
    httpUtils.stop();
    
//	data.clear();
}
