#ifndef TABLE_H
#define TABLE_H

class Table {
private:
    int capacity;
    int assignedPartyIndex;

public:
    Table(int cap);

    int getCapacity() const;
    int getAssignedPartyIndex() const;
    bool isAvailable() const;

    void assignToParty(int partyIndex);
    void clearAssignment();
};

#endif
