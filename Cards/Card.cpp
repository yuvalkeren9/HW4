
#include "Card.h"
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

Card::Card(const CardStats& stats) :
    m_stats(stats){
}

ostream& operator<<(ostream& os, const Card& card){
    card.printInfo();
    return os;
}



