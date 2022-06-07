//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_FAIRY_H
#define CARD_CPP_FAIRY_H


#include "Card.h"

class Fairy : public Card{
public:
    Fairy() = default;
    ~Fairy() override = default;
    Fairy(Fairy& fairy) = default;
    void printInfo() const override;
    void applyEncounter(Player& player) const override;
private:
    static const int healthHealedByFairy = 10;
};

#endif //CARD_CPP_FAIRY_H
