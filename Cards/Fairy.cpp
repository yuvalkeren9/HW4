//
// Created by יובל קרן on 07/06/2022.
//

#include "Fairy.h"


void Fairy::printInfo() const {
    printCardDetails( cout, "Fairy");
    printEndOfCardDetails(cout);
}

void Fairy::applyEncounter(Player &player) const {
    Player* ptr = &player;
    const Wizard* wizard = dynamic_cast<const Wizard*>(ptr);
    if (wizard != nullptr){
        player.heal(healthHealedByFairy);
        printFairyMessage(true);
    }
    else{
        printFairyMessage(false);
    }
}