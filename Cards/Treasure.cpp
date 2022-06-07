//
// Created by יובל קרן on 07/06/2022.
//

#include "Treasure.h"


Treasure::Treasure() {
    m_stats.loot = 10;
}

void Treasure::applyEncounter(Player& player) const {
    player.addCoins(m_stats.loot);
    printTreasureMessage();
}

void Treasure::printInfo() const{
    printCardDetails( cout, "Treasure");
    printEndOfCardDetails(cout);
}