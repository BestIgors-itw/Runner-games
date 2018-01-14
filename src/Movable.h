#pragma once

#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Entity.h"

class Movable : public Entity {
protected:
	float dx, dy;
	float speed;
	unsigned short int direction;
public:
	Movable(sf::Texture &TEXTURE, float X, float Y, float SPEED, unsigned short int DIRECTION)
		:Entity(TEXTURE, X, Y) {
		speed = SPEED;
		direction = DIRECTION;
		Direction_convert(direction, dx, dy, speed);
	}

	int update(float);

	unsigned short int get_direction();
};