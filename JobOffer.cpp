#include <iostream>
#include "JobOffer.h"

using std::cout;
using std::endl;

JobOffer::JobOffer() : service(nullptr), taken(false) {}

JobOffer::JobOffer(const Villager& villager)
    : villager(villager), service(nullptr), taken(false) {}

const Villager& JobOffer::getVillager() const {
    return villager;
}

void JobOffer::assignService(Services* s) {
    if (!taken) {
        service = s;
        taken = true;
    }
}

void JobOffer::showOffer() const {
    cout << "Villager " << villager.getName() << " needs help." << endl;

    if (taken) {
        cout << "Taken by service: " << service->getName() << endl;
    } else {
        cout << "Status: Available" << endl;
    }
}

void JobOffer::jobDone() const {
    if (!taken || service == nullptr) {
        cout << "No service has taken this job yet." << endl;
        return;
    }

    cout << "Service " << service->getName() << " is doing the job for "
         << villager.getName() << endl;

    service->action();
}

bool JobOffer::getIsTaken() const {
    return taken;
}