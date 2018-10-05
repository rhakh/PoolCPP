#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>
#include <iostream>

class ScavTrap {
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
	ScavTrap();
	ScavTrap(const std::string &_name);
	ScavTrap(const ScavTrap &src);
	~ScavTrap();
	ScavTrap		&operator=(const ScavTrap &rhs);

	void 	rangedAttack(const std::string &target);
	void 	meleeAttack(const std::string &target);
	void 	tackeDamage(unsigned int amount);
	void 	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(const std::string &target);

	std::string		getName() const;
};

#endif //SCAV_TRAP_HPP
