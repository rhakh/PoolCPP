#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	std::string		name;
	const Weapon	*weapon;

public:
	HumanB(const std::string  &_name);
	void	attack() const;
	void	setWeapon(const Weapon  &_weapon);
};

#endif // HUMANB_HPP
