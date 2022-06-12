//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_DRAGON_H
#define CARD_CPP_DRAGON_H

#include "Card.h"

class Dragon : public Card {
public:
    Dragon();
    ~Dragon() override = default;
    Dragon(Dragon& dragon) = default;
    void printInfo() const override;
    void applyEncounter(Player& player) const override;



private:
};



#endif //CARD_CPP_DRAGON_H
