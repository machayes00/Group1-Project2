#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <exception>
#include <unistd.h>

class Board
{
private:

    char** m_map = nullptr; // pointer to 2D array that stores game board characters
    int m_length = 0;  // variable for printAnimate and printAnimateHelp methods

public:

    /**
     * @brief Construct a new Board object
     * @pre none
     * @post a new Board object is created: initializes the m_map member with
     *      a 9x10 array filled with '~' characters representing water waves
     */
    Board();

    /**
     * @brief Construct a new Board object with arguments E: I THINK THIS IS NOT USED
     * @pre none
     * @param hidden_letter character that replaces '~" character in Board object m_map array
     */
    Board(char hidden_letter);
    // The original explanation for this constructor:
    //@process - this function works for hidden_board, which exchange all the '~' into 'hidden_letter'

    /**
     * @brief Destroy the Board object
     * @pre none
     * @post m_map 2D array is deleted and Board object is deallocated from memory
     */
    ~Board();

    /**
     * @brief Calls printAnimateHelp method and passes arguments to it, to create an animation effect
     * @pre Must be called by the doAnimation Player class method
     * @post Arguments are created and passed to printAnimateHelp method, which can now be executed
     * @param row the row index in 2D array (int 0 - 8)
     * @param col the column index in 2D array (int 0 - 9)
     */
    void printAnimate(int row, int col);

    /**
     * @brief Prints hiddenBoard with animation if there is a hit
     * @param length controlled and passed in from printAnimate method
     * @param row the row index in 2D array (int 0 - 8)
     * @param col the column index in 2D array (int 0 - 9)
     * @pre requires printAnimate to pass in arguments
     * @post Animated game board is printed to the screen when there is a hit
     *       (places X's based on what row+length and col+length is)
     */
    void printAnimateHelp(int length, int row, int col);

    /**
     * @brief Prints the calling Board object's m_map 2D array with names for columns and rows
     * @pre none
     * @post Game board for calling Board object is printed to screen
     */
    void print();

    /**
     * @brief Exchanges characters at specified coordinates of the m_map 2D array of a Board object
     * @param row_num the row number, 1-9, of the row of the character to be exchanged
     * @param column_letter  the column letter, 'A' - 'J', of the character to be exchanged
     * @param new_letter the character that will replace the current char at the specified index
     * @pre the coordinates that are passed in must be in the range specifed for the param
     * @post the '~' character of m_map 2D array is exchanged for a new character, if conditions are met
     * @return true if the method succeeds
     * @return false if the method fails
     */
    bool exchange(int row_num, char column_letter, char new_letter);

    /**
     * @brief Places vertical ships on the game board if input arguments are acceptable
     * @param row_num the row number, 1-9, of the ship's first coordinate
     * @param column_letter the column letter, 'A' - 'J', of the ship's first coordinate
     * @param size the size of the ship
     * @param new_letter the character that the '~' character will be exchanged with
     * @return true if the method succeeds (ship could be placed)
     * @return false if the method fails (ship could not be placed)
     */
    bool put_column_ship(int row_num, char column_letter, int size, char new_letter);

    /**
     * @brief Places horizontal ships on the game board if input arguments are acceptable
     * @param row_num the row number, 1-9, of the ship's first coordinate
     * @param column_letter the column letter, 'A' - 'J', of the ship's first coordinate
     * @param size the size of the ship
     * @param new_letter the character that the '~' character will be exchanged with
     * @return true if the method succeeds (ship could be placed)
     * @return false false if the method fails (ship could not be placed)
     */
    bool put_row_ship(int row_num, char column_letter, int size, char new_letter);

    /**
     * @brief 
     * @param row_num the row number, 1-9
     * @param column_letter the column letter, 'A' - 'J'
     * @pre called by Board object in checkHit method in Player class
     * @return char the character at the specified coordinate
     * @throw an exception if the index generated from the arguments is not in the board boundary
     */
    char is_what(int row_num, char column_letter);

    /**
     * @brief Obtain the character at the requested index (used by AI, which efficiently uses array indices)
     * @param row index of m_map of calling Board object
     * @param col index of m_map of calling Board object
     * @pre called by Board object in checkHit2 method in Player class
     * @return char at the specified index of 2D m_map array
     */
    char is_what2(int row, int col);

};

#endif
