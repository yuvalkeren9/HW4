//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_MERCHANT_H
#define CARD_CPP_MERCHANT_H
#include "Card.h"

class Merchant : public Card {
public:

    /** constructor**/
    Merchant() = default;

    /** destructor**/
    ~Merchant() override = default;

    /** copy constructor**/
    Merchant(Merchant& merchant) = default;

    /** assigment operator**/
    Merchant& operator=(const Merchant& merchant)= default;

    /**
      * Handling the player's applyEncounter with the card as required
      * receiving input from user and according to input:
      * allows to increase HP or Force and decreasing coins (if the player has enough)
      * @param player - The player.
      * @return  void
      */
    void applyEncounter(Player& player) const override;


    /** function that prints the Card's info */
    void printInfo() const override;

private:
    static const int priceOfHealthPotion = 5;
    static const int priceOfBuffBoost = 10;
};


#endif //CARD_CPP_MERCHANT_H
