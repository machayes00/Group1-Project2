#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include "Player.h"
using namespace std; 

/**
 * Executive Class for Battleship game. 
 * The top-level class that interacts with players and calls Player class methods.
 */
class Executive
{

private:

    /**
     * A private variable 
     * Player object for player 1
     * Stores Board objects and 
     * variable for keeping track of ships left
     */
    Player player1;

    /**
     * A private variable
     * Player object for player 2
     * Stores Board objects and
     * variable for keeping track of ships left
     */
    Player player2;

    /**
     * A private variable
     * Stores the number of ships for a game.
     */
    int ships;

public:

    /**
     * @brief Construct a new Executive object
     * @pre none
     * @return none
     * @post a new Executive class object is created
     */
    Executive();

    /**
     * @brief Destroy the Executive object
     * @pre none
     * @param none
     * @post an executive class object is deallocated from memory
     */
    ~Executive();

    /**
     * @brief Sets up the game and calls the other methods in the program and coordinates their actions
     * @pre none
     * @param none
     * @return none
     */
    void run();

    /**
     * @brief Places a ship with the passed-in size on the passed-in player's gameBoard.
     * @param size the size of the ship being placed
     * @param new_player Player object passed in by reference
     * @return none
     */
    void place_ship(int size, Player& new_player);

    /**
     * @brief AI randomly places ships on gameBoard.
     * @param size the size of the ship being placed
     * @param new_player Player object passed in by reference
     * @return none
     */
    void aiplace(int size, Player& new_player);

    /**
     * @brief Manages player turn-taking and checks for winner
     * @param player1 Player object
     * @param player2 Player object
     * @param size The number of ships, 1-6
     * @return none
     */
    void game_start(Player& player1, Player& player2, int size, string aitrigger, int difficulty);

    /**
     * @brief prints title with alternating colors
     * @pre none
     * @return none
     * @post none
     */
    void introtitleanimation();

    /**
     * @brief prints player 1 win with alternating colors
     * @pre none
     * @return none
     * @post none
     */
    void endscreenanimation1();

    /**
     * @brief prints title with alternating colors
     * @pre none
     * @return none
     * @post none
     */
    void endscreenanimation2();
};

#endif
