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
    if(hiddenboard.is_what(row,col)=='B')
    {

    }
    else
    {

    }
}

int Player::checkShips()
{
    return shipsLeft;
}

void Player::hit(int row,char col)
{
    gameboard.exchange(row,col,'X');
}

Board Player::getHiddenBoard()
{

}

Board Player::getGameBoard()
{

}