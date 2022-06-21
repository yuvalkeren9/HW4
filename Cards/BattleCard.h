//
// Created by יובל קרן on 19/06/2022.
//

#ifndef CARD_CPP_BATTLECARD_H
#define CARD_CPP_BATTLECARD_H
#include "Card.h"


class BattleCard : public Card {
public:
    BattleCard() = default;
    ~BattleCard() override = default;
    BattleCard(BattleCard& BattleCard) = default;
    /**
     * function that returns the stats of a card
     * @param typeOfStat 0 for force, 1 for hpLossOnDefeat, 2 for loot
     * @return requested stat
     */
    virtual int getStats(int typeOfStat) const = 0;

    /**
     * applying an encounter when this card is part of a gang
     * @param player - the player to apply the gang encounter on
     */
    virtual void gangEncounter (Player &player) const = 0;


};


#endif //CARD_CPP_BATTLECARD_H
