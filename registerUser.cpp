#include <iostream>
#include "registerUser.h"

registerUser::registerUser() : count(0) {}

void registerUser::addUser(string name, int age, string role) {
    if (count >= 100) {
        cout << "Storage full!" << endl;
        return;
    }

    villagers[count] = Villager(name, age, role);
    count++;
}

Villager registerUser::getVillager(int index) const {
    if (index < 0 || index >= count) {
        cout << "Invalid index!" << endl;
        return Villager();
    }
    return villagers[index];
}

ostream& operator<<(ostream& COUT, const Villager& rhs) {
    COUT << rhs.getName() << " " << rhs.getAge() << " " << rhs.getRole();
    return COUT;
}


void registerUser::printAll() const {
    if (count == 0) {
        cout << "No villagers registered." << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "[" << i << "] "
             << villagers[i].getName() << ", age "
             << villagers[i].getAge() << ", "
             << villagers[i].getRole() << endl;
    }
}