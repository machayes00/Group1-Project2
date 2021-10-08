#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <iostream>
#include <string>

class Player
{
private:

    Board hiddenBoard;    // this board is shown to opponent
    Board gameBoard;      // this board shows ships and hit locations
    Board original_Board; // this board stores all the ships and does not make any changes
    int shipsLeft;        // keeps tracks of number of ships remaining

public:

    /**
     * @brief Construct a new Player object
     * @param none
     * @pre none
     * @post new Player object is created
     */
    Player();

    /**
     * @brief Destroy the Player object
     * @pre none
     * @post Player object is deallocated from memory
     */
    ~Player();

    /**
     * @brief Checks for ship hits by checking if a B character exists at the row and col arguments 
     * @param row the row of the coordinate choosen for hit
     * @param col the column of the coordinate choosen for hit
     * @pre the column character must be a capital letter char, A - J; row is int 1-9
     * @return true if coordinates match a B character
     * @return false if coordinates do not match a B character
     */
    bool checkHit(int row, char col);

    /**
     * @brief Check for ships by checking if a B character exists at the row and col arguments
     * @param row the row of the coordinate choosen for hit
     * @param col the column of the coordinate choosen for hit
     * @pre this sane method expects you to pass in 2D array indices, 0-8 for row, 0-9 for col
     * @post none
     * @return true if coordinates match a B character
     * @return false if coordinates do not match a B character
     */
    bool checkHit2(int row, int col);

    /**
     * @brief Determines how many ships left for a player
     * @param none
     * @pre none
     * @post none
     * @return int the number of ships left
     */
    int checkShips();

    /**
     * @brief Replaces a hit B character with an X character
     * @pre hit coordinates must be obtained after calling checkHit method
     * @pre requires exchange method from Board class
     * @param row the row, which is an int 1-9
     * @param col the column, whch is a char, capital letter A - J
     * @ return none (a weird thing for a "get" function but it is not a getter)
     */
    void get_hit(int row, char col); //helper function checkHit()

    /**
     * @brief Prints the "hidden board" which hides the ships 'till hit
     * @pre none
     * @post board with ships hidden, and hits if any, is printed to screen
     * @param none
     * @return none
     */
    void getHiddenBoard();

    /**
     * @brief Prints the Board object that reveals ship locations and hits if present
     * @pre none
     * @post board with ships and hit locations is printed to screen
     * @param none
     * @return none
     */
    void getGameBoard();

    /**
     * @brief Calls printAnimate Board method on hiddenBoard Board object to animate hits
     * @pre Must be called within game_start method, after it calls checkHit method
     * @post printAnimate sub-method prints animation to screen when a ship is hit
     * @param row the row index in 2D array (int 0 - 8)
     * @param col the column index in 2d array (int 0 - 9)
     */
    void doAnimation(int row, int col);

    /**
     * @brief Probably delete method. Original explanation for this method: "print the Game board
     *       object. Mainly used for calling methods of the board class."
     * @param none
     * @return none
     */
    void getOriginalBoard();

    /**
   * @brief Interacts with user to place ships on gameBoard and original_Board objects
   * @param row the rown number for first coordinate of a ship placement (int 1-9)
   * @param col the col letter for first coordinate of a ship (char capital A-J)
   * @param size the size of the ship (number of coordinates that need to be marked)
   * @param dir the direction of the ship (Down or Right, char must be D, d, R, or r)
   * @return true if ship could be placed
   * @return false if ship could not be placed
   */
    bool placeShip(int row, char col, int size, char dir);
    
};

#endif
