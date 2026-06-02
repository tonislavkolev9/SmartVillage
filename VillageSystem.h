#pragma once
#include "registerUser.h"
#include "JobOffer.h"
#include "Services.h"
#include <string>
using std::string;

class VillageSystem {
private:
    registerUser users;
    Services* services[100];
    int serviceCount;
    JobOffer jobs[100];
    int jobCount;

public:
    VillageSystem();
    ~VillageSystem();

    void addVillager(string name, int age, string role);
    void addService(int type, string name, string desc);
    void createJob(int villagerIndex);
    void assignServiceToJob(int jobIndex, Services* service);
    void showAllJobs() const;
};