#pragma once
#include "genericLine.h"
#include <vector>
using namespace std;
class tablesLine :
    public genericLine
{
public:
    tablesLine(string);
    void newTables(string);
	void addTable(int);
    vector<int> getTables() const { return tables; }
    void printTables() const;
private:
    vector<int> tables;
};

