//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_BARFIGHT_H
#define CARD_CPP_BARFIGHT_H

#include "Card.h"
#include "../Players/Fighter.h"

class Barfight : public Card{
public:

    /** constructor**/
    Barfight() = default;

    /** destructor**/
    ~Barfight() override = default;

    /** copy constructor**/
    Barfight(Barfight& barfight) = default;

    /** assigment operator**/
    Barfight& operator=(const Barfight& barfight)= default;


    /** function that prints the Card's info */
    void printInfo() const override;

    /**
    * Handling the player's applyEncounter with the card as required
     * reducing 10 HP to player unless the player type is Fighter, if so nothing happens
    * @param player - The player.
    * @return  void
   */
    void applyEncounter(Player& player) const override;

private:
    static const int damageInflictedByBarFight = 10;
};


#endif //CARD_CPP_BARFIGHT_H
