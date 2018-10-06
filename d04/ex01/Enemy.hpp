#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <string>

class Enemy {

protected:
	int				hp;
	std::string		type;

public:
	Enemy(int hp, const std::string &type);
	virtual	~Enemy();
	Enemy(const Enemy &src);

	Enemy	&operator=(const Enemy &src);

	const std::string	&getType() const;
	int					getHP() const;
	virtual void		takeDamage(int dmg);
};

#endif // ENEMY_HPP
