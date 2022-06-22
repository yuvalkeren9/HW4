
#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H


#include <iostream>

/** a class that represents a player type. The class hold the player's name, his current level, current force, his max HP, current player's HP, and
 * the amount of coins he has */
class Player {

public:

    /** basic constructors for the Player type. Notice the build constructor is not default, and has default values if not attributed by user.
    * Also, a player will always be initialized with a level 1 and 0 coins.*/
    /** ---Player constructor---/
    *
    * @param name - name of the player
    * @param force - starting force
    */
    explicit Player(const std::string& name,const int force = DEFAULT_FORCE);

    /** copy constructor**/
    Player(const Player& player) = default;

    /** destructor**/
    virtual  ~Player() = default;

    /** assigment operator**/
    Player& operator=(const Player&) = default;

    /** function that prints the Player's info */
    virtual void printInfo(std::ostream &os) const=0;

    /**
    * increases the level of the player by 1
    */
    Player& levelUp();



    /** decrease the player's force by 1 */
    void decreaseForce();

    /**
    * increases the player force by given number
    * @param addedForce - amount of force to increase
    */
   virtual Player& buff(const int addedForce);


    /**
    * increases the player HP by given number
    * @param addedHP -amount of HP to increase
    */
   virtual Player& heal(const int addedHP);


    /**
    * decreases the player HP by given number
    * @param damageInflicted --amount of HP to decrease
    */
    virtual   Player& damage(const int damageInflicted);


    /**
    * checks if the players is out of game
    * @return true if player out of HP , otherwise false
    */
    bool isKnockedOut() const;


    /**
    * increases the player coins by given number
    * @param numOfCoins - amount of coins to increase
    */
    virtual Player& addCoins(const int numOfCoins);


    /**
    * decreases the player coins by given number - if possible
    * @param price -amount of coins to decrease
    * @return true if decrease done, otherwise false
    */
    bool pay(const int price);

    /** getter functions */
    int getLevel() const;
    virtual int getAttackStrength() const;
    std::string getName() const;
    int getCoins() const;
    int getHP() const;

    /**
 * /-----  operator <<  -------/
 * the function prints the player info (by asked format) to out stream that given
 * @param os - out stream given
 * @param player - player to print
 * @return os - out stream that given (for pipelining)
 */
    friend std::ostream& operator<<(std::ostream& os, const Player& player);


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
