#include "HumanB.hpp"

void	HumanB::attack() const {
	std::cout << name + " attacks with his " + weapon->getType() << std::endl;
}

HumanB::HumanB(const std::string  &_name) {
	this->name = _name;
}

void	HumanB::setWeapon(const Weapon  &_weapon) {
	this->weapon = &_weapon;
}
