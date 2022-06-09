//
// Created by eladm on 07/06/2022.
//

#include "Rogue.h"
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::string;
using std::ostream;


Rogue::Rogue(const string& name,const int force):Player( name,  force){
}
Rogue& Rogue::addCoins(const int numOfCoins){
    assert(numOfCoins);
    if (numOfCoins < 0){
        return *this;
    }
    this->m_coins +=2*numOfCoins;
    return *this;
}

void Rogue::printInfo(ostream &os) const {
    printPlayerDetails(os,m_name,"Rogue",m_level,m_force,m_HP,m_coins);
}
