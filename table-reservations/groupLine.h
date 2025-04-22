#pragma once
#include "genericLine.h"
class groupLine :
    public genericLine
{
private:
	std::string partyName;
	int partySize;
	int diningTime;
public:
	groupLine(std::string);
	void newGroup(std::string);
	void setPartyName(std::string s) { partyName = s; }
	void setPartySize(int k) { partySize = k; }
	void setDiningTime(int k) { diningTime = k; }
	std::string getPartyName() const { return partyName; }
	int getPartySize() const { return partySize; }
	int getDiningTime() const { return diningTime; }
};

