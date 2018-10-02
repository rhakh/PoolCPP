#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce() {
	std::cout << "<" + name + " (" + type + ")> Braiiiiiiinnnssss..." << std::endl;
}

Zombie::Zombie(std::string _name, std::string _type) {
	name = _name;
	type = _type;
}
