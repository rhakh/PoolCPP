#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Object.hpp"

class Enemy : public Object {

public:
    Enemy();
    Enemy(int x_, int y_);
    Enemy(const Enemy &src);
    ~Enemy();
    Enemy   &operator=(const Enemy &src);
};

#endif // ENEMY_HPP