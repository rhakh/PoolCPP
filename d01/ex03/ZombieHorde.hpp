#ifndef ZOMBIE_HORDE_HPP
#define ZOMBIE_HORDE_HPP

#include "Zombie.hpp"
#include <iostream>
#include <string>

class ZombieHorde {
	int		amount;
	Zombie	*array;

public:
	ZombieHorde(int n);
	~ZombieHorde();
	void	announce();
};

#endif // ZOMBIE_HORDE_HPP
