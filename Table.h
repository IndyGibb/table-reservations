#ifndef TABLE_H
#define TABLE_H

#include "Group.h"

// Represents a restaurant table with seating capacity and a pointer to an assigned Group
class Table {
public:
    // Constructor: initialize table with seating capacity
    Table(int capacity);

    // Getters
    int getCapacity() const;             // Returns seating capacity
    Group* getAssignedGroup() const;     // Returns the pointer to the assigned group
    bool isAvailable() const;            // Returns true if the table is unassigned

    // Assignment operations
    void assignToGroup(Group* groupPtr); // Assign a group to this table
    void clearAssignment();              // Clears any current assignment

private:
    int capacity;           // Max number of people this table can seat
    Group* assignedGroup;   // Pointer to the group currently assigned (nullptr if none)
};

#endif
