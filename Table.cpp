#include "Table.h"

Table::Table(int capacity, int tableNumber)
    : capacity(capacity), tableNumber(tableNumber), assignedGroup(nullptr) {}

int Table::getCapacity() const {
    return capacity;
}

Group* Table::getAssignedGroup() const {
    return assignedGroup;
}

bool Table::isAvailable() const {
    return assignedGroup == nullptr;
}

int Table::getTableNumber() const {
    return tableNumber;
}

void Table::setTableNumber(int number) {
    tableNumber = number;
}

void Table::assignToGroup(Group* groupPtr) {
    assignedGroup = groupPtr;
    if (groupPtr != nullptr) {
        groupPtr->markSeated();
    }
}

void Table::clearAssignment() {
    assignedGroup = nullptr;
}
