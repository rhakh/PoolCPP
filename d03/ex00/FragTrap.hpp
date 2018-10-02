#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>
#include <iostream>

class FragTrap {

	const int		hitPoints;
	const int		maxHitPoints;
	const int		energyPoints;
	const int		maxEnergyPoints;
	const int		level;
	std::string		name;
	const int		meleeAttackRange;
	const int		rangedAttackReduction;
	const int		armorDamageReduction;

public:
	FragTrap();
	FragTrap(const FragTrap &src);
	~FragTrap();
	FragTrap		&operator=(const FragTrap &rhs);

	void 	rangedAttack(const std::string &target);
	void 	meleeAttack(const std::string &target);
	void 	tackeDamage(const std::string &target);
	void 	beRepaired(unsigned int amount);

	std::string		&getName() const;
};

#endif //FRAG_TRAP_HPP
