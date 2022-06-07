//
// Created by יובל קרן on 07/06/2022.
//

#include "Pitfall.h"

void Pitfall::printInfo() const {
    printCardDetails( cout, "Pitfall");
    printEndOfCardDetails(cout);
}

void Pitfall::applyEncounter(Player &player) const {
    Player* ptr = &player;    //test this yuval~!!~!!!!
    const Rouge* rouge = dynamic_cast<const Rouge*>(ptr);
    if (rouge == nullptr){
        player.damage(damageInflictedByPitfall);
    }
}