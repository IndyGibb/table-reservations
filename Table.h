#ifndef TABLE_H
#define TABLE_H

#include "Group.h"

// Represents a restaurant table with capacity, assigned group, and table number
class Table {
public:
    // Constructor: initialize with seating capacity and optional table number
    Table(int capacity, int tableNumber = -1);

    // Getters
    int getCapacity() const;             // Returns seating capacity
    Group* getAssignedGroup() const;     // Returns pointer to the assigned group
    bool isAvailable() const;            // Returns true if table is unassigned
    int getTableNumber() const;          // Returns the table number

    // Setters
    void assignToGroup(Group* groupPtr); // Assign a group to this table
    void clearAssignment();              // Clears current assignment
    void setTableNumber(int number);     // Set the table number

private:
    int capacity;           // Max number of people this table can seat
    int tableNumber;        // Unique number identifying this table
    Group* assignedGroup;   // Pointer to assigned group (nullptr if unassigned)
};

#endif
