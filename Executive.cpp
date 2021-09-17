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
  system("clear");
  string tempinput;
  cout << "It is time for Btttle Ship!!!!\n";
  do
  {
    cout<<"How many ships would you like to play with for this time:\n";
    cin>>tempinput;

  }while(!(tempinput=="1" || tempinput=="2" || tempinput=="3" || tempinput=="4" || tempinput=="5" || tempinput=="6"));
  ships=stoi(tempinput);
  cout<<"you have selected: "<<ships <<" ships to play with \n";
  player1ships = ships;
  player2ships = ships;

  cout << "Place the ships for player1\n"; // place ships for palyer 1
  place_ship(ships, player1);
  system("clear");

  cout << "Place the ships for player2\n"; // place ships for palyer 2
  place_ship(ships, player2);
  system("clear");

  game_start(player1,player2,ships);

  return;
}

void Executive::place_ship(int size, Player& new_player)
{
  string tempinput;
  int num = 1; // reocord the size of ship
  int row = 0;
  char column = ' ';
  do{
      new_player.getGameBoard(); //returns the hidden board of the player class and prints it
      do
      {

        cout<<"where would you like to place a ship with size 1x" << num << " ?\n";
        cout<<"It will default to the point of your choice, down or right.\n";
        cout<<"It will repeat for invalid placement of the ship. Please check if it repeats.\n";

        do
        {
          cout<<"Please enter a number for the row you would wish to put a ship in.\n";
          cin>>tempinput;

        }while(!(tempinput=="1" || tempinput=="2" || tempinput=="3" || tempinput=="4" || tempinput=="5" || tempinput=="6" || tempinput=="7" || tempinput=="8" || tempinput=="9"));
        row=stoi(tempinput);
        cout<<"Please enter a letter for the column you wish to put a ship in.\n";
        cin>>column;
      }while (!new_player.placeShip(row,column,num));// places the ship in the hidden board where the player has specified.

      cout << "Placed!\n";
      new_player.getGameBoard(); // a check to make sure that the ship has been put in the correct spot
      num++;
   } while(num < size+1);

   return;
}

void Executive::game_start(Player& player1, Player& player2, int size)
{
  int player1_count = 0; //it count all the hitted numbers
  int player2_count = 0;
  int max_count = size*(1+size)/2;
  char player_choice = 'n';
  int row = 0;
  char column = ' ';
  int column_num = 0;
  string tempinput;
  do
  {
    cout << "======================PLAYER1=======================\n\n";
    cout << "The Board of Player 2, choose one point to hit. \n";
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

      if (player2.checkHit(row, column))
      {
        player2.get_hit(row,column);
        player2_count++;
        cout << "YOU HIT IT!!!\n";
        player2.getHiddenBoard();
        if (player2_count == max_count) //check if Player1 wins
        {
          break;
        }
      }
      else
      {
        cout << "YOU MISS IT!!!\n";
        player2.getHiddenBoard();
      }

      cout << "Do you want to show your private Board(y/n)?\n";
      cin >> player_choice;
      if(player_choice == 'y')
      {
        cout <<"YOUR BOARD\n";
        player1.getGameBoard();
      }
      else{}

      do
      {
        cout << "Do you want to take turn(y/n)?\n";
        cin >> player_choice;
      }while (player_choice == 'n');
      system("clear");


      cout << "======================PLAYER2=======================\n\n";
      cout << "The Board of Player 1, choose one point to hit. \n";
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
        int column_num = (char)column - 65;
      }while (column_num<0 || column_num >10); //Boundary

      if (player1.checkHit(row, column))
      {
        player1.get_hit(row,column);
        player1_count++;
        cout << "YOU HIT IT!!!\n";
        player1.getHiddenBoard();
      }
      else
      {
        cout << "YOU MISS IT!!!\n";
        player1.getHiddenBoard();
      }

      cout << "Do you want to show your private Board(y/n)?\n";
      cin >> player_choice;
      if(player_choice == 'y')
      {
        cout <<"YOUR BOARD\n";
        player2.getGameBoard();
      }
      else{}

      do
      {
        cout << "Do you want to take turn(y/n)?\n";
        cin >> player_choice;
      }while (player_choice == 'n');
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
