#ifndef ZOMBIE_EVENT_HPP
#define ZOMBIE_EVENT_HPP

#include <string>
#include "Zombie.hpp"

class ZombieEvent {
	std::string		zombieType;

public:
	Zombie	*newZombie(std::string zombieName);
	void	setZombieType(std::string _zombieType);
	Zombie	*randomChamp();
};

#endif // ZOMBIE_EVENT_HPP
