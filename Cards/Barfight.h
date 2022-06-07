//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_BARFIGHT_H
#define CARD_CPP_BARFIGHT_H

#include "Card.h"

class Barfight : public Card{
public:
    Barfight() = default;
    ~Barfight() override = default;
    Barfight(Barfight& barfight) = default;
    void printInfo() const override;
    void applyEncounter(Player& player) const override;
private:
    static const int damamageInflictedByBarFight = 10;
};


#endif //CARD_CPP_BARFIGHT_H
