//
// Created by יובל קרן on 07/06/2022.
//

#include "Goblin.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;


Goblin::Goblin() {
    m_stats.force = 6;
    m_stats.loot = 2;
    m_stats.hpLossOnDefeat = 10;
}


void Goblin::printInfo() const{
    printCardDetails( cout, "Goblin");
    printMonsterDetails(cout, m_stats.force, m_stats.hpLossOnDefeat, m_stats.loot, false);
    printEndOfCardDetails(cout);
}


void Goblin::applyEncounter(Player& player) const{
    if (player.getAttackStrength() >= this->m_stats.force) {
                player.levelUp();
                player.addCoins(this->m_stats.loot);
                printWinBattle(player.getName(), "Goblin");
            }
    else {
               player.damage(this->m_stats.hpLossOnDefeat);
               printLossBattle(player.getName(), "Goblin");
            }
}

int Goblin::getStats(int typeOfStat) const {
    switch (typeOfStat){
        case 0:
            return m_stats.force;
        case 1:
            return m_stats.hpLossOnDefeat;
        case 2:
            return m_stats.loot;
        default:
            return 0;
    }
}

void Goblin::gangEncounter (Player &player) const {
    player.damage(this->m_stats.hpLossOnDefeat);
    printLossBattle(player.getName(), "Goblin");
}