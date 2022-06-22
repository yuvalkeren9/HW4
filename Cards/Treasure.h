//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_TREASURE_H
#define CARD_CPP_TREASURE_H

#include "Card.h"
#include "../Players/Player.h"

class Treasure : public Card {
public:

    /** constructor**/
    Treasure();

    /** destructor**/
    ~Treasure() override = default;

    /** copy constructor**/
    Treasure(Treasure &treasure) = default;

    /** assigment operator**/
    Treasure& operator=(const Treasure& treasure)= default;

    /**
   * Handling the player's applyEncounter with the card as required
   * Increasing the player coins by 10
   * @param player - The player.
   * @return  void
   */
    void applyEncounter(Player& player) const override;

    /** function that prints the Card's info */
    void printInfo() const override;
private:
    static const int defaultLoot = 10;
};


#endif //CARD_CPP_TREASURE_H
