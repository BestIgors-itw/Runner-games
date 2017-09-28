#pragma once

#include <SFML/Graphics.hpp>
#include "Unit.h"

extern sf::Clock game_timer;

class Player : public Unit {
public:
	float score;
	Player(sf::Image &IMAGE, float X, float Y, int W, int H, float SPEED,
		int HEALTH, float TIME_BETWEEN_ATTACK, int DAMAGE)
		:Unit(IMAGE, X, Y, W, H, SPEED, STAY, HEALTH, TIME_BETWEEN_ATTACK, DAMAGE),
		score(0.0) {
	}

	void control();

	int update(float time);

};