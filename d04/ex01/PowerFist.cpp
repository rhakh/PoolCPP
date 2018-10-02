#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {

}

PowerFist::~PowerFist() {

}

PowerFist::PowerFist(const PowerFist &src) :
	name(src.getName()), apcost(src.getAPCost()), damage(src.getDamage()) {
}

PowerFist	&PowerFist::operator=(const PowerFist &src) {

	name = src.getName();
	apcost = src.getAPCost();
	damage = src.getDamage();

	return (*this);
}

void			PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
