#ifndef PLAYER_H
#define PLAYER_H


#include "Board.h"
#include <iostream>
#include <string>


class Player{
private:
  Board hiddenBoard ; // this board is shown to opponent
  Board gameBoard; // this board shows ships and hit locations
  Board original_Board;// this board stores all the ships and does not make any changes
  int shipsLeft;  // keeps tracks of number of ships remaining

public:
  Player();
  ~Player();
  bool checkHit(int row,char col);//checks what is hit
  //@input - int row - the row in which the player wants to place a boat.
  //@input - char col - the column in which the player wants to place a ship.
  //@process - uses the passed parameters to check to see if a B exists at the passed location in the hiddenBoard.
  //return 1 if hits ships, 0 if hits water

  int checkShips();
  //@input - none.
  //@input - none.
  //@process - none
  //@return - returns the amount of ships left for the player class.

  void get_hit(int row, char col);//helper function checkHit()
  //@input - int row - the row in which the player wants to place a boat.
  //@input - char col - the column in which the player wants to place a ship.
  //@process - replaces a B in the array with an X.
  //@return - none.

  void getHiddenBoard();
  //@input - none.
  //@input - none.
  //@process - print the hidden board object.
  //@return - none

  void getGameBoard();
  //@input - none.
  //@input - none.
  //@process - print the Game board object.
  //@return - none

  void getOriginalBoard();
  //@input - none.
  //@input - none.
  //@process - print the Game board object. Mainly used for calling methods of the board class
  //@return - none

  // E: extra string parameter added in was causing compiler error
  // so I changed to char
  bool placeShip(int row, char col, int size, char dir);
  //@input - the row number in which the ship will be placed
  //@input - the column number in which the ship will be place
  //@input - int the size of the ship
  //@process - asking user about the direction of the shop. places a ship in the gameBoard and original_Board
  //@return - true if ship was placed, false if ship wasnt placed.

};

#endif
