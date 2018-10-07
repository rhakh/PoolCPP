#include "Bullet.hpp"

Bullet::Bullet() :
Object(BULLET_COLOUR, BACKWARD_DIRECT, BULLET_SHAPE, 0, 0, DEF_HP)
{

}

Bullet::Bullet(int x_, int y_, int direction) :
Object(BULLET_COLOUR, direction, BULLET_SHAPE, x_, y_, DEF_HP)
{
    (void)(direction);
}

Bullet::Bullet(const Bullet &src) : Object(src)
{
    
}

Bullet::~Bullet()
{
    
}

Bullet   &Bullet::operator=(const Bullet &src)
{
    Object::operator=(src);
    return (*this);
}
