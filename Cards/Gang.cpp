//
// Created by יובל קרן on 19/06/2022.
//

#include "Gang.h"
using std::cout;
using std::endl;

Gang::Gang(std::deque<std::shared_ptr<BattleCard>> gangMembers) : m_gangMembers(gangMembers){
}

void Gang::printInfo() const {
    printCardDetails( cout, "Gang");
    printEndOfCardDetails(cout);
}

void Gang::applyEncounter(Player &player) const {
    bool lostEncounterFlag = false;
    for(const std::shared_ptr<BattleCard>& gangMember : m_gangMembers){
        if (!lostEncounterFlag && player.getAttackStrength() >= gangMember->getStats(0)) {
            player.addCoins(gangMember->getStats(2));
        }
        else{
            lostEncounterFlag = true;
            gangMember->gangEncounter(player);
        }
    }
    if (!lostEncounterFlag){
        player.levelUp();
        printWinBattle(player.getName(), "Gang");
    }

}