// table-reservations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}
*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// TableReservations.cpp : This program tries to assign tables to various parties
// seeking to dine at a restaurant.

#include <iostream>
#include <fstream>
#include "Group.h"
#include "Table.h"
#include "groupLine.h"
#include "tablesLine.h"
using namespace std;

const int max_tables = 6;

// The return value indicates whether all parties were successfully accommodated.
bool reserve_table(const int table[], int original_taken[], const int length,
    const int party_size[], const int size_length) {
    const int size = party_size[size_length - 1];
    if (size_length < 1) {
        // There are no more parties to accommodate!
        return true;
    }

    int taken[max_tables];
    // Make a copy of the original table assignments.
    for (int k = 0; k < max_tables; k++) {
        taken[k] = original_taken[k];
    }

    cout << "Hello!  I see you have a party of " << size << endl;

    for (int i = 0; i < length; i++) {
        // Parties of one or two people can only be seated at a table that seats at most 2.
        if (taken[i] < 0 && size <= table[i] && (size > 2 || table[i] < 3)) {
            taken[i] = size_length - 1;
            cout << "Your party of " << size << " is assigned to table " << i + 1 << endl;
            // Ultimately, success depends on whether all other parties can be accommodated.
            if (reserve_table(table, taken, length, party_size, size_length - 1)) {
                // Copy the table assignments that worked out fine so the caller of this
                // function (which might be the main function) can see what they are.
                for (int k = 0; k < max_tables; k++) {
                    original_taken[k] = taken[k];
                }
                return true;
            }
            else { return false; }
        }
    }

    if (size <= 2) {
        // Parties of one or two people can only be assigned to a single table.
        // If a table for two was not found above, try assigning the party to a table for 4.
        for (int i = 0; i < length; i++) {
            if (taken[i] < 0 && size <= table[i]) {
                taken[i] = size_length - 1;
                cout << "Your party of " << size << " is assigned to table " << i + 1 << endl;
                // Ultimately, success depends on whether all other parties can be accommodated.
                if (reserve_table(table, taken, length, party_size, size_length - 1)) {
                    // Copy the table assignments that worked out fine so the caller of this
                    // function (which might be the main function) can see what they are.
                    for (int k = 0; k < max_tables; k++) {
                        original_taken[k] = taken[k];
                    }
                    return true;
                }
                else { return false; }
            }
        }
        cout << "We don't have any tables available for your party of " << size << ".  Sorry!\n";
        return false;
    }

    else {
        // Find a free table, regardless of size.
        for (int i = 0; i < length; i++) {
            // Note that the if below is looking at the original table assignments.
            if (original_taken[i] < 0) {
                int assigned = i;
                // Now find a second free table.
                for (int j = i + 1; j < length; j++) {
                    // Go back to the original table assignments.
                    for (int k = 0; k < max_tables; k++) {
                        taken[k] = original_taken[k];
                    }
                    // The two tables, when put together, must seat the entire party.
                    if (taken[j] < 0 && j != assigned && table[assigned] + table[j] >= size) {
                        int also_assigned = j;
                        taken[also_assigned] = taken[assigned] = size_length - 1;
                        cout << "Your party of " << size << " is assigned to tables " << assigned + 1
                            << " and " << also_assigned + 1 << endl;
                        if (reserve_table(table, taken, length, party_size, size_length - 1)) {
                            // Copy the table assignments that worked out fine so the caller of this
                            // function (which might be the main function) can see what they are.
                            for (int k = 0; k < max_tables; k++) {
                                original_taken[k] = taken[k];
                            }
                            return true;
                        }
                    }
                }
            }
        }

        cout << "We don't have any tables big enough for your party of " << size << ".  Sorry!\n";
        return false;
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

    tablesLine tables(line);

    cout << "Here are the table capacities:\n";

    tables.printTables();
    cout << endl;

    vector<Table> tableObjects;
	for (int i = 0; i < tables.getTables().size(); i++) {
		tableObjects.push_back(Table(tables.getTables()[i]));
	}

    vector<Group> groups;
    Group* g;
	while (getline(fin, line)) {
		groupLine group(line);
		g = new Group(group.getPartyName(), group.getPartySize(), group.getDiningTime());
		groups.push_back(*g);
        delete g;
	}

    /*
    const int max_types = 2;
    const int table_types[] = { 2, 4 };  // how many people may be seated at a table
    const int party_size_length = 5;  // there are 5 parties
    const int party_size[] = { 4,2,3,6,1 };
    int table[max_tables], taken[max_tables];
    for (int i = 0; i < max_tables; i++) {
        table[i] = table_types[rand() % 2];
        taken[i] = -1;  // a negative number means the given table is not taken
    }
    cout << "Here are the table capacities:\n";
    for (int i = 0; i < max_tables; i++) {
        cout << "Table " << i + 1 << " seats " << table[i] << " people.\n";
    }

    if (reserve_table(table, taken, max_tables, party_size, party_size_length)) {
        cout << "\nHere are the final table assignments:\n";
        for (int i = 0; i < max_tables; i++) {
            if (taken[i] < 0) {
                cout << "Table " << i + 1 << " is not assigned to anyone.\n";
            }
            else {
                cout << "Table " << i + 1 << " is assigned to party number " << taken[i]
                    << ", which is a party of size " << party_size[taken[i]] << endl;
            }
        }
    }
    else { cout << "\nThe parties could not all be accommodated.\n"; }
    */
    return 0;
}
