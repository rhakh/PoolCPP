#include "Enemy.hpp"

Enemy::Enemy(int _hp, const std::string &_type) :
	hp(_hp), type(_type) {

}

Enemy::~Enemy() {

}

Enemy::Enemy(const Enemy &src) :
	hp(src.getHP()), type(src.getType()) {

}

Enemy	&Enemy::operator=(const Enemy &src) {
	type = src.getType();
	hp = src.getHP();

	return (*this);
}

const std::string	&getType() const {
	return (type);
}

int					getHP() const {
	return (hp);
}
