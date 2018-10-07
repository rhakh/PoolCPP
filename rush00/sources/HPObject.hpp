#ifndef HP_OBJECT_HPP
#define HP_OBJECT_HPP

#include "Object.hpp"

class HPObject : public Object {

public:
    HPObject();
    HPObject(int x_, int y_);
    HPObject(const HPObject &src);
    ~HPObject();
    HPObject   &operator=(const HPObject &src);
};

#endif // HP_OBJECT_HPP