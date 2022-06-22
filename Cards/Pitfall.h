//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_PITFALL_H
#define CARD_CPP_PITFALL_H


#include "Card.h"
#include "../Players/Rogue.h"

class Pitfall : public Card{
public:

    /** constructor**/
    Pitfall() = default;

    /** destructor**/
    ~Pitfall() override = default;

    /** copy constructor**/
    Pitfall(Pitfall& pitfall) = default;

    /** assigment operator**/
    Pitfall& operator=(const Pitfall& pitfall)= default;

    /** function that prints the Card's info */
    void printInfo() const override;

    /**
  * Handling the player's applyEncounter with the card as required
   * if player type is Rogue nothing happens ,otherwise ,decrease HP by 10
  * @param player - The player.
  * @return  void
 */
    void applyEncounter(Player& player) const override;
private:
    static const int damageInflictedByPitfall = 10;
};



#endif //CARD_CPP_PITFALL_H
