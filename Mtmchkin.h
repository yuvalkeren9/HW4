#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include <memory>
#include <queue>
#include "Cards/Card.h"





class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
private:
    static bool checkCardType(const std::string& card);
    static std::shared_ptr<Card> getPointerToNewCard(const std::string& cardName);
    std::queue<std::shared_ptr<Card>> m_CardDeck;
    std::queue<std::unique_ptr<Player>> m_PlayersQueue;
    static int getNumberOfPlayers();
    static std::queue<std::unique_ptr<Player>> createPlayersQueue(int numberOfPlayers);
    static bool checkPlayerName(const std::string& playerName);
    static bool checkPlayerType(const std::string& playerType);
    static void pushingPlayerToQueue(std::queue<std::unique_ptr<Player>> &Players, const std::string &playerType, const std::string &playerName); //add bad alloc
    static const int meow = 5;

};



#endif /* MTMCHKIN_H_ */
