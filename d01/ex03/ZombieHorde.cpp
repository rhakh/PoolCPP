#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) {
	this->amount = n;
	array = new Zombie[n];
}

ZombieHorde::~ZombieHorde() {
	delete[] array;
}

void	ZombieHorde::announce() {
	for (int i = 0; i < amount; i++)
		array[i].announce();
}
