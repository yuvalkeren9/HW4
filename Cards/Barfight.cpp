//
// Created by יובל קרן on 07/06/2022.
//

#include "Barfight.h"
using std::cout;
using std::endl;
using std::string;


void Barfight::printInfo() const {
    printCardDetails( cout, "Barfight");
    printEndOfCardDetails(cout);
}

void Barfight::applyEncounter(Player &player) const {
    Player* ptr = &player;
    const Fighter* fighter = dynamic_cast<const Fighter*>(ptr);
    if (fighter == nullptr){
        player.damage(damageInflictedByBarFight);
        printBarfightMessage(false);
    }
    else{
        printBarfightMessage(true);
    }
}