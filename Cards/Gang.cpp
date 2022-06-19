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
    for(const std::shared_ptr<BattleCard>& gangMember : m_gangMembers){
        if (player.getAttackStrength() >= gangMember->getStats(0)) {
            cout << "Inside Gang" << endl;
            gangMember->printInfo();
        }

    }
}