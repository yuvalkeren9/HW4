//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_VAMPIRE_H
#define CARD_CPP_VAMPIRE_H

#include "BattleCard.h"

class Vampire : public BattleCard {
public:
    Vampire();
    ~Vampire() override = default;
    Vampire(Vampire& vampire) = default;
    void printInfo() const override;
    void applyEncounter(Player& player) const override;
    int getStats(int typeOfStat) const override;



private:
};


#endif //CARD_CPP_VAMPIRE_H
