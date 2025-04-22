#ifndef TABLE_H
#define TABLE_H

#include <string>

// The Table class represents a single table in the restaurant.
// Each table has a seating capacity and may be assigned to a group.
class Table {
private:
    int capacity;              // The number of people this table can seat
    std::string assignedGroup; // Name of the group assigned to this table (empty if unassigned)

public:
    // Constructor: creates a table with a specified capacity
    Table(int cap);

    // Returns the seating capacity of the table
    int getCapacity() const;

    // Returns the name of the group currently assigned to this table
    std::string getAssignedGroup() const;

    // Returns true if the table is currently unassigned (available)
    bool isAvailable() const;

    // Assigns the table to a group with the given name
    void assignToGroup(const std::string& groupName);

    // Clears any current group assignment from the table
    void clearAssignment();
};

#endif
