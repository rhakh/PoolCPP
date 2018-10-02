#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce() {
	std::cout << "<" + name + " (" + type + ")> Braiiiiiiinnnssss..." << std::endl;
}

Zombie::Zombie(std::string _name, std::string _type) {
	name = _name;
	type = _type;
}

Zombie::Zombie() {
	std::string		names[] = {"Fredo", "Al", "Samanta", "Salma"};
	std::string		types[] = {"Boss", "pawn", "nerd", "monobrowed"};

	this->name = names[rand() % (sizeof(names) / sizeof(*names))];
	this->type = types[rand() % (sizeof(types) / sizeof(*types))];
}
