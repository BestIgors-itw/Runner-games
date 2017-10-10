#pragma once

#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Entity.h"

class Movable : public Entity {
protected:
	float dx, dy;
	float speed;
	int direction;
public:
	Movable(sf::Image &IMAGE, float X, float Y, float SPEED, float DIRECTION)
		:Entity(IMAGE, X, Y) {
		speed = SPEED;
		direction = DIRECTION;
		Direction_convert(direction, dx, dy, speed);
	}

	int update(float);

	int return_direction();
};