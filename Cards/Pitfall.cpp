//
// Created by יובל קרן on 07/06/2022.
//

#include "Pitfall.h"

void Pitfall::printInfo() const {
    printCardDetails( cout, "Pitfall");
    printEndOfCardDetails(cout);
}

void Pitfall::applyEncounter(Player &player) const {
    const Rogue* rogue = dynamic_cast<const Rogue*>(player);
    if (rogue == nullptr){
        player.damage(damamageInflictedByPitfall);
    }
}