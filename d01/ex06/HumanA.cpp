#include "HumanA.hpp"

void	HumanA::attack() const {
	std::cout << name + " attacks with his " + weapon->getType() << std::endl;
}

HumanA::HumanA(const std::string  &_name, const  Weapon &_weapon) : 
	name(_name) {
		this->weapon = &_weapon;
}
