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

/** constructor  **/
Rogue::Rogue(const string& name,const int force):Player( name,  force){
}

/** increasingvRogue coins by given number**/
Rogue& Rogue::addCoins(const int numOfCoins){
    assert(numOfCoins);
    if (numOfCoins < 0){
        return *this;
    }
    this->m_coins +=2*numOfCoins;
    return *this;
}
/** printing function  **/
void Rogue::printInfo(ostream &os) const {
    printPlayerDetails(os,m_name,"Rogue",m_level,m_force,m_HP,m_coins);
}
