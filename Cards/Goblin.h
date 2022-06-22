//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_GOBLIN_H
#define CARD_CPP_GOBLIN_H
#include "BattleCard.h"

class Goblin : public BattleCard {
public:

    /** constructor**/
    Goblin();

    /** destructor**/
    ~Goblin() override = default;

    /** copy constructor**/
    Goblin(Goblin& goblin) = default;

    /** assigment operator**/
    Goblin& operator=(const Goblin& goblin)= default;

    /** function that prints the Card's info */
    void printInfo() const override;


    /**
   * Handling the player's applyEncounter with the card as required
    * attack strength is greater than the Goblin force the player wins and levels up
    * otherwise, decreasing the player HP by 10
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
      * decreasing the player HP by 10
      * @param player - the player to apply the gang encounter on
      */
    void gangEncounter (Player &player) const override;




private:
};


#endif //CARD_CPP_GOBLIN_H
