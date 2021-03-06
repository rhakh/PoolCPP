#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :
hitPoints(100), maxHitPoints(100), energyPoints(50),
maxEnergyPoints(50), level(1), meleeAttackDamage(20),
rangedAttackDamage(15), armorDamageReduction(3)
{
	this->name = "noname_ScavTrap";
	std::cout << "SC4V-TP<" << this->name
				<< ">: dafault, shit !" << std::endl;
}

ScavTrap::ScavTrap(const std::string &_name) :
hitPoints(100), maxHitPoints(100), energyPoints(50),
maxEnergyPoints(50), level(1), meleeAttackDamage(20),
rangedAttackDamage(15), armorDamageReduction(3)
{
	this->name = _name;
	std::cout << "SC4V-TP<" << this->name
				<< ">: I was born, right now." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs)
{
	*this = rhs;
	std::cout << "SC4V-TP<" << this->name
				<< ">: Oh, my God, coppied..." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SC4V-TP<" << this->name
				<< ">: * last breath *" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
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
	std::cout << "SC4V-TP<" << this->name
				<< ">: *copy created*" << std::endl;
	return (*this);
}

std::string		ScavTrap::getName() const
{
	return (this->name);
}

void 	ScavTrap::rangedAttack(const std::string &target)
{
	std::cout << "SC4V-TP<" << this->name
				<< ">: attacks " << target
				<< " at range, causing " << this->rangedAttackDamage
				<< " points of damage!" << std::endl;
}

void 	ScavTrap::meleeAttack(const std::string &target)
{
	std::cout << "SC4V-TP<" << this->name
				<< ">: attacks " << target
				<< " at melee, causing " << this->meleeAttackDamage
				<< " points of damage!" << std::endl;
}

void 	ScavTrap::tackeDamage(unsigned int amount)
{
	if (this->hitPoints == 0) {
		std::cout << "SC4V-TP<" << this->name
					<< ">: I can't get any more damage"
					<< std::endl;
	} else if ((int)amount <= this->armorDamageReduction) {
		std::cout << "SC4V-TP<" << this->name
					<< ">: Armour saves me"
					<< std::endl;
	} else {
		this->hitPoints = this->hitPoints +
							this->armorDamageReduction -
							amount;
		(this->hitPoints < 0) ? (this->hitPoints = 0) : (0);
		std::cout << "SC4V-TP<" << this->name
				<< ">: takes " << amount
				<< " of damage, hit points now " << this->hitPoints
				<< std::endl;
	}
}

void 	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == this->maxHitPoints) {
		std::cout << "SC4V-TP<" << this->name
				<< ">: My HP is full !"
				<< std::endl;
	} else {
		this->hitPoints += amount;
		if (this->hitPoints > this->maxHitPoints)
			this->hitPoints = this->maxHitPoints;
		std::cout << "SC4V-TP<" << this->name
				<< ">: was repaired by " << amount
				<< " points, hit points now " << this->hitPoints
				<< std::endl;
	}
}

void	ScavTrap::challangeNewcomer()
{
	std::string	challanges[] = {	"salto mortelo",
                                    "take master degree in KPI",
                                    "eat frog legs"
                                    "pass CPP pool",
                                    "get Ballmer peak"};
	int challangesSize = sizeof(challanges) / sizeof(challanges[0]);

	if (this->energyPoints >= 25) {
		this->energyPoints -= 25;
		std::cout << "SC4V-TP<" << this->name
				<< ">: did challange named as " << challanges[rand() % challangesSize]
				<< ", energy points now " << this->energyPoints 
				<< std::endl;
	} else {
		std::cout << "SC4V-TP<" << this->name
				<< ">: Tired, too tired ..."
				<< std::endl;
	}
}
