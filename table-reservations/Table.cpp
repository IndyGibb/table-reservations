#include "Table.h"

// Constructor: initializes the table with the given capacity
// and marks it as unassigned (assignedGroup is empty)
Table::Table(int cap) : capacity(cap), assignedGroup("") {}

// Returns the number of people the table can seat
int Table::getCapacity() const {
    return capacity;
}

// Returns the name of the group currently assigned to this table
std::string Table::getAssignedGroup() const {
    return assignedGroup;
}

// Returns true if the table is unassigned (available)
bool Table::isAvailable() const {
    return assignedGroup.empty();
}

// Assigns this table to the specified group
void Table::assignToGroup(const std::string& groupName) {
    assignedGroup = groupName;
}

// Clears the current assignment, making the table available again
void Table::clearAssignment() {
    assignedGroup.clear();
}
