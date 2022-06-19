//
// Created by יובל קרן on 19/06/2022.
//

#ifndef CARD_CPP_BATTLECARD_H
#define CARD_CPP_BATTLECARD_H
#include "Card.h"


class BattleCard : public Card {
public:
    BattleCard() = default;
    virtual ~BattleCard() override = default;
    BattleCard(BattleCard& BattleCard) = default;
    virtual void printInfo() const override = 0;
    virtual void applyEncounter(Player& player)  const override = 0;
    /**
     *
     * @param typeOfStat 0 for force, 1 for hpLossOnDefeat, 2 for loot
     * @return requested stat
     */
    virtual int getStats(int typeOfStat) const = 0;


};


#endif //CARD_CPP_BATTLECARD_H
