#include "Star.hpp"

Star::Star() :
Object(STAR_COLOUR, BACKWARD_DIRECT, STAR_SHAPE, 0, 0, DEF_HP)
{

}

Star::Star(int x_, int y_) :
Object(STAR_COLOUR, BACKWARD_DIRECT, STAR_SHAPE, x_, y_, DEF_HP)
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

int     Star::processMove(int frn, int pressCode)
{
    return (Object::processMove(frn, pressCode));
}