#pragma once

#include <SFML/Graphics.hpp>
#include "Unit.h"

extern sf::Clock game_timer;

class Enemies_cars : public Unit {
private:
	float moving_timer;
public:
	Enemies_cars(sf::Image &IMAGE, float X, float Y, int W, int H, float SPEED,
		float DIRECTION, float HEALTH, float TIME_BETWEEN_ATTACK, int DAMAGE)
		:Unit(IMAGE, X, Y, W, H, SPEED, DIRECTION, HEALTH, TIME_BETWEEN_ATTACK, DAMAGE) {

		moving_timer = attack_frequency_time;

		if (direction == 2) {
			sprite.setScale(1, -1);
		}
	}

	virtual ~Enemies_cars() {}

	int update(float time);
};
