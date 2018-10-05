#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap();
	FragTrap(const std::string &_name);
	FragTrap(const FragTrap &src);
	~FragTrap();
	FragTrap		&operator=(const FragTrap &rhs);

	void 	rangedAttack(const std::string &target);
	void 	meleeAttack(const std::string &target);
	void 	tackeDamage(unsigned int amount);
	void 	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(const std::string &target);
};

#endif //FRAG_TRAP_HPP
