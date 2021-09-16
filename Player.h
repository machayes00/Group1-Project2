#ifndef PLAYER_H
#define PLAYER_H


#include "Board.h"


class Player{
private:
  Board hiddenBoard;
  Board gameBoard;
  int shipsLeft;

public:
  Player(int ships);
  ~Player();
  bool checkHit(int row,char col);//checks what is hit
  //@input - int row - the row in which the player wants to place a boat.
  //@input - char col - the column in which the player wants to place a ship.
  //@process - uses the passed parameters to check to see if a B exists at the passed location in the hiddenBoard.
  //@return - the board object of the player class.
  //pass a row and coloumn
  //return 1 if hits ships, 0 if hits water

  int checkShips();
  //@input - none.
  //@input - none.
  //@process - none
  //@return - returns the amount of ships left for the player class.
  void hit(int row, char col);//helper function checkHit()
  //@input - int row - the row in which the player wants to place a boat.
  //@input - char col - the column in which the player wants to place a ship.
  //@process - replaces a B in the array with an X.
  //@return - none.
  Board getHiddenBoard();
  //@input - none.
  //@input - none.
  //@process - return the hidden board object. Mainly used for calling methods of the board class
  //@return - the board object of the player class.
  Board getGameBoard();
  //@input - none.
  //@input - none.
  //@process - return the Game board object. Mainly used for calling methods of the board class
  //@return - the board object of the player class.
  bool placeShip(int row, char col);
  //@input - the row number in which the ship will be placed
  //@input - the column number in which the ship will be place
  //@process - places a ship in the hidden board obj of the player class.
  //@return - true if ship was placed, false if ship wasnt placed.

};
//mark hits with x misses with o

#endif