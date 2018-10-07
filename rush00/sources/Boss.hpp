#ifndef BOSS_HPP
#define BOSS_HPP

#include "Object.hpp"

class Boss : public Object {

public:
    Boss();
    Boss(int x_, int y_);
    Boss(const Boss &src);
    ~Boss();
    Boss   &operator=(const Boss &src);
};

#endif // BOSS_HPP