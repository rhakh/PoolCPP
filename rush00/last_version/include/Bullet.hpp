#ifndef BULLET_HPP
#define BULLET_HPP

#include "Object.hpp"

class Bullet : public Object {

public:
    Bullet();
    Bullet(int x_, int y_, int direction);
    Bullet(const Bullet &src);
    ~Bullet();
    Bullet   &operator=(const Bullet &src);

    int     processMove(int frn, int pressCode);
};

#endif // BULLET_HPP