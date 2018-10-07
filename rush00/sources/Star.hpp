#ifndef STAR_HPP
#define STAR_HPP

#include "Object.hpp"

class Star : public Object {

public:
    Star();
    Star(int x_, int y_);
    Star(const Star &src);
    ~Star();
    Star   &operator=(const Star &src);

    int     processMove(int frn, int pressCode);
};

#endif // STAR_HPP