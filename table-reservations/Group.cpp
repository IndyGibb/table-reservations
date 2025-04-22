#include "Group.h"

// Constructor initializes all group values.
// Sets wait time to 0 and seated status to false by default.
Group::Group(const std::string& name, int size, int time)
    : partyName(name), partySize(size), diningTime(time), waitTime(0), seated(false) {
}

// Return the party's name
std::string Group::getName() const {
    return partyName;
}

// Return the number of people in the party
int Group::getSize() const {
    return partySize;
}

// Return the total time the party will dine
int Group::getDiningTime() const {
    return diningTime;
}

// Return how long the party has to wait before seating
int Group::getWaitTime() const {
    return waitTime;
}

// Return true if the party has already been seated
bool Group::isSeated() const {
    return seated;
}

// Update the name of the party
void Group::setName(const std::string& newName) {
    partyName = newName;
}

// Update the number of people in the party
void Group::setSize(int newSize) {
    partySize = newSize;
}

// Update how long the party will dine
void Group::setDiningTime(int newTime) {
    diningTime = newTime;
}

// Set how many minutes the group has to wait
void Group::setWaitTime(int minutes) {
    waitTime = minutes;
}

// Mark the party as seated 
void Group::markSeated() {
    seated = true;
}
