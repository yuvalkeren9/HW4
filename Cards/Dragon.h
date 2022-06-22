//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_DRAGON_H
#define CARD_CPP_DRAGON_H

#include "BattleCard.h"

class Dragon : public BattleCard {
public:
    /** constructor**/
    Dragon();

    /** destructor**/
    ~Dragon() override = default;

    /** copy constructor**/
    Dragon(Dragon& dragon) = default;

    /** assigment operator**/
    Dragon& operator=(const Dragon& dragon)= default;

    /** function that prints the Card's info */
    void printInfo() const override;

    /**
   * Handling the player's applyEncounter with the card as required
    * if attack strength is greater than the dragoon force the player wins ,levels up, and receives the loot,
    * otherwise the player is dead
   * @param player - The player.
   * @return  void
  */
    void applyEncounter(Player& player) const override;

    /**
    * function that returns the stats of a card according to argument sent to the function
    * @param typeOfStat 0 for force, 1 for hpLossOnDefeat, 2 for loot
    * @return requested stat
    */
    int getStats(int typeOfStat) const override;

    /**
   * applying an encounter when this card is part of a gang -
   * kiiling the player - decreasing all his HP
   * @param player - the player to apply the gang encounter on
   */
    void gangEncounter (Player &player) const override;

private:
};



#endif //CARD_CPP_DRAGON_H
