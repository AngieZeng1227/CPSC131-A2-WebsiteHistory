#pragma once
#ifndef browserhistory_h
#define browserhistory_h

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdexcept>
#include "Webpage.h"
using namespace std;

class BrowserHistory {
public:
	BrowserHistory();

	void visitSite(Webpage newSite);
	string back();
	string forward();

	void readHistory(string fileName);

	string getUrl();
	size_t getNavSize();
	list<Webpage> getSitesVisited();

private:
	// The list, navHistory, keeps track of the user's browser history
	list<Webpage> navHistory;
	
	// The list, navPos, keeps track of the user's position in the browser history
	list<Webpage>::iterator navPos;
	
	// The list, sitesVisited, keeps track of the number of sites the user visited
	list<Webpage> sitesVisited;
	
	// The numSites variable stores the number of websites the user visited
	int numSites;
};

// The readHistory() member function reads in the browser history file 
void BrowserHistory::readHistory(string fileName) {
	string temp;
	int newTime;
	Webpage newSite;
	ifstream inFile(fileName.c_str());

	while (inFile >> temp) {
		if (temp == "new") {
			inFile >> temp >> newTime;
			newSite = Webpage(temp, time_t(newTime));
			visitSite(newSite);
		}
		else if (temp == "back") {
			back();
		}
		else if (temp == "forward") {
			forward();
		}
		else {
			throw logic_error("invalid command");
		}
	}
}

// The default constructor initializes the the value of numSites to 0 and sets navPos to the 
// beginning of the list
BrowserHistory::BrowserHistory()
{
	navPos = navHistory.begin();
	numSites = 0;
}

// The visitSite() member function add the new site and the time it was accessed to the sitesVisited list
void BrowserHistory::visitSite(Webpage newSite)
{
	// Check if there are websites to delete from back/forward
	while (navPos != --navHistory.end())
	{
		navHistory.pop_back();
		numSites--;
	}
	
	sitesVisited.push_back(newSite);
	navHistory.push_back(newSite);
	numSites++;
	
	if(navHistory.size() == 1)
		navPos = navHistory.begin();
	else
		navPos++;
}

// The back() member function returns the user to the previous website they visited
string BrowserHistory::back()
{
	navPos--;
	return navPos->getUrl();
}

// The forward() member function returns the webpage that comes after the webpage the user access
string BrowserHistory::forward()
{
	navPos++;
	return navPos->getUrl();
}

// The getUrl() member function returns the webpage url given to the program through the text files.
// Returns an error if the history contains no websites visited (No browser history).
string BrowserHistory::getUrl()
{
	if (navHistory.empty()) 
		throw logic_error("Empty website history.");
	return navPos->getUrl();
	
}

// The getSitesVisited() member function returns the number (list) of sites visited
list<Webpage> BrowserHistory::getSitesVisited()
{
	return sitesVisited;
}

// The getNavSize() member function returns the size of the navHistory list 
size_t BrowserHistory::getNavSize()
{
	return (navHistory.size());
}

#endif
