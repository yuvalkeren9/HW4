
#include "Player.h"
#include <iostream>
#include <cassert>


using std::ostream;
using std::cout;
using std::endl;
using std::string;



/** ---Player constructor---**/
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


/**
 * increases the level of the player by 1
 */
Player& Player::levelUp(){
    if (this->m_level <10 ){
        ++this->m_level;
    }
    return *this;
}


/**
 * returns the level of the player
 */
int Player::getLevel() const{
    return this->m_level;
}


/**
 * increases the player force by given number
 * @param addedForce - amount of force to increase
 */
Player& Player::buff(const int addedForce){
    assert(addedForce >= 0);
    if (addedForce < 0){
        return *this;
    }
    this->m_force += addedForce;
    return *this;
}


/** increases the player's hp by the amount received as argument */
Player& Player::heal(const int addedHP){
    assert(addedHP >=0);
    if (addedHP < 0){
        return *this;
    }
    if(this->m_HP + addedHP >= DEFAULT_MAX_HP){
        this->m_HP = DEFAULT_MAX_HP;
    }
    else{
        this->m_HP += addedHP;
    }
    return *this;
}


/** decreases the player's hp by the amount received as argument */
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


/** methods returns whether a player's hp is a 0 (returns true if hp is 0) */
bool Player::isKnockedOut() const{
    return !(this->m_HP);
}


/** increases the player's amount of coins by the amount received as argument */
Player& Player::addCoins(const int numOfCoins){
    assert(numOfCoins);
    if (numOfCoins < 0){
        return *this;
    }
    this->m_coins += numOfCoins;
    return *this;
}


/** decreases the player's amount of coins by the amount received as argument. If player doesn't have enough coins, nothing will happen
   * and function will return false. If succeeded, true will be returned.*/
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


/**
 * @return the attackstrength of the player
 */
int Player::getAttackStrength() const{
    return (this->m_level + this->m_force);
}


/**
 * @return the name of the player
 */
string Player::getName() const{
    return this->m_name;
}


/**
 * decreases the force of the player by 1
 */
void Player::decreaseForce(){
    if(this->m_force>0)
    {
        this->m_force= this->m_force-1;
    }
}


/**
 * @return amount of coins of the player
 */
int Player::getCoins() const{
    return this->m_coins;
}


/**
 * @return amount of HP of the player
 */
int Player::getHP() const{
    return this->m_HP;
}


/**
 * /-----  operator <<  -------/
 * the function prints the player info (by asked format) to out stream that given
 * @param os - out stream given
 * @param player - player to print
 * @return os - out stream that given (for pipelining)
 */
ostream& operator<<(ostream& os,const Player& player) {
  player.printInfo(os);
   return  os;
}
