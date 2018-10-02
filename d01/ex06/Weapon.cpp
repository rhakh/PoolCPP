#include "Weapon.hpp"

Weapon::Weapon() {
	this->type = "<empty type>";
}

Weapon::Weapon(const std::string &_type) {
	this->type = _type;
}

const std::string &Weapon::getType() const {
	return (type);
}

void	Weapon::setType(const std::string &_type) {
	this->type = _type;
}
