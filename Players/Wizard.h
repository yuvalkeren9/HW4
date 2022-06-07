//
// Created by eladm on 07/06/2022.
//

#ifndef HW4_WIZARD_H
#define HW4_WIZARD_H
#include "Player.h"
#include "../utilities.h"

class Wizard: public Player{

public:
    ~Wizard() override =default;
    Wizard();
    explicit Wizard(const string& name, const int maxHP = DEFAULT_MAX_HP ,const int force = DEFAULT_FORCE);
    Wizard& heal(const int addedHP) override;
    void printInfo(ostream &os) const override;
};



#endif //HW4_WIZARD_H
