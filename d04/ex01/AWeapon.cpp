#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) :
name(name), apcost(apcost), damage(damage) {

}

AWeapon::AWeapon() :
name(""), apcost(0), damage(0) {

}

AWeapon::~AWeapon() {

}

AWeapon(const AWeapon &src) {
	name = src.getName();
	apcost = src.getAPCost();
	damage = src.getDamage();
}

AWeapon	&operator=(const AWeapon &src) {
	name = src.getName();
	apcost = src.getAPCost();
	damage = src.getDamage();

	return (*this);
}

const std::string	&getName() const {
	return (name);
}

int					getAPCost() const {
	return (apcost);
}

int					getDamage() const {
	return (damage);
}
