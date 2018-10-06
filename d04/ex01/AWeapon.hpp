#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <string>

class AWeapon {

protected:
	std::string		name;
	int				apcost;
	int				damage;

public:
	AWeapon();
	AWeapon(const std::string &name, int apcost, int damage);
	virtual ~AWeapon();
	AWeapon(const AWeapon &src);

	AWeapon	&operator=(const AWeapon &src);

	const std::string	&getName() const;
	int					getAPCost() const;
	int					getDamage() const;
	virtual void		attack() const = 0;

};

#endif // AWEAPON_HPP
