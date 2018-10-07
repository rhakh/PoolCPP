#include "Enemy.hpp"

Enemy::Enemy() : Object()
{

}

Enemy::Enemy(int x_, int y_) : Object(x_, y_)
{
    
}

Enemy::Enemy(const Enemy &src) : Object(src)
{
    
}

Enemy::~Enemy()
{
    
}

Enemy   &Enemy::operator=(const Enemy &src)
{
    Object::operator=(src);
    return (*this);
}
