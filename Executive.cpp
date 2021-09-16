#include "Executive.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
using namespace std;


Executive::Executive()
{

}

Executive::~Executive()
{

}

void Executive::run()
{
  int ships;
  cout<<"how many ships would you like to play with.\n";
  cin>>ships;
  cout<<"you have selected: "<<ships <<" ships to play with \n";
  Player player1(ships);
  Player player2(ships);
  player1ships = ships;
  player2ships = ships;
  int counter=0; //counter to make sure all of the ships have been put onto the board.
  int row=0; // the row in which the player want to add a ship.
  char column = ' '; // the column in which the player wants to add a ship.
  do{
    player1.getHiddenBoard().print(); //returns the hidden board of the player class and prints it
    cout<<"where would you like to place a ship.\n";
    cout<<" Please enter a number for the row you would wish to put a ship in.\n";
    cin>>row;
    cout<<"Please enter a letter for the column you wish to put a ship in.\n";
    cin>>column;
    player1.getHiddenBoard().exchange(row,column,'B'); // places the ship in the hidden board where the player has specified.
    player1.getHiddenBoard().print(); // a check to make sure that the ship has been put in the correct spot
    break;    //break for the loop since all the code hasnt been implemented
  } while(counter != player1ships); //while loop to place the ships on the board, only for player1 at the moment.


  do {
    break;  
    /*put this here so that the program will end if a test run is down 
    *because right now it just goes endlessly.
    */
  } while(player1ships != 0 && player2ships != 0);
}
