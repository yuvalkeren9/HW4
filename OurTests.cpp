//
// Created by יובל קרן on 07/06/2022.
//

#include "Cards/Card.h"
#include "Players/Player.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Vampire.h"
#include "Cards/Treasure.h"
#include "Cards/BattleCard.h"
#include "Mtmchkin.h"
using std::cout;
using std::endl;
using std::string;
#include <cassert>




int main() {
//    Wizard yuval("Yuval");
//    cout << "Goblin Test"  << endl;
//    Goblin goblin1;
//    assert(goblin1.getStats(0) == 6);
//    assert(goblin1.getStats(1) == 10);
//    assert(goblin1.getStats(2) == 2);
//    Goblin goblin2 = goblin1;
//    goblin2.printInfo();
//    cout << "Testing combat of Goblin" << endl;
//




    Mtmchkin game("deckj.txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < 100) {
        game.playRound();
    }
    game.printLeaderBoard();
//    Dragon dragon;
//    Goblin goblin;
//    Vampire vampire;
//    Fairy fairy;
//    Barfight barfight;
//    Pitfall pitfall;
//    Treasure treasure;
//    Merchant merchant;
//    Rogue ganav("Cenzor", 3);
//    Wizard harry("HarryPotter", 2);
//    Fighter habib("Habib", 500);
//    cout << ganav << endl;
//    cout << harry << endl;
//    cout << habib << endl << endl;

   // treasure.applyEncounter(ganav);
//    treasure.applyEncounter(habib);
//    vampire.applyEncounter(ganav);
//    cout << ganav << endl;
//    cout << ganav << endl;
//    goblin.applyEncounter(harry);
//    goblin.applyEncounter(harry);
//    goblin.applyEncounter(harry);
//    cout << treasure << endl;
//    cout << merchant << endl;
//    merchant.applyEncounter(habib);
//    cout << habib << endl << endl;
    return 0;
}

