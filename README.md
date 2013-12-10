ofxTwitter
=====================================
OpenFrameworks addon for developing Twitter based projects.

Introduction
------------

The original addon was created by Edric Stanley on 2010 and was adapted from code by [Paul Shen](http://in.somniac.me/2010/01/openframeworks-http-requests-xml-parser/).
Afterwards [Andrew Vergara](https://github.com/drewvergara/ofxTwitter) updated the addon to use the most recent version of [ofxHttpUtils](https://github.com/arturoc/ofxHttpUtils).

With the new [Twitter API 1.1](https://dev.twitter.com/docs/api/1.1/overview) the old addon stopped working so I decided to start working in this new version.

Installation
------------
Before using the examples you must create your app and obtain a 'consumer' and a 'secret key' at [https://dev.twitter.com/apps](https://dev.twitter.com/apps)

Don´t forget to provide also a Callback URL like 'http://mydomain.com' on the form (The URL can be anything, its like a boolean saying "my application can use callback-base") That way ofxOAuth can go through the autorization proccess and will create an credentials.xml file on the data folder with your info.

Dependencies
------------
* Uses Christopher Baker [ofxOAuth](https://github.com/bakercp/ofxOAuth) addon
* ofxXmlSettings is also needed for ofxOAuth
* Uses Jeff Crouse [ofxJSON](https://github.com/jefftimesten/ofxJSON) for parsing Twitter REST API JSON data as XML is not supported anymore by the API.

Compatibility
------------
Tested with OF 0.8 in OSX 10.9

Known issues
------------
WIP

Version history
------------
WIP

Licence
-------
The code in this repository is available under the [MIT License](https://secure.wikimedia.org/wikipedia/en/wiki/Mit_license).

Copyright (c) 2013 Pelayo Méndez

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.