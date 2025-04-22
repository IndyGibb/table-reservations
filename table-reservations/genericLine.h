#pragma once
class genericLine
{
public:
	enum linetype { tables, group };
	linetype getLineType() const { return type; }
protected:
	void setLineType(linetype t) { type = t; }
private:
	linetype type;
};

