#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <iostream>
#include <string>

/**
 * Player Class for Battleship game
 * Creates Player objects and controls Player boards with help of Board class methods
 */
class Player
{
private:

    /**
     * A private variable 
     * Board object that is whown to opponent; hides ships until they are hit
     */
    Board hiddenBoard;    // this board is shown to opponent

    /**
     * A private variable
     * Board object that shows all ships and hit locations
     */
    Board gameBoard;     

    /**
     * A private variable
     * Board object that stores all the ships and is not changes after ships are placed
     */
    Board original_Board; // this board stores all the ships and does not make any changes

    /**
     * A private variable
     * keeps track of the number of ships remaining unsunk on a board
     */
    int shipsLeft;       

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
     * @brief Checks for ship hits by checking if a 'B' character exists at the row and col arguments
     *          Used to make sure ships do not overlap during placement on board. 
     * @param row the row of the coordinate choosen for hit
     * @param col the column of the coordinate choosen for hit
     * @pre the column character must be a capital letter char, A - J; row is int 1-9
     * @return true if coordinates match a B character
     * @return false if coordinates do not match a B character
     */
    bool checkHit(int row, char col);

    /**
     * @brief Check for ships by checking if a 'B' character exists at the row and col arguments.
     *          Used by AI which deals with array indices rather that 1-9, A-J coordinates.
     * @param row the row index of the coordinate choosen for hit
     * @param col the column index of the coordinate choosen for hit
     * @pre expects arguments that are 2D array indices, 0-8 for row, 0-9 for col
     * @post none
     * @return true if coordinates match a 'B' character
     * @return false if coordinates do not match a 'B' character
     */
    bool checkHit2(int row, int col);

    /**
     * @brief Check if there is a hit 'X' character at the specified index, for Medium AI game
     * @param row index, 0-8
     * @param col inex, 0-9
     * @return true if there is an 'X' and the index
     * @return false if there is not an 'X' at the index
     */
    bool checkHit3(int row, int col);

    /**
     * @brief Determines how many ship coordinates are left for a player
     * @param none
     * @pre none
     * @post none
     * @return int the number of ships left
     */
    int checkShips();

    /**
     * @brief Replaces a hit B character with an X character. It is a helper function checkHit()
     * @pre hit coordinates must be obtained after calling checkHit method
     * @pre requires exchange method from Board class
     * @param row the row, which is an int 1-9
     * @param col the column, whch is a char, capital letter A - J
     * @return none (a weird thing for a "get" function but it is not a getter)
     */
    void get_hit(int row, char col); 

    /**
     * @brief Prints the "hidden board" which hides the ships 'till hit
     * @pre none
     * @post board with ships hidden, and hits if any, is printed to screen
     * @param none
     * @return none
     */
    void getHiddenBoard();

    /**
     * @brief Prints the Board object that reveals all ship locations and hits if present
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
     * @param col the column index in 2D array (int 0 - 9)
     * @param hit 
     */
    void doAnimation(int row, char col, bool hit);

    /**
     * @brief Print the Game board object. Mainly used for calling methods of the board class
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
