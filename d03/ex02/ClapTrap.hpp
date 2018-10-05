#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {

protected:
	int			hitPoints;
	int			maxHitPoints;
	int			energyPoints;
	int			maxEnergyPoints;
	int			level;
	std::string	name;
	int			meleeAttackDamage;
	int			rangedAttackDamage;
	int			armorDamageReduction;

public:
	ClapTrap();
	ClapTrap(const std::string &_name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap();
	ClapTrap		&operator=(const ClapTrap &rhs);

	void 	rangedAttack(const std::string &target);
	void 	meleeAttack(const std::string &target);
	void 	tackeDamage(unsigned int amount);
	void 	beRepaired(unsigned int amount);

	std::string		getName() const;
};

#endif //CLAP_TRAP_HPP