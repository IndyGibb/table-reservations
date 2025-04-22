#include "Table.h"

Table::Table(int cap) : capacity(cap), assignedPartyIndex(-1) {}

int Table::getCapacity() const {
    return capacity;
}

int Table::getAssignedPartyIndex() const {
    return assignedPartyIndex;
}

bool Table::isAvailable() const {
    return assignedPartyIndex < 0;
}

void Table::assignToParty(int partyIndex) {
    assignedPartyIndex = partyIndex;
}

void Table::clearAssignment() {
    assignedPartyIndex = -1;
}
