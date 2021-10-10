#include "Executive.h"
#include "Board.h"
#include "Player.h"
#include <stdio.h>  // probably not needed; we are using <iostream> for io
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

// Prints title with alternating colors for a specified length of time
string asciiArt1 =   R"( 
                      *   
                    *_\/_*     
                    * /\ *     
                     *..*)";

string asciiArt2 = R"( .:::.                
                       :|||:  
                        :::)"  ;

string asciiArt3 = R"(
          _______  _        _______  _______  _______  _______ 
|\     /|(  ____ \( \      (  ____ \(  ___  )(       )(  ____ \
| )   ( || (    \/| (      | (    \/| (   ) || () () || (    \/
| | _ | || (__    | |      | |      | |   | || || || || (__    
| |( )| ||  __)   | |      | |      | |   | || |(_)| ||  __)   
| || || || (      | |      | |      | |   | || |   | || (      
| () () || (____/\| (____/\| (____/\| (___) || )   ( || (____/\
(_______)(_______/(_______/(_______/(_______)|/     \|(_______/
)";

string asciiArt4 = R"(
_________ _______ 
\__   __/(  ___  )
   ) (   | (   ) |
   | |   | |   | |
   | |   | |   | |
   | |   | |   | |
   | |   | (___) |
   )_(   (_______|
)";

string asciiArt5 = R"(
     ______   _______ __________________ _        _______  _______          _________ _______    _ 
(  ___ \ (  ___  )\__   __/\__   __/( \      (  ____ \(  ____ \|\     /|\__   __/(  ____ )  ( )
| (   ) )| (   ) |   ) (      ) (   | (      | (    \/| (    \/| )   ( |   ) (   | (    )|  | |
| (__/ / | (___) |   | |      | |   | |      | (__    | (_____ | (___) |   | |   | (____)|  | |
|  __ (  |  ___  |   | |      | |   | |      |  __)   (_____  )|  ___  |   | |   |  _____)  | |
| (  \ \ | (   ) |   | |      | |   | |      | (            ) || (   ) |   | |   | (        (_)
| )___) )| )   ( |   | |      | |   | (____/\| (____/\/\____) || )   ( |___) (___| )         _ 
|/ \___/ |/     \|   )_(      )_(   (_______/(_______/\_______)|/     \|\_______/|/         (_)
)";

string asciiArt6 = R"(
    _.-^^---....,,--       
 _--                  --_  
<                        >)
|                         | 
 \._                   _./  
    ```--. . , ; .--'''       
          | |   |             
       .-=||  | |=-.   
       `-=#$%&%$#=-'   
          | ;  :|     
 _____.,-#%&$@%#&#~,._____
)";


string asciiArt7 = R"(
 _______  _        _______           _______  _______     __              _________ _        _______    _ 
(  ____ )( \      (  ___  )|\     /|(  ____ \(  ____ )   /  \    |\     /|\__   __/( (    /|(  ____ \  ( )
| (    )|| (      | (   ) |( \   / )| (    \/| (    )|   \/) )   | )   ( |   ) (   |  \  ( || (    \/  | |
| (____)|| |      | (___) | \ (_) / | (__    | (____)|     | |   | | _ | |   | |   |   \ | || (_____   | |
|  _____)| |      |  ___  |  \   /  |  __)   |     __)     | |   | |( )| |   | |   | (\ \) |(_____  )  | |
| (      | |      | (   ) |   ) (   | (      | (\ (        | |   | || || |   | |   | | \   |      ) |  (_)
| )      | (____/\| )   ( |   | |   | (____/\| ) \ \__   __) (_  | () () |___) (___| )  \  |/\____) |   _ 
|/       (_______/|/     \|   \_/   (_______/|/   \__/   \____/  (_______)\_______/|/    )_)\_______)  (_)
)";

string asciiArt8 = R"(
 _______  _        _______           _______  _______    _______            _________ _        _______    _ 
(  ____ )( \      (  ___  )|\     /|(  ____ \(  ____ )  / ___   )  |\     /|\__   __/( (    /|(  ____ \  ( )
| (    )|| (      | (   ) |( \   / )| (    \/| (    )|  \/   )  |  | )   ( |   ) (   |  \  ( || (    \/  | |
| (____)|| |      | (___) | \ (_) / | (__    | (____)|      /   )  | | _ | |   | |   |   \ | || (_____   | |
|  _____)| |      |  ___  |  \   /  |  __)   |     __)    _/   /   | |( )| |   | |   | (\ \) |(_____  )  | |
| (      | |      | (   ) |   ) (   | (      | (\ (      /   _/    | || || |   | |   | | \   |      ) |  (_)
| )      | (____/\| )   ( |   | |   | (____/\| ) \ \__  (   (__/\  | () () |___) (___| )  \  |/\____) |   _ 
|/       (_______/|/     \|   \_/   (_______/|/   \__/  \_______/  (_______)\_______/|/    )_)\_______)  (_)
                                                                                                            
)";
string victoryArt4 = R"(
                *    *
   *         '       *       .  *   '     .           * *
                                                               '
       *                *'          *          *        '
   .           *               |               /
               '.         |    |      '       |   '     *
                 \*        \   \             /
       '          \     '* |    |  *        |*                *  *
            *      `.       \   |     *     /    *      '
  .                  \      |   \          /               *
     *'  *     '      \      \   '.       |
        -._            `                  /         *
  ' '      ``._   *                           '          .      '
   *           *\*          * .   .      *
*  '        *    `-._                       .         _..:='        *
             .  '      *       *    *   .       _.:--'
          *           .     .     *         .-'         *
   .               '             . '   *           *         .
  *       ___.-=--..-._     *                '               '
                                  *       *
                *        _.'  .'       `.        '  *             *
     *              *_.-'   .'            `.               *
                   .'                       `._             *  '
   '       '                        .       .  `.     .
       .                      *                  `
               *        '             '                          .
     .                          *        .           *  *
             *        .
)";

string victoryArt1 = R"(
           /\
          /  \
         /    \
        /      \
       /        \
      /          \
     /            \
    /              \
   /                \
  /                  \
 /                    \
/______________________\
  |                  |
  |            _     |
  |        _.-'_)    |
  |    _.-'_.-'      |
  |   (_  (._        |
  |     `-._ `-_     |
  |         `-. )    |
  |   /~`-._  | |    |
  |   |  _  | | |    |
  |   | | | | | |    |
  |   | | | `~  |    |
  |   | |  ~-._/'    |
  |   (_ `-._        |
  |     `-._ `-_     |
  |        _)  _)    |
  |    _.-'_.-'      |
 _|   (_  (._        |
| |     `-._ `-_     |
| |         `-. )    |
| |        _.-'_|    |
| |    _.-'_.-'      |
| |   (_  (._        |
| |     `-._ `-_     |
| |         `-._)    |
| |                  |
| |                  |
| |                  |
| |~~~~~~~~||~~~~~~~~
| |        ||
| |         \\  ,
| |          \*'
| |          ',``
| |
| |
| |
)";

string victoryArt2 = R"(
    .:::.                
    :|||:  
    (:::)
    .:::.                
    :|||:  
    (:::)
    .:::.                
    :|||:  
    (:::)
    .:::.                
    :|||:  
    (:::)
    .:::.                
    :|||:  
    (:::)
    .:::.                
    :|||:  
    (:::)
    .:::.                
    :|||:  
    (:::)
    .:::.                
    :|||:  
    (:::)
    .:::.                
    :|||:  
    (:::)
    .:::.                
    :|||:  
    (:::)
)";

string victoryArt3 = R"(

     R"( 
                      *   
                    *_\/_*     
                    * /\ *     
                     *..*
                      *   
                    *_\/_*     
                    * /\ *     
                     *..*   *   
                    *_\/_*     
                    * /\ *     
                     *..*   *   
                    *_\/_*     
                    * /\ *     
                     *..*   *   
                    *_\/_*     
                    * /\ *     
                     *..*   *   
                    *_\/_*     
                    * /\ *     
                     *..*   *   
                    *_\/_*     
                    * /\ *     
                     *..*   *   
                    *_\/_*     
                    * /\ *     
                     *..*
                        *   
                    *_\/_*     
                    * /\ *     
                     *..*   *   
                    *_\/_*     
                    * /\ *     
                     *..*)";



//G: Prints title with alternating colors for a specified length
void Executive::introtitleanimation()
{
   for(int i = 0; i <2; i++)//loops for a specified duration
   {
   cout << "\033[1;91m" << asciiArt2 << "\033[0m " << '\n';//special art
   cout << "\033[1;91m" <<asciiArt3<< "\033[0m ";//prints string with specified color: color is 91m
   cout << "\033[1;92m" << asciiArt4 << "\033[0m ";
   cout << "\033[1;93m" << asciiArt5 <<"\033[0m \n";
   cout << "\033[1;91m" << asciiArt2 << "\033[0m " << '\n';//special art
   usleep(200000);//lasts for 0.5 seconds
   system("clear"); //clears previous prints statement allows for alternating title

   cout << "\033[1;93m" << asciiArt1 << "\033[0m " << '\n';//special art
   cout << "\033[1;94m" <<asciiArt3<< "\033[0m ";//prints string with specified color: color is 91m
   cout << "\033[1;95m" << asciiArt4 << "\033[0m ";
   cout << "\033[1;96m" << asciiArt5 <<"\033[0m \n";
   cout << "\033[1;93m" << asciiArt1 << "\033[0m " << '\n';//special art
   usleep(200000);
   system("clear");

   cout << "\033[1;92m" << asciiArt6 << "\033[0m " << '\n';
   cout << "\033[1;91m" <<asciiArt3<< "\033[0m ";//prints string with specified color: color is 91m
   cout << "\033[1;93m" << asciiArt4 << "\033[0m ";
   cout << "\033[1;95m" << asciiArt5 <<"\033[0m\n";
   cout << "\033[1;92m" << asciiArt6 << "\033[0m " << '\n';
   usleep(200000);
   system("clear");

   cout << "\033[1;93m" << asciiArt1 << "\033[0m " << '\n';
   cout << "\033[1;92m" <<asciiArt3<< "\033[0m ";//prints string with specified color: color is 91m
   cout << "\033[1;94m" << asciiArt4 << "\033[0m ";
   cout << "\033[1;96m" << asciiArt5 <<"\033[0m \n";
  cout << "\033[1;93m" << asciiArt1 << "\033[0m " << '\n';
   usleep(200000);
   system("clear");

   cout << "\033[1;91m" << asciiArt2 << "\033[0m " << '\n';
   cout << "\033[1;91m" <<asciiArt3<< "\033[0m ";//prints string with specified color: color is 91m
   cout << "\033[1;94m" << asciiArt4 << "\033[0m ";
   cout << "\033[1;95m" << asciiArt5 <<"\033[0m \n";
   cout << "\033[1;91m" << asciiArt2 << "\033[0m " << '\n';
   usleep(200000);
   system("clear");

   cout << "\033[1;92m" << asciiArt6 << "\033[0m " << '\n';
   cout << "\033[1;93m" <<asciiArt3<< "\033[0m ";//prints string with specified color: color is 91m
   cout << "\033[1;96m" << asciiArt4 << "\033[0m ";
   cout << "\033[1;92m" << asciiArt5 <<"\033[0m \n";
   cout << "\033[1;92m" << asciiArt6 << "\033[0m " << '\n';
   usleep(200000);
   system("clear");
   }
}

// Prints end screen for player 1 with alternating colors for a specified length of time

// Prints end screen for player 2 with alternating colors for a specified length of time
void Executive::endscreenanimation1()
{
    cout << "\033[1;91m" << victoryArt1 << "\033[0m " << '\n'; //prints variations of victoryArt which are fireworks
    usleep(500000);
    system("clear");
    cout << "\033[1;92m" << victoryArt2 << "\033[0m " << '\n';
    usleep(400000);
    system("clear");
    cout << "\033[1;93m" << victoryArt3 << "\033[0m " << '\n';
    usleep(400000);
    system("clear");
    cout << "\033[1;91m" << victoryArt4 << "\033[0m " << '\n';
    usleep(300000);
    system("clear");
    cout << "\033[1;92m" << victoryArt4<< "\033[0m " << '\n';
    usleep(300000);
    system("clear");
    cout << "\033[1;94m" << victoryArt4<< "\033[0m " << '\n';
    usleep(300000);
    system("clear");
    cout << "\033[1;96m" << victoryArt4<< "\033[0m " << '\n';
    usleep(300000);
    system("clear");
    cout << "\033[1;95m" << victoryArt4<< "\033[0m " << '\n';
    usleep(300000);
    system("clear");
   for(int i = 0; i <2; i++)
   {

   
       if(i == 0)
       {
        cout << "\033[1;91m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     //lasts for 0.2 seconds
        system("clear");    //clears previous prints statement allows for alternating title
        cout << "\033[1;92m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     //lasts for 0.2 seconds
        system("clear");
        cout << "\033[1;93m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");    
        cout << "\033[1;94m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");   
        cout << "\033[1;95m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");   
        cout << "\033[1;96m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");   
        cout << "\033[1;97m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear"); 
       }
       else
       {
        cout << "\033[1;91m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     //lasts for 0.2 seconds
        system("clear");    //clears previous prints statement allows for alternating title
        cout << "\033[1;93m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     //lasts for 0.2 seconds
        system("clear");
        cout << "\033[1;95m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");    
        cout << "\033[1;97m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");   
        cout << "\033[1;92m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");   
        cout << "\033[1;94m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");   
        cout << "\033[1;96m" << asciiArt8 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");    
       }
   }
}


void Executive::endscreenanimation2()
{
    cout << "\033[1;91m" << victoryArt1 << "\033[0m " << '\n';
    usleep(500000);
    system("clear");
    cout << "\033[1;92m" << victoryArt2 << "\033[0m " << '\n';
    usleep(400000);
    system("clear");
    cout << "\033[1;93m" << victoryArt3 << "\033[0m " << '\n';
    usleep(400000);
    system("clear");
    cout << "\033[1;91m" << victoryArt4 << "\033[0m " << '\n';
    usleep(300000);
    system("clear");
    cout << "\033[1;92m" << victoryArt4<< "\033[0m " << '\n';
    usleep(300000);
    system("clear");
    cout << "\033[1;94m" << victoryArt4<< "\033[0m " << '\n';
    usleep(300000);
    system("clear");
    cout << "\033[1;96m" << victoryArt4<< "\033[0m " << '\n';
    usleep(300000);
    system("clear");
    cout << "\033[1;95m" << victoryArt4<< "\033[0m " << '\n';
    usleep(300000);
    system("clear");

   for(int i = 0; i <8; i++) //loops for a specified duration
   {
       if(i == 0)
       {
        cout << "\033[1;91m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     //lasts for 0.2 seconds
        system("clear");    //clears previous prints statement allows for alternating title
        cout << "\033[1;92m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     //lasts for 0.2 seconds
        system("clear");
        cout << "\033[1;93m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");    
        cout << "\033[1;94m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");   
        cout << "\033[1;95m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");   
        cout << "\033[1;96m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");   
        cout << "\033[1;97m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear"); 
       }
       else
       {
        cout << "\033[1;91m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     //lasts for 0.2 seconds
        system("clear");    //clears previous prints statement allows for alternating title
        cout << "\033[1;93m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     //lasts for 0.2 seconds
        system("clear");
        cout << "\033[1;95m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");    
        cout << "\033[1;97m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");   
        cout << "\033[1;92m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");   
        cout << "\033[1;94m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");   
        cout << "\033[1;96m" << asciiArt7 << "\033[0m " << '\n';
        usleep(100000);     
        system("clear");    
       }

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
        // E: should the above be outside of do-while? Because the animation would repeat if player gives bad input.
        // I left it as it was originally for now, because I'm altering mostly AI code in this commit

        cout << "\nPlease enter a number between 1-6 for the number of ships you would like per player:  ";
        cin >> tempinput;

    } while (!(tempinput == "1" || tempinput == "2" || tempinput == "3" || tempinput == "4" ||
               tempinput == "5" || tempinput == "6")); //runs loop until a valid number of ships is entered

    ships = stoi(tempinput); // changes string input to int
    cout << "\nYou have selected: " << ships << " ships per player for this game. \n";
    player1ships = ships;
    player2ships = ships;

    cout << "Do you want to play against an AI instead of human opponent? (Y/N): ";
    cin >> aitrigger;

    cout << "\nPlacing the ships for player 1\n"; // Player 1 ship placement same for AI opponent or human opponent
    cout << endl;
    place_ship(ships, player1);

    system("clear"); // screen clears after player 1 ships are placed, to prepare for player 2

    if (aitrigger == "Y" || aitrigger == "y")
    {
        cout << "What level of difficulty for the game? Easy(1), Medium(2), Hard(3):  ";
        cin >> difficulty;
        cout << "\nPlacing the ships for AI (Player 2)\n";
        aiplace(ships, player2);

        // E: maybe insert a stall here so screen is shown with the "Placing ships" message

        system("clear");
    }
    else
    {
        cout << "Place the ships for Player 2\n";
        place_ship(ships, player2);
        system("clear");
    }

    game_start(player1, player2, ships, aitrigger, difficulty);
}

// Placing ships randomly for the AI opponent
void Executive::aiplace(int size, Player& new_player)
{
    char dir = ' ';    // will be randomly assigned a direction
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
            // Rationale is, n%m  gives values between (0 and m-1) and so I want to add 1 to result
            row = (rand() % 9) + 1; // This should give random number between 1 and 9
            
            // generate random column:
            // rand() % 10 gives randon number between 0 and 9
            int randomnumber = (rand() % 10);  // want to add 0 to 9 to the 'A' value
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
        // new_player.getGameBoard();  E: commented out since AI ship placements should not be shown and in any case
        // it is too quick to be seen
        // but maybe insert pause screen pause before next clear-screen so the "Placed ship!" message shows after each ship is placed for AH 

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
        new_player.getGameBoard(); // prints the player's game board to help decide ship placement
        do
        {
            cout << "\nWhere would you like to place a ship with size 1x" << num << "?\n";
            cout << "The rest of the ship will extend down or right from your selected coordinate.\n";
            cout << "If the placement is invalid your ship will not be placed and you will be prompted for new placemnet information.\n";

            do
            {
                cout << "\nPlease enter a number for the row you would wish to place a ship in:  ";
                cin >> tempinput;
            } while (!(tempinput == "1" || tempinput == "2" || tempinput == "3" || tempinput == "4" ||
                       tempinput == "5" || tempinput == "6" || tempinput == "7" || tempinput == "8" || tempinput == "9"));

            row = stoi(tempinput);  // converts user input from string to int

            cout << "\nPlease enter a letter for the column you wish to place a ship in:  ";
            cin >> column;
            cout << "\nIn which direction do you want to place? Enter D or d for down (vertical), R or r for right (horizontal):  ";
            cin >> direction;
        } while (!new_player.placeShip(row, column, num, direction)); // places the ship in the hidden board where the player has specified

        cout << "\nPlaced ship!\n\n";
        // new_player.getGameBoard(); E: commented out by previous group; probably delete; do not need this since board is shown at start of each iteration of while loop    
        num++;
    } while (num < size + 1);
    // E: need to show game board to player after all ships have been placed
    // E: probably need to insert pause before next screen clear, so player can see all of the placed ships.  

}

void Executive::game_start(Player& player1, Player& player2, int size, string aitrigger, int difficulty)
{
    int player1_count = 0; //keeps a running total of the number of hits scored on each player's side
    int player2_count = 0;
    int max_count = size * (1 + size) / 2; //uses the number of ships (size argument) to check how many hits each player can have before they are out of ships
    char player_choice = 'n';  // stores yes (y) or no (n) responses from payer after way too many questions during game
    int row = 0;               // int 1 - 9 after converting user input to int
    char column = ' ';         // A - J
    int column_num = 0;        // 0 - 9
    string tempinput;          // temporary store of user row input before it is converted to int

    do  // long do-while loop that takes up most of the game_start method (bad name; the method starts and ends the shooting)
    {
        cout << "======================PLAYER1=======================\n\n";  // Player 1 is always human, so takes firs shots
        cout << "Opponent's Board: choose a coordinate to fire at.\n\n";       // regardless of human or AI opponent

        player2.getHiddenBoard();  // prints Player 2 board with ships hidden

        do
        {
            cout << "\nEnter the the row number: "; 
            cin >> tempinput;

        } while (!(tempinput == "1" || tempinput == "2" || tempinput == "3" || tempinput == "4" || tempinput == "5" 
                  || tempinput == "6" || tempinput == "7" || tempinput == "8" || tempinput == "9"));

        row = stoi(tempinput);   // convert string user input to int (1 - 9)

        do
        {
            cout << "Enter the column character: "; 
            cin >> column;
            column_num = (char)column - 65;     // converts char to decimal ASCII; 'A' is 65, so converts to (0 to 9)
            // while condition checks for valid gameboard boundary
        } while (column_num < 0 || column_num > 9); // E: This was column_num > 10 in the game we inherited.
                                                    // I don't think that's right so I changed to 9
        system("clear");

        if (player2.checkHit(row, column))
        {
            player2.doAnimation(row - 1, column_num, 1);
            player2.get_hit(row, column);
            player2_count++;
            player2.getHiddenBoard();
            cout << "\nYOU HIT!\n\n";
            if (player2_count == max_count) //check if Player1 wins
            {
                player2.doAnimation(row - 1, column_num, 1);
                break;
            }
        }
        else
        {
            player2.doAnimation(row - 1, column_num, 0);
            // E: when there is a miss, the hiddenBoard did not correctly show miss location because wrong board was shown
            player2.getHiddenBoard(); // E: I changed this from player1 to player2; it was showing the wrong board
            cout << "\nYOU MISSED!\n\n";
        }

        cout << "Do you want to see your Board(y/n)?  ";
        cin >> player_choice;
        if (player_choice == 'y')
        {
            cout << "\n\nYOUR BOARD\n\n";
            player1.getGameBoard();
        }

        do
        {
            cout << "\nEnd Turn(y/n)?  ";
            cin >> player_choice;
        } while (player_choice != 'y');
        system("clear");

        do
        {
            cout << "Player2: Begin Turn(y/n)?  ";
            cin >> player_choice;
        } while (player_choice != 'y');
        system("clear");

        cout << "======================PLAYER2=======================\n\n";  // Player 2 is either AI or human depending on game mode

        player1.getHiddenBoard(); // Prints the board with hidden ships for Player 2 to shoot at

        if(aitrigger == "y" || aitrigger == "Y")
        {
            cout << "Opponent's Board: AI is firing!\n";  // Can change or remove this later

            srand(time(NULL)); // sets unique seed for random number generation

            if (difficulty == 1) // easy game, AI fires randomly
            {
                row = (rand() % 9) + 1; // genterates a random number, 1-9
                int randomnumber = (rand() % 10);  // generates a random number 0-9
                column = 'A' + randomnumber;       // adds 0 to 9 to ASCII for 'A" to get 'A' - 'J'
            }
            else if(difficulty == 2) // medium game, AI fires randomy unless there is a previous hit with unsunk ship
            {
                bool orthog = false; // if get an orthogonal hit, change to true, stop scanning board, and don't try random hit
                int hitRow; // store hit coordinate if scanning opponent's board finds hit
                int hitCol; //  ""    ""
                
                // traverse 2D array to search for 'X' (a previous hit), then check orthogonally for good hit coordinate
                for (int i = 0; i < 9; i++) 
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if (orthog == false && player1.checkHit3(i, j))  // keep cheking coordinates 'till orthog is true
                        {
                            hitRow = i; // if find hit character, store it in in hitRow, hitCol
                            hitCol = j; // do not really need new variables for hit but more clear than using i, j in next steps

                            // check if going up from hit is in board boundary and if so, check if it is a 'B'
                            if (hitRow - 1 >= 0 && player1.checkHit2(hitRow - 1, hitCol))
                            {
                                // set AI hit coordinate for this AI turn, if the condition is met
                                row = hitRow; // index for hit is hitRow-1 but need to convert so it is 1-9 for method compatibility
                                column = 'A' + hitCol; // need to convert for method compatibility
                                orthog = true; // stop looking for hit coordinate for this AI turn
                            }
                            // check if going left of hit is in boundary and if so, check if it is a 'B'
                            else if (hitCol + 1 <= 9 && player1.checkHit2(hitRow, hitCol + 1))
                            {
                                row = hitRow + 1;
                                column = 'A' + (hitCol + 1);
                                orthog = true;
                            }
                            // check if going down from hit is in boundary and if so, check if it is a 'B'
                            else if (hitRow + 1 <= 8 && player1.checkHit2(hitRow + 1, hitCol))
                            {
                                row = hitRow + 2;
                                column = 'A' + hitCol;
                                orthog = true;
                            }
                            // check if going right from hit is in boundary and if so, check if it is a 'B'
                            else if (hitCol - 1 >= 0 && player1.checkHit2(hitRow, hitCol - 1))
                            {
                                row = hitRow + 1;
                                column = 'A' + (hitCol - 1);
                                orthog = true;
                            }
                        } // end of if-block checking around a prior turn hit coordinate
                    }
                } // end of nested for-loops that scan the board

                if (orthog == false) // if can't get a hit around a previous hit, then do random firing like Easy option
                {
                    row = (rand() % 9) + 1;           // genterates a random number, 1-9
                    int randomnumber = (rand() % 10); // generates a random number 0-9
                    column = 'A' + randomnumber;      // adds 0 to 9 to ASCII for 'A" to get 'A' - 'J'
                }
                else 
                {
                }              
            } // end of medium-difficulty if-block
            else if(difficulty == 3)  // hard game, AI cheats and peeks at the ships
            {
                for (int i = 0; i < 9; i++) 
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if(player1.checkHit2(i, j))  // Checks if there is a 'B' character at the index
                        {
                            row = i + 1;
                            column = 'A' + j;
                            // break; probably add break but don't really need, works if commented out
                        }
                    }
                }
            } // end of 3 difficulty game options
        } // end of AI obtain shooting coordinates

        else  // human opponent Player 2 shooting
        {
            cout << "Opponent's Board: choose a coordinate to fire at.\n";

            do
            {
                cout << "\nEnter the the row number: "; 
                cin >> tempinput;

            } while (!(tempinput == "1" || tempinput == "2" || tempinput == "3" || tempinput == "4" || tempinput == "5" 
                       || tempinput == "6" || tempinput == "7" || tempinput == "8" || tempinput == "9"));
            row = stoi(tempinput); // convert string user input to int (1 - 9)

            do
            {
                cout << "\nEnter the column character: "; 
                cin >> column;
                column_num = (char)column - 65;
                // while condition checks for valid game board boundary
            } while (column_num < 0 || column_num > 9); // E: This was column_num > 10 in the game we inherited.
                                                        // I don't think that's right so I changed to 9
        } // end human opponent obtain shooting coordinates

        system("clear"); 

        if (player1.checkHit(row, column))
        {
            player1.doAnimation(row - 1, column_num, 1);
            player1.get_hit(row, column);
            player1_count++;
            player1.getHiddenBoard();
            cout << "\n\nYOU HIT!\n\n";
            if (player1_count == max_count) //check if Player2 wins
            {
                player1.doAnimation(row - 1, column_num, 1);
                break;
            }
        }
        else
        {
            player1.doAnimation(row - 1, column_num, 0);
            player1.getHiddenBoard();
            cout << "\nYOU MISS!\n\n"; 
        }

        cout << "Do you want to see your Board(y/n)?  ";
        cin >> player_choice;
        if (player_choice == 'y')
        {
            cout << "\n\nYOUR BOARD\n\n";
            player2.getGameBoard();
        }
        else
        {
        }

        do
        {
            cout << "\nEnd Turn(y/n)?  ";
            cin >> player_choice;
        } while (player_choice != 'y');
        system("clear");

        do
        {
            cout << "Player1: Begin Turn(y/n)?  ";
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
