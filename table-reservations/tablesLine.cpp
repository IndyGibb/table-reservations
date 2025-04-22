#include "tablesLine.h"
#include <sstream>

tablesLine::tablesLine(string s) {
	setLineType(genericLine::tables);
	setLine(s);
	newTables(s);
}

void tablesLine::newTables(string s) {
	stringstream ss(s);
	int table;
	while (ss >> table) {
		addTable(table);
		if (ss.peek() == ',') {
			ss.ignore();
		}
	}
}

void tablesLine::addTable(int t) {
	tables.push_back(t);
}

void tablesLine::printTables() const {
	for (int i = 0; i < tables.size(); i++) {
		cout << "Table " << i + 1 << ": " << tables[i] << endl;
	}
}