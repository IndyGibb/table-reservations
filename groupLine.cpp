#include "groupLine.h"
#include <sstream>

groupLine::groupLine(std::string s) {
	setLineType(genericLine::group);
	setLine(s);
	newGroup(s);
}

void groupLine::newGroup(std::string s) {
	std::stringstream ss(s);
	std::string name;
	int size, time;
	std::getline(ss, name, ',');
	ss >> size;
	ss.ignore();
	ss >> time;
	setPartyName(name);
	setPartySize(size);
	setDiningTime(time);
}