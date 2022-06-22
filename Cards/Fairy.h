//
// Created by יובל קרן on 07/06/2022.
//

#ifndef CARD_CPP_FAIRY_H
#define CARD_CPP_FAIRY_H


#include "Card.h"
#include "../Players/Wizard.h"

class Fairy : public Card{
public:

    /** constructor**/
    Fairy() = default;

    /** destructor**/
    ~Fairy() override = default;

    /** copy constructor**/
    Fairy(Fairy& fairy) = default;

    /** assigment operator**/
    Fairy& operator=(const Fairy& fairy)= default;

    /** function that prints the Card's info */
    void printInfo() const override;

    /**
  * Handling the player's applyEncounter with the card as required
   * if player type is Wizard ,increase HP with 20
   * otherwise nothing happens
  * @param player - The player.
  * @return  void
 */
    void applyEncounter(Player& player) const override;
private:
    static const int healthHealedByFairy = 10;
};

#endif //CARD_CPP_FAIRY_H
