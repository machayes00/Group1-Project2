#include "Executive.h"
#include "Board.h"
#include "Player.h"
#include <stdio.h>  
#include <stdlib.h>  // need for srand rand
#include <time.h>    // need for unique start point (seed) for random number generation
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
  system("clear");  // this clears the screen
  string tempinput; // temporary variable for capturing user input for number of ships
  string aitrigger; // variable for capturing user choice of AI or human player
  cout << "It is time for Batttle Ship!!!\n";
  do
  {
    cout << "Please enter a number between 1-6 for the number of ships you would like per player:\n";
    cin >> tempinput;

  } while (!(tempinput == "1" || tempinput == "2" || tempinput == "3" || tempinput == "4" || 
          tempinput == "5" || tempinput == "6")); //runs loop until a valid number of ships is entered

  ships = stoi(tempinput); // changes string input to int
  cout << "You have selected: " << ships << " ships per player for this game. \n";
  player1ships = ships;
  player2ships = ships;

  cout << "Do you want to play against an AI instead of human opponent? (Y/N): ";
  cin >> aitrigger;

  cout << "Placing the ships for player 1\n"; // Player 1 ship placement same for AI opponent or human opponent
  cout << endl;
  place_ship(ships, player1);

  system("clear"); // screen clears after player 1 ships are placed, to prepare for player 2

  if (aitrigger == "Y" || aitrigger == "y")
  {
    cout << "Placing the ships for player 2\n"; 
    aiplace(ships, player2);
    system("clear");
  }
  else
  {
    cout << "Place the ships for player 2\n"; 
    place_ship(ships, player2);
    system("clear");
  }

  game_start(player1, player2, ships);
}

// Placing ships randomly for the AI opponent
void Executive::aiplace(int size, Player& new_player)
{
  char dir = ' '; // will be randomly assigned a direction (changed to char because string caused compiler error)
  int num = 1; // the size of the ship, to be incremented after each placement
  int row = 0;  // will be randomly generated
  char column = ' '; // will be randomly generated

  do
  {
    new_player.getGameBoard(); //returns the hidden board of the player class and prints it
    srand(time(NULL));  // seed for random number generator is set based on current time
    do
    {
      // generate random row:
      row = (rand()%9)+1;  // This should give random number between 1 and 9
      // Rationale is, n%m  gives values between (0 and m-1) and so I want to add 1 to result

      // generate random column:
      // rand() % 10 gives randon number between 0 and 9
      int randomnumber = (rand()%10)+1;
      // Now, covnert randomnumber to ASCII and assign that to column char variable
      column = 'A' + randomnumber; 

      // generate random orientation for ship placement
      int oddoreven = rand() % 2;
      if (oddoreven == 1) 
      {
        dir = 'r';
      }
      else
      {
        dir = 'd';
      }
    } while (!new_player.placeShip(row, column, num, dir)); // places the ship in the hidden board where the player has specified.

    cout << "Placed ship!\n";
    new_player.getGameBoard(); // a check to make sure that the ship has been put in the correct spot
    num++;
  } while (num < size + 1);
}

// Placing ship for human opponent
void Executive::place_ship(int size, Player& new_player)
{
  int num = 1;      // stores the size of ship, to be incremented with each ship placement
  string tempinput; // stores user imput for row number, to be converted to int
  int row = 0;
  char column = ' ';
  char direction = ' ';  // changed to char, to fix compiler error
  do
  {
    new_player.getGameBoard(); //returns the hidden board of the player class and prints it
    do
    {
      cout << "Where would you like to place a ship with size 1x" << num << "?\n";
      cout << "The rest of the ship will extend down or right from your selected coordinate.\n";
      cout << "If the placement is invalid your ship will not be placed and you will be prompted for new placemnet information.\n";

      do
      {
        cout << "Please enter a number for the row you would wish to place a ship in.\n";
        cin >> tempinput;
      } while (!(tempinput == "1" || tempinput == "2" || tempinput == "3" || tempinput == "4" || 
              tempinput == "5" || tempinput == "6" || tempinput == "7" || tempinput == "8" || tempinput == "9"));

      row = stoi(tempinput);

      cout << "Please enter a letter for the column you wish to place a ship in.\n";
      cin >> column;
      cout << "In which direction do you want to place? Enter D or d for down (vertical), R or r for right (horizontal):\n";
      cin >> direction;
    } while (!new_player.placeShip(row, column, num, direction)); // places the ship in the hidden board where the player has specified.

    cout << "Placed ship!\n";
    //new_player.getGameBoard(); // a check to make sure that the ship has been put in the correct spot
    num++;
  } while (num < size + 1);
}

void Executive::game_start(Player& player1, Player& player2, int size)
{
  int player1_count = 0; //keeps a running total of the number of hits scored on each player's side
  int player2_count = 0;
  int max_count = size * (1 + size) / 2; //uses the given amount of ships(size) to check how many hits each player can have before they are out of ships.
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
      cout << "Enter the the row number: "; // get the row
      cin >> tempinput;

    } while (!(tempinput == "1" || tempinput == "2" || tempinput == "3" || tempinput == "4" || tempinput == "5" 
              || tempinput == "6" || tempinput == "7" || tempinput == "8" || tempinput == "9"));

    row = stoi(tempinput);

    do
    {
      cout << "Enter the column character: "; // get the column
      cin >> column;
      column_num = (char)column - 65;
    } while (column_num < 0 || column_num > 10); //Boundary
    system("clear");
    
    if (player2.checkHit(row, column))
    {
      player2.get_hit(row, column);
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
    if (player_choice == 'y')
    {
      cout << "YOUR BOARD\n";
      player1.getGameBoard();
    }

    do
    {
      cout << "End Turn(y/n)?\n";
      cin >> player_choice;
    } while (player_choice != 'y');
    system("clear");

    do
    {
      cout << "Player2: Begin Turn(y/n)?\n";
      cin >> player_choice;
    } while (player_choice != 'y');
    system("clear");

    cout << "======================PLAYER2=======================\n\n";
    cout << "Opponent's Board: choose a coordinate to fire at.\n";
    player1.getHiddenBoard();

    do
    {
      cout << "Enter the the row number: "; // get the row
      cin >> tempinput;

    } while (!(tempinput == "1" || tempinput == "2" || tempinput == "3" || tempinput == "4" || tempinput == "5" 
              || tempinput == "6" || tempinput == "7" || tempinput == "8" || tempinput == "9"));
    row = stoi(tempinput);
    do
    {
      cout << "Enter the column character: "; // get the column
      cin >> column;
      column_num = (char)column - 65;
    } while (column_num < 0 || column_num > 10); //Boundary

    system("clear");
    if (player1.checkHit(row, column))
    {
      player1.get_hit(row, column);
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
    if (player_choice == 'y')
    {
      cout << "YOUR BOARD\n";
      player2.getGameBoard();
    }
    else
    {
    }

    do
    {
      cout << "End Turn(y/n)?\n";
      cin >> player_choice;
    } while (player_choice != 'y');
    system("clear");

    do
    {
      cout << "Player1: Begin Turn(y/n)?\n";
      cin >> player_choice;
    } while (player_choice != 'y');
    system("clear");

  } while (player1_count < max_count && player2_count < max_count);
  if (player1_count == max_count)
  {
    cout << "Player2 WINS!\n";
  }
  else
  {
    cout << "Player1 WINS!\n";
  }
}
