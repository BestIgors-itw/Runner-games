#pragma once

#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Entity.h"

class Movable : public Entity {
public:
	float dx, dy;
	float speed;
	int direction;
	Movable(sf::Image &IMAGE, float X, float Y, int W, int H, float SPEED, float DIRECTION)
		:Entity(IMAGE, X, Y, W, H) {
		speed = SPEED;
		direction = DIRECTION;
		Direction_convert(direction, dx, dy, speed);
	}

	int update(float time);
};