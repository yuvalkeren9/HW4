//
// Created by eladm on 07/06/2022.
//

#include "Fighter.h"
#include <iostream>


using std::cout;
using std::endl;
using std::string;
using std::ostream;

/** constructor  **/
Fighter::Fighter(const string& name,const int force):Player( name, force){
}
/** get attackstrength function  **/
int Fighter::getAttackStrength() const{
    return (this->m_level + 2*(this->m_force));
}

/** printing function  **/
void Fighter::printInfo(ostream &os) const {
    printPlayerDetails(os,m_name,"Fighter",m_level,m_force,m_HP,m_coins);

}
