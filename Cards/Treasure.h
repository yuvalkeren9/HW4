//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_TREASURE_H
#define CARD_CPP_TREASURE_H

#include "Card.h"
#include "../Players/Player.h"

class Treasure : public Card {
public:
    Treasure();
    ~Treasure() override = default;
    Treasure(Treasure &treasure) = default;
    Treasure& operator=(const Treasure& treasure)= default;
    void applyEncounter(Player& player) const override;
    void printInfo() const override;
private:
    static const int defaultLoot = 10;
};


#endif //CARD_CPP_TREASURE_H
