//
// Created by eladm on 07/06/2022.
//

#ifndef HW4_WIZARD_H
#define HW4_WIZARD_H
#include "Player.h"
#include "../utilities.h"

class Wizard: public Player{

public:

    /** basic constructors for the Player Wizard type. Notice the build constructor is not default, and has default values if not attributed by user.
   * Also, a Wizard will always be initialized with a level 1 and 0 coins.*/
    explicit Wizard(const std::string& name,const int force = DEFAULT_FORCE);

    /** copy constructor**/
    Wizard(const Wizard& wizard) = default;

    /** assigment operator**/
    Wizard& operator=(const Wizard&) = default;


    /** destructor  **/
    ~Wizard() override =default;

    /**
     * increases the Wizard HP by *twice* the given number (calculated different from other player types)
     * @param addedHP -amount of HP to increase( before doubling)
     */
    Wizard& heal(const int addedHP) override;

    /** printing function  **/
    /**
    * the function prints the Wizard info (by asked format) to out stream that given
    * @param os - out stream given
    * @return os - out stream that given (for pipelining)
    */
    void printInfo(std::ostream &os) const override;
};



#endif //HW4_WIZARD_H
