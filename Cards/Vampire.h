//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_VAMPIRE_H
#define CARD_CPP_VAMPIRE_H

#include "Card.h"

class Vampire : public Card {
public:
    Vampire();
    ~Vampire() override = default;
    Vampire(Vampire& vampire) = default;
    void printInfo() const override;
    void applyEncounter(Player& player) const override;



private:
};


#endif //CARD_CPP_VAMPIRE_H
