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


  do {
    
  } while(player1ships != 0 && player2ships != 0);
}
