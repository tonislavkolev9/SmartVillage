#pragma once
#include <iostream>
#include <string>
#include "Villager.h"

using std::string;
using std::cout;
using std::endl;

class registerUser {
private:
    Villager villagers[100];
    int count;

public:
    registerUser();

    void addUser(string name, int age, string role);
    void printAll() const;
    Villager getVillager(int index) const;
    friend ostream& operator<<(ostream& COUT, const Villager& rhs);  
};