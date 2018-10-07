#include "Object.hpp"

void    Object::print(WINDOW *win)
{
    wattron(win, COLOR_PAIR(this->colour));
    mvwaddch(win, this->y, this->x, this->shape | A_BOLD);
    wattroff(win, COLOR_PAIR(this->colour));
}

int     Object::getX() const
{
    return (this->x);
}

int     Object::getY() const
{
    return (this->y);
}

int     Object::getColour() const
{
    return (this->colour);
}

int     Object::getDirection() const
{
    return (this->direction);
}

int     Object::getShape() const
{
    return (this->shape);
}

int     Object::getHP() const
{
    return (this->hp);
}

Object::Object() :
colour(DEF_COLOUR), direction(DEF_DIRECT),
shape(DEF_SHAPE), x(0), y(0), hp(DEF_HP)
{

}

Object::Object(int x_, int y_) :
colour(DEF_COLOUR), direction(DEF_DIRECT),
shape(DEF_SHAPE), x(x_), y(y_), hp(DEF_HP)
{

}

Object::Object(int colour_, int direction_, char shape_, int x_, int y_, int hp_) :
colour(colour_), direction(direction_),
shape(shape_), x(x_), y(y_), hp(hp_)
{

}

Object::Object(const Object &src) :
colour(DEF_COLOUR), direction(DEF_DIRECT),
shape(DEF_SHAPE)
{
    *this = src;
}

Object::~Object()
{

}

Object  &Object::operator=(const Object &src)
{
    this->x = src.x;
    this->y = src.y;
    this->hp = src.hp;
    return (*this);
}

void    Object::decreaseHP()
{
    this->hp--;
}

void    Object::increaseHP()
{
    this->hp++;
}

/*
 * return   0 - ok, otherwise look at GameEvents
 */
int     Object::processMove(int frn, int pressCode)
{
    int random;

    random = rand() % 100;

    switch (this->shape) {
        case ENEMY_SHAPE: {
            if (frn % 2 == 0)
                return (0);
            // // move by Y
            // if (random >= 0 && random < 2)
            // {
            //     if (this->y - 1 > PL_START_Y)
            //         this->y--;
            // } else if (random >= 2 && random < 4)
            // {
            //     if (this->y + 1 < pl_height)
            //         this->y++;
            // }
            if (random < 3)
                return (ENEMY_SHOT);
        }
        case BOSS_SHAPE:
        case STAR_SHAPE:
        case BULLET_SHAPE: {
            // move by X
            if (this->direction == BACKWARD_DIRECT &&
                (this->x - 1 > PL_START_X))
            {
                this->x--;
            } else if (this->direction == FORWARD_DIRECT &&
                        (this->x + 2 < pl_length))
            {
                this->x++;    
            } else if (this->direction == BACKWARD_DIRECT && (this->x - 1 <= PL_START_X)) {
                return (OBJECT_REACH_LEFT_SIDE);
            } else if (this->direction == FORWARD_DIRECT && (this->x + 2 >= pl_length)) {
                return (OBJECT_REACH_RIGHT_SIDE);
            }
            return (0);
        }
        break;
        case PLAYER_SHAPE: {
            if (pressCode == ERR) {
                return (0);
            } else if (pressCode == KEY_UP && (this->y - 1) > PL_START_Y) {
                this->y--;
            } else if (pressCode == KEY_DOWN && (this->y + 2) < pl_height) {
                this->y++;
            } else if (pressCode == KEY_RIGHT && (this->x + 2) < pl_length) {
                this->x++;
            } else if (pressCode == KEY_LEFT && (this->x - 1) > PL_START_X) {
                this->x--;
            } else if (pressCode == ' ')
                return (PLAYER_SHOT);
            return (0);
        }
        break;
    }
    return (0);
}