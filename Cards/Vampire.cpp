//
// Created by יובל קרן on 07/06/2022.
//

#include "Vampire.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Vampire::Vampire() {
    m_stats.force = 10;
    m_stats.loot = 2;
    m_stats.hpLossOnDefeat = 10;
}


void Vampire::printInfo() const{
    printCardDetails( cout, "Vampire");
    printMonsterDetails(cout, m_stats.force, m_stats.hpLossOnDefeat, m_stats.loot, false);
    printEndOfCardDetails(cout);
}

void Vampire::applyEncounter(Player& player) const{
    if (player.getAttackStrength() >= this->m_stats.force) {
        player.levelUp();
        player.addCoins(this->m_stats.loot);
        printWinBattle(player.getName(), "Vampire");
    } else {
        player.damage(this->m_stats.hpLossOnDefeat);
        player.decreaseForce();
        printLossBattle(player.getName(), "Vampire");
    }
}

int Vampire::getStats(int typeOfStat) const {
    switch (typeOfStat){
        case RETURN_VALUE_FORCE_FLAG:
            return m_stats.force;
        case RETURN_VALUE_HP_LOSS_FLAG:
            return m_stats.hpLossOnDefeat;
        case RETURN_VALUE_LOOT_FLAG:
            return m_stats.loot;
        default:
            return 0;
    }
}
void Vampire::gangEncounter (Player &player) const{
    player.damage(this->m_stats.hpLossOnDefeat);
    player.decreaseForce();
    printLossBattle(player.getName(), "Vampire");
}


