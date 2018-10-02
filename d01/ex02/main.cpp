#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int		main(void) {
	ZombieEvent		ze;
	Zombie			*zp;
	Zombie			zombieSt("Duck", "static");

	std::cout << "Example of randomChamp()" << std::endl;
	zp = ze.randomChamp();
	delete zp;
	zp = ze.randomChamp();
	delete zp;
	zp = ze.randomChamp();
	delete zp;
	zp = ze.randomChamp();
	delete zp;
	std::cout << std::endl;

	std::cout << "Announce from zombie on stack" << std::endl;
	zombieSt.announce();
	std::cout << std::endl;

	std::cout << "Test of newZombie() and setZombieType()" << std::endl;
	ze.setZombieType("sad");
	zp = ze.newZombie("Marvin");
	zp->announce();
	delete zp;

	return (0);
}
