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

int     Boss::processMove(int frn, int pressCode) {
    int random = rand() % 100;

    if (frn % 2 == 0)
        return (0);
    
    // move by Y
    if (random >= 0 && random < 3)
    {
        if (this->y - 1 > PL_START_Y)
            this->y--;
    } else if (random >= 3 && random < 5)
    {
        if (this->y + 1 < pl_height)
            this->y++;
    }

    Object::processMove(frn, pressCode);

    if (random < 3)
        return (ENEMY_SHOT);
    return (0);
}
