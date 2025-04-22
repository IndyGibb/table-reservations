#pragma once
#include "genericLine.h"
#include <vector>
using namespace std;
class tablesLine :
    public genericLine
{
public:
    tablesLine();
    vector<int> getTables() const { return tables; }
private:
    vector<int> tables;
};

