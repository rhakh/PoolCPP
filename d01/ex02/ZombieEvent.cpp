#include "ZombieEvent.hpp"

Zombie	*ZombieEvent::newZombie(std::string zombieName) {
	Zombie	*zombie = new Zombie(zombieName, zombieType);
	//todo: add handler for non-mem allocation
	return (zombie);
}

void	ZombieEvent::setZombieType(std::string _zombieType) {
	zombieType = _zombieType;
}

Zombie	*ZombieEvent::randomChamp() {
	std::string		namesPool[] = {"Fred", "Alfi", "Monica", "Luciano"};
	std::string		typesPool[] = {"Boss", "pawn", "rider", "egghead"};
	Zombie			*zombie;

	setZombieType(typesPool[rand() % (sizeof(typesPool) / sizeof(*typesPool))]);
	zombie = newZombie(namesPool[rand() % (sizeof(namesPool) / sizeof(*namesPool))]);
	zombie->announce();

	return (zombie);
}
