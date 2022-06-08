//
// Created by eladm on 07/06/2022.
//

#ifndef HW4_ROUGE_H
#define HW4_ROUGE_H
#include "Player.h"
#include "../utilities.h"

class Rouge: public Player{

public:
    ~Rouge() override =default;
    explicit Rouge(const string& name,const int force = DEFAULT_FORCE);
    Rouge& addCoins(const int numOfCoins) override;
    void printInfo(ostream &os) const override;
};


#endif //HW4_ROUGE_H
