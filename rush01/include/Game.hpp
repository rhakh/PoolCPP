/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <apelykh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:19:00 by apelykh           #+#    #+#             */
/*   Updated: 2018/10/07 23:33:40 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <sys/time.h>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "main.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "node_t.hpp"
#include "Enemy.hpp"
#include "Boss.hpp"
#include "HPObject.hpp"
#include "Star.hpp"
#include "Bullet.hpp"
#include "Exceptions.hpp"

class Game {
	public:
		Game();
		Game(Game const & src);
		~Game();

		Game &operator=(const Game &src);

		int	startGame();
		int	getpressCode() const;
		int	getScore() const;
		int	getTimeInGame() const;

	private:
		WINDOW *win;
		WINDOW *data_win;
		node_t *list;

		int	pressCode;
		int	score;
		int	isPaused;
		unsigned frameNumber;

		void processMoves();
		void printWindow();
		void destroyGame();
		void createGame();
		void createEnemy();
		void checkForCollisions();
		void deleteDeadObjects();
		int	checkObjects(Object *obj1, Object *obj2);
};

#endif
