#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include <memory>
#include <queue>
#include <stack>
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

    int m_CurrentRoundNum;
    int m_numOfPlayers;
    std::queue<std::shared_ptr<Card>> m_CardDeck;
    std::vector<std::shared_ptr<Player>> m_PlayersVector;
    std::vector<std::shared_ptr<Player>> m_stillInGame;
    std::deque<std::shared_ptr<Player>> m_Winners;
    std::deque<std::shared_ptr<Player>> m_Losers;


    /**
     * Checks if card type inserted is valid
     * @param card - card to check
     * @return true if valid, false otherwise
     */
    static bool checkCardType(const std::string& card);

    /**
     * create a new instance of the card type sent and return a shared ptr to the object
     * @param cardName - card type to create
     * @return a shared pointer to the object allocated
     */
    static std::shared_ptr<Card> getPointerToNewCard(const std::string& cardName);

    /**
     * the function updating the leaderboard (remove/add from/to winners/losers the player) according the flag (isWinner)
     * @param isWinner - flag of how the updating need to be done
     * @param playerIt - an iterator points on the specific object to remove/add from/to winners/losers
     * @param index - index of the player in container
     */
    void updateLeaderboard(bool isWinner, std::vector<std::shared_ptr<Player>>::iterator& playerIt, int index);

    /**
     * this function create a new GANG abject according to the source file sent
     * @param source - the source file
     * @param currentLine - the current line read in the source file
     * @return a pointer to the object allocated
     */
    static std::shared_ptr<Card> getPointerToNewGang(std::ifstream& source, int& currentLine );

    /**
     * the function receive int from std input channel and checks for validity
     * @return a copy of valid integer (2-6) received from user
     */
    static int getNumberOfPlayers();


    /**
     * this function create a new vector containing shared pointers to player types
     * according to users input, and check for validity
     * @param numberOfPlayers - number of players
     * @return shared ptr of players vector allocated
     */
    static std::vector<std::shared_ptr<Player>> createPlayersVector(int numberOfPlayers);

    /**
     * checking for validity of string (length and signs)
     * @param playerName - the string to check
     * @return true if valid,false otherwise.
     */
    static bool checkPlayerName(const std::string& playerName);

    /**
     * checking for validity of string
     * @param playerType - the string to check
     * @return true if valid,false otherwise.
     */
    static bool checkPlayerType(const std::string& playerType);

    /**
     * the function create a new player as type received , with the name received and pushing a shared ptr to the object  into the vector
     * @param Players - container to push into
     * @param playerType - player type creating an object according to
     * @param playerName - name of the player to create
     */
    static void pushingPlayerToVector(std::vector<std::shared_ptr<Player>> &Players, const std::string &playerType, const std::string &playerName); //add bad alloc

};



#endif /* MTMCHKIN_H_ */
