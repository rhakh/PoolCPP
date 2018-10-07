#include "HPObject.hpp"

HPObject::HPObject() : Object()
{

}

HPObject::HPObject(int x_, int y_) : Object(x_, y_)
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