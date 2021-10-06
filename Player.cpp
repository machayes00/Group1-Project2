#include "Player.h"

using namespace std;

Player::Player()
{
}

Player::~Player()
{
}

bool Player::checkHit(int row, char col)
{
    if (gameBoard.is_what(row, col) == 'B') //checks to see if there is a ship at the specified coordinates.
    {
        return true;
    }
    else if (gameBoard.is_what(row, col) == '~') //checks to see if water is at that location.
    {
        hiddenBoard.exchange(row, col, 'O'); //replaces a wave (~) with a miss (O).
        return false;
    }
    return false; // added this to get rid of compiler warning
}

int Player::checkShips()
{
    return shipsLeft;
}

void Player::get_hit(int row, char col)
{
    gameBoard.exchange(row, col, 'X'); //replaces a ship (B) with a hit (X).
    hiddenBoard.exchange(row, col, 'X');
}

void Player::getHiddenBoard()
{
    hiddenBoard.print();
}

void Player::getGameBoard()
{
    gameBoard.print();
}

void Player::doAnimation(int row, int col)
{
    hiddenBoard.printAnimate(row, col);
}

// E: I don't think this method is ever used.
// and the "getBoard" methods are not getters. Do not need getters.
void Player::getOriginalBoard()
{
    original_Board.print();
}

// E: Alex added extra string parameter here (direction). I agree with the intent
// but it caused compiler error even tho string library was imported. Changed to char.
bool Player::placeShip(int row, char col, int size, char dir)
{
    if (dir == 'r' || dir == 'R') // when the direction is right, horizontal
    {
        if (gameBoard.put_row_ship(row, col, size, 'B'))
        {
            original_Board.put_row_ship(row, col, size, 'B');
            return true;
        }
        else // over boundary or put on top of an existing ship.
        {
            return false;
        }
    }
    else if (dir == 'd' || dir == 'D') // when the direction is down, vertical
    {
        if (gameBoard.put_column_ship(row, col, size, 'B'))
        {
            original_Board.put_column_ship(row, col, size, 'B');
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
void Player::finder(int row,char col)
{
    bool check = false;
    char x;
    for(int i=1; i <= 9; i++)
    {
        for(int j =0; j < 10; j++)
        {
                if(check == true)
                {
                }
                else
                {
                x='A'+j;
                if (gameBoard.is_what(i, x) == 'B')
                {
                    row = i;
                    col= x;
                    check =true;
                }
                }
        }
     }
}
