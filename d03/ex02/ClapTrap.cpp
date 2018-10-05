#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
hitPoints(100), maxHitPoints(100), energyPoints(100),
maxEnergyPoints(100), level(1), meleeAttackDamage(30),
rangedAttackDamage(20), armorDamageReduction(5)
{
	this->name = "noname_ClapTrap";
	std::cout << "CL4P-TP<" << this->name
				<< ">: New noname ClapTrap." << std::endl;
}

ClapTrap::ClapTrap(const std::string &_name) :
hitPoints(100), maxHitPoints(100), energyPoints(100),
maxEnergyPoints(100), level(1), meleeAttackDamage(30),
rangedAttackDamage(20), armorDamageReduction(5)
{
	this->name = _name;
	std::cout << "CL4P-TP<" << this->name
				<< ">: New ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	*this = rhs;
	std::cout << "CL4P-TP<" << this->name
				<< ">: Copy" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "CL4P-TP<" << this->name
				<< ">: * dead of ClapTrap *" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
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
	std::cout << "CL4P-TP<" << this->name
				<< ">: * copy created *" << std::endl;
	return (*this);
}

std::string		ClapTrap::getName() const
{
	return (this->name);
}

void 	ClapTrap::rangedAttack(const std::string &target)
{
	std::cout << "CL4P-TP<" << this->name
				<< ">: attacks " << target
				<< " at range, causing " << this->rangedAttackDamage
				<< " points of damage!" << std::endl;
}

void 	ClapTrap::meleeAttack(const std::string &target)
{
	std::cout << "CL4P-TP<" << this->name
				<< ">: attacks " << target
				<< " at melee, causing " << this->meleeAttackDamage
				<< " points of damage!" << std::endl;
}

void 	ClapTrap::tackeDamage(unsigned int amount)
{
	if (this->hitPoints == 0) {
		std::cout << "CL4P-TP<" << this->name
					<< ">: I can't get any more damage"
					<< std::endl;
	} else if ((int)amount <= this->armorDamageReduction) {
		std::cout << "CL4P-TP<" << this->name
					<< ">: Still alive"
					<< std::endl;
	} else {
		this->hitPoints = this->hitPoints +
							this->armorDamageReduction -
							amount;
		(this->hitPoints < 0) ? (this->hitPoints = 0) : (0);
		std::cout << "CL4P-TP<" << this->name
				<< ">: takes " << amount
				<< " of damage, hit points now " << this->hitPoints
				<< std::endl;
	}
}

void 	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == this->maxHitPoints) {
		std::cout << "CL4P-TP<" << this->name
				<< ">: I'm healthy as a cow !"
				<< std::endl;
	} else {
		this->hitPoints += amount;
		if (this->hitPoints > this->maxHitPoints)
			this->hitPoints = this->maxHitPoints;
		std::cout << "CL4P-TP<" << this->name
				<< ">: was repaired by " << amount
				<< " points, hit points now " << this->hitPoints
				<< std::endl;
	}
}
