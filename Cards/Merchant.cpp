//
// Created by יובל קרן on 07/06/2022.
//

#include "Merchant.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;





void Merchant::applyEncounter(Player& player) const{
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName(), player.getCoins());
    const string allNums = "0123456789";
    bool wasCorrectInputScannedFlag = false;
    string playerDecisionInput;
    while (!wasCorrectInputScannedFlag){
        std::getline(cin, playerDecisionInput);
        if (playerDecisionInput.find_first_not_of(allNums) != string::npos){
            printInvalidInput();
            continue;
        }
        int playerDecisionTemp = stoi(playerDecisionInput);
        if (playerDecisionTemp < 0 || playerDecisionTemp > 2){
            printInvalidInput();
            continue;
        }
        wasCorrectInputScannedFlag = true;
    }
    int playerDecision = stoi(playerDecisionInput);
    switch (playerDecision){
        case 0 : {
            printMerchantSummary(cout, player.getName(), 0, 0);
            break;
        }
        case 1 : {
            if (player.getCoins() < priceOfHealthPotion){
                printMerchantInsufficientCoins(cout);
                printMerchantSummary(cout, player.getName(), 1, 0);
                break;
            }
            else {
                player.pay(priceOfHealthPotion);
                player.heal(1);
            }
            printMerchantSummary(cout, player.getName(), 1, priceOfHealthPotion);
            break;
        }
        case 2 : {
            if (player.getCoins() < priceOfBuffBoost){
                printMerchantInsufficientCoins(cout);
                printMerchantSummary(cout, player.getName(), 2, 0);
                break;
            }
            else {
                player.pay(priceOfBuffBoost);
                player.buff(1);
            }
            printMerchantSummary(cout, player.getName(), 2, priceOfBuffBoost);
            break;
        }
        default :
            break;
    }

}


void Merchant::printInfo() const{
    printCardDetails( cout, "Merchant");
    printEndOfCardDetails(cout);
}