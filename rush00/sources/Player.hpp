#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Object.hpp"

class Player : public Object {

public:
    Player();
    Player(int x_, int y_);
    Player(const Player &src);
    ~Player();
    Player   &operator=(const Player &src);
};

#endif // PLAYER_HPP