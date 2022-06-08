//
// Created by eladm on 07/06/2022.
//

#include "Fighter.h"
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::string;


Fighter::Fighter(const string& name,const int force):Player( name, force){
}
int Fighter::getAttackStrength() const{
    return (this->m_level + 2*(this->m_force));
}
void Fighter::printInfo(ostream &os) const {
    printPlayerDetails(os,m_name,"Fighter",m_level,m_force,m_HP,m_coins);

}
