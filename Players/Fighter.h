//
// Created by eladm on 07/06/2022.
//

#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H
#include "Player.h"
#include "../utilities.h"

class Fighter: public Player{

public:

    /** basic constructors for the Player Fighter type. Notice the build constructor is not default, and has default values if not attributed by user.
    * Also, a Fighter will always be initialized with a level 1 and 0 coins.*/
    explicit Fighter(const std::string& name,const int force = DEFAULT_FORCE);

    /** copy constructor**/
    Fighter(const Fighter& fighter) = default;

    /** assigment operator**/
    Fighter& operator=(const Fighter&) = default;

    /** destructor  **/
    ~Fighter() override =default;


    /**
 * @return the attackstrength of the fighter (calculated different from other player types)
 */
    int getAttackStrength() const override;


    /**
 * the function prints the Fighter info (by asked format) to out stream that given
 * @param os - out stream given
 * @return os - out stream that given (for pipelining)
 */
    void printInfo(std::ostream &os) const override;
};

#endif //HW4_FIGHTER_H
