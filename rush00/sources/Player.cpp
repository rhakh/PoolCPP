#include "Player.hpp"

Player::Player() : Object()
{

}

Player::Player(int x_, int y_) : Object(x_, y_)
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
