#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

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
	void	challangeNewcomer();
};

#endif //SCAV_TRAP_HPP
