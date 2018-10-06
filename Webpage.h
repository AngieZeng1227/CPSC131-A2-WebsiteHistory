#pragma once
#ifndef webpage_h
#define webpage_h

#include <string>
using namespace std;

class Webpage {
public:
	Webpage();
	Webpage(const string& webpageUrl, const time_t& timeVisited);
	string getUrl();
	time_t getTime();

private:
	string url;
	time_t time;
};
// Default constructor 
Webpage::Webpage()
{



}

// 
Webpage::Webpage(const string& webpageUrl, const time_t& timeVisited);
{



}

// The getUrl() member function gets a URL from the text file
string Webpage::getUrl()
{


}

// 
time_t Webpage::getTime()
{


}


#endif 
