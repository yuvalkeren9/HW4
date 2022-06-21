//
// Created by יובל קרן on 08/06/2022.
//

#include "utilities.h"
/*
#include <cstring>
#include "Players/Player.h"
#include <queue>
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
#include "Exception.h" */
#include <memory>

#include "Mtmchkin.h"

using std::cin;
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;


int main(){
    try {
        Mtmchkin game("deck.txt");
        while(!game.isGameOver() && game.getNumberOfRounds() < 100){
           game.playRound();
           game.printLeaderBoard();
       }
    }
    catch (Exception& e){
        cout << e.what();
    }
    catch (std::bad_alloc& e){
        cout << e.what();
    }
    return 0;

}


