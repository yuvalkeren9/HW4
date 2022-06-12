//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_MERCHANT_H
#define CARD_CPP_MERCHANT_H
#include "Card.h"

class Merchant : public Card {
public:
    Merchant() = default;
    ~Merchant() override = default;
    Merchant(Merchant& merchant) = default;
    void applyEncounter(Player& player) const override;
    void printInfo() const override;

private:
    static const int priceOfHealthPotion = 5;
    static const int priceOfBuffBoost = 10;
};


#endif //CARD_CPP_MERCHANT_H
