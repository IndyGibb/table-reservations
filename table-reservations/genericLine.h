#pragma once
#include <string>
class genericLine
{
public:
	enum linetype { tables, group };
	linetype getLineType() const { return type; }
protected:
	void setLineType(linetype t) { type = t; }
	void setLine(const std::string l) { line = l; }
	std::string line;
private:
	linetype type;
};

