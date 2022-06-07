//
// Created by יובל קרן on 07/06/2022.
//

#include "Dragon.h"
#include "Cards/Card.h"
#include "utilities.h"
#include <iostream>
#include "Player.h"


Dragon::Dragon() {
    m_stats.force = 25;
    m_stats.loot = 1000;
}


void Dragon::printInfo() const{
    printCardDetails( cout, "Dragon");
    printMonsterDetails(cout, m_stats.force, m_stats.hpLossOnDefeat, m_stats.loot, true);
    printEndOfCardDetails(cout);
}

void Dragon::applyEncounter(Player& player) const{
    if (player.getAttackStrength() >= this->m_stats.force) {
        player.levelUp();
        player.addCoins(this->m_stats.loot);
        printWinBattle(player.getName, "Dragon");
    } else {
        int damageToInflict = player.getHP;
        player.damage(damageToInflict);
        printLossBattle(player.getName, "Dragon");
    }
}



