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

using std::cin;
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using namespace std;

static const string allLettersInABC = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getNumberOfPlayers();
queue<shared_ptr<Player>> createPlayersQueue(int numberOfPlayers);
bool checkPlayerName(const string& playerName);
bool checkPlayerType(const string& playerType);



int main(){
    printStartGameMessage();
    int numOfPlayers = getNumberOfPlayers();
    queue<shared_ptr<Player>> playersQueue = createPlayersQueue(numOfPlayers);
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

queue<shared_ptr<Player>> createPlayersQueue(int numberOfPlayers){
    int counter = 0;
    queue<shared_ptr<Player>> temp;
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
            shared_ptr<Player> tempWizard(new Wizard(playerName));
            temp.push(tempWizard);
        }
        else if (playerType == "Fighter"){
            shared_ptr<Player> tempFighter(new Fighter(playerName));
            temp.push(tempFighter);
        }
        else {
            shared_ptr<Player> tempRogue(new Rouge(playerName));
            temp.push(tempRogue);
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