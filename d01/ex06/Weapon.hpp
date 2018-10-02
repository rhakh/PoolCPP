#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	std::string	type;

public:
	Weapon();
	Weapon(const std::string &_type);
	const std::string	&getType() const;
	void				setType(const std::string &_type);
};

#endif // WEAPON_HPP
