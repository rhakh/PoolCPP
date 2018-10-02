#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class	Zombie {
	std::string		type;
	std::string		name;

public:
	Zombie(std::string _name, std::string _type);
	Zombie();
	void	announce();
};

#endif // ZOMBIE_HPP
