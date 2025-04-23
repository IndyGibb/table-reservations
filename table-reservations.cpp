// table-reservations.cpp : This file contains the 'main' function. Program execution begins and ends there.

// TableReservations.cpp : This program tries to assign tables to various parties
// seeking to dine at a restaurant.

#include <iostream>
#include <fstream>
#include "Group.h"
#include "Table.h"
#include "groupLine.h"
#include "tablesLine.h"
using namespace std;

vector<Table> sortByTime(vector<Table> tables) {
    for (int i = 0; i < tables.size(); i++) {
        for (int j = i + 1; j < tables.size(); j++) {
			if (tables[i].getAssignedGroup()->getDiningTime() > tables[j].getAssignedGroup()->getDiningTime()) {
				// Swap tables[i] and tables[j] if they are out of order
				Table temp = tables[i];
				tables[i] = tables[j];
				tables[j] = temp;
			}
        }
    }
    return tables;
}

vector<Table> sortByNumber(vector<Table> tables) {
    for (int i = 0; i < tables.size(); i++) {
        for (int j = i + 1; j < tables.size(); j++) {
            if (tables[i].getTableNumber() > tables[j].getTableNumber()) {
                Table temp = tables[i];
				tables[i] = tables[j];
				tables[j] = temp;
            }
        }
    }
    return tables;
}

void next_party(vector<Table>& tables, vector<Group>& groups) {
    vector<Table> tablesResorted = sortByTime(tables);
	Group* nextParty = nullptr;
    int longestTime;
    for (int i = 0; i < groups.size(); i++) {
        if (!groups[i].isSeated()) {
            for (int j = 0; j < tablesResorted.size(); j++) {
                if (groups[i].getSize() <= tables[j].getCapacity()) {
                    cout << "The next party " << groups[i].getName() << " of size " << groups[i].getSize() << " will be assigned to table " << tablesResorted[j].getTableNumber() << " in " << tables[j].getAssignedGroup()->getDiningTime() << " minutes.\n";
                    return;
                }
            }
            for (int j = 0; j < tablesResorted.size(); j++) {
                int assigned = j;
				longestTime = tablesResorted[j].getAssignedGroup()->getDiningTime();
                for (int k = j + 1; k < tablesResorted.size(); k++) {
					if (groups[i].getSize() <= tablesResorted[j].getCapacity() + tablesResorted[k].getCapacity()) {
                        if (tablesResorted[k].getAssignedGroup()->getDiningTime() > longestTime) {
                            longestTime = tablesResorted[k].getAssignedGroup()->getDiningTime();
                        }
						cout << "The next party " << groups[i].getName() << " of size " << groups[i].getSize() << " will be assigned to tables " << tablesResorted[assigned].getTableNumber() << " and " << k + 1 << " in " << longestTime << " minutes.\n";
						return;
					}
                }
            }
            
        }
    }
}

// The return value indicates whether all parties were successfully accommodated.
bool reserve_table(vector<Table>& tables, vector<Group>& groups) {
    bool allSeated = true;
    Group* nextParty = nullptr;
    // Find the first party that has not been seated, or end the program if all have been seated
    for (int i = 0; (i < groups.size()) && allSeated ; i++) {
        if (!groups[i].isSeated()) {
            allSeated = false;
			nextParty = &groups[i];
        }
    }
	if (allSeated) {
		cout << "All parties have been seated.";
		return true;
	}
	// Find the largest table available for the next party
    int largestTable = 0;
	for (int i = tables.size() - 1; i >= 0; i--) {
		if (tables[i].isAvailable() && (tables[i].getCapacity() > largestTable)) {
			largestTable = tables[i].getCapacity();
			break;
		}
	}

    

    cout << "Hello!  I see you have a party of " << nextParty->getSize() << endl;
    // Since the tables are sorted by size from smallest to largest, any given party will be put at the smallest table which can accomodate them.
    if (nextParty->getSize() <= largestTable) {
        for (int i = 0; i < groups.size(); i++) {
            if (tables[i].isAvailable() && nextParty->getSize() <= tables[i].getCapacity()) {
                tables[i].assignToGroup(nextParty);
                cout << "Party " << nextParty->getName() << " of size " << nextParty->getSize() << " is assigned to table " << tables[i].getTableNumber() << endl;
                // Ultimately, success depends on whether all other parties can be accommodated.
                if (reserve_table(tables, groups)) {
                    return true;
                }
                else { return false; }
            }
        }
        cout << "We don't have any tables available for party " << nextParty->getName() << " of size " << nextParty->getSize() << ".  Sorry!\n";
        return false;
    }

    else {
        // Find a free table, regardless of size.
        for (int i = 0; i < tables.size(); i++) {
            if (tables[i].isAvailable()) {
                int assigned = i;
                // Now find a second free table.
                for (int j = i + 1; j < tables.size(); j++) {
                    // Go back to the original table assignments.
                    // The two tables, when put together, must seat the entire party.
                    if (tables[j].isAvailable() && j != assigned && tables[assigned].getCapacity() + tables[j].getCapacity() >= nextParty->getSize()) {
                        int also_assigned = j;
						tables[assigned].assignToGroup(nextParty);
						tables[also_assigned].assignToGroup(nextParty);
                        cout << "Party " << nextParty->getName() << " of size " << nextParty->getSize() << " is assigned to tables " << tables[assigned].getTableNumber()
                            << " and " << tables[also_assigned].getTableNumber() << endl;
                        if (reserve_table(tables, groups)) {
                            return true;
                        }
                        else { return false; }
                    }
                }
            }
        }

        cout << "We don't have any tables big enough for party " << nextParty->getName() << " of size " << nextParty->getSize() << ".  Sorry!\n";
        return false;
    }
}

void sort(vector<Table>& tables) { // Sorts tables by capacity
    for (int i = 0; i < tables.size() - 1; i++) {
        for (int j = i + 1; j < tables.size(); j++) {
            if (tables[i].getCapacity() > tables[j].getCapacity()) {
                // Swap tables[i] and tables[j] if they are out of order
                Table temp = tables[i];
                tables[i] = tables[j];
                tables[j] = temp;
            }
        }
    }
}

int main()
{
    string inputFileName, line;
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    ifstream fin(inputFileName);
    while (!fin) {
        cout << "Error opening file " << inputFileName << ".\nPlease enter a new file name, or q to quit: ";
        cin >> inputFileName;
		if (inputFileName == "q") {
			cout << "Goodbye!\n";
			return 0;
        }
        cout << endl;
        fin.close();
        fin.open(inputFileName);
    }
	cout << "File " << inputFileName << " opened successfully.\n";

    getline(fin, line);

    tablesLine tables(line); // Sifts through and puts the tables into a vector, as well as allowing easy printing capabilities.

    cout << "Here are the table capacities:\n";

    tables.printTables();
    cout << endl;

    

    vector<Table> tableObjects; // Convert the vector of integers to a vector of Table objects
	for (int i = 0; i < tables.getTables().size(); i++) {
		tableObjects.push_back(Table(tables.getTables()[i]));
		tableObjects[i].setTableNumber(i + 1);
	}

    sort(tableObjects);

	vector<Group> groups; // Vector of groups
    Group* g;
    groupLine group(line);
	while (getline(fin, line)) {
        group.newGroup(line);
		g = new Group(group.getPartyName(), group.getPartySize(), group.getDiningTime());
		groups.push_back(*g);
        delete g;
	}

    

	if (reserve_table(tableObjects, groups)) {
		cout << "\nHere are the final table assignments:\n";
        vector<Table> tablesByNumber = sortByNumber(tableObjects);
		for (int i = 0; i < tablesByNumber.size(); i++) {
			if (tablesByNumber[i].isAvailable()) {
				cout << "Table " << i + 1 << " is not assigned to anyone.\n";
			}
			else {
				cout << "Table " << i + 1 << " is assigned to party " << tablesByNumber[i].getAssignedGroup()->getName()
					<< ", which is a party of size " << tablesByNumber[i].getAssignedGroup()->getSize() << endl;
			}
		}
	}
	else {
        cout << "\nThe parties could not all be accommodated.\n";
        next_party(tableObjects, groups);
    }



    
    return 0;
}
