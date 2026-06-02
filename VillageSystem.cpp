#include <iostream>
#include "VillageSystem.h"
#include "JobTaken.h"

using std::cout;
using std::endl;


VillageSystem::VillageSystem() : jobCount(0), serviceCount(0) {}


VillageSystem::~VillageSystem() {
    for (int i = 0; i < serviceCount; i++) {
        delete services[i];
    }
}

void VillageSystem::addVillager(string name, int age, string role) {
    users.addUser(name, age, role);
}


void VillageSystem::addService(int type, string name, string desc) {
    if (serviceCount >= 100) {
        cout << "Service storage full!" << endl;
        return;
    }
    if (type == 1)      services[serviceCount++] = new Doctor(name, desc);
    else if (type == 2) services[serviceCount++] = new Repairman(name, desc);
    else if (type == 3) services[serviceCount++] = new Shop(name, desc);
    else cout << "Unknown service type." << endl;
}

void VillageSystem::createJob(int villagerIndex) {
    Villager v = users.getVillager(villagerIndex);

    if (JobTaken::hasExistingJob(v, jobs, jobCount)) {
        cout << v.getName() << " already has a job offer." << endl;
        return;
    }

    jobs[jobCount] = JobOffer(v);
    jobCount++;
}

void VillageSystem::assignServiceToJob(int jobIndex, Services* service) {
    jobs[jobIndex].assignService(service);
}


void VillageSystem::showAllJobs() const {
    if (jobCount == 0) {
        cout << "No job offers yet." << endl;
        return;
    }
    for (int i = 0; i < jobCount; i++) {
        cout << "[" << i << "] ";
        jobs[i].showOffer();
    }
}
