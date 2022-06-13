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
#include "utilities.h"




using std::cout;
using std::ifstream;
using std::endl;
using std::string;
using std::getline;
using std::shared_ptr;
using std::cin;
using std::shared_ptr;
using namespace std;
using std::vector;
using std::deque;

/** Mtmchkin Methods */

/** Mtmchkin Constructor */
Mtmchkin::Mtmchkin(const std::string fileName) : m_CurrentRoundNum(0) {
    printStartGameMessage();
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
    m_numOfPlayers = getNumberOfPlayers();
    try {
        m_PlayersVector = createPlayersVector(m_numOfPlayers);
    }
    catch (bad_alloc& e){}; //do something

    /** Now we initilize the leaderboard */
     m_stillInGame = m_PlayersVector;
}


void Mtmchkin::playRound(){
    printRoundStartMessage(m_CurrentRoundNum + 1);
    int currentPlayerIndex = 0;
    for (vector<shared_ptr<Player>>::iterator it = m_PlayersVector.begin(); it != m_PlayersVector.end(); ){
            printTurnStartMessage((**it).getName());
            m_CardDeck.front()->applyEncounter(**it);
            shared_ptr<Card> temp = m_CardDeck.front();   //maybe do as function (maybe)
            m_CardDeck.push(temp);
            m_CardDeck.pop();
        if ((**it).isKnockedOut()){
            updateLeaderboard(false, it, currentPlayerIndex);
            m_PlayersVector.erase(it);         //LEADERBOARD UPDATE
            continue;
        }
        if ((**it).getLevel() == 10){
            updateLeaderboard(true, it, currentPlayerIndex);
            m_PlayersVector.erase(it);    //LEADERBOARD UPDATE
            continue;
        }
        ++it;
        ++currentPlayerIndex;
    }
    ++m_CurrentRoundNum;
    if(this->isGameOver()){
        printGameEndMessage();
    }
}

int Mtmchkin::getNumberOfRounds() const {
    return this->m_CurrentRoundNum;
}

bool Mtmchkin::isGameOver() const {
    return (m_PlayersVector.empty());
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int counter = 1;
    for (const shared_ptr<Player>& data : m_Winners){
        printPlayerLeaderBoard(counter, *data);
        ++counter;
    }
    for (const shared_ptr<Player>& data : m_stillInGame){
        printPlayerLeaderBoard(counter, *data);
        ++counter;
    }
    for (const shared_ptr<Player>& data : m_Losers){
        printPlayerLeaderBoard(counter, *data);
        ++counter;
    }
}





/** Card Initilzing Functions */

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
    const string allNums = "0123456789";
    bool wasCorrectInputScannedFlag = false;
    string playerDecisionInput;
    while (!wasCorrectInputScannedFlag){
        std::getline(cin, playerDecisionInput);
        if (playerDecisionInput.find_first_not_of(allNums) != string::npos){
            printInvalidTeamSize();
            continue;
        }
        int numOfPlayersTemp = stoi(playerDecisionInput);
        if (numOfPlayersTemp < 2 || numOfPlayersTemp > 6){
            printInvalidTeamSize();
            continue;
        }
        wasCorrectInputScannedFlag = true;
    }
    int numOfPlayers = stoi(playerDecisionInput);
    return numOfPlayers;
}


vector<shared_ptr<Player>> Mtmchkin::createPlayersVector(int numberOfPlayers){
    vector<shared_ptr<Player>> temp;
    for (int i=0; i < numberOfPlayers; ++i) {
        bool flag = false;
        printInsertPlayerMessage();
        while (flag == false) {
            string playerName;
            cin >> playerName;
            string playerType;
            cin >> playerType;
            if (!checkPlayerName(playerName)) {
                printInvalidName();
                continue;
            }
            if (!checkPlayerType(playerType)) {
                printInvalidClass();
                continue;
            }
            try {
                pushingPlayerToVector(temp, playerType, playerName);
            }
            catch (std::bad_alloc &e) {};    //dont forget to do something
            flag = true;
            cin.ignore();
        }
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


void Mtmchkin::pushingPlayerToVector(vector<shared_ptr<Player>> &Players, const string &playerType, const string &playerName){
    if (playerType == "Wizard"){
        Players.push_back(shared_ptr<Player> (new Wizard(playerName)));
    }
    else if (playerType == "Fighter"){
        Players.push_back(shared_ptr<Player> (new Fighter(playerName)));
    }
    else {
        Players.push_back(shared_ptr<Player> (new Rogue(playerName)));
    }

}


/** Helper functions */
//
//void Mtmchkin::updateLeaderboard(bool isWinner, shared_ptr<Player>& playerPtr, int index){          //if we have time, make this an enum
//    vector<shared_ptr<Player>> temp;
//    shared_ptr<Player> tempPtr = playerPtr;
//    if(isWinner){
//        vector<shared_ptr<Player>>::iterator it = m_Leaderboard.begin();
//        for (int i= 0; i < m_leftIndex ; ++i, ++it) {
//            temp.push_back(*it);
//        }
//        temp.push_back(tempPtr);
//        while ()
//        m_Leaderboard.erase(it);
//        ++m_leftIndex;
//        for (int i = m_leftIndex; i < m_Leaderboard.size(); ++i, ++it)
//    }
//
//}


void Mtmchkin::updateLeaderboard(bool isWinner, vector<shared_ptr<Player>>::iterator& playerIt, int index){
    shared_ptr<Player> tempPtr = *playerIt;
    if(isWinner){
        m_Winners.push_back(tempPtr);
    }
    else {
        m_Losers.push_front(tempPtr);
    }
    vector<shared_ptr<Player>>::iterator it = m_stillInGame.begin();
    for(int i=0; i < index; ++i ){
        ++it;
    }
    m_stillInGame.erase(it);
}