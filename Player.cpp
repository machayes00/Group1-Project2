#include "Player.h"
using namespace std;


Player::Player(int ships)
{
    shipsLeft = ships;
}

Player::~Player()
{

}

bool Player::checkHit(int row,char col)
{
    if(gameBoard.is_what(row,col)=='B')
    {
        return true;
    }
    else //if (gameBoard.is_what(row,col) == '~')
    {
        hiddenBoard.exchange(row,col,'O');
        return false;
    }
}

int Player::checkShips()
{
    return shipsLeft;
}

void Player::get_hit(int row,char col)
{
    gameBoard.exchange(row,col,'X');
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

bool Player::placeShip(int row, char col, int size)
{
    string direction;
    do {
      cout << "In which direction do you want the ship to extend? (>/v)\n"; //row or collumn is ambigous (example: is row left or right?)
      cin >> direction;
    } while(!(direction == ">" || direction == "v"));

    if (direction == ">") // when the direction is row
    {
        if(gameBoard.put_row_ship(row,col,size,'B'))
        {
            original_Board.put_row_ship(row,col,size,'B');
            return true;
        }
        else // over boundary or over put
        {
            return false;
        }
    }
    else if (direction == "v") // when the direction is col
    {
        if(gameBoard.put_column_ship(row,col,size,'B'))
        {
            original_Board.put_column_ship(row,col,size,'B');
            return true;
        }
        else // over boundary or over put
        {
            return false;
        }
    }
    else //invalid input
    {
        return false;
    }
}
