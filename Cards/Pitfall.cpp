//
// Created by יובל קרן on 07/06/2022.
//

#include "Pitfall.h"
using std::cout;
using std::endl;
using std::string;


void Pitfall::printInfo() const {
    printCardDetails( cout, "Pitfall");
    printEndOfCardDetails(cout);
}

void Pitfall::applyEncounter(Player &player) const {
    Player* ptr = &player;    //test this yuval~!!~!!!!
    const Rogue* rouge = dynamic_cast<const Rogue*>(ptr);
    if (rouge == nullptr){
        player.damage(damageInflictedByPitfall);
        printPitfallMessage(false);
    }
    else{
        printPitfallMessage(true);
    }
}