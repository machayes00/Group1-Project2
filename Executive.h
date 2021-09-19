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
  Executive();

  ~Executive();

  void run();
  //@input - none.
  //@input - none.
  //@process - This creates the space where the game is is run and dishes out tasks to the other methods ie the setup and game_start method.
  //@return - none

  void place_ship(int size, Player& new_player);
  //@input - size - the size of the ship you wish to place at that coordinate.ie a 1x1 or 1x2 etc.
  //@input - new_player - passes a player object by reference.
  //@process - places a ship with the passed size on the passed players gameBoard.
  //@return - none

  void game_start(Player& player1, Player& player2, int size);
  //@input - player1 - a passed player object.
  //@input - player2 - a passed player object
  //@input - size - amount of ships that game is currrently being player with between 1-6.
  //@process - runs the games turns and checks for a win for both players.
  //@return - none

};

#endif
