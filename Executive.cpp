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
  //int player1shipstoplace = ships; //how many ships this player needs to place before the game can begin;
  //int player2shipstoplace = ships; //how many ships this player needs to place before the game can begin;
  //int counter=0; //counter to make sure all of the ships have been put onto the board. //replaced by i in for loop
  int row=0; // the row in which the player want to add a ship.
  char column = ' '; // the column in which the player wants to add a ship.
  int size = 0;//the size of the ship that they wish to put there.

  for(int i=1; i<=ships; i++)
  {
    player1.getGameBoard(); //returns the hidden board of the player class and prints it
    cout<<"where would you like to place your 1x" <<i <<" ship.\n";
    do {
      cout<<"Please enter a number from 1 to 9 for the row you would wish to put a ship in.\n";
      cin>>row;
    } while(!(row >= 1 && row <= 9));
    do {
      cout<<"Please enter a capital letter from A to J for the column you wish to put a ship in.\n";
      cin>>column;
    } while(!((char)column >= 65 && (char)column <= 74)); //loops untill a capital leter from A to J is given
    size=i;

    if(player1.placeShip(row,column,size)) // places the ship in the hidden board where the player has specified.
    {
      cout<<"Ship placed.\n";
    }
    else
    {
      cout<<"Can't place a ship there!\n";
      i--;
    }
    player1.getGameBoard(); // a check to make sure that the ship has been put in the correct spot

  }



  do {
    break;
    /*put this here so that the program will end if a test run is down
    *because right now it just goes endlessly.
    */
  } while(player1ships != 0 && player2ships != 0);
}
