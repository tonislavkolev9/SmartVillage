#include <iostream>
#include <string>
#include "Menu.h"
#include "Services.h"
#include "Villager.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

    void showStats() {
        cout << "Residents: " << Villager::villager_counter << endl;
        cout << "Doctors: " << Doctor::doctor_counter << endl;
        cout << "Repairman: " << Repairman::repairman_counter << endl;
        cout << "Shopkeepers: " << Shop::shop_counter << endl;
        cout << "=========================" << endl;
    }

    void showMainMenu() {
        cout << "=========================" << endl;
        cout << "1. Show job offers" << endl;
        cout << "2. Add a villager" << endl;
        cout << "3. Add a service" << endl;
        cout << "4. Create a job offer" << endl;
        cout << "5. Exit" << endl;
        cout << "=========================" << endl;
        showStats();
    }

    enum menuOptions {
        Show_Offer = 1,
        Add_Villager,
        Add_Service,
        Create_Job,
        Exit
    };

    void showOffers(VillageSystem& village) {
        cout << "=========================" << endl;
        cout << "Current job offers:" << endl;
        village.showAllJobs();
        cout << "=========================" << endl;
    }

    void addVillager(VillageSystem& village) {
        string name, role;
        int age;
        cout << "Enter villager name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter role (e.g. Resident): ";
        cin >> role;
        village.addVillager(name, age, role);
        cout << "Villager added!" << endl;
    }

    void addService(VillageSystem& village) {
        int type;
        string name, desc;
        cout << "Service type: 1) Doctor  2) Repairman  3) Shop" << endl;
        cout << "Choice: ";
        cin >> type;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter description: ";
        cin.ignore();
        getline(cin, desc);
        village.addService(type, name, desc);
        cout << "Service added!" << endl;
    }

    void createJob(VillageSystem& village) {
        int index;
        cout << "Enter villager index to create job for: ";
        cin >> index;
        village.createJob(index);
        cout << "Job offer created!" << endl;
    }

    void addListing(VillageSystem& village) {}

    void handleChoice(int choice, VillageSystem& village) {
        switch (choice) {
            case Show_Offer:
                showOffers(village);
                break;
            case Add_Villager:
                addVillager(village);
                break;
            case Add_Service:
                addService(village);
                break;
            case Create_Job:
                createJob(village);
                break;
            case Exit:
                cout << "Exiting..." << endl;
                break;
        }
    }

    void runMenu(VillageSystem& village) {
        int choice;
        do {
            showMainMenu();
            cout << "Enter your choice: ";
            while (true) {
                if (!(cin >> choice)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid choice! Try again: ";
                }
                else if (choice < 1 || choice > 5) {
                    cout << "Invalid choice! Try again: ";
                }
                else { break; }
            }
            handleChoice(choice, village);
        } while (choice != Exit);
    }