#include "Player.h"

using namespace std;


Player::Player()
{
    
}

Player::~Player()
{
    
}

bool Player::checkHit(int row,char col)
{
    if(gameBoard.is_what(row,col)=='B') //checks to see if there is a ship at the specified coordinates.
    {
        return true;
    }
    else if (gameBoard.is_what(row,col) == '~')//checks to see if water is at that location.
    {
        hiddenBoard.exchange(row,col,'O');//replaces a wave (~) with a miss (O).
        return false;
    }
    return false; // added this to get rid of compiler warning
}

int Player::checkShips()
{
    return shipsLeft;
}

void Player::get_hit(int row,char col)
{
    gameBoard.exchange(row,col,'X'); //replaces a ship (B) with a hit (X).
    hiddenBoard.exchange(row,col,'X');
}

void Player::getHiddenBoard()
{
    hiddenBoard.print();
}

void Player::getGameBoard()
{
    gameBoard.print();
}

void Player::getOriginalBoard()
{
    original_Board.print();
}

// E: Alex added extra strubg parameter here (direction). I agree with the intent 
// but it caused compiler error. Changed to char.
bool Player::placeShip(int row, char col, int size, char dir)
{
    if (dir == 'r' || dir == 'R') // when the direction is right, horizontal
    {
        if(gameBoard.put_row_ship(row,col,size,'B'))
        {
            original_Board.put_row_ship(row,col,size,'B');
            return true;
        }
        else // over boundary or put on top of an existing ship.
        {
            return false;
        }
    }
    else if (dir == 'd' || dir == 'D') // when the direction is down, vertical
    {
        if(gameBoard.put_column_ship(row,col,size,'B'))
        {
            original_Board.put_column_ship(row,col,size,'B');
            return true;
        }
        else // over boundary or put on top of an existing ship.
        {
            return false;
        }
    }
    else //invalid input
    {
        return false;
    }
}
