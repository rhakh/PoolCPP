#include "Boss.hpp"

Boss::Boss() : Object()
{

}

Boss::Boss(int x_, int y_) : Object(x_, y_)
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