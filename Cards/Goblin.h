//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_GOBLIN_H
#define CARD_CPP_GOBLIN_H
#include "BattleCard.h"

class Goblin : public BattleCard {
public:
    Goblin();
    ~Goblin() override = default;
    Goblin(Goblin& goblin) = default;
    void printInfo() const override;
    void applyEncounter(Player& player) const override;
    int getStats(int typeOfStat) const override;
    void gangEncounter (Player &player) const override;




private:
};


#endif //CARD_CPP_GOBLIN_H
