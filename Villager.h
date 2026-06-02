#pragma once
#include <iostream>
#include <string>
using std::string;
using std::ostream;

    class Villager {
    private:
        string name;
        int age;
        string role; // jitel, rabota.. t.n
    public:
        static int villager_counter;
        Villager () {};
        Villager (string name, int age, string role);

        void setName(string NAME);
        string getName() const;

        void setAge(int AGE);
        int getAge() const;

        void setRole(string ROLE);
        string getRole() const;


        friend ostream& operator<<(ostream& COUT, Villager& rhs);
    };  