#include "Boss.hpp"

Boss::Boss() :
Object(BOSS_COLOUR, BACKWARD_DIRECT, BOSS_SHAPE, 0, 0, BOSS_HP)
{
    
}

Boss::Boss(int x_, int y_) :
Object(BOSS_COLOUR, BACKWARD_DIRECT, BOSS_SHAPE, x_, y_, BOSS_HP)
{
    
}

Boss::Boss(const Boss &src) : Object(src)
{
    
}

Boss::~Boss()
{
    
}

Boss   &Boss::operator=(const Boss &src)
{
    Object::operator=(src);
    return (*this);
}