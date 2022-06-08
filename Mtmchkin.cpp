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
    while(m_CardDeck.size() != 0){
        m_CardDeck.front()->printInfo();
        m_CardDeck.pop();
    }
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