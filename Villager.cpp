#include "Villager.h"
#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::cout;
using std::endl;

        int Villager::villager_counter = 0;
        
        Villager::Villager (string name, int age, string role) {
            this->name = name;
            this->age = age;
            this->role = role;
            Villager::villager_counter++;
        }

        void Villager::setName(string NAME) { name = NAME; }
        string Villager::getName() const { return name; }

        void Villager::setAge(int AGE) { age = AGE; }
        int Villager::getAge() const { return age; }

        void Villager::setRole(string ROLE) { role = ROLE; }
        string Villager::getRole() const { return role; }


        ostream& operator<<(ostream& COUT, Villager& rhs) {
            COUT << rhs.getName();
            COUT << rhs.getAge();
            COUT << rhs.getRole();
            return COUT;
        }