#include "Executive.h"
#include "Board.h"
#include "Player.h"
#include <stdio.h>
#include <stdlib.h> // need for srand rand
#include <time.h>   // need for unique start point (seed) for random number generation
#include <iostream>
#include <unistd.h> 
#include <string>
using namespace std;

Executive::Executive()
{

}

Executive::~Executive()
{
}


//G: Prints title with alternating colors for a specified length
void Executive::introtitleanimation()
{
   for(int i = 0; i <10; i++)//loops for a specified duration
   {
   cout << "\033[1;91m********Welcome\033[0m ";//prints string with specified color: color is 91m
   cout << "\033[1;92m to\033[0m ";
   cout << "\033[1;93m battleship!********\033[0m\n";
   usleep(200000);//lasts for 0.5 seconds
   system("clear"); //clears previous prints statement allows for alternating title
   cout << "\033[1;94m----------Welcome\033[0m ";
   cout << "\033[1;95m to\033[0m ";
   cout << "\033[1;96m battleship!----------\033[0m\n";
   usleep(200000);
   system("clear");
   cout << "\033[1;91m********Welcome\033[0m ";
   cout << "\033[1;93m to\033[0m ";
   cout << "\033[1;95m battleship!********\033[0m\n";
   usleep(200000);
   system("clear");
   cout << "\033[1;92m----------Welcome\033[0m ";
   cout << "\033[1;94m to\033[0m ";
   cout << "\033[1;96m battleship!----------\033[0m\n";
   usleep(200000);
   system("clear");
   }
}


//G: Prints end screen for player 1 with alternating colors for a specified length
void Executive::endscreenanimation1()
{
   for(int i = 0; i <10; i++)//loops for a specified duration
   {
   cout << "\033[1;91m ********Player\033[0m ";//prints string with specified color: color is 91m
   cout << "\033[1;92m 1\033[0m ";
   cout << "\033[1;93m wins!********\033[0m\n";
   usleep(200000);//lasts for 0.5 seconds
   system("clear");//clears previous prints statement allows for alternating title
   cout << "\033[1;94m ********Player\033[0m ";
   cout << "\033[1;95m 1\033[0m ";
   cout << "\033[1;96m wins!********\033[0m\n";
   usleep(200000);
   system("clear");
   cout << "\033[1;91m ********Player\033[0m ";
   cout << "\033[1;93m 1\033[0m ";
   cout << "\033[1;95m wins!********\033[0m\n";
   usleep(200000);
   system("clear");
   cout << "\033[1;92m ********Player\033[0m ";
   cout << "\033[1;94m 1\033[0m ";
   cout << "\033[1;96m wins!********\033[0m\n";
   usleep(200000);
   system("clear");
   }   
}


//G: Prints end screen for player 2 with alternating colors for a specified length
void Executive::endscreenanimation2()
{
   for(int i = 0; i <10; i++)
   {
   cout << "\033[1;91m :D********Player\033[0m "; //prints string with specified color: color is 91m
   cout << "\033[1;92m 2\033[0m ";
   cout << "\033[1;93m wins!********:D\033[0m\n";
   usleep(200000);//lasts for 0.5 seconds
   system("clear");//clears previous prints statement allows for alternating title
   cout << "\033[1;94m :D********Player\033[0m ";
   cout << "\033[1;95m 2\033[0m ";
   cout << "\033[1;96m wins!********:D\033[0m\n";
   usleep(200000);
   system("clear");
   cout << "\033[1;91m :D********Player\033[0m ";
   cout << "\033[1;93m 2\033[0m ";
   cout << "\033[1;95m wins!********:D\033[0m\n";
   usleep(200000);
   system("clear");
   cout << "\033[1;92m :D********Player\033[0m ";
   cout << "\033[1;94m 2\033[0m ";
   cout << "\033[1;96m wins!********:D\033[0m\n";
   usleep(200000);
   system("clear");
   }   
}


    



void Executive::run()
{
    system("clear");  // this clears the screen
    string tempinput; // temporary variable for capturing user input for number of ships
    string aitrigger; // variable for capturing user choice of AI or human player
    int difficulty; // variable for difficulty for AI game (changed from "diff" so people don't have to rembember)


    do
    {
        introtitleanimation(); // prints title to screen with special effects
        cout << "\nPlease enter a number between 1-6 for the number of ships you would like per player:\n";
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
        cout << "What lever of difficulty for the game? Easy(1), Medium(2), Hard(3):";
        cin >> difficulty;
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

    game_start(player1, player2, ships, aitrigger, difficulty);
}

// Placing ships randomly for the AI opponent
void Executive::aiplace(int size, Player& new_player)
{
    char dir = ' ';    // will be randomly assigned a direction (changed to char because string caused compiler error)
    int num = 1;       // the size of the ship, to be incremented after each placement
    int row = 0;       // will be randomly generated (1 - 9)
    char column = ' '; // will be randomly generated ('A' - 'J')

    do
    {
        new_player.getGameBoard(); //returns the hidden board of the player class and prints it
        srand(time(NULL));         // seed for random number generator is set based on current time
        do
        {
            // generate random row:
            row = (rand() % 9) + 1; // This should give random number between 1 and 9
            // Rationale is, n%m  gives values between (0 and m-1) and so I want to add 1 to result

            // generate random column:
            // rand() % 10 gives randon number between 0 and 9
            int randomnumber = (rand() % 10);  // E: I deleted the +1 because you want to add 0 to 9 to the 'A' value
            // Now, covnert randomnumber to ASCII and assign that to column char variable
            column = 'A' + randomnumber;  // ASCII 65 plus 0 through 9

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
        } while (!new_player.placeShip(row, column, num, dir)); // places the ship in the hidden board where AI player has specified.

        cout << "Placed ship!\n";
        new_player.getGameBoard(); // a check to make sure that the ship has been put in the correct spot
        // comment out the above if the check is not needed
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
    char direction = ' '; 
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

            row = stoi(tempinput);  // converts user input from string to int

            cout << "Please enter a letter for the column you wish to place a ship in.\n";
            cin >> column;
            cout << "In which direction do you want to place? Enter D or d for down (vertical), R or r for right (horizontal):\n";
            cin >> direction;
        } while (!new_player.placeShip(row, column, num, direction)); // places the ship in the hidden board where the player has specified.

        cout << "Placed ship!\n";
        // new_player.getGameBoard(); // a check to make sure that the ship has been put in the correct spot
        // comment out the above line if the test is not needed
        num++;
    } while (num < size + 1);
}

void Executive::game_start(Player& player1, Player& player2, int size, string aitrigger, int difficulty)
{
    int player1_count = 0; //keeps a running total of the number of hits scored on each player's side
    int player2_count = 0;
    int max_count = size * (1 + size) / 2; //uses the given amount of ships(size) to check how many hits each player can have before they are out of ships.
    char player_choice = 'n';  // stores yes (y) or no (n) responses from payer after way too many questiond during game
    int row = 0;               // int 1 - 9 after converting user input to int
    char column = ' ';         // A - J
    int column_num = 0;        // 0 - 9
    string tempinput;          // temporary store of user row input before it is converted to int

    do  // long do-while loop that takes up most of the game_start method (bad name; the method starts and ends the shooting)
    {
        cout << "======================PLAYER1=======================\n\n";  // Player 1 is alays human, so takes firs shots
        cout << "Opponent's Board: choose a coordinate to fire at.\n";       // regardless of human or AI opponent

        player2.getHiddenBoard();  // pirnts Player 2 board with ships hidden (not a getter method despite name)

        do
        {
            cout << "Enter the the row number: "; // get the row
            cin >> tempinput;

        } while (!(tempinput == "1" || tempinput == "2" || tempinput == "3" || tempinput == "4" || tempinput == "5" 
                  || tempinput == "6" || tempinput == "7" || tempinput == "8" || tempinput == "9"));

        row = stoi(tempinput);   // convert string user input to int (1 - 9)

        do
        {
            cout << "Enter the column character: "; // get the column
            cin >> column;
            column_num = (char)column - 65;     // converts char to decimal ASCII; 'A' is 65, so converts to (0 to 9)
            // while condition checks for valid gameboard boundary
        } while (column_num < 0 || column_num > 9); // E: This was column_num > 10 in the game we inherited.
                                                    // I don't think that's right so I changed to 9
        system("clear");

        if (player2.checkHit(row, column))
        {
            player2.doAnimation(row - 1, column_num);
            player2.get_hit(row, column);
            player2_count++;
            player2.getHiddenBoard();
            cout << "YOU HIT!\n";
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

        cout << "======================PLAYER2=======================\n\n";  // Player 2 is either AI or human

        player1.getHiddenBoard(); // Prints the board with hidden ships for Player 2 to shoot at

        // E: temporary comment: split between AI and human opponent has to be at this point.

        if(aitrigger == "y" || aitrigger == "Y")
        {
            cout << "Opponent's Board: AI is firing!.\n";  // Can change or remove this later

            srand(time(NULL)); // sets unique seed for random number generation
            if (difficulty == 1) // easy game, AI fires randomly
            {
                row = (rand() % 9) + 1; // genterates a random number, 1-9
                int randomnumber = (rand() % 10);  // generates a random number 0-9
                column = 'A' + randomnumber;       // adds 0 to 9 to ASCII for 'A" to get 'A' - 'J'
            }
            else if(difficulty == 3)  // hard game, AI cheats and peeks at the ships
            {
                for (int i = 0; i < 9; i++) 
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if(player1.checkHit2(i, j))
                        {
                            row = i + 1;
                            column = 'A' + j;
                            // break; probably add break but don't really need
                        }
                    }
                }
            }
            // else if(difficulty == 2) need to put Medium difficulty here
        }

        else
        {
            cout << "Opponent's Board: choose a coordinate to fire at.\n";

            do
            {
                cout << "Enter the the row number: "; // get the row
                cin >> tempinput;

            } while (!(tempinput == "1" || tempinput == "2" || tempinput == "3" || tempinput == "4" || tempinput == "5" 
                       || tempinput == "6" || tempinput == "7" || tempinput == "8" || tempinput == "9"));
            row = stoi(tempinput); // convert string user input to int (1 - 9)

            do
            {
                cout << "Enter the column character: "; // get the column
                cin >> column;
                column_num = (char)column - 65;
                // while condition checks for valid gameboard boundary
            } while (column_num < 0 || column_num > 9); // E: This was column_num > 10 in the game we inherited.
                                                        // I don't think that's right so I changed to 9
        }

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

    } while (player1_count < max_count && player2_count < max_count); // end of longest do-while

    if (player1_count == max_count)
    {
        endscreenanimation1();
    }
    else
    {   
        endscreenanimation2();
    }
}
