#include "Table.h"

Table::Table(int capacity)
    : capacity(capacity), assignedGroup(nullptr) {}

int Table::getCapacity() const {
    return capacity;
}

Group* Table::getAssignedGroup() const {
    return assignedGroup;
}

bool Table::isAvailable() const {
    return assignedGroup == nullptr;
}

void Table::assignToGroup(Group* groupPtr) {
    assignedGroup = groupPtr;
    if (groupPtr != nullptr) {
        groupPtr->markSeated();  // Mark the group as seated
    }
}

void Table::clearAssignment() {
    assignedGroup = nullptr;
}
