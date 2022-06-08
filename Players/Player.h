
#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H


#include <iostream>
//using std::cout;
//using std::endl;
//using std::string;
//using std::ostream;
/** a class that represents a player type. The class hold the player's name, his current level, current force, his max HP, current player's HP, and
 * the amount of coins he has */
class Player {

public:

    /** basic constructors for the Player type. Notice the build constructor is not default, and has default values if not attributed by user.
    * Also, a player will always be initialized with a level 1 and 0 coins.*/

    explicit Player(const std::string& name,const int force = DEFAULT_FORCE);
    Player(const Player& player) = default;



    virtual  ~Player() = default;
    Player& operator=(const Player&) = default;

    /** function that prints the Player's info */
    virtual void printInfo(std::ostream &os) const=0;

    /** increases the player's level by 1 */
    Player& levelUp();

    /** getter functions */
    int getLevel() const;
    virtual int getAttackStrength() const;
    std::string getName() const;
    int getCoins();
    int getHP();

    /** decrease the player's force by 1 */
    void decreaseForce();

    /** increases the player's force by the amount received as argument */
   virtual Player& buff(const int addedForce);

    /** increases the player's hp by the amount received as argument */
   virtual Player& heal(const int addedHP);

    /** decreases the player's hp by the amount received as argument */
    virtual   Player& damage(const int damageInflicted);

    /** methods returns whether a player's hp is a 0 (returns true if hp is 0) */
    bool isKnockedOut() const;

    /** increases the player's amount of coins by the amount received as argument */
    virtual Player& addCoins(const int numOfCoins);

    /** decreases the player's amount of coins by the amount received as argument. If player doesn't have enough coins, nothing will happen
     * and function will return false. If succeeded, true will be returned.*/
    bool pay(const int price);
    friend std::ostream& operator<<(std::ostream& os,Player& player);


        protected:
    std::string m_name;   //Character's name
    int m_level;     //Player's level
    int m_force;     //Player's force
  //  int m_maxHP;     //Player's maximum HP allowed
    int m_HP;        //Player's current HP
    int m_coins;     //Player's amount of coins he currently holds

    /** defining default values for the class */
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_COINS = 10;
    static const int DEFAULT_ENTRY_LEVEL = 1;
};

#endif //HW2_PLAYER_H
