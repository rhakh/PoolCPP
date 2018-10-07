#include "Player.hpp"

Player::Player() :
Object(PLAYER_COLOUR, BACKWARD_DIRECT, PLAYER_SHAPE, 0, 0, PLAYER_HP)
{

}

Player::Player(int x_, int y_) :
Object(PLAYER_COLOUR, BACKWARD_DIRECT, PLAYER_SHAPE, x_, y_, PLAYER_HP)
{
    
}

Player::Player(const Player &src) : Object(src)
{
    
}

Player::~Player()
{
    
}

Player   &Player::operator=(const Player &src)
{
    Object::operator=(src);
    return (*this);
}

int     Player::processMove(int frn, int pressCode)
{
    (void)(frn);
    if (pressCode == ERR) {
        return (0);
    } else if (pressCode == KEY_UP && (this->y - 1) > PL_START_Y) {
        this->y--;
    } else if (pressCode == KEY_DOWN && (this->y + 2) < pl_height) {
        this->y++;
    } else if (pressCode == KEY_RIGHT && (this->x + 2) < pl_length) {
        this->x++;
    } else if (pressCode == KEY_LEFT && (this->x - 1) > PL_START_X) {
        this->x--;
    } else if (pressCode == ' ')
        return (PLAYER_SHOT);
    return (0);
}