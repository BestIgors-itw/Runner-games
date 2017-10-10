#pragma once

#include <SFML/Graphics.hpp>
#include "Movable.h"

extern sf::Clock game_timer;

class Effect : public Movable {
public:
	float timer, exist_time;
	Effect(sf::Image &IMAGE, float X, float Y, float SPEED, float DIRECTION,
		float EXIST_TIME) :Movable(IMAGE, X, Y, SPEED, DIRECTION) {
		timer = game_timer.getElapsedTime().asSeconds();
		exist_time = EXIST_TIME;
	}

	int update(float time);
};