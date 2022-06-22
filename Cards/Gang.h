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
    Gang(std::deque<std::shared_ptr<BattleCard>> gangMembers);
    ~Gang() override = default;
    Gang(Gang& gang) = default;
    Gang& operator=(const Gang& gang)= default;
    void printInfo() const override;
    void applyEncounter(Player& player) const override;
private:
    std::deque<std::shared_ptr<BattleCard>> m_gangMembers;
};


#endif //CARD_CPP_GANG_H
