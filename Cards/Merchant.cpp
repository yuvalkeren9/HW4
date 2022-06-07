//
// Created by יובל קרן on 07/06/2022.
//

#include "Merchant.h"
#include "utilities.h"
#include "Player.h"

using std::cin;




void Merchant::applyEncounter(Player& player) const{
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName, player.getCoins);
    int playerDecision;
    cin >> playerDecision;
    //check if correct input was entered, and ask for correct one until it is solved
    switch (playerDecision){
        case 0 : {
            printMerchantSummary(cout, player.getName, 0, 0);
            break;
        }
        case 1 : {
            if (player.getCoins < priceOfHealthPotion){
                printMerchantInsufficientCoins(cout);
            }
            else {
                player.pay(priceOfHealthPotion);
                player.heal(1);
            }
            printMerchantSummary(cout, player.getName, 1, priceOfHealthPotion);
            break;
        }
        case 2 : {
            if (player.getCoins < priceOfBuffBoost){
                printMerchantInsufficientCoins(cout);
            }
            else {
                player.pay(priceOfBuffBoost);
                player.buff(1);
            }
            printMerchantSummary(cout, player.getName, 2, priceOfBuffBoost);
            break;
        }
        default :
            break;
    }

}


void Merchant::printInfo() const{
    printCardDetails( cout, "Treasure");
    printEndOfCardDetails(cout);
}