#include <iostream>
#include "Services.h"
using std::string;

        int Doctor::doctor_counter = 0;
        int Repairman::repairman_counter = 0;
        int Shop::shop_counter = 0;

        Services::Services(string name, string desc) {
            this->name = name;
            this->desc = desc;
        };

        void Services::setName(string NAME) { name = NAME; }
        string Services::getName() const { return name; }

        void Services::setDesc(string DESC) { desc = DESC; }
        string Services::getDesc() const { return desc; }

        Doctor::Doctor(string name, string desc) : Services(name, desc) { Doctor::doctor_counter++; };

        void Doctor::action() {
            cout << "The doctor is performing a routine check" << endl;
        }

        void Doctor::offer() {
            cout << "Doctor services" << endl;
        }

        Repairman::Repairman(string name, string desc) : Services(name, desc) { Repairman::repairman_counter++; }; 

        void Repairman::action() {
            cout << "The repairman is fixing the problem" << endl;
        }

        void Repairman::offer() {
            cout << "Repairman services" << endl;
        }

        void Shop::offer() {
            cout << "Shopkeeper services" << endl;
        }

        Shop::Shop(string name, string desc) : Services(name, desc) { Shop::shop_counter++; };

        void Shop::action() {
            cout << "The shopkeeper is checking the customer out" << endl;
        }