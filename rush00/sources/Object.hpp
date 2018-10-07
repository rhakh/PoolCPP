#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <ncurses.h>
#include <cstdlib>
#include "main.hpp"

class Object {

public:
    Object();
    Object(int x_, int y_);
    Object(const Object &src);
    virtual ~Object();
    virtual Object  &operator=(const Object &src);

    virtual int     processMove(int frn, int pressCode);
    virtual void    print(WINDOW *win);

    virtual int     getX() const;
    virtual int     getY() const;
    virtual int     getColour() const;
    virtual int     getDirection() const;
    virtual int     getShape() const;
    virtual int     getHP() const;
    virtual void    decreaseHP();
    virtual void    increaseHP();

protected:
    const int   colour, direction;
    const char  shape;
    int         x, y, hp;
};

#endif // OBJECT_HPP