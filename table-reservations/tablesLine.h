#pragma once
#include "genericLine.h"
#include <vector>
using namespace std;
class tablesLine :
    public genericLine
{
public:
    tablesLine();
private:
    vector<int> tables;
};

