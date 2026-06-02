#pragma once
#include "Villager.h"
#include "JobOffer.h"

class JobTaken {
public:
    static bool hasExistingJob(const Villager& villager,
                               const JobOffer jobs[],
                               int jobCount);
};