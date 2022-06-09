//
// Created by eladm on 07/06/2022.
//

#ifndef HW4_ROUGE_H
#define HW4_ROUGE_H
#include "Player.h"
#include "../utilities.h"
#include <cstring>

class Rogue: public Player{

public:
    ~Rogue() override =default;
    explicit Rogue(const std::string& name,const int force = DEFAULT_FORCE);
    Rogue& addCoins(const int numOfCoins) override;
    void printInfo(std::ostream &os) const override;
};


#endif //HW4_ROUGE_H
