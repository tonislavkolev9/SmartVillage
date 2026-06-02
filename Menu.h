#pragma once
#include <iostream>
#include "VillageSystem.h"

void showMainMenu();
void showStats();
void showOffers(VillageSystem& village);
void addListing(VillageSystem& village);
void handleChoice(int choice, VillageSystem& village);
void runMenu(VillageSystem& village);