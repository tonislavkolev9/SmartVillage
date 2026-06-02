#include "JobTaken.h"
#include "JobOffer.h"

bool JobTaken::hasExistingJob(const Villager& villager,
                                  const JobOffer jobs[],
                                  int jobCount) {
    for (int i = 0; i < jobCount; i++) {
        if (jobs[i].getVillager().getName() == villager.getName()) {
            return true;
        }
    }
    return false;
}