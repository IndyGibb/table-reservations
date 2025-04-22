#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>

// The Group class represents a dining party at a restaurant.
// It stores the party's name, size, how long they'll dine, how long they'll wait,
// and whether they have been successfully seated.
class Group {
public:
    // Constructor to create a group with name, size, and dining time.
    Group(const std::string& name, int size, int diningTime);

    // Getters
    std::string getName() const;      // Returns the name of the party
    int getSize() const;              // Returns the number of people in the party
    int getDiningTime() const;        // Returns the total time the party will dine
    int getWaitTime() const;          // Returns how long the party has to wait
    bool isSeated() const;            // Returns true if the party has been seated

    // Setters
    void setName(const std::string& newName);     // Updates the name of the party
    void setSize(int newSize);                    // Updates the size of the party
    void setDiningTime(int newTime);              // Updates the dining time
    void setWaitTime(int minutes);                // Sets how long the group has to wait
    void markSeated();                            // Marks the group as successfully seated

private:
    std::string partyName;    // Name of the party
    int partySize;            // Number of people in the party
    int diningTime;           // How long the party stays once seated (in minutes)
    int waitTime;             // How long the party has to wait before being seated
    bool seated;              // Whether the party has been assigned a table
};

#endif
