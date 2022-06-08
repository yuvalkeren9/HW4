//
// Created by יובל קרן on 08/06/2022.
//

#include "utilities.h"
#include <cstring>
#include "Players/Player.h"
#include <queue>
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Players/Rouge.h"
#include <memory>
#include "Exception.h"
#include "Mtmchkin.h"

using std::cin;
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using namespace std;

static const string allLettersInABC = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getNumberOfPlayers();
queue<unique_ptr<Player>> createPlayersQueue(int numberOfPlayers);
bool checkPlayerName(const string& playerName);
bool checkPlayerType(const string& playerType);



int main(){
    Mtmchkin game("deck.txt");
    printStartGameMessage();
    int numOfPlayers = getNumberOfPlayers();
    queue<unique_ptr<Player>> playersQueue = createPlayersQueue(numOfPlayers);
    playersQueue.front()->printInfo(cout);
    playersQueue.pop();
    cout << endl;
    playersQueue.front()->printInfo(cout);
    return 0;

}

int getNumberOfPlayers(){
    printEnterTeamSizeMessage();
    int numOfPlayers;
    cin >> numOfPlayers;
    while (cin.fail() || (numOfPlayers < 2) || (numOfPlayers > 6)){
        printInvalidTeamSize();
        cin.clear();
        cin.ignore(256, '\n');
        printEnterTeamSizeMessage();
        cin >> numOfPlayers;
    }
    cin.ignore();
    return numOfPlayers;
}

queue<unique_ptr<Player>> createPlayersQueue(int numberOfPlayers){
    int counter = 0;
    queue<unique_ptr<Player>> temp;
    while (counter != numberOfPlayers){
        printInsertPlayerMessage();
        string playerName;
        getline(cin, playerName, ' ');
        string playerType;
        getline(cin, playerType);
        if (!checkPlayerName(playerName)){
            printInvalidName();
            continue;
        }
        if(!checkPlayerType(playerType)){
            printInvalidClass();
            continue;
        }
        if (playerType == "Wizard"){
            //unique_ptr<Player> tempWizard(new Wizard(playerName));
            temp.push(unique_ptr<Player> (new Wizard(playerName)));
        }
        else if (playerType == "Fighter"){
            //unique_ptr<Player> tempFighter(new Fighter(playerName));
            temp.push(unique_ptr<Player> (new Fighter(playerName)));
        }
        else {
            //unique_ptr<Player> tempRogue(new Rouge(playerName));
            temp.push(unique_ptr<Player> (new Rouge(playerName)));
        }
        counter++;
    }
    return temp;
}

bool checkPlayerName(const string& playerName){
    if (playerName.length() > 15 ){
        return false;
    }
    if (playerName.find_first_not_of(allLettersInABC) != string::npos){
        return false;
    }
    return true;
}

bool checkPlayerType(const string& playerType){
    if (playerType != "Rogue" && playerType != "Wizard" && playerType != "Fighter"){
        return false;
    }
    return true;
}