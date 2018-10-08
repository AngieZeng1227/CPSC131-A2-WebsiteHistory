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
	list<Webpage> navHistory;
	list<Webpage>::iterator navPos;
	list<Webpage> sitesVisited;
	int numSites;
};

// Read in the file
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

// Default Constructor
BrowserHistory::BrowserHistory()
{
	navPos = navHistory.begin();
	numSites = 0;
}

// Add new site to visited
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

// Back 1 website
string BrowserHistory::back()
{
	navPos--;
	return navPos->getUrl();
}

// Forward
string BrowserHistory::forward()
{
	navPos++;
	return navPos->getUrl();
}

// Get url from list
string BrowserHistory::getUrl()
{
	if (navHistory.empty()) 
		throw logic_error("Empty website history.");
	return navPos->getUrl();
	
}

// Return list of sites visited
list<Webpage> BrowserHistory::getSitesVisited()
{
	return sitesVisited;
}

// Return the size of navHistory
size_t BrowserHistory::getNavSize()
{
	return (navHistory.size());
}

#endif
