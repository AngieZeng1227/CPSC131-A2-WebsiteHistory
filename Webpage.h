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

// The default constructor assigns a temporary string to the variable, url, 
// and sets the time variable equal to 0 if both are not available at the time the program compiles
Webpage::Webpage()
{
	url = "Blank (N/A)";
	time = 0; 
	
}

// Sets url and time accessed from the main function
Webpage::Webpage(const string& webpageUrl, const time_t& timeVisited)
{
	url = webpageUrl;
	time = timeVisited;
}

// The getUrl() member function returns the url of the website
string Webpage::getUrl()
{
	return url;
}

// The getTime() member function returns the time the website was accessed
time_t Webpage::getTime()
{
	return time;
}


#endif 
