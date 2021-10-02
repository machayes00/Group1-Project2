#include "Executive.h"
#include "Board.h"
#include "Player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
  system("clear");
  string tempinput;
  string aitrigger;
  cout << "It is time for Batttle Ship!!!\n";
  do
  {
    cout<<"Please enter a number between 1-6 of how many ships you would like to play with this game:\n";
    cin>>tempinput;

  }while(!(tempinput=="1" || tempinput=="2" || tempinput=="3" || tempinput=="4" || tempinput=="5" || tempinput=="6")); //runs loop until a valid number of ships is entered into the program
  ships=stoi(tempinput);
  cout<<"you have selected: "<<ships <<" ships to play with \n";
  player1ships = ships;
  player2ships = ships;
  cout << "Do you want to play against an AI?(Y/N)";
  cin >> aitrigger;
  cout << "Place the ships for player 1\n"; // place ships for palyer 1
  place_ship(ships, player1);
  system("clear");
  if(aitrigger == "Y" || aitrigger == "y")
  {
    cout << "Placing the ships for player 2\n"; // place ships for palyer 2
    aiplace(ships,player2);
    system("clear");
  }
  else
  {
  cout << "Place the ships for player 2\n"; // place ships for palyer 2
  place_ship(ships, player2);
  system("clear");
  }
  game_start(player1,player2,ships);

  return;
}

// E: please add comments to make it easier for me to help with this. I only marked syntax errors.
// If comments clarify the intnet or plan, it makes it easier to fix the code.
void Executive::aiplace(int size, Player& new_player)
{
  string tempinput; // E: tempinput is declared as both string and int
  int num = 1; // reocord the size of ship
  int row = 0;
  char column = ' ';
  int tempinput;  // E: tempinput is declared as both string and int (I think 2nd declaration is ignored)
  string dir;

  do{
      new_player.getGameBoard(); //returns the hidden board of the player class and prints it
      srand(time(NULL));
      do{
      row=rand() % 9;
      tempinput=rand() % 10;
      column = tempinput + 'A'; // E: column was declared as a char. Can't assign to a string OR int
      tempinput=rand() % 2;
      if(tempinput == 1) //  E: needs fix. C++ thinks you are comparing a string type to an int type
      {
        dir="row";
      }
      else
      {
        dir="col";
      }
      }while (!new_player.placeShip(row,column,num,dir));// places the ship in the hidden board where the player has specified.

      cout << "Placed!\n";
      //new_player.getGameBoard(); // a check to make sure that the ship has been put in the correct spot
      num++;
   } while(num < size+1);

   return;
}
void Executive::place_ship(int size, Player& new_player)
{
  string tempinput;
  int num = 1; // reocord the size of ship
  int row = 0;
  char column = ' ';
  string direction;
  do{
      new_player.getGameBoard(); //returns the hidden board of the player class and prints it
      do
      {

        cout<<"Where would you like to place a ship with size 1x" << num << "?\n";
        cout<<"The rest of the ship will extend down or right from your selected coordinate.\n";
        cout<<"If the placement is invalid your ship will not be placed and you will be prompted for new placemnet information.\n";

        do
        {
          cout<<"Please enter a number for the row you would wish to place a ship in.\n";
          cin>>tempinput;
        }while(!(tempinput=="1" || tempinput=="2" || tempinput=="3" || tempinput=="4" || tempinput=="5" || tempinput=="6" || tempinput=="7" || tempinput=="8" || tempinput=="9"));
        row=stoi(tempinput);
        cout<<"Please enter a letter for the column you wish to place a ship in.\n";
        cin>>column;
        cout << "In which direction do you want to place? (row/col)";
        cin >> direction;
      } while(!new_player.placeShip(row,column,num,direction));// places the ship in the hidden board where the player has specified.

      cout << "Placed!\n";
      //new_player.getGameBoard(); // a check to make sure that the ship has been put in the correct spot
      num++;
   } while(num < size+1);

   return;
}

void Executive::game_start(Player& player1, Player& player2, int size)
{
  int player1_count = 0; //keeps a running total of the number of hits scored on each players side
  int player2_count = 0;
  int max_count = size*(1+size)/2; //uses the given amount of ships(size) to check how many hits each player can have before they are out of ships.
  char player_choice = 'n';
  int row = 0;
  char column = ' ';
  int column_num = 0;
  string tempinput;
  do
  {
    cout << "======================PLAYER1=======================\n\n";
    cout << "Opponent's Board: choose a coordinate to fire at.\n";
    player2.getHiddenBoard();

      do
      {
        cout << "Enter the the row number: ";  // get the row
        cin>>tempinput;

      }while(!(tempinput=="1" || tempinput=="2" || tempinput=="3" || tempinput=="4" || tempinput=="5" || tempinput=="6" || tempinput=="7" || tempinput=="8" || tempinput=="9"));
      row=stoi(tempinput);
      do
      {
        cout << "Enter the column character: "; // get the column
        cin >> column;
        column_num = (char)column - 65;
      }while (column_num<0 || column_num >10);//Boundary


      system("clear");
      if (player2.checkHit(row, column))
      {
        player2.get_hit(row,column);
        player2_count++;
        cout << "YOU HIT!\n";
        player2.getHiddenBoard();
        if (player2_count == max_count) //check if Player1 wins
        {
          break;
        }
      }
      else
      {
        cout << "YOU MISSED!\n";
        player2.getHiddenBoard();
      }

      cout << "Do you want to see your Board(y/n)?\n";
      cin >> player_choice;
      if(player_choice == 'y')
      {
        cout <<"YOUR BOARD\n";
        player1.getGameBoard();
      }


      do
      {
        cout << "End Turn(y/n)?\n";
        cin >> player_choice;
      }while (player_choice != 'y');
      system("clear");

      do
      {
        cout << "Player2: Begin Turn(y/n)?\n";
        cin >> player_choice;
      }while (player_choice != 'y');
      system("clear");

      cout << "======================PLAYER2=======================\n\n";
      cout << "Opponent's Board: choose a coordinate to fire at.\n";
      player1.getHiddenBoard();


      do
      {
        cout << "Enter the the row number: ";  // get the row
        cin>>tempinput;

      }while(!(tempinput=="1" || tempinput=="2" || tempinput=="3" || tempinput=="4" || tempinput=="5" || tempinput=="6" || tempinput=="7" || tempinput=="8" || tempinput=="9"));
      row=stoi(tempinput);
      do
      {
        cout << "Enter the column character: "; // get the column
        cin >> column;
        column_num = (char)column - 65;
      }while (column_num<0 || column_num >10); //Boundary

      system("clear");
      if (player1.checkHit(row, column))
      {
        player1.get_hit(row,column);
        player1_count++;
        cout << "YOU HIT!\n";
        player1.getHiddenBoard();
        if (player1_count == max_count) //check if Player2 wins
        {
          break;
        }
      }
      else
      {
        cout << "YOU MISS!\n";
        player1.getHiddenBoard();
      }

      cout << "Do you want to see your Board(y/n)?\n";
      cin >> player_choice;
      if(player_choice == 'y')
      {
        cout <<"YOUR BOARD\n";
        player2.getGameBoard();
      }
      else{}

      do
      {
        cout << "End Turn(y/n)?\n";
        cin >> player_choice;
      }while (player_choice != 'y');
      system("clear");

      do
      {
        cout << "Player1: Begin Turn(y/n)?\n";
        cin >> player_choice;
      }while (player_choice != 'y');
      system("clear");

  }while (player1_count < max_count && player2_count < max_count);
  if (player1_count == max_count)
  {
    cout << "Player2 WINS!\n";
  }
  else
  {
    cout << "Player1 WINS!\n";
  }

  return;
}
