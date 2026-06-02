#pragma once
#include "Villager.h"
#include "Services.h"

class JobOffer {
private:
    Villager villager;
    Services* service;
    bool taken;

public:
    JobOffer();
    JobOffer(const Villager& villager);

    void assignService(Services* s);
    void showOffer() const;
    void jobDone() const;

    bool getIsTaken() const;

    const Villager& getVillager() const;
};