#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	std::string		name;
	const Weapon	*weapon;

public:
	HumanA(const std::string  &_name, const Weapon &_weapon);
	void	attack() const;
};

#endif // HUMANA_HPP
