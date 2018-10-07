#include "Enemy.hpp"

Enemy::Enemy() :
Object(ENEMY_COLOUR, BACKWARD_DIRECT, ENEMY_SHAPE, 0, 0, DEF_HP)
{

}

Enemy::Enemy(int x_, int y_) :
Object(ENEMY_COLOUR, BACKWARD_DIRECT, ENEMY_SHAPE, x_, y_, DEF_HP)
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
