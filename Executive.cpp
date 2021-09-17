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
  int size = 0;//the size of the ship that they wish to put there.
  do{
    player1.getGameBoard(); //returns the hidden board of the player class and prints it
    cout<<"where would you like to place a ship.\n";
    do {
      cout<<" Please enter a number from 1 to 9 for the row you would wish to put a ship in.\n";
      cin>>row;
    } while(!(row >= 1 && row <= 9));
    do {
      cout<<"Please enter a letter from A to J for the column you wish to put a ship in.\n";
      cin>>column;
    } while(!((char)column >= 65 && (char)column <= 74)); //loops untill a capital leter from A to J is given

    cout<<"what size ship do you wish to add to the board.\n";
    cin>>size;
    player1.placeShip(row,column,size); // places the ship in the hidden board where the player has specified.
    player1.getGameBoard(); // a check to make sure that the ship has been put in the correct spot
    break;    //break for the loop since all the code hasnt been implemented
  } while(counter != player1ships); //while loop to place the ships on the board, only for player1 at the moment.


  do {
    break;
    /*put this here so that the program will end if a test run is down
    *because right now it just goes endlessly.
    */
  } while(player1ships != 0 && player2ships != 0);
}
