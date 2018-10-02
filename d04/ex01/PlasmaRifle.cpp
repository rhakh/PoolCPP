#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {

}

PlasmaRifle::~PlasmaRifle() {

}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &src) :
	name(src.getName()), apcost(src.getAPCost()), damage(src.getDamage()) {
}

PlasmaRifle	&PlasmaRifle::operator=(const PlasmaRifle &src) {

	name = src.getName();
	apcost = src.getAPCost();
	damage = src.getDamage();

	return (*this);
}

void			PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
