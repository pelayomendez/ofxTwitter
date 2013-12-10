/*
 *  Tweet.h
 *
 *  Created by Douglas Edric Stanley on 10/12/10
 *  cc-by-sa 2010 www.abstractmachine.net. Some rights reserved.
 *  http://creativecommons.org/licenses/by-sa/3.0/
 *
 *  Adapted from code by Paul Shen
 *  cf. http://in.somniac.me/2010/01/openframeworks-http-requests-xml-parser/
 *
 *  10/12/2013 Adapted to Twitter API 1.1 by Pelayo M�ndez
 *
 */

#pragma once

#include "ofMain.h"

struct TweetAuthor {
    
    string id_str;
    string uri;
    
    string name;
	string screen_name;
    string description;
    string location;
    string lang;
    string url;
    
    bool default_profile;
    bool default_profile_image;
    bool geo_enabled;
    
	string profile_image_url;
    string profile_banner_url;
    string profile_background_image_url;
    string profile_background_color;
    bool profile_background_tile;
    bool profile_use_background_image;
    
};

struct Tweet {

	string id_str;
    string created_at;
	string language;
    string text;
    string geo;
    string source;
    int retweet_count;
    
    bool truncated;
    
	TweetAuthor user;
    
    Tweet() { }
	Tweet(string defaultString)	: text(defaultString) { }
    
	void print() {
        
		string str;
        
        str +=  "\n";
        str +=  "\n--- Tweet ---";
		str += "\nid_str: " + id_str;
		str +=  "\ncreated_at: " + created_at;
        str +=  "\nlanguage: " + language;
		str +=  "\ntext: " + text;
        str +=  "\ngeo: " + geo;
        str +=  "\nsource: " + source;
        str +=  "\nretweet_count: " + ofToString(retweet_count);
        str +=  "\n--- User ---";
		str +=  "\nuser:name: " + user.name;
        str +=  "\nuser:screen_name: "+ user.screen_name;
		str +=  "\nuser:uri: " + user.uri;
		str +=  "\nuser:imageUri: " + user.profile_image_url;
        str +=  "\nuser:description: " + user.description;
        str +=  "\nuser:location: " + user.location;
        str +=  "\nuser:lang: " + user.lang;
        str +=  "\nuser:url:" + user.url;
        
		cout << str;

	}
	
};