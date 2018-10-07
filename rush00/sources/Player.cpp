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
