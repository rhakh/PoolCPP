#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>
#include <iostream>

class FragTrap {
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
	FragTrap();
	FragTrap(const std::string &_name);
	FragTrap(const FragTrap &src);
	~FragTrap();
	FragTrap		&operator=(const FragTrap &rhs);

	void 	rangedAttack(const std::string &target);
	void 	meleeAttack(const std::string &target);
	void 	tackeDamage(const std::string &target);
	void 	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(const std::string &target);

	std::string		getName() const;
};

#endif //FRAG_TRAP_HPP
