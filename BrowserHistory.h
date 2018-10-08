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


void BrowserHistory::visitSite(Webpage newSite)
{
	
	while (navPos != --navHistory.end())
	{
		if (numSites > 1)
		{
			navHistory.pop_back();
			numSites--;
		}

		sitesVisited.insert(navPos, newSite);
		navHistory.insert(navPos, newSite);
		numSites++;

		if (navHistory.size() != 1)
			navPos++;
	}
}

string BrowserHistory::back()
{
	navPos--;
	return navPos->getUrl();
}

string BrowserHistory::forward()
{
	navPos++;
	return navPos->getUrl();
}


string BrowserHistory::getUrl()
{
	if (navHistory.empty()) 
		throw std::logic_error("Empty website history.");
	return navPos->getUrl();
	
}


list<Webpage> BrowserHistory::getSitesVisited()
{
	return sitesVisited;
}

size_t BrowserHistory::getNavSize()
{
	return (navHistory.size());
}

#endif
