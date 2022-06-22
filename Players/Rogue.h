//
// Created by eladm on 07/06/2022.
//

#ifndef HW4_ROUGE_H
#define HW4_ROUGE_H
#include "Player.h"
#include "../utilities.h"
#include <cstring>

class Rogue: public Player{

public:


    /** basic constructors for the Player Rogue type. Notice the build constructor is not default, and has default values if not attributed by user.
    * Also, a Rogue will always be initialized with a level 1 and 0 coins.*/
    explicit Rogue(const std::string& name,const int force = DEFAULT_FORCE);

    /** copy constructor**/
    Rogue(const Rogue& rogue) = default;

    /** assigment operator**/
    Rogue& operator=(const Rogue&) = default;


    /** destructor  **/
    ~Rogue() override =default;

    /**
    * increases the Rogue coins by *twice* the given number (calculated different from other player types)
    * @param numOfCoins - amount of coins to increase ( before doubling)
    */
    Rogue& addCoins(const int numOfCoins) override;

    /**
    * the function prints the Rogue info (by asked format) to out stream that given
    * @param os - out stream given
    * @return os - out stream that given (for pipelining)
    */
    void printInfo(std::ostream &os) const override;
};


#endif //HW4_ROUGE_H
