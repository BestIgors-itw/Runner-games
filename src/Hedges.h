#pragma once

#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "Entity.h"

#define screen_width 1600
#define screen_hight 900

class Hedges : public Entity {
public:
	float speed, health;
	int direction;
	Hedges(sf::Image &image, float X, float Y, int W, int H,
		float Direction, float Health)
		:Entity(image, X, Y, W, H) {
		health = Health;
		direction = Direction;
		speed = 0.6;
		Direction_convert(direction, dx, dy, speed);
	}

	int update(float time);
};


