//
// Created by יובל קרן on 08/06/2022.
//

#include "Mtmchkin.h"
#include <fstream>
#include <string>
#include <iostream>
#include "Exception.h"
#include "Cards/Goblin.h"
#include "Cards/Vampire.h"
#include "Cards/Dragon.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Barfight.h"
#include "Cards/Pitfall.h"
#include "Cards/Fairy.h"




using std::cout;
using std::ifstream;
using std::endl;
using std::string;
using std::getline;
using std::shared_ptr;
using std::cin;
using std::unique_ptr;
using namespace std;


Mtmchkin::Mtmchkin(const std::string fileName) {
    ifstream source(fileName);
    if(!source){
        throw DeckFileNotFound();
    }
    int currentLine =1;
    string cardName;
    while (getline(source, cardName)){
        //getline(source, cardName);
        if (!checkCardType(cardName)){
            string error = std::to_string(currentLine);
            throw DeckFileFormatError(error);
        }
        shared_ptr<Card> tempPtr= getPointerToNewCard(cardName);
        this->m_CardDeck.push(tempPtr);
        ++currentLine;
    }
    if( m_CardDeck.size() < 5){
        throw DeckFileInvalidSize();
    }
    /** Now we initialise the player */
    printStartGameMessage();
    int numOfPlayers = getNumberOfPlayers();
    try {
        m_PlayersQueue = createPlayersQueue(numOfPlayers);
    }
    catch (bad_alloc& e){}; //do something
}


bool Mtmchkin::checkCardType(const std::string& card){
    string availableCardTypes[] = {"Goblin", "Vampire", "Dragon", "Pitfall", "Fairy", "Barfight", "Merchant", "Treasure"};
    for (int i=0; i < 8; ++i){
        if (card == availableCardTypes[i]){
            return true;
        }
    }
    return false;
}

shared_ptr<Card> Mtmchkin::getPointerToNewCard(const string& cardName){
    if (cardName == "Goblin"){
        return shared_ptr<Card>(new Goblin());
    }
    else if( cardName == "Vampire"){
        return shared_ptr<Card>(new Vampire());
    }
    else if( cardName == "Dragon"){
        return shared_ptr<Card>(new Dragon());
    }
    else if( cardName == "Barfight"){
        return shared_ptr<Card>(new Barfight());
    }
    else if( cardName == "Fairy"){
        return shared_ptr<Card>(new Fairy());
    }
    else if( cardName == "Pitfall"){
        return shared_ptr<Card>(new Pitfall());
    }
    else if( cardName == "Merchant"){
        return shared_ptr<Card>(new Merchant());
    }
    else{
        return shared_ptr<Card>(new Treasure());
    }
}



/** Player initializing functions */

int Mtmchkin::getNumberOfPlayers(){
    printEnterTeamSizeMessage();
    int numOfPlayers;
    cin >> numOfPlayers;
    while (cin.fail() || (numOfPlayers < 2) || (numOfPlayers > 6)){
        printInvalidTeamSize();
        cin.clear();
        cin.ignore(256, '\n');             //CHANGE IT SO 2a DOESNT WORK
        printEnterTeamSizeMessage();
        cin >> numOfPlayers;
    }
    cin.ignore();
    return numOfPlayers;
}


queue<unique_ptr<Player>> Mtmchkin::createPlayersQueue(int numberOfPlayers){
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
        try{
            pushingPlayerToQueue(temp, playerType, playerName);
        }
        catch (std::bad_alloc &e){};    //dont forget to do something
//        if (playerType == "Wizard"){
//            //unique_ptr<Player> tempWizard(new Wizard(playerName));
//            temp.push(unique_ptr<Player> (new Wizard(playerName)));
//        }
//        else if (playerType == "Fighter"){
//            //unique_ptr<Player> tempFighter(new Fighter(playerName));
//            temp.push(unique_ptr<Player> (new Fighter(playerName)));
//        }
//        else {
//            //unique_ptr<Player> tempRogue(new Rouge(playerName));
//            temp.push(unique_ptr<Player> (new Rouge(playerName)));
//        }
        counter++;
    }
    return temp;
}



bool Mtmchkin::checkPlayerName(const string& playerName){
    const string allLettersInABC = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (playerName.length() > 15 ){
        return false;
    }
    if (playerName.find_first_not_of(allLettersInABC) != string::npos){
        return false;
    }
    return true;
}

bool Mtmchkin::checkPlayerType(const string& playerType){
    if (playerType != "Rogue" && playerType != "Wizard" && playerType != "Fighter"){
        return false;
    }
    return true;
}


void Mtmchkin::pushingPlayerToQueue(queue<unique_ptr<Player>> &Players, const string &playerType, const string &playerName){
    if (playerType == "Wizard"){
        Players.push(unique_ptr<Player> (new Wizard(playerName)));
    }
    else if (playerType == "Fighter"){
        Players.push(unique_ptr<Player> (new Fighter(playerName)));
    }
    else {
        Players.push(unique_ptr<Player> (new Rouge(playerName)));
    }

}


