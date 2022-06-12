
#include "Player.h"
#include <iostream>
#include <cassert>


using std::ostream;

using std::cout;
using std::endl;
using std::string;

Player::Player(const string& name, const int force) :
    m_name(name),
    m_level(DEFAULT_ENTRY_LEVEL),
    m_force(force),
    m_HP(DEFAULT_MAX_HP),
    m_coins(DEFAULT_COINS)
{
    if (force <= 0){
        this->m_force = DEFAULT_FORCE;
    }
}
//
//void Player::printInfo() const {
//    const char* nameSent = m_name.c_str();     //converting from string type to char* type
//    printPlayerInfo(nameSent, this->m_level, this->m_force, this->m_HP, this->m_coins);
//
//}

Player& Player::levelUp(){
    if (this->m_level <10 ){
        ++this->m_level;
    }
    return *this;
}

int Player::getLevel() const{
    return this->m_level;
}

Player& Player::buff(const int addedForce){
    assert(addedForce >= 0);
    if (addedForce < 0){
        return *this;
    }
    this->m_force += addedForce;
    return *this;
}

Player& Player::heal(const int addedHP){
    assert(addedHP >=0);
    if (addedHP < 0){
        return *this;
    }
    if(this->m_HP + addedHP >= this->DEFAULT_MAX_HP){
        this->m_HP = this->DEFAULT_MAX_HP;
    }
    else{
        this->m_HP += addedHP;
    }
    return *this;
}

Player& Player::damage(const int damageInflicted){
    assert(damageInflicted >= 0);
    if (damageInflicted < 0){
        return *this;
    }
    if (this->m_HP - damageInflicted <= 0){
        this->m_HP =0;
    }
    else {
        this->m_HP -= damageInflicted;
    }
    return *this;
}

bool Player::isKnockedOut() const{
    return !(this->m_HP);
}

Player& Player::addCoins(const int numOfCoins){
    assert(numOfCoins);
    if (numOfCoins < 0){
        return *this;
    }
    this->m_coins += numOfCoins;
    return *this;
}
bool Player::pay(const int price){
    assert (price >= 0);
    if (price <= 0){
        return true;
    }
    if (this->m_coins < price){
        return false;
    }
    this->m_coins -= price;
    return true;
}

int Player::getAttackStrength() const{
    return (this->m_level + this->m_force);
}

string Player::getName() const{
    return this->m_name;
}

void Player::decreaseForce(){
    if(this->m_force>0)
    {
        this->m_force= this->m_force-1;
    }
}

int Player::getCoins(){
    return this->m_coins;
}
int Player::getHP(){
    return this->m_HP;
}
ostream& operator<<(ostream& os,const Player& player) {
    player.printInfo(os);
    return  os;
}
