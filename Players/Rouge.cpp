//
// Created by eladm on 07/06/2022.
//

#include "Rouge.h"
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::string;


Rouge::Rouge(const string& name,const int force):Player( name,  force){
}
Rouge& Rouge::addCoins(const int numOfCoins){
    assert(numOfCoins);
    if (numOfCoins < 0){
        return *this;
    }
    this->m_coins +=2*numOfCoins;
    return *this;
}

void Rouge::printInfo(ostream &os) const {
    printPlayerDetails(os,m_name,"Rouge",m_level,m_force,m_HP,m_coins);
}
