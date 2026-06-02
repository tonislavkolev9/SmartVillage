#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Services {
    private:
        string name;
        string desc;
    public:
        Services(string name, string desc);

        void setName(string NAME);
        string getName() const;

        void setDesc(string DESC);
        string getDesc() const; 
        
        virtual void offer() = 0;
        virtual void action() = 0;

        virtual ~Services() {}
    };

        class Doctor : public Services {
        public:
        static int doctor_counter;
        Doctor(string name, string desc);
        void action() override;
        void offer() override;
     };

     class Shop : public Services {
        public:
        static int shop_counter;
        Shop(string name, string desc);
        void action() override;
        void offer() override;
     };

     class Repairman : public Services {
        public:
        static int repairman_counter;
        Repairman(string name, string desc);
        void action() override;
        void offer() override;
     };