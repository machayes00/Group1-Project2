#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include "Player.h"

class Executive
{
private:
    Player player1;
    Player player2;
    int player1ships;
    int player2ships;
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
     * return none
     */
    void game_start(Player& player1, Player& player2, int size);
};

#endif
