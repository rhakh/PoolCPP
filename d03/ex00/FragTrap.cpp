#include "FragTrap.hpp"

FragTrap::FragTrap() :
hitPoints(100), maxHitPoints(100), energyPoints(100),
maxEnergyPoints(100), level(1), meleeAttackDamage(30),
rangedAttackDamage(20), armorDamageReduction(5)
{
	this->name = "noname_FragTrap";
	std::cout << "FragTrap<" << this->name
				<< ">: OMG, I'm default." << std::endl;
}

FragTrap::FragTrap(const std::string &_name) :
hitPoints(100), maxHitPoints(100), energyPoints(100),
maxEnergyPoints(100), level(1), meleeAttackDamage(30),
rangedAttackDamage(20), armorDamageReduction(5)
{
	this->name = _name;
	std::cout << "FragTrap<" << this->name
				<< ">: I'am alive !!!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs)
{
	*this = rhs;
	std::cout << "FragTrap<" << this->name
				<< ">: I'm f**king copy !." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap<" << this->name
				<< ">: *out of life*" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	this->name = src.getName();
	this->hitPoints = src.hitPoints;
	this->maxHitPoints = src.maxHitPoints;
	this->energyPoints = src.energyPoints;
	this->maxEnergyPoints = src.maxEnergyPoints;
	this->level = src.level;
	this->meleeAttackDamage = src.meleeAttackDamage;
	this->rangedAttackDamage = src.rangedAttackDamage;
	this->armorDamageReduction = src.armorDamageReduction;
	std::cout << "FragTrap<" << this->name
				<< ">: *copy created*" << std::endl;
	return (*this);
}

std::string		FragTrap::getName() const
{
	return (this->name);
}

void 	FragTrap::rangedAttack(const std::string &target)
{
	std::cout << "FR4G-TP " << this->name
				<< " attacks " << target
				<< " at range, causing " << this->rangedAttackDamage
				<< " points of damage!" << std::endl;
}

void 	FragTrap::meleeAttack(const std::string &target)
{
	std::cout << "FR4G-TP " << this->name
				<< " attacks " << target
				<< " at melee, causing " << this->meleeAttackDamage
				<< " points of damage!" << std::endl;
}

void 	FragTrap::tackeDamage(const std::string &target) {

}

void 	FragTrap::beRepaired(unsigned int amount) {

}
