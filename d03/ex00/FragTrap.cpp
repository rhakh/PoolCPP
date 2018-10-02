#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->name = "noname_FragTrap";
}

FragTrap::FragTrap(const FragTrap &rhs) {
	this->name = rhs.getName();
}

FragTrap::~FragTrap() {
}

FragTrap	&FragTrap::operator=(const FragTrap &src) {
	this->name = src.getName();

	return (*this);
}

std::string		&FragTrap::getName() const {
	return (this->name);
}

void 	FragTrap::rangedAttack(const std::string &target) {
	std::cout << "FR4G-TP " << this->name
				<< " attacks " << target
				<< " at range, causing " << this->rangedAttackReduction
				<< " points of damage!" << std::endl;
}

void 	FragTrap::meleeAttack(const std::string &target) {

}

void 	FragTrap::tackeDamage(const std::string &target) {

}

void 	FragTrap::beRepaired(unsigned int amount) {

}
