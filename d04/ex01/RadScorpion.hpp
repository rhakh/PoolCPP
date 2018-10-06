#ifndef RAD_SCORPION_HPP
#define RAD_SCORPION_HPP

#include "Enemy.hpp"
#include <iostream>
#include <string>


class RadScorpion : public Enemy {

public:
	RadScorpion();
	~RadScorpion();
	RadScorpion(const RadScorpion &src);

	RadScorpion	&operator=(const RadScorpion &src);
};

#endif // RAD_SCORPION_HPP
