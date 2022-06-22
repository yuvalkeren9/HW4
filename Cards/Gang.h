//
// Created by יובל קרן on 19/06/2022.
//

#ifndef CARD_CPP_GANG_H
#define CARD_CPP_GANG_H
#include "Card.h"
#include <deque>
#include <memory>
#include "BattleCard.h"

class Gang : public Card {
public:

    /** constructor**/
    Gang(std::deque<std::shared_ptr<BattleCard>> gangMembers);


    /** destructor**/
    ~Gang() override = default;

    /** copy constructor**/
    Gang(Gang& gang) = default;

    /** assigment operator**/
    Gang& operator=(const Gang& gang)= default;

    /** function that prints the Card's info */
    void printInfo() const override;

    /**
     * Handling the player's applyEncounter with every card in the GANG
     * if all encounters finish within a win for the player, he levels up
     * otherwise, from the encounter the player lost and on, he will lose in all encounters regardless his attack strength
     * @param player - The player.
     * @return  void
     */
    void applyEncounter(Player& player) const override;
private:
    std::deque<std::shared_ptr<BattleCard>> m_gangMembers;
};


#endif //CARD_CPP_GANG_H
