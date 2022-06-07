//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_PITFALL_H
#define CARD_CPP_PITFALL_H


#include "Card.h"
#include "../Players/Rouge.h"

class Pitfall : public Card{
public:
    Pitfall() = default;
    ~Pitfall() override = default;
    Pitfall(Pitfall& pitfall) = default;
    void printInfo() const override;
    void applyEncounter(Player& player) const override;
private:
    static const int damageInflictedByPitfall = 10;
};



#endif //CARD_CPP_PITFALL_H
