#include "FragTrap.hpp"

FragTrap::FragTrap() :
hitPoints(100), maxHitPoints(100), energyPoints(100),
maxEnergyPoints(100), level(1), meleeAttackDamage(30),
rangedAttackDamage(20), armorDamageReduction(5)
{
	this->name = "noname_FragTrap";
	std::cout << "FR4G-TP<" << this->name
				<< ">: OMG, I'm default." << std::endl;
}

FragTrap::FragTrap(const std::string &_name) :
hitPoints(100), maxHitPoints(100), energyPoints(100),
maxEnergyPoints(100), level(1), meleeAttackDamage(30),
rangedAttackDamage(20), armorDamageReduction(5)
{
	this->name = _name;
	std::cout << "FR4G-TP<" << this->name
				<< ">: I'am alive !!!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs)
{
	*this = rhs;
	std::cout << "FR4G-TP<" << this->name
				<< ">: I'm f**king copy !." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP<" << this->name
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
	std::cout << "FR4G-TP<" << this->name
				<< ">: *copy created*" << std::endl;
	return (*this);
}

std::string		FragTrap::getName() const
{
	return (this->name);
}

void 	FragTrap::rangedAttack(const std::string &target)
{
	std::cout << "FR4G-TP<" << this->name
				<< ">: attacks " << target
				<< " at range, causing " << this->rangedAttackDamage
				<< " points of damage!" << std::endl;
}

void 	FragTrap::meleeAttack(const std::string &target)
{
	std::cout << "FR4G-TP<" << this->name
				<< ">: attacks " << target
				<< " at melee, causing " << this->meleeAttackDamage
				<< " points of damage!" << std::endl;
}

void 	FragTrap::tackeDamage(unsigned int amount)
{
	if (this->hitPoints == 0) {
		std::cout << "FR4G-TP<" << this->name
					<< ">: I can't get anu more damage"
					<< std::endl;
	} else if ((int)amount <= this->armorDamageReduction) {
		std::cout << "FR4G-TP<" << this->name
					<< ">: You didn't pierced my armor"
					<< std::endl;
	} else {
		this->hitPoints = this->hitPoints +
							this->armorDamageReduction -
							amount;
		(this->hitPoints < 0) ? (this->hitPoints = 0) : (0);
		std::cout << "FR4G-TP<" << this->name
				<< ">: takes " << amount
				<< " of damage, hit points now " << this->hitPoints
				<< std::endl;
	}
}

void 	FragTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == this->maxHitPoints) {
		std::cout << "FR4G-TP<" << this->name
				<< ">: I'm healthy as a bull !"
				<< std::endl;
	} else {
		this->hitPoints += amount;
		if (this->hitPoints > this->maxHitPoints)
			this->hitPoints = this->maxHitPoints;
		std::cout << "FR4G-TP<" << this->name
				<< ">: was repaired by " << amount
				<< " points, hit points now " << this->hitPoints
				<< std::endl;
	}
}

void	FragTrap::vaulthunter_dot_exe(const std::string &target)
{
	std::string	attacks[] = {	"Avada Kedavra",
								"Punch",
								"Flash attack"
								"Cruciatus",
								"Wall of fire"};
	int attacksSize = sizeof(attacks) / sizeof(attacks[0]);

	if (this->energyPoints >= 25) {
		this->energyPoints -= 25;
		std::cout << "FR4G-TP<" << this->name
				<< ">: uses " << attacks[rand() % attacksSize]
				<< " on " << target
				<< ", energy points now " << this->energyPoints 
				<< std::endl;
	} else {
		std::cout << "FR4G-TP<" << this->name
				<< ">: I'am exhausted !"
				<< std::endl;
	}
}
