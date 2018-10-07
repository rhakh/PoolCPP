#include "HPObject.hpp"

HPObject::HPObject() :
Object(HP_COLOUR, BACKWARD_DIRECT, HP_SHAPE, 0, 0, DEF_HP)
{

}

HPObject::HPObject(int x_, int y_) :
Object(HP_COLOUR, BACKWARD_DIRECT, HP_SHAPE, x_, y_, DEF_HP)
{
    
}

HPObject::HPObject(const HPObject &src) : Object(src)
{
    
}

HPObject::~HPObject()
{
    
}

HPObject   &HPObject::operator=(const HPObject &src)
{
    Object::operator=(src);
    return (*this);
}

int     HPObject::processMove(int frn, int pressCode)
{
    (void)(pressCode);
    if (frn % 5 == 0)
        return (0);

    return (Object::processMove(frn, pressCode));
}