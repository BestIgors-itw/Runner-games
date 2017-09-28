#pragma once

#include <SFML/Graphics.hpp>
#include "Unit.h"

extern sf::Clock game_timer, moving_timer;

class Shooter_enemies_cars : public Unit {
private:
	float moving_timer;
public:
	Shooter_enemies_cars(sf::Image &IMAGE, float X, float Y, int W, int H, float SPEED,
		int DIRECTION, float HEALTH, float TIME_BETWEEN_ATTACK, float DAMAGE)
		:Unit(IMAGE, X, Y, W, H, SPEED, DIRECTION, HEALTH, TIME_BETWEEN_ATTACK, DAMAGE) {

		moving_timer = attack_frequency_time;
	}

	virtual ~Shooter_enemies_cars() {}

	int update(float time);
};