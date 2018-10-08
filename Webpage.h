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

// Enter url and time visited into class
Webpage::Webpage(const string& webpageUrl, const time_t& timeVisited)
{
	url = webpageUrl;
	time = timeVisited;
}

// Return url
string Webpage::getUrl()
{
	return url;
}

// Return time
time_t Webpage::getTime()
{
	return time;
}




#endif 
