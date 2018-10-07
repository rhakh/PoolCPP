#include "Star.hpp"

Star::Star() : Object()
{

}

Star::Star(int x_, int y_) : Object(x_, y_)
{
    
}

Star::Star(const Star &src) : Object(src)
{
    
}

Star::~Star()
{
    
}

Star   &Star::operator=(const Star &src)
{
    Object::operator=(src);
    return (*this);
}